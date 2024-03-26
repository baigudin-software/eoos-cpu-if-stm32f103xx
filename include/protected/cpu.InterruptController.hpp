/**
 * @file      cpu.InterruptController.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019-2023, Sergey Baigudin, Baigudin Software
 */ 
#ifndef CPU_INTERRUPTCONTROLLER_HPP_
#define CPU_INTERRUPTCONTROLLER_HPP_

#include "cpu.NonCopyable.hpp"
#include "api.CpuInterruptController.hpp"
#include "cpu.Interrupt.hpp"
#include "cpu.Registers.hpp"
#include "lib.ResourceMemory.hpp"

namespace eoos
{
namespace cpu
{

/**
 * @class InterruptController
 * @brief CPU HW interrupt controller.
 */
class InterruptController : public NonCopyable<NoAllocator>, public api::CpuInterruptController
{
    typedef NonCopyable<NoAllocator> Parent;
    typedef Interrupt<InterruptController> Resource;

public:

    /**
     * @brief Constructor.
     *
     * @param reg Target CPU register model.     
     * @param gie Global interrupt enable controller.
     */
    InterruptController(Registers& reg, api::Guard& gie);

    /** 
     * @brief Destructor.
     */                               
    virtual ~InterruptController();
    
    /**
     * @copydoc eoos::api::Object::isConstructed()
     */
    virtual bool_t isConstructed() const;
        
    /**
     * @copydoc eoos::api::CpuInterruptController::createResource()
     *
     * @note For now all the resources are created on default priority level, which is zero. 
     * This means priorities of interrupts are defined following vector sequence priorities, 
     * and no preemption applied thus no nesting interrupts.
     *
     * @todo Add interrupt resource priorities but control that SysTick and PendSV have 
     * the same priority level, and the level equal or less than any other interrupt 
     * priorities as this is very important for FreeRTOS port especially for the 
     * portYIELD_FROM_ISR() function usage.     
     */
    virtual api::CpuInterrupt* createResource(api::Runnable& handler, int32_t source);

    /**
     * @copydoc eoos::api::CpuInterruptController::getGlobal()
     */      
    virtual api::Guard& getGlobal();
    
    /**
     * @copydoc eoos::api::CpuInterruptController::jump(int32_t)
     */      
    virtual void jump(int32_t exception);
    
    /**
     * @copydoc eoos::api::CpuInterruptController::getNumberSystick()
     */      
    virtual int32_t getNumberSystick() const;

    /**
     * @copydoc eoos::api::CpuInterruptController::getNumberSupervisor()
     */
    virtual int32_t getNumberSupervisor() const;
    
    /**
     * @copydoc eoos::api::CpuInterruptController::getNumberPendSupervisor()
     */
    virtual int32_t getNumberPendSupervisor() const;    
    
    /**
     * @brief Allocates memory.
     *
     * @param size Number of bytes to allocate.
     * @return Allocated memory address or a null pointer.
     */
    static void* allocate(size_t size);

    /**
     * @brief Frees allocated memory.
     *
     * @param ptr Address of allocated memory block or a null pointer.
     */
    static void free(void* ptr);

    /**
     * @brief Handles exceptions.
     *
     * @param exception Exception number.
     */
    static void handleException(int32_t exception);

private:

    /**
     * @brief Constructs this object.
     *
     * @return true if object has been constructed successfully.
     */
    bool_t construct();

    /**
     * @brief Initializes the allocator with heap for resource allocation.
     *
     * @param resource Heap for allocation.
     * @return True if initialized.
     */
    bool_t initialize(api::Heap* resource);

    /**
     * @brief Deinitializes the allocator.
     */
    static void deinitialize();
    
    /**
     * @brief Heap for resource allocation.
     */
    static api::Heap* resource_;

    /**
     * @brief This object.
     */
    static InterruptController* this_;

    /**
     * @brief Target CPU register model.
     */
    Registers& reg_;
    
    /**
     * @brief Global interrupt enable controller.
     */
    api::Guard& gie_;    

    /**
     * @brief Resource memory allocator.
     */     
    lib::ResourceMemory<Resource, EOOS_GLOBAL_CPU_NUMBER_OF_INTERRUPTS> memory_;
    
    /**
     * @brief Global data for all Interrupt objects;
     */    
    Resource::Data data_;

};
    
} // namespace cpu
} // namespace eoos
#endif // CPU_INTERRUPTCONTROLLER_HPP_
