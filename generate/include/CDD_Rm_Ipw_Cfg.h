/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*    Copyright 2020-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CDD_RM_IPW_CFG_H
#define CDD_RM_IPW_CFG_H

/**
*   @file CDD_Rm_Ipw_Cfg.h
*
*   @addtogroup RM_MODULE RM Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Rm_Ipw_VS_0_PBcfg.h"
#include "CDD_Rm_Ipw_VS_HEADLESS_PBcfg.h"

#include "Xrdc_Ip_Types.h"
#include "Mpu_M7_Ip_Types.h"
#include "Sema42_Ip_Types.h"
#include "Mscm_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_CFG_VENDOR_ID                    43
#define RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_IPW_CFG_AR_RELEASE_MINOR_VERSION     4
#define RM_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_IPW_CFG_SW_MAJOR_VERSION             4
#define RM_IPW_CFG_SW_MINOR_VERSION             0
#define RM_IPW_CFG_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_Ipw_VS_0_PBcfg.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_IPW_PBCFG_VS_0_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_0_PBcfg.h have different vendor ids"
#endif
#if ((RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_PBCFG_VS_0_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_PBCFG_VS_0_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_PBCFG_VS_0_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_0_PBcfg.h are different"
#endif
#if ((RM_IPW_CFG_SW_MAJOR_VERSION != RM_IPW_PBCFG_VS_0_SW_MAJOR_VERSION) || \
     (RM_IPW_CFG_SW_MINOR_VERSION != RM_IPW_PBCFG_VS_0_SW_MINOR_VERSION) || \
     (RM_IPW_CFG_SW_PATCH_VERSION != RM_IPW_PBCFG_VS_0_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_0_PBcfg.h are different"
#endif
/* Checks against CDD_Rm_Ipw_VS_HEADLESS_PBcfg.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_IPW_PBCFG_VS_HEADLESS_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_HEADLESS_PBcfg.h have different vendor ids"
#endif
#if ((RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_PBCFG_VS_HEADLESS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_PBCFG_VS_HEADLESS_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_PBCFG_VS_HEADLESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_HEADLESS_PBcfg.h are different"
#endif
#if ((RM_IPW_CFG_SW_MAJOR_VERSION != RM_IPW_PBCFG_VS_HEADLESS_SW_MAJOR_VERSION) || \
     (RM_IPW_CFG_SW_MINOR_VERSION != RM_IPW_PBCFG_VS_HEADLESS_SW_MINOR_VERSION) || \
     (RM_IPW_CFG_SW_PATCH_VERSION != RM_IPW_PBCFG_VS_HEADLESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_HEADLESS_PBcfg.h are different"
#endif

/* Checks against Xrdc_Ip_Types.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_XRDC_IP_TYPES_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and Xrdc_Ip_Types.h have different vendor ids"
#endif
#if (( RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_XRDC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_XRDC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_XRDC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and Xrdc_Ip_Types.h are different"
#endif
#if (( RM_IPW_CFG_SW_MAJOR_VERSION != RM_XRDC_IP_TYPES_SW_MAJOR_VERSION) || \
     ( RM_IPW_CFG_SW_MINOR_VERSION != RM_XRDC_IP_TYPES_SW_MINOR_VERSION) || \
     ( RM_IPW_CFG_SW_PATCH_VERSION != RM_XRDC_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and Xrdc_Ip_Types.h are different"
#endif

/* Checks against Mpu_M7_Ip_Types.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_MPU_M7_IP_TYPES_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and Mpu_M7_Ip_Types.h have different vendor ids"
#endif
#if (( RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MPU_M7_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_MPU_M7_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_MPU_M7_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and Mpu_M7_Ip_Types.h are different"
#endif
#if (( RM_IPW_CFG_SW_MAJOR_VERSION != RM_MPU_M7_IP_TYPES_SW_MAJOR_VERSION) || \
     ( RM_IPW_CFG_SW_MINOR_VERSION != RM_MPU_M7_IP_TYPES_SW_MINOR_VERSION) || \
     ( RM_IPW_CFG_SW_PATCH_VERSION != RM_MPU_M7_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and Mpu_M7_Ip_Types.h are different"
#endif

/* Checks against Sema42_Ip_Types.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_SEMA42_IP_TYPES_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and Sema42_Ip_Types.h have different vendor ids"
#endif
#if ((RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_SEMA42_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_SEMA42_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and Sema42_Ip_Types.h are different"
#endif
#if ((RM_IPW_CFG_SW_MAJOR_VERSION != RM_SEMA42_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_IPW_CFG_SW_MINOR_VERSION != RM_SEMA42_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_IPW_CFG_SW_PATCH_VERSION != RM_SEMA42_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and Sema42_Ip_Types.h are different"
#endif

/* Checks against Mscm_Ip_Types.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_MSCM_IP_TYPES_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and Mscm_Ip_Types.h have different vendor ids"
#endif
#if (( RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MSCM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_MSCM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_MSCM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and Mscm_Ip_Types.h are different"
#endif
#if (( RM_IPW_CFG_SW_MAJOR_VERSION != RM_MSCM_IP_TYPES_SW_MAJOR_VERSION) || \
     ( RM_IPW_CFG_SW_MINOR_VERSION != RM_MSCM_IP_TYPES_SW_MINOR_VERSION) || \
     ( RM_IPW_CFG_SW_PATCH_VERSION != RM_MSCM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and Mscm_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/

#define RM_IPW_ENABLE_XRDC                                (STD_OFF)
#define RM_IPW_ENABLE_MPU_M7                              (STD_ON)
#define RM_IPW_ENABLE_SEMA42                              (STD_OFF)
#define RM_IPW_MPU_MULTICORE_SUPPORT                      (STD_OFF)
#define RM_IPW_ENABLE_MSCM                                (STD_OFF)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#if (STD_ON == RM_IPW_ENABLE_SEMA42)
/**
* @brief          Sema42 Logic Channel configuration structure
*/
typedef struct
{
    uint32 u32HardwareInstance;                                /*!< Hardware Instance */
    uint8  u8HardwareChannel;                                  /*!< Hardware Channel  */
} Rm_Ipw_Sema42_LogicChannelConfigType;

/**
* @brief          Sema42 Logic Channel configuration structure
*/
typedef struct
{
    const Rm_Ipw_Sema42_LogicChannelConfigType*   pLogicChannelArray;        /*!< Logic Channel Array */
} Rm_Ipw_Sema42_ConfigType;
#endif

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct
{
#if (STD_ON == RM_IPW_ENABLE_XRDC)
    const Xrdc_Ip_ConfigType         *Rm_Ipw_pXrdcConfig;
#endif
#if (STD_ON == RM_IPW_ENABLE_SEMA42)
    const Rm_Ipw_Sema42_ConfigType   *Rm_Ipw_pSema42Config;
#endif
#if (STD_ON == RM_IPW_ENABLE_MSCM)
    const Mscm_Ip_ConfigType         *Rm_Ipw_pMscmConfig;
#endif
#if (STD_ON == RM_IPW_ENABLE_MPU_M7)
    const Mpu_M7_Ip_ConfigType       *Rm_Ipw_pMpuConfig;
#endif
} Rm_Ipw_ConfigType;

/**
* @brief   Collection of all configuration structures declarations.
*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

RM_IPW_CONFIG_VS_0_PB
RM_IPW_CONFIG_VS_HEADLESS_PB

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CDD_RM_IPW_CFG_H */

