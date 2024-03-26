/**
 * @file      cpu.reg.SysTick.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_SYSTICK_HPP_
#define CPU_REG_SYSTICK_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct SysTick
 * @brief System tick of System Control Space.
 */
struct SysTick
{

public:
  
    /**
     * @brief System Control address.
     */    
    static const uint32_t ADDRESS = 0xE000E010;
        
    /** 
     * @brief Constructor.
     */  
    SysTick()
        : csr()      
        , rvr()      
        , cvr()      
        , cr() {
    }

    /** 
     * @brief Destructor.
     */  
    ~SysTick(){}
   
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
     * @brief SysTick Control and Status Register.
     */
    union Csr
    {
        typedef uint32_t Value;
        Csr(){}
        Csr(Value v){value = v;}
       ~Csr(){}    
      
        Value value;
        struct Bit 
        {
            Value enable    : 1;
            Value tickint   : 1;
            Value clksource : 1;
            Value           : 13;
            Value countflag : 1;
            Value           : 15;
        } bit;
    };

    /**
     * @brief SysTick Reload Value Register.
     */
    union Rvr
    {
        typedef uint32_t Value;
        Rvr(){}
        Rvr(Value v){value = v;}
       ~Rvr(){}    
      
        Value value;
        struct Bit 
        {
            Value reload : 24;
            Value        : 8;
        } bit;
    };

    /**
     * @brief SysTick Current Value Register.
     */
    union Cvr
    {
        typedef uint32_t Value;
        Cvr(){}
        Cvr(Value v){value = v;}
       ~Cvr(){}    
      
        Value value;
        struct Bit 
        {
            Value current : 32;
        } bit;
    };

    /**
     * @brief SysTick Calibration Value Register.
     */
    union Cr
    {
        typedef uint32_t Value;
        Cr(){}
        Cr(Value v){value = v;}
       ~Cr(){}    
      
        Value value;
        struct Bit 
        {
            Value tenms : 24;
            Value       : 6;
            Value skew  : 1;
            Value noref : 1;
        } bit;
    };
    
    /**
     * @brief Register map.
     */
public:
    Csr csr;   // 0xE000E010
    Rvr rvr;   // 0xE000E014
    Cvr cvr;   // 0xE000E018
    Cr  cr;    // 0xE000E01C
};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_SYSTICK_HPP_
