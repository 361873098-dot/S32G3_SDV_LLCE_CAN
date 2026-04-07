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
#ifndef CDD_RM_IPW_H
#define CDD_RM_IPW_H

/**
*   @file CDD_Rm_Ipw.h
*
*   @addtogroup RM_MODULE RM Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Rm_Ipw_Cfg.h"

#if (RM_IPW_ENABLE_XRDC == STD_ON)
    #include "Xrdc_Ip.h"
#endif

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)
    #include "Sema42_Ip.h"
#endif

#if (RM_IPW_ENABLE_MPU_M7 == STD_ON)
    #include "Mpu_M7_Ip.h"
#endif

#if (RM_IPW_ENABLE_MSCM == STD_ON)
    #include "Mscm_Ip.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_VENDOR_ID                    43
#define RM_IPW_AR_RELEASE_MAJOR_VERSION     4
#define RM_IPW_AR_RELEASE_MINOR_VERSION     4
#define RM_IPW_AR_RELEASE_REVISION_VERSION  0
#define RM_IPW_SW_MAJOR_VERSION             4
#define RM_IPW_SW_MINOR_VERSION             0
#define RM_IPW_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_Ipw_Cfg.h */
#if (RM_IPW_VENDOR_ID != RM_IPW_CFG_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_IPW_CFG_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_IPW_CFG_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h are different"
#endif

#if (RM_IPW_ENABLE_XRDC == STD_ON)
/* Checks against Xrdc_Ip.h */
#if (RM_IPW_VENDOR_ID != RM_XRDC_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and Xrdc_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_XRDC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_XRDC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_XRDC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and Xrdc_Ip.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_XRDC_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_XRDC_IP_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_XRDC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and Xrdc_Ip.h are different"
#endif
#endif

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)
/* Checks against Sema42_Ip.h */
#if (RM_IPW_VENDOR_ID != RM_SEMA42_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and Sema42_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and Sema42_Ip.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_SEMA42_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_SEMA42_IP_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_SEMA42_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and Sema42_Ip.h are different"
#endif
#endif

#if (RM_IPW_ENABLE_MPU_M7 == STD_ON)
/* Checks against Mpu_M7_Ip.h */
#if (RM_IPW_VENDOR_ID != RM_MPU_M7_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and Mpu_M7_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_MPU_M7_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_MPU_M7_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_MPU_M7_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and Mpu_M7_Ip.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_MPU_M7_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_MPU_M7_IP_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_MPU_M7_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and Mpu_M7_Ip.h are different"
#endif
#endif

#if (RM_IPW_ENABLE_MSCM == STD_ON)
/* Checks against Mscm_Ip.h */
#if (RM_IPW_VENDOR_ID != RM_MSCM_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and Mscm_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_MSCM_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_MSCM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and Mscm_Ip.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_MSCM_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_MSCM_IP_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_MSCM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and Mscm_Ip.h are different"
#endif
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#if (RM_IPW_ENABLE_XRDC == STD_ON)
#define RM_XRDC_UNKNOWN_DOMAIN                (XRDC_UNKNOWN_DOMAIN)

#endif

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)
#define RM_SEMAPHORE_FREE                     (SEMA42_IP_UNLOCKED_GATE)

#define RM_SEMAPHORE_UNKNOWN_DOMAINID         (SEMA42_IP_UNKNOWN_DOMAINID)
#endif

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (RM_IPW_ENABLE_XRDC == STD_ON)
/** Enumeration listing secure attributes of a XRDC master */
typedef Xrdc_Ip_SecureAttributeType   Rm_XrdcSecureAttributeType;

/** Structure used to retrieve information violation details and the domain ID where violation occured. */
typedef Xrdc_Ip_DomainIDErrStatusType Rm_XrdcDomainIDErrStatusType;

/** Master core type, use for PID feature*/
typedef Xrdc_Ip_MasterCoreType        Rm_XrdcMasterCoreType;

/** Domain ID */
typedef uint32                        Rm_DomainIdType;

typedef Xrdc_Ip_InstanceConfigType Rm_XrdcInstanceConfigType;
#endif

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)
/** Channel Type for Sema42 */
typedef uint8                         Rm_Sema42_ChannelType;

/** Status Type for Sema42 */
typedef Sema42_Ip_StatusType          Rm_Sema42_StatusType;
#endif

#if (RM_IPW_ENABLE_MPU_M7 == STD_ON)
/** Configuration structure containing the region configuration for Mpu M7 */
typedef Mpu_M7_Ip_RegionConfigType    Rm_Mpu_M7_RegionConfigType;

/** Enumeration listing access permisions for Mpu M7 */
typedef Mpu_M7_Ip_AccessRightsType    Rm_Mpu_M7_AccessRightsType;

/** Enumeration listing the possible access errors for Mpu M7 */
typedef Mpu_M7_Ip_ErrorDetailsType    Rm_Mpu_M7_ErrorDetailsType;
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

#if (RM_IPW_ENABLE_XRDC == STD_ON)
void Rm_Ipw_Xrdc_Init(Rm_Ipw_ConfigType const * pIpwConfig);

void Rm_Ipw_Xrdc_InstanceInit(Rm_XrdcInstanceConfigType const * pXrdcInstanceConfig);

void Rm_Ipw_Xrdc_SetProcessID(Rm_XrdcMasterCoreType MasterCore, uint8 u8Pid, Rm_XrdcSecureAttributeType SecureAttr);

void Rm_Ipw_Xrdc_GetDomainIDErrorStatus(uint32 u32Instance, Rm_XrdcDomainIDErrStatusType * pXrdcDomainIDErrorStatus);

uint32 Rm_Ipw_Xrdc_GetDomainID(uint32 u32Instance);

#endif

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)

void Rm_Ipw_Sema4_Init(Rm_Ipw_ConfigType const * pIpwConfig);     

Std_ReturnType Rm_Ipw_Sema4_LockGate(const uint8 u8LogicChannel, uint8 u8DomainId);

Std_ReturnType Rm_Ipw_Sema4_UnlockGate(const uint8 u8LogicChannel);

void Rm_Ipw_Sema4_ResetGate(const uint8 u8LogicChannel);

void Rm_Ipw_Sema4_ResetAllGates(void);

uint8 Rm_Ipw_Sema4_GetGateLocker(const uint8 u8LogicChannel);

Rm_DomainIdType Rm_Ipw_SemaphoreGetDomainID(Rm_Sema42_ChannelType ChannelNumber);

Rm_DomainIdType Rm_Ipw_Sema4_GetResetGateDomainId(Rm_Sema42_ChannelType ChannelNumber);

boolean Rm_Ipw_Sema4_IsResetGateStateIdle(Rm_Sema42_ChannelType ChannelNumber);

Rm_Sema42_ChannelType Rm_Ipw_Sema4_GetResetedGate(Rm_Sema42_ChannelType ChannelNumber);
#endif

#if (RM_IPW_ENABLE_MPU_M7 == STD_ON)
void Rm_Ipw_Mpu_M7_Init(Rm_Ipw_ConfigType const * pIpwConfig);

void Rm_Ipw_Mpu_M7_SetRegionConfig(uint8 u8RegionNum, const Rm_Mpu_M7_RegionConfigType * const pUserConfigPtr);

void Rm_Ipw_Mpu_M7_EnableRegion(uint8 u8RegionNum, boolean bEnable);

void Rm_Ipw_Mpu_M7_SetAccessRight(uint8 u8RegionNum, Rm_Mpu_M7_AccessRightsType eRights);

boolean Rm_Ipw_Mpu_M7_GetErrorDetails(Rm_Mpu_M7_ErrorDetailsType * pErrorDetails);

#if (RM_IPW_MPU_MULTICORE_SUPPORT == STD_ON)
void Rm_Ipw_Mpu_M7_MulticoreInit(void);
#endif
#endif

#if (RM_IPW_ENABLE_MSCM == STD_ON)
void Rm_Ipw_Mscm_Init(Rm_Ipw_ConfigType const * pIpwConfig);
#endif

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_RM_IPW_H */

