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
#ifndef CDD_RM_H
#define CDD_RM_H

/**
*   @file CDD_Rm.h
*
*   @addtogroup RM_MODULE RM Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "CDD_Rm_Cfg.h"
#include "CDD_Rm_Ipw.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_VENDOR_ID                       43
#define RM_MODULE_ID                       255
#define RM_AR_RELEASE_MAJOR_VERSION        4
#define RM_AR_RELEASE_MINOR_VERSION        4
#define RM_AR_RELEASE_REVISION_VERSION     0
#define RM_SW_MAJOR_VERSION                4
#define RM_SW_MINOR_VERSION                0
#define RM_SW_PATCH_VERSION                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of CDD_Rm.h and Mcal.h are different"
    #endif
#endif
/* Checks against CDD_Rm_Cfg.h */
#if (RM_VENDOR_ID != RM_CFG_VENDOR_ID)
    #error "CDD_Rm.h and CDD_Rm_Cfg.h have different vendor ids"
#endif
#if ((RM_AR_RELEASE_MAJOR_VERSION    != RM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AR_RELEASE_MINOR_VERSION    != RM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_AR_RELEASE_REVISION_VERSION != RM_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm.h and CDD_Rm_Cfg.h are different"
#endif
#if ((RM_SW_MAJOR_VERSION != RM_CFG_SW_MAJOR_VERSION) || \
     (RM_SW_MINOR_VERSION != RM_CFG_SW_MINOR_VERSION) || \
     (RM_SW_PATCH_VERSION != RM_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm.h and CDD_Rm_Cfg.h are different"
#endif
/* Checks against CDD_Rm_Ipw.h */
#if (RM_VENDOR_ID != RM_IPW_VENDOR_ID)
    #error "CDD_Rm.h and CDD_Rm_Ipw.h have different vendor ids"
#endif
#if ((RM_AR_RELEASE_MAJOR_VERSION    != RM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AR_RELEASE_MINOR_VERSION    != RM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (RM_AR_RELEASE_REVISION_VERSION != RM_IPW_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm.h and CDD_Rm_Ipw.h are different"
#endif
#if ((RM_SW_MAJOR_VERSION != RM_IPW_SW_MAJOR_VERSION) || \
     (RM_SW_MINOR_VERSION != RM_IPW_SW_MINOR_VERSION) || \
     (RM_SW_PATCH_VERSION != RM_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm.h and CDD_Rm_Ipw.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

/**  Export RM configurations.*/
RM_CONFIG_EXT

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

#if (RM_DEV_ERROR_DETECT == STD_ON)
    #define RM_INIT_ID_U8                               ((uint8)0x00U)
    #define RM_E_ALREADY_INITIALIZED_U8                 ((uint8)0x02U)
    #define RM_E_UNINIT_U8                              ((uint8)0x03U)
    #define RM_E_INIT_FAILED_U8                         ((uint8)0x04U)
#if (RM_GET_VERSION_INFO_API == STD_ON)
    #define RM_E_PARAM_POINTER                          ((uint8)0x05U)
    #define RM_GETVERSIONINFO_ID                        ((uint8)0x01U)
#endif  /* RM_GET_VERSION_INFO_API == STD_ON */

#if (STD_ON == RM_ENABLE_XRDC)
    #define RM_E_XRDC_UNKNOWN_DOMAINID_U8               ((uint8)0x10U)

    #define RM_XRDC_GET_DOMAIN_ID_U8                    ((uint8)0x03U)
#endif
#if (STD_ON == RM_ENABLE_SEMA42)
    #define RM_E_ALREADY_LOCKED_U8                      ((uint8)0x20U)
    #define RM_E_ALREADY_UNLOCKED_U8                    ((uint8)0x21U)
    #define RM_E_LOCKED_BY_OTHER_CORE_U8                ((uint8)0x22U)
    #define RM_E_INVALID_SEMA4_CHANNEL_U8               ((uint8)0x23U)
    #define RM_E_SEMAPHORE_UNKNOWN_DOMAINID_U8          ((uint8)0x24U)
#endif
#endif  /* (RM_DEV_ERROR_DETECT == STD_ON) */

#if (RM_ENABLE_SEMA42 == STD_ON)
#define RM_LOCK_ID_U8                     ((uint8)0x04U)

#define RM_UNLOCK_ID_U8                   ((uint8)0x05U)

#define RM_GET_GATE_ID_U8                 ((uint8)0x08U)

#define RM_RESET_GATE_ID_U8               ((uint8)0x06U)

#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief          This function initializes the RM hardware components.
 * @details        This service is a non reentrant function used for driver initialization.
 *        The  Initialization function  shall initialize  all relevant  registers of  the configured
 *        hardware with the  values of the  structure referenced by  the parameter ConfigPtr.
 *        If  the  hardware  allows  for   only  one  usage   of  the  register,   the  driver module
 *        implementing that functionality is responsible for initializing the register.
 *        The initialization function of this module shall always have a pointer as a parameter, even
 *        though for Variant PC no configuration set shall be given.
 *        Instead a NULL pointer shall be passed to the initialization function.
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 *
 * @return             void
 * @api
 *
 *
 */
void Rm_Init(Rm_ConfigType const * ConfigPtr);

#if (RM_ENABLE_XRDC == STD_ON)
 
/**
* @brief        Write process ID for specific master core
* @details
*
* @param[in]    MasterCore                Master core instance
* @param[in]    u8PID                    Processor ID
* @param[in]    SecureAttr              XRDC_SECURE
*                                        XRDC_NON_SECURE
*
* @param[out]   none
*
* @return       none
*
* @api
*
*/
void Rm_XrdcSetProcessID(Rm_XrdcMasterCoreType MasterCore,
                         uint8 u8PID,
                         Rm_XrdcSecureAttributeType SecureAttr
                        );

/**
* @brief        Retrieves current domain ID
* @details
*
* @param[in]       u32Instance          XRDC instance
*
* @param[out]   none
*
* @return       Rm_DomainIdType     Domain ID
*
* @api
*
*/
Rm_DomainIdType Rm_XrdcGetDomainID(uint32 u32Instance);

/**
 * @brief          Retrieve domain ID error list
 * @details
 *
 * @param[in]       u32Instance                       XRDC instance
 * @param[in]       pXrdcDomainIDErrorStatus         uint32 DomainIDAccessError
 *                                                   Xrdc_Ip_ErrorStatusType ErrorStatus[20]
 * @param[out]      none
 *
 * @return          none
 *
 * @api
 */
void Rm_XrdcGetDomainIDErrorStatus(uint32 u32Instance,
                                   Rm_XrdcDomainIDErrStatusType *pXrdcDomainIDErrorStatus
                                  );

/**
 * @brief          Initialize XRDC instance
 * @details
 *
 * @param[in]       uint32 pXrdcInstanceConfig                                      - XRDC instance configuration
 * @param[out]      none
 *
 * @return          none
 *
 * @api
 */
/* @implements         Rm_XrdcInstanceInit */
void Rm_XrdcInstanceInit(Rm_XrdcInstanceConfigType const * pXrdcInstanceConfig);

#endif

#if (STD_ON == RM_ENABLE_SEMA42)

/**
* @brief        Rm_SemaphoreGetStatus
* @details      This function returns the status of the selected Semaphore.
*               The return is either the number of the core that keeps it locked,
*               or RM_SEMAPHORE_FREE (255) if the Semaphore is free
*
* @param[in]    ChannelNumber   Semaphore channel
*
* @retval       Returns the number of the domain ID if the semaphore is locked
*               and RM_SEMAPHORE_FREE (255)
*
*/
Rm_DomainIdType Rm_SemaphoreGetStatus(Rm_Sema42_ChannelType ChannelNumber);

/**
* @brief        Rm_SemaphoreLockGate
* @details      This function locks a Semaphore from a given core, in order to guard
*               a critical section
*
* @param[in]    ChannelNumber   Semaphore channel
*
* @return       Std_ReturnType
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*/
Std_ReturnType Rm_SemaphoreLockGate(Rm_Sema42_ChannelType ChannelNumber);

/**
* @brief        Rm_SemaphoreUnlockGate
* @details      This function unlocks a Semaphore from a given core, in order to mark the end of
*               a critical section
*
* @param[in]    ChannelNumber   Semaphore channel
*
* @return       Std_ReturnType
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
*/
Std_ReturnType Rm_SemaphoreUnlockGate(Rm_Sema42_ChannelType ChannelNumber);

/**
* @brief        Rm_SemaphoreResetGate
* @details      This function Resets the status of all Semaphores configured by the RM driver
*               The API is not part of the standard semaphore usage, it should only
*               be used in case of faults in the hardware or a deadlock.
*
* @param[in]    ChannelNumber   Semaphore channel
*
*/
void Rm_SemaphoreResetGate(Rm_Sema42_ChannelType ChannelNumber);

/**
* @brief        Rm_SemaphoreResetAllGates
* @details      This function Resets the status of all Semaphores configured by the RM driver.
*               The API is not part of the standard semaphore usage, it should only
*               be used in case of faults in the hardware or a deadlock.
*
* @param[in]    NA
*
*/
void Rm_SemaphoreResetAllGates(void);

/**
* @brief        Rm_SemaphoreGetResetGateDomainId
* @details      This function get the Domain which initiated the most recent write operation on the reset register on the instance of the semaphore channel.
*
* @param[in]    ChannelNumber   Semaphore channel
*
*/
Rm_DomainIdType Rm_SemaphoreGetResetGateDomainId(Rm_Sema42_ChannelType ChannelNumber);

/**
* @brief        Rm_SemaphoreIsResetGateStateIdle
* @details      This function check if the current state of the reset gate state machine is idle on the instance of the semaphore channel.
*
* @param[in]    ChannelNumber   Semaphore channel
* @return       boolean
* @retval       TRUE        if the reset gate is idle
* @retval       FALSE       if the reset gate is waiting for the second write or if it is actively resseting a gate
*
*/
boolean Rm_SemaphoreIsResetGateStateIdle(Rm_Sema42_ChannelType ChannelNumber);

/**
* @brief        Rm_SemaphoreGetResetedGate
* @details      This function get the logical channel which targetted by the most recent reset attempt on the instance of a semaphore channel.
*
* @param[in]    ChannelNumber   Semaphore channel
* @return       Rm_Sema42_ChannelType
* @retval       Logical semaphore channel.
*
*/
Rm_Sema42_ChannelType Rm_SemaphoreGetResetedGate(Rm_Sema42_ChannelType ChannelNumber);

#endif /* #if (STD_ON == RM_ENABLE_SEMA42)  */

#if (RM_ENABLE_MPU_M7 == STD_ON)
/**
* @brief         Configures the region selected by u8RegionNum with the data from pUserConfigPtr
*
* @details       This function is Reentrant
*
* @param[in]     u8RegionNum:    region number
* @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU M7.
* @return        void
*
* @api
*
* @pre
*
* */
void Rm_Mpu_M7_SetRegionConfig(uint8 u8RegionNum, const Rm_Mpu_M7_RegionConfigType * const pUserConfigPtr);

/**
 * @brief         Enables or disabled a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum       Region to be modified
 * @param[in]     bEnable           Specifies whether the region is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Rm_Mpu_M7_EnableRegion(uint8 u8RegionNum, boolean bEnable);

/**
 * @brief         Modify the access rights for a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum      Region to be modified
 * @param[in]     eRights          Specifies the new access rights
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Rm_Mpu_M7_SetAccessRight(uint8 u8RegionNum, Rm_Mpu_M7_AccessRightsType eRights);

/**
 * @brief         Retrieve error details
 *
 * @details       This function is Reentrant
 *
 * @param[out]    pErrorDetails : Storage where the data will be saved
 *
 * @return        Std_ReturnType
 * @retval        E_OK                    if an error was present
 * @retval        E_NOT_OK                otherwise
 * @api
 *
 * @pre
 *
 * */
Std_ReturnType Rm_Mpu_M7_GetErrorDetails(Rm_Mpu_M7_ErrorDetailsType * pErrorDetails);

#if (RM_MPU_M7_MULTICORE_SUPPORT == STD_ON)
/**
 * @brief         Disables the module and resets all region configurations
 *
 * @details       This function is Reentrant
 *
 * @return        void
 *
 * @api
 *
 * @pre
 * */
void Rm_Mpu_M7_MulticoreInit(void);
#endif /* RM_MPU_M7_MULTICORE_SUPPORT == STD_ON */
#endif /* #if (STD_ON == RM_ENABLE_MPU_M7) */





#if (RM_GET_VERSION_INFO_API == STD_ON)
/**
 * @brief   This service returns the version information of this module.
 * @details This  service is Non reentrant and returns the version information of this module.
 *          The version information includes:
 *          - Module Id
 *          - Vendor Id
 *          - Vendor specific version numbers
 *          If source code for caller and callee of this function is available this function should
 *          be realized as a macro. The macro should be defined in the modules header file.
 *
 * @param[out]    versioninfo      Pointer to location to store version info
 *
 * @return void
 *
 * @api
 *
 * */
void Rm_GetVersionInfo(Std_VersionInfoType  * versioninfo);
#endif  /* RM_GET_VERSION_INFO_API == STD_ON */

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* RM_H */
