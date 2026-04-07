/*==================================================================================================
*
* Copyright 2024 NXP  
*
* NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms.
* By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
* the software, you are agreeing that you have read, and that you agree to comply with and are bound
* by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
* may not retain, install, activate or otherwise use the software.
==================================================================================================*/

#ifndef CORE_HEARTBEAT
#define CORE_HEARTBEAT

#include "StandardTypes.h"

#define HEARTBEAT_STRUCTURE_ADDRESS   (0x4384FFD0U)
#define HEARTBEAT_MAX_TIME_DIFFERENCE (100u)

void Core_Heartbeat_Init(void);
void Core_Heartbeat_Check(void);

#endif /* CORE_HEARTBEAT */
