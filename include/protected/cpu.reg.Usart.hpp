/**
 * @file      cpu.reg.Usart.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_USART_HPP_
#define CPU_REG_USART_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Usart
 * @brief Universal Synchronous Asynchronous Transceiver (USART).
 */
struct Usart
{

public:
  
    /**
     * @brief Addresses.
     */    
    static const uint32_t ADDRESS_USART1 = 0x40013800;
    static const uint32_t ADDRESS_USART2 = 0x40004400;
    static const uint32_t ADDRESS_USART3 = 0x40004800;
    static const uint32_t ADDRESS_UART4  = 0x40004C00;
    static const uint32_t ADDRESS_UART5  = 0x40005000;

    /** 
     * @brief Constructor.
     */  
    Usart()
        : sr()
        , dr()
        , brr()
        , cr1()
        , cr2()
        , cr3()
        , gtpr() {
    }

    /** 
     * @brief Destructor.
     */  
    ~Usart(){}
   
    /**
     * @brief Operator new.
     *
     * @param size Unused.
     * @param ptr  Address of memory.
     * @return The address of memory.
     */
    void* operator new(size_t, uint32_t ptr)
    {
        return reinterpret_cast<void*>(ptr);
    }

    /**
     * @brief Status register (USARTx_SR).
     */     
    union Sr
    {
        typedef uint32_t Value;
        Sr(){}
        Sr(Value v){value = v;}
       ~Sr(){}    
      
        Value value;
        struct Bit 
        {
            Value pe   : 1;
            Value fe   : 1;
            Value ne   : 1;
            Value ore  : 1;
            Value idle : 1;
            Value rxne : 1;
            Value tc   : 1;
            Value txe  : 1;
            Value lbd  : 1;
            Value cts  : 1;
            Value      : 22;
        } bit;
    };

    /**
     * @brief Data register (USARTx_DR).
     */     
    union Dr
    {
        typedef uint32_t Value;
        Dr(){}
        Dr(Value v){value = v;}
       ~Dr(){}    
      
        Value value;
        struct Bit 
        {
            Value dr : 9;
            Value    : 23;            
        } bit;
    };

    /**
     * @brief Baud Rate Register (USARTx_BRR).
     */
    union Brr
    {
        typedef uint32_t Value;
        Brr(){}
        Brr(Value v){value = v;}
       ~Brr(){}    
      
        Value value;
        struct Bit 
        {
            Value divfraction : 4;
            Value divmantissa : 12;
            Value             : 16;
        } bit;
    };

    /**
     * @brief Control register 1 (USARTx_CR1).
     */
    union Cr1
    {
        typedef uint32_t Value;
        Cr1(){}
        Cr1(Value v){value = v;}
       ~Cr1(){}    
      
        Value value;
        struct Bit 
        {
            Value sbk    : 1;
            Value rwu    : 1;
            Value re     : 1;
            Value te     : 1;
            Value idleie : 1;
            Value rxneie : 1;
            Value tcie   : 1;
            Value txeie  : 1;
            Value peie   : 1;
            Value ps     : 1;
            Value pce    : 1;
            Value wake   : 1;
            Value m      : 1;
            Value ue     : 1;
            Value        : 18;
        } bit;
    };

    /**
     * @brief Control register 2 (USARTx_CR2).
     */
    union Cr2
    {
        typedef uint32_t Value;
        Cr2(){}
        Cr2(Value v){value = v;}
       ~Cr2(){}    
      
        Value value;
        struct Bit 
        {
            Value add   : 4;
            Value       : 1;
            Value lbdl  : 1;
            Value lbdie : 1;
            Value       : 1;
            Value lbcl  : 1;
            Value cpha  : 1;
            Value cpol  : 1;
            Value clken : 1;
            Value stop  : 2;
            Value linen : 1;
            Value       : 17;
        } bit;
    };

    /**
     * @brief Control register 3 (USARTx_CR3).
     */
    union Cr3
    {
        typedef uint32_t Value;
        Cr3(){}
        Cr3(Value v){value = v;}
       ~Cr3(){}    
      
        Value value;
        struct Bit 
        {
            Value eie   : 1;
            Value iren  : 1;
            Value irlp  : 1;
            Value hdsel : 1;
            Value nack  : 1;
            Value scen  : 1;
            Value dmar  : 1;
            Value dmat  : 1;
            Value rtse  : 1;
            Value ctse  : 1;
            Value ctsie : 1;
            Value       : 21;
        } bit;
    };

    /**
     * @brief Protection Time and Prescaler Register (USARTx_GTPR).
     */
    union Gtpr
    {
        typedef uint32_t Value;
        Gtpr(){}
        Gtpr(Value v){value = v;}
       ~Gtpr(){}    
      
        Value value;
        struct Bit 
        {
            Value psc : 8;
            Value gt  : 8;
            Value     : 16;
        } bit;
    };
    
    /**
     * @brief Register map.
     */
public:
    Sr   sr;   // 0x00
    Dr   dr;   // 0x04
    Brr  brr;  // 0x08
    Cr1  cr1;  // 0x0C
    Cr2  cr2;  // 0x10
    Cr3  cr3;  // 0x14
    Gtpr gtpr; // 0x18
    
};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_USART_HPP_
