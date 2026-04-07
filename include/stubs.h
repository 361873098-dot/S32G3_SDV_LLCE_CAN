#ifndef STUBS_H
#define STUBS_H

#include "Can_43_LLCE.h"
#include "can_common.h"
#include "Platform_Types.h"

#define ASSERT(expr) \
    if (!(expr)) \
        fail = ON

/* Stub functions */
void CanIf_RxIndication( const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr );
void CanIf_TxConfirmation( PduIdType CanTxPduId);
void CanIf_ControllerModeIndication( uint8 Controller, Can_ControllerStateType ControllerMode);
void CanIf_ControllerBusOff( uint8 Controller);
void RxTimestampNotification(Can_HwHandleType Hoh, uint32 u32TimestampVal);
void TxTimestampNotification(Can_HwHandleType Hoh, PduIdType CanTxPduId, uint32 u32TimestampVal);
void CanErrorNotification(uint8 u8CanIfCtrlId, Llce_Can_NotificationIdType eNotifId, volatile Llce_Can_ErrorNotifType* ErrorInfo);

void Can_CallBackSetUp(void);

extern volatile uint8   Can_RxData[CAN_FD_FRAME_LEN];
extern volatile uint8  Can_RxHandle;
extern volatile Can_IdType Can_RxId;
extern volatile uint8  Can_RxDlc;
extern volatile uint8  Can_ControllerId;
extern volatile PduIdType Can_TxConfirmation_CanTxPduId;
extern volatile uint8  Can_BusOffConfirmation;
extern volatile uint32   Can_Tx_No[16];
extern volatile uint32 u32CustomCallbackExecutions;
#if CAN_43_LLCE_MAX_PARTITIONS == 1U
    extern volatile uint32 Can_RxIndication;
    extern volatile uint32 Can_TxConfirmation;
#else
    extern volatile uint32 Can_RxIndication[MAX_NUM_OF_CORES];
    extern volatile uint32 Can_TxConfirmation[MAX_NUM_OF_CORES];
#endif

#endif /* STUBS_H */
