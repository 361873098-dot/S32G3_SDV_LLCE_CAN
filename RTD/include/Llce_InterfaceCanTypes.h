/**
 *   @file    Llce_InterfaceCanTypes.h
 *
 *   @brief   LLCE data structures used to implement the LLCE interface
 *   @details This file contains data structures used to implement the LLCE
 *            interface
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
/*==================================================================================================
==================================================================================================*/
#ifndef LLCE_INTERFACECANTYPES_H
#define LLCE_INTERFACECANTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __DOXYGEN__
/**
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.3, A project should not contain unused
 * type declarations Some types are used either in FW or driver, or provided as
 * API
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused
 * macro declarations Some macros are used either in FW or driver, or provided
 * as API
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
 *
 * @section Llce_InterfaceCanTypes_h_REF_1
 * Violates MISRA 2012 Required Rule 21.1, #define and #undef shall not be used
 * on a reserved identifier or reserved macro name. The #define is enabled only
 * when PC-LINT analyses the code as a workaround for a bug in the tool (it
 * doesn't recognize structure name when __attribute__ keyword prefixes it).
 *
 * @section Llce_InterfaceCanTypes_h_REF_2
 * Violates MISRA 2012 Advisory Rule 4.9, A function should be used in
 * preference to a function-like macro where they are interchangeable. The
 * #define is enabled only when PC-LINT analyses the code as a workaround for a
 * bug in the tool (it doesn't recognize structure name when __attribute__
 * keyword prefixes it).
 */
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/
#ifdef CHECK_ABI_COMPATIBILITY
#pragma ABICHECK stop
#endif

#include "Llce_RegAccess.h"
#include "Llce_InterfaceCanConfig.h"
#include "Llce_FwVersion.h"
#include "Llce_InterfaceFwMgr.h"

#ifdef CHECK_ABI_COMPATIBILITY
#pragma ABICHECK start
#endif
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
/**
 * @{
 * @brief Offset bits for NCBT register
 */
#define LLCE_NCBT_NPRESDIV_SHIFT_U8 ((uint8)23U)
#define LLCE_NCBT_NRJW_SHIFT_U8 ((uint8)16U)
#define LLCE_NCBT_NTSEG2_SHIFT_U8 ((uint8)9U)
/**@}*/

/**
 * @{
 * @brief Offset bits for DCBT register
 */
#define LLCE_DCBT_DPRESDIV_SHIFT_U8 ((uint8)23U)
#define LLCE_DCBT_DRJW_SHIFT_U8 ((uint8)16U)
#define LLCE_DCBT_DTSEG2_SHIFT_U8 ((uint8)9U)
/**@}*/

/*==================================================================================================
 *                                CONTROLLER OPTIONS
 ==================================================================================================*/
/**
 * @brief Controller option used by the initialization command in order to
 * inform LLCE firmware that a specific controller shall be initialized.
 * See \link Llce_Can_InitCmdType \endlink
 */
#define LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32 ((uint32)0x10000000U)
/**
 * @brief CAN controller option used to enable reporting of the Protocol
 * Exception errors.
 * See \link Llce_Can_GetStatusCmdType \endlink
 */
#define LLCE_CAN_CONTROLLERCONFIG_PE_EN_U32 ((uint32)0x00040000U)
/** @brief CAN controller option used to enable Timestamp feature. */
#define LLCE_CAN_CONTROLLERCONFIG_TST_END_U32 ((uint32)0x00080000U)
/**
 * @brief CAN controller option used to enable Timestamp feature at the start
 * of the CAN frame.
 */
#define LLCE_CAN_CONTROLLERCONFIG_TST_START_U32 ((uint32)0x00000080U)
/**
 * @brief CAN controller option used to enable Timestamp feature in the start of
 * frame for classical CAN frames and in the res bit for CAN FD frames.
 */
#define LLCE_CAN_CONTROLLERCONFIG_TST_FD_U32 ((uint32)0x00000040U)
/** @brief CAN controller option used to enable Listen-Only mode. */
#define LLCE_CAN_CONTROLLERCONFIG_LOM_EN_U32 ((uint32)0x00100000U)
/** @brief CAN controller option used to enable internal LoopBack mode. */
#define LLCE_CAN_CONTROLLERCONFIG_LPB_EN_U32 ((uint32)0x00200000U)
/** @brief CAN controller option used to enable self-reception mode. */
#define LLCE_CAN_CONTROLLERCONFIG_SRX_EN_U32 ((uint32)0x00400000U)
/**< @brief   CAN controller option used to enable automatic bus-off recovery. */
#define LLCE_CAN_CONTROLLERCONFIG_ABR_EN_U32  ((uint32)0x00000001U) 
/**< @brief   CAN controller option used to enable TX FIFO mode. */
#define LLCE_CAN_CONTROLLERCONFIG_TXFIFO_EN_U32  ((uint32)0x00000002U) 
/**< @brief   CAN controller option used to enable manual bus-off recovery. */
#define LLCE_CAN_CONTROLLERCONFIG_MBR_EN_U32  ((uint32)0x00000004U) 
/**
 * @brief Number of interfaces used for interrupt reporting
 * (one per channel) + number of polling classes.
 */
#define LLCE_CAN_RX_TX_INTERFACES                                              \
    ((uint8)(LLCE_CAN_CONFIG_MAXCTRL_COUNT + LLCE_CAN_MAX_POLLING_CLASSES))
/**
 * @brief Default value in the transmission request informing LLCE that tx
 * confirmation is not needed for that frame.
 */
#define LLCE_CAN_ACK_DISABLED ((uint8)0xADU)
#define LLCE_CAN_PARAM_NOT_USED ((uint8)0xFFU)

/*==================================================================================================
                 DEFINES SHARED BETWEEN HOST AND LLCE
==================================================================================================*/
/** @brief Frame DLC field mask. */
#define LLCE_CAN_MB_DLC_MASK_U32 ((uint32)0x0000000FU)
/** @brief Frame ID field mask. */
#define LLCE_CAN_MB_ID_MASK_U32 ((uint32)0x1FFFFFFFU)
/** @brief Frame FDF field mask. */
#define LLCE_CAN_MB_FDF_U32 ((uint32)0x00008000U)
/** @brief Frame BRS field mask. */
#define LLCE_CAN_MB_BRS_U32 ((uint32)0x00010000U)
/** @brief Frame ESI field mask. */
#define LLCE_CAN_MB_ESI_U32 ((uint32)0x00020000U)
/** @brief Frame IDE field mask. */
#define LLCE_CAN_MB_IDE_U32 ((uint32)0x40000000U)
/** @brief Frame RTR field mask. */
#define LLCE_CAN_MB_RTR_U32 ((uint32)0x80000000U)
/** @brief Frame standard ID field mask. */
#define LLCE_CAN_MB_IDSTD_MASK_U32 ((uint32)0x1FFC0000U)
/** @brief Frame extended ID field mask. */
#define LLCE_CAN_MB_IDEXT_MASK_U32 ((uint32)0x0003FFFFU)
/** @brief Routing feature default configuration. */
#define LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG ((uint32)0x00000000U)
/** @brief Routing feature mask for non-converting frame. */
#define LLCE_CAN_ROUTING_NOCHANGE ((uint32)0x00000001U)
/** @brief Routing feature mask for converting frame (CANFD->CAN). */
#define LLCE_CAN_ROUTING_CAN ((uint32)0x00000002U)
/** @brief Routing feature mask for converting frame (CAN->CANFD). */
#define LLCE_CAN_ROUTING_CANFD ((uint32)0x00000004U)
/** @brief Routing feature mask for id remapping. */
#define LLCE_CAN_ROUTING_ID_REMAPPING_EN ((uint32)0x00000008U)

/** @brief Shift value for extracting FD flag  from CAN frame. */
#define LLCE_CAN_MB_FDF_SHIFT_U32 ((uint32)15U)
/** @brief Shift value for extracting Baud Rate Switch flag from CAN frame. */
#define LLCE_CAN_MB_BRS_SHIFT_U32 ((uint32)16U)
/** @brief Shift value for extracting ESI flag feature from CAN frame. */
#define LLCE_CAN_MB_ESI_SHIFT_U32 ((uint32)17U)
/** @brief Shift value for extracting frame ID from CAN frame. */
#define LLCE_CAN_MB_IDSTD_SHIFT_U32 ((uint32)18U)
/** @brief Shift value for extracting IDE flag from CAN frame. */
#define LLCE_CAN_MB_IDE_SHIFT_U32 ((uint32)30U)
/** @brief Shift value for extracting RTR flag from CAN frame. */
#define LLCE_CAN_MB_RTR_SHIFT_U32 ((uint32)31U)

/** @brief Shift value for extracting precalculated length from CAN frame. */
#define LLCE_CAN_MB_PRECALC_LEN_SHIFT_U32 ((uint32)24U)

/** @brief Constant used to identify a reserved mask id. */
#define LLCE_CAN_FULLCAN_MASK_U32 ((uint32)0xFFFFFFFFU)

/*=========================================================
              DEFINES FOR INTERACTING WITH PFE
=========================================================*/
#define LLCE_CAN2ETH_PFE_EMAC0          (0x0001U)
#define LLCE_CAN2ETH_PFE_EMAC1          (0x0002U)
#define LLCE_CAN2ETH_PFE_EMAC2          (0x0004U)
#define LLCE_CAN2ETH_PFE_HIF0           (0x0008U)
#define LLCE_CAN2ETH_PFE_HIF1           (0x0010U)
#define LLCE_CAN2ETH_PFE_HIF2           (0x0020U)
#define LLCE_CAN2ETH_PFE_HIF3           (0x0040U)
#define LLCE_CAN2ETH_PFE_HIFNOCPY       (0x0080U)
#define LLCE_CAN2ETH_PFE_AUX            (0x0100U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
 * @brief Notification IDs used to interface with LLCE.
 *
 * Notifications send by LLCE to host core.
 **/
typedef enum LLCE__PACKED
{
    /** @brief No error. */
    LLCE_CAN_NOTIF_NOERROR = 0U,
    /** @brief Error related to the common platform area. */
    LLCE_CAN_NOTIF_PLATFORMERROR,
    /** @brief Error related to a specific channel.*/
    LLCE_CAN_NOTIF_CHANNELERROR,
    /** @brief Notification related to changing CAN controller mode.*/
    LLCE_CAN_NOTIF_CTRLMODE,
} Llce_Can_NotificationIdType;

/**
 * @brief Command IDs used to interface with LLCE.
 *
 * Some of those commands are sent by the host to LLCE module and others are
 * sent by LLCE module to the host.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Host initializes LLCE module. */
    LLCE_CAN_CMD_INIT = 0U,
    /** @brief Host deinitializes a specific CAN controller. */
    LLCE_CAN_CMD_DEINIT,
    /** @brief Host sets a baud rate for a specific CAN controller.*/
    LLCE_CAN_CMD_SETBAUDRATE,
    /** @brief Host checks the state for a specific CAN controller.*/
    LLCE_CAN_CMD_GETCONTROLLERMODE,
    /** @brief Host changes the state for a specific CAN controller.*/
    LLCE_CAN_CMD_SETCONTROLLERMODE,
    /**
     * @brief Host requests the recovery from bus-off state
     * transmission of a specific CAN controller.
     */
    LLCE_CAN_CMD_MANUAL_BUSOFF_RECOVERY,
    /**
     * @brief LLCE delivers to the host the content of all status registers
     * of the CAN controller.
     */
    LLCE_CAN_CMD_GETSTATUS,
    /** @brief The host configures multiple filters on the reception side.*/
    LLCE_CAN_CMD_SETFILTER,
    /** @brief The host configures multiple advanced feature filters on reception side*/
    LLCE_CAN_CMD_SETADVANCEDFILTER,
    /** @brief The host enables/disables the already set filter. */
    LLCE_CAN_CMD_SETFILTERENABLESTATUS,
    /** @brief The host invalidates a specific filter.*/
    LLCE_CAN_CMD_REMOVE_FILTER,
    /** @brief Request version string from FW.*/
    LLCE_CAN_CMD_GETFWVERSION,
    /** @brief Host request for platform initialization.*/
    LLCE_CAN_CMD_INIT_PLATFORM,
    /**
     * @brief LLCE internal command request for initialization of
     * common resources.
     */
    LLCE_CAN_CMD_INIT_PLATFORM_COMMON,
    /** @brief Host request for platform deinitialization.*/
    LLCE_CAN_CMD_DEINIT_PLATFORM,
    /**
     * @brief Host request for platform initialization regarding
     * CAN2ETH-ETH2CAN use case.
     */
    LLCE_CAN_CMD_INIT_PFE,
        /**
     * @brief Host request for platform initialization regarding
     * CAN2ETH-ETH2CAN use case using ring buffers generated on host side.
     */
    LLCE_CAN_CMD_INIT_PFE_EXT_RING_BUF,
    /**
     * @brief Host request for platform initialization regarding
     * HSE bridge use case.
     */
    LLCE_CAN_CMD_INIT_HSE,
    /**
     * @brief Host creates a destination to be used by the advanced
     * routing filters.
     */
    LLCE_CAN_CMD_CREATE_AF_DESTINATION,
    /**
     * @brief Host requests the abortion of the lowest priority pending
     * transmission of a specific CAN controller.
     */
    LLCE_CAN_CMD_ABORT_MB,
    /** @brief Custom command to be implemented by user in FDK */
    LLCE_CAN_CMD_CUSTOM,
    /** @brief The host configures multiple filters on the reception side for rxlut2 on g3.*/
    LLCE_CAN_CMD_SETAUXFILTER,
    /** @brief The host requests the addition of a new filter by specifying filter address.*/
    LLCE_CAN_CMD_SETFILTER_AT_ADDRESS,
    /** @brief The host enables or disables a channel in a routing multicast configuration.*/
    LLCE_CAN_CMD_SETCHANNELROUTINGOUTPUTSTATE,
    /** @brief The host enables or disables Can2Eth processing entirely.*/
    LLCE_CAN_CMD_SETCAN2ETHSTATE,
    /** @brief The host enables or disables Eth2Can processing for a format.*/
    LLCE_CAN_CMD_SETETH2CANFORMATSTATE,
    /** @brief The host requests the addition of a new advanced filter by specifying filter address.*/
    LLCE_CAN_CMD_SETADVANCEDFILTER_AT_ADDRESS,
    /** @brief The host enables or disables Can2Pcie processing entirely.*/
    LLCE_CAN_CMD_SETCAN2PCIESTATE,
    /** @brief The host requests all LLCE cores to execute WFI and shut down.*/
    LLCE_CAN_CMD_SHUTDOWN,
    /** @brief Host removes a destination which is used by the advanced routing filters. Stored data of this destination will be lost. */
    LLCE_CAN_CMD_REMOVE_AF_DESTINATION
} Llce_Can_CommandIdType;

/**
 * @brief CAN frame ID type.
 *
 * Specifies the CAN frame ID type based on it's length as it is
 * defined by the CAN specification.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Extended ID (29 bits) */
    LLCE_CAN_EXTENDED = 0U,
    /** @brief Standard ID (11 bits) */
    LLCE_CAN_STANDARD,
    /** @brief Mixed ID (29 bits) */
    LLCE_CAN_MIXED
} Llce_Can_IdLengthType;

/**
 * @brief Requested transitions of a CAN controller.
 *
 * These controller state transitions are requested by the host in a specific
 * order.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Request transition from START state into STOP state. */
    LLCE_CAN_T_STOP = 0U,
    /** @brief Request transition from STOP state into START state. */
    LLCE_CAN_T_START,
} Llce_Can_StateTransitionType;

/**
 * @brief CAN controller states.
 *
 * CAN controller states as they are reported by the LLCE firmware as a result
 * of state transition requests.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Controller is uninitialised (default) */
    LLCE_CAN_UNINIT_CTRL = 0U,
    /**
     * @brief Controller is in a pending state of unitialization, waiting
     * for the resources to be restored (e.g Rx tokens)
     */
    LLCE_CAN_UNINIT_CTRL_PENDING,
    /** @brief Controller is stopping, but not offline yet */
    LLCE_CAN_STOP_PENDING,
    /**
     * @brief Controller is in the BUSOFF_PENDING state which means that it
     * does not do any bus transactions.
     */
    LLCE_CAN_BUSOFF_PENDING,
    /**
     * @brief Controller is in the STOPPED state which means that it does
     * not do any bus transactions.
     */
    LLCE_CAN_STOPPED,
    /** @brief Controller is starting, but cannot do bus transactions yet.*/
    LLCE_CAN_START_PENDING,
    /**
     * @brief Controller is in the STARTED state which means that it do bus
     * transactions.
     */
    LLCE_CAN_STARTED,
    /**
     * @brief Controller is in the IDLE state. This state is not used
     * by LLCE module.
     */
    LLCE_CAN_IDLE,
    /**
     * @brief Controller is in state when the common components of the
     * platform are not initialized.
     */
    LLCE_CAN_UNINIT_PLATFORM
} Llce_Can_CtrlStateType;

/**
 * @brief CAN firmware components IDs.
 *
 * CAN firmware components IDs used to identify the component which generated a
 * specific error.
 **/
typedef enum LLCE__PACKED
{
    /** @brief CAN TX firmware component. */
    LLCE_TX = 101U,
    /** @brief CAN RX firmware component. */
    LLCE_RX,
    /** @brief CAN DTE firmware component. */
    LLCE_DTE,
    /** @brief CAN FRPE firmware component. */
    LLCE_FRPE,
    /** @brief CAN2CAN TX firmware component. */
    LLCE_CAN2CAN_TX,
    /** @brief CAN2CAN RX firmware component. */
    LLCE_CAN2CAN_RX,
    /** @brief CAN2CAN FRPE firmware component. */
    LLCE_CAN2CAN_FRPE,
    /** @brief AF ETH2CAN TX firmware component. */
    LLCE_AF_ETH_TX,
    /** @brief AF CAN2ETH RX firmware component. */
    LLCE_AF_ETH_RX,
    /** @brief AF CAN2ETH or ETH2CAN FRPE firmware component. */
    LLCE_AF_ETH_FRPE,
    /** @brief HSE TX firmware component. */
    LLCE_AF_HSE_TX,
    /** @brief HSE RX firmware component. */
    LLCE_AF_HSE_RX,
    /** @brief HSE FRPE firmware component. */
    LLCE_AF_HSE_FRPE,
    /** @brief AF TX  firmware component. */
    LLCE_AF_TX,
    /** @brief AF RX  firmware component. */
    LLCE_AF_RX,
    /** @brief AF FRPE firmware component. */
    LLCE_AF_FRPE,
    /** @brief Headless TX boot firmware component. */
    LLCE_HEADLESS_TX,
    /** @brief Headless RX boot firmware component. */
    LLCE_HEADLESS_RX,
    /** @brief Headless FRPE boot firmware component. */
    LLCE_HEADLESS_FRPE
} Llce_Can_ModuleType;

/**
 * @brief CAN Logging options.
 *
 * CAN options for logging frames feature.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Logging of CAN frame is disabled.*/
    LLCE_AF_LOGGING_DISABLED = 1U,
    /** @brief Logging of CAN frame is enabled.*/
    LLCE_AF_LOGGING_ENABLED
} Llce_Af_LoggingOptionsType;

typedef enum LLCE__PACKED
{
    /** @brief Reception of the CAN frame by the host is disabled.*/
    LLCE_AF_HOSTRECEIVE_DISABLED = 1U,
    /** @brief Reception of the CAN frame by the host is enabled.*/
    LLCE_AF_HOSTRECEIVE_ENABLED
} Llce_Can_HostReceiveOptionsType;

typedef enum LLCE__PACKED
{
    /** @brief Authentication of CAN frame is disabled.*/
    LLCE_AF_AUTHENTICATION_DISABLED = 1U,
    /** @brief Authentication of CAN frame is enabled.*/
    LLCE_AF_AUTHENTICATION_ENABLED,
    LLCE_AF_AUTHENTICATION_NOT_SUPPORTED
} Llce_Af_AuthenticationOptionsType;

typedef enum LLCE__PACKED
{
    /** @brief Custom processing of CAN frame is disabled.*/
    LLCE_AF_CUSTOMPROCESSING_DISABLED = 1U,
    /** @brief Custom processing of CAN frame is enabled.*/
    LLCE_AF_CUSTOMPROCESSING_ENABLED,
} Llce_Af_CustomProcessingOptionsType;

/**
 * @brief RXLUT entries type
 *
 * Specifies the type of entry in the table.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Exact match entry type. */
    LLCE_CAN_ENTRY_EXACT_MATCH = 0U,
    /** @brief Masked match entry type. */
    LLCE_CAN_ENTRY_CFG_MASKED,
    /** @brief Range match entry type. */
    LLCE_CAN_ENTRY_CFG_RANGED,
} Llce_Can_EntryType;

/**
 * @brief Type of Advanced Feature(AF) rule.
 *
 * Specifies the type of entry in the destination rule table.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Destination rule type used for Can2Can use case. */
    CAN_AF_CAN2CAN = 0U,
    /** @brief Destination rule type used for Can2Eth use case. */
    CAN_AF_CAN2ETH,
    /** @brief Destination rule type used for Can2Pcie use case. */
    CAN_AF_CAN2PCIE,
    /** @brief Destination rule type used for Can2Hse use case. */
    CAN_AF_CAN2HSE
} Llce_Af_RuleIdType;

/**
 * @brief Type of Can2Eth routing
 *
 * Speccifies the type of packing to apply for Can2Eth
 **/
typedef enum LLCE__PACKED
{
    /** @brief IEEE1722-2016 AVPT non-time-synchronous CAN brief format */
    LLCE_AF_CAN2AVTP_NTSCF_BRIEF = 0U,
    /** @brief IEEE1722-2016 AVPT non-time-synchronous CAN regular format */
    LLCE_AF_CAN2AVTP_NTSCF_FULL,
    /** @brief IEEE1722-2016 AVPT time-synchronous CAN brief format */
    LLCE_AF_CAN2AVTP_TSCF_BRIEF,
    /** @brief IEEE1722-2016 AVPT time-synchronous CAN regular format */
    LLCE_AF_CAN2AVTP_TSCF_FULL,
    /** @brief UDP format, over IPv4*/
    LLCE_AF_CAN2UDP,
    /** @brief UDP format, type B, over IPv4*/
    LLCE_AF_CAN2UDP_B,
    /** @brief UDP format, over IPv6*/
    LLCE_AF_CAN2UDP_IPV6,
    /** @brief UDP format, type B, over IPv6 */
    LLCE_AF_CAN2UDP_B_IPV6,
    /** @brief Placeholder for maximum value */
    LLCE_AF_CAN2ETH_FORMAT_MAX
} Llce_Can_EthEncapsulationFormat;
/**
 * @brief Initialization status of the controllers.
 *
 * Initialization status of the controllers.
 * See \link Llce_Can_InitPlatformCmdType \endlink.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Entity is initialised */
    INITIALIZED = 1U,
    /** @brief Entity is uninitialised (default) */
    UNINITIALIZED = 2U
} Llce_Can_StatusType;

/**
 * @brief Processing type of a specific error
 *
 * Processing type of a specific error.
 * See \link Llce_Can_InitPlatformCmdType \endlink.
 **/
typedef enum LLCE__PACKED
{
    /** @brief LLCE Firmware does not report the error */
    IGNORE = 1U,
    /**
     * @brief LLCE Firmware reports the error through the notification table
     * corresponding to processing type configured by host
     */
    NOTIF_FIFO0,
    /**
     * @brief LLCE Firmware reports the error through the notification table
     * corresponding to processing type configured by host
     */
    NOTIF_FIFO1,
} Llce_Can_ErrorProcessingType;

/**
 * @brief AbortMB Type
 *
 * Specifies the type of AbortMB command. It can be either Single MB
 * abort or All MBs abort
 **/
typedef enum LLCE__PACKED
{
    /** @brief Request aborting of a single MB with a specific MB tag. */
    ABORT_ONLY_ONE_MB = 0U,
    /** @brief Request aborting of all the MBs with a specific MB tag. */
    ABORT_ALL_MB
} Llce_Can_AbortMbType;

/** @brief    MB length accepted by a filter
 *  @details  MB length (8/64 bytes) configured to be accepted by a filter.
 *            No mixed mode available. 
 *
 **/  
typedef enum LLCE__PACKED
{
    /** @brief Opt for 64 bytes MB size accepted by a filter */
    USE_LONG_MB = 0U,
    /** @brief Opt for 8 bytes MB size accepted by a filter */
    USE_SHORT_MB,
} Llce_CanRx_MbLengthType;

/**
 * @brief Generic binary type
 *
 * Logical binary type. Redefined for consistency.
 **/
typedef enum LLCE__PACKED
{
    LLCE_FALSE = 0,
    LLCE_TRUE
} Llce_Can_BinaryValueType;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*
 * These structure must be kept as they are because BCAN is
 * sending data in this format !
 */
/**
 * @brief CAN message buffer.
 *
 * CAN message buffer is a memory area placed in the shared memory
 * which is used by the LLCE firmware to receive/transmit from/to BCAN
 * controller. LLCE firmware transmit/receive the frame in a word by word way so
 * the content of the 4 structure fields contains the frame fields as they are
 * described in the picture from below. For the reception process the LLCE
 * firmware store inside message buffer frame the time stamp read from the
 * hardware CAN controller.
 *
 * \image latex rx_mb.JPG "LLCE message buffer structure." width=17cm
 *
 * @pre Before to use any message buffer it is needed to initialize, configure
 * and start a CAN controller
 **/
typedef struct
{
    /**
     * @brief INPUT/OUTPUT: The first word of a frame as it is
     * expected/provided by the CAN controller.
     */
    uint32 u32Word0;
    /**
     * @brief INPUT/OUTPUT: The second word of a frame as it is
     * expected/provided by the CAN controller.
     */
    uint32 u32Word1;
    /**
     * @brief INPUT/OUTPUT: Frame payload needed for the maximum
     * payload size case.
     */
    uint8 u8Payload[LLCE_CAN_CONFIG_PAYLOAD_MAX_SIZE];
    /**
     * @brief INPUT: Time stamp of the received frames.It is not used
     * for the transmitted frames.
     */
    uint32 u32Timestamp;


} LLCE__ALIGNED__PACKED Llce_Can_MbType;

typedef struct
{
    /**
     * @brief INPUT/OUTPUT: The first word of a frame as it is
     * expected/provided by the CAN controller.
     */
    uint32 u32Word0;
    /**
     * @brief INPUT/OUTPUT: The second word of a frame as it is
     * expected/provided by the CAN controller.
     */
    uint32 u32Word1;
    /**
     * @brief INPUT/OUTPUT: Frame payload needed for the short
     * payload size case.
     */
    uint8 u8Payload[LLCE_CAN_CONFIG_SHORT_PAYLOAD_MAX_SIZE];
    /**
     * @brief INPUT: Time stamp of the received frames.It is not used
     * for the transmitted frames.
     */
    uint32 u32Timestamp;

} LLCE__ALIGNED__PACKED Llce_Can_ShortMbType;


/**
 * @brief Reception message buffer descriptor.
 *
 * Reception message buffer descriptor is a memory area placed in the shared
 * memory which is written by the LLCE firmware with the specific runtime info
 * needed by the host software.(e.g.matching filter ID ). Also it includes an
 * index to a CAN message buffer allocated during initialization to each
 * descriptor. After reception, the host shall copy the content of the reception
 * message buffer descriptor and the referred message buffer by this descriptor
 * from the shared memory into the host memory in order to be processed later by
 * the host software and to allow the current message buffer descriptor to be
 * used by LLCE firmware for the reception of a new frame.
 *
 * @pre Before to use any receive message buffer descriptor it is needed to
 * initialize, configure and start a CAN controller
 **/
typedef struct
{
    /**
     * @brief OUTPUT: Filter identifier resulted at the end of filtering
     * process.
     *
     * This field is completed by the LLCE filtering mechanism with a value
     * which was configured during initialization time.
     * It is used in order to map a received frame to a specific filter
     * defined by the host.
     */
    uint16 u16FilterId;
    /**
     * @brief OUTPUT: Result of RxLut2 filtering.
     * See \link Llce_Can_MbType \endlink
     */
    uint16 u16AuxSearchResult;
} LLCE__ALIGNED__PACKED Llce_Can_RxMbDescriptorType;

/**
 * @brief Transmission message buffer descriptor.
 *
 * Transmission message buffer descriptor is a memory area placed in the shared
 * memory which is written by the host software with other additional info
 * (e.g. frame tag IDs) which is sent back to the host by the LLCE firmware as
 * acknowledge information. Those internal tags are not changed/used by the
 * LLCE firmware.
 *
 * @pre Before to use any transmission message buffer descriptor it is needed
 * to initialize, configure and start a CAN controller
 **/
typedef struct
{
    /**
     * @brief INPUT: Host defined tag used to track a specific frame.
     *
     * This field is not changed by the LLCE firmware and is returned
     * back to the host as it is.
     * See \link Llce_Can_Tx2HostAckInfoType \endlink
     */
    uint16 u16FrameTag1;
    /**
     * @brief INPUT: Host defined tag used to track a specific frame.
     *
     * This field is not changed by the LLCE firmware and is returned back
     * to the host as it is.
     * See \link Llce_Can_Tx2HostAckInfoType \endlink
     */
    uint16 u16FrameTag2;
    /**
     * @brief OUTPUT: Index to the frame message buffer.
     * See \link Llce_Can_MbType \endlink
     */
    uint16 u16MbFrameIdx;
    /**
     * @brief INPUT: Host defined interface used to select the acknowledge
     * interface of a specific frame.
     *
     * This field is not changed by the LLCE firmware.
     */
    uint8 u8AckInterface;
    /**
     * @brief INPUT: Request firmware to add MAC code to the transmitted
     * frame payload.
     */
    uint8 u8EnableTxFrameMac;
} LLCE__ALIGNED__PACKED Llce_Can_TxMbDescriptorType;

/**
 * @brief Acknowledge transmission information send from LLCE to host.
 *
 * It is used in order to send from LLCE to host needed information in order to
 * identify and confirm that a specific frame was transmitted on the CAN bus.
 * This data structure type is used in order to implement a circular buffer for
 * each channel which is accessed by using indexes transferred from LLCE to host
 * by using TXACK FIFOs.
 * This approach allows usage of existing hardware FIFOs even the size of the
 * transferred data is higher than the FIFO element width size.
 *
 * @pre Before to read any acknowledge information, it is needed to do a
 * transmission request.
 **/
typedef struct
{
    /** @brief OUTPUT: Transmission time stamp.*/
    uint32 u32TxTimestamp;
    /**
     * @brief OUTPUT: Host defined tag used to track a specific frame.
     * This field is not changed by the LLCE firmware and is returned back
     * to the host as it is.
     * See \link Llce_Can_TxMbDescriptorType \endlink
     */
    uint16 u16FrameTag1;
    /**
     * @brief OUTPUT: Host defined tag used to track a specific frame.
     * This field is not changed by the LLCE firmware and is returned back
     * to the host as it is.
     * See \link Llce_Can_TxMbDescriptorType \endlink
     */
    uint16 u16FrameTag2;
} LLCE__ALIGNED__PACKED Llce_Can_Tx2HostAckInfoType;

/**
 * @brief Command for polling of controller state .
 * @details  It is sent from host to LLCE to query it for the controller state.
 *
 **/
typedef struct
{
    /** @brief OUTPUT: Current state of the CAN controller. */
    Llce_Can_CtrlStateType eControllerState;
} LLCE__ALIGNED__PACKED  Llce_Can_GetControllerModeCmdType;

/**
 * @brief Set controller mode command.
 *
 * It is sent from host to LLCE module in order request changing the state of a
 * CAN controller. Currently it allows only to start and stop a controller.
 * When a controller is started it allows to transmit and receive frames from
 * the bus. When the controller is stopped it ignores all frames from the bus
 * and it doesn't transmit any frame.
 *
 * @pre Before changing the controller state it must be initialized.
 **/
typedef struct
{
    /** @brief INPUT: The new state which is requested. */
    Llce_Can_StateTransitionType eTransition;
} LLCE__ALIGNED__PACKED Llce_Can_SetControllerModeCmdType;

/**
 * @brief Data baud rate settings for a CAN FD controller.
 *
 * It is used to configure the CAN FD settings including baud rate used during
 * data phase.
 **/
typedef struct
{
    /**
     * @brief INPUT: Configuration of data phase baud rate:
     * - Prescaler divisor: (bit 23-27)
     * - Resynchronization Jump Width: (bit 16-19)
     * - Time Segment 2: (bit 9-12)
     * - Time Segment 1: (bit 0-4)
     *
     * Each parameter value shall be decreased by 1 when it is written into
     * this data structure field.
     */
    uint32 u32DataBaudrateConfig;
    /**
     * @brief INPUT: Enable or disable FD related features of the CAN
     * controller.
     */
    uint8 u8FdEnable;
    /**
     * @brief INPUT: Enable or disable baud rate switch (BRS) at the level
     * of CAN controller.
     */
    uint8 u8ControllerTxBitRateSwitch;
    /**
     * @brief INPUT: Enable or disable Transceiver Delay Compensation:
     * - TRUE: enabled
     * - FALSE: disabled.
     */
    uint8 u8TrcvDelayCompEnable;
    /**
     * @brief INPUT: Enable or disable Transceiver Delay Measurement:
     * - TRUE: enabled
     * - FALSE: disabled.
     *
     * When it is enabled, the secondary sample point is determined by the
     * sum of the transceiver delay measurement plus transceiver delay
     * compensation offset. When it is disabled, the secondary sample point
     * is determined only by the transceiver delay compensation offset.
     */
    uint8 u8TrcvDelayMeasEnable;
    /** @brief INPUT: Value of Transceiver Delay Compensation Offset*/
    uint8 u8TrcvDelayCompOffset;
} LLCE__ALIGNED__PACKED Llce_Can_ControllerFdConfigType;

/**
 * @brief Set baud rate command.
 *
 * It is sent from host to LLCE module in order to configure baud rate
 * parameters for arbitration phase.
 **/
typedef struct
{
    /**
     * @brief INPUT: Configuration parameters for nominal baud rate:
     * - Prescaler divisor: (bit 23-31)
     * - Resynchronization Jump Width (bit 16-22)
     * - Time Segment 2 (bit 9-15)
     * - Time Segment 1 (bit 0-7)
     *
     * Each parameter value shall be decreased by 1 when it is written into
     * this data structure field.
     */
    uint32 u32NominalBaudrateConfig;
    /**
     * @brief INPUT: Configuration parameters for data baud rate of the
     * CAN controller.
     */
    Llce_Can_ControllerFdConfigType ControllerFD;
} LLCE__ALIGNED__PACKED Llce_Can_SetBaudrateCmdType;

/**
 * @brief Filter element settings.
 *
 * It is used to define a specific filter.Current filtering process suppose to
 * accept a frame if it's frame ID match the filter ID masked with the mask
 * value. At the end of filtering process an internal filter ID is mapped to
 * the accepted frame in order to track it later by the host software.
 * A maximum number of frames accepted by a specific filter can be managed
 * by LLCE at each point in time.
 **/
typedef struct
{
    /**
     * @brief INPUT:
     * - For MASK filters: Frame id mask value. Bit fields containing
     * \b 0 means don't care.
     * - For RANGE filters: Maximum accepted id value.
     * - For EXACT MATCH: not used.
     *
     * Set LLCE_CAN_MB_IDE_U32 to match only standard/extended, unset for mixed
     */
    uint32 uIdMask;
    /**
     * @brief INPUT:
     * - For MASK filters: CAN frame ID value.
     * - For RANGE filters: Minimum accepted id value.
     * - For EXACT MATCH: id value
     *
     * Bit LLCE_CAN_MB_IDE_U32 controls extended/standard if enabled in mask.
     */
    uint32 uMessageId;
    /**
     * @brief INPUT: Filter identifier used to track frames after filtering
     * process on the reception side.
     * See also \link Llce_Can_RxMbDescriptorType \endlink
     */
    uint16 u16FilterId;
    /**
     * @brief INPUT: Maximum number of message buffers which can be used to
     * store frames accepted by this filter at each specific point in time.
     * When the maximum value is reached the firmware will begin to drop the
     * received frames accepted by that filter.It is used also in order to
     * prevent that the frames accepted by a specific filter do not overload
     * the LLCE internal hardware resources (e.g. message buffers, FIFOs).
     */
    uint16 u16MbCount;
    /**
     * @brief OUTPUT: Filter address inside hardware filtering accelerator
     * where the filter fields are stored.
     *
     * Host side application can use this to track used filter entries.
     * The search operation start from low filter addresses and continue to
     * the high filter addresses.
     */
    uint16 u16FilterAddr;
    /**
     * @brief INPUT: Reception interface id used to deliver frames accepted
     * by that filter to the host.
     */
    uint8 u8RxDestInterface;
    /** @brief INPUT: Filter entry type: mask, range, exact match */
    Llce_Can_EntryType eEntryType;
    /** @brief INPUT: Message buffer payload length: 8 or 64 bytes */
    Llce_CanRx_MbLengthType eFilterMbLength;

} LLCE__ALIGNED__PACKED Llce_Can_ReceiveFilterType;

/**
 * @brief Filter element settings for RxLut2.
 *
 * It is used to define a specific filter.Current filtering process supposes to
 * accept a frame if its frame ID matches the filter ID masked with the mask
 * value. At the end of the filtering process, an internal filter ID is mapped to
 * the accepted frame in order to track it later by the host software.
 * A maximum number of frames accepted by a specific filter can be managed
 * by LLCE at each point in time.
 **/
typedef struct
{
    /**
     * @brief INPUT:
     * - For MASK filters: Frame id mask value. Bit fields containing
     * \b 0 means don't care.
     * - For RANGE filters: Maximum accepted id value.
     * - For EXACT MATCH: not used.
     *
     * Set LLCE_CAN_MB_IDE_U32 to match only standard/extended, unset for mixed
     */
    uint32 uIdMask;
    /**
     * @brief INPUT:
     * - For MASK filters: CAN frame ID value.
     * - For RANGE filters: Minimum accepted id value.
     * - For EXACT MATCH: id value
     *
     * Bit LLCE_CAN_MB_IDE_U32 controls extended/standard if enabled in mask.
     */
    uint32 uMessageId;
    /**
     * @brief INPUT: Custom value configured by the user.
     */
    uint16 u16AuxSearchResult;
    /** @brief INPUT: Filter entry type: mask, range, exact match */
    Llce_Can_EntryType eEntryType;
} LLCE__ALIGNED__PACKED Llce_Can_AuxFilterType;

/**
 * @brief Set filter command.
 *
 * It is sent by the host to LLCE in order to configure one or more reception
 * filters inside LLCE.
 **/
typedef struct
{
    /**
     * @brief INPUT: Array containing configuration for reception
     * filters.
     */
    Llce_Can_ReceiveFilterType aRxFilters[LLCE_CAN_CONFIG_MAX_FILTERS_COUNT];
    /** @brief INPUT: Number of configured filters. */
    uint16 u16RxFiltersCount;
} LLCE__ALIGNED__PACKED Llce_Can_SetFilterCmdType;

/**
 * @brief Set filter command.
 *
 * It is sent by the host to LLCE in order to configure one or more auxiliary reception
 * filters inside LLCE.
 **/
typedef struct
{
    /**
     * @brief INPUT: Array containing configuration for reception
     * filters.
     */
    Llce_Can_AuxFilterType aRxAuxFilters[LLCE_CAN_CONFIG_MAX_FILTERS_COUNT];
    /** @brief INPUT: Number of configured filters. */
    uint16 u16RxAuxFiltersCount;
} LLCE__ALIGNED__PACKED Llce_Can_SetAuxFilterCmdType;

/**
 * @brief CAN to CAN routing filter configuration.
 *
 * It is used to define a specific routing filter. Current routing
 * implementation suppose to accept a received frame for a specific
 * ID and ID mask combination, then route that frame to one or more transmission
 * channels.
 **/
typedef struct
{
    /** @brief INPUT: Special options for advanced routing. See
    \link LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG \endlink
    \link LLCE_CAN_ROUTING_NOCHANGE \endlink
    \link LLCE_CAN_ROUTING_CAN \endlink
    \link LLCE_CAN_ROUTING_CANFD \endlink
    \link LLCE_CAN_ROUTING_ID_REMAPPING_EN \endlink*/
    uint32 u32Can2CanRoutingOptions;
    /** @brief INPUT: Can Id Remap Value.
     * Copied into u32Word0 of outgoing frame, except RTR flag. See \link Llce_Can_MbType \endlink.
     */
    uint32 u32CanIdRemapValue;
    /**
     * @brief INPUT: List of destination CAN controllers for the
     * accepted frame.
     */
    uint8 u8DestHwChList[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
    /** @brief INPUT: Length of the destination CAN controller list.*/
    uint8 u8DestHwChListCount;
} LLCE__ALIGNED__PACKED Llce_Can_Can2CanRoutingTableType;

/**
 * @brief Data structure type containing CAN to Ethernet destination rule
 * configuration.
 *
 * It is used to define a specific destination rule for Can2Eth internal
 * routing.
 **/
typedef struct
{
    /** @brief   INPUT: Base address of the buffer area for this destination */
    uint32 pu8Can2EthBuffAddr;
    /** @brief   INPUT: Size of each buffer for this destination */
    uint16 u16Can2EthBuffSize;
    /** @brief   INPUT: Number of buffers of size u16Can2EthBuffSize for this destination */
    uint8  u8Can2EthBuffCount;
    /** @brief   INPUT: Type of encapsulation */
    Llce_Can_EthEncapsulationFormat eFormat;
    /** @brief INPUT: Ethernet MAC destination address */
    uint8 u8Can2EthDestMac[6];
    /** @brief INPUT: Ethernet MAC source address */
    uint8 u8Can2EthSrcMac[6];
    /** @brief INPUT: Destination IP address (UDP only) */
    uint8 u8Can2EthDstIp[16];
    /** @brief INPUT: Source IP address (UDP only) */
    uint8 u8Can2EthSrcIp[16];
    /** @brief INPUT: Destination port (UDP only) */
    uint16 u8Can2EthDstPort;
    /** @brief INPUT: Source port (UDP only) */
    uint16 u8Can2EthSrcPort;
    /** @brief INPUT: Ethernet physical interface (bit list) - see LLCE_CAN2ETH_PFE_* */
    uint16 u16Can2EthPhyIfList;
} LLCE__ALIGNED__PACKED Llce_Can_Can2EthRoutingTableType;

/**
 * @brief Data structure type containing CAN to PCIe destination rule
 * configuration.
 *
 * It is used to define a specific destination rule for Can2Pcie routing.
 **/
typedef struct
{
    /** @brief   INPUT: Base address of the buffer area on the RC side*/
    uint64 u64Can2PcieRcBuffAddr;
    /** @brief   INPUT: Base address of the local buffer area for this destination */
    uint32 pu8Can2PcieBuffAddr;
    /** @brief   INPUT: Size of each buffer for this destination */
    uint16 u16Can2PcieBuffSize;
    /** @brief   INPUT: Number of buffers of size u16Can2PcieBuffSize for this destination */
    uint8  u8Can2PcieBuffCount;
    /** @brief   INPUT: PCIe controller used */
    uint8  u8Can2PcieController;
    /** @brief   INPUT: PCIe DMA channel used */
    uint8  u8Can2PcieDmaChannel;
    /** @brief   INPUT: MSI to trigger on transmission; 0xFF to disable */
    uint8  u8Can2PcieMsiId;
} LLCE__ALIGNED__PACKED Llce_Can_Can2PcieRoutingTableType;

/**
 * @brief Data structure type containing CAN to HSE destination rule
 * configuration.
 *
 * It is used to define a specific destination rule for Can2Hse routing.
 **/
typedef struct 
{
    /** @brief   INPUT: Key handle required to compute key on HSE side */
    uint32 u32Can2HseKeyHandle;
}LLCE__ALIGNED__PACKED Llce_Can_Can2HseRoutingTableType;


/**
 * @brief Data structure type representing  destination rule used by Advanced
 * Features(AF)
 *
 * Used to hold a generic type of AF destination rule
 **/
typedef struct
{
    /** @brief Destination rule content.*/
    union {
        /**
         * @brief INPUT: Destination rule for Can2Can internal routing
         * use case.
         */
        Llce_Can_Can2CanRoutingTableType Can2Can;
        /** @brief INPUT: Destination rule for Can2Eth use case.*/
        Llce_Can_Can2EthRoutingTableType Can2Eth;
        /** @brief INPUT: Destination rule for Can2Pcie use case.*/
        Llce_Can_Can2PcieRoutingTableType Can2Pcie;
        /** @brief INPUT: Destination rule for Can2Hse use case.*/
        Llce_Can_Can2HseRoutingTableType Can2Hse;
    } AfDest;
    /** @brief INPUT: Destination rule type.*/
    Llce_Af_RuleIdType eAfDestId;
} LLCE__ALIGNED__PACKED Can_Af_DestRulesType;

/**
 * @brief Advanced filter configuration.
 *
 * It is used to define an advanced filter. It contains references to the
 * individual features configured by the host.
 **/
typedef struct
{
    /** @brief INPUT: Option for frame authentication feature. */
    Llce_Af_AuthenticationOptionsType eCanAuthenticationFeature;
    /** @brief INPUT: Option for host receive feature. */
    Llce_Can_HostReceiveOptionsType eHostReceive;
    /** @brief INPUT: Option for logging feature. */
    Llce_Af_LoggingOptionsType eCanLoggingFeature;
    /** @brief INPUT: Option for custom processing. */
    Llce_Af_CustomProcessingOptionsType eCanCustomProcessing;
    /**
     * @brief INPUT: CAN2CAN routing table index.
     * Reference to the routing table rule.
     * See \link Llce_Can_Can2CanRoutingTableType \endlink
     */
    uint8 u8Can2CanRoutingTableIdx;
    /**
     * @brief INPUT: CAN2ETH routing table index.
     * Reference to the routing table rule.
     * See \link Llce_Can_Can2EthRoutingTableType \endlink
     */
    uint8 u8Can2EthRoutingTableIdx;
    /**
     * @brief INPUT: Other destination routing table index.
     * Reference to a routing table rule.
     */
    uint8 u8OtherRoutingTableIdx;
} LLCE__ALIGNED__PACKED Llce_Can_AdvancedFeatureType;

/**
 * @brief Advanced filter element configuration.
 *
 * It is used to define a specific filter. Current filtering suppose to accept
 * a frame for processing if it's frame ID match the filter ID masked with the
 * mask value. At the end of filtering process the frame is processed according
 * to the advanced configuration of the filter.
 **/
typedef struct
{
    /** @brief INPUT: Standard filter configuration. */
    Llce_Can_ReceiveFilterType Llce_Can_RxFilter;
    /** @brief INPUT: Can advanced features used by the filter. */
    Llce_Can_AdvancedFeatureType Llce_Can_AdvancedFeature;
} LLCE__ALIGNED__PACKED Llce_Can_AdvancedFilterType;

/**
 * @brief Set advanced filter command.
 *
 * It is sent by the host to LLCE in order to set one or more advanced filters.
 **/
typedef struct
{
    /**
     * @brief INPUT: Array containing configuration for one or
     * more filters.
     */
    Llce_Can_AdvancedFilterType aAdvancedFilters[LLCE_CAN_CONFIG_ADVANCED_FILTERS_COUNT];
    /** @brief INPUT: Number of configured filters. */
    uint16 u16RxFiltersCount;
} LLCE__ALIGNED__PACKED Llce_Can_SetAdvancedFilterCmdType;

/**
 * @brief Configurable errors that LLCE Firmware handles.
 *
 * Configurable errors that LLCE Firmware handles using different types of
 * processing.It is part of platform initialization command.
 * Only BusOff processing type is selectable per channel.
 **/
typedef struct
{
    /** @brief CAN Protocol errors supported by CAN controller. */
    Llce_Can_ErrorProcessingType eCanProtocolErr;
    /** @brief DATALOST event as described by Autosar standard */
    Llce_Can_ErrorProcessingType eDataLostErr;
    /**
     * @brief Initialization errors, like resources overflow, bad commands
     * flow, bad command parameters, invalid indexes or any other errors
     * caused by bad usage or a malicious host.
     */
    Llce_Can_ErrorProcessingType eInitErr;
    /** @brief Internal errors, like timeouts. */
    Llce_Can_ErrorProcessingType eInternalErr;
    /** @brief BusOff processing is selectable per channel */
    Llce_Can_ErrorProcessingType eBusOffErr[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
    /** @brief Passive state + TX/RX WRN. */
    Llce_Can_ErrorProcessingType eCanProtocolWarn;
} LLCE__ALIGNED__PACKED Llce_Can_ErrorCategoryType;

/**
 * @brief Platform initialization command.
 *
 * It is sent by the host to LLCE in order to configure the platform related
 * parameters. It is the first command which shall be send to LLCE module after
 * booting in order to configure common LLCE components.
 * Most important operations done by LLCE firmware at platform initialization
 * are:
 * - initializes all common internal LLCE components (hardware and software).
 * - prepare filter management data structures
 **/
typedef struct
{
    /**
     * @brief INPUT: Array containing the initialization status of the
     * controllers
     */
    Llce_Can_StatusType eCtrlInitStatus[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
    /**
     * @brief INPUT: Array containing maximum number of regular filters per
     * channel.
     * See \link LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32 \endlink as a
     * controller option example
     */
    uint16 au16MaxRegularFilterCount[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
    /**
     * @brief INPUT: Array containing maximum number of advanced filters
     * per channel.
     * See \link LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32 \endlink as a
     * controller option example
     */
    uint16 au16MaxAdvancedFilterCount[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
    /**
     * @brief INPUT: Array containing maximum number of RX message buffers
     * per output interface, considering interrupt processing.
     */
    uint16 au16MaxIntMbCount[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
    /**
     * @brief INPUT: Array containing maximum number of RX message buffers
     * per polling class, considering polling processing.
     * There are a number of \link LLCE_CAN_MAX_POLLING_CLASSES \endlink
     * provided.
     */
    uint16 au16MaxPollMbCount[LLCE_CAN_MAX_POLLING_CLASSES];
    /**
     * @brief INPUT: Array containing maximum number of reserved TX confirmation
     * buffers per output interface, considering interrupt processing.
     */
    uint16 au16MaxIntTxAckCount[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
    /**
     * @brief INPUT: Array containing maximum number of reserved TX
     * confirmation buffers per polling class, considering polling
     * processing.
     * There are a number of \link LLCE_CAN_MAX_POLLING_CLASSES \endlink
     * provided.
     */
    uint16 au16MaxPollTxAckCount[LLCE_CAN_MAX_POLLING_CLASSES];
    /**
     * @brief INPUT: Structure describing the way of processing each errors
     * category. This can be: INTERRUPT, POLLING or IGNORE.
     */
    Llce_Can_ErrorCategoryType CanErrorReporting;
} LLCE__ALIGNED__PACKED Llce_Can_InitPlatformCmdType;

/**
 * @brief Initialization command.
 *
 * It is sent by the host to LLCE in order to load and configure all needed
 * parameters inside LLCE. 
 * Most important operations done by LLCE firmware at initialization are:
 * - when this command is executed for the first CAN channel it initialize also
 * all internal LLCE components.
 * - configure the hardware features of a CAN controller.
 * - set a CAN controller in the stop state.
 **/
typedef struct
{
    /**
     * @brief INPUT: Configuration options for a hardware CAN controller.
     * See \link LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32 \endlink as a
     * controller  option example
     */
    uint32 u32CtrlConfig;
    /**
     * @brief INPUT: Number of transmission message buffer descriptors used
     * for transmissions initialized by the host.The remaining elements are
     * used for internal routing scenarios.
     */
    uint8 u8TxMbCount;
} LLCE__ALIGNED__PACKED Llce_Can_InitCmdType;

/**
 * @brief LLCE-PFE Initialization command.
 *
 * It is sent by the host to LLCE in order to activate the LLCE-PFE interface,
 * and obtain the addresses of the relevant data structures.
 * @note Use uint32 instead of void*, for portability
 **/
typedef struct
{
    /** @brief OUTPUT: Address of the PFE RX Ring in LLCE memory */
    uint32 pRxRing;
    /** @brief OUTPUT: Address of the PFE RX Writeback Ring in LLCE memory */
    uint32 pRxWbRing;
    /** @brief OUTPUT: Address of the PFE TX Ring in LLCE memory */
    uint32 pTxRing;
    /** @brief OUTPUT: Address of the PFE TX Writeback Ring in LLCE memory */
    uint32 pTxWbRing;
     /** @brief INPUT: Pointer to the buffers used for RX */
    uint32 pRxBuffers;
    /** @brief INPUT: Size of the buffers used for RX */
    uint16 u16RxBufSize;
    /** @brief INPUT: Number of buffers used for RX */
    uint8 u8RxBufCount;
    /** @brief INPUT: Index of the PFE HIF to use in LLCE */
    uint8 u8Hif;
} LLCE__ALIGNED__PACKED Llce_Can_InitPfeCmdType;

/**
 * @brief LLCE-PFE Configurable Ring Initialization command.
 *
 * It is sent by the host to LLCE in order to activate the LLCE-PFE interface,
 * use the addresses of the relevant data structures provided by the host.
 * @note Use uint32 instead of void*, for portability
 **/
typedef struct
{
    /** @brief INPUT: Address of the PFE RX Ring in LLCE memory */
    uint32 pRxRing;
    /** @brief INPUT: Address of the PFE RX Writeback Ring in LLCE memory */
    uint32 pRxWbRing;
    /** @brief INPUT: Address of the PFE TX Ring in LLCE memory */
    uint32 pTxRing;
    /** @brief INPUT: Address of the PFE TX Writeback Ring in LLCE memory */
    uint32 pTxWbRing;
     /** @brief INPUT: Pointer to the buffers used for RX */
    uint32 pRxBuffers;
    /** @brief INPUT: Ring size of the PFE Rx Ring */
    uint32 u32RingSize;
    /** @brief INPUT: Pointer to the header */
    uint32 pHeader;
    /** @brief INPUT: Size of the buffers used for RX */
    uint16 u16RxBufSize;
    /** @brief INPUT: Number of buffers used for RX */
    uint8 u8RxBufCount;
    /** @brief INPUT: Size of the header */
    uint8 u8HeaderSize;
    /** @brief INPUT: Index of the PFE HIF to use in LLCE */
    uint8 u8Hif;    
} LLCE__ALIGNED__PACKED Llce_Can_InitPfeWithExternRingCmdType;

/**
 * @brief Get status command.
 *
 * It is sent by the host to LLCE in order to get the content of all status
 * registers of a specific CAN controller. This command makes only a read
 * operation on the status registers of CAN controller.
 *
 \image latex bcan_ecr.jpg "LLCE BCAN ECR." width=14cm
 \image html bcan_ecr.jpg "LLCE BCAN ECR."
 \image docbook bcan_ecr.jpg "LLCE BCAN ECR."
 \image rtf bcan_ecr.jpg "LLCE BCAN ECR."
 *
 \image latex bcan_crc.jpg "LLCE BCAN CRC." width=14cm
 \image html bcan_crc.jpg "LLCE BCAN CRC."
 \image docbook bcan_crc.jpg "LLCE BCAN CRC."
 \image rtf bcan_crc.jpg "LLCE BCAN CRC."
 *
 \image latex bcan_isr.jpg "LLCE BCAN ISR." width=14cm
 \image html bcan_isr.jpg "LLCE BCAN ISR."
 \image docbook bcan_isr.jpg "LLCE BCAN ISR."
 \image rtf bcan_isr.jpg "LLCE BCAN ISR."
 *
 \image latex bcan_sr.jpg "LLCE BCAN SR." width=14cm
 \image html bcan_sr.jpg "LLCE BCAN SR."
 \image docbook bcan_sr.jpg "LLCE BCAN SR."
 \image rtf bcan_sr.jpg "LLCE BCAN SR."
 *
 \image latex bcan_sr_2.jpg "LLCE BCAN SR-2." width=14cm
 \image html bcan_sr_2.jpg "LLCE BCAN SR-2."
 \image docbook bcan_sr_2.jpg "LLCE BCAN SR-2."
 \image rtf bcan_sr_2.jpg "LLCE BCAN SR-2."
 *
 **/
typedef struct
{
    /** @brief OUTPUT: Register ECR of CAN controller. */
    uint32 u32ECR;
    /** @brief OUTPUT: Register ISR of CAN controller. */
    uint32 u32ISR;
    /** @brief OUTPUT: Register SR of CAN controller. */
    uint32 u32SR;
    /** @brief OUTPUT: Register CRC of CAN controller. */
    uint32 u32CRC;
} LLCE__ALIGNED__PACKED Llce_Can_GetStatusCmdType;

/**
 * @brief Get firmware version command.
 *
 * It is sent by the host to LLCE in order to get the firmware version string.
 * It is copied in the response.
 **/
typedef Llce_Fw_VersionType Llce_Can_GetFwVersionType;

/**
 * @brief Filter address identifier
 *
 * It is sent by the host to LLCE in order to disable/enable a specific filter,
 * identified by its address
* <TABLE>
* <TR><TD>Type</TD><TD>Direction</TD><TD>Name</TD><TD>Disable filter</TD><TD>Enable filter</TD></TR>
* <TR><TD>uint8</TD><TD>in</TD><TD>u8FilterEnabled</TD><TD>0U</TD><TD>1U</TD></TR>
* </TABLE>
 **/
typedef struct
{
    /**
     * @brief INPUT: Address of the filter which shall be
     * removed/disabled/enabled.
     */
    uint16 u16FilterAddr;
    /** @brief INPUT: Request new state (0 - disable filter / 1 - enable filter) 
     *  of the filter when using SetFilterEnableStatus command. */
    uint8 u8FilterEnabled;
} LLCE__ALIGNED__PACKED Llce_Can_ChangeFilterType;

/**
 * @brief Add AF destination command structure.
 *
 * It is sent by the host to LLCE in order add a destination to be used by AF
 **/
typedef struct
{
    /** @brief INPUT: Destination to add to the list */
    Can_Af_DestRulesType rule;
    /** @brief OUTPUT: Index in LLCE list where destination was inserted */
    uint8 u8Idx;
} LLCE__ALIGNED__PACKED Llce_Can_CreateAfDestination;

/**
 * @brief Remove AF destination command.
 *
 * It is sent by the host to LLCE in order remove a destination used by AF. It is the index in LLCE list of destination to be removed.
 **/
typedef uint8 Llce_Can_RemoveAfDestination;



/**
 * @brief Abort MB command structure
 *
 * It is sent by the host to LLCE in order to abort the lowest priority pending
 * transmission of a specific controller.
 **/
typedef struct
{
    /**
     * @brief INPUT: Host defined tag used to track a specific frame.
     * See \link Llce_Can_TxMbDescriptorType \endlink
     */
    uint16 u16FrameTag;
    /** @brief   OUTPUT: Number of Tx pending transmissions aborted */
    uint8 u8AbortedFrameCnt;
    /** @brief INPUT: Specifies the type of AbortMB command. */
    Llce_Can_AbortMbType eAbortMbType;
} LLCE__ALIGNED__PACKED Llce_Can_AbortMbCmdType;

/**
 * @brief Set Eth2Can decapsulation state.
 *
 * It is sent by the host to LLCE in order to turn on or off decapsulation
 * for a given format.
 **/
typedef struct
{
    /** @brief INPUT: Encapsulation format */
    Llce_Can_EthEncapsulationFormat eFormat;
    /** @brief INPUT: State to set */
    Llce_Can_BinaryValueType eState;
} LLCE__ALIGNED__PACKED Llce_Can_SetEth2CanFormatStateCmdType;


/**
 * @brief List of commands used by host.
 *
 * It is used in order to use the same memory area for all commands send from
 * host to LLCE.
 **/
typedef union {
    /** @brief Command for initializing a specific CAN channel. */
    Llce_Can_InitCmdType Init;
    /**
     * @brief Command for getting the hardware status information for a
     * specific CAN controller.
     */
    Llce_Can_GetStatusCmdType GetStatus;
    /**
     * @brief Command for configuring filters for a specific CAN controller
     * in order to deliver frames to the host.
     */
    Llce_Can_SetFilterCmdType SetFilter;
    /**
     * @brief Command for configuring filters in order to route frames to
     * other destinations than host.
     */
    Llce_Can_SetAdvancedFilterCmdType SetAdvancedFilter;
    /** @brief Hardware address of filter to disable/enable/remove. */
    Llce_Can_ChangeFilterType ChangeFilter;
    /**
     * @brief Command for configuring baud rate parameters for a specific
     * CAN controller.
     */
    Llce_Can_SetBaudrateCmdType SetBaudrate;
    /**
     * @brief Command for getting the status of a specific CAN controller.
     */
    Llce_Can_GetControllerModeCmdType GetControllerMode;
    /**
     * @brief Command for changing the status of a specific CAN controller.
     */
    Llce_Can_SetControllerModeCmdType SetControllerMode;
    /** @brief Command for getting the firmware version. */
    Llce_Can_GetFwVersionType GetFwVersion;
    /**
     * @brief Command for configuring platform related parameters and common
     * HW components used by all CAN channels
     */
    Llce_Can_InitPlatformCmdType InitPlatform;
    /**
     * @brief Command for initializing the LLCE-PFE interface and getting
     * buffer locations
     */
    Llce_Can_InitPfeCmdType InitPfe;
    /**
     * @brief Command for initializing the LLCE-PFE interface using user's
     * ring buffer input
     */
    Llce_Can_InitPfeWithExternRingCmdType InitPfeWithExternRing;
    /** @brief Command for creating a destination for AF */
    Llce_Can_CreateAfDestination CreateAfDest;
    /** @brief Command for removing a destination for AF */
    Llce_Can_RemoveAfDestination RemoveAfDest;
    /**
     * @brief Command for aborting either the lowest priority message buffer
     * or all the message buffers with a specific tag.
     */
    Llce_Can_AbortMbCmdType AbortMb;
    /** @brief Pointer to argument for custom command */
    uint32 pCustomCmdArg;
    /**
     * @brief Command for configuring custom filters for a specific CAN controller
     * in order to deliver frames to the host.
     */
    Llce_Can_SetAuxFilterCmdType SetAuxFilter;
    /**
     * @brief Generic argument for binary values
     */
    Llce_Can_BinaryValueType eBinaryValue;
    /**
     * @brief Command for turning Eth2Can on or off for a certain format
     */
    Llce_Can_SetEth2CanFormatStateCmdType SetEth2CanFormatState;
} Llce_Can_CommandListType;

/**
 * @brief Command used by host.
 *
 * It is used in order to send commands from host to LLCE using shared memory.
 **/
typedef struct
{
    /** @brief INPUT: Command parameters. */
    Llce_Can_CommandListType CmdList;
    /** @brief INPUT: Command ID. */
    Llce_Can_CommandIdType eCmdId;
    /** @brief OUTPUT: Return status code after command completion.*/
    Llce_Fw_ReturnType eReturnValue;
} LLCE__ALIGNED__PACKED Llce_Can_CommandType;

/**
 * @brief Set controller mode notification.
 *
 * Notification send from LLCE to host in order to inform about a specific
 * controller state change.
 **/
typedef struct
{
    /**
     * @brief OUTPUT: Current state of the CAN controller.
     * See also \link Llce_Can_CtrlStateType \endlink
     */
    Llce_Can_CtrlStateType eControllerState;
    /** @brief OUTPUT: CAN controller id. */
    uint8 u8HwCtrl;
} LLCE__ALIGNED__PACKED Llce_Can_CtrlModeNotifType;

/**
 * @brief Platform specific error.
 *
 * Platform error details send to host in order to report an internal
 * LLCE error.
 **/
typedef struct
{
    /**
     * @brief OUTPUT: LLCE firmware component id.
     * See also \link Llce_Can_ModuleType \endlink
     */
    Llce_Can_ModuleType eModuleId;
    /**
     * @brief OUTPUT: LLCE error code.
     * See also \link Llce_Fw_ReturnType \endlink
     */
    Llce_Fw_ReturnType eErrorCode;
    /** @brief OUTPUT: Number of occurrences of the last error. */
    uint16 u16ErrorCount;
} LLCE__ALIGNED__PACKED Llce_Can_ErrorNotifType;

/** @brief Channel specific error.
 *
 * Channel error details send to host in order to report an internal LLCE error.
 **/
typedef struct
{
    Llce_Can_ErrorNotifType ErrorInfo;
    /** @brief OUTPUT: Controller ID. */
    uint8 u8HwCtrl;
} LLCE__ALIGNED__PACKED Llce_Can_ChannelErrorNotifType;

/**
 * List of notifications send by LLCE to host, used by host.
 *
 * It is used by LLCE to notify host about specific events inside LLCE.
 **/
typedef union {
    /**
     * @brief OUTPUT: Notification parameters for controller state changes.
     * See also \link Llce_Can_CtrlModeNotifType \endlink
     */
    Llce_Can_CtrlModeNotifType CtrlMode;
    /**
     * @brief OUTPUT: Notification parameters for platform errors.
     * See also \link Llce_Can_ErrorNotifType \endlink
     */
    Llce_Can_ErrorNotifType PlatformError;
    /**
     * @brief OUTPUT: Notification parameters for channel errors.
     * See also \link Llce_Can_ChannelErrorNotifType \endlink
     */
    Llce_Can_ChannelErrorNotifType ChannelError;
} Llce_Can_NotificationListType;

/**
 * @brief Notifications used by LLCE.
 *
 * It is used in order to send notifications from LLCE to host by using shared
 * memory.
 **/
typedef struct
{
    /**
     * @brief OUTPUT: Notification parameters.
     * See also \link Llce_Can_NotificationListType \endlink
     */
    Llce_Can_NotificationListType NotifList;
    /**
     * @brief OUTPUT: Notification ID.
     * See also \link Llce_Can_NotificationIdType \endlink
     */
    Llce_Can_NotificationIdType eNotifId;
} LLCE__ALIGNED__PACKED Llce_Can_NotificationType;

/**
 * @brief Notification tables.
 *
 * Notification tables used to store the details of the notifications.
 * The index of entries are sent to host cores.The two tables are related to
 * reporting method:interrupt or polling.
 **/
typedef struct
{
    /**
     * @brief OUTPUT: Table used to report notifications in interrupt mode.
     * See also \link Llce_Can_NotificationType \endlink
     */
    Llce_Can_NotificationType
        Can_aNotif0_Table[LLCE_CAN_CONFIG_HIF_COUNT]
                         [LLCE_CAN_CONFIG_NOTIF_TABLE_SIZE];
    /**
     * @brief OUTPUT: Table used to report notifications in polling mode.
     * See also \link Llce_Can_NotificationType \endlink
     */
    Llce_Can_NotificationType
        Can_aNotif1_Table[LLCE_CAN_CONFIG_HIF_COUNT]
                         [LLCE_CAN_CONFIG_NOTIF_TABLE_SIZE];
} LLCE__ALIGNED__PACKED Llce_Can_NotificationTableType;

/**
 * @brief Shared memory structure
 *
 * Structure that encapsulates all the shared memory with LLCE on the CAN side.
 **/
typedef struct
{
    /** @brief Receive message buffer descriptors. */
    Llce_Can_RxMbDescriptorType Can_Rx_aMbDesc[LLCE_CAN_CONFIG_MAXRXMB + LLCE_CAN_CONFIG_MAX_SHORTRXMB];
    /** @brief Transmit message buffer descriptors. */
    Llce_Can_TxMbDescriptorType Can_Tx_aMbDesc[LLCE_CAN_CONFIG_MAXTXMB];
    /** @brief Shared memory used to store the LONG CAN message buffers (64B). */
    Llce_Can_MbType Can_aMb[LLCE_CAN_CONFIG_MAXRXMB + LLCE_CAN_CONFIG_MAXTXMB +
                            LLCE_CAN_CONFIG_MAXAFFRMB];

    /** @brief Shared memory used to store the SHORT CAN message buffers (8B). */
    Llce_Can_ShortMbType Can_aSMb[LLCE_CAN_CONFIG_MAX_SHORTRXMB];

    /** @brief Shared memory used to send commands from Host to LLCE . */
    Llce_Can_CommandType aCanCmd[LLCE_CAN_CONFIG_HIF_COUNT];
    /** @brief Shared memory used to store notifications from LLCE to host.
     */
    Llce_Can_NotificationTableType Can_NotificationTable;
    /**
     * @brief Circular buffer used to send ACK info from TX core to HOST
     * core. Reserved 1 extra buffer for each interface for consistency
     * purposes.
     */
    Llce_Can_Tx2HostAckInfoType Can_Tx_aAckInfo[LLCE_CAN_CONFIG_MAX_TXACKINFO];
} LLCE__ALIGNED__PACKED Llce_Can_SharedMemoryType;

typedef struct
{
    /** @brief Shows the number of CAN frames received by each controller */
    uint32 u32GeneralRxCount;
    /** @brief Shows the number of CAN frames sent by each controller and acknowledged on the bus */
    uint32 u32GeneralTxCount;
    /** @brief All CAN frames received by the controller from other controllers via CAN */
    uint32 u32Can2CanInCount;
    /** @brief All CAN frames sent by the controller to other controller via CAN */
    uint32 u32Can2CanOutCount;
    /** @brief All CAN frames received by controller to be encapsulated in Ethernet format and sent to PFE for transmission over ethernet */
    uint32 u32Can2EthCount;
    /** @brief All Ethernet frames transfered from PFE to LLCE controller for decoding and transmission over CAN */
    uint32 u32Eth2CanCount;
    /** @brief Reserved for future use */
    uint32 u32ReservedCount1;
    /** @brief Reserved for future use */
    uint32 u32ReservedCount2;
    /** @brief Reserved for future use */
    uint32 u32ReservedCount3;
    /** @brief Reserved for future use */
    uint32 u32ReservedCount4;
} LLCE__ALIGNED__PACKED Llce_Can_RxTxCountType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*LLCE_INTERFACECANTYPES_H*/

/** @} */
