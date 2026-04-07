/**
*   
*   @brief   LLCE Generic Software Fifo enums and data structures
*   @details This file contains the Generic Software Fifo data types.
*
*   @addtogroup LLCE_SwFifo
*   @{
*/
/*==================================================================================================
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

#ifndef LLCE_SWFIFO_H
#define LLCE_SWFIFO_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Llce_InterfaceCanTypes.h"
#include "StandardTypes.h"
#include "Can_43_LLCE_Cfg.h"
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
#if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
typedef enum 
{
    LLCE_SWFIFO_FULL,
    LLCE_SWFIFO_EMPTY, 
    LLCE_SWFIFO_OPERATIONAL
} Llce_SwFifo_StatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct
{   
    uint8 *pu8BaseAddr;
    uint16 u16WrByteIdx;
    uint16 u16RdByteIdx;
    uint16 u16MaxNElements;
    uint8  u8ElemSize;
    Llce_SwFifo_StatusType eFifoStatus;
} Llce_SwFifo_Type;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
Llce_Fw_ReturnType Llce_SwFifo_Init(void *pu8BaseAddr, uint8 u8ElemSize, uint16 u16MaxNElements, Llce_SwFifo_Type *pLlce_SwFifo);

Llce_Fw_ReturnType Llce_SwFifo_Push(const void *pGenericElem, Llce_SwFifo_Type *pLlce_SwFifo);

Llce_Fw_ReturnType Llce_SwFifo_Pop(void *pGenericElem, Llce_SwFifo_Type *pLlce_SwFifo);
#endif

#ifdef __cplusplus
}
#endif

#endif /* LLCE_SWFIFO_H */

/** @} */
