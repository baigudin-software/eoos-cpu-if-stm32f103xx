/**
 * @file      cpu.reg.Gpio.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_GPIO_HPP_
#define CPU_REG_GPIO_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Gpio
 * @brief General-purpose Input Output (GPIO).
 */
struct Gpio
{

public:
  
    /**
     * @brief Addresses.
     */    
    static const uint32_t ADDRESS_GPIOA = 0x40010800;
    static const uint32_t ADDRESS_GPIOB = 0x40010C00;
    static const uint32_t ADDRESS_GPIOC = 0x40011000;
    static const uint32_t ADDRESS_GPIOD = 0x40011400;
    static const uint32_t ADDRESS_GPIOE = 0x40011800;

    /** 
     * @brief Constructor.
     */  
    Gpio()
        : crl() 
        , crh() 
        , idr()
        , odr()
        , bsrr()
        , brr()
        , lckr()
        , iosen() {    
    }

    /** 
     * @brief Destructor.
     */  
    ~Gpio(){}
   
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
     * @brief Port x Configuration Low Register (GPIOx_CRL).
     */     
    union Crl
    {
        typedef uint32_t Value;
        Crl(){}
        Crl(Value v){value = v;}
       ~Crl(){}    
      
        Value value;
        struct Bit 
        {
            Value mode0 : 2;
            Value cnf0  : 2;
            Value mode1 : 2;
            Value cnf1  : 2;
            Value mode2 : 2;
            Value cnf2  : 2;
            Value mode3 : 2;
            Value cnf3  : 2;
            Value mode4 : 2;
            Value cnf4  : 2;
            Value mode5 : 2;
            Value cnf5  : 2;
            Value mode6 : 2;
            Value cnf6  : 2;
            Value mode7 : 2;
            Value cnf7  : 2;
        } bit;
    };

    /**
     * @brief Port x Configuration High Register (GPIOx_CRH).
     */     
    union Crh
    {
        typedef uint32_t Value;
        Crh(){}
        Crh(Value v){value = v;}
       ~Crh(){}    
      
        Value value;
        struct Bit 
        {
            Value mode8  : 2;
            Value cnf8   : 2;
            Value mode9  : 2;
            Value cnf9   : 2;
            Value mode10 : 2;
            Value cnf10  : 2;
            Value mode11 : 2;
            Value cnf11  : 2;
            Value mode12 : 2;
            Value cnf12  : 2;
            Value mode13 : 2;
            Value cnf13  : 2;
            Value mode14 : 2;
            Value cnf14  : 2;
            Value mode15 : 2;
            Value cnf15  : 2;
        } bit;
    };

    /**
     * @brief Port x Input Data Register (GPIOx_IDR).
     */     
    union Idr
    {
        typedef uint32_t Value;
        Idr(){}
        Idr(Value v){value = v;}
       ~Idr(){}    
      
        Value value;
        struct Bit 
        {
            Value idr0  : 1;
            Value idr1  : 1;
            Value idr2  : 1;
            Value idr3  : 1;
            Value idr4  : 1;
            Value idr5  : 1;
            Value idr6  : 1;
            Value idr7  : 1;
            Value idr8  : 1;
            Value idr9  : 1;
            Value idr10 : 1;
            Value idr11 : 1;
            Value idr12 : 1;
            Value idr13 : 1;
            Value idr14 : 1;
            Value idr15 : 1;
            Value       : 15;
        } bit;
    };

    /**
     * @brief Port x Output Data Register (GPIOx_ODR).
     */     
    union Odr
    {
        typedef uint32_t Value;
        Odr(){}
        Odr(Value v){value = v;}
       ~Odr(){}    
      
        Value value;
        struct Bit 
        {
            Value odr0  : 1;
            Value odr1  : 1;
            Value odr2  : 1;
            Value odr3  : 1;
            Value odr4  : 1;
            Value odr5  : 1;
            Value odr6  : 1;
            Value odr7  : 1;
            Value odr8  : 1;
            Value odr9  : 1;
            Value odr10 : 1;
            Value odr11 : 1;
            Value odr12 : 1;
            Value odr13 : 1;
            Value odr14 : 1;
            Value odr15 : 1;
            Value       : 15;
        } bit;
    };

    /**
     * @brief Port x bit set/clear register (GPIOx_BSRR).
     */     
    union Bsrr
    {
        typedef uint32_t Value;
        Bsrr(){}
        Bsrr(Value v){value = v;}
       ~Bsrr(){}    
      
        Value value;
        struct Bit 
        {
            Value bs0  : 1;
            Value bs1  : 1;
            Value bs2  : 1;
            Value bs3  : 1;
            Value bs4  : 1;
            Value bs5  : 1;
            Value bs6  : 1;
            Value bs7  : 1;
            Value bs8  : 1;
            Value bs9  : 1;
            Value bs10 : 1;
            Value bs11 : 1;
            Value bs12 : 1;
            Value bs13 : 1;
            Value bs14 : 1;
            Value bs15 : 1;
            Value br0  : 1;
            Value br1  : 1;
            Value br2  : 1;
            Value br3  : 1;
            Value br4  : 1;
            Value br5  : 1;
            Value br6  : 1;
            Value br7  : 1;
            Value br8  : 1;
            Value br9  : 1;
            Value br10 : 1;
            Value br11 : 1;
            Value br12 : 1;
            Value br13 : 1;
            Value br14 : 1;
            Value br15 : 1;
        } bit;
    };

    /**
     * @brief Port x bit clear register (GPIOx_BRR).
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
            Value br0  : 1;
            Value br1  : 1;
            Value br2  : 1;
            Value br3  : 1;
            Value br4  : 1;
            Value br5  : 1;
            Value br6  : 1;
            Value br7  : 1;
            Value br8  : 1;
            Value br9  : 1;
            Value br10 : 1;
            Value br11 : 1;
            Value br12 : 1;
            Value br13 : 1;
            Value br14 : 1;
            Value br15 : 1;
            Value      : 15;
        } bit;
    };

    /**
     * @brief Port x Configuration Lock Register (GPIOx_LCKR).
     */     
    union Lckr
    {
        typedef uint32_t Value;
        Lckr(){}
        Lckr(Value v){value = v;}
       ~Lckr(){}    
      
        Value value;
        struct Bit 
        {
            Value lck0  : 1;
            Value lck1  : 1;
            Value lck2  : 1;
            Value lck3  : 1;
            Value lck4  : 1;
            Value lck5  : 1;
            Value lck6  : 1;
            Value lck7  : 1;
            Value lck8  : 1;
            Value lck9  : 1;
            Value lck10 : 1;
            Value lck11 : 1;
            Value lck12 : 1;
            Value lck13 : 1;
            Value lck14 : 1;
            Value lck15 : 1;
            Value lckk  : 1;
            Value       : 14;
        } bit;
    };

    /**
     * @brief Port x Schmitt Trigger Configuration Register (GPIOx_IOSEN).
     */     
    union Iosen
    {
        typedef uint32_t Value;
        Iosen(){}
        Iosen(Value v){value = v;}
       ~Iosen(){}    
      
        Value value;
        struct Bit 
        {
            Value iosen0  : 1;
            Value iosen1  : 1;
            Value iosen2  : 1;
            Value iosen3  : 1;
            Value iosen4  : 1;
            Value iosen5  : 1;
            Value iosen6  : 1;
            Value iosen7  : 1;
            Value iosen8  : 1;
            Value iosen9  : 1;
            Value iosen10 : 1;
            Value iosen11 : 1;
            Value iosen12 : 1;
            Value iosen13 : 1;
            Value iosen14 : 1;
            Value iosen15 : 1;
            Value         : 15;
        } bit;
    };
    
    /**
     * @brief Register map.
     */
public:
    Crl      crl;   // 0x00
    Crh      crh;   // 0x04
    Idr      idr;   // 0x08
    Odr      odr;   // 0x0C
    Bsrr     bsrr;  // 0x10
    Brr      brr;   // 0x14
    Lckr     lckr;  // 0x18
private:
    uint32_t space0_[5];
public:
    Iosen    iosen; // 0x30
    
};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_GPIO_HPP_
