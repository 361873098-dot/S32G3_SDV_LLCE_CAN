/**
*   @file    Can_43_LLCE_PBcfg.c
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Configuration Structures for PostBuild.
*
*   @internal
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

/*
   (CAN078) The code file structure shall not be defined within this specification completely.
            At this point it shall be pointed out that the code-file structure shall include the following file named: Can_43_LLCE_PBcfg.c.
            This file shall contain all post-build time configurable parameters.
   (CAN221) VariantPB: (Mix of precompile and Post Build multiple selectable configurable configurations.
*/
/**
* @file           Can_43_LLCE_PBcfg.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_LLCE.h"
#include "Can_43_LLCE_IPW.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_43_LLCE_PBcfg.c
*/
#define CAN_43_LLCE_VENDOR_ID_PBCFG_C                   43
#define CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
#define CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PBCFG_C     4
#define CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PBCFG_C  0
#define CAN_SW_MAJOR_VERSION_PBCFG_C             1
#define CAN_SW_MINOR_VERSION_PBCFG_C             0
#define CAN_SW_PATCH_VERSION_PBCFG_C             11

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_PBCFG_C != CAN_43_LLCE_VENDOR_ID)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_43_LLCE_PBcfg.c and Can_43_LLCE.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_43_LLCE_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_43_LLCE_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_43_LLCE_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_43_LLCE_PBcfg.c and Can_43_LLCE.h are different"
#endif

/* Check if current file and Can_IPW configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_PBCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_43_LLCE_PBcfg.c and Can_43_LLCE_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_43_LLCE_PBcfg.c and Can_43_LLCE_IPW.h are different"
#endif

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Can_43_LLCE_MemMap.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define LLCE_CTRL_0_MAX_RX_FILTERS      1
#define LLCE_CTRL_0_MAX_RXAF_FILTERS    4
#define LLCE_CTRL_14_MAX_RX_FILTERS      4

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================*/
/**
* @brief        Configuration parameters of the entire platform.
* @details      Config parameters needed for init platform command. E.g:
*               Maximum number of filters requested to be supported by filtering hardware. It is used to generate the data structures used for tracking used hardware filters.
*               Maximum number of RX hardware objects (for interrupt mode) of each channel needed to be reserved for RX buffering mechanism.
*               Maximum number of RX hardware objects of each polling class needed to be reserved for RX buffering mechanism.
*               Maximum number of TX confirmation buffers (for interrupt mode) of each channel needed to be reserved for TX confirmations buffering mechanism.
*               Maximum number of TX confirmation buffers of each polling class needed to be reserved for TX confirmations buffering mechanism.
*
*/
/*==================================================================================================*/
static const Llce_Can_InitPlatformCmdType PlatformInitConfig_VS_0 = {
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
};

/*==================================================================================================*/
/**
* @brief          Arrays of filters for LLCE
* @details        Lists of regular and advanced reception filters to be sent to LLCE, grouped by controller
*
*/
/*==================================================================================================*/
static Llce_Can_ReceiveFilterType Llce_Rx_Filters_Ctrl0_PB_VS_0 [ LLCE_CTRL_0_MAX_RX_FILTERS ] =
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
  }
};
static Llce_Can_ReceiveFilterType Llce_Rx_Filters_Ctrl14_PB_VS_0 [ LLCE_CTRL_14_MAX_RX_FILTERS ] =
{   
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
  }
};
/* List of regular filter arrays */
static Llce_Can_ReceiveFilterType * Llce_Rx_Filters_List_VS_0[] =
{
    Llce_Rx_Filters_Ctrl0_PB_VS_0,
    NULL_PTR /* No filters for channel 1 */,
    NULL_PTR /* No filters for channel 2 */,
    NULL_PTR /* No filters for channel 3 */,
    NULL_PTR /* No filters for channel 4 */,
    NULL_PTR /* No filters for channel 5 */,
    NULL_PTR /* No filters for channel 6 */,
    NULL_PTR /* No filters for channel 7 */,
    NULL_PTR /* No filters for channel 8 */,
    NULL_PTR /* No filters for channel 9 */,
    NULL_PTR /* No filters for channel 10 */,
    NULL_PTR /* No filters for channel 11 */,
    NULL_PTR /* No filters for channel 12 */,
    NULL_PTR /* No filters for channel 13 */,
    Llce_Rx_Filters_Ctrl14_PB_VS_0,
    NULL_PTR /* No filters for channel 15 */
};

static Llce_Can_AdvancedFilterType Llce_RxAf_Filters_Ctrl0_PB_VS_0 [ LLCE_CTRL_0_MAX_RXAF_FILTERS ] =
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
    } /* End advanced filter 3 for BCAN_0 */
 };


/* List of regular filter arrays */
static Llce_Can_AdvancedFilterType * Llce_RxAf_Filters_List_VS_0[] =
{
    Llce_RxAf_Filters_Ctrl0_PB_VS_0,
    NULL_PTR /* No filters for channel 1 */,
    NULL_PTR /* No filters for channel 2 */,
    NULL_PTR /* No filters for channel 3 */,
    NULL_PTR /* No filters for channel 4 */,
    NULL_PTR /* No filters for channel 5 */,
    NULL_PTR /* No filters for channel 6 */,
    NULL_PTR /* No filters for channel 7 */,
    NULL_PTR /* No filters for channel 8 */,
    NULL_PTR /* No filters for channel 9 */,
    NULL_PTR /* No filters for channel 10 */,
    NULL_PTR /* No filters for channel 11 */,
    NULL_PTR /* No filters for channel 12 */,
    NULL_PTR /* No filters for channel 13 */,
    NULL_PTR /* No filters for channel 14 */,
    NULL_PTR /* No filters for channel 15 */
};

/*==================================================================================================*/
/**
* @brief          Information about hardware objects.
* @details        (CAN100)Several TX hardware objects with unique HTHs may be configured. The CanIf module provides the HTH as parameter of the TX request. See Figure 7-2 for a possible configuration.
*
*/
/*==================================================================================================*/

static const Can_43_LLCE_HOHType MessageBufferConfigs_PB_VS_0[CAN_43_LLCE_MAXHOH_CONFIGURED] =
{
    /* CanHO_Config1_RX0 Message Buffer 0 on Can Controller 0 */
    {
        CAN_43_LLCE_RECEIVE,  /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)0U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHOH_Routing_RX0 Message Buffer 1 on Can Controller 0 */
    {
        CAN_43_LLCE_RECEIVE_AF, /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)0U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHOH_Can2CanFD Message Buffer 2 on Can Controller 0 */
    {
        CAN_43_LLCE_RECEIVE_AF, /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)0U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHOH_CanFD2Can Message Buffer 3 on Can Controller 0 */
    {
        CAN_43_LLCE_RECEIVE_AF, /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)0U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHOH_Routing_RX0_IdRemap Message Buffer 4 on Can Controller 0 */
    {
        CAN_43_LLCE_RECEIVE_AF, /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)0U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHO_Config1_RX14_Routing Message Buffer 5 on Can Controller 2 */
    {
        CAN_43_LLCE_RECEIVE,  /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)2U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)14U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHO_Config1_RX14_RCan2CanFD Message Buffer 6 on Can Controller 2 */
    {
        CAN_43_LLCE_RECEIVE,  /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)2U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)14U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHO_Config1_RX14_RCanFD2Can Message Buffer 7 on Can Controller 2 */
    {
        CAN_43_LLCE_RECEIVE,  /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)2U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)14U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHO_Config1_RX14_IdRemap Message Buffer 8 on Can Controller 2 */
    {
        CAN_43_LLCE_RECEIVE,  /* Object Type */
        (uint16)0x14, /* MBCount */
        (uint8)2U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
        (uint8)14U, /* Rx is reported through this interface . */
        (boolean)FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                                     0u,
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHO_Config1_TX1 Message Buffer 9 on Can Controller 1 */
    {
        CAN_43_LLCE_TRANSMIT,  /* Object Type */
        (uint16)0x10, /* MBCount */
        (uint8)1U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        /* Read/Write period reference used when polling mode is selected for this HTH */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HTH configured for interrupt mode, reference not used.*/
        (uint8)1U,   /* Ack reported through this interface . */
        (boolean)FALSE, /* Add no MAC code for frames transmitted using this HTH. */
                                         0u, /* No key handler required if no MAC code is requested */
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }
,

    /* CanHO_Config1_TX15 Message Buffer 10 on Can Controller 3 */
    {
        CAN_43_LLCE_TRANSMIT,  /* Object Type */
        (uint16)0x4, /* MBCount */
        (uint8)3U, /* ControllerId  - based on the order from CanController list */
        (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
        /* Read/Write period reference used when polling mode is selected for this HTH */
        LLCE_CAN_REFERENCE_NOT_USED,   /* HTH configured for interrupt mode, reference not used.*/
        (uint8)15U,   /* Ack reported through this interface . */
        (boolean)FALSE, /* Add no MAC code for frames transmitted using this HTH. */
                                         0u, /* No key handler required if no MAC code is requested */
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        (boolean)FALSE, /* Trigger Transmit disabled */
        #endif
        #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        (boolean)FALSE, /* Dummy HRH disabled */
        #endif
    }

};

/*==================================================================================================*/
/**
* @brief          Configuration of Bcan controller
* @details        Configuration of Bcan controller
*
*/
static const Can_43_LLCE_ControllerBaudrateConfigType ControllerBaudrateCfgSet0_PB_0_VS_0[CAN_43_LLCE_CFGSET0_MAX_BAUDRATE_FC_0_0] =
{
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
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)0
#endif
    }
,

    {
        /* Configuration 1 for CanController ID0 == BCAN_0 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)3 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)13) |      /*Segment 1 */
                      ((uint32)4 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)3U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)1U) |   /* Time segment 1 */
                     ((uint32)1U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)1
#endif
    }
,

    {
        /* Configuration 2 for CanController ID0 == BCAN_0 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)0 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)27) |      /*Segment 1 */
                      ((uint32)10 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)0U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)6U) |   /* Time segment 1 */
                     ((uint32)1U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)2
#endif
    }

};
static const Can_43_LLCE_ControllerBaudrateConfigType ControllerBaudrateCfgSet0_PB_1_VS_0[CAN_43_LLCE_CFGSET0_MAX_BAUDRATE_FC_1_1] =
{
    {
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
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)0
#endif
    }
,

    {
        /* Configuration 1 for CanController ID1 == BCAN_1 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)3 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)13) |      /*Segment 1 */
                      ((uint32)4 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)3U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)1U) |   /* Time segment 1 */
                     ((uint32)1U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)1
#endif
    }
,

    {
        /* Configuration 2 for CanController ID1 == BCAN_1 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)0 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)27) |      /*Segment 1 */
                      ((uint32)10 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)0U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)6U) |   /* Time segment 1 */
                     ((uint32)1U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)2
#endif
    }

};
static const Can_43_LLCE_ControllerBaudrateConfigType ControllerBaudrateCfgSet0_PB_2_VS_0[CAN_43_LLCE_CFGSET0_MAX_BAUDRATE_FC_14_2] =
{
    {
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
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)0
#endif
    }
,

    {
        /* Configuration 1 for CanController ID2 == BCAN_14 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)3 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)13) |      /*Segment 1 */
                      ((uint32)4 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)3U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)1U) |   /* Time segment 1 */
                     ((uint32)1U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)1
#endif
    }
,

    {
        /* Configuration 2 for CanController ID2 == BCAN_14 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)0 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)27) |      /*Segment 1 */
                      ((uint32)10 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)0U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)6U) |   /* Time segment 1 */
                     ((uint32)1U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)2
#endif
    }

};
static const Can_43_LLCE_ControllerBaudrateConfigType ControllerBaudrateCfgSet0_PB_3_VS_0[CAN_43_LLCE_CFGSET0_MAX_BAUDRATE_FC_15_3] =
{
    {
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
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)0
#endif
    }
,

    {
        /* Configuration 1 for CanController ID3 == BCAN_15 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)3 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)13) |      /*Segment 1 */
                      ((uint32)4 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)3U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)1U) |   /* Time segment 1 */
                     ((uint32)1U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)1
#endif
    }
,

    {
        /* Configuration 2 for CanController ID3 == BCAN_15 */
        {
            /* ===== Nominal Bit Timing Register - NCBT ===== */
            (uint32)( ((uint32)0 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
                      ((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                      ((uint32)27) |      /*Segment 1 */
                      ((uint32)10 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
                    ),
            { /* Llce_Can_ControllerFdConfig */
            (uint32)(((uint32)0U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
                     ((uint32)0U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                     ((uint32)6U) |   /* Time segment 1 */
                     ((uint32)1U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            (uint8)LLCE_TRUE,  /* CAN FD enabled */
            (uint8)LLCE_TRUE,  /* BRS activated*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
            (uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
            (uint8)0U, /*Trcv Delay*/
            },
        },
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        (uint16)2
#endif
    }

};

/*==================================================================================================*/
/**
* @brief          LLCE Per-channel Init 
* @details        Information needed to initialize each LLCE channel
*
*/
static const Llce_Can_InitCmdType ControllerInit_VS_0[LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
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
      { /* Options for BCAN_2 */
         /* BCAN_2 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_3 */
         /* BCAN_3 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_4 */
         /* BCAN_4 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_5 */
         /* BCAN_5 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_6 */
         /* BCAN_6 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_7 */
         /* BCAN_7 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_8 */
         /* BCAN_8 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_9 */
         /* BCAN_9 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_10 */
         /* BCAN_10 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_11 */
         /* BCAN_11 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_12 */
         /* BCAN_12 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
      },
      { /* Options for BCAN_13 */
         /* BCAN_13 not enabled */
         (uint32)(0U),
         /* Number of configured HTHs for this controller */
         (uint8)0U
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

};

/*==================================================================================================*/
/**
* @brief          Description of individual Bcan controllers on chip
* @details        Description of individual Bcan controllers on chip
*
*/
static const Can_43_LLCE_ControllerDescriptorType ControllerDescriptors_PB_VS_0[CAN_43_LLCE_MAXCTRL_CONFIGURED] =
{
    /* ControllerDescriptor of CanController_0*/
    {
        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)3U,
        /* Default BaudRate configured for current controller - u8DefaultBaudRateIndex */
        (uint8)0U,
        /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr*/
        ControllerBaudrateCfgSet0_PB_0_VS_0,
        /* u32CoreId placeholder*/
        (uint32)4294967295,
        /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        (uint8)0
    }, /* ControllerDescriptors CanController_0 end */

    /* ControllerDescriptor of CanController_1*/
    {
        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)3U,
        /* Default BaudRate configured for current controller - u8DefaultBaudRateIndex */
        (uint8)0U,
        /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr*/
        ControllerBaudrateCfgSet0_PB_1_VS_0,
        /* u32CoreId placeholder*/
        (uint32)4294967295,
        /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        (uint8)1
    }, /* ControllerDescriptors CanController_1 end */

    /* ControllerDescriptor of CanController_2*/
    {
        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)3U,
        /* Default BaudRate configured for current controller - u8DefaultBaudRateIndex */
        (uint8)0U,
        /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr*/
        ControllerBaudrateCfgSet0_PB_2_VS_0,
        /* u32CoreId placeholder*/
        (uint32)4294967295,
        /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        (uint8)14
    }, /* ControllerDescriptors CanController_2 end */

    /* ControllerDescriptor of CanController_3*/
    {
        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)3U,
        /* Default BaudRate configured for current controller - u8DefaultBaudRateIndex */
        (uint8)0U,
        /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr*/
        ControllerBaudrateCfgSet0_PB_3_VS_0,
        /* u32CoreId placeholder*/
        (uint32)4294967295,
        /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        (uint8)15
    }
};


static const Can_43_LLCE_HwControllerDescriptorType HwControllerDescriptors_PB_VS_0[LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
{
    /* ControllerDescriptor of HwCanController_0*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(
        LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 | /* Rx select by interrupt */
        LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 | /* Tx select by interrupt */
        LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 | /* BusOff select by interrupt */
        0U), 
        /* Can Controller ID in CanIf */
        (uint8)0U,
        (uint8)0U/**< LLCE FIFO Interface used for interrupt processing */
    }, /* ControllerDescriptors HwCanController_0 end */

    /* ControllerDescriptor of HwCanController_1*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(
        LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 | /* Rx select by interrupt */
        LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 | /* Tx select by interrupt */
        LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 | /* BusOff select by interrupt */
        0U), 
        /* Can Controller ID in CanIf */
        (uint8)1U,
        (uint8)1U/**< LLCE FIFO Interface used for interrupt processing */
    }, /* ControllerDescriptors HwCanController_1 end */

    /* ControllerDescriptor of HwCanController_2*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_2 end */

    /* ControllerDescriptor of HwCanController_3*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_3 end */

    /* ControllerDescriptor of HwCanController_4*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_4 end */

    /* ControllerDescriptor of HwCanController_5*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_5 end */

    /* ControllerDescriptor of HwCanController_6*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_6 end */

    /* ControllerDescriptor of HwCanController_7*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_7 end */

    /* ControllerDescriptor of HwCanController_8*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_8 end */

    /* ControllerDescriptor of HwCanController_9*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_9 end */

    /* ControllerDescriptor of HwCanController_10*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_10 end */

    /* ControllerDescriptor of HwCanController_11*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_11 end */

    /* ControllerDescriptor of HwCanController_12*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_12 end */

    /* ControllerDescriptor of HwCanController_13*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(0U),
        /* Can Controller ID in CanIf */
        (uint8)LLCE_NULL_OFFSET_U8,
        /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
        (uint8)LLCE_NULL_OFFSET_U8
    }, /* ControllerDescriptors HwCanController_13 end */

    /* ControllerDescriptor of HwCanController_14*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(
        LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 | /* Rx select by interrupt */
        LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 | /* Tx select by interrupt */
        LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 | /* BusOff select by interrupt */
        0U), 
        /* Can Controller ID in CanIf */
        (uint8)14U,
        (uint8)14U/**< LLCE FIFO Interface used for interrupt processing */
    }, /* ControllerDescriptors HwCanController_14 end */

    /* ControllerDescriptor of HwCanController_15*/
    {
        /* ===== Controller Options for the driver ===== */
        (uint32)(
        LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 | /* Rx select by interrupt */
        LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 | /* Tx select by interrupt */
        LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 | /* BusOff select by interrupt */
        0U), 
        /* Can Controller ID in CanIf */
        (uint8)15U,
        (uint8)15U/**< LLCE FIFO Interface used for interrupt processing */
    }
};


/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
const Can_43_LLCE_ConfigType Can_43_LLCE_Config_VS_0=
{
    &PlatformInitConfig_VS_0, 
    ControllerInit_VS_0, 
    Llce_Rx_Filters_List_VS_0,
    Llce_RxAf_Filters_List_VS_0,
    NULL_PTR, /* There are no filters configured for the second rxlut */
    NULL_PTR,
    MessageBufferConfigs_PB_VS_0, 
    ControllerDescriptors_PB_VS_0, 
    HwControllerDescriptors_PB_VS_0, 
    NULL_PTR, /* No custom processing defined for any HRH */
    (boolean)FALSE, /* LLCE started normally */
    4294967295, /* u32CoreId */ 
    LLCE_CAN_HIF0, /* u8ActiveHif */ 
    0U /* u8DefaultController */
};
    

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Can_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

