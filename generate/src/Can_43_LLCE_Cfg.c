/**
*   @file    Can_43_LLCE_Cfg.c
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Configuration Structures for PreCompile.
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


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_LLCE.h"
#include "Can_43_LLCE_IPW.h"

/**
* @file           Can_43_LLCE_Cfg.c
*/



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_43_LLCE_VENDOR_ID_PCCFG_C                    43
#define CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PCCFG_C     4
#define CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PCCFG_C     4
#define CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PCCFG_C  0
#define CAN_SW_MAJOR_VERSION_PCCFG_C             1
#define CAN_SW_MINOR_VERSION_PCCFG_C             0
#define CAN_SW_PATCH_VERSION_PCCFG_C             11

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_PCCFG_C != CAN_43_LLCE_VENDOR_ID)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_43_LLCE_Cfg.c and Can_43_LLCE.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_43_LLCE_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_43_LLCE_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_43_LLCE_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_43_LLCE_Cfg.c and Can_43_LLCE.h are different"
#endif

/* Check if current file and Can_IPW configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_PCCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_43_LLCE_Cfg.c and Can_43_LLCE.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_43_LLCE_Cfg.c and Can_43_LLCE.h are different"
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


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
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

