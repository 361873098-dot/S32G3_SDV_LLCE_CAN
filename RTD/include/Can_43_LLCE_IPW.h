/**
*   @file    Can_43_LLCE_IPW.h
*   @implements Can_IPW.h_Artifact
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Main header file - can include different IPV models.
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

#ifndef CAN_43_LLCE_IPW_H
#define CAN_43_LLCE_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_Llce.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Can_43_LLCE_IPW.h
*/
#define CAN_IPW_VENDOR_ID_H                    43
#define CAN_IPW_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_IPW_AR_RELEASE_MINOR_VERSION_H     4
#define CAN_IPW_AR_RELEASE_REVISION_VERSION_H  0
#define CAN_IPW_SW_MAJOR_VERSION_H             1
#define CAN_IPW_SW_MINOR_VERSION_H             0
#define CAN_IPW_SW_PATCH_VERSION_H             11
/**@}*/


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
    #define     CAN_43_LLCE_NULL_OFFSET      (LLCE_NULL_OFFSET_U8)

    #define         Can_43_LLCE_IPW_DeInitPlatform()                                            (Can_Llce_DeInitPlatform())

Llce_Fw_ReturnType Can_43_LLCE_IPW_SetCachedCtrlState(uint8 u8HwCtrl);

#if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)
    #if (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_WRITE == STD_OFF)
        #define         Can_43_LLCE_IPW_MainFunctionWrite()                                     (Can_Llce_MainFunctionWrite())
    #else
        #define         Can_43_LLCE_IPW_MainFunctionMultipleWritePoll(writepoll)                (Can_Llce_MainFunctionMultipleWritePoll(writepoll))
    #endif
#endif
    
#if (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON)
    #if (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_READ == STD_OFF)
        #define         Can_43_LLCE_IPW_MainFunctionRead()                                      (Can_Llce_MainFunctionRead())
    #else
        #define         Can_43_LLCE_IPW_MainFunctionMultipleReadPoll(readpoll)                  (Can_Llce_MainFunctionMultipleReadPoll(readpoll))
    #endif 
#endif

#if (CAN_43_LLCE_BUSOFFPOLL_SUPPORTED == STD_ON)
    #define         Can_43_LLCE_IPW_ProcessBusOffPoll(void)                                     (Can_Llce_ProcessBusOffNotification(void))
#endif    

#if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
    #define         Can_43_LLCE_IPW_ProcessErrorNotification(void)                              (Can_Llce_ProcessErrorNotification(void))
#endif    

    #define         Can_43_LLCE_IPW_GetFwVersion(pVersionString, u8StringLength) \
                                    (Can_Llce_GetFwVersion(pVersionString, u8StringLength))
                            
    #define         Can_43_LLCE_IPW_SetFilter(pCanFilter)                                       (Can_Llce_SetFilter(pCanFilter))
    
    #define         Can_43_LLCE_IPW_SetFilterAtAddress(pCanFilter, u16FilterAddr)               (Can_Llce_SetFilterAtAddress(pCanFilter, u16FilterAddr))

    #define         Can_43_LLCE_IPW_SetAfFilterAtAddress(pAfFilter, u16FilterAddr)              (Can_Llce_SetAfFilterAtAddress(pAfFilter, u16FilterAddr))

    #define         Can_43_LLCE_IPW_SetAfFilter(pAfFilter)                                      (Can_Llce_SetAfFilter(pAfFilter))

    #define         Can_43_LLCE_IPW_CreateAfDestination(destRule, pu8RuleIdx)                   (Can_Llce_CreateAfDestination(destRule, pu8RuleIdx))

    #define         Can_43_LLCE_IPW_RemoveAfDestination(u8RuleIdx)                              (Can_Llce_RemoveAfDestination(u8RuleIdx))

    #define         Can_43_LLCE_IPW_RemoveFilter(Hrh, u16FilterAddr)                            (Can_Llce_RemoveFilter(Hrh, u16FilterAddr))

    #define         Can_43_LLCE_IPW_SetFilterState(Hrh, eState)                                 (Can_Llce_SetFilterState(Hrh, eState))

    #define         Can_43_LLCE_IPW_EnableNotifInterrupt(u8ActiveHif)                           (Can_Llce_EnableNotifInterrupt(u8ActiveHif))

    #define         Can_43_LLCE_IPW_Shutdown()                                                  (Can_Llce_Shutdown())

#if (CAN_43_LLCE_API_ENABLE_ABORT_MB == STD_ON)
    #define         Can_43_LLCE_Ipw_AborMb(Hth)                    (Can_Llce_AbortMb(Hth))
#endif

#if (CAN_43_LLCE_API_MANUAL_BUSOFF_RECOVERY == STD_ON)
Std_ReturnType Can_43_LLCE_Ipw_ManualBusOffRecovery(uint8 ControllerId);
#endif

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

Llce_Fw_ReturnType Can_43_LLCE_IPW_Init(const Can_43_LLCE_ConfigType * pxCurrentConfig);
Std_ReturnType Can_43_LLCE_IPW_DeInitController(uint8 Controller);
Std_ReturnType Can_43_LLCE_IPW_GetControllerMode(uint8 Controller, Can_ControllerStateType* ControllerModePtr);
Std_ReturnType Can_43_LLCE_IPW_SetControllerMode( uint8 Controller, Can_ControllerStateType Transition);
Std_ReturnType Can_43_LLCE_IPW_GetControllerStatus(uint8 Controller, Llce_Can_GetStatusCmdType* StatusPtr);
Std_ReturnType Can_43_LLCE_IPW_GetControllerErrorState(uint8 Controller,Can_ErrorStateType* ErrorStatePtr);
Std_ReturnType Can_43_LLCE_IPW_GetControllerRxErrorCounter(uint8 Controller, uint8* RxErrorCounterPtr);
Std_ReturnType Can_43_LLCE_IPW_GetControllerTxErrorCounter(uint8 Controller, uint8* TxErrorCounterPtr);
Std_ReturnType Can_43_LLCE_IPW_Write (Can_HwHandleType Hth, const Can_PduType * PduInfo, PduInfoType PduInfoTriggerTransmit);
Std_ReturnType Can_43_LLCE_IPW_ChangeBaudrate(uint8 Controller, uint8 u8BaudrateIndex);
Std_ReturnType Can_43_LLCE_IPW_SetChannelRoutingOutputState(uint8 ControllerId, Can_43_LLCE_ChannelStateType eChannelStatus);
void Can_43_LLCE_IPW_DisableControllerInterrupts(uint8 Controller);
void Can_43_LLCE_IPW_EnableControllerInterrupts(uint8 Controller);
void Can_43_LLCE_IPW_MainFunctionMode(uint8 Controller);

#ifdef __cplusplus
}
#endif

#endif /* CAN_43_LLCE_IPW_H */

/** @} */
