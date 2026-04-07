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

#include "Core_Heartbeat.h"
#include "Llce_RegAccess.h"
#include "Llce_InterfaceFwMgr.h"

/* Macro used for rollover detection of the global counter u32SysTickCounter. (Rollover every ~118h when counting hundreds of microseconds (100us granularity)) */
#define MAX_UINT32_VALUE (uint32)4294967295U
#define MAX_NR_OF_CORE_TIMEOUT   10u

/* Counter increases when a timeout occurs (up to 10) and decreases when it doesn't */
static struct 
{
  uint8 core1TimeoutCounter;
  uint8 core2TimeoutCounter;
  uint8 core3TimeoutCounter;
}timeoutCoreCounter;


static Llce_Mgr_TimeStampCoresType Core_Heartbeat_Time_Elapsed(Llce_Mgr_TimeStampCoresType currentHeartbeatValue, Llce_Mgr_TimeStampCoresType previousHeartbeatValue);
static uint32 Core_Heartbeat_Calculate_Time_Difference(uint32 currentHeartbeatCoreValue, uint32 previousHeartbeatCoreValue);
static void Core_Heartbeat_Update_All_Counters(Llce_Mgr_TimeStampCoresType heartbeatTimeDifference);
static void Core_Heartbeat_Update_Counter(uint32 timestampDifference, uint8 *counter);

void Core_Heartbeat_Init(void)
{
  /* Init already done in Can_Enable_Timestamp() from Platform_Init.c */

}

void Core_Heartbeat_Check(void)
{   
  static volatile Llce_Mgr_TimeStampCoresType previousHeartbeatValue;
  static volatile Llce_Mgr_TimeStampCoresType* pcurrentHeartbeatValue = (Llce_Mgr_TimeStampCoresType*)HEARTBEAT_STRUCTURE_ADDRESS;
  Llce_Mgr_TimeStampCoresType heartbeatTimeDifference;

  heartbeatTimeDifference = Core_Heartbeat_Time_Elapsed(*pcurrentHeartbeatValue, previousHeartbeatValue);

  Core_Heartbeat_Update_All_Counters(heartbeatTimeDifference);

  if(
       (timeoutCoreCounter.core1TimeoutCounter >= MAX_NR_OF_CORE_TIMEOUT) 
    || (timeoutCoreCounter.core2TimeoutCounter >= MAX_NR_OF_CORE_TIMEOUT) 
    || (timeoutCoreCounter.core3TimeoutCounter >= MAX_NR_OF_CORE_TIMEOUT)
    )
  {
    /* Insert reaction here */
  }

  previousHeartbeatValue = *pcurrentHeartbeatValue;
}

/* Increment or decrement a counter based on the time difference between two consecutive timestamps */
static void Core_Heartbeat_Update_Counter(uint32 timestampDifference, uint8 *counter)
{
  if((timestampDifference) > HEARTBEAT_MAX_TIME_DIFFERENCE)
  {
    if(*counter < 255u)
    {
      (*counter)++;
    }
  }
  else
  {
    if(*counter > 0u)
    {
      (*counter)--;
    }
  }
}

/* Update the counter value for every core */
static void Core_Heartbeat_Update_All_Counters(Llce_Mgr_TimeStampCoresType heartbeatTimeDifference)
{
  Core_Heartbeat_Update_Counter(heartbeatTimeDifference.timeStampCore1, &timeoutCoreCounter.core1TimeoutCounter);
  Core_Heartbeat_Update_Counter(heartbeatTimeDifference.timeStampCore2, &timeoutCoreCounter.core2TimeoutCounter);
  Core_Heartbeat_Update_Counter(heartbeatTimeDifference.timeStampCore3, &timeoutCoreCounter.core3TimeoutCounter);
}

/* Update for every core the difference between two consecutive timestamps. */
static Llce_Mgr_TimeStampCoresType Core_Heartbeat_Time_Elapsed(Llce_Mgr_TimeStampCoresType currentHeartbeatValue, Llce_Mgr_TimeStampCoresType previousHeartbeatValue)
{
  Llce_Mgr_TimeStampCoresType heartbeatTimeDifference;

  heartbeatTimeDifference.timeStampCore1 = Core_Heartbeat_Calculate_Time_Difference(currentHeartbeatValue.timeStampCore1, previousHeartbeatValue.timeStampCore1);
  heartbeatTimeDifference.timeStampCore2 = Core_Heartbeat_Calculate_Time_Difference(currentHeartbeatValue.timeStampCore2, previousHeartbeatValue.timeStampCore2);
  heartbeatTimeDifference.timeStampCore3 = Core_Heartbeat_Calculate_Time_Difference(currentHeartbeatValue.timeStampCore3, previousHeartbeatValue.timeStampCore3);

  return heartbeatTimeDifference;
}

/* Calculate the time difference between two consecutive timestamps */
static uint32 Core_Heartbeat_Calculate_Time_Difference(uint32 currentHeartbeatCoreValue, uint32 previousHeartbeatCoreValue)
{
  uint32 timeDifference;
  if(currentHeartbeatCoreValue >= previousHeartbeatCoreValue)
  {
    timeDifference = currentHeartbeatCoreValue - previousHeartbeatCoreValue;
  }
  else
  {
    /* In case of overflow of currentHeartbeatValue */
    timeDifference = MAX_UINT32_VALUE - previousHeartbeatCoreValue + currentHeartbeatCoreValue;
  }
  
  return timeDifference;
}
