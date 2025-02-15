/**
 * @file      cpu.InterruptController.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019-2023, Sergey Baigudin, Baigudin Software
 */ 
#include "cpu.InterruptController.hpp"
#include "lib.UniquePointer.hpp"

namespace eoos
{
namespace cpu
{
    
/**
 * @brief Jumps to the exception handler.
 *
 * @param exception Exception number.
 * @note The function relies the exception argument is valid, as
 *       it has ASM implementation and difficulty to check the argument.
 */
extern "C" void CpuInterruptController_jumpUsrLow(int32_t exception);

/**
 * @brief Jumps to the SVCall exception handler.
 *
 * @param exception Exception number.
 * @note The function relies the exception argument is valid, as
 *       it has ASM implementation and difficulty to check the argument.
 */
extern "C" void CpuInterruptController_jumpSvcLow(int32_t exception);

/**
 * @brief Handles exceptions.
 *
 * @param exception Exception number.
 */
extern "C" void CpuInterruptController_handleException(int32_t exception)
{
    InterruptController::handleException(exception);
}
    
api::Heap* InterruptController::resource_( NULLPTR );

InterruptController* InterruptController::this_( NULLPTR );

InterruptController::InterruptController(Registers& reg, api::Guard& gie)
    : NonCopyable<NoAllocator>()
    , api::CpuInterruptController()
    , reg_(reg)
    , gie_(gie)
    , memory_(gie_)
    , data_(reg_, gie_) {
    bool_t const isConstructed( construct() );
    setConstructed( isConstructed );
}

InterruptController::~InterruptController()
{
    InterruptController::deinitialize();
}

bool_t InterruptController::isConstructed() const
{
    return Parent::isConstructed();
}
    
api::CpuInterrupt* InterruptController::createResource(api::Runnable& handler, int32_t source)
{
    api::CpuInterrupt* ptr( NULLPTR );
    if( isConstructed() )
    {
        lib::UniquePointer<api::CpuInterrupt> res( new Resource(data_, handler, source) );
        if( !res.isNull() )
        {
            if( !res->isConstructed() )
            {
                res.reset();
            }
        }
        ptr = res.release();
    }    
    return ptr;
}

api::Guard& InterruptController::getGlobal()
{
    return gie_;
}

void InterruptController::jump(int32_t exception)
{
    if( !Resource::isException(exception) )
    {
        return;
    }
    if( exception == getNumberSupervisor() )
    {
        CpuInterruptController_jumpSvcLow(exception);
    }
    else if( exception == getNumberPendSupervisor() )
    {
        // Make PendSV exception pending
        // @todo consider to move this functionality to a set() function, 
        // as actually here we set a pending flag and after that HW routers 
        // a program to an appropriate ISR. 
        data_.reg.scs.scb->icsr.bit.pendsvset = 1;
    }
    else
    {
        CpuInterruptController_jumpUsrLow(exception);
    }
}

int32_t InterruptController::getNumberSystick() const
{
    return Resource::EXCEPTION_SYSTICK;
}

int32_t InterruptController::getNumberSupervisor() const
{
    return Resource::EXCEPTION_SVCALL;
}

int32_t InterruptController::getNumberPendSupervisor() const
{
    return Resource::EXCEPTION_PENDSV;
}

bool_t InterruptController::construct()
{
    bool_t res( false );
    do 
    {
        if( !isConstructed() )
        {
            break;
        }
        if( !memory_.isConstructed() )
        {
            break;
        }
        if( !initialize(&memory_) )
        {
            break;
        }
        res = true;
    } while(false);
    return res;
}

void* InterruptController::allocate(size_t size)
{
    if( resource_ != NULLPTR )
    {
        return resource_->allocate(size, NULLPTR);
    }
    else
    {
        return NULLPTR;
    }
}

void InterruptController::free(void* ptr)
{
    if( resource_ != NULLPTR )
    {
        resource_->free(ptr);
    }
}

void InterruptController::handleException(int32_t exception)
{
    #ifdef EOOS_DEBUG_MODE
    // As soon as ISR must be as fast as possible, do these checkes only in debug mode.
    if( this_ == NULLPTR )
    {
        return;
    }
    if( !Resource::isException(exception) )
    {
        return;
    }
    if( this_->data_.handlers[exception] == NULLPTR )
    {
        return;
    }
    #endif // EOOS_DEBUG_MODE
    this_->data_.handlers[exception]->start();
}

bool_t InterruptController::initialize(api::Heap* resource)
{
    if( resource_ != NULLPTR || this_ != NULLPTR) 
    {
        return false;
    }
    resource_ = resource;
    this_ = this;
    return true;
}

void InterruptController::deinitialize()
{
    resource_ = NULLPTR;
    this_ = NULLPTR;
}
    
} // namespace cpu
} // namespace eoos
