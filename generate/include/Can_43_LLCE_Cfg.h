/**
*   @file    $filename$
*   @version 1.0.11
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

#ifndef CAN_43_LLCE_CFG_H
#define CAN_43_LLCE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Soc_Ips.h"
#include "OsIf.h"
#include "Can_43_LLCE_VS_0_PBcfg.h"
#include "Can_43_LLCE_VS_HEADLESS_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_43_LLCE_VENDOR_ID_CFG_H                     43
#define CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_CFG_H      4
#define CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_CFG_H      4
#define CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_CFG_H   0
#define CAN_43_LLCE_SW_MAJOR_VERSION_CFG_H              1
#define CAN_43_LLCE_SW_MINOR_VERSION_CFG_H              0
#define CAN_43_LLCE_SW_PATCH_VERSION_CFG_H              11

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_AR_RELEASE_MAJOR_VERSION) || \
(CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_CFG_H != STD_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Can_43_LLCE_Cfg.h and Std_Types.h are different"
#endif
#endif
/* Check if header file and Can_43_LLCE_VS_0_PBcfg.h configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_VS_0_PBCFG_H != CAN_43_LLCE_VENDOR_ID_CFG_H)
#error "Can_43_LLCE_VS_0_PBcfg.h and Can_43_LLCE_Cfg.h have different vendor IDs"
#endif
/* Check if header file and Can_43_LLCE_VS_0_PBcfg.h configuration header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_H != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
(CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_H != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_CFG_H) || \
(CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_H != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_CFG_H))
#error "AutoSar Version Numbers of Can_43_LLCE_VS_0_PBcfg.h and Can_43_LLCE_Cfg.h are different"
#endif
/* Check if header file and Can_43_LLCE_VS_0_PBcfg.h configuration header file are of the same software version */
#if ((CAN_43_LLCE_SW_MAJOR_VERSION_VS_0_PBCFG_H != CAN_43_LLCE_SW_MAJOR_VERSION_CFG_H) || \
(CAN_43_LLCE_SW_MINOR_VERSION_VS_0_PBCFG_H != CAN_43_LLCE_SW_MINOR_VERSION_CFG_H) || \
(CAN_43_LLCE_SW_PATCH_VERSION_VS_0_PBCFG_H != CAN_43_LLCE_SW_PATCH_VERSION_CFG_H))
#error "Software Version Numbers of Can_43_LLCE_VS_0_PBcfg.h and Can_43_LLCE_Cfg.h are different"
#endif
/* Check if header file and Can_43_LLCE_VS_HEADLESS_PBcfg.h configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_VS_HEADLESS_PBCFG_H != CAN_43_LLCE_VENDOR_ID_CFG_H)
#error "Can_43_LLCE_VS_HEADLESS_PBcfg.h and Can_43_LLCE_Cfg.h have different vendor IDs"
#endif
/* Check if header file and Can_43_LLCE_VS_HEADLESS_PBcfg.h configuration header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_VS_HEADLESS_PBCFG_H != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
(CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_VS_HEADLESS_PBCFG_H != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_CFG_H) || \
(CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_VS_HEADLESS_PBCFG_H != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_CFG_H))
#error "AutoSar Version Numbers of Can_43_LLCE_VS_HEADLESS_PBcfg.h and Can_43_LLCE_Cfg.h are different"
#endif
/* Check if header file and Can_43_LLCE_VS_HEADLESS_PBcfg.h configuration header file are of the same software version */
#if ((CAN_43_LLCE_SW_MAJOR_VERSION_VS_HEADLESS_PBCFG_H != CAN_43_LLCE_SW_MAJOR_VERSION_CFG_H) || \
(CAN_43_LLCE_SW_MINOR_VERSION_VS_HEADLESS_PBCFG_H != CAN_43_LLCE_SW_MINOR_VERSION_CFG_H) || \
(CAN_43_LLCE_SW_PATCH_VERSION_VS_HEADLESS_PBCFG_H != CAN_43_LLCE_SW_PATCH_VERSION_CFG_H))
#error "Software Version Numbers of Can_43_LLCE_VS_HEADLESS_PBcfg.h and Can_43_LLCE_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief          Enable support for MAC generation and verification.
* @details        Enable support for MAC generation and verification.
*
*/
#define CAN_43_LLCE_HSE_SUPPORT_ENABLE   (STD_OFF)  
#define RXLUT2_ENABLE  (STD_OFF) 
#define CAN_43_LLCE_MAX_IDMASK    (Can_IdType)0x1FFFFFFFU 
#define CanHO_Config1_RX0   0  /* RECEIVE object of Can Controller ID = 0 */ 
#define CanHOH_Routing_RX0   1  /* RECEIVE object of Can Controller ID = 0 */ 
#define CanHOH_Can2CanFD   2  /* RECEIVE object of Can Controller ID = 0 */ 
#define CanHOH_CanFD2Can   3  /* RECEIVE object of Can Controller ID = 0 */ 
#define CanHOH_Routing_RX0_IdRemap   4  /* RECEIVE object of Can Controller ID = 0 */ 
#define CanHO_Config1_RX14_Routing   5  /* RECEIVE object of Can Controller ID = 2 */ 
#define CanHO_Config1_RX14_RCan2CanFD   6  /* RECEIVE object of Can Controller ID = 2 */ 
#define CanHO_Config1_RX14_RCanFD2Can   7  /* RECEIVE object of Can Controller ID = 2 */ 
#define CanHO_Config1_RX14_IdRemap   8  /* RECEIVE object of Can Controller ID = 2 */ 
#define CanHO_Config1_TX1   9  /* TRANSMIT object of Can Controller ID = 1 */ 
#define CanHO_Config1_TX15   10  /* TRANSMIT object of Can Controller ID = 3 */ 
#define CAN_43_LLCE_LPDU_NOTIFICATION_ENABLE    (STD_OFF) 
#define CAN_43_LLCE_LPDU_CALLOUT_EXTENSION    (STD_OFF) 
#define CAN_43_LLCE_RX_TIMESTAMP    (STD_ON) 
#define CAN_43_LLCE_ACK_TIMESTAMP    (STD_ON) 
#define CAN_43_LLCE_CUSTOM_RX_CALLBACK_USED    (STD_OFF) 
#define CAN_43_LLCE_CUSTOM_WRITE_CALLBACK_USED    (STD_OFF) 
#define CAN_43_LLCE_CUSTOM_CONFIRMATION_CALLBACK    (STD_OFF) 
#define CAN_43_LLCE_ERROR_NOTIF_ENABLE    (STD_ON) 
#define CAN_43_LLCE_SET_BAUDRATE_API   (STD_ON) 
#define CAN_LLCE_USE_HEADLESSMODE   (STD_OFF) 
/** Report controllers started without waiting to synchronise on bus */
#define CAN_43_LLCE_CONTROLLER_START_NOSYNC   (STD_OFF)

#define CAN_43_LLCE_DEV_ERROR_DETECT   (STD_ON) 

#define CAN_43_LLCE_VERSION_INFO_API   (STD_OFF) 
#define CAN_43_LLCE_INSTANCE   0 
#ifndef AUTOSAR_COMPATIBLE_MODE
#define AUTOSAR_COMPATIBLE_MODE   (STD_ON)
#endif
#define CAN_43_LLCE_MULTICORE_ENABLED        (STD_OFF) 
#define CAN_43_LLCE_MAX_PARTITIONS    1U

#define CAN_43_LLCE_TRIGGER_TRANSMIT_EN   (STD_OFF) 
#define CAN_43_LLCE_DUMMY_HRH_EN   (STD_OFF) 
#define CAN_43_LLCE_MAXHRH_CONFIGURED 9 
#define CAN_43_LLCE_MAXHTH_CONFIGURED 2 
#define CAN_43_LLCE_MAXHOH_CONFIGURED (CAN_43_LLCE_MAXHRH_CONFIGURED + CAN_43_LLCE_MAXHTH_CONFIGURED) 
#define CAN_43_LLCE_FIRST_HTH_CONFIGURED 9 
#define CAN_43_LLCE_MAXRXMB_CONFIGURED 180 
#define CAN_43_LLCE_MAXTXMB_CONFIGURED 20 
#define CAN_43_LLCE_MAXCTRL_CONFIGURED 4 
#define CAN_43_LLCE_TXPOLL_SUPPORTED (STD_OFF) 
#define CAN_43_LLCE_RXPOLL_SUPPORTED (STD_OFF) 
#define CAN_43_LLCE_BUSOFFPOLL_SUPPORTED (STD_OFF) 
#define CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED (STD_ON) 
#define CAN_43_LLCE_CFGSET0_MAX_BAUDRATE_FC_0_0    3U
#define CAN_43_LLCE_CFGSET0_MAX_BAUDRATE_FC_1_1    3U
#define CAN_43_LLCE_CFGSET0_MAX_BAUDRATE_FC_14_2    3U
#define CAN_43_LLCE_CFGSET0_MAX_BAUDRATE_FC_15_3    3U
#define CAN_43_LLCE_FD_MODE_ENABLE (STD_ON) 
#define CAN_43_LLCE_TIMEOUT_DURATION     100000U
#define CAN_43_LLCE_SERVICE_TIMEOUT_TYPE    OSIF_COUNTER_SYSTEM
#define CAN_43_LLCE_PRECOMPILE_SUPPORT    (STD_OFF) 
#define CAN_43_LLCE_MAINFUNCTION_MULTIPLE_READ    (STD_OFF) 
#define CAN_43_LLCE_MAINFUNCTION_MULTIPLE_WRITE    (STD_OFF) 
#define CAN_43_LLCE_MAINFUNCTION_MODE_PERIOD   0.001F 
#define CAN_43_LLCE_CONFIG_EXT \
    CAN_43_LLCE_CONFIG_VS_0_PB \
    CAN_43_LLCE_CONFIG_VS_HEADLESS_PB 
#define CAN_43_LLCE_API_ENABLE_ABORT_MB      (STD_OFF) 
#define CAN_43_LLCE_ABORT_ONLY_ONE_MB      (STD_OFF) 
/*
* @brief          Support for Manual BusOff recovery request API
* @details        Enables an additional API for requesting recovery from BusOff confinement state. 
*                 It is enabled when at least one controller configuration handles the recovery from bus-off manually.
*                 Not Autosar required.
*/
#define CAN_43_LLCE_API_MANUAL_BUSOFF_RECOVERY      (STD_OFF) 

/*
* @brief          Checks whether the BUSOFF_RECOVERY mode is ENABLED.
* @details        BUSOFF_RECOVERY is ENABLED when Manual or Auto Bus-off Recovery is set for any controller.
*                 Not Autosar required.
*/
#define CAN_43_LLCE_BUSOFF_RECOVERY_ENABLED      (STD_OFF) 


 

#ifdef __cplusplus
}
#endif

#endif /* CAN_43_LLCE_CFG_H */

/** @} */

