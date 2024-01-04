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
        Mcr(){}
        Mcr(uint32_t v){value = v;}
       ~Mcr(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t inrq  : 1;
            uint32_t sleep : 1;
            uint32_t txfp  : 1;
            uint32_t rflm  : 1;
            uint32_t nart  : 1;
            uint32_t awum  : 1;
            uint32_t abom  : 1;
            uint32_t ttcm  : 1;
            uint32_t       : 7;
            uint32_t reset : 1;
            uint32_t dbf   : 1;
            uint32_t       : 15;
        } bit;
    };

    /**
     * @brief CAN master status register (CAN_MSR).
     */
    union Msr
    {
        Msr(){}
        Msr(uint32_t v){value = v;}
       ~Msr(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t inak  : 1;
            uint32_t slak  : 1;
            uint32_t erri  : 1;
            uint32_t wkui  : 1;
            uint32_t slaki : 1;
            uint32_t       : 3;
            uint32_t txm   : 1;
            uint32_t rxm   : 1;
            uint32_t samp  : 1;
            uint32_t rx    : 1;
            uint32_t       : 20;
        } bit;
    };

    /**
     * @brief CAN transmit status register (CAN_TSR).
     */
    union Tsr
    {
        Tsr(){}
        Tsr(uint32_t v){value = v;}
       ~Tsr(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t rqcp0 : 1;
            uint32_t txok0 : 1;
            uint32_t alst0 : 1;
            uint32_t terr0 : 1;
            uint32_t       : 3;
            uint32_t abrq0 : 1;
            uint32_t rqcp1 : 1;
            uint32_t txok1 : 1;
            uint32_t alst1 : 1;
            uint32_t terr1 : 1;
            uint32_t       : 3;
            uint32_t abrq1 : 1;
            uint32_t rqcp2 : 1;
            uint32_t txok2 : 1;
            uint32_t alst2 : 1;
            uint32_t terr2 : 1;
            uint32_t       : 3;
            uint32_t abrq2 : 1;
            uint32_t code  : 2;
            uint32_t tme   : 3;
            uint32_t low   : 3;
        } bit;
    };

    /**
     * @brief CAN receive FIFO X register (CAN_RFxR).
     */
    union RfXr
    {
        RfXr(){}
        RfXr(uint32_t v){value = v;}
       ~RfXr(){}
      
        uint32_t value;
        struct 
        {
            uint32_t fmpx  : 2;
            uint32_t       : 1;
            uint32_t fullx : 1;
            uint32_t fovrx : 1;
            uint32_t rfomx : 1;
            uint32_t       : 26;
        } bit;
    };

    /**
     * @brief CAN interrupt enable register (CAN_IER).
     */
    union Ier
    {
        Ier(){}
        Ier(uint32_t v){value = v;}
       ~Ier(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t tmeie  : 1;
            uint32_t fmpie0 : 1;
            uint32_t ffie0  : 1;
            uint32_t fovie0 : 1;
            uint32_t fmpie1 : 1;
            uint32_t ffie1  : 1;
            uint32_t fovie1 : 1;
            uint32_t        : 1;
            uint32_t ewgie  : 1;
            uint32_t epvie  : 1;
            uint32_t bofie  : 1;
            uint32_t lecie  : 1;
            uint32_t        : 3;
            uint32_t errie  : 1;
            uint32_t wkuie  : 1;
            uint32_t slkie  : 1;
            uint32_t        : 14;
        } bit;
    };

    /**
     * @brief CAN error status register (CAN_ESR).
     */
    union Esr
    {
        Esr(){}
        Esr(uint32_t v){value = v;}
       ~Esr(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t ewgf : 1;
            uint32_t epvf : 1;
            uint32_t boff : 1;
            uint32_t      : 1;
            uint32_t lec  : 3;
            uint32_t      : 9;
            uint32_t tec  : 8;
            uint32_t rec  : 8;
        } bit;
    };

    /**
     * @brief CAN bit timing register (CAN_BTR).
     */
    union Btr
    {
        Btr(){}
        Btr(uint32_t v){value = v;}
       ~Btr(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t brp  : 10;
            uint32_t      : 6;
            uint32_t ts1  : 4;
            uint32_t ts2  : 3;
            uint32_t      : 1;
            uint32_t sjw  : 2;
            uint32_t      : 4;
            uint32_t lbkm : 1;
            uint32_t silm : 1;
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
            TiXr(){}
            TiXr(uint32_t v){value = v;}
           ~TiXr(){}    
          
            uint32_t value;
            struct 
            {
                uint32_t txrq : 1;
                uint32_t rtr  : 1;
                uint32_t ide  : 1;
                uint32_t exid : 18;
                uint32_t stid : 11;
            } bit;
        };
        
        /**
         * @brief CAN mailbox data length control and time stamp register (CAN_TDTxR).
         */
        union TdtXr
        {
            TdtXr(){}
            TdtXr(uint32_t v){value = v;}
           ~TdtXr(){}    
          
            uint32_t value;
            struct 
            {
                uint32_t dlc  : 4;
                uint32_t      : 4;
                uint32_t tgt  : 1;
                uint32_t      : 7;
                uint32_t time : 16;
            } bit;
        };
        
        /**
         * @brief CAN mailbox data low register (CAN_TDLxR).
         */
        union TdlXr
        {
            TdlXr(){}
            TdlXr(uint32_t v){value = v;}
           ~TdlXr(){}    
          
            uint32_t value;
            struct 
            {
                uint32_t data0 : 8;
                uint32_t data1 : 8;
                uint32_t data2 : 8;
                uint32_t data3 : 8;
            } bit;
        };
        
        /**
         * @brief CAN mailbox data high register (CAN_TDHxR).
         */
        union TdhXr
        {
            TdhXr(){}
            TdhXr(uint32_t v){value = v;}
           ~TdhXr(){}    
          
            uint32_t value;
            struct 
            {
                uint32_t data4 : 8;
                uint32_t data5 : 8;
                uint32_t data6 : 8;
                uint32_t data7 : 8;
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
            RiXr(){}
            RiXr(uint32_t v){value = v;}
           ~RiXr(){}    
          
            uint32_t value;
            struct 
            {
                uint32_t      : 1;
                uint32_t rtr  : 1;
                uint32_t ide  : 1;
                uint32_t exid : 18;
                uint32_t stid : 11;
            } bit;
        };
        
        /**
         * @brief CAN receive FIFO mailbox data length control and time stamp register (CAN_RDTxR).
         */
        union RdtXr
        {
            RdtXr(){}
            RdtXr(uint32_t v){value = v;}
           ~RdtXr(){}    
          
            uint32_t value;
            struct 
            {
                uint32_t dlc  : 4;
                uint32_t      : 4;
                uint32_t fmi  : 8;
                uint32_t time : 16;
            } bit;
        };
        
        /**
         * @brief CAN receive FIFO mailbox data low register (CAN_RDLxR).
         */
        union RdlXr
        {
            RdlXr(){}
            RdlXr(uint32_t v){value = v;}
           ~RdlXr(){}    
          
            uint32_t value;
            struct 
            {
                uint32_t data0 : 8;
                uint32_t data1 : 8;
                uint32_t data2 : 8;
                uint32_t data3 : 8;
            } bit;
        };
        
        /**
         * @brief CAN receive FIFO mailbox data high register (CAN_RDHxR).
         */
        union RdhXr
        {
            RdhXr(){}
            RdhXr(uint32_t v){value = v;}
           ~RdhXr(){}    
          
            uint32_t value;
            struct 
            {
                uint32_t data4 : 8;
                uint32_t data5 : 8;
                uint32_t data6 : 8;
                uint32_t data7 : 8;
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
        Fmr(){}
        Fmr(uint32_t v){value = v;}
       ~Fmr(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t finit  : 1;
            uint32_t        : 7;
            uint32_t can2sb : 6;
            uint32_t        : 18;
        } bit;
    };

    /**
     * @brief CAN filter mode register (CAN_FM1R).
     */
    union Fm1r
    {
        Fm1r(){}
        Fm1r(uint32_t v){value = v;}
       ~Fm1r(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t fbm : 28;
            uint32_t     : 4;
        } bit;
    };

    /**
     * @brief CAN filter scale register (CAN_FS1R).
     */
    union Fs1r
    {
        Fs1r(){}
        Fs1r(uint32_t v){value = v;}
       ~Fs1r(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t fsc : 28;
            uint32_t     : 4;
        } bit;
    };

    /**
     * @brief CAN filter FIFO assignment register (CAN_FFA1R).
     */
    union Ffa1r
    {
        Ffa1r(){}
        Ffa1r(uint32_t v){value = v;}
       ~Ffa1r(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t ffa : 28;
            uint32_t     : 4;
        } bit;
    };

    /**
     * @brief CAN filter activation register (CAN_FA1R).
     */
    union Fa1r
    {
        Fa1r(){}
        Fa1r(uint32_t v){value = v;}
       ~Fa1r(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t fact : 28;
            uint32_t      : 4;
        } bit;
    };
    
    /**
     * @brief Filter bank i register x (CAN_FiRx).
     */
    union FiRx
    {
        FiRx(){}
        FiRx(uint32_t v){value = v;}
       ~FiRx(){}    
      
        uint32_t value;
        struct 
        {
            uint32_t fb : 32;
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
