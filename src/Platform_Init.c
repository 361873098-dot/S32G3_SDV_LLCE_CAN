/*==================================================================================================
*
* Copyright 2018-2024 NXP  
*
* NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms.
* By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
* the software, you are agreeing that you have read, and that you agree to comply with and are bound
* by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
* may not retain, install, activate or otherwise use the software.
==================================================================================================*/

#include "Llce_RegAccess.h"
#include "Mcu.h"
#include "OsIf.h"
#include "Platform.h"
#include "CDD_Rm.h"
#ifdef USE_PORT_HLD
    #include "Port.h" /* EB Tresos demo project */
#else
    #include "Siul2_Port_Ip.h" /* S32DS demo project */
#endif

#define MACRO_CONCAT(a,b) a##b
#define MACRO_CONFIG(a,b) MACRO_CONCAT(a, b)
#ifndef CONFIG_VARIANT_USED
 #define MCU_VARIANT    NULL_PTR
 #define PORT_VARIANT   NULL_PTR
#else
 #define MCU_VARIANT    &MACRO_CONFIG(Mcu_Config_, CONFIG_VARIANT_USED)
 #define PORT_VARIANT   &MACRO_CONFIG(Port_Config_, CONFIG_VARIANT_USED)
#endif

/* Bcan Timestamping related defines */
#define TST_CTRL_REG_ADDR   0x4007C0F0  /* TIMESTAMP_CONTROL_REGISTER */
#define TST_SOURCE_SEL_MASK 0x00000001  /* Timestamp 1 counter output is selected as timestamp module output */
#define TST_ENABLE_MASK     0x00000004  /* Timestamp module enable control */
#define STM7_BASE_ADDR      0x40228000  /* STM_7 base address */
#define STM7_ENABLE_MASK    0x00000001  /* STM_7 enable bit */
#define STMTS_REG_ADDR      0x4400C000  /* STM_TS register address */
#define STMTS_SEL_MASK      0x00008501  /* STM_TS mask to set presclarer to 133 */

static void Can_Enable_Timestamp(void);

void PlatformInit(void)
{
    #if (RM_PRECOMPILE_SUPPORT == STD_OFF)
        Rm_Init(&Rm_Config_VS_0);
    #else
        Rm_Init(NULL_PTR);
    #endif

    /* Configure S32G clocks */
    /* Enable LLCE partition */
    Mcu_Init(MCU_VARIANT);
    Mcu_InitClock(McuClockSettingConfig_0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
    Mcu_SetMode(McuModeSettingConf_0);

#ifdef USE_PORT_HLD
    Port_Init(PORT_VARIANT);
#else
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
#endif

    OsIf_Init(NULL_PTR); /* enable system timer for timeout detection */

    /* Configurations for IRQ routing, priority and enable through Platform plugin. */
    Platform_Init(NULL_PTR);

    Can_Enable_Timestamp();

}

/*================================================================================================*/
/**
@brief         Enable Bcan timestamping
@details       Select timestamp source and enable timestamping
*/
/*================================================================================================*/
static void Can_Enable_Timestamp(void)
{
	/* Select timestamp source STM_7 and enable timestamp module in TIMESTAMP_CONTROL_REGISTER */
    Reg_Bit_Set32(TST_CTRL_REG_ADDR, TST_SOURCE_SEL_MASK | TST_ENABLE_MASK);

	/*start STM_7*/
	Reg_Bit_Set32(STM7_BASE_ADDR, STM7_ENABLE_MASK);

    /* Set STM Prescaler 133. - This shall offer 1ms ticks */
    Reg_Bit_Set32(STMTS_REG_ADDR, STMTS_SEL_MASK);
}


