
/**
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
#ifndef CAN_43_LLCE_EXTERNALS_H
#define CAN_43_LLCE_EXTERNALS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_43_LLCE_EXTERNALS_VENDOR_ID_H                       43
#define CAN_43_LLCE_EXTERNALS_MODULE_ID_H                       80
#define CAN_43_LLCE_EXTERNALS_AR_RELEASE_MAJOR_VERSION_H        4
#define CAN_43_LLCE_EXTERNALS_AR_RELEASE_MINOR_VERSION_H        4
#define CAN_43_LLCE_EXTERNALS_AR_RELEASE_REVISION_VERSION_H     0
#define CAN_43_LLCE_EXTERNALS_SW_MAJOR_VERSION_H                1
#define CAN_43_LLCE_EXTERNALS_SW_MINOR_VERSION_H                0
#define CAN_43_LLCE_EXTERNALS_SW_PATCH_VERSION_H                11
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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
#define CAN_43_LLCE_START_SEC_CODE
#include "Can_43_LLCE_MemMap.h"

void RxTimestampNotification(Can_HwHandleType Hoh, uint32 u32TimestampVal);
        #define Can_43_LLCE_RxTimestampNotification     (RxTimestampNotification)
        
        void TxTimestampNotification(Can_HwHandleType Hoh, PduIdType CanTxPduId, uint32 u32TimestampVal);
        #define Can_43_LLCE_TxTimestampNotification     (TxTimestampNotification)
        
        void CanErrorNotification(CanErrorNotificationType* error);
        #define Can_43_LLCE_ErrorNotificationCallback   (CanErrorNotification)
        
        

#define CAN_43_LLCE_STOP_SEC_CODE
#include "Can_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CAN_43_LLCE_EXTERNALS_H */

/** @} */

