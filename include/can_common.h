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

#ifndef CAN_COMMON
#define CAN_COMMON

#ifdef ASR_NOT_USED
    #include "PlatformTypes.h"    
#endif

#define CAN_FD_FRAME_LEN 64U
#define CAN_STD_FRAME_LEN 8U
#define TP_TIMEOUT 800000U
#define CONTROLLER1 1
#define CONTROLLER0 0
#define CONTROLLER2 2
#define CONTROLLER3 3
#define CONTROLLER4 4
#define CONTROLLER5 5
#define CONTROLLER7 7
#define CONTROLLER10 10
#define CONTROLLER11 11
#define CONTROLLER12 12
#define CONTROLLER14 14
#define CONTROLLER15 15
#define ITER_NR 200
#define MAX_BUFFER_FRAME_FD 64
#define CAN_LPDU_FD_U32 ((uint32)0x40000000)
#define MAX_NUM_OF_CORES 8U
#define ON  1
#define OFF 0

/* Sample app specific variable. Possible values: ON, OFF */
extern volatile uint8 fail;

#if CAN_43_LLCE_MAX_PARTITIONS == 1U
    extern volatile uint32 last_RxIndication;
    extern volatile uint32 last_TxConfirmation;
#else
    extern volatile uint32 last_RxIndication[MAX_NUM_OF_CORES];
    extern volatile uint32 last_TxConfirmation[MAX_NUM_OF_CORES];
#endif

void Circular_Permutation(volatile uint8 *Payload, uint8 n);
StatusType Check_Status(Can_PduType *CanMessage);


#endif  /* CAN_COMMON */
