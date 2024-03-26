/**
 * @file      cpu.reg.Scb.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_SCB_HPP_
#define CPU_REG_SCB_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Scb
 * @brief System Control Block.
 */
struct Scb
{

public:
  
    /**
     * @brief System Control address.
     */    
    static const uint32_t ADDRESS = 0xE000ED00;
        
    /** 
     * @brief Constructor.
     */  
    Scb()
        : cpuid()      
        , icsr()       
        , vtor()       
        , aircr()      
        , scr()        
        , ccr()        
        , shcsr()      
        , cfsr()       
        , hfsr()       
        , dfsr()       
        , mmfar()      
        , bfar()       
        , afsr()       
        , idpfr0()     
        , idpfr1()     
        , iddfr0()     
        , idafr0()     
        , idmmfr0()    
        , idmmfr1()    
        , idmmfr2()    
        , idmmfr3()    
        , idisar0()    
        , idisar1()    
        , idisar2()    
        , idisar3()    
        , idisar4()    
        , cpacr() {
    }

    /** 
     * @brief Destructor.
     */  
    ~Scb(){}
   
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
     * @brief CPUID Base Register.
     */
    union Cpuid
    {
        typedef uint32_t Value;
        Cpuid(){}
        Cpuid(Value v){value = v;}
       ~Cpuid(){}    
      
        Value value;
        struct Bit 
        {
            Value revision    : 4;
            Value partno      : 12;
            Value             : 4;
            Value variant     : 4;
            Value implementer : 8;
        } bit;
    };

    /**
     * @brief Interrupt Control and State Register.
     */
    union Icsr
    {
        typedef uint32_t Value;
        Icsr(){}
        Icsr(Value v){value = v;}
       ~Icsr(){}    
      
        Value value;
        struct Bit 
        {
            Value vectactive  : 9;
            Value             : 2;
            Value rettobase   : 1;
            Value vectpending : 9;
            Value             : 1;
            Value isrpending  : 1;
            Value isrpreempt  : 1;
            Value             : 1;
            Value pendstclr   : 1;
            Value pendstset   : 1;
            Value pendsvclr   : 1;
            Value pendsvset   : 1;
            Value             : 2;
            Value nmipendset  : 1;
        } bit;
    };

    /**
     * @brief Vector Table Offset Register.
     */
    union Vtor
    {
        typedef uint32_t Value;
        Vtor(){}
        Vtor(Value v){value = v;}
       ~Vtor(){}    
      
        Value value;
        struct Bit 
        {
            Value        : 7;
            Value tbloff : 25;
        } bit;
    };

    /**
     * @brief Application Interrupt and Reset Control Register.
     */
    union Aircr
    {
        typedef uint32_t Value;
        Aircr(){}
        Aircr(Value v){value = v;}
       ~Aircr(){}    
      
        Value value;
        struct Bit 
        {
            Value vectreset     : 1; 
            Value vectclractive : 1; 
            Value sysresetreq   : 1; 
            Value               : 5;
            Value prigroup      : 3; 
            Value               : 4;
            Value endianess     : 1; 
            Value vectkey       : 16;
        } bit;
    };

    /**
     * @brief System Control Register.
     */
    union Scr
    {
        typedef uint32_t Value;
        Scr(){}
        Scr(Value v){value = v;}
       ~Scr(){}    
      
        Value value;
        struct Bit 
        {
            Value             : 1;
            Value sleeponexit : 1;
            Value sleepdeep   : 1;
            Value             : 1;
            Value sevonpend   : 1;
            Value             : 27;
        } bit;
    };

    /**
     * @brief Configuration and Control Register.
     */
    union Ccr
    {
        typedef uint32_t Value;
        Ccr(){}
        Ccr(Value v){value = v;}
       ~Ccr(){}    
      
        Value value;
        struct Bit 
        {
            Value nonbasethrdena : 1;
            Value usersetmpend   : 1;
            Value                : 1;
            Value unalign_trp    : 1;
            Value div0trp        : 1;
            Value                : 3;
            Value bfhfnmign      : 1;
            Value stkalign       : 1;
            Value                : 6;
            Value dc             : 1;
            Value ic             : 1;
            Value bp             : 1;
            Value                : 13;            
        } bit;
    };

    /**
     * @brief System Handler Priority Register 1-3.
     */
    union ShprN
    {
        typedef uint32_t Value;
        ShprN(){}
        ShprN(Value v){value = v;}
       ~ShprN(){}    
      
        Value value;
        struct Bit 
        {                       // | Register 1  | Register 2  | Register 3     |
            Value priN0 : 8; // | MPU Fault   |             | Debug Monitor  |
            Value priN1 : 8; // | Bus Fault   |             |                |
            Value priN2 : 8; // | Usage Fault |             | PendSV         |
            Value priN3 : 8; // |             | SVCall      | SysTick        |
        } bit;
    };

    /**
     * @brief System Handler Control and State Register.
     */
    union Shcsr
    {
        typedef uint32_t Value;
        Shcsr(){}
        Shcsr(Value v){value = v;}
       ~Shcsr(){}    
      
        Value value;
        struct Bit 
        {
            Value memfaultact    : 1;
            Value busfaultact    : 1;
            Value                : 1;
            Value usgfaultact    : 1;
            Value                : 3;
            Value svcallact      : 1;
            Value monitoract     : 1;
            Value                : 1;
            Value pendsvact      : 1;
            Value systickact     : 1;
            Value usgfaultpended : 1;
            Value memfaultpended : 1;
            Value busfaultpended : 1;
            Value svcallpended   : 1;
            Value memfaultena    : 1;
            Value busfaultena    : 1;
            Value usgfaultena    : 1;
            Value                : 13;
        } bit;
    };

    /**
     * @brief Configurable Fault Status Registers.
     */
    union Cfsr
    {
        typedef uint32_t Value;
        Cfsr(){}
        Cfsr(Value v){value = v;}
       ~Cfsr(){}    
      
        Value value;
        struct Bit 
        {
            Value mmfsrIaccviol   : 1;
            Value mmfsrDaccviol   : 1;
            Value                 : 1;
            Value mmfsrMunstkerr  : 1;
            Value mmfsrMstkerr    : 1;
            Value mmfsrMlsperr    : 1;
            Value                 : 1;
            Value mmfsrMmarvalid  : 1;
            Value bfsrIbuserr     : 1;
            Value bfsrPreciserr   : 1;
            Value bfsrImpreciserr : 1;
            Value bfsrUnstkerr    : 1;
            Value bfsrStkerr      : 1;
            Value bfsrLsperr      : 1;
            Value                 : 1;
            Value bfsrBfarvalid   : 1;
            Value ufsrUndefinstr  : 1;
            Value ufsrInvstate    : 1;
            Value ufsrInvpc       : 1;
            Value ufsrNocp        : 1;
            Value                 : 4;
            Value ufsrUnaligned   : 1;
            Value ufsrDivbyzero   : 1;
            Value                 : 6;
        } bit;
    };

    /**
     * @brief HardFault Status Register.
     */
    union Hfsr
    {
        typedef uint32_t Value;
        Hfsr(){}
        Hfsr(Value v){value = v;}
       ~Hfsr(){}    
      
        Value value;
        struct Bit 
        {
            Value          : 1;
            Value vecttbl  : 1;
            Value          : 28;
            Value forced   : 1;
            Value debugevt : 1;
        } bit;
    };

    /**
     * @brief Debug Fault Status Register.
     */
    union Dfsr
    {
        typedef uint32_t Value;
        Dfsr(){}
        Dfsr(Value v){value = v;}
       ~Dfsr(){}    
      
        Value value;
        struct Bit 
        {
            Value halted   : 1;
            Value bkpt     : 1;
            Value dwttrap  : 1;
            Value vcatch   : 1;
            Value external : 1;
            Value          : 27;
        } bit;
    };

    /**
     * @brief MemManage Address Register.
     */
    union Mmfar
    {
        typedef uint32_t Value;
        Mmfar(){}
        Mmfar(Value v){value = v;}
       ~Mmfar(){}    
      
        Value value;
        struct Bit 
        {
            Value address : 32;
        } bit;
    };

    /**
     * @brief BusFault Address Register.
     */
    union Bfar
    {
        typedef uint32_t Value;
        Bfar(){}
        Bfar(Value v){value = v;}
       ~Bfar(){}    
      
        Value value;
        struct Bit 
        {
            Value address : 32;
        } bit;
    };

    /**
     * @brief Auxiliary Fault Status Register.
     */
    union Afsr
    {
        typedef uint32_t Value;
        Afsr(){}
        Afsr(Value v){value = v;}
       ~Afsr(){}    
      
        Value value;
        struct Bit 
        {
            Value auxfault : 32;
        } bit;
    };

    /**
     * @brief Processor Feature Register 0.
     */
    union IdPfr0
    {
        typedef uint32_t Value;
        IdPfr0(){}
        IdPfr0(Value v){value = v;}
       ~IdPfr0(){}    
      
        Value value;
    };

    /**
     * @brief Processor Feature Register 1.
     */
    union IdPfr1
    {
        typedef uint32_t Value;
        IdPfr1(){}
        IdPfr1(Value v){value = v;}
       ~IdPfr1(){}    
      
        Value value;
    };

    /**
     * @brief Debug Features Register 0.
     */
    union IdDfr0
    {
        typedef uint32_t Value;
        IdDfr0(){}
        IdDfr0(Value v){value = v;}
       ~IdDfr0(){}    
      
        Value value;
    };

    /**
     * @brief Auxiliary Features Register 0.
     */
    union IdAfr0
    {
        typedef uint32_t Value;
        IdAfr0(){}
        IdAfr0(Value v){value = v;}
       ~IdAfr0(){}    
      
        Value value;
    };

    /**
     * @brief Memory Model Feature Register 0.
     */
    union IdMmfr0
    {
        typedef uint32_t Value;
        IdMmfr0(){}
        IdMmfr0(Value v){value = v;}
       ~IdMmfr0(){}    
      
        Value value;
    };

    /**
     * @brief Memory Model Feature Register 1.
     */
    union IdMmfr1
    {
        typedef uint32_t Value;
        IdMmfr1(){}
        IdMmfr1(Value v){value = v;}
       ~IdMmfr1(){}    
      
        Value value;
    };

    /**
     * @brief Memory Model Feature Register 2.
     */
    union IdMmfr2
    {
        typedef uint32_t Value;
        IdMmfr2(){}
        IdMmfr2(Value v){value = v;}
       ~IdMmfr2(){}    
      
        Value value;
    };

    /**
     * @brief Memory Model Feature Register 3.
     */
    union IdMmfr3
    {
        typedef uint32_t Value;
        IdMmfr3(){}
        IdMmfr3(Value v){value = v;}
       ~IdMmfr3(){}    
      
        Value value;
    };

    /**
     * @brief Instruction Set Attributes Register 0.
     */
    union IdIsar0
    {
        typedef uint32_t Value;
        IdIsar0(){}
        IdIsar0(Value v){value = v;}
       ~IdIsar0(){}    
      
        Value value;
    };

    /**
     * @brief Instruction Set Attributes Register 1.
     */
    union IdIsar1
    {
        typedef uint32_t Value;
        IdIsar1(){}
        IdIsar1(Value v){value = v;}
       ~IdIsar1(){}    
      
        Value value;
    };

    /**
     * @brief Instruction Set Attributes Register 2.
     */
    union IdIsar2
    {
        typedef uint32_t Value;
        IdIsar2(){}
        IdIsar2(Value v){value = v;}
       ~IdIsar2(){}    
      
        Value value;
    };

    /**
     * @brief Instruction Set Attributes Register 3.
     */
    union IdIsar3
    {
        typedef uint32_t Value;
        IdIsar3(){}
        IdIsar3(Value v){value = v;}
       ~IdIsar3(){}    
      
        Value value;
    };

    /**
     * @brief Instruction Set Attributes Register 4.
     */
    union IdIsar4
    {
        typedef uint32_t Value;
        IdIsar4(){}
        IdIsar4(Value v){value = v;}
       ~IdIsar4(){}    
      
        Value value;
    };

    /**
     * @brief Coprocessor Access Control Register.
     */
    union Cpacr
    {
        typedef uint32_t Value;
        Cpacr(){}
        Cpacr(Value v){value = v;}
       ~Cpacr(){}    
      
        Value value;
    };
    
    /**
     * @brief Register map.
     */
public:
    Cpuid       cpuid;   // 0xE000ED00
    Icsr        icsr;    // 0xE000ED04
    Vtor        vtor;    // 0xE000ED08
    Aircr       aircr;   // 0xE000ED0C
    Scr         scr;     // 0xE000ED10
    Ccr         ccr;     // 0xE000ED14
    ShprN       shpr[3]; // 0xE000ED18 - 0xE000ED20
    Shcsr       shcsr;   // 0xE000ED24
    Cfsr        cfsr;    // 0xE000ED28
    Hfsr        hfsr;    // 0xE000ED2C
    Dfsr        dfsr;    // 0xE000ED30
    Mmfar       mmfar;   // 0xE000ED34
    Bfar        bfar;    // 0xE000ED38
    Afsr        afsr;    // 0xE000ED3C
    IdPfr0      idpfr0;  // 0xE000ED40
    IdPfr1      idpfr1;  // 0xE000ED44
    IdDfr0      iddfr0;  // 0xE000ED48
    IdAfr0      idafr0;  // 0xE000ED4C
    IdMmfr0     idmmfr0; // 0xE000ED50
    IdMmfr1     idmmfr1; // 0xE000ED54
    IdMmfr2     idmmfr2; // 0xE000ED58
    IdMmfr3     idmmfr3; // 0xE000ED5C
    IdIsar0     idisar0; // 0xE000ED60
    IdIsar1     idisar1; // 0xE000ED64
    IdIsar2     idisar2; // 0xE000ED68
    IdIsar3     idisar3; // 0xE000ED6C
    IdIsar4     idisar4; // 0xE000ED70
private:
    uint32_t    space2_[0x5D];
public:
    Cpacr       cpacr;   // 0xED88

};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_SCB_HPP_
