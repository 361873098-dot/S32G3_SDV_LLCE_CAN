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
#include "Can_43_LLCE_IrqConfig.h"
#include "CanIf_Can.h"
#include "Mcal.h"
#include "Llce_InterfaceFifo.h"
#include "Llce_InterfaceIcsr.h"





/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* The integration of incompatible files shall be avoided. */
#define CAN_43_LLCE_VENDOR_ID_IRQ_C                      43
#define CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_IRQ_C       4
#define CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define CAN_SW_MAJOR_VERSION_IRQ_C               1
#define CAN_SW_MINOR_VERSION_IRQ_C               0
#define CAN_SW_PATCH_VERSION_IRQ_C               11



/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_IRQ_C != CAN_43_LLCE_VENDOR_ID)
    #error "Can_Irq.c and Can_43_LLCE.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_IRQ_C    != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_IRQ_C    != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_IRQ_C != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_Irq.c and Can_43_LLCE.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_IRQ_C != CAN_43_LLCE_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_IRQ_C != CAN_43_LLCE_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_IRQ_C != CAN_43_LLCE_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_Irq.c and Can_43_LLCE.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
    #if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_IRQ_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_IRQ_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_Irq.c and Det.h are different"
    #endif
#endif
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
#if defined CAN_43_LLCE_MEASURE_IRQ_ACK_LATENCY || defined CAN_43_LLCE_MEASURE_IRQ_RECV_LATENCY
extern volatile uint32 Stm_Measurement;
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
ISR(Can_FifoTxAckNotEmptyIsr_0_7);
ISR(Can_FifoTxAckNotEmptyIsr_8_15);
ISR(Can_FifoRxOutNotEmptyIsr_0_7);
ISR(Can_FifoRxOutNotEmptyIsr_8_15);
ISR(Can_FifoRxInNotEmptyIsr_0_7);
ISR(Can_FifoRxInNotEmptyIsr_8_15);

#define CAN_43_LLCE_START_SEC_CODE
#include "Can_43_LLCE_MemMap.h"
/**
* @implements     Can_Isr_X_Activity
*/
ISR(Can_FifoTxAckNotEmptyIsr_0_7)
{ 
    uint32 u32IntrStatusFlags;

    /*Read contents of interrupt concentrator register.*/
    u32IntrStatusFlags = Reg_Read32(LLCE_ICSR_ADDR(22));

    /*Check all bit fields from interrupt concentrator register. */
#ifdef CAN_43_LLCE_MEASURE_IRQ_ACK_LATENCY
        Stm_Measurement = Reg_Read32(LLCE_STM_CNT);
host_irq_ack_label:
#endif

#if (LLCE_FIFO_TXACK_00_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_00 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_00))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_00_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_01_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_01 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_01))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_01_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_02_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_02 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_02))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_02_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_03_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_03 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_03))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_03_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_04_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_04 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_04))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_04_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_05_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_05 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_05))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_05_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_06_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_06 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_06))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_06_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_07_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_07 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_07))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_07_ISR();
    }
#endif      
}

/**
* @implements     Can_Isr_X_Activity
*/
ISR(Can_FifoTxAckNotEmptyIsr_8_15)
{ 
    uint32 u32IntrStatusFlags;

    /*Read contents of interrupt concentrator register.*/
    u32IntrStatusFlags = Reg_Read32(LLCE_ICSR_ADDR(23));

    /*Check all bit fields from interrupt concentrator register. */
#if (LLCE_FIFO_TXACK_08_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_00 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_00))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_08_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_09_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_01 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_01))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_09_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_10_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_02 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_02))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_10_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_11_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_03 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_03))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_11_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_12_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_04 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_04))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_12_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_13_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_05 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_05))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_13_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_14_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_06 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_06))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_14_ISR();
    }
#endif
#if (LLCE_FIFO_TXACK_15_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_07 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_07))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_TXACK_15_ISR();
    }
#endif      
}

/**
* @implements     Can_Isr_X_Activity
*/
ISR(Can_FifoRxOutNotEmptyIsr_0_7)
{ 
    uint32 u32IntrStatusFlags;

    /*Read contents of interrupt concentrator register.*/
    u32IntrStatusFlags = Reg_Read32(LLCE_ICSR_ADDR(16));

    /*Check all bit fields from interrupt concentrator register. */

#ifdef CAN_43_LLCE_MEASURE_IRQ_RECV_LATENCY
        Stm_Measurement = Reg_Read32(LLCE_STM_CNT);
host_irq_recv_label:
#endif

#if (LLCE_FIFO_RXOUT_00_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_00 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_00))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_00_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_01_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_01 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_01))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_01_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_02_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_02 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_02))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_02_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_03_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_03 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_03))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_03_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_04_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_04 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_04))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_04_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_05_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_05 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_05))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_05_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_06_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_06 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_06))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_06_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_07_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_07 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_07))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_07_ISR();
    }
#endif 
}

/**
* @implements     Can_Isr_X_Activity
*/
ISR(Can_FifoRxOutNotEmptyIsr_8_15)
{ 
    uint32 u32IntrStatusFlags;    

    /*Read contents of interrupt concentrator register.*/
    u32IntrStatusFlags = Reg_Read32(LLCE_ICSR_ADDR(17));

    /*Check all bit fields from interrupt concentrator register. */

#if (LLCE_FIFO_RXOUT_08_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_00 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_00))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_08_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_09_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_01 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_01))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_09_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_10_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_02 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_02))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_10_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_11_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_03 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_03))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_11_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_12_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_04 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_04))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_12_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_13_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_05 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_05))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_13_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_14_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_06 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_06))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_14_ISR();
    }
#endif
#if (LLCE_FIFO_RXOUT_15_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_07 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_07))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXOUT_15_ISR();
    }
#endif 
}

/**
* @implements     Can_Isr_X_Activity
*/
ISR(Can_FifoRxInNotEmptyIsr_0_7)
{ 
    uint32 u32IntrStatusFlags;

    /*Read contents of interrupt concentrator register.*/
    u32IntrStatusFlags = Reg_Read32(LLCE_ICSR_ADDR(14));

    /*Check all bit fields from interrupt concentrator register. */

#if (LLCE_FIFO_RXIN_00_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_00 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_00))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_00_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_01_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_01 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_01))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_01_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_02_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_02 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_02))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_02_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_03_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_03 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_03))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_03_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_04_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_04 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_04))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_04_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_05_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_05 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_05))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_05_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_06_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_06 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_06))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_06_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_07_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_07 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_07))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_07_ISR();
    }
#endif 
}

/**
* @implements     Can_Isr_X_Activity
*/
ISR(Can_FifoRxInNotEmptyIsr_8_15)
{ 
    uint32 u32IntrStatusFlags;    

    /*Read contents of interrupt concentrator register.*/
    u32IntrStatusFlags = Reg_Read32(LLCE_ICSR_ADDR(15));

    /*Check all bit fields from interrupt concentrator register. */

#if (LLCE_FIFO_RXIN_08_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_00 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_00))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_08_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_09_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_01 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_01))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_09_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_10_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_02 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_02))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_10_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_11_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_03 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_03))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_11_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_12_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_04 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_04))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_12_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_13_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_05 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_05))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_13_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_14_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_06 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_06))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_14_ISR();
    }
#endif
#if (LLCE_FIFO_RXIN_15_EN == STD_ON)
    if (LLCE_ICSR_INTFLAG_07 == (u32IntrStatusFlags & LLCE_ICSR_INTFLAG_07))
    {
        /* Call the processing routine for this kind of interrupt.*/
        LLCE_FIFO_RXIN_15_ISR();
    }
#endif 
}

#define CAN_43_LLCE_STOP_SEC_CODE
#include "Can_43_LLCE_MemMap.h"
#ifdef __cplusplus
}
#endif
/** @} */
