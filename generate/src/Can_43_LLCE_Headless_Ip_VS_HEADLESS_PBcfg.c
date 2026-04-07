/**
*   @file    Can_43_LLCE_Headless_Ip_PBcfg.c
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Configuration Structures for PostBuild.
*
*   @addtogroup CAN_LLCE
*   @{
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.11
*   Build Version        : S32_RTD_1_0_11_D2511_ASR_REL_4_4_REV_0000_20251121
*
*   Copyright 2020-2025 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Llce_InterfaceCanTypes.h"
#include "Llce_Headless.h"


#define CAN_43_LLCE_MAX_IDMASK    (uint32)0x1FFFFFFFU

__attribute__((section(".llce_headlessconfig")))
volatile struct {
    Llce_Headless_Descriptor descriptor;
    Llce_Can_InitPlatformCmdType initPlatform;
    Llce_Can_InitCmdType initChannels[4];
    Llce_Can_SetBaudrateCmdType baudrates[4];
    Can_Af_DestRulesType advancedDestinations[4];
    Llce_Can_ReceiveFilterType regularFilters[5];
    Llce_Can_AdvancedFilterType advancedFilters[4];
} LLCE__ALIGNED__PACKED Can_43_LLCE_HeadlessCfg = {
    /* Headless config descriptor */
    {
        /** "Magic number" used to detect headless mode */
        LLCE_HEADLESSMODE_MAGICVALUE,
        /** Number of channels used */
        4U,
        /** Number of routing destinations used. Used for advanced filters */
        4U,
        /** Number of regular filters used */
        {1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 4U, 0U, },
        /** Number of advanced filters used */
        {4U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, }
    },
    /* Platform init */
    {
     /*  Array containing the initialization status of the controllers */
     {INITIALIZED, INITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, UNINITIALIZED, INITIALIZED, INITIALIZED},

     /* Array containing maximum number of regular filters per hardware controller */
     {(uint16)1U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)4U,  (uint16)0U},

     /* Array containing maximum number of advanced filters per hardware controller */
     {(uint16)4U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U,  (uint16)0U},

     /* Array containing maximum number of INTERRUPT driven receive Message Buffers per FIFO interface. */
     {(uint16)100U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)80U, (uint16)0U},

     /* Array containing maximum number of RX Message Buffers per POLLING class. There are 6 of them available */
     {(uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U},

     /* Array containing maximum number of INTERRUPT driven TX confirmation buffers per FIFO interface. */
     {(uint16)0U, (uint16)16U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)4U},

     /* Array containing maximum number of TX confirmation buffers per POLLING class. There are 6 of them available */
     {(uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U, (uint16)0U},

     /* Structure describing the way of processing each errors category. This can be: INTERRUPT, POLLING or IGNORE. */
     {
        NOTIF_FIFO1, /*CAN_PROTOCOL_ERR*/
        NOTIF_FIFO0, /*DATALOST_ERR*/
        IGNORE, /*CONFIGURATION_ERR*/
        NOTIF_FIFO0, /*INTERNAL_ERR*/
        {
        NOTIF_FIFO0,
        NOTIF_FIFO0,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        IGNORE,
        NOTIF_FIFO0,
        NOTIF_FIFO0
        }, /* BusOff processing type for each channel */
        IGNORE /*CAN_PROTOCOL_WRN*/
     }
    },
    /* Channel init */
    {
      { /* Options for BCAN_0 */
         /* ===== Controller Options for firmware ===== */
         (uint32)(
        LLCE_CAN_CONTROLLERCONFIG_TST_END_U32 |/* Timestamp capture point END */ 
         /* Listen-only mode disabled */
         /* LoopBack mode disabled */
         /* Self reception mode disabled */
         /* Protocol Exception feature disabled */
         /* Can TX FIFO Mode disabled */
         /* Automatic Bus Off Recovery disabled */
         /* Manual Bus Off Recovery disabled */
        
        LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32
         ),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_1 */
         /* ===== Controller Options for firmware ===== */
         (uint32)(
        LLCE_CAN_CONTROLLERCONFIG_TST_END_U32 |/* Timestamp capture point END */ 
         /* Listen-only mode disabled */
         /* LoopBack mode disabled */
         /* Self reception mode disabled */
         /* Protocol Exception feature disabled */
         /* Can TX FIFO Mode disabled */
         /* Automatic Bus Off Recovery disabled */
         /* Manual Bus Off Recovery disabled */
        
        LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32
         ),
         /* Number of configured HTHs for this controller */
         (uint8)16U
      },
      { /* Options for BCAN_14 */
         /* ===== Controller Options for firmware ===== */
         (uint32)(
        LLCE_CAN_CONTROLLERCONFIG_TST_END_U32 |/* Timestamp capture point END */ 
         /* Listen-only mode disabled */
         /* LoopBack mode disabled */
         /* Self reception mode disabled */
         /* Protocol Exception feature disabled */
         /* Can TX FIFO Mode disabled */
         /* Automatic Bus Off Recovery disabled */
         /* Manual Bus Off Recovery disabled */
        
        LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32
         ),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_15 */
         /* ===== Controller Options for firmware ===== */
         (uint32)(
        LLCE_CAN_CONTROLLERCONFIG_TST_END_U32 |/* Timestamp capture point END */ 
         /* Listen-only mode disabled */
         /* LoopBack mode disabled */
         /* Self reception mode disabled */
         /* Protocol Exception feature disabled */
         /* Can TX FIFO Mode disabled */
         /* Automatic Bus Off Recovery disabled */
         /* Manual Bus Off Recovery disabled */
        
        LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32
         ),
         /* Number of configured HTHs for this controller */
         (uint8)4U
      },
  },
    /* Default Baudrates */
    {
        /* Configuration 0 for CanController ID0 == BCAN_0 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)4 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)22) |      /*Segment 1 */
                      ((uint32)7 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)4U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)10U) |   /* Time segment 1 */
                     ((uint32)3U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
        /* Configuration 0 for CanController ID1 == BCAN_1 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)4 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)22) |      /*Segment 1 */
                      ((uint32)7 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)4U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)10U) |   /* Time segment 1 */
                     ((uint32)3U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
        /* Configuration 0 for CanController ID2 == BCAN_14 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)4 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)22) |      /*Segment 1 */
                      ((uint32)7 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)4U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)10U) |   /* Time segment 1 */
                     ((uint32)3U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
        /* Configuration 0 for CanController ID3 == BCAN_15 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)4 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)22) |      /*Segment 1 */
                      ((uint32)7 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)4U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)10U) |   /* Time segment 1 */
                     ((uint32)3U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
},
  /* Advanced destinations */
    {
    {
        {.Can2Can = {
        /* ======= Routing Rule ======= */
            (uint32)(
                  LLCE_CAN_ROUTING_NOCHANGE |
                  LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
            ),
            (uint32)0U,
            {
                (uint8)15,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0
         },
       (uint8)1U
       }},
        /* ======= Destination rule type ======= */
        CAN_AF_CAN2CAN 
    },
    {
        {.Can2Can = {
        /* ======= Routing Rule ======= */
            (uint32)(
              LLCE_CAN_ROUTING_CANFD |
                  LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
            ),
            (uint32)0U,
            {
                (uint8)15,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0
         },
       (uint8)1U
       }},
        /* ======= Destination rule type ======= */
        CAN_AF_CAN2CAN 
    },
    {
        {.Can2Can = {
        /* ======= Routing Rule ======= */
            (uint32)(
                  LLCE_CAN_ROUTING_CAN |
                  LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
            ),
            (uint32)0U,
            {
                (uint8)15,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0
         },
       (uint8)1U
       }},
        /* ======= Destination rule type ======= */
        CAN_AF_CAN2CAN 
    },
    {
        {.Can2Can = {
        /* ======= Routing Rule ======= */
            (uint32)(
                  LLCE_CAN_ROUTING_NOCHANGE |
                  LLCE_CAN_ROUTING_ID_REMAPPING_EN |
                  LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
            ),
              (uint32)999U << LLCE_CAN_MB_IDSTD_SHIFT_U32,
            {
                (uint8)15,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0
         },
       (uint8)1U
       }},
        /* ======= Destination rule type ======= */
        CAN_AF_CAN2CAN 
    },

    },
    /* Regular filters */
    {
    { /* Regular filter 0 for BCAN_0 */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0x1U & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x0U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)0U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
    { /* Regular filter 0 for BCAN_14 */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0xfU & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x5U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)14U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
    { /* Regular filter 1 for BCAN_14 */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0x7bU & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x6U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)14U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
    { /* Regular filter 2 for BCAN_14 */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0x141U & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x7U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)14U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
    { /* Regular filter 3 for BCAN_14 */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0x3e7U & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x8U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)14U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
  },
    /* Advanced filters */
   {
    { /* Advanced filter 0 for BCAN_0 */
    { /* RxFilter */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0xfU & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x1U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)0U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
    { /* AdvancedFeature */
      LLCE_AF_AUTHENTICATION_DISABLED, /* Option for frame authentication feature */
      LLCE_AF_HOSTRECEIVE_DISABLED, /* Option for host receive feature */
      LLCE_AF_LOGGING_DISABLED, /* Option for logging feature */
      LLCE_AF_CUSTOMPROCESSING_DISABLED, /* Option for custom processing in FDK */
      (uint8)0U, /* Reference to Can2Can routing entry */
      (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED,  /* Can2Eth not used */
      (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED  /* Can2Other not used */
    }
    } /* End advanced filter 0 for BCAN_0 */,
    { /* Advanced filter 1 for BCAN_0 */
    { /* RxFilter */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0x7bU & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x2U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)0U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
    { /* AdvancedFeature */
      LLCE_AF_AUTHENTICATION_DISABLED, /* Option for frame authentication feature */
      LLCE_AF_HOSTRECEIVE_DISABLED, /* Option for host receive feature */
      LLCE_AF_LOGGING_DISABLED, /* Option for logging feature */
      LLCE_AF_CUSTOMPROCESSING_DISABLED, /* Option for custom processing in FDK */
      (uint8)1U, /* Reference to Can2Can routing entry */
      (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED,  /* Can2Eth not used */
      (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED  /* Can2Other not used */
    }
    } /* End advanced filter 1 for BCAN_0 */,
    { /* Advanced filter 2 for BCAN_0 */
    { /* RxFilter */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0x141U & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x3U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)0U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
    { /* AdvancedFeature */
      LLCE_AF_AUTHENTICATION_DISABLED, /* Option for frame authentication feature */
      LLCE_AF_HOSTRECEIVE_DISABLED, /* Option for host receive feature */
      LLCE_AF_LOGGING_DISABLED, /* Option for logging feature */
      LLCE_AF_CUSTOMPROCESSING_DISABLED, /* Option for custom processing in FDK */
      (uint8)2U, /* Reference to Can2Can routing entry */
      (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED,  /* Can2Eth not used */
      (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED  /* Can2Other not used */
    }
    } /* End advanced filter 2 for BCAN_0 */,
    { /* Advanced filter 3 for BCAN_0 */
    { /* RxFilter */
      (uint32)(((0x7ffU & CAN_43_LLCE_MAX_IDMASK) | LLCE_CAN_MB_RTR_U32) | LLCE_CAN_MB_IDE_U32),  /* uIdMask */
      (uint32)((0x378U & CAN_43_LLCE_MAX_IDMASK)),   /* MessageId */
      (uint16)0x4U, /* FilterId */
      (uint16)0x14, /* MBCount */
      (uint16)0U, /* Output filter address */
      (uint8)0U,   /* Rx is reported through this interface . */
      LLCE_CAN_ENTRY_CFG_MASKED,
      USE_LONG_MB /* Use 64B size Hw Object */
    },
    { /* AdvancedFeature */
      LLCE_AF_AUTHENTICATION_DISABLED, /* Option for frame authentication feature */
      LLCE_AF_HOSTRECEIVE_DISABLED, /* Option for host receive feature */
      LLCE_AF_LOGGING_DISABLED, /* Option for logging feature */
      LLCE_AF_CUSTOMPROCESSING_DISABLED, /* Option for custom processing in FDK */
      (uint8)3U, /* Reference to Can2Can routing entry */
      (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED,  /* Can2Eth not used */
      (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED  /* Can2Other not used */
    }
    } /* End advanced filter 3 for BCAN_0 */,
  }
};

#ifdef __cplusplus
}
#endif

