/**
 *   @file    Llce_InterfaceFwMgr.h
 *
 *   @brief   LLCE defines used to configure the LLCE firmware and interface
 *   @details LLCE defines used to configure the LLCE firmware and interface.
 *            Those configuration parameters are used both by LLCE firmware and
 *            host software.
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

#ifndef LLCE_INTERFACEFWMGR_H
#define LLCE_INTERFACEFWMGR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* This violation is due to the AUTOSAR requirement [SWS_BSW_00036] (perform inter module checks).
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* This rule does not apply if either identifier is a macro identifier, because this case is covered
* by Rule 5.4 and Rule 5.5.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The identifier clash is between macro identifiers. Therefore, this rule is incorrectly reported by the tool.
*
* @section Llce_InterfaceFwMgr_h_REF_1
* Violates MISRA 2012 Required Rule 21.1, #define and #undef shall not be used on a reserved identifier or
* reserved macro name.
* Certain keywords are not recognized by tools such as PC-LINT and LDRA.
*
* @section Llce_InterfaceFwMgr_h_REF_2
* Violates MISRA 2012 Advisory Rule 4.9, A function should be used in
* preference to a function-like macro where they are interchangeable. Function
* like macro are used to reduce code complexity
*
* @section Llce_InterfaceFwMgr_h_REF_3
* Violates MISRA 2012 Advisory Rule 2.3, A project should not contain unused type declarations.
* False detection by lint tool.
*
*/

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/


#include "Llce_RegAccess.h"

#ifdef CHECK_ABI_COMPATIBILITY
#pragma ABICHECK start
#endif
#include "Llce_FwVersion.h"

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
 *                                      Interrupts
 ==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/

/**
 * @brief CAN firmware notification categories.
 * @details Contains the notification categories of the values returned by the LLCE Firmware.
 * @see Llce_Fw_ReturnType
 **/
typedef enum LLCE__PACKED
{
    LLCE_NOTIFCAT_CAN_PROTOCOL = 1U,
    LLCE_NOTIFCAT_DATA_LOST,
    LLCE_NOTIFCAT_CONFIGURATION,
    LLCE_NOTIFCAT_INTERNAL,
    LLCE_NOTIFCAT_BUSOFF,
    LLCE_NOTIFCAT_FW_STATUS,
    LLCE_NOTIFCAT_CAN_PROTOCOL_CRITICAL_STATE

} Llce_Fw_Notification_Category;

/**
 * @brief CAN firmware error values.
 *
 * CAN error values as they are reported by the LLCE firmware. Some of them are
 * channel related and other are platform related.
 **/
typedef enum LLCE__PACKED
{
    /** @brief CAN firmware error: BOTH SW AND HW TXACK FIFOS are full. */
    LLCE_ERROR_TXACK_FIFO_FULL = 1U,
    /** @brief CAN firmware error: RXOUT SW FIFO is full. */
    LLCE_ERROR_RXOUT_FIFO_FULL,
    /** @brief CAN firmware error: Reserved for future use. */
    LLCE_ERROR_CODE_RESERVED_0,
    /** @brief CAN firmware error: The system lost indexes or HW FIFO was not cleared and it is full. */
    LLCE_ERROR_HW_FIFO_FULL,
    /** @brief CAN firmware error: There was an attempt to perform a pop operation on an empty SW FIFO. */
    LLCE_ERROR_SW_FIFO_EMPTY,
    /** @brief CAN firmware error: There was an attempt to perform a push operation on a full SW FIFO.*/
    LLCE_ERROR_SW_FIFO_FULL,
    /** @brief CAN firmware error: The maximum hardware object count on the reception side was reached. */
    LLCE_ERROR_MB_NOTAVAILABLE,
    /** @brief CAN firmware error: Short Message buffer is configured but a long frame is received. */
    LLCE_ERROR_SHORT_MB_NOTAVAILABLE,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_BCAN_FRZ_EXIT,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_BCAN_SYNC,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_BCAN_FRZ_ENTER,
    /**
     * @brief CAN firmware error: CAN protocol error due to inability to
     * enter in low-power mode.
     */
    LLCE_ERROR_BCAN_LPM_EXIT,
    /**
     * @brief CAN firmware error: CAN protocol error due to inability to
     * enter in soft reset.
     */
    LLCE_ERROR_BCAN_SRT_ENTER,
    /**
     * @brief CAN firmware error: An error callback was called, but no error code matches : unknown CAN protocol error 
     */
    LLCE_ERROR_BCAN_UNKNOWN_ERROR,
    /**
     * @brief CAN firmware error: ACKERR indicates that an acknowledge error
     * has been detected by the transmitter node.
     */
    LLCE_ERROR_BCAN_ACKERR,
    /**
     * @brief CAN firmware error: CRCERR indicates that a CRC error has been
     * detected by the receiver node in a CAN frame.
     */
    LLCE_ERROR_BCAN_CRCERR,
    /**
     * @brief CAN firmware error: BIT0ERR indicates when an inconsistency
     * occurs between the transmitted and the received bit in a CAN frame.
     */
    LLCE_ERROR_BCAN_BIT0ERR,
    /**
     * @brief CAN firmware error: BIT1ERR indicates when an inconsistency
     * occurs between the transmitted and the received bit in a CAN frame.
     */
    LLCE_ERROR_BCAN_BIT1ERR,
    /**
     * @brief CAN firmware error: DPBIT1ERR indicates when an inconsistency
     * occurs between the transmitted and the received bit in the data phase
     * of a CAN-FD frame.
     */
    LLCE_ERROR_BCAN_DPBIT1ERR,
    /**
     * @brief CAN firmware error: DPBIT0ERR indicates when an inconsistency
     * occurs between the transmitted and the received bit in the data phase
     * of a CAN-FD frame.
     */
    LLCE_ERROR_BCAN_DPBIT0ERR,
    /**
     * @brief CAN firmware error: DPSTFERR indicates that a stuffing error has
     * been detected by the receiver node in the data phase of a CAN-FD frame.
     */
    LLCE_ERROR_BCAN_DPSTFERR,
    /**
     * @brief CAN firmware error: DPFRMERR indicates that a form error has
     * been detected by the receiver node in the data phase of a CAN-FD frame
     * - a fixed-form bit field contains at least one illegal bit.
     */
    LLCE_ERROR_BCAN_DPFRMERR,
    /**
     * @brief CAN firmware error: DPCRCERR indicates that a CRC error has been
     * detected by the receiver node in the data phase of a CAN-FD frame
     */
    LLCE_ERROR_BCAN_DPCRCERR,
    /**
     * @brief CAN firmware error: FRMERR indicates that a form error has
     * been detected by the receiver node in a CAN frame - a fixed-form bit
     * field contains at least one illegal bit.
     */
    LLCE_ERROR_BCAN_FRMERR,
    /**
     * @brief CAN firmware error: STFERR indicates that a stuffing error has
     * been detected by the receiver node in a CAN frame.
     */
    LLCE_ERROR_BCAN_STFERR,
    /**
     * @brief CAN firmware error: TDC mechanism is out of range, 
     * unable to compensate the transceiver's loop delay.
     */
    LLCE_ERROR_BCAN_TDCFAIL,
    /**
     * @brief CAN firmware error: DataLost event caused by BCAN RX Fifo
     * Overrun.
     */
    LLCE_ERROR_BCAN_RXFIFO_OVERRUN,
    /**
     * @brief CAN firmware error: Reports data lost event due to resources
     * exceeded after the frame was received
     */
    LLCE_ERROR_DATA_LOST,
    /** @brief CAN firmware error: The number of Message Buffers available for transmission arbitration was exceeded or the status register indicates that the TXLUT accelerator is full. */
    LLCE_ERROR_TXLUT_FULL,
    /** @brief CAN firmware error: A command with an unknown id was issued or the current host tried to overlap the other host's resources at initialization. */
    LLCE_ERROR_CMD_PROCESSING,
    /** @brief CAN firmware error: Reserved for future use. */
    LLCE_ERROR_CODE_RESERVED_1,
    /** @brief CAN firmware error: Indicates hardware malfunction when trying to perform a read or write operation on RXLUT registers. */
    LLCE_ERROR_RXLUT_ACCESS_MODE,
    /** @brief CAN firmware error: Indicates hardware malfunction when trying to perform a read or write operation on RXLUT registers. */
    LLCE_ERROR_RXLUT_SEARCH_MODE,
    /** @brief CAN firmware error: Indicates hardware malfunction when trying to perform a read on RXLUT registers and no value was obtained within a configured timeout. */
    LLCE_ERROR_RXLUT_SLOW_OPERATION,
    /** @brief CAN firmware error: Indicates hardware malfunction when trying to perform a read on the RXLUT status register during search operation and no value was obtained within a configured timeout. */
    LLCE_ERROR_RXLUT_INCOMPLETE_OP,
    /** @brief CAN firmware error: Indicates hardware malfunction when trying to perform a read on the RXLUT status register during flush operation and no value was obtained within a configured timeout. */
    LLCE_ERROR_RXLUT_OPERATING_MODE,
    /** @brief CAN firmware error: Failed to configure the filter entry address and issue write command. */
    LLCE_ERROR_RXLUT_INIT_SLOW_OP,
    /** @brief CAN firmware error: Reserved for future use. */
    LLCE_ERROR_CODE_RESERVED_2,
    /** @brief CAN firmware error: Reserved for future use. */
    LLCE_ERROR_CODE_RESERVED_3,
    /** @brief CAN firmware error: Reserved for future use. */
    LLCE_ERROR_CODE_RESERVED_4,
    /** @brief CAN firmware error: Reserved for future use. */
    LLCE_ERROR_CODE_RESERVED_5,
    /** @brief CAN firmware error: Reserved for future use. */
    LLCE_ERROR_CODE_RESERVED_6,
    /** @brief CAN firmware error: Controller is not started or bus-off event has occured. */
    LLCE_ERROR_CTRL_NOT_READY,
    /** @brief CAN firmware error: A bus off event was triggered.
     * This notification is skipped in case of auto-recovery.
     */
    LLCE_ERROR_BUSOFF,
    /** @brief CAN firmware error: Logging FIFO is full. */
    LLCE_ERROR_FIFO_LOG_FULL,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_CODE_RESERVED_7,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_CODE_RESERVED_8,
    /**
     * @brief CAN firmware error: Error reported due to the rx core not
     * responding.
     */
    LLCE_ERROR_COMMAND_RXPPE_NORESPONSE,
    /**
     * @brief CAN firmware error: Error reported due to frpe core not
     * responding.
     */
    LLCE_ERROR_COMMAND_AF_NORESPONSE,
    /**
     * @brief CAN firmware error: Error reported because the controller is
     * not stopped.
     */
    LLCE_ERROR_COMMAND_DEINIT_NOTSTOP,
    /**
     * @brief CAN firmware error: Error reported because the host didn't
     * read all the RX tokens (indexes in fifos). LLCE waits for indexes
     * to be read and returned.
     */
    LLCE_ERROR_RXTOKENS_UNRETURNED,
    /**
     * @brief CAN firmware error: Error reported because the host didn't
     * read all the ACKs (indexes in fifos). LLCE waits for indexes to be
     * read.
     */
    LLCE_ERROR_TXACK_NOT_READ,
    /**
     * @brief CAN firmware error: Error reported because the requested
     * command is not in the list of supported commands.
     */
    LLCE_ERROR_COMMAND_NOTSUPPORTED,
    /**
     * @brief CAN firmware error: Error reported because command is not
     * validated by the command flow.
     */
    LLCE_ERROR_COMMAND_NOTVALIDATED,
    /**
     * @brief CAN firmware error: Error reported because the requested
     * command is correct but it not accepted.
     */
    LLCE_ERROR_COMMAND_NOTACCEPTED,
    /**
     * @brief CAN firmware error: Error reported because the requested
     * command parameters are invalid.
     */
    LLCE_ERROR_COMMAND_INVALID_PARAMS,
    /** @brief CAN firmware error: Reserved for future use. */
    LLCE_ERROR_CODE_RESERVED_9,
    /**
     * @brief CAN firmware error: Reports frame accepted, but not delivered
     * to host because of filters misconfiguration.
     */
    LLCE_ERROR_FRAME_NOT_DELIVERED,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_CODE_RESERVED_10,
    /**
     * @brief CAN firmware error: Reports frame accepted, but not delivered
     * to host due to lack of descriptors in software FIFO.
     */
    LLCE_ERROR_FRAME_NOT_DELIVERED_TO_HOST,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_CODE_RESERVED_12,
    /**
     * @brief CAN firmware error: Error reported because there are no
     * filters available to be set for a specific controller.
     */
    LLCE_ERROR_FILTERS_FULL,
    /**
     * @brief CAN firmware error: The filter pointed by the related address
     * is not used by the related controller.
     */
    LLCE_ERROR_FILTERS_NOTEXIST,
    /** @brief CAN firmware error: There are no free configuration filters.
     */
    LLCE_ERROR_FILTERS_MASK_EMPTY,
    /** @brief CAN firmware error: There are no free configuration filters.
     */
    LLCE_ERROR_FILTERS_RANGE_EMPTY,
    /** @brief CAN firmware error: There are no free exact match filters. */
    LLCE_ERROR_FILTERS_EM_EMPTY,
    /** @brief CAN firmware error: The index returned by host is not valid, possibly a duplicate index. */
    LLCE_ERROR_IDX_NOT_VALID_HOST,
    /** @brief CAN firmware error: The index returned by logging is not valid, the associated destination didn't match.
     */
    LLCE_ERROR_IDX_NOT_VALID_LOG,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_CODE_RESERVED_13,
    /**
     * @brief CAN firmware error: Reserved for future use.
     * to HSE because of full FIFO.
     */
    LLCE_ERROR_CODE_RESERVED_14,
    /**
     * @brief CAN firmware error: Tx frame was dropped because MAC generation failed.
     */
    LLCE_ERROR_TXFRAME_MAC_GEN_ERROR,
    /**
     * @brief CAN firmware error: Rx frame was dropped because it is not
     * authentic.
     */
    LLCE_ERROR_RXFRAME_AUTH_ERROR,
    /**
     * @brief CAN firmware error: Reserved for future use.
     * TX core.
     */
    LLCE_ERROR_CODE_RESERVED_16,
    /**
     * @brief CAN firmware error: Reserved for future use.
     */
    LLCE_ERROR_CODE_RESERVED_17,
    /** @brief CAN firmware error: RX Software FIFO is empty. */
    LLCE_ERROR_RX_SW_FIFO_EMPTY,
    /** @brief AF error : error communicating with PFE due to PFE internal error*/
    LLCE_ERROR_PFEIF,
    /** @brief AF error : error communicating with HSE due to HSE internal error*/
    LLCE_ERROR_HSEIF,
    /**
     * @brief Generic firmware code: Command was executed successfully by
     * LLCE Firmware.
     */
    LLCE_FW_SUCCESS,
    /**
     * @brief Generic firmware error: During command execution
     * an error condition was detected.
     */
    LLCE_FW_ERROR,
    /**
     * @brief Generic firmware code: Default value of command return
     * status, set by the host before to send it to LLCE firmware.
     */
    LLCE_FW_NOTRUN,
    /**
     * @brief CAN firmware error: Internal Descriptor was not returned
     * to the source.
     */
    LLCE_ERROR_INTERNALDESC_NOT_RETURNED,
    /**
     * @brief CAN firmware error: Internal Descriptor was not delivered
     * to the destination.
     */
    LLCE_ERROR_INTERNALDESC_NOT_DELIVERED,
    /**
     * @brief CAN firmware error: Internal Descriptor is not available because 
     * the internal LLCE software FIFO is empty.
     */
    LLCE_ERROR_INTERNALDESC_NOTAVAIL,
    /**
     * @brief CAN firmware error: Internal Descriptor software FIFO is full.
     */
    LLCE_ERROR_INTERNALDESC_FIFO_FULL,
    /** @brief CAN firmware error: Message Buffer is not available.
     * the internal message buffer software FIFO is empty.
     */
    LLCE_ERROR_MB_NOTAVAIL,
    /** @brief CAN firmware error: Message Buffer software FIFO is full. */
    LLCE_ERROR_MB_FIFO_FULL,
    /**
     * @brief CAN firmware error: Maximum number of Tx MB per controller for
     * AF is reached.
     */
    LLCE_ERROR_NO_MB_AVAILABLE,
    /** @brief CAN firmware error: The source of the request did not match any of the LLCE cores ids. */
    LLCE_ERROR_UNKNOWN_SRC,
    /** @brief CAN firmware error: Unknown destination of the request : it's neither a CAN or ETHERNET channel, nor the host. */
    LLCE_ERROR_UNKNOWN_DEST,
    /** @brief CAN firmware error: Unknown request in intercore communication. */
    LLCE_ERROR_UNKNOWN_REQUEST,
    /** @brief CAN firmware error: Issued for frames with DLC greater than 8 where destination is not FD . */
    LLCE_ERROR_CONVERSION,
    /**
     * @brief CAN firmware error: AbortMB request failed due to no pending
     * transmission that can be aborted.
     */
    LLCE_ERROR_NO_MB_TO_ABORT,
    /**
     * @brief CAN firmware error: Index not recovered from DTE after Stop
     * or busoff event.
     */
    LLCE_ERROR_INDEX_NOT_RECOVERED,
    /** @brief CAN firmware error: The controller did not exit from freeze mode within a conifgured timeout. */
    LLCE_ERROR_RESET_PENDING,
    /** @brief CAN firmware fatal error: core has entered an error state and is not recoverable. */
    LLCE_ERROR_FATAL,
    /** @brief CAN firmware notification: BCAN is ready to leave bus-off
     * state after the automatic recovery procedure
     */
    LLCE_NOTIF_BUSOFF_DONE,
    /** @brief CAN firmware error: TXWRN is set when the Tx error counter ECR[TEC] reached 96. */
    LLCE_ERROR_BCAN_TXWRN,
    /** @brief CAN firmware error: RXWRN is set when the Rx error counter ECR[REC] reached 96. */
    LLCE_ERROR_BCAN_RXWRN,
    /** @brief CAN firmware error: PASSERR is set when BCAN enters Passive state. */
    LLCE_ERROR_BCAN_PASSERR,
    /** @brief CAN firmware notification: BCAN exits Passive state. */
    LLCE_NOTIF_BCAN_EXIT_PASSIVE_STATE,
    /** @brief CAN firmware notification: There was an attempt to perform routing to a disabled destination. */
    LLCE_ERROR_ROUTINGCHANNEL_DISABLED,
    /** @brief CAN firmware notification: Shutdown request received from host. */
    LLCE_SHUTDOWN_REQUESTED,
    /** @brief CAN firmware notification: Core has entered shutdown state. */
    LLCE_SHUTDOWN_ENTERED,
    /** @brief CAN firmware notification: Core has received an unexpected event during shutdown and
     * is halted but awake */
    LLCE_SHUTDOWN_FAILED,
    /** @brief Generic firmware code: FW successfully booted in headless mode */
    LLCE_HEADLESS_SUCCESS,
    /** @brief Generic firmware error: Invalid InitPlatform section in headless configuration */
    LLCE_HEADLESS_INITPLATFORM_ERROR,
    /** @brief Generic firmware error: Invalid controller Init section in headless configuration */
    LLCE_HEADLESS_INITCTRL_ERROR,
    /** @brief Generic firmware error: Invalid advanced destinations section in headless configuration */
    LLCE_HEADLESS_CREATEDESTINATIONS_ERROR,
    /** @brief Generic firmware error: Invalid regular filter section in headless configuration */
    LLCE_HEADLESS_SETFILTER_ERROR,
    /** @brief Generic firmware error: Invalid advanced filter section in headless configuration */
    LLCE_HEADLESS_SETADVANCEDFILTER_ERROR,
    /** @brief Number of enum elements. It must be kept as the last member of the list. */
    LLCE_FW_RETURNTYPE_COUNT

} Llce_Fw_ReturnType;

/*==================================================================================================
 *                                STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/
/**
 * @brief Boot sequence data type.
 *
 * Data type used to access shared memory area for managing LLCE boot sequence
 **/

typedef struct
{
    /**
     * @brief OUTPUT: Boot Status of TXPPE. This can be NOTRUN, SUCCESS, or
     * a specific ERROR information
     */
    Llce_Fw_ReturnType eTxBootStatus;
    /**
     * @brief OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or
     * a specific ERROR information
     */
    Llce_Fw_ReturnType eRxBootStatus;
    /**
     * @brief OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or
     * a specific ERROR information
     */
    Llce_Fw_ReturnType eDteBootStatus;
    /**
     * @brief OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or
     * a specific ERROR information
     */
    Llce_Fw_ReturnType eFrpeBootStatus;
    /** @brief OUTPUT: LLCE FW version structure. */
    Llce_Fw_VersionType LlceFwVersion;

} LLCE__ALIGNED__PACKED Llce_Mgr_StatusType;

/**
 * @brief Structure for the timestamps of cores 1, 2, and 3
 * 
 * Structure contains the timestamps for the cores 1, 2, and 3 and shall be 
 * read by host in order to verify if a crash, or high delay has occurred or not.
 **/
typedef struct
{
    /** @brief Timestamp for Core 1. */
    uint32 timeStampCore1;
    /** @brief Timestamp for Core 2. */
    uint32 timeStampCore2;
    /** @brief Timestamp for Core 3. */
    uint32 timeStampCore3;
} LLCE__ALIGNED__PACKED Llce_Mgr_TimeStampCoresType;


#ifdef CHECK_ABI_COMPATIBILITY
#pragma ABICHECK stop
#endif
/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
 ==================================================================================================*/

 /** @brief   Helper function that returns the category of a value returned by the LLCE FW.
 *   @details Determines the category of a value returned by the LLCE Firmware.
 *            It can take as input errors, notifications and status values (see Llce_Fw_ReturnType).
 *            It will return the category that value belongs to.
 *   @param[in] eNotificationCode CAN error, notification or status values as they are reported by the LLCE firmware.
 *   @return CAN firmware notification category.
 */
static inline Llce_Fw_Notification_Category Llce_GetNotificationCategory(Llce_Fw_ReturnType eNotificationCode)
{
    Llce_Fw_Notification_Category eNotifCategory;

    switch(eNotificationCode)
    {
        case LLCE_ERROR_BUSOFF:
        case LLCE_NOTIF_BUSOFF_DONE:
            eNotifCategory = LLCE_NOTIFCAT_BUSOFF;
            break;

        /* Treat all the cases leading to DATA_LOST which should be reported to the host */
        case LLCE_ERROR_RXOUT_FIFO_FULL:
        case LLCE_ERROR_MB_NOTAVAILABLE:
        case LLCE_ERROR_BCAN_RXFIFO_OVERRUN:
            eNotifCategory = LLCE_NOTIFCAT_DATA_LOST;
            break;

        /* Can protocol errors */
        case LLCE_ERROR_BCAN_TDCFAIL:
        case LLCE_ERROR_BCAN_ACKERR:
        case LLCE_ERROR_BCAN_CRCERR:
        case LLCE_ERROR_BCAN_BIT0ERR:
        case LLCE_ERROR_BCAN_BIT1ERR:
        case LLCE_ERROR_BCAN_DPBIT0ERR:
        case LLCE_ERROR_BCAN_DPBIT1ERR:
        case LLCE_ERROR_BCAN_STFERR:
        case LLCE_ERROR_BCAN_FRMERR:
        case LLCE_ERROR_BCAN_DPSTFERR:
        case LLCE_ERROR_BCAN_DPFRMERR:
        case LLCE_ERROR_BCAN_DPCRCERR:
        case LLCE_ERROR_BCAN_UNKNOWN_ERROR:
        case LLCE_ERROR_BCAN_FRZ_EXIT:
        case LLCE_ERROR_BCAN_SYNC:
        case LLCE_ERROR_BCAN_FRZ_ENTER:
        case LLCE_ERROR_BCAN_LPM_EXIT:
        case LLCE_ERROR_BCAN_SRT_ENTER:
        case LLCE_NOTIF_BCAN_EXIT_PASSIVE_STATE:
            eNotifCategory = LLCE_NOTIFCAT_CAN_PROTOCOL;
            break;
        case LLCE_ERROR_BCAN_TXWRN:
        case LLCE_ERROR_BCAN_RXWRN:
        case LLCE_ERROR_BCAN_PASSERR:
            eNotifCategory = LLCE_NOTIFCAT_CAN_PROTOCOL_CRITICAL_STATE;
            break;

        /* Initialization errors. This category contains errors caused by bad usage or a
           malicious host (eg initialization errors, bad cmd parameters, invalid indexes etc). */
        case LLCE_ERROR_COMMAND_NOTSUPPORTED:
        case LLCE_ERROR_COMMAND_NOTACCEPTED:
        case LLCE_ERROR_COMMAND_INVALID_PARAMS:
        case LLCE_ERROR_RXTOKENS_UNRETURNED:
        case LLCE_ERROR_FILTERS_NOTEXIST:
        case LLCE_ERROR_FILTERS_FULL:
        case LLCE_ERROR_CMD_PROCESSING:
        case LLCE_ERROR_TXACK_NOT_READ:
        case LLCE_ERROR_COMMAND_DEINIT_NOTSTOP:
            eNotifCategory = LLCE_NOTIFCAT_CONFIGURATION;
            break;

        /* Values that are neither errors nor notifications. */
        case LLCE_FW_SUCCESS:
        case LLCE_FW_ERROR:
        case LLCE_FW_NOTRUN:
            eNotifCategory = LLCE_NOTIFCAT_FW_STATUS;
            break;

        default:
            eNotifCategory = LLCE_NOTIFCAT_INTERNAL;
            break;
    }

    return eNotifCategory;
}


#ifdef __cplusplus
}
#endif

#endif /* LLCE_INTERFACEFWMGR_H */

/** @} */
