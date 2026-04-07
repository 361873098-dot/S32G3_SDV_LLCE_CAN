/**
*   @file    Can_IrqConfig.h
*   
*   @version 1.0.0
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Header file used to map ISRs to specific hardware FIFOs.It shall be synchronised also with the LLCE firmware configuration.
*
*   @addtogroup CAN_LLCE
*   @{
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

#ifndef CAN_43_LLCE_IRQCONFIG_H
#define CAN_43_LLCE_IRQCONFIG_H


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Llce_RegAccess.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define LLCE_FIFO_TXACK_00_EN   (STD_ON)
#define LLCE_FIFO_TXACK_01_EN   (STD_ON)
#define LLCE_FIFO_TXACK_02_EN   (STD_ON)
#define LLCE_FIFO_TXACK_03_EN   (STD_ON)
#define LLCE_FIFO_TXACK_04_EN   (STD_ON)
#define LLCE_FIFO_TXACK_05_EN   (STD_ON)
#define LLCE_FIFO_TXACK_06_EN   (STD_ON)
#define LLCE_FIFO_TXACK_07_EN   (STD_ON)
#define LLCE_FIFO_TXACK_08_EN   (STD_ON)
#define LLCE_FIFO_TXACK_09_EN   (STD_ON)
#define LLCE_FIFO_TXACK_10_EN   (STD_ON)
#define LLCE_FIFO_TXACK_11_EN   (STD_ON)
#define LLCE_FIFO_TXACK_12_EN   (STD_ON)
#define LLCE_FIFO_TXACK_13_EN   (STD_ON)
#define LLCE_FIFO_TXACK_14_EN   (STD_ON)
#define LLCE_FIFO_TXACK_15_EN   (STD_ON)


#define LLCE_FIFO_RXOUT_00_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_01_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_02_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_03_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_04_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_05_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_06_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_07_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_08_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_09_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_10_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_11_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_12_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_13_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_14_EN   (STD_ON)
#define LLCE_FIFO_RXOUT_15_EN   (STD_ON)


#define LLCE_FIFO_RXIN_00_EN    (STD_ON)
#define LLCE_FIFO_RXIN_01_EN    (STD_OFF) /* It used without interrupt service routine.*/
#define LLCE_FIFO_RXIN_02_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_03_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_04_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_05_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_06_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_07_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_08_EN    (STD_ON)
#define LLCE_FIFO_RXIN_09_EN    (STD_OFF) /* It used without interrupt service routine.*/
#define LLCE_FIFO_RXIN_10_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_11_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_12_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_13_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_14_EN    (STD_OFF)
#define LLCE_FIFO_RXIN_15_EN    (STD_OFF)


#define LLCE_FIFO_TXACK_00_ISR() Can_Llce_ProcessTx(0)
#define LLCE_FIFO_TXACK_01_ISR() Can_Llce_ProcessTx(1)
#define LLCE_FIFO_TXACK_02_ISR() Can_Llce_ProcessTx(2)
#define LLCE_FIFO_TXACK_03_ISR() Can_Llce_ProcessTx(3)
#define LLCE_FIFO_TXACK_04_ISR() Can_Llce_ProcessTx(4)
#define LLCE_FIFO_TXACK_05_ISR() Can_Llce_ProcessTx(5)
#define LLCE_FIFO_TXACK_06_ISR() Can_Llce_ProcessTx(6)
#define LLCE_FIFO_TXACK_07_ISR() Can_Llce_ProcessTx(7)
#define LLCE_FIFO_TXACK_08_ISR() Can_Llce_ProcessTx(8)
#define LLCE_FIFO_TXACK_09_ISR() Can_Llce_ProcessTx(9)
#define LLCE_FIFO_TXACK_10_ISR() Can_Llce_ProcessTx(10)
#define LLCE_FIFO_TXACK_11_ISR() Can_Llce_ProcessTx(11)
#define LLCE_FIFO_TXACK_12_ISR() Can_Llce_ProcessTx(12)
#define LLCE_FIFO_TXACK_13_ISR() Can_Llce_ProcessTx(13)
#define LLCE_FIFO_TXACK_14_ISR() Can_Llce_ProcessTx(14)
#define LLCE_FIFO_TXACK_15_ISR() Can_Llce_ProcessTx(15)


#define LLCE_FIFO_RXOUT_00_ISR() Can_Llce_ProcessRx(0)
#define LLCE_FIFO_RXOUT_01_ISR() Can_Llce_ProcessRx(1)
#define LLCE_FIFO_RXOUT_02_ISR() Can_Llce_ProcessRx(2)
#define LLCE_FIFO_RXOUT_03_ISR() Can_Llce_ProcessRx(3)
#define LLCE_FIFO_RXOUT_04_ISR() Can_Llce_ProcessRx(4)
#define LLCE_FIFO_RXOUT_05_ISR() Can_Llce_ProcessRx(5)
#define LLCE_FIFO_RXOUT_06_ISR() Can_Llce_ProcessRx(6)
#define LLCE_FIFO_RXOUT_07_ISR() Can_Llce_ProcessRx(7)
#define LLCE_FIFO_RXOUT_08_ISR() Can_Llce_ProcessRx(8)
#define LLCE_FIFO_RXOUT_09_ISR() Can_Llce_ProcessRx(9)
#define LLCE_FIFO_RXOUT_10_ISR() Can_Llce_ProcessRx(10)
#define LLCE_FIFO_RXOUT_11_ISR() Can_Llce_ProcessRx(11)
#define LLCE_FIFO_RXOUT_12_ISR() Can_Llce_ProcessRx(12)
#define LLCE_FIFO_RXOUT_13_ISR() Can_Llce_ProcessRx(13)
#define LLCE_FIFO_RXOUT_14_ISR() Can_Llce_ProcessRx(14)
#define LLCE_FIFO_RXOUT_15_ISR() Can_Llce_ProcessRx(15)


#define LLCE_FIFO_RXIN_00_ISR() Can_Llce_ProcessNotificationISR()
#define LLCE_FIFO_RXIN_01_ISR() 
#define LLCE_FIFO_RXIN_02_ISR() 
#define LLCE_FIFO_RXIN_03_ISR() 
#define LLCE_FIFO_RXIN_04_ISR() 
#define LLCE_FIFO_RXIN_05_ISR() 
#define LLCE_FIFO_RXIN_06_ISR() 
#define LLCE_FIFO_RXIN_07_ISR() 
#define LLCE_FIFO_RXIN_08_ISR() Can_Llce_ProcessNotificationISR()
#define LLCE_FIFO_RXIN_09_ISR() 
#define LLCE_FIFO_RXIN_10_ISR() 
#define LLCE_FIFO_RXIN_11_ISR() 
#define LLCE_FIFO_RXIN_12_ISR() 
#define LLCE_FIFO_RXIN_13_ISR() 
#define LLCE_FIFO_RXIN_14_ISR() 
#define LLCE_FIFO_RXIN_15_ISR() 

/*==================================================================================================
*                                      Interrupts
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


#ifdef __cplusplus
}
#endif

#endif /* CAN_43_LLCE_IRQCONFIG_H */

/** @} */
