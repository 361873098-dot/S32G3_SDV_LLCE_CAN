/**
 *   @file    Llce_FwVersion.h
 *
 *   @brief   LLCE Version module data structures and defines
 *   @details This file contains the LLCE Version data structures, defines and
 *            function declarations to specify the version information included
 *            in the binaries.
 *
 *   @addtogroup LLCE_version LLCE firmware version
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

#ifndef LLCE_FW_VERSION_H
#define LLCE_FW_VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/
#include "Llce_RegAccess.h"

/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/
#define LLCE_VERSION_MAX_LENGTH 50

/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief Firmware version datatype.
 * It contains the versionString which encodes the 
 * firmware image characteristics, such as: build time,
 * target derivative and the versions of each feature
 **/
typedef struct
{
    /** @brief OUTPUT: LLCE FW version string actual length. */
    uint8 stringLength;
    /** @brief OUTPUT: LLCE FW version string. */
    uint8 versionString[LLCE_VERSION_MAX_LENGTH];
} LLCE__ALIGNED__PACKED Llce_Fw_VersionType;

/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* LLCE_FW_VERSION_H*/

/** @} */
