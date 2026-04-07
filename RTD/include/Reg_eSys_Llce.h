/**
*   @file    Reg_eSys_Llce.h
*   @implements Reg_eSys_Llce.h_Artifact
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - S32Gxx Llce Defines and Macros Definitions.
*   @details Header file for S32Gxx Llce Defines and Macros Definitions.
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


#ifndef REG_ESYS_LLCE_H
#define REG_ESYS_LLCE_H

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Llce_InterfaceCanTypes.h"
#include "Can_43_LLCE_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                BIT MASKS FOR SHIFTING BCAN REGISTER VALUES
==================================================================================================*/
/**
* @brief Define used for Can_43_LLCE_ControllerDescriptorType.u8ControllerOffset when controller is not enabled.
*/
#define LLCE_NULL_OFFSET_U8              (0xFFU)

/**
* @brief Defines used to check specific field of the LPDU frame exchanged with upper software layers.
*/
#define CAN_LPDU_ID_MASK_U32              ((uint32)0x3FFFFFFFU)

#define CAN_LPDU_IDE_U32                  ((uint32)0x80000000U)

#define CAN_LPDU_FD_U32                   ((uint32)0x40000000)       

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

#endif /*TEMPLATE_H*/

/** @} */
