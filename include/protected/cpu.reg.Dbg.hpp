/**
 * @file      cpu.reg.Dbg.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2024, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_DBG_HPP_
#define CPU_REG_DBG_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Dbg
 * @brief Debug MCU.
 */
struct Dbg
{

public:
  
    /**
     * @brief System Control address.
     */    
    static const uint32_t ADDRESS = 0xE0042000;
        
    /** 
     * @brief Constructor.
     */  
    Dbg()
        : idcode()
        , cr() {
    }

    /** 
     * @brief Destructor.
     */  
    ~Dbg(){}
   
    /**
     * @brief Operator new.
     *
     * @param size Unused.
     * @param ptr  Address of memory.
     * @return The address of memory.
     */
    static void* operator new(size_t, uint32_t ptr)
    {
        return reinterpret_cast<void*>(ptr);
    }

    /**
     * @brief MCU device ID code (DBGMCU_IDCODE).
     */
    union Idcode
    {
        typedef uint32_t Value;
        Idcode(){}
        Idcode(Value v){value = v;}
       ~Idcode(){}    
      
        Value value;
        struct Bit 
        {
            Value devid : 12;
            Value       : 4;
            Value revid : 16;
        } bit;
    };

    /**
     * @brief Debug MCU configuration (DBGMCU_CR).
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
            Value dbgsleep            : 1;
            Value dbgstop             : 1;
            Value dbgstandby          : 1;
            Value                     : 2;
            Value traceioen           : 1;
            Value tracemode           : 2;
            Value dbgiwdgtop          : 1;
            Value dbgwwdgstop         : 1;
            Value dbgtim1stop         : 1;
            Value dbgtim2stop         : 1;
            Value dbgtim3stop         : 1;
            Value dbgtim4stop         : 1;
            Value dbgcan1stop         : 1;
            Value dbgi2c1smbustimeout : 1;
            Value dbgi2c2smbustimeout : 1;
            Value dbgtim8stop         : 1;
            Value dbgtim5stop         : 1;
            Value dbgtim6stop         : 1;
            Value dbgtim7stop         : 1;
            Value dbgcan2stop         : 1;
            Value                     : 10;
        } bit;
    };
    
    /**
     * @brief Register map.
     */
public:
    Idcode idcode; // 0xE0042000
    Cr     cr;     // 0xE0042004

};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_DBG_HPP_
