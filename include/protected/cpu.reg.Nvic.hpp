/**
 * @file      cpu.reg.Nvic.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_NVIC_HPP_
#define CPU_REG_NVIC_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Nvic
 * @brief Nested Vectored Interrupt Controller (NVIC).
 */
struct Nvic
{

public:
  
    /**
     * @brief System Control address.
     */    
    static const uint32_t ADDRESS = 0xE000E100;
        
    /** 
     * @brief Constructor.
     */  
    Nvic()
    {
    }

    /** 
     * @brief Destructor.
     */  
    ~Nvic(){}
   
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
     * @brief Interrupt Set-Enable Registers.
     */
    union Iser
    {
        typedef uint32_t Value;
        Iser(){}
        Iser(Value v){value = v;}
       ~Iser(){}    
      
        Value value;
        struct Bit 
        {
            Value setena : 32;
        } bit;
    };

    /**
     * @brief Interrupt Clear-Enable Registers.
     */
    union Icer
    {
        typedef uint32_t Value;
        Icer(){}
        Icer(Value v){value = v;}
       ~Icer(){}    
      
        Value value;
        struct Bit 
        {
            Value clrena : 32;
        } bit;
    };

    /**
     * @brief Interrupt Set-Pending Registers.
     */
    union Ispr
    {
        typedef uint32_t Value;
        Ispr(){}
        Ispr(Value v){value = v;}
       ~Ispr(){}    
      
        Value value;
        struct Bit 
        {
            Value setpend : 32;
        } bit;
    };

    /**
     * @brief Interrupt Clear-Pending Registers.
     */
    union Icpr
    {
        typedef uint32_t Value;
        Icpr(){}
        Icpr(Value v){value = v;}
       ~Icpr(){}    
      
        Value value;
        struct Bit 
        {
            Value clrpend : 32;
        } bit;
    };

    /**
     * @brief Interrupt Active Bit Registers.
     */
    union Iabr
    {
        typedef uint32_t Value;
        Iabr(){}
        Iabr(Value v){value = v;}
       ~Iabr(){}    
      
        Value value;
        struct Bit 
        {
            Value active : 32;
        } bit;
    };

    /**
     * @brief Interrupt Priority Registers.
     */
    union Ipr
    {
        typedef uint32_t Value;
        Ipr(){}
        Ipr(Value v){value = v;}
       ~Ipr(){}    
      
        Value value;
        struct Bit 
        {
            Value priN0 : 8;
            Value priN1 : 8;
            Value priN2 : 8;
            Value priN3 : 8;
        } bit;
    };

    
    /**
     * @brief Register map.
     */
public:
    Iser        iser[16];       // 0xE000E100-0xE000E13C
private:
    uint32_t    space0_[16];
public:
    Icer        icer[16];       // 0xE000E180-0xE000E1BC
private:
    uint32_t    space1_[16];    
public:
    Ispr        ispr[16];       // 0xE000E200-0xE000E23C
private:
    uint32_t    space2_[16];
public:
    Icpr        icpr[16];       // 0xE000E280-0xE000E2BC
private:
    uint32_t    space3_[16];
public:
    Iabr        iabr[16];       // 0xE000E300-0xE000E33C
private:
    uint32_t    space4_[48];
public:
    Ipr         ipr[124];       // 0xE000E400-0xE000E5EC
};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_NVIC_HPP_
