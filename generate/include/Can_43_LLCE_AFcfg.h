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
#ifndef CAN_AFCFG_H
#define CAN_AFCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
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
#define LLCE_CAN_ADVANCED_FEATURE_AF_CNT          4U
#define LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT     4U
#define LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT     0U
#define LLCE_CAN_ADVANCED_FEATURE_CAN2PCIE_CNT    0U
#define LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT   0U
#define LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED       STD_OFF
#if(LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0)
/*
* @brief          CAN2ETH with external buffer
* @details        User shall use the external rings instead of internal ones.
*
*/
#define LLCE_USE_EXTERNAL_RING_BUF (STD_OFF)
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* Configuration for advanced features */
extern const Llce_Can_AdvancedFeatureType Can_Llce_AdvancedFeature[LLCE_CAN_ADVANCED_FEATURE_AF_CNT];

/* Configuration for Routing Rules (CAN2CAN, CAN2ETH, CAN2OTHER)  */
extern const Can_Af_DestRulesType Llce_Can_AfRoutingTable[LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT];
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* CAN_AFCFG_H */

/** @} */

