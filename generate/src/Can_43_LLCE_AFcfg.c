/**
*   @file    Can_43_LLCE_AFcfg.c
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Configuration Structures for PostBuild.
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

/**
* @file           Can_43_LLCE_AFcfg.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Llce_InterfaceCanTypes.h"
#include "Mcal.h"
#include "Can_43_LLCE_AFcfg.h"

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#include "Can_43_LLCE_MemMap.h"

#define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
#include "Can_43_LLCE_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"


/* Configuration for Can2Can and Can2Eth and Can2Other routing */
const Can_Af_DestRulesType Llce_Can_AfRoutingTable[LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT] =
{
    {
        {.Can2Can = {
        /* ======= Routing Rule ======= */
            (uint32)(
                  LLCE_CAN_ROUTING_NOCHANGE |
                  LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
            ),
            (uint32)0U,
            {
                (uint8)15,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0
         },
       (uint8)1U
       }},
        /* ======= Destination rule type ======= */
        CAN_AF_CAN2CAN 
    },
    {
        {.Can2Can = {
        /* ======= Routing Rule ======= */
            (uint32)(
              LLCE_CAN_ROUTING_CANFD |
                  LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
            ),
            (uint32)0U,
            {
                (uint8)15,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0
         },
       (uint8)1U
       }},
        /* ======= Destination rule type ======= */
        CAN_AF_CAN2CAN 
    },
    {
        {.Can2Can = {
        /* ======= Routing Rule ======= */
            (uint32)(
                  LLCE_CAN_ROUTING_CAN |
                  LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
            ),
            (uint32)0U,
            {
                (uint8)15,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0
         },
       (uint8)1U
       }},
        /* ======= Destination rule type ======= */
        CAN_AF_CAN2CAN 
    },
    {
        {.Can2Can = {
        /* ======= Routing Rule ======= */
            (uint32)(
                  LLCE_CAN_ROUTING_NOCHANGE |
                  LLCE_CAN_ROUTING_ID_REMAPPING_EN |
                  LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
            ),
              (uint32)999U << LLCE_CAN_MB_IDSTD_SHIFT_U32,
            {
                (uint8)15,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0,
                (uint8)0
         },
       (uint8)1U
       }},
        /* ======= Destination rule type ======= */
        CAN_AF_CAN2CAN 
    },
      };


#define CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

