/**
*   
*   @brief   LLCE Generic Software Fifo functions
*   @details This file contains the LLCE Generic Software Fifo function definitions.
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

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Llce_SwFifo.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/

/*=================================================================================================
*                                            LOCAL FUNCTIONS 
==================================================================================================*/        

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
/**
    * @brief          Initialize the Software Fifo structure with needed fields.
    * @details        Receives the size of the elements stored in the FIFO, the number of elements
    *                 able to be stored in the FIFO, the base address and the structure itself needed
    *                 to be initialized and updates the fields: u16MaxNElements, u16WrByteIdx, u16RdByteIdx,
    *                 pu8BaseAddr, u8ElemSize, eFifoStatus
    *  
    * @param          pu8BaseAddr - pointer to the base address of the buffer used by the FIFO
    * @param          u8ElemSize - the size of the elements stored in the FIFO
    * @param          u16MaxNElements - the maximum number of elements stored in the FIFO
    * @param          pLlce_SwFifo - pointer to the Software Fifo structure used
    *
    * @retval         Llce_Fw_ReturnType
    *
    * @pre            A buffer should be declared in order to be passed to the FIFO 
    *
    */
Llce_Fw_ReturnType Llce_SwFifo_Init(void *pu8BaseAddr, uint8 u8ElemSize, uint16 u16MaxNElements, Llce_SwFifo_Type *pLlce_SwFifo)
{   
    pLlce_SwFifo->u16MaxNElements = u16MaxNElements;
    pLlce_SwFifo->u16WrByteIdx = 0;
    pLlce_SwFifo->u16RdByteIdx = 0;
    pLlce_SwFifo->pu8BaseAddr = (uint8*)pu8BaseAddr;
    pLlce_SwFifo->u8ElemSize = u8ElemSize;
    pLlce_SwFifo->eFifoStatus = LLCE_SWFIFO_EMPTY;
    return LLCE_FW_SUCCESS;
}

/**
    * @brief          Stores a new element in the FIFO
    * @details        Receives the element to be stored and the Software FIFO and writes the
    *                 information, byte by byte into the FIFO buffer
    *  
    * @param          pGenericElem - pointer to the element which needs to be pushed into FIFO
    * @param          pLlce_SwFifo - pointer the Software FIFO structure used
    *
    * @retval         Llce_Fw_ReturnType
    *
    * @pre            The FIFO should be initialized before applying any operation on it
    *
    */
Llce_Fw_ReturnType Llce_SwFifo_Push(const void *pGenericElem, Llce_SwFifo_Type *pLlce_SwFifo)
{
    /* Index used to iterate each byte into the elements of struct type */
    uint8 u8CopyIdx;
    /* Variable for return status. */
    Llce_Fw_ReturnType eReturnValue = LLCE_FW_SUCCESS;
    /* Pointer to the element which needs to be pushed. Used for elements of struct type */
    const uint8 *pElem;

    /* Check FIFO STATUS */
    if (pLlce_SwFifo->eFifoStatus == LLCE_SWFIFO_FULL)
    {
        eReturnValue = LLCE_FW_ERROR;
    }
    else /* Fifo not full */
    {   
        switch (pLlce_SwFifo->u8ElemSize)
        {
        case ((uint8)sizeof(uint32)):
            *(uint32*)(&(pLlce_SwFifo->pu8BaseAddr[pLlce_SwFifo->u16WrByteIdx])) = *(const uint32*)pGenericElem;
            
            break;
        case ((uint8)sizeof(uint16)):
            *(uint16*)(&(pLlce_SwFifo->pu8BaseAddr[pLlce_SwFifo->u16WrByteIdx])) = *(const uint16*)pGenericElem;

            break;
        case ((uint8)sizeof(uint8)):
            *(uint8*)(&(pLlce_SwFifo->pu8BaseAddr[pLlce_SwFifo->u16WrByteIdx])) = *(const uint8*)pGenericElem;

            break;
        default: /* used for elements of struct type */
            pElem = (const uint8*)pGenericElem;
            /* Copy each byte from source to destination */
            for (u8CopyIdx = 0; u8CopyIdx < pLlce_SwFifo->u8ElemSize; u8CopyIdx++)
            {
                pLlce_SwFifo ->pu8BaseAddr[pLlce_SwFifo->u16WrByteIdx + u8CopyIdx] = pElem[u8CopyIdx];
            }

            break;
        }

        /* Update the position of the writing index */
        pLlce_SwFifo->u16WrByteIdx += pLlce_SwFifo->u8ElemSize;

        /* Check writing index position and reset if needed */
        if (pLlce_SwFifo->u16WrByteIdx >= (pLlce_SwFifo->u8ElemSize * pLlce_SwFifo->u16MaxNElements))
        {
            pLlce_SwFifo->u16WrByteIdx = 0;
        }

        /* Update FIFO status after push operation */
        if (pLlce_SwFifo->u16WrByteIdx == pLlce_SwFifo->u16RdByteIdx)
        {
            pLlce_SwFifo->eFifoStatus = LLCE_SWFIFO_FULL;
        }
        else
        {
            pLlce_SwFifo->eFifoStatus = LLCE_SWFIFO_OPERATIONAL;
        }
    }

    return eReturnValue;
}

/**
    * @brief          Removes an element in the FIFO
    * @details        Receives a pointer to the location where the element will be stored
    *                 and the Software FIFO and writes the information, byte by byte from
    *                 the FIFO buffer to the destination location
    *  
    * @param          pGenericElem - pointer location where the extracted element will be stored
    * @param          pLlce_SwFifo - pointer the Software Fifo structure used
    *
    * @retval         Llce_Fw_ReturnType
    *
    * @pre            The FIFO should be initialized before applying any operation on it
    *
    */
Llce_Fw_ReturnType Llce_SwFifo_Pop(void *pGenericElem, Llce_SwFifo_Type *pLlce_SwFifo)
{
    /* Index used to iterate each byte into the elements of struct type */
    uint8 u8CopyIdx;
    /* Variable for return status. */
    Llce_Fw_ReturnType eReturnValue = LLCE_FW_SUCCESS;
    /* Pointer to the element which needs to be popped.Used for elements of struct type  */
    uint8 *pElem;
    
    /* Check FIFO STATUS */
    if (pLlce_SwFifo->eFifoStatus == LLCE_SWFIFO_EMPTY)
    {
        eReturnValue = LLCE_FW_ERROR;
    }
    else /* Fifo not empty */
    {   
        switch (pLlce_SwFifo->u8ElemSize)
        {
        case ((uint8)sizeof(uint32)):
            *(uint32*)pGenericElem = *(uint32*)(&(pLlce_SwFifo->pu8BaseAddr[pLlce_SwFifo->u16RdByteIdx]));

            break;
        case ((uint8)sizeof(uint16)):
            *(uint16*)pGenericElem = *(uint16*)(&(pLlce_SwFifo->pu8BaseAddr[pLlce_SwFifo->u16RdByteIdx]));

            break;
        case ((uint8)sizeof(uint8)):
            *(uint8*)pGenericElem = *(uint8*)(&(pLlce_SwFifo->pu8BaseAddr[pLlce_SwFifo->u16RdByteIdx]));

            break;
        default: /* used for elements of struct type */
            pElem = (uint8*)pGenericElem;
            /* Copy each byte from source to destination */
            for (u8CopyIdx = 0; u8CopyIdx < pLlce_SwFifo->u8ElemSize; u8CopyIdx++)
            {
                pElem[u8CopyIdx] = pLlce_SwFifo ->pu8BaseAddr[pLlce_SwFifo->u16RdByteIdx + u8CopyIdx];
            }

            break;
        }

        /* Update the position of the reading index */
        pLlce_SwFifo->u16RdByteIdx += pLlce_SwFifo->u8ElemSize;

        /* Check reading index position and reset if needed */
        if (pLlce_SwFifo->u16RdByteIdx >= (pLlce_SwFifo->u8ElemSize * pLlce_SwFifo->u16MaxNElements))
        {
            pLlce_SwFifo->u16RdByteIdx = 0;
        }
        /* Update FIFO status after pop operation */
        if (pLlce_SwFifo->u16WrByteIdx == pLlce_SwFifo->u16RdByteIdx)
        {
            pLlce_SwFifo->eFifoStatus = LLCE_SWFIFO_EMPTY;
        }
        else
        {
            pLlce_SwFifo->eFifoStatus = LLCE_SWFIFO_OPERATIONAL;
        }
    }

    return eReturnValue;
}
#endif

#ifdef __cplusplus
}
#endif

/** @} */
