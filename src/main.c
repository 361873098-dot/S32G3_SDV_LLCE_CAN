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

#include "stubs.h"
#include "Can_43_LLCE.h"
#include "PlatformInit.h"
#include "Llce_Firmware_Load.h"
#include "can_common.h"
#include "Core_Heartbeat.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define MACRO_CONCAT(a,b) a##b
 #define CAN_VARIANT(var) MACRO_CONCAT(Can_43_LLCE_Config_, var)
#ifndef CONFIG_VARIANT_USED
 #define CAN_LLCE_VARIANT   NULL_PTR
#else
 #define CAN_LLCE_VARIANT   &CAN_VARIANT(CONFIG_VARIANT_USED)     
#endif


/* Autosar Configuration (see CAN2CAN_Project ) mapping is: idx 2 -> hwCtrl (BCAN) 14; idx 3 -> hwCtrl (BCAN)  15 */
#define LOGICAL_CONTROLLER15 3
#define LOGICAL_CONTROLLER14 2


void Can_Driver_Sample_Test(void)
{
    Can_ErrorStateType ErrorState;
    Std_ReturnType can_retval = E_NOT_OK;
    Can_PduType CanMessage;
    static uint8 can_fd_data[CAN_FD_FRAME_LEN];
    static uint8 can_std_data[CAN_STD_FRAME_LEN];
    uint16 u16MbGlobalIndex = 0U;

    Can_43_LLCE_Init(CAN_LLCE_VARIANT);

    /* Reset global flags and counters. */
    Can_CallBackSetUp();

    /*Initialize transmission data buffer with a standard Can frame.*/
    for (u16MbGlobalIndex = 0; u16MbGlobalIndex < CAN_STD_FRAME_LEN; u16MbGlobalIndex++)
    {
        can_std_data[u16MbGlobalIndex] = u16MbGlobalIndex;
    }

    /*Initialize transmission data buffer with a Can Fd frame.*/
    for (u16MbGlobalIndex = 0; u16MbGlobalIndex < CAN_FD_FRAME_LEN; u16MbGlobalIndex++)
    {
        can_fd_data[u16MbGlobalIndex] = u16MbGlobalIndex;
    }

    (void)can_retval;

/* In headless mode the call of Can_SetBaudrate() would cause a re-initialization of the CAN Controller 
   when it is in STARTED state and will return E_NOT_OK according to (SWS_Can_00256) */

    /* Start CONTROLLER0 */
#ifndef LLCE_USE_HEADLESS
    can_retval = Can_43_LLCE_SetBaudrate(CONTROLLER0, 1); /* Index 1 corresponds to a baudrate configuration of (500 kbps; 2000 kbps).See Tresos configuration*/
    ASSERT(E_OK == can_retval);
#endif
    can_retval = Can_43_LLCE_SetControllerMode(CONTROLLER0, CAN_CS_STARTED);
    ASSERT(E_OK == can_retval);
    can_retval = Can_43_LLCE_GetControllerErrorState(CONTROLLER0, &ErrorState);
    ASSERT(E_OK == can_retval);
    /* Start CONTROLLER1 */
#ifndef LLCE_USE_HEADLESS    
    can_retval = Can_43_LLCE_SetBaudrate(CONTROLLER1, 1); /* Index 1 corresponds to a baudrate configuration of (500 kbps; 2000 kbps).See Tresos configuration*/
    ASSERT(E_OK == can_retval);
#endif
    can_retval = Can_43_LLCE_SetControllerMode(CONTROLLER1, CAN_CS_STARTED);
    ASSERT(E_OK == can_retval);
    can_retval = Can_43_LLCE_GetControllerErrorState(CONTROLLER1, &ErrorState);
    ASSERT(E_OK == can_retval);

    /* Make sure that Tx Message Buffers used for host are less than 16. The difference between 16(max number of tx mb) 
    and tx Mb reserved or host will be used for routing on that channel. In this demo, that's channel 15.
    It has 4 MBs used for standard transmission, and 12 MBs used for routing frames to other channels. */

    /* Start CONTROLLER15 */
#ifndef LLCE_USE_HEADLESS
    can_retval = Can_43_LLCE_SetBaudrate(LOGICAL_CONTROLLER15, 0); /* Index 0 corresponds to a baudrate configuration of (250 kbps; 500 kbps). See Tresos configuration*/
    ASSERT(E_OK == can_retval);
#endif
    can_retval = Can_43_LLCE_SetControllerMode(LOGICAL_CONTROLLER15, CAN_CS_STARTED);
    ASSERT(E_OK == can_retval);
    /* Start CONTROLLER14 */
#ifndef LLCE_USE_HEADLESS
    can_retval = Can_43_LLCE_SetBaudrate(LOGICAL_CONTROLLER14, 0);  /* Index 0 corresponds to a baudrate configuration of (250 kbps; 500 kbps). See Tresos configuration*/
    ASSERT(E_OK == can_retval);
#endif
    can_retval = Can_43_LLCE_SetControllerMode(LOGICAL_CONTROLLER14, CAN_CS_STARTED);
    ASSERT(E_OK == can_retval);

    /* Send data */
    Can_TxConfirmation = 0;
    Can_RxIndication = 0;
    Can_RxDlc = 0;

    last_RxIndication = 0;
    last_TxConfirmation = 0;

    for (u16MbGlobalIndex = 0; u16MbGlobalIndex < ITER_NR; u16MbGlobalIndex++)
    {   
        Core_Heartbeat_Check();

        /* Set-up CAN frame data */
        CanMessage.length = CAN_FD_FRAME_LEN;
        CanMessage.sdu = can_fd_data;
        CanMessage.swPduHandle = u16MbGlobalIndex & 15; //%16

        /* Ctrl1 send frame to Ctrl0. This is an unrouted frame. In configuration, the HRH which receive frame with ID=1 has the routing option OFF */
        CanMessage.id = 1 | CAN_LPDU_FD_U32;
        can_retval = Can_43_LLCE_Write(CanHO_Config1_TX1, &CanMessage);
        ASSERT(E_OK == can_retval);

        /* Check status of transmission and reception */
        can_retval = Check_Status(&CanMessage);
        ASSERT(E_OK == can_retval);
        
        /* Ctrl 1 will send a message to ctrl 0, which does internal routing to channel 15, which will send the frame
        with id=15 to ctrl 14 on the external bus. Now, ctrl 0 will receive the frame on another HRH which receive frame with ID=15 and has the routing option ON,
        and the routing table indicates destination channel = 15 (configurable in Llce plugin)  */
        /* This is a routed frame */
        CanMessage.id = 15 | CAN_LPDU_FD_U32;
        can_retval = Can_43_LLCE_Write(CanHO_Config1_TX1, &CanMessage);
        ASSERT(E_OK == can_retval);
        
        /* Check status of transmission and reception */
        can_retval = Check_Status(&CanMessage);
        ASSERT(E_OK == can_retval);

        /* Now, Ctrl 1 will send a message with ID=888 to ctrl 0, which has a filter that accepts that ID. In the same time, it has an advanced feature reference
        (CanAdvancedFeature_3 in Llce_Af plugin, linked to the HRH CanHOH_Routing_RX0_IdRemap in Can_Llce plugin) which says "change the frame ID to 999 and forward
         it to destination channel 15, and don't deliver it to the host". It's also possible to send the frame also to the host core, to a logging core and to a list
         of multiple channel destinations simultaneously. */
        CanMessage.id = 888 | CAN_LPDU_FD_U32;
        can_retval = Can_43_LLCE_Write(CanHO_Config1_TX1, &CanMessage);
        ASSERT(E_OK == can_retval);
        
        /* Check status of transmission and reception */
        can_retval = Check_Status(&CanMessage);
        ASSERT(E_OK == can_retval);
        
        /* New Id value received */
        ASSERT((Can_RxId & ~CAN_LPDU_FD_U32) == 999);
        
        /* --- Routing with converting frame between CAN and CAN-FD --- */
        /* Set-up CAN frame data */
        CanMessage.length = CAN_STD_FRAME_LEN;
        CanMessage.sdu = can_std_data;

        /* Now, Ctrl 1 will send a message with ID=321 to ctrl 0, which has a filter (named CanHOH_CanFD2Can) which accepts that ID. In the same time, it is linked to an advanced feature 
            reference (CanAdvancedFeature_2) which says "change the frame format from CAN-FD to CAN and forward it to channel 15, and don't deliver it to the host" */
        CanMessage.id = 321 | CAN_LPDU_FD_U32;
        can_retval = Can_43_LLCE_Write(CanHO_Config1_TX1, &CanMessage);
        ASSERT(E_OK == can_retval);
        
        /* Check status of transmission and reception */
        can_retval = Check_Status(&CanMessage);
        ASSERT(E_OK == can_retval);

        /* Check received RxID frame */
        ASSERT(CAN_LPDU_FD_U32 != (Can_RxId & CAN_LPDU_FD_U32));
       
        /* Now, Ctrl 1 will send a message with ID=123 to ctrl 0, which has a filter (named CanHOH_Can2CanFD) which accepts that ID. In the same time, it is linked to an advanced feature 
            reference (CanAdvancedFeature_1) which says "change the frame format from CAN-FD to CAN and forward it to channel 15, and don't deliver it to the host" */
        CanMessage.id = 123;
        can_retval = Can_43_LLCE_Write(CanHO_Config1_TX1, &CanMessage);
        ASSERT(E_OK == can_retval);
        
        /* Check status of transmission and reception */
        can_retval = Check_Status(&CanMessage);
        ASSERT(E_OK == can_retval);

        /* Check received RxID frame */
        ASSERT(CAN_LPDU_FD_U32 == (Can_RxId & CAN_LPDU_FD_U32));
    }

	/* Check eventual errors configured to be reported in polling. This will trigger CanErrorNotification. */
	Can_43_LLCE_MainFunction_ErrorNotification();
    can_retval = Can_43_LLCE_SetControllerMode(CONTROLLER0, CAN_CS_STOPPED);
    ASSERT(E_OK == can_retval);
    can_retval = Can_43_LLCE_SetControllerMode(CONTROLLER1, CAN_CS_STOPPED);
    ASSERT(E_OK == can_retval);
    can_retval = Can_43_LLCE_SetControllerMode(LOGICAL_CONTROLLER14, CAN_CS_STOPPED);
    ASSERT(E_OK == can_retval);
    can_retval = Can_43_LLCE_SetControllerMode(LOGICAL_CONTROLLER15, CAN_CS_STOPPED);
    ASSERT(E_OK == can_retval);

    /* 5 writes was executed per iteration */
    ASSERT(5 * ITER_NR == Can_TxConfirmation);
    ASSERT(5 * ITER_NR == Can_RxIndication);

	Can_43_LLCE_DeInit();

}

int main(void)
{
    PlatformInit();
    
    Llce_Firmware_Load();
    Can_Driver_Sample_Test();

    while (1);
}

#ifdef __cplusplus
}
#endif
