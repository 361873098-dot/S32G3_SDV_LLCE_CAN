/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   Copyright 2020-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef MSCM_IP_CFG_DEFINES_H
#define MSCM_IP_CFG_DEFINES_H

/**
*   @file Mscm_Ip_Cfg_Defines.h
*
*   @addtogroup MSCM_IP MSCM IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
/**
 * Include specific header file
 */
#include "StandardTypes.h" 
#include "S32G399A_MSCM.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_CFG_DEFINES_VENDOR_ID                          43
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           4
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
#define RM_MSCM_IP_CFG_DEFINES_SW_MAJOR_VERSION                   4
#define RM_MSCM_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define RM_MSCM_IP_CFG_DEFINES_SW_PATCH_VERSION                   2
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief    Core Mask to write MSCM Register */
#define MSCM_IP_CORE_MASK                        (31U)
/** @brief    Development error checking */
#define MSCM_IP_DEV_ERROR_DETECT                (STD_OFF)
/** @brief        Last implemented interrupt routing */
#define MSCM_IP_SPI_MAX                            (230U)
/** @brief        Number of SPI Routing Support */
#define MSCM_IP_SPI_COUNT                        (211U)

/** @brief        SPI Number Configuration */
#define MSCM_MSCM_SERDES_1_MSI_INTERRUPT_TO_M7_A53                                                       (0U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_0                                                              (1U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_1                                                              (2U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_2                                                              (3U)
#define MSCM_MSCM_SERDES_0_MSI_INTERRUPT_TO_M7_A53                                                       (4U)
#define MSCM_CTI_0                                                                                       (5U)
#define MSCM_CTI_1                                                                                       (6U)
#define MSCM_MCM                                                                                         (7U)
#define MSCM_EDMA_0_CH_0_TO_15                                                                           (8U)
#define MSCM_EDMA_0_CH_16_TO_31                                                                          (9U)
#define MSCM_EDMA_0_ERROR_INTERRUPT_REQUEST                                                              (10U)
#define MSCM_EDMA_1_CH_0_TO_15                                                                           (11U)
#define MSCM_EDMA_1_CH_16_TO_31                                                                          (12U)
#define MSCM_EDMA_1_ERROR_INTERRUPT_REQUEST                                                              (13U)
#define MSCM_SWT_0                                                                                       (14U)
#define MSCM_SWT_1                                                                                       (15U)
#define MSCM_SWT_2                                                                                       (16U)
#define MSCM_SWT_3                                                                                       (17U)
#define MSCM_SWT_4                                                                                       (18U)
#define MSCM_SWT_5                                                                                       (19U)
#define MSCM_SWT_6                                                                                       (20U)
#define MSCM_SWT_7                                                                                       (21U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_3                                                              (22U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_4                                                              (23U)
#define MSCM_STM_0                                                                                       (24U)
#define MSCM_STM_1                                                                                       (25U)
#define MSCM_STM_2                                                                                       (26U)
#define MSCM_STM_3                                                                                       (27U)
#define MSCM_STM_4                                                                                       (28U)
#define MSCM_STM_5                                                                                       (29U)
#define MSCM_STM_6                                                                                       (30U)
#define MSCM_STM_7                                                                                       (31U)
#define MSCM_QUADSPI_ORED_INTERRUPT_VIA_OTC                                                              (32U)
#define MSCM_QUADSPI_FLASH_A_ERROR_INTERRUPT_VIA_OTC                                                     (33U)
#define MSCM_QUADSPI_FLASH_B_ERROR_INTERRUPT_VIA_OTC                                                     (34U)
#define MSCM_STCU2                                                                                       (35U)
#define MSCM_USDHC                                                                                       (36U)
#define MSCM_FLEXCAN_0_CAN_BUS_WENT_TO_BUS_OFF_STATE                                                     (37U)
#define MSCM_FLEXCAN_0_ERRORS_DETECTED_ON_CAN_BUS                                                        (38U)
#define MSCM_FLEXCAN_0_MESSAGE_BUFFER_INTERRUPT_LINE_0_TO_7                                              (39U)
#define MSCM_FLEXCAN_0_LOGICAL_OR_OF_MESSAGE_BUFFER_INTERRUPT_LINES_127_TO_8                             (40U)
#define MSCM_FLEXCAN_1_CAN_BUS_WENT_TO_BUS_OFF_STATE                                                     (41U)
#define MSCM_FLEXCAN_1_ERRORS_DETECTED_ON_CAN_BUS                                                        (42U)
#define MSCM_FLEXCAN_1_MESSAGE_BUFFER_INTERRUPT_LINE_0_TO_7                                              (43U)
#define MSCM_FLEXCAN_1_LOGICAL_OR_OF_MESSAGE_BUFFER_INTERRUPT_LINES_127_TO_8                             (44U)
#define MSCM_FLEXCAN_2_CAN_BUS_WENT_TO_BUS_OFF_STATE                                                     (45U)
#define MSCM_FLEXCAN_2_ERRORS_DETECTED_ON_CAN_BUS                                                        (46U)
#define MSCM_FLEXCAN_2_MESSAGE_BUFFER_INTERRUPT_LINE_0_TO_7                                              (47U)
#define MSCM_FLEXCAN_2_LOGICAL_OR_OF_MESSAGE_BUFFER_INTERRUPT_LINES_127_TO_8                             (48U)
#define MSCM_FLEXCAN_3_CAN_BUS_WENT_TO_BUS_OFF_STATE                                                     (49U)
#define MSCM_FLEXCAN_3_ERRORS_DETECTED_ON_CAN_BUS                                                        (50U)
#define MSCM_FLEXCAN_3_MESSAGE_BUFFER_INTERRUPT_LINE_0_TO_7                                              (51U)
#define MSCM_FLEXCAN_3_LOGICAL_OR_OF_MESSAGE_BUFFER_INTERRUPT_LINES_127_TO_8                             (52U)
#define MSCM_PIT_0                                                                                       (53U)
#define MSCM_PIT_1                                                                                       (54U)
#define MSCM_FTM_0                                                                                       (55U)
#define MSCM_FTM_1                                                                                       (56U)
#define MSCM_GMAC_0_COMMON_INTERRUPT                                                                     (57U)
#define MSCM_GMAC_0_CH0_TX                                                                               (58U)
#define MSCM_GMAC_0_CH0_RX                                                                               (59U)
#define MSCM_GMAC_0_CH1_TX                                                                               (60U)
#define MSCM_GMAC_0_CH1_RX                                                                               (61U)
#define MSCM_GMAC_0_CH2_TX                                                                               (62U)
#define MSCM_GMAC_0_CH2_RX                                                                               (63U)
#define MSCM_GMAC_0_CH3_TX                                                                               (64U)
#define MSCM_GMAC_0_CH3_RX                                                                               (65U)
#define MSCM_GMAC_0_CH4_TX                                                                               (66U)
#define MSCM_GMAC_0_CH4_RX                                                                               (67U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_5                                                              (68U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_6                                                              (69U)
#define MSCM_SAR_ADC_0                                                                                   (70U)
#define MSCM_SAR_ADC_1                                                                                   (71U)
#define MSCM_FLEXRAY_LRAM_DRAM_NON_CORRECTED_ERROR_INTERRUPT                                             (72U)
#define MSCM_FLEXRAY_LRAM_DRAM_CORRECTED_ERROR_INTERRUPT                                                 (73U)
#define MSCM_FLEXRAY_RECEIVE_FIFO_CHA_NOT_EMPTY_INTERRUPT                                                (74U)
#define MSCM_FLEXRAY_RECEIVE_FIFO_CHB_NOT_EMPTY_INTERRUPT                                                (75U)
#define MSCM_FLEXRAY_WAKEUP_INTERRUPT                                                                    (76U)
#define MSCM_FLEXRAY_COMBINED_PROTOCOL_STATUS_AND_ERROR_INTERRUPT                                        (77U)
#define MSCM_FLEXRAY_COMBINED_CHI_ERROR_INTERRUPT                                                        (78U)
#define MSCM_FLEXRAY_COMBINED_TRANSMIT_MESSAGE_BUFFER_INTERRUPT                                          (79U)
#define MSCM_FLEXRAY_COMBINED_RECEIVE_MESSAGE_BUFFER_INTERRUPT                                           (80U)
#define MSCM_FLEXRAY_COMBINED_MODULE_INTERRUPT                                                           (81U)
#define MSCM_LINFLEXD_0                                                                                  (82U)
#define MSCM_LINFLEXD_1                                                                                  (83U)
#define MSCM_LINFLEXD_2                                                                                  (84U)
#define MSCM_SPI_0                                                                                       (85U)
#define MSCM_SPI_1                                                                                       (86U)
#define MSCM_SPI_2                                                                                       (87U)
#define MSCM_SPI_3                                                                                       (88U)
#define MSCM_SPI_4                                                                                       (89U)
#define MSCM_SPI_5                                                                                       (90U)
#define MSCM_I2C_0                                                                                       (92U)
#define MSCM_I2C_1                                                                                       (93U)
#define MSCM_I2C_2                                                                                       (94U)
#define MSCM_I2C_3                                                                                       (95U)
#define MSCM_I2C_4                                                                                       (96U)
#define MSCM_MC_RGM                                                                                      (98U)
#define MSCM_FCCU_ALARM_STATE                                                                            (100U)
#define MSCM_FCCU_MISCELLANEOUS_CONDITIONS                                                               (101U)
#define MSCM_SBSW                                                                                        (102U)
#define MSCM_HSE_ORED_TX_INTERRUPT_TO_MU_0                                                               (103U)
#define MSCM_HSE_ORED_RX_INTERRUPT_TO_MU_0                                                               (104U)
#define MSCM_HSE_ORED_GENERAL_PURPOSE_INTERRUPT_REQUEST_TO_MU_0                                          (105U)
#define MSCM_HSE_ORED_TX_INTERRUPT_TO_MU_1                                                               (106U)
#define MSCM_HSE_ORED_RX_INTERRUPT_TO_MU_1                                                               (107U)
#define MSCM_HSE_ORED_GENERAL_PURPOSE_INTERRUPT_REQUEST_TO_MU_1                                          (108U)
#define MSCM_HSE_ORED_TX_INTERRUPT_TO_MU_2                                                               (109U)
#define MSCM_HSE_ORED_RX_INTERRUPT_TO_MU_2                                                               (110U)
#define MSCM_HSE_ORED_GENERAL_PURPOSE_INTERRUPT_REQUEST_TO_MU_2                                          (111U)
#define MSCM_HSE_ORED_TX_INTERRUPT_TO_MU_3                                                               (112U)
#define MSCM_HSE_ORED_RX_INTERRUPT_TO_MU_3                                                               (113U)
#define MSCM_HSE_ORED_GENERAL_PURPOSE_INTERRUPT_REQUEST_TO_MU_3                                          (114U)
#define MSCM_DDR_0_ONE_FULL_ADDRESS_RANGE_SWEEP_OR_COUNTER_OVERFLOW                                      (115U)
#define MSCM_DDR_0_PHY_ADDRESS_DECODING_ERROR_INSIDE_DDR_SS_OR_PHY_INTERRUPT                             (116U)
#define MSCM_CTU_FIFO0_TO_FIFO3_FULL_OR_EMPTY_OR_OVERFLOW_OR_OVERRUN_INTERRUPT                           (117U)
#define MSCM_CTU_MASTER_RELOAD_INTERRUPT_OR_TRIGGER_0_TO_7_OR_ADC_COMMAND_INTERRUPT                      (118U)
#define MSCM_CTU_ERROR_INTERRUPT                                                                         (119U)
#define MSCM_TMU                                                                                         (120U)
#define MSCM_RTC                                                                                         (121U)
#define MSCM_SERDES_0_LOGICAL_OR_OF_SERDES_DMA_INTERRUPTS                                                (123U)
#define MSCM_SERDES_0_LINK_REQUEST_STATUS_INTERRUPT                                                      (124U)
#define MSCM_SERDES_0_DSP_AXI_MSI_INTERRUPT_DETECTED                                                     (125U)
#define MSCM_SERDES_0_PHY_LINK_DOWN_INTERRUPT                                                            (126U)
#define MSCM_SERDES_0_PHY_LINK_UP_INTERRUPT                                                              (127U)
#define MSCM_SERDES_0_INTA_MESSAGE_RECEIVED                                                              (128U)
#define MSCM_SERDES_0_INTB_MESSAGE_RECEIVED                                                              (129U)
#define MSCM_SERDES_0_INTC_MESSAGE_RECEIVED                                                              (130U)
#define MSCM_SERDES_0_INTD_MESSAGE_RECEIVED                                                              (131U)
#define MSCM_SERDES_0_MISCELLANEOUS_INTERRUPT_GENERATED_BY_SERDES_SUBSYSTEM                              (132U)
#define MSCM_SERDES_0_PCS_INTERRUPT                                                                      (133U)
#define MSCM_SERDES_0_TLP_REQUEST_NOT_COMPLETE_WITHIN_THE_EXPECTED_TIME_WINDOW                           (134U)
#define MSCM_OTC_INT0_OS_SLOT_0                                                                          (135U)
#define MSCM_OTC_INT1_OS_SLOT_0                                                                          (136U)
#define MSCM_OTC_INT0_OS_SLOT_1                                                                          (137U)
#define MSCM_OTC_INT1_OS_SLOT_1                                                                          (138U)
#define MSCM_OTC_INT0_OS_SLOT_2                                                                          (139U)
#define MSCM_OTC_INT1_OS_SLOT_2                                                                          (140U)
#define MSCM_OTC_INT0_OS_SLOT_3                                                                          (141U)
#define MSCM_OTC_INT1_OS_SLOT_3                                                                          (142U)
#define MSCM_OTC_INT0_OS_SLOT_4                                                                          (143U)
#define MSCM_OTC_INT1_OS_SLOT_4                                                                          (144U)
#define MSCM_OTC_CONTROLLER_NOTIFICATION_INTERRUPT                                                       (145U)
#define MSCM_OTC_CONTROLLER_ERROR_INTERRUPT                                                              (146U)
#define MSCM_OTC_SOFTWARE_NOTIFICATION_INTERRUPT                                                         (147U)
#define MSCM_OTC_REGISTER_ACCESS_ERROR_INTERRUPT                                                         (148U)
#define MSCM_OTC_AUTHENTICATION_REQUEST_INTERRUPT                                                        (149U)
#define MSCM_OTC_CRITICAL_ERROR_INTERRUPT                                                                (150U)
#define MSCM_CORTEX_A53_L2_L2_RAM_DOUBLE_BIT_ECC_ERROR_FOR_CLUSTER0                                      (151U)
#define MSCM_CORTEX_A53_L2_CLUSTER0_CORE1_LIVELOCK_ERROR                                                 (152U)
#define MSCM_CORTEX_A53_L2_L2_RAM_DOUBLE_BIT_ECC_ERROR_FOR_CLUSTER1                                      (153U)
#define MSCM_CORTEX_A53_L2_CLUSTER1_CORE1_LIVELOCK_ERROR                                                 (154U)
#define MSCM_JDC                                                                                         (155U)
#define MSCM_SWT_8                                                                                       (156U)
#define MSCM_SWT_9                                                                                       (157U)
#define MSCM_SWT_10                                                                                      (158U)
#define MSCM_SWT_11                                                                                      (159U)
#define MSCM_STM_8                                                                                       (160U)
#define MSCM_STM_9                                                                                       (161U)
#define MSCM_STM_10                                                                                      (162U)
#define MSCM_STM_11                                                                                      (163U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_7                                                              (164U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_8                                                              (165U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_9                                                              (166U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_10                                                             (167U)
#define MSCM_MSCM_CPU_TO_M7_A53_INTERRUPT_11                                                             (168U)
#define MSCM_LLCE_HOST_INTERRUPT_FROM_CORE0                                                              (170U)
#define MSCM_LLCE_HOST_INTERRUPT_FROM_CORE1                                                              (171U)
#define MSCM_LLCE_HOST_INTERRUPT_FROM_CORE2                                                              (172U)
#define MSCM_LLCE_HOST_INTERRUPT_FROM_CORE3                                                              (173U)
#define MSCM_LLCE_FIFO_ICSR14                                                                            (174U)
#define MSCM_LLCE_FIFO_ICSR15                                                                            (175U)
#define MSCM_LLCE_FIFO_ICSR16                                                                            (176U)
#define MSCM_LLCE_FIFO_ICSR17                                                                            (177U)
#define MSCM_LLCE_FIFO_ICSR18                                                                            (178U)
#define MSCM_LLCE_FIFO_ICSR19                                                                            (179U)
#define MSCM_LLCE_FIFO_ICSR20                                                                            (180U)
#define MSCM_LLCE_FIFO_ICSR21                                                                            (181U)
#define MSCM_LLCE_FIFO_ICSR22                                                                            (182U)
#define MSCM_LLCE_FIFO_ICSR23                                                                            (183U)
#define MSCM_LLCE_FIFO_ICSR24                                                                            (184U)
#define MSCM_LLCE_FIFO_ICSR25                                                                            (185U)
#define MSCM_LLCE_FIFO_ICSR26                                                                            (186U)
#define MSCM_LLCE_FIFO_ICSR27                                                                            (187U)
#define MSCM_PFE_CH0_INTERRUPT_SIGNAL_STATUS                                                             (190U)
#define MSCM_PFE_CH1_INTERRUPT_SIGNAL_STATUS                                                             (191U)
#define MSCM_PFE_CH2_INTERRUPT_SIGNAL_STATUS                                                             (192U)
#define MSCM_PFE_CH3_INTERRUPT_SIGNAL_STATUS                                                             (193U)
#define MSCM_PFE_BMU1_OR_BMU2_INTERRUPT                                                                  (194U)
#define MSCM_PFE_HIF_NO_COPY                                                                             (195U)
#define MSCM_PFE_UTILPE_OR_GPT_INTERRUPT                                                                 (196U)
#define MSCM_PFE_PMT_INTERRUPT                                                                           (197U)
#define MSCM_PFE_LOGICAL_OR_ALL_INTERRUPTS_FROM_MMC_AND_PCS_AND_MAC                                      (198U)
#define MSCM_STM_TS                                                                                      (204U)
#define MSCM_SIUL1_                                                                                      (210U)
#define MSCM_USB0_OTG_CORE_INTERRUPT                                                                     (211U)
#define MSCM_USB0_OTG_WAKEUP_INTERRUPT                                                                   (212U)
#define MSCM_WKPU                                                                                        (213U)
#define MSCM_SERDES_1_LOGICAL_OR_OF_SERDES_DMA_INTERRUPTS                                                (214U)
#define MSCM_SERDES_1_LINK_REQUEST_STATUS_INTERRUPT                                                      (215U)
#define MSCM_SERDES_1_DSP_AXI_MSI_INTERRUPT_DETECTED                                                     (216U)
#define MSCM_SERDES_1_PHY_LINK_DOWN_INTERRUPT                                                            (217U)
#define MSCM_SERDES_1_PHY_LINK_UP_INTERRUPT                                                              (218U)
#define MSCM_SERDES_1_INTA_MESSAGE_RECEIVED                                                              (219U)
#define MSCM_SERDES_1_INTB_MESSAGE_RECEIVED                                                              (220U)
#define MSCM_SERDES_1_INTC_MESSAGE_RECEIVED                                                              (221U)
#define MSCM_SERDES_1_INTD_MESSAGE_RECEIVED                                                              (222U)
#define MSCM_SERDES_1_MISCELLANEOUS_INTERRUPT_GENERATED_BY_SERDES_SUBSYSTEM                              (223U)
#define MSCM_SERDES_1_PCS_INTERRUPT                                                                      (224U)
#define MSCM_SERDES_1_TLP_REQUEST_NOT_COMPLETE_WITHIN_THE_EXPECTED_TIME_WINDOW                           (225U)
#define MSCM_XRDC_0                                                                                      (229U)
#define MSCM_XRDC_1                                                                                      (230U)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MSCM_IP_CFG_DEFINES_H */

