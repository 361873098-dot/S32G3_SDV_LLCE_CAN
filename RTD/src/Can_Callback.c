/**
*   @file    Can_Callback.c
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
#include "Can_Callback.h"


#if (STD_ON == AUTOSAR_COMPATIBLE_MODE)
    #include "Det.h"
    #include "Can_43_LLCE.h"
    #include "SchM_Can_43_LLCE.h"
#endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */

#if (STD_ON == AUTOSAR_COMPATIBLE_MODE)
/**
* @brief          Implements wrapper for error report 
* @details        This routine is called by all APIs that change controller state, e.g. Can_Llce_SetControllerToStopMode:
*
* @param[in]      sid             Controller mode
*                 eTransition     Controller transition state
*
* @return         void
*
*
* @pre            The AUTOSAR_COMPATIBLE_MODE define is set to STD_ON for code generated with Tresos.
*
*/
void Can_43_LLCE_ReportError(uint8 sid , uint8 eTransition)
{
    /*In ASR context, report error through Det module - not available in non-ASR DesignStudio*/
    #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        if(((uint8)CAN_43_LLCE_E_DATALOST) != eTransition)
        {   
            (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, sid, eTransition);
        }
    #else
        /* To avoid MISRA and compilation warnings */
        (void)sid;
        (void)eTransition;
    #endif
}
#else /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
void Can_43_LLCE_ReportError(uint8 sid , uint8 eTransition)
{
    /* Call custom configurable callback in NON-AUTOSAR MODE*/
    Can_43_LLCE_DevErrorDetectCallback(sid, eTransition);
}
#endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */

#if (STD_ON == AUTOSAR_COMPATIBLE_MODE)
/**
* @brief          Implements wrapper for runtime error report 
* @details        This routine is called by Can_Llce_ProcessNotificationISR in case of overwrite or overrun
*
* @param[in]      sid             Controller mode
*                 eTransition     Controller transition state
*
* @return         void
*
*
*/
void Can_43_LLCE_ReportRuntimeError(uint8 sid , uint8 eTransition)
{
    /*In ASR context, report error through Det module - not available in non-ASR DesignStudio*/
    (void)Det_ReportRuntimeError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, sid, eTransition);
}
#else /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
void Can_43_LLCE_ReportRuntimeError(uint8 sid , uint8 eTransition)
{
    /* Call custom configurable callback in NON-AUTOSAR MODE*/
    Can_43_LLCE_DevErrorDetectCallback(sid, eTransition);
}
#endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */


#if (STD_ON == AUTOSAR_COMPATIBLE_MODE)
/**
* @brief          Implements wrapper for configurable callback for controller state report to CanIf module in AUTOSAR MODE
* @details        This routine is called by all APIs that change controller state, e.g. Can_Llce_SetControllerToStopMode:
*
* @param[in]      u8HwCtrl      Controller id
*                 ctrlState     Controller transition state
*
* @return         void
*
*
* @pre            The AUTOSAR_COMPATIBLE_MODE define is set to STD_ON for code generated with Tresos.
*
*/
void Can_43_LLCE_ControllerModeIndication(uint8 u8HwCtrl, Can_ControllerStateType ctrlState)
{
    /* In ASR context, make call to CanIf - not available in non-ASR DesignStudio */
    CanIf_ControllerModeIndication(Can_43_LLCE_GetCurrentConfig()->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId, ctrlState);
}
#else /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
void Can_43_LLCE_ControllerModeIndication(uint8 u8HwCtrl, Can_ControllerStateType ctrlState)
{
    /* Call custom configurable callback for controller state report in NON-AUTOSAR MODE */
    Can_43_LLCE_ControllerModeIndicationCallback(u8HwCtrl, ctrlState);
}
#endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */

#if (STD_ON == AUTOSAR_COMPATIBLE_MODE)
/**
* @brief          Implements wrapper for confirmation callback reporting to CanIf in AUTOSAR MODE
* @details        This routine is called by:
*                - Can_Llce_ProcessTxPollingClass and Can_Llce_ProcessTx
*
* @param[in]      tag             Frame tag
*
* @return         void
*
*
* @pre            The AUTOSAR_COMPATIBLE_MODE define is set to STD_ON for code generated with Tresos.
*
*/
void Can_43_LLCE_TxConfirmation(uint16 tag)
{
    /*In ASR context, make call to CanIf - not available in non-ASR DesignStudio*/
    CanIf_TxConfirmation(tag);
}
#else /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
void Can_43_LLCE_TxConfirmation(uint16 tag)
{
    /* Call custom confirmation callback in NON-AUTOSAR MODE */
    Can_43_LLCE_TxConfirmationCallback(tag);
}
#endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */

#if (STD_ON == AUTOSAR_COMPATIBLE_MODE)
/**
* @brief          Implements wrapper for BusOff callback report to CanIf in AUTOSAR MODE
* @details        This routine is called by:
*                - Can_Llce_ControllerBusOff
*
* @param[in]      u8HwCtrl             controller id
*
* @return         void
*
*
* @pre            The AUTOSAR_COMPATIBLE_MODE define is set to STD_ON for code generated with Tresos.
*/
void Can_43_LLCE_ControllerBusOff(uint8 u8HwCtrl)
{
    /* Inform CanIf about BusOff event */
    CanIf_ControllerBusOff(Can_43_LLCE_GetCurrentConfig()->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId);
}
#else /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
void Can_43_LLCE_ControllerBusOff(uint8 u8HwCtrl)
{
    /* Call custom BusOff callback in NON-AUTOSAR MODE */
    Can_43_LLCE_ControllerBusOffCallback(u8HwCtrl);
}
#endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */


/* Wrapper for configurable callback in non-Autosar context, and CanIf callback in Autosar context. */
void Can_43_LLCE_RxIndication(uint32 u32MbMessageId, uint16 u16FilterId, uint8* u8FramePayload, uint8 u8MbDataLength)
{
    uint8 Controller;
    /* Used to store the FD feature enable or disable. */
    boolean bFdEnable;  
    /* Variable to hold the index of the current baudrate */
    uint8 u8BaudrateIndex;
    uint8 u8MbDataLengthCopy;
    uint8 u8HwCtrl;

    /* comply with misra Rule 17.8 A function parameter should not be modified */
    u8MbDataLengthCopy = u8MbDataLength;
    /* Identify the corresponding controller */
    Controller = Can_43_LLCE_GetCurrentConfig()->aHohList[u16FilterId].u8ControllerId;

    /* Get the hardware offset for this controller. */
    u8HwCtrl = Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8HwCtrl;

    u8BaudrateIndex = Can_43_LLCE_ControllerBaudRateIndexes[Controller].u8CurrentBaudRateIndex;
    bFdEnable = (Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].pControllerBaudrateConfigsPtr[u8BaudrateIndex].baudrateConfig.ControllerFD.u8FdEnable > 0U);

    /* Check if the length parameter is bigger than the maximum accepted value defined by the configuration. */
    if ( (bFdEnable == FALSE) && (u8MbDataLengthCopy > (uint8)8U) )
    {
        /* Shrink the length parameter according to the configuration. This prevents a buffer overflow generated by a CAN bus error affecting length field. */
        u8MbDataLengthCopy = (uint8)8U;
    }
    else if ( (bFdEnable == TRUE) && (u8MbDataLengthCopy > (uint8)64U) )
    {
        u8MbDataLengthCopy = (uint8)64U;
    }
    else if (( (u32MbMessageId & (uint32)CAN_LPDU_FD_U32) != CAN_LPDU_FD_U32) && ( u8MbDataLengthCopy > (uint8)8U ))
    {
        u8MbDataLengthCopy = (uint8)8U;
    }
    else
    {
        /* Length ok. */
    }

    #if (STD_ON == AUTOSAR_COMPATIBLE_MODE)
        /* Identifies the HRH and its corresponding CAN Controller. */
        Can_HwType Mailbox;
        /* Pointer to the received L-PDU. */
        PduInfoType PduInfo;

        /* Standard/Extended CAN ID of CAN L-PDU */
        Mailbox.CanId = u32MbMessageId;       
        
        /* ID of the corresponding Hardware Object Range */
        Mailbox.Hoh = u16FilterId;

        Mailbox.ControllerId = Can_43_LLCE_GetCurrentConfig()->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId;

        /* length of the SDU in bytes */
        PduInfo.SduLength = u8MbDataLengthCopy;
        
        /* pointer to the SDU (i.e. payload data) of the PDU */
        PduInfo.SduDataPtr = u8FramePayload;

        CanIf_RxIndication(&Mailbox, &PduInfo );
    #else /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
        Can_43_LLCE_RxIndicationCallback(u8HwCtrl, u16FilterId, u8FramePayload, u8MbDataLengthCopy);
    #endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
}

void Can_Hth_FreeTxObject(uint16 Hth, uint8 freeObjCount)
{
    #if (STD_ON == AUTOSAR_COMPATIBLE_MODE)

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_02();

    /* Increase the number of free Tx objects for the current HTH */
    Can_au16TransmitHwObjectCnt[Hth - CAN_43_LLCE_FIRST_HTH_CONFIGURED] += freeObjCount;
    
    if ( Can_au16TransmitHwObjectCnt[Hth - CAN_43_LLCE_FIRST_HTH_CONFIGURED] > Can_43_LLCE_GetCurrentConfig()->aHohList[Hth].u16MbCount )
    {
        Can_au16TransmitHwObjectCnt[Hth - CAN_43_LLCE_FIRST_HTH_CONFIGURED] = Can_43_LLCE_GetCurrentConfig()->aHohList[Hth].u16MbCount;
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_02();

    #endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
}


