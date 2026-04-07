/**
*   @file    Can_Llce_Types.h
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - module interface.
*   @details API header for CAN driver.
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


#ifndef CAN_LLCE_TYPES_H
#define CAN_LLCE_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif



/**
* @file           Can_Llce_Types.h
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Can_43_LLCE_Cfg.h"
#include "Llce_InterfaceCanTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief          Development errors.
* @details        (CAN104) The Can module shall be able to detect the following errors and exceptions depending on its configuration (development/production).
*                 (CAN026) Development Errors shall indicate errors that are caused by erroneous usage of the Can module API. This covers API
*                   parameter checks and call sequence errors.
*                 (CAN080) Development error values are of type uint8.
*
*/
#if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)

    #define CAN_43_LLCE_E_PARAM_POINTER      ((uint8)0x01U)
    #define CAN_43_LLCE_E_PARAM_HANDLE       ((uint8)0x02U)
    #define CAN_43_LLCE_E_PARAM_DATA_LENGTH  ((uint8)0x03U)
    #define CAN_43_LLCE_E_PARAM_CONTROLLER   ((uint8)0x04U)
    #define CAN_43_LLCE_E_UNINIT             ((uint8)0x05U)

#endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */

#define CAN_43_LLCE_E_TRANSITION         ((uint8)0x06U)

#if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)

#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
    #define CAN_43_LLCE_E_PARAM_BAUDRATE     ((uint8)0x07U)
#endif

    #define CAN_43_LLCE_E_PARAM_CONFIG       ((uint8)0x08U)

    #define CAN_43_LLCE_E_INIT_FAILED        ((uint8)0x09U)

    #define CAN_43_LLCE_E_LLCE_FAILED        ((uint8)0x0AU) /* FIFO Interface communication failed. 1 TX token is lost. Requires controller restart. */

#endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */

/**@}*/

/**
* @{
* @brief          Runtime errors.
*
*/
#define CAN_43_LLCE_E_DATALOST           ((uint8)0x01U)

/**@}*/

/**
* @{
* @brief          Service ID (APIs) for Det reporting
*
*/
#define CAN_43_LLCE_SID_INIT                          ((uint8)0x00U)
#define CAN_43_LLCE_SID_CREATE_DESTINATION            ((uint8)0x01U)
#define CAN_43_LLCE_SID_SET_CONTROLLER_MODE           ((uint8)0x03U)

#define CAN_43_LLCE_SID_DISABLE_CONTROLLER_INTERRUPTS ((uint8)0x04U)
#define CAN_43_LLCE_SID_ENABLE_CONTROLLER_INTERRUPTS  ((uint8)0x05U)
#define CAN_43_LLCE_SID_WRITE                         ((uint8)0x06U)

#if (CAN_43_LLCE_VERSION_INFO_API == STD_ON)
#define CAN_43_LLCE_SID_GET_VERSION_INFO              ((uint8)0x07U)
#endif

#define CAN_43_LLCE_SID_CBK_CHECK_WAKEUP              ((uint8)0x0BU)

#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
#define CAN_43_LLCE_SID_SET_BAUDRATE                  ((uint8)0x0FU)
#endif

#define CAN_43_LLCE_SID_DEINIT                            ((uint8)0x10U)
#define CAN_43_LLCE_SID_GETCONTROLLERERRORSTATE           ((uint8)0x11U)
#define CAN_43_LLCE_SID_GETCONTROLLERMODE                 ((uint8)0x12U)
#define CAN_43_LLCE_SID_GET_CTRL_RX_ERROR_COUNTER         ((uint8)0x13U)
#define CAN_43_LLCE_SID_GET_CTRL_TX_ERROR_COUNTER         ((uint8)0x14U)

#define CAN_43_LLCE_SID_PROCESS_NOTIFICATION_ISR          ((uint8)0x15U)
#define CAN_43_LLCE_SID_REMOVE_DESTINATION                ((uint8)0x16U)
#define CAN_43_LLCE_SID_SET_FILTER                        ((uint8)0x17U)
#define CAN_43_LLCE_SID_REMOVE_FILTER                     ((uint8)0x18U)
#define CAN_43_LLCE_SID_SET_FILTER_ENABLE_STATE           ((uint8)0x1AU)
#define CAN_43_LLCE_SID_SETCHANNEL_ROUTING_OUTPUTSTATE    ((uint8)0x1BU)

#if (CAN_43_LLCE_API_ENABLE_ABORT_MB == STD_ON)
#define CAN_43_LLCE_SID_ABORT_LOWEST_PRIO_MB          ((uint8)0x19U)
#endif

#if (CAN_43_LLCE_API_MANUAL_BUSOFF_RECOVERY == STD_ON)
#define CAN_43_LLCE_SID_MANUAL_BUSOFF_RECOVERY        ((uint8)0x20U)
#endif


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct 
{
    uint32 u32MessageId;
    uint32 u32TxHseKeyHandle;
    uint32 u32SduLength;
    uint16 u16FrameTag1;
    uint16 u16FrameTag2;
    uint16 u16MbFrameIdx;
    uint8 u8AckInterface;
    boolean bEnableTxFrameMac;    
    boolean bFdEnabled;
    uint8 u8FdPaddingValue;
    const uint8* u8SduDataPtr;
    
}Can_43_LLCE_TxFrameInfoType;



#ifdef __cplusplus
}
#endif

#endif /* CAN_LLCE_TYPES_H */

/** @} */
