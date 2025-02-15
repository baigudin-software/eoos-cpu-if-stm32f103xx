/**
 * @file      cpu.reg.Auxiliary.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_AUXILIARY_HPP_
#define CPU_REG_AUXILIARY_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Auxiliary
 * @brief Interrupt Controller Type and Auxiliary Control registers of System Control Space.
 */
struct Auxiliary
{

public:
  
    /**
     * @brief System Control address.
     */    
    static const uint32_t ADDRESS = 0xE000E008;
        
    /** 
     * @brief Constructor.
     */  
    Auxiliary()
        : actlr() {
    }

    /** 
     * @brief Destructor.
     */  
    ~Auxiliary(){}
   
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
     * @brief Auxiliary Control Register.
     */
    union Actlr
    {
        typedef uint32_t Value;
        Actlr(){}
        Actlr(Value v){value = v;}
       ~Actlr(){}    
      
        Value value;
        struct Bit
        {
            Value dismcycint : 1;
            Value disdefwbuf : 1;
            Value disfold    : 1;
            Value            : 29;
        } bit;
    };
    
    /**
     * @brief Register map.
     */
public:
    Actlr       actlr;   // 0xE008
};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_AUXILIARY_HPP_
