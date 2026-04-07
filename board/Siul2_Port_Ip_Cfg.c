/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file      Siul2_Port_Ip_Cfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Siul2_Port_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_VENDOR_ID_CFG_C                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_C        4
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_C                4
#define SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_C                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_C                2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are of the same vendor */
#if (SIUL2_PORT_IP_VENDOR_ID_CFG_C != SIUL2_PORT_IP_VENDOR_ID_CFG_H)
    #error "Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
    (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
    (SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_C != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are different"
#endif
/* Check if Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are of the same Software version */
#if ((SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_C != SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
    (SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_C != SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
    (SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_C != SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                             LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                             LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                            LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                           LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                           GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                           GLOBAL VARIABLES
==================================================================================================*/

/* clang-format off */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
VS_0:
- options: {callFromInitBoot: 'true', coreID: M7_0}
- pin_list:
  - {pin_num: F15, peripheral: LLCE_CAN_0, signal: rxd, pin_signal: PC_11}
  - {pin_num: G11, peripheral: LLCE_CAN_0, signal: txd, pin_signal: PC_12}
  - {pin_num: D17, peripheral: LLCE_CAN_1, signal: rxd, pin_signal: PJ_02}
  - {pin_num: B11, peripheral: LLCE_CAN_1, signal: txd, pin_signal: PJ_01}
  - {pin_num: F14, peripheral: LLCE_CAN_10, signal: rxd, pin_signal: PK_04}
  - {pin_num: E11, peripheral: LLCE_CAN_10, signal: txd, pin_signal: PK_03}
  - {pin_num: B15, peripheral: LLCE_CAN_11, signal: rxd, pin_signal: PK_06}
  - {pin_num: D11, peripheral: LLCE_CAN_11, signal: txd, pin_signal: PK_05}
  - {pin_num: F13, peripheral: LLCE_CAN_12, signal: rxd, pin_signal: PK_08}
  - {pin_num: C10, peripheral: LLCE_CAN_12, signal: txd, pin_signal: PK_07}
  - {pin_num: E14, peripheral: LLCE_CAN_13, signal: rxd, pin_signal: PK_10}
  - {pin_num: E10, peripheral: LLCE_CAN_13, signal: txd, pin_signal: PK_09}
  - {pin_num: C14, peripheral: LLCE_CAN_14, signal: rxd, pin_signal: PK_12}
  - {pin_num: A9, peripheral: LLCE_CAN_14, signal: txd, pin_signal: PK_11}
  - {pin_num: B13, peripheral: LLCE_CAN_15, signal: rxd, pin_signal: PK_14}
  - {pin_num: C9, peripheral: LLCE_CAN_15, signal: txd, pin_signal: PK_13}
  - {pin_num: C15, peripheral: LLCE_CAN_2, signal: rxd, pin_signal: PJ_04}
  - {pin_num: D10, peripheral: LLCE_CAN_2, signal: txd, pin_signal: PJ_03}
  - {pin_num: D15, peripheral: LLCE_CAN_3, signal: rxd, pin_signal: PJ_06}
  - {pin_num: C11, peripheral: LLCE_CAN_3, signal: txd, pin_signal: PJ_05}
  - {pin_num: F16, peripheral: LLCE_CAN_4, signal: rxd, pin_signal: PJ_08}
  - {pin_num: D12, peripheral: LLCE_CAN_4, signal: txd, pin_signal: PJ_07}
  - {pin_num: D16, peripheral: LLCE_CAN_5, signal: rxd, pin_signal: PJ_10}
  - {pin_num: B12, peripheral: LLCE_CAN_5, signal: txd, pin_signal: PJ_09}
  - {pin_num: E16, peripheral: LLCE_CAN_6, signal: rxd, pin_signal: PJ_12}
  - {pin_num: E12, peripheral: LLCE_CAN_6, signal: txd, pin_signal: PJ_11}
  - {pin_num: C16, peripheral: LLCE_CAN_7, signal: rxd, pin_signal: PJ_14}
  - {pin_num: A11, peripheral: LLCE_CAN_7, signal: txd, pin_signal: PJ_13}
  - {pin_num: A15, peripheral: LLCE_CAN_8, signal: rxd, pin_signal: PK_00}
  - {pin_num: A10, peripheral: LLCE_CAN_8, signal: txd, pin_signal: PJ_15}
  - {pin_num: D14, peripheral: LLCE_CAN_9, signal: rxd, pin_signal: PK_02}
  - {pin_num: F11, peripheral: LLCE_CAN_9, signal: txd, pin_signal: PK_01}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*! @brief Array of pin configuration structures */
const Siul2_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0] =
{
    {
        .base                        = IP_SIUL2_0,
        .pinPortIdx                  = 43u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL4,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         745u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_0,
        .pinPortIdx                  = 44u,
        .mux                         = PORT_MUX_ALT2,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL4,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 146u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         746u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 145u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 164u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         755u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 163u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 166u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         756u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 165u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 168u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         757u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 167u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 170u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         758u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 169u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 172u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         759u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 171u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 174u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         760u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 173u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 148u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         747u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 147u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 150u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         748u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 149u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 152u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         749u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 151u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 154u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         750u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 153u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 156u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         751u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 155u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 158u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         752u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 157u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 160u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         753u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 159u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 162u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .inputMuxReg                 = {
                                         754u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2_1,
        .pinPortIdx                  = 161u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL0,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue                   = 2u
    },
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

#ifdef SIUL2_PORT_IP_INIT_UNUSED_PIN
#if (STD_ON == SIUL2_PORT_IP_INIT_UNUSED_PIN)

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*! @brief Array of unused pin */
const Siul2_Port_Ip_UnUsedPinType g_unused_Pin[NUM_OF_UNUSED_PINS] =
{
    { (uint16)2, SIUL2_0_U8 },
    { (uint16)3, SIUL2_0_U8 },
    { (uint16)6, SIUL2_0_U8 },
    { (uint16)7, SIUL2_0_U8 },
    { (uint16)8, SIUL2_0_U8 },
    { (uint16)9, SIUL2_0_U8 },
    { (uint16)10, SIUL2_0_U8 },
    { (uint16)11, SIUL2_0_U8 },
    { (uint16)12, SIUL2_0_U8 },
    { (uint16)13, SIUL2_0_U8 },
    { (uint16)14, SIUL2_0_U8 },
    { (uint16)15, SIUL2_0_U8 },
    { (uint16)16, SIUL2_0_U8 },
    { (uint16)17, SIUL2_0_U8 },
    { (uint16)18, SIUL2_0_U8 },
    { (uint16)19, SIUL2_0_U8 },
    { (uint16)20, SIUL2_0_U8 },
    { (uint16)21, SIUL2_0_U8 },
    { (uint16)22, SIUL2_0_U8 },
    { (uint16)23, SIUL2_0_U8 },
    { (uint16)24, SIUL2_0_U8 },
    { (uint16)25, SIUL2_0_U8 },
    { (uint16)26, SIUL2_0_U8 },
    { (uint16)27, SIUL2_0_U8 },
    { (uint16)28, SIUL2_0_U8 },
    { (uint16)29, SIUL2_0_U8 },
    { (uint16)30, SIUL2_0_U8 },
    { (uint16)31, SIUL2_0_U8 },
    { (uint16)32, SIUL2_0_U8 },
    { (uint16)33, SIUL2_0_U8 },
    { (uint16)34, SIUL2_0_U8 },
    { (uint16)35, SIUL2_0_U8 },
    { (uint16)36, SIUL2_0_U8 },
    { (uint16)37, SIUL2_0_U8 },
    { (uint16)38, SIUL2_0_U8 },
    { (uint16)39, SIUL2_0_U8 },
    { (uint16)40, SIUL2_0_U8 },
    { (uint16)41, SIUL2_0_U8 },
    { (uint16)42, SIUL2_0_U8 },
    { (uint16)45, SIUL2_0_U8 },
    { (uint16)46, SIUL2_0_U8 },
    { (uint16)47, SIUL2_0_U8 },
    { (uint16)48, SIUL2_0_U8 },
    { (uint16)49, SIUL2_0_U8 },
    { (uint16)50, SIUL2_0_U8 },
    { (uint16)51, SIUL2_0_U8 },
    { (uint16)52, SIUL2_0_U8 },
    { (uint16)53, SIUL2_0_U8 },
    { (uint16)54, SIUL2_0_U8 },
    { (uint16)55, SIUL2_0_U8 },
    { (uint16)56, SIUL2_0_U8 },
    { (uint16)57, SIUL2_0_U8 },
    { (uint16)58, SIUL2_0_U8 },
    { (uint16)59, SIUL2_0_U8 },
    { (uint16)60, SIUL2_0_U8 },
    { (uint16)61, SIUL2_0_U8 },
    { (uint16)62, SIUL2_0_U8 },
    { (uint16)63, SIUL2_0_U8 },
    { (uint16)64, SIUL2_0_U8 },
    { (uint16)65, SIUL2_0_U8 },
    { (uint16)66, SIUL2_0_U8 },
    { (uint16)67, SIUL2_0_U8 },
    { (uint16)68, SIUL2_0_U8 },
    { (uint16)69, SIUL2_0_U8 },
    { (uint16)70, SIUL2_0_U8 },
    { (uint16)71, SIUL2_0_U8 },
    { (uint16)72, SIUL2_0_U8 },
    { (uint16)73, SIUL2_0_U8 },
    { (uint16)74, SIUL2_0_U8 },
    { (uint16)75, SIUL2_0_U8 },
    { (uint16)76, SIUL2_0_U8 },
    { (uint16)77, SIUL2_0_U8 },
    { (uint16)78, SIUL2_0_U8 },
    { (uint16)79, SIUL2_0_U8 },
    { (uint16)80, SIUL2_0_U8 },
    { (uint16)81, SIUL2_0_U8 },
    { (uint16)82, SIUL2_0_U8 },
    { (uint16)83, SIUL2_0_U8 },
    { (uint16)84, SIUL2_0_U8 },
    { (uint16)85, SIUL2_0_U8 },
    { (uint16)86, SIUL2_0_U8 },
    { (uint16)87, SIUL2_0_U8 },
    { (uint16)88, SIUL2_0_U8 },
    { (uint16)89, SIUL2_0_U8 },
    { (uint16)90, SIUL2_0_U8 },
    { (uint16)91, SIUL2_0_U8 },
    { (uint16)92, SIUL2_0_U8 },
    { (uint16)93, SIUL2_0_U8 },
    { (uint16)94, SIUL2_0_U8 },
    { (uint16)95, SIUL2_0_U8 },
    { (uint16)96, SIUL2_0_U8 },
    { (uint16)97, SIUL2_0_U8 },
    { (uint16)98, SIUL2_0_U8 },
    { (uint16)99, SIUL2_0_U8 },
    { (uint16)100, SIUL2_0_U8 },
    { (uint16)101, SIUL2_0_U8 },
    { (uint16)112, SIUL2_1_U8 },
    { (uint16)113, SIUL2_1_U8 },
    { (uint16)114, SIUL2_1_U8 },
    { (uint16)115, SIUL2_1_U8 },
    { (uint16)116, SIUL2_1_U8 },
    { (uint16)117, SIUL2_1_U8 },
    { (uint16)118, SIUL2_1_U8 },
    { (uint16)119, SIUL2_1_U8 },
    { (uint16)120, SIUL2_1_U8 },
    { (uint16)121, SIUL2_1_U8 },
    { (uint16)122, SIUL2_1_U8 },
    { (uint16)144, SIUL2_1_U8 },
    { (uint16)175, SIUL2_1_U8 },
    { (uint16)176, SIUL2_1_U8 },
    { (uint16)177, SIUL2_1_U8 },
    { (uint16)178, SIUL2_1_U8 },
    { (uint16)179, SIUL2_1_U8 },
    { (uint16)180, SIUL2_1_U8 },
    { (uint16)181, SIUL2_1_U8 },
    { (uint16)182, SIUL2_1_U8 },
    { (uint16)183, SIUL2_1_U8 },
    { (uint16)184, SIUL2_1_U8 },
    { (uint16)185, SIUL2_1_U8 },
    { (uint16)186, SIUL2_1_U8 },
    { (uint16)187, SIUL2_1_U8 },
    { (uint16)188, SIUL2_1_U8 },
    { (uint16)189, SIUL2_1_U8 },
    { (uint16)190, SIUL2_1_U8 }
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* (STD_ON == SIUL2_PORT_IP_INIT_UNUSED_PIN) */
#endif /* (SIUL2_PORT_IP_INIT_UNUSED_PIN) */

/*==================================================================================================
                                      LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                           GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

