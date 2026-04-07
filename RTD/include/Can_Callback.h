/**
*   @file    Can_Callback.h
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

#ifndef CAN_43_LLCE_CALLBACK_H
#define CAN_43_LLCE_CALLBACK_H

#include "Can_43_LLCE_Cfg.h"
#if (STD_ON == AUTOSAR_COMPATIBLE_MODE)
    #include "Can_43_LLCE.h"
    #include "CanIf_Can.h"

#endif /* (STD_ON == AUTOSAR_COMPATIBLE_MODE) */
#include "Reg_eSys_Llce.h"


void Can_43_LLCE_ReportError(uint8 sid , uint8 eTransition);
void Can_43_LLCE_ReportRuntimeError(uint8 sid , uint8 eTransition);
void Can_43_LLCE_TxConfirmation(uint16 tag);
void Can_43_LLCE_RxIndication(uint32 u32MbMessageId, uint16 u16FilterId, uint8* u8FramePayload, uint8 u8MbDataLength);
void Can_43_LLCE_ControllerBusOff(uint8 u8HwCtrl);
void Can_43_LLCE_ControllerModeIndication(uint8 u8HwCtrl, Can_ControllerStateType ctrlState);
void Can_Hth_FreeTxObject(uint16 Hth, uint8 freeObjCount);





#endif /* CAN_43_LLCE_CALLBACK_H */
