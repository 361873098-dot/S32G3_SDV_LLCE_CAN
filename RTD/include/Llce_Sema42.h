/**
*   @addtogroup LLCE_IP_Drivers
*   @{
*   @addtogroup LLCE_SEMA42
*   @{
*   
*   @brief   Semaphores2 (SEMA42) module data structures and defines
*   @details This file contains the Semaphores2 (SEMA42) data structures, defines and function declarations.
*
*/
/*==================================================================================================
*
* Copyright 2018-2023 NXP 
* 
* NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in 
* accordance with the applicable license terms.
* By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
* the software, you are agreeing that you have read, and that you agree to comply with and are bound
* by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
* may not retain, install, activate or otherwise use the software.
==================================================================================================*/

#ifndef LLCE_SEMA42_H
#define LLCE_SEMA42_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

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
#define LLCE_SEMA42_BASEADDR            ((uint32)0x43C20000UL)
#define LLCE_SEMA42_GR(gate)            ((uint32)(LLCE_SEMA42_BASEADDR + (uint32)(((uint32)(gate) & 0x3FU))))

#define LLCE_SEMA42_GR_GTFSM_0          (0x0U)
#define LLCE_SEMA42_GR_GTFSM_1          (0x1U)
#define LLCE_SEMA42_GR_GTFSM_2          (0x2U)
#define LLCE_SEMA42_GR_GTFSM_3          (0x3U)
#define LLCE_SEMA42_GR_GTFSM_4          (0x4U)
#define LLCE_SEMA42_GR_GTFSM_5          (0x5U)
#define LLCE_SEMA42_GR_GTFSM_6          (0x6U)
#define LLCE_SEMA42_GR_GTFSM_7          (0x7U)
#define LLCE_SEMA42_GR_GTFSM_8          (0x8U)
#define LLCE_SEMA42_GR_GTFSM_9          (0x9U)
#define LLCE_SEMA42_GR_GTFSM_10         (0xAU)
#define LLCE_SEMA42_GR_GTFSM_11         (0xBU)
#define LLCE_SEMA42_GR_GTFSM_12         (0xCU)
#define LLCE_SEMA42_GR_GTFSM_13         (0xDU)
#define LLCE_SEMA42_GR_GTFSM_14         (0xEU)
#define LLCE_SEMA42_GR_GTFSM_15         (0xFU)
/*==================================================================================================
*                                      Interrupts
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/   
/** @brief    Gate numbers used by sema42 module to lock and unlock gates.
 *  @details  Gate numbers used by sema42 module to lock and unlock gates.
 **/
typedef enum LLCE__PACKED
{
    LLCE_SEMA42_GATE0   =  0UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE1   =  1UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE2   =  2UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE3   =  3UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE4   =  4UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE5   =  5UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE6   =  6UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE7   =  7UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE8   =  8UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE9   =  9UL,          /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE10  =  10UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE11  =  11UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE12  =  12UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE13  =  13UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE14  =  14UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE15  =  15UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE16  =  16UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE17  =  17UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE18  =  18UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE19  =  19UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE20  =  20UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE21  =  21UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE22  =  22UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE23  =  23UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE24  =  24UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE25  =  25UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE26  =  26UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE27  =  27UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE28  =  28UL,         /**< @brief Sema42 Gate *//*free*/
    LLCE_SEMA42_GATE29  =  29UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE30  =  30UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE31  =  31UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE32  =  32UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE33  =  33UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE34  =  34UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE35  =  35UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE36  =  36UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE37  =  37UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE38  =  38UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE39  =  39UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE40  =  40UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE41  =  41UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE42  =  42UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE43  =  43UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE44  =  44UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE45  =  45UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE46  =  46UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE47  =  47UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE48  =  48UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE49  =  49UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE50  =  50UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE51  =  51UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE52  =  52UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE53  =  53UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE54  =  54UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE55  =  55UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE56  =  56UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE57  =  57UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE58  =  58UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE59  =  59UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE60  =  60UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE61  =  61UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE62  =  62UL,         /**< @brief Sema42 Gate */
    LLCE_SEMA42_GATE63  =  63UL,         /**< @brief Sema42 Gate */    

} Llce_Sema42_GateType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef CHECK_ABI_COMPATIBILITY
#pragma ABICHECK stop
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
  
/*==================================================================================================
*                                     INLINE FUNCTION
==================================================================================================*/
/*================================================================================================*/
/** 
* @brief Lock Sema42 gate
* @details The function locks specific sema42 gate.
*/
/*================================================================================================*/
static inline void Llce_Sema42_Lock(Llce_Sema42_GateType eGate, uint8 u8Domain)
{
    /* Lock the semaphore */
    do
    {
        Reg_Write8(LLCE_SEMA42_GR(eGate), u8Domain);
    } while (u8Domain != Reg_Read8(LLCE_SEMA42_GR(eGate)));    

}

/*================================================================================================*/
/** 
* @brief Unlock Sema42 gate
* @details The function unlocks specific sema42 gate.
*/
/*================================================================================================*/
static inline void Llce_Sema42_Unlock(Llce_Sema42_GateType eGate)
{
    /* Unlock the semaphore */
    Reg_Write8(LLCE_SEMA42_GR(eGate), LLCE_SEMA42_GR_GTFSM_0);
}


#ifdef __cplusplus
}
#endif

#endif /* LLCE_SEMA42_H */

/** @} */
/** @} */
