/**
*   @file    Can_Irq.c
*   @implements Can_Irq.c_Artifact
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Interrupt routines for Can driver.
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

/*
(CAN035) The module Can_Irq.c contains the implementation of interrupt frames.The implementation of the interrupt service routine shall be in Can_43_LLCE.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Can_Irq.c
*/
#include "Can_43_LLCE.h"
#include "Can_43_LLCE_IPW.h"
#include "CanIf_Can.h"
#include "Mcal.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* The integration of incompatible files shall be avoided. */
#define CAN_IPW_VENDOR_ID_C                    43
#define CAN_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define CAN_IPW_AR_RELEASE_MINOR_VERSION_C     4
#define CAN_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define CAN_SW_MAJOR_VERSION_IPW_C             1
#define CAN_SW_MINOR_VERSION_IPW_C             0
#define CAN_SW_PATCH_VERSION_IPW_C             11



/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and CAN header file are of the same vendor */
#if (CAN_IPW_VENDOR_ID_C != CAN_IPW_VENDOR_ID_H)
    #error "Can_IPW.c and Can_IPW.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_C    != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_MINOR_VERSION_C    != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_REVISION_VERSION_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_IPW.c and Can_IPW.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_IPW_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_IPW_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_IPW_C != CAN_IPW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_IPW.c and Can_IPW.h are different"
#endif


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


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

Can_43_LLCE_ControllerBaudRate   Can_43_LLCE_ControllerBaudRateIndexes[CAN_43_LLCE_MAXCTRL_CONFIGURED];

#define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
Llce_Fw_ReturnType Can_43_LLCE_IPW_Init(const Can_43_LLCE_ConfigType * pxCurrentConfig)
{
    for (uint8 u8CtrlIndex = 0U; u8CtrlIndex < CAN_43_LLCE_MAXCTRL_CONFIGURED; u8CtrlIndex++)
    {
      #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
      if(Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[u8CtrlIndex].u32CoreId == Can_43_LLCE_GetCoreID())
      {
      #endif
        /* Set the controller current baudrate index as default */
        Can_43_LLCE_ControllerBaudRateIndexes[u8CtrlIndex].u8CurrentBaudRateIndex = (uint8)(pxCurrentConfig->aControllerDescriptors[u8CtrlIndex].u8DefaultBaudRateIndex);
      #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
      }
      #endif
    }

    return Can_Llce_Init(pxCurrentConfig);
}

Std_ReturnType Can_43_LLCE_IPW_Write (Can_HwHandleType Hth, const Can_PduType * PduInfo, PduInfoType PduInfoTriggerTransmit)
{
    uint8 u8HwCtrl = 0U;
    uint8 u8CtrlId = 0U;
    uint8 u8BaudrateIndex = 0U;
    const Can_43_LLCE_ControllerDescriptorType * pxCanControllerDescriptor;
    Can_43_LLCE_TxFrameInfoType TxFrameInfo;
    const Can_43_LLCE_HOHType * pxHth;
    const Can_43_LLCE_ConfigType* pxCurrentConfig = Can_43_LLCE_GetCurrentConfig();

    pxHth = &(pxCurrentConfig->aHohList[Hth]);
    u8CtrlId = pxHth->u8ControllerId;

    pxCanControllerDescriptor = &(pxCurrentConfig->aControllerDescriptors[u8CtrlId]);

    u8HwCtrl = pxCanControllerDescriptor->u8HwCtrl;

    /* Get the index of the current baud rate */
    u8BaudrateIndex = Can_43_LLCE_ControllerBaudRateIndexes[u8CtrlId].u8CurrentBaudRateIndex;

    /* Get the status of the FD feature */
    TxFrameInfo.bFdEnabled = (pxCanControllerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].baudrateConfig.ControllerFD.u8FdEnable != 0U);

    TxFrameInfo.u8FdPaddingValue = pxHth->u8FdPaddingValue;

    TxFrameInfo.u16FrameTag2 = PduInfo->swPduHandle;
    TxFrameInfo.u16FrameTag1 = Hth;
    TxFrameInfo.u8AckInterface = pxHth->u8RWInterface;
    TxFrameInfo.bEnableTxFrameMac = pxHth->bEnableTxFrameMac;
    TxFrameInfo.u32TxHseKeyHandle = pxHth->u32TxHseKeyHandle;
    TxFrameInfo.u32MessageId = (uint32)PduInfo->id;
    TxFrameInfo.u32SduLength = PduInfoTriggerTransmit.SduLength;
    TxFrameInfo.u8SduDataPtr = (uint8*)PduInfoTriggerTransmit.SduDataPtr;

    return Can_Llce_Write(u8HwCtrl, &TxFrameInfo);
}

Std_ReturnType Can_43_LLCE_IPW_GetControllerMode(uint8 Controller, Can_ControllerStateType* ControllerModePtr)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    return Can_Llce_GetControllerMode(u8HwCtrl, ControllerModePtr);
}

Std_ReturnType Can_43_LLCE_IPW_SetControllerMode( uint8 Controller, Can_ControllerStateType Transition)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;
    uint8 u8BaudrateIndex = Can_43_LLCE_ControllerBaudRateIndexes[Controller].u8CurrentBaudRateIndex;
    const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr = &(Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].pControllerBaudrateConfigsPtr[u8BaudrateIndex].baudrateConfig);

    return Can_Llce_SetControllerMode(u8HwCtrl, Transition, pxBaudrateConfigPtr);
}

void Can_43_LLCE_IPW_DisableControllerInterrupts(uint8 Controller)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    Can_Llce_DisableControllerInterrupts(u8HwCtrl);
}

void Can_43_LLCE_IPW_EnableControllerInterrupts(uint8 Controller)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    Can_Llce_EnableControllerInterrupts(u8HwCtrl);
}

Std_ReturnType Can_43_LLCE_IPW_GetControllerStatus(uint8 Controller, Llce_Can_GetStatusCmdType* StatusPtr)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    return Can_Llce_GetControllerStatus(u8HwCtrl, StatusPtr);
}

Std_ReturnType Can_43_LLCE_IPW_ChangeBaudrate(uint8 Controller, uint8 u8BaudrateIndex)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;
    const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr = &(Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].pControllerBaudrateConfigsPtr[u8BaudrateIndex].baudrateConfig);

    return Can_Llce_ChangeBaudrate(u8HwCtrl, pxBaudrateConfigPtr);
}

void Can_43_LLCE_IPW_MainFunctionMode(uint8 Controller)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    Can_Llce_MainFunctionMode(u8HwCtrl);
}

Std_ReturnType Can_43_LLCE_IPW_GetControllerErrorState(uint8 Controller,Can_ErrorStateType* ErrorStatePtr)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    return Can_Llce_GetControllerErrorState(u8HwCtrl, ErrorStatePtr);
}

Std_ReturnType Can_43_LLCE_IPW_GetControllerRxErrorCounter(uint8 Controller, uint8* RxErrorCounterPtr)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    return Can_Llce_GetControllerRxErrorCounter(u8HwCtrl, RxErrorCounterPtr);
}

Std_ReturnType Can_43_LLCE_IPW_GetControllerTxErrorCounter(uint8 Controller, uint8* TxErrorCounterPtr)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    return Can_Llce_GetControllerTxErrorCounter(u8HwCtrl, TxErrorCounterPtr);
}

Std_ReturnType Can_43_LLCE_IPW_DeInitController(uint8 Controller)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    return Can_Llce_DeInitController(u8HwCtrl);
}

Std_ReturnType Can_43_LLCE_IPW_SetChannelRoutingOutputState(uint8 ControllerId, Can_43_LLCE_ChannelStateType eChannelStatus)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[ControllerId].u8HwCtrl;

    return Can_Llce_SetChannelRoutingOutputState(u8HwCtrl, eChannelStatus);
}
#if (CAN_43_LLCE_API_MANUAL_BUSOFF_RECOVERY == STD_ON)

Std_ReturnType Can_43_LLCE_Ipw_ManualBusOffRecovery(uint8 ControllerId)
{
    /* Get hardware controller based on logical controller index */
    uint8 u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[ControllerId].u8HwCtrl;
    
    return Can_Llce_ManualBusOffRecovery(u8HwCtrl);
}

#endif

/*================================================================================================*/


#define CAN_43_LLCE_START_SEC_CODE
#include "Can_43_LLCE_MemMap.h"




#define CAN_43_LLCE_STOP_SEC_CODE
#include "Can_43_LLCE_MemMap.h"
#ifdef __cplusplus
}
#endif
/** @} */
