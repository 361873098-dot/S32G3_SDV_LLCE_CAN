/**
*   @file    Can_Llce.h
*   @implements Can_Llce.h_Artifact
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - LLD module interface.
*   @details Low Level Driver header file for IPV = Llce.
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



#ifndef CAN_LLCE_H
#define CAN_LLCE_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*  (CAN222) Imported types: Dem_Types.h, CanIf_Types.h, Std_Types.h, ComStackTypes.h */
/*
* @file           Can_Llce.h
*/


#include "Llce_RegAccess.h"
#include "Reg_eSys_Llce.h"
#include "Can_GeneralTypes.h"
#include "ComStackTypes.h"
#include "CanIf_Can.h"
#include "Mcal.h"
#include "Can_43_LLCE.h"
#include "Can_43_LLCE_AFcfg.h"
#include "Llce_InterfaceCanTypes.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Can_Llce.h
*/
#define CAN_LLCE_VENDOR_ID_H                    43
#define CAN_LLCE_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_LLCE_AR_RELEASE_MINOR_VERSION_H     4
#define CAN_LLCE_AR_RELEASE_REVISION_VERSION_H  0
#define CAN_LLCE_SW_MAJOR_VERSION_H             1
#define CAN_LLCE_SW_MINOR_VERSION_H             0
#define CAN_LLCE_SW_PATCH_VERSION_H             11

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** @brief   STM timer used for performance measurements. */
#ifdef CAN_43_LLCE_STM_MEASUREMENT_ENABLE
    #define LLCE_STM_BASEADDR          ((uint32)0x43C1A000UL)
    #define LLCE_STM_CR                 (LLCE_STM_BASEADDR)
    #define LLCE_STM_CNT                (LLCE_STM_BASEADDR + 4 )
#endif

#if (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U)
#define CAN_LLCE_FILTER_DEFAULT_EMPTY_ADDRESS_U16   ((uint16)0xFFFF)
#endif

#define LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32   ((uint32)0x00000200U) /**< @brief   Enable interrupt on receive.*/
#define LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32   ((uint32)0x00000100U) /**< @brief   Enable interrupt on transmit.*/
#define LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32   ((uint32)0x00001000U) /**< @brief   Enable interrupt mode for Bus off.*/
#define LLCE_CAN_REFERENCE_NOT_USED              ((uint8)0xFFU)  /**< @brief   R/W period reference not used */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
* @brief          CAN Interrupts state.
* @details        CAN Interrupts state.
*
*/
typedef enum
{
    CAN_INTERRUPT_DISABLED = 0U,  /*< @brief Interrupts disabled */
    CAN_INTERRUPT_ENABLED         /*< @brief Interrupts enabled */
} Can_InterruptStateType;

#if(LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0)
/**
* @brief          Can2Eth state type
*
*/
typedef enum
{
    CAN_LLCE_CAN2ETH_DISABLED = 0U,
    CAN_LLCE_CAN2ETH_ENABLED
} Can_Llce_Can2EthStateType;
#endif

#if(LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON)
/**
* @brief          Eth2Can state type
*
*/
typedef enum
{
    CAN_LLCE_ETH2CAN_DISABLED = 0U,
    CAN_LLCE_ETH2CAN_ENABLED
} Can_Llce_Eth2CanStateType;
#endif

#if LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0
/**
* @brief          Can2Pcie state type
*
*/
typedef enum
{
    CAN_LLCE_CAN2PCIE_DISABLED = 0U,
    CAN_LLCE_CAN2PCIE_ENABLED
} Can_Llce_Can2PcieStateType;
#endif
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
    
/**
* @brief          Records the status of a CAN Controller during runtime.
* @details        Records the status of a CAN Controller during runtime.
*
* @note           This structure is not configured by Tresos.
*/
typedef struct
    {
        uint8 u8IntDisableLevel; /*< @brief Storage space for Can_43_LLCE_DisableControllerInterrupts nesting level */
        
        Can_InterruptStateType eInterruptMode; /*< @brief Global interrupt authorization state */
        
        Can_ControllerStateType eCachedControllerState; /*< @brief Local copy of controller state */

        Can_InterruptStateType eSetIntEnRequest;   /*< @brief Interrupt Enable Request for given controller */

    } Can_43_LLCE_ControllerStatusType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                           MACROS
=====================================================================================================*/
    
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_CODE

#include "Can_43_LLCE_MemMap.h"

Llce_Fw_ReturnType Can_Llce_Init( const Can_43_LLCE_ConfigType * pxCurrentConfig);

#if((LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON))
Std_ReturnType Can_Llce_Init_PfeIf( uint8 Hif);
Std_ReturnType Can_Llce_Start_PfeIf(void);
#endif

#if(LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0)
Std_ReturnType Can_Llce_SetCan2EthState(Can_Llce_Can2EthStateType eState);
#endif

#if (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON)
Llce_Fw_ReturnType Can_Llce_SetEth2CanFormatState(Llce_Can_EthEncapsulationFormat eFormat, Can_Llce_Eth2CanStateType eState);
#endif 

#if LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0
Std_ReturnType Can_Llce_SetCan2PcieState(Can_Llce_Can2PcieStateType eState);
#endif

Std_ReturnType Can_Llce_DeInitController(uint8 u8HwCtrl);

Std_ReturnType Can_Llce_DeInitPlatform(void);

Std_ReturnType Can_Llce_Shutdown(void);

Std_ReturnType Can_Llce_ChangeBaudrate(uint8 u8HwCtrl, const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr);

Std_ReturnType Can_Llce_GetControllerMode(uint8 u8HwCtrl, Can_ControllerStateType * ControllerModePtr);

Std_ReturnType Can_Llce_SetControllerMode(uint8 u8HwCtrl, Can_ControllerStateType Transition, const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr);

void Can_Llce_DisableControllerInterrupts(uint8 u8HwCtrl);
void Can_Llce_EnableControllerInterrupts(uint8 u8HwCtrl);

void Can_Llce_EnableNotifInterrupt(uint8 u8ActiveHif);
void Can_Llce_DisableNotifInterrupt(uint8 u8ActiveHif);

Std_ReturnType Can_Llce_Write(uint8 u8HwCtrl, Can_43_LLCE_TxFrameInfoType* TxFrameInfo);

void Can_Llce_ProcessTx(const uint8 u8AckInterface );

#if (CAN_43_LLCE_BUSOFFPOLL_SUPPORTED == STD_ON)
void Can_Llce_ProcessBusOffNotification(void);
#endif /* (CAN_43_LLCE_BUSOFFPOLL_SUPPORTED == STD_ON) */

#if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
void Can_Llce_ProcessErrorNotification(void);
#endif /* (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON) */

void Can_Llce_ProcessNotificationISR(void);

void Can_Llce_ProcessRx(const uint8 u8RxInterface);

#if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)

void Can_Llce_MainFunctionWrite(void);

void Can_Llce_MainFunctionMultipleWritePoll(uint8 writepoll);

#endif /* (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON) */

#if (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON)

void Can_Llce_MainFunctionRead(void);

void Can_Llce_MainFunctionMultipleReadPoll(uint8 readpoll);

#endif /* (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON) */

void Can_Llce_MainFunctionMode(uint8 u8HwCtrl);
Std_ReturnType Can_Llce_GetControllerErrorState(uint8 u8HwCtrl, Can_ErrorStateType * ErrorStatePtr);
Std_ReturnType Can_Llce_GetControllerRxErrorCounter(uint8 u8HwCtrl, uint8 * RxErrorCounterPtr);
Std_ReturnType Can_Llce_GetControllerTxErrorCounter(uint8 u8HwCtrl, uint8 * TxErrorCounterPtr);
Std_ReturnType Can_Llce_GetControllerStatus(uint8 u8HwCtrl, Llce_Can_GetStatusCmdType * StatusPtr);

Std_ReturnType Can_Llce_GetFwVersion(const uint8 ** pVersionString, uint8 * pStringLength);
Std_ReturnType Can_Llce_SetFilter(const Can_SetFilterType * pCanFilter);
Std_ReturnType Can_Llce_SetFilterAtAddress(const Can_SetFilterType * pCanFilter, const uint16 u16FilterAddr);
Std_ReturnType Can_Llce_SetAfFilterAtAddress(const Can_SetAfFilterType * pAfFilter, const uint16 u16FilterAddr);
Std_ReturnType Can_Llce_CreateAfDestination(Can_Af_DestRulesType destRule, uint8* pu8RuleIdx);
Std_ReturnType Can_Llce_RemoveAfDestination(uint8 u8RuleIdx);
Std_ReturnType Can_Llce_SetAfFilter(const Can_SetAfFilterType * pAfFilter);
Std_ReturnType Can_Llce_RemoveFilter(Can_HwHandleType Hrh, uint16* u16FilterAddr);
Std_ReturnType Can_Llce_SetFilterState(Can_HwHandleType Hrh, Can_43_LLCE_FilterStateType eState);
Std_ReturnType Can_Llce_SetChannelRoutingOutputState(uint8 u8HwCtrl, Can_43_LLCE_ChannelStateType eChannelStatus);

Std_ReturnType Can_Llce_ExecuteCustomCommand(const void* const argument);

#if (CAN_43_LLCE_API_ENABLE_ABORT_MB == STD_ON)
Std_ReturnType Can_Llce_AbortMb(Can_HwHandleType Hth);
#endif

#if (CAN_43_LLCE_API_MANUAL_BUSOFF_RECOVERY == STD_ON)
Std_ReturnType Can_Llce_ManualBusOffRecovery(uint8 u8HwCtrl);
#endif

#define CAN_43_LLCE_STOP_SEC_CODE

#include "Can_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CAN_LLCE_H */

/** @} */
