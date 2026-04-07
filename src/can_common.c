/*==================================================================================================
*
* Copyright 2018-2024 NXP  
*
* NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms.
* By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
* the software, you are agreeing that you have read, and that you agree to comply with and are bound
* by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
* may not retain, install, activate or otherwise use the software.
==================================================================================================*/


#ifndef ASR_NOT_USED
    #include "stubs.h"
    #include "Can_43_LLCE.h"
#endif

#include "can_common.h"


#ifdef __cplusplus
extern "C"
{
#endif

volatile uint8 fail = OFF;

#if CAN_43_LLCE_MAX_PARTITIONS == 1U
    volatile uint32 last_RxIndication;
    volatile uint32 last_TxConfirmation;
#else
    volatile uint32 last_RxIndication[MAX_NUM_OF_CORES];
    volatile uint32 last_TxConfirmation[MAX_NUM_OF_CORES];
#endif

/* Circular permutation on data buffer. The reason of using this function is for checking data sent is the same with data received every time.  */
void Circular_Permutation(volatile uint8 *Payload, uint8 n)
{
    uint8 temp = Payload[0];

    for (uint8 Idx = 0; Idx < n - 1; Idx++)
    {
        Payload[Idx] = Payload[Idx + 1];
    }

    Payload[n - 1] = temp;
}

StatusType Check_Status(Can_PduType *CanMessage)
{
    uint32 can_counter = 0;
    uint8 u8Idx = 0;
    StatusType transmission_status = E_OK;

#if CAN_43_LLCE_MAX_PARTITIONS != 1U    
    uint32 u32CoreId = OsIf_GetCoreID();
#endif

    /* Wait for transmission and reception */
#if CAN_43_LLCE_MAX_PARTITIONS == 1U    
    while ( (( (Can_TxConfirmation - last_TxConfirmation) < 1) || ( (Can_RxIndication - last_RxIndication) < 1))  && (can_counter < TP_TIMEOUT) )
#else
    while ( (( (Can_TxConfirmation[u32CoreId] - last_TxConfirmation[u32CoreId]) < 1) || ( (Can_RxIndication[u32CoreId] - last_RxIndication[u32CoreId]) < 1))  && (can_counter < TP_TIMEOUT) )
#endif
    {
        can_counter++;
    }

    /* Check received Data length */
    if (Can_RxDlc != CanMessage->length)
    {
        transmission_status = E_NOT_OK;
    }

    /* Check integrity of received Data content */
    for (u8Idx = 0; u8Idx < CanMessage->length; u8Idx++)
    {
        if (Can_RxData[u8Idx] != CanMessage->sdu[u8Idx])
        {
            transmission_status = E_NOT_OK;
            break;
        }
    }

#if CAN_43_LLCE_MAX_PARTITIONS == 1U    
    last_RxIndication++;
    last_TxConfirmation++;
#else
    last_RxIndication[u32CoreId]++;
    last_TxConfirmation[u32CoreId]++;
#endif

    /* Shuffle the data in order to check sending/receiving of another frame */
    Circular_Permutation(CanMessage->sdu, CAN_FD_FRAME_LEN);

    return transmission_status;
}

