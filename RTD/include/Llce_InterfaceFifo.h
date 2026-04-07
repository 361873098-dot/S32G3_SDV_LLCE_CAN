/**
 *   @file    Llce_InterfaceFifo.h
 *
 *   @brief   This file contains defines used for accessing LLCE FIFO hw module
 *   @details This file contains defines used for accessing LLCE FIFO hw module
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

#ifndef LLCE_FIFOINTERFACE_H
#define LLCE_FIFOINTERFACE_H

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
#include "Llce_RegAccess.h"
#include "Llce_InterfaceCanConfig.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 ==================================================================================================*/

/*==================================================================================================
 *                                     FILE VERSION CHECKS
 ==================================================================================================*/

/*==================================================================================================
 *                                          CONSTANTS
 ==================================================================================================*/

extern const uint32 Llce_Can_u32BlrinBaseAddress[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
extern const uint32 Llce_Can_u32BlroutBaseAddress[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
extern const uint32 Llce_Can_u32TxackBaseAddress[LLCE_CAN_CONFIG_MAXCTRL_COUNT +
                                                 LLCE_CAN_MAX_POLLING_CLASSES];
extern const uint32 Llce_Can_u32RxoutBaseAddress[LLCE_CAN_CONFIG_MAXCTRL_COUNT +
                                                 LLCE_CAN_MAX_POLLING_CLASSES];

extern const uint32 Llce_Can_u32NotifFifo0BaseAddress[LLCE_CAN_CONFIG_HIF_COUNT];
extern const uint32 Llce_Can_u32NotifFifo1BaseAddress[LLCE_CAN_CONFIG_HIF_COUNT];

extern const uint32 Llce_Can_u32RxinBaseAddress[LLCE_CAN_CONFIG_HIF_COUNT];
extern const uint32 Llce_Can_u32CmdBaseAddress[LLCE_CAN_CONFIG_HIF_COUNT];

extern const uint32 Llce_Can_u32RxinLogBaseAddress[1];
extern const uint32 Llce_Can_u32RxoutLogBaseAddress[1];
/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/
 /* LLCE base addresses*/
/** @brief Base address for Generic FIFO 0. */
#define LLCE_GENERIC_FIFO_BASEADDR ((uint32)0x43A12000UL)
/** @brief Base address for the interrupt concentrator registers. */
#define LLCE_ICSR_BASEADDR ((uint32)0x43A14000UL)

#define LLCE_CONFIG_FIFO_DEPTH_U8 ((uint8)16U)

#define LLCE_FIFO_FFULLD_U32 ((uint32)0x00000001U)
#define LLCE_FIFO_FEMTYD_U32 ((uint32)0x00000002U)
#define LLCE_FIFO_SR_QCOUNT_SHIFT_U8 ((uint8)24U)

#define LLCE_FIFO_FCR_FIFOEN_U32 ((uint32)0x00000001U)
#define LLCE_FIFO_FCR_FLENOWEN_U32 ((uint32)0x00000002U)
#define LLCE_FIFO_FCR_POPEN_U32 ((uint32)0x00000004U)
#define LLCE_FIFO_FCR_PUSHEN_U32 ((uint32)0x00000008U)
#define LLCE_FIFO_FCR_FLUSH_U32 ((uint32)0x00000010U)

#define LLCE_FIFO_FCR_RESET_U32 ((uint32)0x0U)

/*Generic defines used to access STATUS, ILR and IER registers of FIFOs.*/
#define LLCE_FIFO_FFULL_U32    ((uint32)0x00000100U)
#define LLCE_FIFO_FNFULL_U32   ((uint32)0x00000200U)
#define LLCE_FIFO_FEMTY_U32    ((uint32)0x00000400U)
#define LLCE_FIFO_FNEMTY_U32   ((uint32)0x00000800U)
#define LLCE_FIFO_POPEVT_U32   ((uint32)0x00001000U)
#define LLCE_FIFO_WMKFL_U32    ((uint32)0x00002000U)
#define LLCE_FIFO_WMKEM_U32    ((uint32)0x00004000U)
#define LLCE_FIFO_POPUND_U32   ((uint32)0x00008000U)
#define LLCE_FIFO_PUSHOVR_U32  ((uint32)0x00010000U)
#define LLCE_FIFO_MSBNOMT_U32  ((uint32)0x00020000U)

/* Default value returned when popping an empty fifo */
#define LLCE_FIFO_NULL_VALUE ((uint32)0xFFFFFFFFU)

#define LLCE_FIFO_0_BASE_ADDRESS            (0x43A00000UL)
#define LLCE_FIFO_1_BASE_ADDRESS            (0x43A00400UL)
#define LLCE_FIFO_2_BASE_ADDRESS            (0x43A00800UL)
#define LLCE_FIFO_3_BASE_ADDRESS            (0x43A00C00UL)
#define LLCE_FIFO_4_BASE_ADDRESS            (0x43A01000UL)
#define LLCE_FIFO_5_BASE_ADDRESS            (0x43A01400UL)
#define LLCE_FIFO_6_BASE_ADDRESS            (0x43A01800UL)
#define LLCE_FIFO_7_BASE_ADDRESS            (0x43A01C00UL)
#define LLCE_FIFO_8_BASE_ADDRESS            (0x43A02000UL)
#define LLCE_FIFO_9_BASE_ADDRESS            (0x43A02400UL)
#define LLCE_FIFO_10_BASE_ADDRESS           (0x43A02800UL)
#define LLCE_FIFO_11_BASE_ADDRESS           (0x43A02C00UL)
#define LLCE_FIFO_12_BASE_ADDRESS           (0x43A03000UL)
#define LLCE_FIFO_13_BASE_ADDRESS           (0x43A03400UL)
#define LLCE_FIFO_14_BASE_ADDRESS           (0x43A03800UL)
#define LLCE_FIFO_15_BASE_ADDRESS           (0x43A03C00UL)
#define LLCE_FIFO_16_BASE_ADDRESS           (0x43A04000UL)
#define LLCE_FIFO_17_BASE_ADDRESS           (0x43A04400UL)
#define LLCE_FIFO_18_BASE_ADDRESS           (0x43A04800UL)
#define LLCE_FIFO_19_BASE_ADDRESS           (0x43A04C00UL)
#define LLCE_FIFO_20_BASE_ADDRESS           (0x43A05000UL)
#define LLCE_FIFO_21_BASE_ADDRESS           (0x43A08000UL)
#define LLCE_FIFO_22_BASE_ADDRESS           (0x43A08400UL)
#define LLCE_FIFO_23_BASE_ADDRESS           (0x43A08800UL)
#define LLCE_FIFO_24_BASE_ADDRESS           (0x43A08C00UL)
#define LLCE_FIFO_25_BASE_ADDRESS           (0x43A09000UL)
#define LLCE_FIFO_26_BASE_ADDRESS           (0x43A09400UL)
#define LLCE_FIFO_27_BASE_ADDRESS           (0x43A09800UL)
#define LLCE_FIFO_28_BASE_ADDRESS           (0x43A09C00UL)
#define LLCE_FIFO_29_BASE_ADDRESS           (0x43A0A000UL)
#define LLCE_FIFO_30_BASE_ADDRESS           (0x43A0A400UL)
#define LLCE_FIFO_31_BASE_ADDRESS           (0x43A0A800UL)
#define LLCE_FIFO_32_BASE_ADDRESS           (0x43A0AC00UL)
#define LLCE_FIFO_33_BASE_ADDRESS           (0x43A0B000UL)
#define LLCE_FIFO_34_BASE_ADDRESS           (0x43A0B400UL)
#define LLCE_FIFO_35_BASE_ADDRESS           (0x43A0B800UL)
#define LLCE_FIFO_36_BASE_ADDRESS           (0x43A0BC00UL)
#define LLCE_FIFO_37_BASE_ADDRESS           (0x43A0C000UL)
#define LLCE_FIFO_38_BASE_ADDRESS           (0x43A0C400UL)
#define LLCE_FIFO_39_BASE_ADDRESS           (0x43A0C800UL)
#define LLCE_FIFO_40_BASE_ADDRESS           (0x43A0CC00UL)
#define LLCE_FIFO_41_BASE_ADDRESS           (0x43A0D000UL)
#define LLCE_FIFO_42_BASE_ADDRESS           (0x43B00000UL)
#define LLCE_FIFO_43_BASE_ADDRESS           (0x43B00400UL)
#define LLCE_FIFO_44_BASE_ADDRESS           (0x43B00800UL)
#define LLCE_FIFO_45_BASE_ADDRESS           (0x43B00C00UL)
#define LLCE_FIFO_46_BASE_ADDRESS           (0x43B01000UL)
#define LLCE_FIFO_47_BASE_ADDRESS           (0x43B01400UL)
#define LLCE_FIFO_48_BASE_ADDRESS           (0x43B01800UL)
#define LLCE_FIFO_49_BASE_ADDRESS           (0x43B01C00UL)
#define LLCE_FIFO_50_BASE_ADDRESS           (0x43B02000UL)
#define LLCE_FIFO_51_BASE_ADDRESS           (0x43B02400UL)
#define LLCE_FIFO_52_BASE_ADDRESS           (0x43B02800UL)
#define LLCE_FIFO_53_BASE_ADDRESS           (0x43B02C00UL)
#define LLCE_FIFO_54_BASE_ADDRESS           (0x43B03000UL)
#define LLCE_FIFO_55_BASE_ADDRESS           (0x43B03400UL)
#define LLCE_FIFO_56_BASE_ADDRESS           (0x43B03800UL)
#define LLCE_FIFO_57_BASE_ADDRESS           (0x43B03C00UL)
#define LLCE_FIFO_58_BASE_ADDRESS           (0x43B04000UL)
#define LLCE_FIFO_59_BASE_ADDRESS           (0x43B04400UL)
#define LLCE_FIFO_60_BASE_ADDRESS           (0x43B04800UL)
#define LLCE_FIFO_61_BASE_ADDRESS           (0x43B04C00UL)
#define LLCE_FIFO_62_BASE_ADDRESS           (0x43B05000UL)
#define LLCE_FIFO_63_BASE_ADDRESS           (0x43B08000UL)
#define LLCE_FIFO_64_BASE_ADDRESS           (0x43B08400UL)
#define LLCE_FIFO_65_BASE_ADDRESS           (0x43B08800UL)
#define LLCE_FIFO_66_BASE_ADDRESS           (0x43B08C00UL)
#define LLCE_FIFO_67_BASE_ADDRESS           (0x43B09000UL)
#define LLCE_FIFO_68_BASE_ADDRESS           (0x43B09400UL)
#define LLCE_FIFO_69_BASE_ADDRESS           (0x43B09800UL)
#define LLCE_FIFO_70_BASE_ADDRESS           (0x43B09C00UL)
#define LLCE_FIFO_71_BASE_ADDRESS           (0x43B0A000UL)
#define LLCE_FIFO_72_BASE_ADDRESS           (0x43B0A400UL)
#define LLCE_FIFO_35_BASE_ADDRESS           (0x43A0B800UL)
#define LLCE_FIFO_36_BASE_ADDRESS           (0x43A0BC00UL)
#define LLCE_FIFO_37_BASE_ADDRESS           (0x43A0C000UL)
#define LLCE_FIFO_38_BASE_ADDRESS           (0x43A0C400UL)
#define LLCE_FIFO_39_BASE_ADDRESS           (0x43A0C800UL)
#define LLCE_FIFO_40_BASE_ADDRESS           (0x43A0CC00UL)
#define LLCE_FIFO_41_BASE_ADDRESS           (0x43A0D000UL)
#define LLCE_FIFO_42_BASE_ADDRESS           (0x43B00000UL)
#define LLCE_FIFO_43_BASE_ADDRESS           (0x43B00400UL)
#define LLCE_FIFO_44_BASE_ADDRESS           (0x43B00800UL)
#define LLCE_FIFO_45_BASE_ADDRESS           (0x43B00C00UL)
#define LLCE_FIFO_46_BASE_ADDRESS           (0x43B01000UL)
#define LLCE_FIFO_47_BASE_ADDRESS           (0x43B01400UL)
#define LLCE_FIFO_48_BASE_ADDRESS           (0x43B01800UL)
#define LLCE_FIFO_49_BASE_ADDRESS           (0x43B01C00UL)
#define LLCE_FIFO_50_BASE_ADDRESS           (0x43B02000UL)
#define LLCE_FIFO_51_BASE_ADDRESS           (0x43B02400UL)
#define LLCE_FIFO_52_BASE_ADDRESS           (0x43B02800UL)
#define LLCE_FIFO_53_BASE_ADDRESS           (0x43B02C00UL)
#define LLCE_FIFO_54_BASE_ADDRESS           (0x43B03000UL)
#define LLCE_FIFO_55_BASE_ADDRESS           (0x43B03400UL)
#define LLCE_FIFO_56_BASE_ADDRESS           (0x43B03800UL)
#define LLCE_FIFO_57_BASE_ADDRESS           (0x43B03C00UL)
#define LLCE_FIFO_58_BASE_ADDRESS           (0x43B04000UL)
#define LLCE_FIFO_59_BASE_ADDRESS           (0x43B04400UL)
#define LLCE_FIFO_60_BASE_ADDRESS           (0x43B04800UL)
#define LLCE_FIFO_61_BASE_ADDRESS           (0x43B04C00UL)
#define LLCE_FIFO_62_BASE_ADDRESS           (0x43B05000UL)
#define LLCE_FIFO_63_BASE_ADDRESS           (0x43B08000UL)
#define LLCE_FIFO_64_BASE_ADDRESS           (0x43B08400UL)
#define LLCE_FIFO_65_BASE_ADDRESS           (0x43B08800UL)
#define LLCE_FIFO_66_BASE_ADDRESS           (0x43B08C00UL)
#define LLCE_FIFO_67_BASE_ADDRESS           (0x43B09000UL)
#define LLCE_FIFO_68_BASE_ADDRESS           (0x43B09400UL)
#define LLCE_FIFO_69_BASE_ADDRESS           (0x43B09800UL)
#define LLCE_FIFO_70_BASE_ADDRESS           (0x43B09C00UL)
#define LLCE_FIFO_71_BASE_ADDRESS           (0x43B0A000UL)
#define LLCE_FIFO_72_BASE_ADDRESS           (0x43B0A400UL)
#define LLCE_FIFO_73_BASE_ADDRESS           (0x43B0A800UL)
#define LLCE_FIFO_74_BASE_ADDRESS           (0x43B0AC00UL)
#define LLCE_FIFO_75_BASE_ADDRESS           (0x43B0B000UL)
#define LLCE_FIFO_76_BASE_ADDRESS           (0x43B0B400UL)
#define LLCE_FIFO_77_BASE_ADDRESS           (0x43B0B800UL)
#define LLCE_FIFO_78_BASE_ADDRESS           (0x43B0BC00UL)
#define LLCE_FIFO_79_BASE_ADDRESS           (0x43B0C000UL)
#define LLCE_FIFO_80_BASE_ADDRESS           (0x43B0C400UL)
#define LLCE_FIFO_81_BASE_ADDRESS           (0x43B0C800UL)
#define LLCE_FIFO_82_BASE_ADDRESS           (0x43B0CC00UL)
#define LLCE_FIFO_83_BASE_ADDRESS           (0x43B0D000UL)
#define LLCE_FIFO_84_BASE_ADDRESS           (0x43B10000UL)
#define LLCE_FIFO_85_BASE_ADDRESS           (0x43B10400UL)
#define LLCE_FIFO_86_BASE_ADDRESS           (0x43B10800UL)
#define LLCE_FIFO_87_BASE_ADDRESS           (0x43B10C00UL)
#define LLCE_FIFO_88_BASE_ADDRESS           (0x43B11000UL)
#define LLCE_FIFO_89_BASE_ADDRESS           (0x43B11400UL)
#define LLCE_FIFO_90_BASE_ADDRESS           (0x43B11800UL)
#define LLCE_FIFO_91_BASE_ADDRESS           (0x43B11C00UL)
#define LLCE_FIFO_92_BASE_ADDRESS           (0x43B12000UL)
#define LLCE_FIFO_93_BASE_ADDRESS           (0x43B12400UL)
#define LLCE_FIFO_94_BASE_ADDRESS           (0x43B12800UL)
#define LLCE_FIFO_95_BASE_ADDRESS           (0x43B12C00UL)
#define LLCE_FIFO_96_BASE_ADDRESS           (0x43B13000UL)
#define LLCE_FIFO_97_BASE_ADDRESS           (0x43B13400UL)
#define LLCE_FIFO_98_BASE_ADDRESS           (0x43B13800UL)
#define LLCE_FIFO_99_BASE_ADDRESS           (0x43B13C00UL)
#define LLCE_FIFO_100_BASE_ADDRESS          (0x43B14000UL)
#define LLCE_FIFO_101_BASE_ADDRESS          (0x43B14400UL)
#define LLCE_FIFO_102_BASE_ADDRESS          (0x43B14800UL)
#define LLCE_FIFO_103_BASE_ADDRESS          (0x43B14C00UL)
#define LLCE_FIFO_104_BASE_ADDRESS          (0x43B15000UL)
#define LLCE_GENERIC_FIFO_0_BASE_ADDRESS    (0x43A12000UL)
#define LLCE_GENERIC_FIFO_1_BASE_ADDRESS    (0x43A12400UL)
#define LLCE_GENERIC_FIFO_2_BASE_ADDRESS    (0x43A12800UL)
#define LLCE_GENERIC_FIFO_3_BASE_ADDRESS    (0x43A12C00UL)


/* Specific FIFOs base address calculation macros. */
#define LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo)                           \
    ((uint32)(LLCE_GENERIC_FIFO_BASEADDR +                                     \
              ((uint32)(u8GenFfo) * (uint32)0x400U))) 

#define LLCE_GENERIC_FIFO_CONFIG(u8GenFfo)                                     \
    ((uint32)(LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo)))
#define LLCE_GENERIC_FIFO_STATUS0(u8GenFfo)                                    \
    ((uint32)(LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo) + 0x04U))
#define LLCE_GENERIC_FIFO_STATUS1(u8GenFfo)                                    \
    ((uint32)(LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo) + 0x08U))
#define LLCE_GENERIC_FIFO_IER(u8GenFfo)                                        \
    ((uint32)(LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo) + 0x0CU))
#define LLCE_GENERIC_FIFO_ILR(u8GenFfo)                                        \
    ((uint32)(LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo) + 0x10U))
#define LLCE_GENERIC_FIFO_PUSH0(u8GenFfo)                                      \
    ((uint32)(LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo) + 0x14U))
#define LLCE_GENERIC_FIFO_POP0(u8GenFfo)                                       \
    ((uint32)(LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo) + 0x24U))
#define LLCE_GENERIC_FIFO_FMR(u8GenFfo)                                        \
    ((uint32)(LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo) + 0x34U))

#define LLCE_FIFO_CONFIG(u32BaseAddr) ((uint32)(u32BaseAddr))
#define LLCE_FIFO_STATUS0(u32BaseAddr) ((uint32)(u32BaseAddr + 0x04U))
#define LLCE_FIFO_STATUS1(u32BaseAddr) ((uint32)(u32BaseAddr + 0x08U))
#define LLCE_FIFO_IER(u32BaseAddr) ((uint32)(u32BaseAddr + 0x0CU))
#define LLCE_FIFO_ILR(u32BaseAddr) ((uint32)(u32BaseAddr + 0x10U))
#define LLCE_FIFO_PUSH0(u32BaseAddr) ((uint32)(u32BaseAddr + 0x14U))
#define LLCE_FIFO_POP0(u32BaseAddr) ((uint32)(u32BaseAddr + 0x24U))
#define LLCE_FIFO_FMR(u32BaseAddr) ((uint32)(u32BaseAddr + 0x34U))

#define LLCE_FIFO_BLRIN_BASE_ADDRESS(u8HwCtrl)                                 \
    (Llce_Can_u32BlrinBaseAddress[u8HwCtrl])
#define LLCE_FIFO_RXOUT_BASE_ADDRESS(u8HwCtrl)                                 \
    (Llce_Can_u32RxoutBaseAddress[u8HwCtrl])
#define LLCE_FIFO_TXACK_BASE_ADDRESS(u8HwCtrl)                                 \
    (Llce_Can_u32TxackBaseAddress[u8HwCtrl])
#define LLCE_FIFO_BLROUT_BASE_ADDRESS(u8HwCtrl)                                \
    (Llce_Can_u32BlroutBaseAddress[u8HwCtrl])

#define LLCE_NOTIF_FIFO0_BASE_ADDRESS(u8HostCore)                              \
    (Llce_Can_u32NotifFifo0BaseAddress[u8HostCore])
#define LLCE_NOTIF_FIFO1_BASE_ADDRESS(u8HostCore)                              \
    (Llce_Can_u32NotifFifo1BaseAddress[u8HostCore])

#define LLCE_FIFO_RXIN_BASE_ADDRESS(u8HostCore)                                \
    (Llce_Can_u32RxinBaseAddress[u8HostCore])
#define LLCE_FIFO_CMD_BASE_ADDRESS(u8HostCore)                                 \
    (Llce_Can_u32CmdBaseAddress[u8HostCore])

#define LLCE_FIFO_RXINLOG_BASE_ADDRESS() (Llce_Can_u32RxinLogBaseAddress[0])
#define LLCE_FIFO_RXOUTLOG_BASE_ADDRESS() (Llce_Can_u32RxoutLogBaseAddress[0])

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

#endif /* LLCE_FIFOINTERFACE_H */

/** @} */
