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
*   Copyright 2020-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef MSCM_IP_CFG_H
#define MSCM_IP_CFG_H

/**
*   @file Mscm_Ip_Cfg.h
*
*   @addtogroup MSCM_IP MSCM IPV Driver
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
#include "Mcal.h"

#include "Mscm_Ip_VS_0_PBcfg.h"
#include "Mscm_Ip_VS_HEADLESS_PBcfg.h"
#include "Mscm_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_CFG_VENDOR_ID                    43
#define RM_MSCM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_MSCM_IP_CFG_AR_RELEASE_MINOR_VERSION     4
#define RM_MSCM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_MSCM_IP_CFG_SW_MAJOR_VERSION             4
#define RM_MSCM_IP_CFG_SW_MINOR_VERSION             0
#define RM_MSCM_IP_CFG_SW_PATCH_VERSION             2

/*==================================================================================================
*                                   FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mscm_Ip_VS_0_PBcfg.h */
#if (RM_MSCM_IP_CFG_VENDOR_ID != RM_MSCM_IP_PBCFG_VS_0_VENDOR_ID)
    #error "Mscm_Ip_Cfg.h and Mscm_Ip_VS_0_PBcfg.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MSCM_IP_PBCFG_VS_0_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MSCM_IP_PBCFG_VS_0_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MSCM_IP_PBCFG_VS_0_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip_Cfg.h and Mscm_Ip_VS_0_PBcfg.h are different"
#endif
#if ((RM_MSCM_IP_CFG_SW_MAJOR_VERSION != RM_MSCM_IP_PBCFG_VS_0_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_CFG_SW_MINOR_VERSION != RM_MSCM_IP_PBCFG_VS_0_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_CFG_SW_PATCH_VERSION != RM_MSCM_IP_PBCFG_VS_0_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mscm_Ip_Cfg.h and Mscm_Ip_VS_0_PBcfg.h are different"
#endif

/* Checks against Mscm_Ip_VS_HEADLESS_PBcfg.h */
#if (RM_MSCM_IP_CFG_VENDOR_ID != RM_MSCM_IP_PBCFG_VS_HEADLESS_VENDOR_ID)
    #error "Mscm_Ip_Cfg.h and Mscm_Ip_VS_HEADLESS_PBcfg.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MSCM_IP_PBCFG_VS_HEADLESS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MSCM_IP_PBCFG_VS_HEADLESS_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MSCM_IP_PBCFG_VS_HEADLESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip_Cfg.h and Mscm_Ip_VS_HEADLESS_PBcfg.h are different"
#endif
#if ((RM_MSCM_IP_CFG_SW_MAJOR_VERSION != RM_MSCM_IP_PBCFG_VS_HEADLESS_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_CFG_SW_MINOR_VERSION != RM_MSCM_IP_PBCFG_VS_HEADLESS_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_CFG_SW_PATCH_VERSION != RM_MSCM_IP_PBCFG_VS_HEADLESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mscm_Ip_Cfg.h and Mscm_Ip_VS_HEADLESS_PBcfg.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_MSCM_IP_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_MSCM_IP_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Mscm_Ip_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Checks against Mscm_Ip_Types.h */
#if (RM_MSCM_IP_CFG_VENDOR_ID != RM_MSCM_IP_TYPES_VENDOR_ID)
    #error "Mscm_Ip_Cfg.h and Mscm_Ip_Types.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MSCM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MSCM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MSCM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip_Cfg.h and Mscm_Ip_Types.h are different"
#endif
#if ((RM_MSCM_IP_CFG_SW_MAJOR_VERSION != RM_MSCM_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_CFG_SW_MINOR_VERSION != RM_MSCM_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_CFG_SW_PATCH_VERSION != RM_MSCM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mscm_Ip_Cfg.h and Mscm_Ip_Types.h are different"
#endif

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
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* MSCM_IP_CFG_H */

