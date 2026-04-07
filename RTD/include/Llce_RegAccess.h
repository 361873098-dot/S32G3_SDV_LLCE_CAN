/**
 *   @file    Llce_RegAccess.h
 *
 *   @brief   This file contains functions used for reading and writing
 *            registers
 *   @details This file contains functions used for reading and writing
 *            registers
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

#ifndef LLCE_REGACCESS_H
#define LLCE_REGACCESS_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/
/**
 * @file        Llce_RegAccess.h
 * @brief Include platform types
 */
#include "PlatformTypes.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
 ==================================================================================================*/

/*==================================================================================================
 *                                           CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                       DEFINES AND MACROS
 ==================================================================================================*/
 #if defined(LDRA) || defined(__DOXYGEN__)
     /* Workaround for Doxygen and LDRA tools not to see packed keyword */
      #define LLCE__PACKED
 #else
     #define LLCE__PACKED __attribute__((packed))
 #endif

 #if defined(__DOXYGEN__)
     /* Workaround for Doxygen not to see attribute keyword */
      #define LLCE__ALIGNED__PACKED

     /* Common defines for standard version. Meant to be used by Doxygen*/
     #define S32G2 ON
  
     #define CANETH_ENABLE ON
 
     #define CAN2CAN_ENABLE ON

     #define LIN_ENABLE ON

     #define CANHSE_ENABLE ON

     #define LOGGING_ENABLE ON

     #define AF_ENABLE ON
 #else
     #define LLCE__ALIGNED__PACKED __attribute__((aligned(4), packed))
 #endif
/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/

/*==================================================================================================
 *                                 STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/

/*==================================================================================================
 *                                 STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/

/*==================================================================================================
 *                                     FUNCTION PROTOTYPES
 ==================================================================================================*/

/**
 * @brief 8 bits memory write function
 */
static inline void Reg_Write8(uint32 address, uint8 value)
{
    *(volatile uint8 *)(address) = value;
}

/**
 * @brief 16 bits memory write function.
 */
static inline void Reg_Write16(uint32 address, uint16 value)
{
    *(volatile uint16 *)(address) = value;
}

/**
 * @brief 32 bits memory write function.
 */
static inline void Reg_Write32(uint32 address, uint32 value)
{
    *(volatile uint32 *)(address) = value;
}

/**
 * @brief 8 bits memory read function.
 */
static inline uint8 Reg_Read8(uint32 address)
{
    return (*(volatile uint8 *)(address));
}

/**
 * @brief 16 bits memory read function.
 */
static inline uint16 Reg_Read16(uint32 address)
{
    return (*(volatile uint16 *)(address));
}

/**
 * @brief 32 bits memory read function.
 */
static inline uint32 Reg_Read32(uint32 address)
{
    return (*(volatile uint32 *)(address));
}

/**
 * @brief 8 bits indexed memory write function.
 * Index i must have the data type uint32.
 */
static inline void Reg_Awrite8(uint32 address, uint32 i, uint8 value)
{
    *(volatile uint8 *)(address + i) = value;
}

/**
 * @brief 16 bits indexed memory write function.
 * Index i must have the data type uint32.
 */
static inline void Reg_Awrite16(uint32 address, uint32 i, uint16 value)
{
    *(volatile uint16 *)(address + i) = value;
}

/**
 * @brief 32 bits indexed memory write function.
 * Index i must have the data type uint32.
 */
static inline void Reg_Awrite32(uint32 address, uint32 i, uint32 value)
{
    *(volatile uint32 *)(address + i) = value;
}

/**
 * @brief 8 bits indexed memory read function.
 * Index i must have the data type uint32.
 */
static inline uint8 Reg_Aread8(uint32 address, uint32 i)
{
    return (*(volatile uint8 *)(address + i));
}

/**
 * @brief 16 bits indexed memory read function.
 * Index i must have the data type uint32.
 */
static inline uint16 Reg_Aread16(uint32 address, uint32 i)
{
    return (*(volatile uint16 *)(address + ((uint32)(i << 1U))));
}

/**
 * @brief 32 bits indexed memory read function.
 * Index i must have the data type uint32.
 */
static inline uint32 Reg_Aread32(uint32 address, uint32 i)
{
    return (*(volatile uint32 *)(address + ((uint32)(i << 2U))));
}

/**
 * @brief 8 bits bits clearing function.
 */
static inline void Reg_Bit_Clear8(uint32 address, uint8 mask)
{
    (*(volatile uint8 *)(address)) &= (~(mask));
}

/**
 * @brief 16 bits bits clearing function.
 */
static inline void Reg_Bit_Clear16(uint32 address, uint16 mask)
{
    (*(volatile uint16 *)(address)) &= (~(mask));
}

/**
 * @brief 32 bits bits clearing function.
 */
static inline void Reg_Bit_Clear32(uint32 address, uint32 mask)
{
    (*(volatile uint32 *)(address)) &= (~(mask));
}

/**
 * @brief 8 bits bits getting function.
 */
static inline uint8 Reg_Bit_Get8(uint32 address, uint8 mask)
{
    return ((*(volatile uint8 *)(address)) & (mask));
}

/**
 * @brief 16 bits bits getting function.
 */
static inline uint16 Reg_Bit_Get16(uint32 address, uint16 mask)
{
    return ((*(volatile uint16 *)(address)) & (mask));
}

/**
 * @brief 32 bits bits getting function.
 */
static inline uint32 Reg_Bit_Get32(uint32 address, uint32 mask)
{
    return ((*(volatile uint32 *)(address)) & (mask));
}

/**
 * @brief 8 bits bits setting function.
 */
static inline void Reg_Bit_Set8(uint32 address, uint8 mask)
{
    *(volatile uint8 *)(address) |= mask;
}

/**
 * @brief 16 bits bits setting function.
 */
static inline void Reg_Bit_Set16(uint32 address, uint16 mask)
{
    *(volatile uint16 *)(address) |= mask;
}

/**
 * @brief 32 bits bits setting function.
 */
static inline void Reg_Bit_Set32(uint32 address, uint32 mask)
{
    *(volatile uint32 *)(address) |= mask;
}

/**
 * @brief 8 bit clear bits and set with new value
 * @note In the current implementation, it is caller's (user's) responsibility
 *       to make sure that value has only "mask" bits set - (value&~mask)==0
 */
static inline void Reg_Rmw8(uint32 address, uint8 mask, uint8 value)
{
    *(volatile uint8 *)(address) =
        (*(volatile uint8 *)(address) & ((uint8) ~(mask))) | value;
}

/**
 * @brief 16 bit clear bits and set with new value
 * @note In the current implementation, it is caller's (user's) responsibility
 *       to make sure that value has only "mask" bits set - (value&~mask)==0
 */
static inline void Reg_Rmw16(uint32 address, uint16 mask, uint16 value)
{
    *(volatile uint16 *)(address) =
        (*(volatile uint16 *)(address) & ((uint16) ~(mask))) | value;
}

/**
 * @brief 32 bit clear bits and set with new value
 * @note In the current implementation, it is caller's (user's) responsibility
 *       to make sure that value has only "mask" bits set - (value&~mask)==0
 */
static inline void Reg_Rmw32(uint32 address, uint32 mask, uint32 value)
{
    *(volatile uint32 *)(address) =
        (*(volatile uint32 *)(address) & ((uint32) ~(mask))) | value;
}

#ifdef __cplusplus
}
#endif

#endif /* #ifndef LLCE_REGACCESS_H */

/** @} */
