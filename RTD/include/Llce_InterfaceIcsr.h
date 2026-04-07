/**
 *   @file    Llce_InterfaceIcsr.h
 *
 *   @brief   This file contains defines used for accessing ICSR hw module
 *   @details This file contains defines used for accessing ICSR hw module
 *
 *   @addtogroup LLCE_CAN_firmware_interface LLCE CAN firmware interface
 *   @{
 */
/*==================================================================================================
 *
 * Copyright 2018-2023 NXP
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that
 * you agree to comply with and are bound by, such license terms.  If you do not
 * agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 ==================================================================================================*/

#ifndef LLCE_INTERFACEICSR_H
#define LLCE_INTERFACEICSR_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __DOXYGEN__
/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 4.9, A function should be used in
 * preference to a function-like macro where they are interchangeable. Function
 * like macro are used to reduce code complexity
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused
 * macro declarations Some macros are used either in FW or driver, or provided
 * as API
 *
 */
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

/*==================================================================================================
 *                                     FILE VERSION CHECKS
 ==================================================================================================*/

/*==================================================================================================
 *                                          CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/

/*==================================================================================================
                  INTERRUPT CONCENTRATOR DEFINES AND ADDRESS
 CALCULATION MACROS
 =================================================================================================*/
#define LLCE_ICSR_ADDR(u8RegNo)                                                \
    ((uint32)LLCE_ICSR_BASEADDR + ((uint32)(u8RegNo) * (uint32)4U))
#define LLCE_ICSR_RIFA16_U32 ((uint32)0x00000001U)
#define LLCE_ICSR_ROFA16_U32 ((uint32)0x00000010U)
#define LLCE_ICSR_TAFA16_U32 ((uint32)0x00000001U)

#define LLCE_ICSR_GF0AINT_U32 ((uint32)0x00000001U)
#define LLCE_ICSR_GF1AINT_U32 ((uint32)0x00000002U)
#define LLCE_ICSR_GF2AINT_U32 ((uint32)0x00000004U)
#define LLCE_ICSR_GF3AINT_U32 ((uint32)0x00000008U)
#define LLCE_ICSR_GF0BINT_U32 ((uint32)0x00000010U)
#define LLCE_ICSR_GF1BINT_U32 ((uint32)0x00000020U)
#define LLCE_ICSR_GF2BINT_U32 ((uint32)0x00000040U)
#define LLCE_ICSR_GF3BINT_U32 ((uint32)0x00000080U)

#define LLCE_ICSR_INTFLAG_00 (0x01U)
#define LLCE_ICSR_INTFLAG_01 (0x02U)
#define LLCE_ICSR_INTFLAG_02 (0x04U)
#define LLCE_ICSR_INTFLAG_03 (0x08U)
#define LLCE_ICSR_INTFLAG_04 (0x10U)
#define LLCE_ICSR_INTFLAG_05 (0x20U)
#define LLCE_ICSR_INTFLAG_06 (0x40U)
#define LLCE_ICSR_INTFLAG_07 (0x80U)

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

#endif /* LLCE_INTERFACEICSR_H */

/** @} */
