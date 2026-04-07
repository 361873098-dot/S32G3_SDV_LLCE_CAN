/**
 *   @file    Llce_InterfaceCanConfig.h
 *
 *   @brief LLCE defines used to configure the LLCE firmware and interface
 *   @details LLCE  defines used to configure the LLCE firmware and interface.
 *                  Those configuration parameters are used both by LLCE
 *                  firmware and host software.
 *
 *
 *   @addtogroup Llce_configuration LLCE precompile configuration parameters
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

#ifndef LLCE_INTERFACECONFIG_H
#define LLCE_INTERFACECONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __DOXYGEN__
/**
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused
 * macro declarations Some macros are used either in FW or driver, or provided
 * as API
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.3, A project should not contain unused
 * type declarations. Some type declarations are used either in FW or driver, or
 * provided as API
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.1, Identifiers (internal and external)
 * shall not rely on the significance of more than 31 characters. The used
 * compilers use more than 31 chars for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope
 * and name space shall be distinct. The used compilers use more than 31 chars
 * for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
 * The used compilers use more than 31 chars for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from
 * macro names. The identifier clash is between macro identifiers. Therefore,
 * this rule is incorrectly reported by the tool.
 */
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/
#include "Llce_RegAccess.h"
#include "Llce_InterfaceFwMgr.h"
#include "Llce_Sema42.h"

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

/* LLCE configuration parameters.*/
/**
 * @brief Default controller ID needed by the host 0 interface in order to
 * transmit INIT_PLATFORM and DEINIT_PLATFORM commands from host to LLCE.
 */
#define LLCE_CAN_CONFIG_DEFAULT_CAN_CTRL_HOST0_U8 ((uint8)0U)
/**
 * @brief Default controller ID needed by the host 1 interface in order to
 * transmit INIT_PLATFORM and DEINIT_PLATFORM commands from host to LLCE.
 */
#define LLCE_CAN_CONFIG_DEFAULT_CAN_CTRL_HOST1_U8 ((uint8)8U)

/**
 * @brief Maximum number of notifications which can be reported by LLCE
 * to host.
 */
#define LLCE_CAN_CONFIG_NOTIF_TABLE_SIZE (17U)
/**
 * @brief Maximum buffer size used to store the CAN FD frame payload.
 * See \link Llce_Can_MbType \endlink
 */
#define LLCE_CAN_CONFIG_PAYLOAD_MAX_SIZE (64U)
/**
 * @brief Maximum buffer size used to store the short CAN FD frame payload.
 * See \link Llce_Can_ShortMbType \endlink
 */
#define LLCE_CAN_CONFIG_SHORT_PAYLOAD_MAX_SIZE (8U)
/**
 * @brief Maximum number of hardware controllers usable inside LLCE.
 * See \link Llce_Can_InitCmdType \endlink
 */
#define LLCE_CAN_CONFIG_MAXCTRL_COUNT (16U)
/**
 * @brief Maximum number of polling classes usable inside LLCE.
 * A polling class is used to tie together multiple filters which
 * report the received frames in polling.
 * See \link Llce_Can_InitCmdType \endlink
 */
#define LLCE_CAN_MAX_POLLING_CLASSES (6U)

/**
 * @brief Maximum number of transmission message buffers.
 * See \link Llce_Can_TxMbDescriptorType \endlink
 */
#define LLCE_CAN_CONFIG_MAXTXMB (256U)
/**
 * @brief Maximum number of 64B reception message buffers.
 * Note: 32 from those are reserved
 * for internal usage and are not available to the host.
 * See \link Llce_Can_RxMbDescriptorType \endlink
 */
#define LLCE_CAN_CONFIG_MAXRXMB (1732U)

/**
 * @brief Maximum number of 8B reception message buffers.
 * for internal usage and are not available to the host.
 * See \link Llce_Can_RxMbDescriptorType \endlink
 */
#define LLCE_CAN_CONFIG_MAX_SHORTRXMB (2396U)


/**
 * @brief Number of AF descriptors reserved for each
 * internal path within LLCE frame routing
*/
#define LLCE_CAN_CONFIG_MAXAFRXMB (256U)
#define LLCE_CAN_CONFIG_MAXAFTXMB (256U)
#define LLCE_CAN_CONFIG_MAXAFFRMB (256U)

/**
 * @brief Maximum number of standard filters which can be configured using
 * using a single command. Multiple commands can be executed when more filters
 * are needed.
 * See \link Llce_Can_ReceiveFilterType \endlink
 */
#define LLCE_CAN_CONFIG_MAX_FILTERS_COUNT ((uint16)20U)
/**
 * @brief Number of entries of the circular buffer used to send ack information
 * from TX core to host core. There is 1 extra buffer for each interface for
 * consistency purpose.
 */
#define LLCE_CAN_CONFIG_MAX_TXACKINFO ((uint16)(512U + LLCE_CAN_RX_TX_INTERFACES))
/**
 * @brief Mask used to get the right data from FIFOs.
 * See FMR config register of FIFO.
 */
#define LLCE_CAN_CONFIG_FIFO_FIXED_MASK_U32 ((uint32)0x0007FFFF)
/**
 * @brief Maximum number of advanced filters which can be configured using a
 * single command. Multiple commands can be executed when more filters are
 * needed.
 * See \link Llce_Can_AdvancedFilterType \endlink
 */
#define LLCE_CAN_CONFIG_ADVANCED_FILTERS_COUNT (8U)
/**
 * @brief Shared memory size allocated for each channel for
 * commands exchange.
 */
#define LLCE_CAN_CONFIG_CTRL_SHARED_MEMORY_SIZE ((uint32)0x400)
/**
 * @brief Reserved value in order to detect if an advanced filter entry
 * is not used.
 */
#define LLCE_CAN_ADVANCED_FILTER_NOT_USED (0xFFU)
/** @brief Interface ID used by different hosts for multihost scenarios. */
#define LLCE_CAN_HIF0 (0U)
/** @brief Interface ID used by different hosts for multihost scenarios. */
#define LLCE_CAN_HIF1 (1U)
/** @brief Number of interfaces which can be used by host cores. */
#define LLCE_CAN_CONFIG_HIF_COUNT (2U)
/** @brief Number of semaphores for each HIF. */
#define LLCE_CAN_CONFIG_IER_SEMA4_COUNT   (2U)
/** @brief Index of FIFO_RXOUT inside Can_Sema4_Ier array. */
#define LLCE_FIFO_RXOUT_INDEX             (0U)
/** @brief Index of FIFO_TXACK inside Can_Sema4_Ier array. */
#define LLCE_FIFO_TXACK_INDEX             (1U)
/** @brief Number of FIFOs used by first HIF. */
#define LLCE_CAN_HIF0_FIFO_CNT            (8U)
/** @brief Semaphore core domain */
#define LLCE_HOST_CORE_SEMA42_DOMAIN         (LLCE_SEMA42_GR_GTFSM_9)
/** @brief No result from RxLut2 */
#define LLCE_RXLUT2_NO_RESULT             ((uint16)0xFFFFU)


/* LIN defines */
/** @brief Maximum buffer size used to store the LIN frame payload */
#define LLCE_LIN_CONFIG_PAYLOAD_MAX_SIZE (8U)
/** @brief Maximum number of LIN transmission buffers */
#define LLCE_LIN_CONFIG_MAXTXBUFF (64U)
/** @brief Maximum number of LIN reception buffers */
#define LLCE_LIN_CONFIG_MAXRXBUFF (64U)

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
 
void DisableFifoInterrupts (uint8 u8FifoInterface, uint8 u8Hif);
void EnableFifoInterrupts (uint8 u8FifoInterface, uint8 u8Hif);

#ifdef __cplusplus
}
#endif

#endif /* LLCE_FIFO_H */

/** @} */
