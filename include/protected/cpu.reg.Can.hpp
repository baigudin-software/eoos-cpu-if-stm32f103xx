/**
 * @file      cpu.reg.Can.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023-2024, Sergey Baigudin, Baigudin Software
 */
#ifndef CPU_REG_CAN_HPP_
#define CPU_REG_CAN_HPP_

#include "Types.hpp"

namespace eoos
{
namespace cpu
{
namespace reg
{

/**
 * @struct Can
 * @brief Controller area network (CAN).
 */
struct Can
{

public:
  
    /**
     * @brief Addresses.
     */    
    static const uint32_t ADDRESS_CAN1 = 0x40006400;
    static const uint32_t ADDRESS_CAN2 = 0x40006800;

    /** 
     * @brief Constructor.
     */  
    Can()
        : mcr()
        , msr()
        , tsr()
        , ier()
        , esr()
        , btr()
        , fmr()
        , fm1r()
        , fs1r()
        , ffa1r()
        , fa1r() {
    }

    /** 
     * @brief Destructor.
     */  
    ~Can(){}
   
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
     * @brief CAN master control register (CAN_MCR).
     */
    union Mcr
    {
        typedef uint32_t Value;
        Mcr(){}
        Mcr(Value v){value = v;}
       ~Mcr(){}    
      
        Value value;
        struct Bit
        {
            Value inrq  : 1;
            Value sleep : 1;
            Value txfp  : 1;
            Value rflm  : 1;
            Value nart  : 1;
            Value awum  : 1;
            Value abom  : 1;
            Value ttcm  : 1;
            Value       : 7;
            Value reset : 1;
            Value dbf   : 1;
            Value       : 15;
        } bit;
    };

    /**
     * @brief CAN master status register (CAN_MSR).
     */
    union Msr
    {
        typedef uint32_t Value;
        Msr(){}
        Msr(Value v){value = v;}
       ~Msr(){}    
      
        Value value;
        struct Bit 
        {
            Value inak  : 1;
            Value slak  : 1;
            Value erri  : 1;
            Value wkui  : 1;
            Value slaki : 1;
            Value       : 3;
            Value txm   : 1;
            Value rxm   : 1;
            Value samp  : 1;
            Value rx    : 1;
            Value       : 20;
        } bit;
    };

    /**
     * @brief CAN transmit status register (CAN_TSR).
     */
    union Tsr
    {
        typedef uint32_t Value;
        Tsr(){}
        Tsr(Value v){value = v;}
       ~Tsr(){}    
      
        Value value;
        struct Bit 
        {
            Value rqcp0 : 1;
            Value txok0 : 1;
            Value alst0 : 1;
            Value terr0 : 1;
            Value       : 3;
            Value abrq0 : 1;
            Value rqcp1 : 1;
            Value txok1 : 1;
            Value alst1 : 1;
            Value terr1 : 1;
            Value       : 3;
            Value abrq1 : 1;
            Value rqcp2 : 1;
            Value txok2 : 1;
            Value alst2 : 1;
            Value terr2 : 1;
            Value       : 3;
            Value abrq2 : 1;
            Value code  : 2;
            Value tme0  : 1;
            Value tme1  : 1;
            Value tme2  : 1;            
            Value low0  : 1;
            Value low1  : 1;
            Value low2  : 1;
        } bit;
    };

    /**
     * @brief CAN receive FIFO X register (CAN_RFxR).
     */
    union RfXr
    {
        typedef uint32_t Value;
        RfXr(){}
        RfXr(Value v){value = v;}
       ~RfXr(){}
      
        Value value;
        struct Bit 
        {
            Value fmpx  : 2;
            Value       : 1;
            Value fullx : 1;
            Value fovrx : 1;
            Value rfomx : 1;
            Value       : 26;
        } bit;
    };

    /**
     * @brief CAN interrupt enable register (CAN_IER).
     */
    union Ier
    {
        typedef uint32_t Value;
        Ier(){}
        Ier(Value v){value = v;}
       ~Ier(){}    
      
        Value value;
        struct Bit 
        {
            Value tmeie  : 1;
            Value fmpie0 : 1;
            Value ffie0  : 1;
            Value fovie0 : 1;
            Value fmpie1 : 1;
            Value ffie1  : 1;
            Value fovie1 : 1;
            Value        : 1;
            Value ewgie  : 1;
            Value epvie  : 1;
            Value bofie  : 1;
            Value lecie  : 1;
            Value        : 3;
            Value errie  : 1;
            Value wkuie  : 1;
            Value slkie  : 1;
            Value        : 14;
        } bit;
    };

    /**
     * @brief CAN error status register (CAN_ESR).
     */
    union Esr
    {
        typedef uint32_t Value;
        Esr(){}
        Esr(uint32_t v){value = v;}
       ~Esr(){}    
      
        Value value;
        struct Bit 
        {
            Value ewgf : 1;
            Value epvf : 1;
            Value boff : 1;
            Value      : 1;
            Value lec  : 3;
            Value      : 9;
            Value tec  : 8;
            Value rec  : 8;
        } bit;
    };

    /**
     * @brief CAN bit timing register (CAN_BTR).
     */
    union Btr
    {
        typedef uint32_t Value;
        Btr(){}
        Btr(Value v){value = v;}
       ~Btr(){}    
      
        Value value;
        struct Bit 
        {
            Value brp  : 10;
            Value      : 6;
            Value ts1  : 4;
            Value ts2  : 3;
            Value      : 1;
            Value sjw  : 2;
            Value      : 4;
            Value lbkm : 1;
            Value silm : 1;
        } bit;
    };
    
    /**
     * @struct Tx
     * @brief CAN TX mailbox.
     */
    struct Tx
    {
        /** 
         * @brief Constructor.
         */  
        Tx()
            : tixr()
            , tdtxr()
            , tdlxr()
            , tdhxr() {
        }
    
        /** 
         * @brief Destructor.
         */  
        ~Tx(){}

        /**
         * @brief CAN TX mailbox identifier register (CAN_TIxR).
         */
        union TiXr
        {
            typedef uint32_t Value;
            TiXr(){}
            TiXr(Value v){value = v;}
           ~TiXr(){}    
          
            Value value;
            struct Bit 
            {
                Value txrq : 1;
                Value rtr  : 1;
                Value ide  : 1;
                Value exid : 18;
                Value stid : 11;
            } bit;
        };
        
        /**
         * @brief CAN mailbox data length control and time stamp register (CAN_TDTxR).
         */
        union TdtXr
        {
            typedef uint32_t Value;
            TdtXr(){}
            TdtXr(Value v){value = v;}
           ~TdtXr(){}    
          
            Value value;
            struct Bit 
            {
                Value dlc  : 4;
                Value      : 4;
                Value tgt  : 1;
                Value      : 7;
                Value time : 16;
            } bit;
        };
        
        /**
         * @brief CAN mailbox data low register (CAN_TDLxR).
         */
        union TdlXr
        {
            typedef uint32_t Value;
            TdlXr(){}
            TdlXr(Value v){value = v;}
           ~TdlXr(){}    
          
            Value value;
            struct Bit 
            {
                Value data0 : 8;
                Value data1 : 8;
                Value data2 : 8;
                Value data3 : 8;
            } bit;
        };
        
        /**
         * @brief CAN mailbox data high register (CAN_TDHxR).
         */
        union TdhXr
        {
            typedef uint32_t Value;
            TdhXr(){}
            TdhXr(Value v){value = v;}
           ~TdhXr(){}    
          
            Value value;
            struct Bit 
            {
                Value data4 : 8;
                Value data5 : 8;
                Value data6 : 8;
                Value data7 : 8;
            } bit;
        };
        
        TiXr     tixr;   // 0x180, 0x190, 0x1A0 
        TdtXr    tdtxr;  // 0x184, 0x194, 0x1A4 
        TdlXr    tdlxr;  // 0x188, 0x198, 0x1A8 
        TdhXr    tdhxr;  // 0x18C, 0x19C, 0x1AC         
    };
    
    /**
     * @struct Rx
     * @brief CAN RX mailbox.
     */
    struct Rx
    {
        /**
         * @brief Constructor.
         */  
        Rx()
            : rixr()
            , rdtxr()
            , rdlxr()
            , rdhxr() {
        }
    
        /** 
         * @brief Destructor.
         */  
        ~Rx(){}

        /**
         * @brief CAN receive FIFO mailbox identifier register (CAN_RIxR).
         */
        union RiXr
        {
            typedef uint32_t Value;
            RiXr(){}
            RiXr(Value v){value = v;}
           ~RiXr(){}    
          
            Value value;
            struct Bit 
            {
                Value      : 1;
                Value rtr  : 1;
                Value ide  : 1;
                Value exid : 18;
                Value stid : 11;
            } bit;
        };
        
        /**
         * @brief CAN receive FIFO mailbox data length control and time stamp register (CAN_RDTxR).
         */
        union RdtXr
        {
            typedef uint32_t Value;
            RdtXr(){}
            RdtXr(Value v){value = v;}
           ~RdtXr(){}    
          
            Value value;
            struct Bit 
            {
                Value dlc  : 4;
                Value      : 4;
                Value fmi  : 8;
                Value time : 16;
            } bit;
        };
        
        /**
         * @brief CAN receive FIFO mailbox data low register (CAN_RDLxR).
         */
        union RdlXr
        {
            typedef uint32_t Value;
            RdlXr(){}
            RdlXr(Value v){value = v;}
           ~RdlXr(){}    
          
            Value value;
            struct Bit 
            {
                Value data0 : 8;
                Value data1 : 8;
                Value data2 : 8;
                Value data3 : 8;
            } bit;
        };
        
        /**
         * @brief CAN receive FIFO mailbox data high register (CAN_RDHxR).
         */
        union RdhXr
        {
            typedef uint32_t Value;
            RdhXr(){}
            RdhXr(Value v){value = v;}
           ~RdhXr(){}    
          
            Value value;
            struct Bit 
            {
                Value data4 : 8;
                Value data5 : 8;
                Value data6 : 8;
                Value data7 : 8;
            } bit;
        };
        
        RiXr     rixr;       // 0x1B0, 0x1C0 
        RdtXr    rdtxr;      // 0x1B4, 0x1C4
        RdlXr    rdlxr;      // 0x1B8, 0x1C8
        RdhXr    rdhxr;      // 0x1BC, 0x1CC
    };

    /**
     * @brief CAN filter master register (CAN_FMR).
     */
    union Fmr
    {
        typedef uint32_t Value;
        Fmr(){}
        Fmr(Value v){value = v;}
       ~Fmr(){}    
      
        Value value;
        struct Bit 
        {
            Value finit  : 1;
            Value        : 7;
            Value can2sb : 6;
            Value        : 18;
        } bit;
    };

    /**
     * @brief CAN filter mode register (CAN_FM1R).
     */
    union Fm1r
    {
        typedef uint32_t Value;
        Fm1r(){}
        Fm1r(Value v){value = v;}
       ~Fm1r(){}    
      
        Value value;
        struct Bit 
        {
            Value fbm : 28;
            Value     : 4;
        } bit;
    };

    /**
     * @brief CAN filter scale register (CAN_FS1R).
     */
    union Fs1r
    {
        typedef uint32_t Value;
        Fs1r(){}
        Fs1r(Value v){value = v;}
       ~Fs1r(){}    
      
        Value value;
        struct Bit 
        {
            Value fsc : 28;
            Value     : 4;
        } bit;
    };

    /**
     * @brief CAN filter FIFO assignment register (CAN_FFA1R).
     */
    union Ffa1r
    {
        typedef uint32_t Value;
        Ffa1r(){}
        Ffa1r(Value v){value = v;}
       ~Ffa1r(){}    
      
        Value value;
        struct Bit 
        {
            Value ffa : 28;
            Value     : 4;
        } bit;
    };

    /**
     * @brief CAN filter activation register (CAN_FA1R).
     */
    union Fa1r
    {
        typedef uint32_t Value;
        Fa1r(){}
        Fa1r(Value v){value = v;}
       ~Fa1r(){}    
      
        Value value;
        struct Bit 
        {
            Value fact : 28;
            Value      : 4;
        } bit;
    };
    
    /**
     * @brief Filter bank i register x (CAN_FiRx).
     */
    union FiRx
    {
        typedef uint32_t Value;
        FiRx(){}
        FiRx(Value v){value = v;}
       ~FiRx(){}    
      
        Value value;
        struct Bit 
        {
            Value fb : 32;
        } bit;
    };

    /**
     * @brief Register map.
     */
public:
    Mcr      mcr;        // 0x000 
    Msr      msr;        // 0x004 
    Tsr      tsr;        // 0x008 
    RfXr     rfxr[2];    // 0x00C-0x010
    Ier      ier;        // 0x014 
    Esr      esr;        // 0x018 
    Btr      btr;        // 0x01C
private:
    uint32_t res0_[88];  // 0x020-0x17F
public:
    Tx       tx[3];      // 0x180-0x1AC
    Rx       rx[2];      // 0x1B0-0x1CC
private:
    uint32_t res1_[12];  // 0x1D0-0x1FF
public:
    Fmr      fmr;        // 0x200 
    Fm1r     fm1r;       // 0x204
private:
    uint32_t res2_[1];   // 0x208 
public:
    Fs1r     fs1r;       // 0x20C 
private:
    uint32_t res3_[1];   // 0x210 
public:
    Ffa1r    ffa1r;      // 0x214 
private:
    uint32_t res4_[1];   // 0x218 
public:
    Fa1r     fa1r;       // 0x21C 
private:
    uint32_t res5_[8];   // 0x220,0x224-0x23F
public:
    FiRx     firx[27][2];// 0x240,0x244-0x318,0x31C

};

} // namespace reg
} // namespace cpu
} // namespace eoos
#endif // CPU_REG_CAN_HPP_
