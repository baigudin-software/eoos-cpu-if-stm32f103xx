/**
 * @file      cpu.reg.Flash.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_FLASH_HPP_
#define CPU_REG_FLASH_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Flash
 * @brief HK32F103xCxDxE Embedded Flash (FLASH).
 */
struct Flash
{

public:
  
    /**
     * @brief Flash address.
     */    
    static const uint32_t ADDRESS = 0x40022000;
        
    /** 
     * @brief Constructor.
     */  
    Flash()
        : acr()        
        , keyr()       
        , optkeyr()    
        , sr()         
        , cr()         
        , ar()         
        , obr()        
        , wrpr()       
        , latencyex()  
        , ecr()        
        , encryctl()   
        , decryctl()   
        , ukeyl()      
        , ukeyh()      
        , pw0()        
        , pw1()            
        , pw2()          
        , pw3() {
    }

    /** 
     * @brief Destructor.
     */  
    ~Flash(){}
   
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
     * @brief Flash Access Control Register (FLASH_ACR).
     */
    union Acr
    {
        typedef uint32_t Value;        
        Acr(){}
        Acr(Value v){value = v;}
       ~Acr(){}    
      
        Value value;
        struct Bit 
        {
            Value latency : 3;
            Value hlfcya  : 1;
            Value prftbe  : 1;
            Value prftbs  : 1;
            Value         : 26;
        } bit;
    };
  
    /**
     * @brief Flash Keyword Register (FLASH_KEYR).
     */
    union Keyr
    {
        typedef uint32_t Value;
        Keyr(){}
        Keyr(Value v){value = v;}
       ~Keyr(){}    
      
        Value value;
        struct Bit 
        {
            Value fkeyr : 32;   
        } bit;
    };
    
    /**
     * @brief Flash Option Keyword Register (FLASH_OPTKEYR).
     */
    union Optkeyr
    {
        typedef uint32_t Value;
        Optkeyr(){}
        Optkeyr(Value v){value = v;}
       ~Optkeyr(){}    
      
        Value value;
        struct Bit 
        {
            Value optkey : 32;
        } bit;
    };
             
    /**
     * @brief Flash Status Register (FLASH_SR).
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
            Value bsy      : 1;
            Value          : 1;
            Value pgerr    : 1;
            Value          : 1;
            Value wrprterr : 1;
            Value eop      : 1;
            Value          : 26;
        } bit;
    };

    /**
     * @brief Flash Control Register (FLASH_CR).
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
            Value pg     : 1;
            Value per    : 1;
            Value mer    : 1;
            Value        : 1;
            Value optpg  : 1;
            Value opter  : 1;
            Value strt   : 1;
            Value lock   : 1;
            Value        : 1;
            Value optwre : 1;
            Value errie  : 1;
            Value        : 1;
            Value eopie  : 1;
            Value        : 19;
        } bit;
    };

    /**
     * @brief Flash Address Register (FLASH_AR).
     */
    union Ar
    {
        typedef uint32_t Value;
        Ar(){}
        Ar(Value v){value = v;}
       ~Ar(){}    
      
        Value value;
        struct Bit 
        {
            Value far : 32;
        } bit;
    };

    /**
     * @brief Flash Option Byte Register (FLASH_OBR).
     */
    union Obr
    {
        typedef uint32_t Value;
        Obr(){}
        Obr(Value v){value = v;}
       ~Obr(){}    
      
        Value value;
        struct Bit 
        {
            Value opterr    : 1;
            Value rdprt     : 1;
            Value wdgsw     : 1;
            Value nrststop  : 1;
            Value nrststdby : 1;
            Value           : 5;
            Value data0     : 8;
            Value data1     : 8;
            Value           : 6;
        } bit;
    };

    /**
     * @brief Flash Write Protect Register (FLASH_WRPR).
     */
    union Wrpr
    {
        typedef uint32_t Value;
        Wrpr(){}
        Wrpr(Value v){value = v;}
       ~Wrpr(){}    
      
        Value value;
        struct Bit 
        {
            Value wrp : 32;
        } bit;
    };
  
    /**
     * @brief Flash wait cycle register (FLASH_LATENCY_EX).
     */
    union Latencyex
    {
        typedef uint32_t Value;
        Latencyex(){}
        Latencyex(Value v){value = v;}
       ~Latencyex(){}    
      
        Value value;
        struct Bit 
        {
            Value latency43 : 2;
            Value           : 30;
        } bit;
    };
  
    /**
     * @brief Flash Control Register 2 (FLASH_ECR).
     */
    union Ecr
    {
        typedef uint32_t Value;
        Ecr(){}
        Ecr(Value v){value = v;}
       ~Ecr(){}    
      
        Value value;
        struct Bit 
        {
            Value sethper : 1;
            Value setwpg  : 1;
            Value set2wpg : 1;
            Value set4wpg : 1;
            Value infhper : 1;
            Value infhwpg : 1;
            Value infwpg  : 1;
            Value inf2wpg : 1;
            Value inf4wpg : 1;
            Value         : 23;    
        } bit;
    };
    
    /**
     * @brief Encryption Control Register (ENCRY_CFG).
     */
    union Encryctl
    {
        typedef uint32_t Value;
        Encryctl(){}
        Encryctl(Value v){value = v;}
       ~Encryctl(){}    
      
        Value value;
        struct Bit 
        {
            Value encryen : 1;
            Value         : 31;   
        } bit;
    };

    /**
     * @brief Decryption Control Register (DECRY_CFG).
     */
    union Decryctl
    {
        typedef uint32_t Value;
        Decryctl(){}
        Decryctl(Value v){value = v;}
       ~Decryctl(){}    
      
        Value value;
        struct Bit 
        {
            Value decryen : 1;
            Value         : 31;
        } bit;
    };
      
    /**
     * @brief Key Register 1 (UKEYL).
     */
    union Ukeyl
    {
        typedef uint32_t Value;
        Ukeyl(){}
        Ukeyl(Value v){value = v;}
       ~Ukeyl(){}    
      
        Value value;
        struct Bit 
        {
            Value ukey : 32;
        } bit;
    };
      
    /**
     * @brief Key Register 2 (UKEYH).
     */
    union Ukeyh
    {
        typedef uint32_t Value;
        Ukeyh(){}
        Ukeyh(Value v){value = v;}
       ~Ukeyh(){}    
      
        Value value;
        struct Bit 
        {
            Value ukey : 32;
        } bit;
    };
        
    /**
     * @brief Programming Data Register 0 (PW0).
     */
    union Pw0
    {
        typedef uint32_t Value;
        Pw0(){}
        Pw0(Value v){value = v;}
       ~Pw0(){}    
      
        Value value;
        struct Bit 
        {
            Value pw0 : 32;
        } bit;
    };
      
    /**
     * @brief Programming Data Register 1 (PW1).
     */
    union Pw1
    {
        typedef uint32_t Value;
        Pw1(){}
        Pw1(Value v){value = v;}
       ~Pw1(){}    
      
        Value value;
        struct Bit 
        {
            Value pw1 : 32;
        } bit;
    };
    
    /**
     * @brief Programming Data Register 2 (PW2).
     */
    union Pw2
    {
        typedef uint32_t Value;
        Pw2(){}
        Pw2(Value v){value = v;}
       ~Pw2(){}    
      
        Value value;
        struct Bit 
        {
            Value pw0 : 32;
        } bit;
    };

    /**
     * @brief Programming Data Register 3 (PW3).
     */
    union Pw3
    {
        typedef uint32_t Value;
        Pw3(){}
        Pw3(Value v){value = v;}
       ~Pw3(){}    
      
        Value value;
        struct Bit 
        {
            Value pw0 : 32;
        } bit;
    };
    
    /**
     * @brief Register map.
     */
public:
    Acr       acr;        // 0x40022000
    Keyr      keyr;       // 0x40022004
    Optkeyr   optkeyr;    // 0x40022008
    Sr        sr;         // 0x4002200C
    Cr        cr;         // 0x40022010
    Ar        ar;         // 0x40022014
private:
    uint32_t  space0_[0x01];
public:
    Obr       obr;        // 0x4002201C
    Wrpr      wrpr;       // 0x40022020
private:
    uint32_t  space1_[0x0F];
public:
    Latencyex latencyex;  // 0x40022060
private:
    uint32_t  space2_[0x03];
public:
    Ecr       ecr;        // 0x40022070
private:
    uint32_t  space3_[0x01];
public:
    Encryctl  encryctl;   // 0x40022078
    Decryctl  decryctl;   // 0x4002207C
    Ukeyl     ukeyl;      // 0x40022080
    Ukeyh     ukeyh;      // 0x40022084
private:
    uint32_t  space4_[0x01];
public:
    Pw0       pw0;        // 0x40022090
    Pw1       pw1;        // 0x40022094
    Pw2       pw2;        // 0x40022098
    Pw3       pw3;        // 0x4002209C
};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_FLASH_HPP_
