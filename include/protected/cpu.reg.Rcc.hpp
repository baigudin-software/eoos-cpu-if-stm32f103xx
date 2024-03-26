/**
 * @file      cpu.reg.Rcc.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_RCC_HPP_
#define CPU_REG_RCC_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Rcc
 * @brief HK32F103xCxDxE Reset and clock control (RCC).
 */
struct Rcc
{

public:
  
    /**
     * @brief RCC address.
     */    
    static const uint32_t ADDRESS = 0x40021000;
        
    /** 
     * @brief Constructor.
     */  
    Rcc() 
        : cr()
        , cfgr()
        , cir()
        , apb2rstr()
        , apb1rstr()
        , ahbenr()
        , apb2enr()
        , apb1enr()
        , bdcr()
        , csr()
        , cfgr2()  
        , cfgr3()  
        , cr2()    
        , hsectl() 
        , pllctl() 
        , cfgr4()  
        , cfgr5()  
        , cfgr6()  
        , ahbrst2()
        , ahbrst3()
        , lsictl() {
    }
  
    /** 
     * @brief Destructor.
     */  
    ~Rcc(){}
   
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
     * @brief Clock control register (RCC_CR).
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
            Value hsion    : 1;
            Value hsirdy   : 1;
            Value          : 1;
            Value hsitrim  : 5;
            Value hsical   : 8;
            Value hseon    : 1;
            Value hserdy   : 1;
            Value hsebyp   : 1;
            Value csson    : 1;
            Value          : 4;
            Value pllon    : 1;
            Value pllrdy   : 1;
            Value          : 6;
        } bit;
    };
    
    /**
     * @brief Clock configuration register (RCC_CFGR).
     */
    union Cfgr
    {
        typedef uint32_t Value;        
        Cfgr(){}
        Cfgr(Value v){value = v;}
       ~Cfgr(){}    
      
        Value value;
        struct Bit 
        {
            Value sw       : 2;
            Value sws      : 2;
            Value hpre     : 4;
            Value ppre1    : 3;
            Value ppre2    : 3;
            Value adcpre   : 2;
            Value pllsrc   : 1;
            Value pllxtpre : 1;
            Value pllmul   : 4;
            Value usbpre   : 1;
            Value          : 1;
            Value mco      : 3;
            Value          : 5;
        } bit;
    };
    
    /**
     * @brief Clock interrupt register (RCC_CIR).
     */
    union Cir
    {
        typedef uint32_t Value;
        Cir(){}
        Cir(Value v){value = v;}
       ~Cir(){}    
      
        Value value;
        struct Bit 
        {
            Value lsirdyf  : 1;          
            Value lserdyf  : 1;
            Value hsirdyf  : 1;
            Value hserdyf  : 1;
            Value pllrdyf  : 1;
            Value          : 2;
            Value cssf     : 1;
            Value lsirdyie : 1;
            Value lserdyie : 1;
            Value hsirdyie : 1;
            Value hserdyie : 1;
            Value pllrdyie : 1;
            Value          : 3;
            Value lsirdyc  : 1;
            Value lserdyc  : 1;
            Value hsirdyc  : 1;
            Value hserdyc  : 1;
            Value pllrdyc  : 1;
            Value          : 2;
            Value cssc     : 1;
            Value          : 8;           
        } bit;
    };
        
    /**
     * @brief APB2 peripheral reset register (RCC_APB2RSTR).
     */
    union Apb2rstr
    {
        typedef uint32_t Value;
        Apb2rstr(){}
        Apb2rstr(Value v){value = v;}
       ~Apb2rstr(){}    
      
        Value value;
        struct Bit 
        {
            Value afiorst   : 1;           
            Value           : 1;
            Value ioparst   : 1;
            Value iopbrst   : 1;
            Value iopcrst   : 1;
            Value iopdrst   : 1;
            Value ioperst   : 1;
            Value           : 1; // iopfrst
            Value iopgrst   : 1;
            Value adc1rst   : 1;
            Value adc2rst   : 1;
            Value tim1rst   : 1;
            Value spi1rst   : 1;
            Value tim8rst   : 1;
            Value usart1rst : 1;
            Value adc3rst   : 1;
            Value           : 3;
            Value           : 1; // tim9rst 
            Value           : 1; // tim10rst
            Value           : 1; // tim11rst
            Value           : 10;
        } bit;
    };

    /**
     * @brief APB1 peripheral reset register (RCC_APB1RSTR).
     */
    union Apb1rstr
    {
        typedef uint32_t Value;
        Apb1rstr(){}
        Apb1rstr(Value v){value = v;}
       ~Apb1rstr(){}    
      
        Value value;
        struct Bit 
        {
            Value tim2rst   : 1;
            Value tim3rst   : 1;
            Value tim4rst   : 1;
            Value tm5rst    : 1;
            Value tm6rst    : 1;
            Value tm7rst    : 1;
            Value           : 1; // tim12rst
            Value           : 1; // tim13rst
            Value           : 1; // tim14rst
            Value           : 2;
            Value wwdgrst   : 1;
            Value           : 2;
            Value spi2rst   : 1;
            Value spi3rst   : 1;
            Value           : 1;
            Value usart2rst : 1;
            Value usart3rst : 1;
            Value uart4rst  : 1;
            Value uart5rst  : 1;
            Value i2c1rst   : 1;
            Value i2c2rst   : 1;
            Value usbrst    : 1;
            Value           : 1;
            Value canrst    : 1;
            Value           : 1;
            Value bkprst    : 1;
            Value pwrrst    : 1;
            Value dacrst    : 1;
            Value           : 2;
        } bit;
    };

    /**
     * @brief AHB peripheral clock enable register (RCC_AHBENR).
     */
    union Ahbenr
    {
        typedef uint32_t Value;
        Ahbenr(){}
        Ahbenr(Value v){value = v;}
       ~Ahbenr(){}    
      
        Value value;
        struct Bit 
        {
            Value dma1en   : 1;
            Value dma2en   : 1;
            Value sramen   : 1;
            Value          : 1;
            Value flitfen  : 1;
            Value          : 1;
            Value crcen    : 1;
            Value          : 1;
            Value fsmcen   : 1;
            Value          : 1;
            Value sdioen   : 1;
            Value          : 21;
        } bit;
    };
    
    /**
     * @brief APB2 peripheral clock enable register (RCC_APB2ENR).
     */
    union Apb2enr
    {
        typedef uint32_t Value;
        Apb2enr(){}
        Apb2enr(Value v){value = v;}
       ~Apb2enr(){}    
      
        Value value;
        struct Bit 
        {
            Value afioen   : 1;
            Value          : 1;
            Value iopaen   : 1;
            Value iopben   : 1;
            Value iopcen   : 1;
            Value iopden   : 1;
            Value iopeen   : 1;
            Value          : 1; // iopfen
            Value          : 1; // iopgen
            Value adc1en   : 1;
            Value adc2en   : 1;
            Value tim1en   : 1;
            Value spi1en   : 1;
            Value tim8en   : 1;
            Value usart1en : 1;
            Value adc3en   : 1;
            Value          : 3;
            Value          : 1; // tim9en 
            Value          : 1; // tim10en
            Value          : 1; // tim11en
            Value          : 10;
        } bit;
    };
    
    /**
     * @brief APB1 peripheral clock enable register (RCC_APB1ENR).
     */
    union Apb1enr
    {
        typedef uint32_t Value;
        Apb1enr(){}
        Apb1enr(Value v){value = v;}
       ~Apb1enr(){}    
      
        Value value;
        struct Bit 
        {
            Value tim2en   : 1;
            Value tim3en   : 1;
            Value tim4en   : 1;
            Value tim5en   : 1;
            Value tim6en   : 1;
            Value tim7en   : 1;
            Value          : 1; // tim12en
            Value          : 1; // tim13en
            Value          : 1; // tim14en
            Value          : 2;
            Value wwdgen   : 1;
            Value          : 2;
            Value spi2en   : 1;
            Value spi3en   : 1;
            Value          : 1;
            Value usart2en : 1;
            Value usart3en : 1;
            Value uart4en  : 1;
            Value uart5en  : 1;
            Value i2c1en   : 1;
            Value i2c2en   : 1;
            Value usben    : 1;
            Value          : 1;
            Value can1en   : 1;
            Value can2en   : 1;
            Value bkpen    : 1;
            Value pwren    : 1;
            Value dacen    : 1;
            Value          : 2;
        } bit;
    };

    /**
     * @brief Backup domain control register (RCC_BDCR).
     */
    union Bdcr
    {
        typedef uint32_t Value;
        Bdcr(){}
        Bdcr(Value v){value = v;}
       ~Bdcr(){}    
      
        Value value;
        struct Bit 
        {
            Value lseon    : 1;
            Value lserdy   : 1;
            Value lsebyp   : 1;
            Value          : 5;
            Value rtcsel   : 2;
            Value          : 5;
            Value rtcen    : 1;
            Value bdrst    : 1;
            Value          : 15;
        } bit;
    };

    /**
     * @brief Control/status register (RCC_CSR).
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
            Value lsion    : 1;
            Value lsirdy   : 1;
            Value          : 22;
            Value rmvf     : 1;
            Value          : 1;
            Value pinrstf  : 1;
            Value porrstf  : 1;
            Value sftrstf  : 1;
            Value iwdgrstf : 1;
            Value wwdgrstf : 1;
            Value lpwrstf  : 1;
        } bit;
    };
    
    /**
     * @brief Clock Configuration Register 2 (RCC_CFGR2).
     */
    union Cfgr2
    {
        typedef uint32_t Value;
        Cfgr2(){}
        Cfgr2(Value v){value = v;}
       ~Cfgr2(){}    
      
        Value value;
        struct Bit 
        {
            Value prediv : 4;
            Value        : 28;
        } bit;
    };    
    
    /**
     * @brief Clock Configuration Register 3 (RCC_CFGR3).
     */
    union Cfgr3
    {
        typedef uint32_t Value;
        Cfgr3(){}
        Cfgr3(Value v){value = v;}
       ~Cfgr3(){}    
      
        Value value;
        struct Bit 
        {
            Value          : 8;
            Value usbsw    : 3;
            Value usbclken : 1;
            Value usbifsw  : 2;
            Value          : 6;
            Value adc1sw   : 3;
            Value adc2sw   : 3;
            Value adc3sw   : 3;
            Value          : 3;
        } bit;
    };

    /**
     * @brief Clock Control Register 2 (RCC_CR2).
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
            Value          : 16;
            Value hsi56on  : 1;
            Value hsi56rdy : 1;
            Value hsi28on  : 1;
            Value hsi28rdy : 1;
            Value          : 12;
        } bit;
    };

    /**
     * @brief HSE control register (RCC_HSECTL).
     */
    union Hsectl
    {
        typedef uint32_t Value;
        Hsectl(){}
        Hsectl(Value v){value = v;}
       ~Hsectl(){}    
      
        Value value;
        struct Bit 
        {
            Value hsewt        : 12;
            Value hsestopkeep  : 1;
            Value              : 3;
            Value xtal32m      : 8;
            Value hsenfbyp     : 1;
            Value cssthreshold : 7;
        } bit;
    };

    /**
     * @brief PLL Control Register (RCC_PLLCTL).
     */
    union Pllctl
    {
        typedef uint32_t Value;
        Pllctl(){}
        Pllctl(Value v){value = v;}
       ~Pllctl(){}    
      
        Value value;
        struct Bit 
        {
            Value       : 25;
            Value pllwt : 5;
            Value       : 2;
        } bit;
    };

    /**
     * @brief Clock Configuration Register 4 (RCC_CFGR4).
     */
    union Cfgr4
    {
        typedef uint32_t Value;
        Cfgr4(){}
        Cfgr4(Value v){value = v;}
       ~Cfgr4(){}    
      
        Value value;
        struct Bit 
        {
            Value pllmulh : 3;
            Value         : 1;
            Value ppss    : 1;
            Value         : 27;
        } bit;
    };

    /**
     * @brief Clock Configuration Register 5 (RCC_CFGR5).
     */
    union Cfgr5
    {
        typedef uint32_t Value;
        Cfgr5(){}
        Cfgr5(Value v){value = v;}
       ~Cfgr5(){}    
      
        Value value;
        struct Bit 
        {
            Value esw         : 3;
            Value             : 1;
            Value esws        : 3;
            Value             : 1;
            Value extclksel   : 2;
            Value             : 1;
            Value esss        : 1;
            Value flitfclksel : 2;
            Value flitfclkpre : 5;
            Value             : 8;
            Value mco3        : 1;
            Value mcopre      : 3;
            Value pllnodiv    : 1;
        } bit;
    };

    /**
     * @brief Clock Configuration Register 6 (RCC_CFGR6).
     */
    union Cfgr6
    {
        typedef uint32_t Value;
        Cfgr6(){}
        Cfgr6(Value v){value = v;}
       ~Cfgr6(){}    
      
        Value value;
        struct Bit 
        {
            Value saiapre : 3;
            Value saiasw  : 2;
            Value saibpre : 3;
            Value saibsw  : 2;
            Value         : 22;
        } bit;
    };

    /**
     * @brief AHB Peripheral Reset Register 2 (RCC_AHBRST2).
     */
    union Ahbrst2
    {
        typedef uint32_t Value;
        Ahbrst2(){}
        Ahbrst2(Value v){value = v;}
       ~Ahbrst2(){}    
      
        Value value;
        struct Bit 
        {
            Value dma1rst : 1;
            Value dma2rst : 1;
            Value         : 4;
            Value crcrst  : 1;
            Value         : 1;
            Value fsmcrst : 1;
            Value         : 1;
            Value sdiorst : 1;
            Value         : 21;
        } bit;
    };

    /**
     * @brief AHB Peripheral Reset Register 3 (RCC_AHBRST3).
     */
    union Ahbrst3
    {
        typedef uint32_t Value;
        Ahbrst3(){}
        Ahbrst3(Value v){value = v;}
       ~Ahbrst3(){}    
      
        Value value;
        struct Bit 
        {    
            Value          : 8;
            Value cacherst : 1;
            Value          : 23;
        } bit;
    };

    /**
     * @brief LSI Clock Control Register (RCC_LSICTL).
     */
    union Lsictl
    {
        typedef uint32_t Value;
        Lsictl(){}
        Lsictl(Value v){value = v;}
       ~Lsictl(){}    
      
        Value value;
        struct Bit 
        {
            Value         : 2;
            Value lsifreq : 2;
            Value         : 4;
            Value lsitrim : 8;
            Value         : 16;
        } bit;
    };

    /**
     * @brief Register map.
     */
public:     
    Cr        cr;           // 0x40021000
    Cfgr      cfgr;         // 0x40021004
    Cir       cir;          // 0x40021008
    Apb2rstr  apb2rstr;     // 0x4002100C
    Apb1rstr  apb1rstr;     // 0x40021010
    Ahbenr    ahbenr;       // 0x40021014
    Apb2enr   apb2enr;      // 0x40021018
    Apb1enr   apb1enr;      // 0x4002101C
    Bdcr      bdcr;         // 0x40021020
    Csr       csr;          // 0x40021024
private:
    uint32_t  space0_[0x01];
public:
    Cfgr2     cfgr2;        // 0x4002102C
    Cfgr3     cfgr3;        // 0x40021030
    Cr2       cr2;          // 0x40021034
private:
    uint32_t  space1_[0x2A];
public:       
    Hsectl    hsectl;       // 0x400210E0
    Pllctl    pllctl;       // 0x400210E4
    Cfgr4     cfgr4;        // 0x400210E8
    Cfgr5     cfgr5;        // 0x400210EC
    Cfgr6     cfgr6;        // 0x400210F0
private:
    uint32_t  space2_[0x06];
public:                            
    Ahbrst2   ahbrst2;      // 0x4002110C
    Ahbrst3   ahbrst3;      // 0x40021110
private:
    uint32_t  space3_[0x02];
public:    
    Lsictl    lsictl;       // 0x4002111C
};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_RCC_HPP_
