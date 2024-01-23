/**
 * @file      cpu.Interrupt.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_INTERRUPT_HPP_
#define CPU_INTERRUPT_HPP_

#include "cpu.NonCopyable.hpp"
#include "api.CpuInterrupt.hpp"
#include "api.Runnable.hpp"
#include "api.Guard.hpp"
#include "cpu.Registers.hpp"
#include "lib.Guard.hpp"

namespace eoos
{
namespace cpu
{

/**
 * @class Interrupt
 * @brief CPU HW interrupt resource.
 * 
 * @tparam A Heap memory allocator class.
 */
template <class A>
class Interrupt : public NonCopyable<A>, public api::CpuInterrupt
{
    typedef NonCopyable<A> Parent;

public:

    /**
     * @enum Exception
     * @brief Exception numbers.
     */
    enum Exception
    {
        // Cortex-M3 exceptions
        EXCEPTION_NMI = 2,          ///< System handler NMI        
        EXCEPTION_HARDFAULT,        ///< Fault handler Hard Fault 
        EXCEPTION_MEMMANAGE,        ///< Fault handler MPU Fault  
        EXCEPTION_BUSFAULT,         ///< Fault handler Bus Fault  
        EXCEPTION_USAGEFAULT,       ///< Fault handler Usage Fault
        EXCEPTION_SVCALL = 11,      ///< System handler SVCall     
        EXCEPTION_DEBUGMON,         ///< Debug Monitor
        EXCEPTION_PENDSV = 14,      ///< System ISR PendSV 
        EXCEPTION_SYSTICK,          ///< System ISR SysTick
        
        // STM32F103xx like XL-density (Non-connectivity) device interrupts
        EXCEPTION_WWDG,             ///< Window Watchdog                               
        EXCEPTION_PVD,              ///< PVD through EXTI Line detect                  
        EXCEPTION_TAMPER,           ///< Tamper                                        
        EXCEPTION_RTC,              ///< RTC                                           
        EXCEPTION_FLASH,            ///< Flash                                         
        EXCEPTION_RCC,              ///< RCC                                           
        EXCEPTION_EXTI0,            ///< EXTI Line 0                                   
        EXCEPTION_EXTI1,            ///< EXTI Line 1                                   
        EXCEPTION_EXTI2,            ///< EXTI Line 2                                   
        EXCEPTION_EXTI3,            ///< EXTI Line 3                                   
        EXCEPTION_EXTI4,            ///< EXTI Line 4                                   
        EXCEPTION_DMA1_CHANNEL1,    ///< DMA Channel 1                                 
        EXCEPTION_DMA1_CHANNEL2,    ///< DMA Channel 2                                 
        EXCEPTION_DMA1_CHANNEL3,    ///< DMA Channel 3                                 
        EXCEPTION_DMA1_CHANNEL4,    ///< DMA Channel 4                                 
        EXCEPTION_DMA1_CHANNEL5,    ///< DMA Channel 5                                 
        EXCEPTION_DMA1_CHANNEL6,    ///< DMA Channel 6                                 
        EXCEPTION_DMA1_CHANNEL7,    ///< DMA Channel 7                                 
        EXCEPTION_ADC1_2,           ///< ADC                                           
        EXCEPTION_USB_HP_CAN1_TX,   ///< USB High Priority or CAN1 TX                  
        EXCEPTION_USB_LP_CAN1_RX0,  ///< USB Low  Priority or CAN1 RX0                 
        EXCEPTION_CAN1_RX1,         ///< CAN1 RX1                                      
        EXCEPTION_CAN1_SCE,         ///< CAN1 SCE                                      
        EXCEPTION_EXTI9_5,          ///< EXTI Line 9..5                                
        EXCEPTION_TIM1_BRK,         ///< TIM1 Break                                    
        EXCEPTION_TIM1_UP,          ///< TIM1 Update                                   
        EXCEPTION_TIM1_TRG_COM,     ///< TIM1 Trigger and Commutation                  
        EXCEPTION_TIM1_CC,          ///< TIM1 Capture Compare                          
        EXCEPTION_TIM2,             ///< TIM2                                          
        EXCEPTION_TIM3,             ///< TIM3                                          
        EXCEPTION_TIM4,             ///< TIM4                                          
        EXCEPTION_I2C1_EV,          ///< I2C1 Event                                    
        EXCEPTION_I2C1_ER,          ///< I2C1 Error                                    
        EXCEPTION_I2C2_EV,          ///< I2C2 Event                                    
        EXCEPTION_I2C2_ER,          ///< I2C2 Error                                    
        EXCEPTION_SPI1,             ///< SPI1                                          
        EXCEPTION_SPI2,             ///< SPI2                                          
        EXCEPTION_USART1,           ///< USART1                                        
        EXCEPTION_USART2,           ///< USART2                                        
        EXCEPTION_USART3,           ///< USART3                                        
        EXCEPTION_EXTI15_10,        ///< EXTI Line 15..10                              
        EXCEPTION_RTCALARM,         ///< RTC Alarm through EXTI Line 17                
        EXCEPTION_USBWAKEUP,        ///< USB Wakeup from suspend                       
        EXCEPTION_TIM8_BRK,         ///< TIM8 Brake interrupt                          
        EXCEPTION_TIM8_UP,          ///< TIM8 Update interrupt                         
        EXCEPTION_TIM8_TRG_COM,     ///< TIM8 Trigger and communication interrupts     
        EXCEPTION_TIM8_CC,          ///< TIM8 Capture Compare Interrupt                
        EXCEPTION_ADC3,             ///< ADC3 Global Interrupts (including EXTI26)     
        EXCEPTION_FSMC,             ///< FSMC Global Interrupt                         
        EXCEPTION_SDIO,             ///< SDIO Global Interrupt                         
        EXCEPTION_TIM5,             ///< TIM5 Global Interrupt                         
        EXCEPTION_SPI3,             ///< SPI3 Global Interrupts                        
        EXCEPTION_UART4,            ///< UART4 Global Interrupt                        
        EXCEPTION_UART5,            ///< UART5 Global Interrupt                        
        EXCEPTION_TIM6,             ///< TIM6 Global Interruptions                     
        EXCEPTION_TIM7,             ///< TIM7 Global Interruptions                     
        EXCEPTION_DMA2_CHANNEL1,    ///< DMA2 Channel 1 Global Interrupt               
        EXCEPTION_DMA2_CHANNEL2,    ///< DMA2 Channel 2 Global Interrupt               
        EXCEPTION_DMA2_CHANNEL3,    ///< DMA2 Channel 3 Global Interrupt               
        EXCEPTION_DMA2_CHANNEL4_5,  ///< DMA2 Channel 4 and Channel 5 Global Interrupts
        
        EXCEPTION_LAST
    };
    
    /**
     * @struct Data
     * @brief Global data for all these objects;
     */
    struct Data
    {
        /**
         * @brief Constructor.
         *
         * @param reg Target CPU register model.     
         * @param gie Global interrupt enable controller.     
         */
        Data(Registers& areg, api::Guard& agie);
        
        /**
         * @brief Target CPU register model.
         */
        Registers& reg;

        /**
         * @brief Global interrupt enable controller.
         */
        api::Guard& gie;
        
        /**
         * @brief Interrupt handlers.
         */        
        api::Runnable* handlers[EXCEPTION_LAST];
    };

    /**
     * @brief Constructor.
     *
     * @param data Global data for all theses objects
     * @param handler User class which implements an interrupt handler interface.
     * @param exception Exception number.
     */
    Interrupt(Data& data, api::Runnable& handler, int32_t exception);
    
    /** 
     * @brief Destructor.
     */                               
    virtual ~Interrupt();
    
    /**
     * @copydoc eoos::api::Object::isConstructed()
     */
    virtual bool_t isConstructed() const;    

    /**
     * @copydoc eoos::api::CpuInterrupt::disable()
     */
    virtual void disable();

    /**
     * @copydoc eoos::api::CpuInterrupt::enable()
     */
    virtual void enable();
    
    /**
     * @brief Test if exception number is valid.
     *
     * @param exception Exception number.
     * @return True is is valid.
     */
    static bool_t isException(int32_t exception);

protected:

    using Parent::setConstructed;
    
private:

    /**
     * @brief Constructs this object.
     *
     * @return true if object has been constructed successfully.
     */
    bool_t construct();

    /**
     * @brief Destructs this object.
     */
    void destruct();
    
    /**
     * @brief Disables IRQ exception.
     */
    void disableIrq();

    /**
     * @brief Enables IRQ exception.
     */
    void enableIrq();
    
    /**
     * @brief Sets exception handler.
     *
     * @param handler A user class interface that implements an interrupt handler interface.
     * @param exception An exception number.
     * @return True if handler is set successfully.
     */      
    bool_t setHandler(api::Runnable& handler, int32_t exception);    
    
    /**
     * @brief First IRQ exception.
     */    
    static const int32_t EXCEPTION_FIRST_IRQ = 16;
    
    /**
     * @brief User class which implements an interrupt handler interface.
     */
    api::Runnable& handler_;    

    /**
     * @brief This resource exception number.
     */
    int32_t exception_;

    /**
     * @brief Global data for all these objects;
     */
    Data& data_;

};

template <class A>
Interrupt<A>::Interrupt(Data& data, api::Runnable& handler, int32_t exception)
    : NonCopyable<A>()
    , api::CpuInterrupt()
    , handler_( handler )
    , exception_( exception )
    , data_( data ) {
    bool_t const isConstructed( construct() );
    setConstructed( isConstructed );
}    

template <class A>
Interrupt<A>::~Interrupt()
{
    destruct();
}

template <class A>
bool_t Interrupt<A>::isConstructed() const
{
    return Parent::isConstructed();
}

template <class A>
void Interrupt<A>::disable()
{
    if( isConstructed() )
    {
        switch(exception_)
        {
            case EXCEPTION_SYSTICK:
            {
                lib::Guard<A> const guard(data_.gie);
                // Disable SysTick exception
                data_.reg.scs.tick->csr.bit.tickint = 0;
                break;
            }
            default:
            {
                if(EXCEPTION_FIRST_IRQ <= exception_ && exception_ < EXCEPTION_LAST)
                {
                    disableIrq();
                }
                break;
            }            
        }
    }    
}

template <class A>
void Interrupt<A>::enable()
{
    if( isConstructed() )
    {
        switch(exception_)
        {
            case EXCEPTION_SYSTICK:
            {
                lib::Guard<A> const guard(data_.gie);
                // Enable SysTick exception to set count to 0 changes the SysTick exception status to pending
                data_.reg.scs.tick->csr.bit.tickint = 1;
                break;
            }
            default:
            {
                if(EXCEPTION_FIRST_IRQ <= exception_ && exception_ < EXCEPTION_LAST)
                {
                    enableIrq();
                }
                break;
            }
        }
    }
}

template <class A>
bool_t Interrupt<A>::isException(int32_t exception)
{
    if(EXCEPTION_NMI <= exception && exception < EXCEPTION_USAGEFAULT)
    {
        return true;
    }
    if(EXCEPTION_SVCALL <= exception && exception <= EXCEPTION_DEBUGMON)
    {
        return true;
    }    
    if(EXCEPTION_PENDSV <= exception && exception <= EXCEPTION_DMA2_CHANNEL4_5)
    {
        return true;
    }
    return false;
}

template <class A>
void Interrupt<A>::disableIrq()
{
    int32_t const irq = exception_ - EXCEPTION_FIRST_IRQ;
    uint32_t bitValue( 0x00000001 );
    uint32_t const bitNumber( irq % 32 );    
    for(uint32_t i(0U); i<bitNumber; i++)
    {
        bitValue <<= 1;
    }
    int32_t const index( irq / 32 );
    {
        lib::Guard<A> const guard(data_.gie);
        uint32_t regValue( data_.reg.scs.nvic->icer[index].value );
        regValue |= bitValue;
        data_.reg.scs.nvic->icer[index].value = regValue;
    }    
}

template <class A>
void Interrupt<A>::enableIrq()
{
    int32_t const irq = exception_ - EXCEPTION_FIRST_IRQ;
    uint32_t bitValue( 0x00000001 );
    uint32_t const bitNumber( irq % 32 );    
    for(uint32_t i(0U); i<bitNumber; i++)
    {
        bitValue <<= 1;
    }
    int32_t const index( irq / 32 );
    {
        lib::Guard<A> const guard(data_.gie);
        uint32_t regValue( data_.reg.scs.nvic->iser[index].value );
        regValue |= bitValue;
        data_.reg.scs.nvic->iser[index].value = regValue;
    }    
}

template <class A>
bool_t Interrupt<A>::construct()
{
    bool_t res( false );
    do 
    {
        if( !isConstructed() )
        {
            break;
        }
        if( !isException(exception_) )
        {
            break;
        }
        if( !setHandler(handler_, exception_) )
        {
            break;
        }
        res = true;
    } while(false);
    return res;    
}

template <class A>
void Interrupt<A>::destruct()
{
    Interrupt<A>::disable();
    lib::Guard<A> const guard(data_.gie);
    data_.handlers[exception_] = NULLPTR;
}

template <class A>
bool_t Interrupt<A>::setHandler(api::Runnable& handler, int32_t exception)
{
    lib::Guard<A> const guard(data_.gie);
    if(exception >= EXCEPTION_LAST)
    {
        return false;
    }
    if( data_.handlers[exception] != NULLPTR )
    {
        return false;
    }
    data_.handlers[exception] = &handler;
    return true;
}

template <class A>
Interrupt<A>::Data::Data(Registers& areg, api::Guard& agie)
    : reg(areg)
    , gie(agie) {
    for(int32_t i(0); i<EXCEPTION_LAST; i++)
    {
        handlers[i] = NULLPTR;
    }
    handlers[EXCEPTION_LAST] = reinterpret_cast<api::Runnable*>(0xFFFFFFFF);
}

} // namespace cpu
} // namespace eoos
#endif // CPU_INTERRUPT_HPP_
