/**
 *   @file    Llce_InterfaceCanUtils.h
 *
 *   @brief   LLCE data structures and functions for ease of use of LLCE interface
 *   @details This file contains auxiliary data structures and functions wrapped onto the LLCE
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
#ifndef LLCE_INTERFACECANUTILS_H
#define LLCE_INTERFACECANUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __DOXYGEN__
/**
 *
 * @page misra_violations MISRA-C:2012 violations
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
 */
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/
#include "Llce_InterfaceCanTypes.h"

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
 /* Masks used for un-shifted values, for checking user input */
 /** @brief Frame RTR field mask unpacked. */
 #define LLCE_CAN_MB_RTR_UNPACKED_U32                   ((uint32)0x00000001U)
 /** @brief Frame IDE field mask unpacked. */
 #define LLCE_CAN_MB_IDE_UNPACKED_U32                   ((uint32)0x00000001U)
 /** @brief Frame standard ID field mask unpacked. */
 #define LLCE_CAN_MB_IDSTD_MASK_UNPACKED_U32            ((uint32)0x0000007FF)
 /** @brief Frame BRS field mask unpacked. */
 #define LLCE_CAN_MB_BRS_UNPACKED_U32                   ((uint32)0x00000001U)
 /** @brief Frame FDF field mask unpacked. */
 #define LLCE_CAN_MB_FDF_UNPACKED_U32                   ((uint32)0x00000001U)
 /** @brief Frame ESI field mask unpacked. */
 #define LLCE_CAN_MB_ESI_UNPACKED_U32                   ((uint32)0x00000001U)
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief Word0 of a CAN frame.
 *
 * It contains the message ID and related configurations.
 **/
typedef struct
{
    /**
     * @brief INPUT/OUTPUT: Can frame Standard or Extended ID field.
     * In base frame format, only the 11 most significant bits (28-18)
     * are used for frame identification. The 18 least significant bits are ignored.
     * 
     * In extended frame format, all bits (0-28) are used for frame  identification.
     */
    uint32 u32Id;
    /**
     * @brief INPUT/OUTPUT: Can frame Remote Transmission Request field.
     * 
     * If BCAN transmits this bit as one (recessive) and receives it as zero
     * (dominant), it is interpreted as an arbitration 
     * loss. If this bit is transmitted as zero (dominant), then if it 
     * is received as one (recessive), BCAN treats it as a bit error. 
     * If the value received matches the value transmitted, it is considered
     *  a successful bit transmission.
     */
    uint8 u8Rtr;
    /**
     * @brief INPUT/OUTPUT: Can frame Identifier Extension field.
     * 
     * This field identifies whether the frame format is base (standard ID) 
     * or extended.
     */
    uint8 u8Ide;
}LLCE__ALIGNED__PACKED Llce_Can_Word0;

/**
 * @brief Word1 of a CAN frame.
 *
 * It contains CAN frame format and bit rate related configurations.
 **/
typedef struct
{
    /**
     * @brief INPUT/OUTPUT: Can frame Data Length Code field.
     * 
     * This 4-bit field defines the number of bytes in the data field 
     * of a CAN frame (DATA BYTE 0 to DATA BYTE 63). 
     * When RTR = 1, the frame is a remote request and does not include
     * the data field, regardless of the DLC field.
     */
    uint8 u8Dlc;
    /**
     * @brief INPUT/OUTPUT: Can frame FD Format Indicator field.
     * 
     * This bit distinguishes between classical CAN format and CAN FD format frames.
     */
    uint8 u8Fdf;
    /**
     * @brief INPUT/OUTPUT: Can frame Bit Rate Switch field. 
     * 
     * This bit defines whether the bit rate is switched inside a CAN FD frame.
     * This bit is meaningful only if FDF = 1, otherwise it is not used by BCAN.
     */
    uint8 u8Brs;
    /**
     * @brief INPUT/OUTPUT: Can frame Error State Indicator field.
     * 
     * This bit indicates if the transmitting node is error active or error passive.
     * This bit is meaningful only if FDF = 1, otherwise it is not used by BCAN.
     */
    uint8 u8Esi;
}LLCE__ALIGNED__PACKED Llce_Can_Word1;


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief              Pack members of Llce_Can_Word0 struct into CAN frame format.
 * 
 * @details            This is a helper function abstracts the CAN frame layout away
 *                     from the user when building a CAN frame.
 * 
 * @param Word0*       - pointer to struct holding fields of Word0 part from CAN frame.
 *                       The result is to be copied into u32Word0 field of Llce_Can_MbType struct.
 */
static inline uint32 Llce_Can_Pack_Word0(const Llce_Can_Word0* Word0)
{
    uint32 u32Word0_Temp = 0U;

    u32Word0_Temp |= ((Word0->u8Rtr & LLCE_CAN_MB_RTR_UNPACKED_U32) << LLCE_CAN_MB_RTR_SHIFT_U32);
    u32Word0_Temp |= ((Word0->u8Ide & LLCE_CAN_MB_IDE_UNPACKED_U32) << LLCE_CAN_MB_IDE_SHIFT_U32);
    if(LLCE_CAN_MB_IDE_UNPACKED_U32 == (Word0->u8Ide & LLCE_CAN_MB_IDE_UNPACKED_U32))
    {
        /* Extended Id */
        u32Word0_Temp |= (Word0->u32Id & LLCE_CAN_MB_ID_MASK_U32);
    }
    else
    {
        /* Standard Id */
        u32Word0_Temp |= ((Word0->u32Id & LLCE_CAN_MB_IDSTD_MASK_UNPACKED_U32) << LLCE_CAN_MB_IDSTD_SHIFT_U32);
    }

    return u32Word0_Temp;
}

/**
 * @brief              Pack members of Llce_Can_Word1 struct into CAN frame format.
 * 
 * @details            This is a helper function abstracts the CAN frame layout away
 *                     from the user when building a CAN frame. 
 * 
 * @param Word1*       - pointer to struct holding fields of Word1 part from CAN frame.
 *                       The result is to be copied into u32Word1 field of Llce_Can_MbType struct.
 */
static inline uint32 Llce_Can_Pack_Word1(const Llce_Can_Word1* Word1)
{
    uint32 Word1_temp = 0U;

    Word1_temp |= ((Word1->u8Brs & LLCE_CAN_MB_BRS_UNPACKED_U32) << LLCE_CAN_MB_BRS_SHIFT_U32);
    Word1_temp |= ((Word1->u8Fdf & LLCE_CAN_MB_FDF_UNPACKED_U32) << LLCE_CAN_MB_FDF_SHIFT_U32);
    Word1_temp |= ((Word1->u8Esi & LLCE_CAN_MB_ESI_UNPACKED_U32) << LLCE_CAN_MB_ESI_SHIFT_U32);
    Word1_temp |= (Word1->u8Dlc & LLCE_CAN_MB_DLC_MASK_U32);

    return Word1_temp;
}

/**
 * @brief              Unpack fields from CAN frame into Llce_Can_Word0 struct.
 * 
 * @details            This is a helper function which extracts the fields of Word0
 *                     from a CAN frame and populates the fields of Llce_Can_Word0 struct.
 *                     
 * @param u32Word0     - Word0 part of CAN frame with fields that match CAN layout.
 *                       The input parameter is u32Word0 field of Llce_Can_MbType struct.
 */
static inline Llce_Can_Word0 Llce_Can_Unpack_Word0(uint32 u32Word0)
{
    Llce_Can_Word0 Word0;

    Word0.u8Rtr = (uint8)((u32Word0 & LLCE_CAN_MB_RTR_U32) >> LLCE_CAN_MB_RTR_SHIFT_U32);
    Word0.u8Ide = (uint8)((u32Word0 & LLCE_CAN_MB_IDE_U32) >> LLCE_CAN_MB_IDE_SHIFT_U32);
    if(LLCE_CAN_MB_IDE_UNPACKED_U32 == (Word0.u8Ide & LLCE_CAN_MB_IDE_UNPACKED_U32))
    {
        /* Extended Id */
        Word0.u32Id = u32Word0 & LLCE_CAN_MB_ID_MASK_U32;
    }
    else
    {
        /* Standard Id */
        Word0.u32Id = ((u32Word0 & LLCE_CAN_MB_IDSTD_MASK_U32) >> LLCE_CAN_MB_IDSTD_SHIFT_U32);
    }

    return Word0;
}

/**
 * @brief              Unpack fields from CAN frame into Llce_Can_Word1 struct.
 * 
 * @details            This is a helper function which extracts the fields of Word1
 *                     from a CAN frame and populates the fields of Llce_Can_Word1 struct.
 * 
 * @param u32Word1     - Word1 part of CAN frame with fields that match CAN layout.
 *                       The input parameter is u32Word1 field of Llce_Can_MbType struct.
 */
static inline Llce_Can_Word1 Llce_Can_Unpack_Word1(uint32 u32Word1)
{
    Llce_Can_Word1 Word1;

    Word1.u8Esi = (uint8)((u32Word1 & LLCE_CAN_MB_ESI_U32) >> LLCE_CAN_MB_ESI_SHIFT_U32);
    Word1.u8Brs = (uint8)((u32Word1 & LLCE_CAN_MB_BRS_U32) >> LLCE_CAN_MB_BRS_SHIFT_U32);
    Word1.u8Fdf = (uint8)((u32Word1 & LLCE_CAN_MB_FDF_U32) >> LLCE_CAN_MB_FDF_SHIFT_U32);
    Word1.u8Dlc = (uint8)(u32Word1 & LLCE_CAN_MB_DLC_MASK_U32);

    return Word1;
}

/**
 * @brief              Retrieve message buffer from shared memory based on rx descriptor index and 
 *                     unpack fields from the message buffer.
 * 
 * @details            This is a helper function which takes a descriptor as input
 *                     and returns the corresponding message buffer, which can be either a long (64 bytes) or short (8bytes) one.
 *                     It also retrieves the relevant fields from the message buffer.
 *                     The lower indexes correspond to long message buffers, followed by the short ones 
 *                     in the rx descriptor array, Llce_Can_RxMbDescriptorType Can_Rx_aMbDesc.
 * 
 * @param pCan_SharedMemory   - Pointer to shared memory.
.* @param u16RxMbDescIdx      - Rx message buffer descriptor index.
 * @param u32Word0            - Word0 field of message buffer.
 * @param u32Word1            - Word1 field of message buffer.
 * @param u8Payload           - Payload - either long or short.
 * @param u32Timestamp        - Timestamp from a clock source.
 */
static inline void Llce_Can_GetMbData(volatile Llce_Can_SharedMemoryType* pCan_SharedMemory, uint16 u16RxMbDescIdx, uint32* u32Word0, uint32* u32Word1, uint8** u8Payload, uint32* u32Timestamp)
{   
    /* Decide whether it's a 64B frame or a 8B frame (Short frame) */
    if (u16RxMbDescIdx < LLCE_CAN_CONFIG_MAXRXMB)
    {
        *u32Word0 = pCan_SharedMemory->Can_aMb[u16RxMbDescIdx].u32Word0;
        *u32Word1 =  pCan_SharedMemory->Can_aMb[u16RxMbDescIdx].u32Word1;
        *u8Payload = (uint8*)pCan_SharedMemory->Can_aMb[u16RxMbDescIdx].u8Payload;
        *u32Timestamp = pCan_SharedMemory->Can_aMb[u16RxMbDescIdx].u32Timestamp;
    }
    else
    {
        *u32Word0 = pCan_SharedMemory->Can_aSMb[u16RxMbDescIdx - LLCE_CAN_CONFIG_MAXRXMB].u32Word0;
        *u32Word1 = pCan_SharedMemory->Can_aSMb[u16RxMbDescIdx - LLCE_CAN_CONFIG_MAXRXMB].u32Word1;
        *u8Payload = (uint8*)pCan_SharedMemory->Can_aSMb[u16RxMbDescIdx - LLCE_CAN_CONFIG_MAXRXMB].u8Payload;
        *u32Timestamp = pCan_SharedMemory->Can_aSMb[u16RxMbDescIdx - LLCE_CAN_CONFIG_MAXRXMB].u32Timestamp;
    }

}

/**
* @brief          Retrieve the SEMA42_GATE corresponding to a given FIFO group idx (RXOUT/TXACK) 
*                 and a given HIF (Host Interface)
* @details        The SEMA42_GATE is used to lock the access to the FIFO IER register which is
*                 handled by LLCE and host. 
*
* @param[in]      u8FifoIdx FIFO group idx (RXOUT/TXACK)
* @param[in]      u8Hif Host Interface
*
* <TABLE>
* <TR><TD>Type</TD><TD>Direction</TD><TD>Name</TD><TD>Value Range</TD></TR>
* <TR><TD>uint8</TD><TD>in</TD><TD>u8FifoIdx</TD><TD>LLCE_FIFO_RXOUT_INDEX-LLCE_FIFO_TXACK_INDEX</TD></TR>
* <TR><TD>uint8</TD><TD>in</TD><TD>u8Hif</TD><TD>LLCE_CAN_HIF0-LLCE_CAN_HIF1</TD></TR>
* </TABLE>
* 
* @return         Llce_Sema42_GateType
*
*/
static inline Llce_Sema42_GateType Llce_GetSema42Gate (uint8 u8FifoIdx, uint8 u8Hif)
{
    /** @brief   Semaphore used to protect access to the FIFO IER register shared between
     *           LLCE and host on interrupt enable/disable. */
    static const Llce_Sema42_GateType Can_Sema4_Ier[LLCE_CAN_CONFIG_IER_SEMA4_COUNT][LLCE_CAN_CONFIG_HIF_COUNT] = 
    {
        {LLCE_SEMA42_GATE20, LLCE_SEMA42_GATE21}, 
        {LLCE_SEMA42_GATE22, LLCE_SEMA42_GATE23}
    };

    return Can_Sema4_Ier[u8FifoIdx][u8Hif];
}

#ifdef __cplusplus
}
#endif

#endif /*LLCE_INTERFACECANUTILS_H*/

/** @} */
