/**
*   @file    Can_Llce.c
*   @implements Can_Llce.c_Artifact
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - IP module implementation.
*   @details Low Level Driver implementation.
*
*   @internal
*   @{
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.11
*   Build Version        : S32_RTD_1_0_11_D2511_ASR_REL_4_4_REV_0000_20251121
*
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
#include "Can_43_LLCE.h"
#include "Can_43_LLCE_IPW.h"
#include "Can_43_LLCE_AFcfg.h"
#include "Can_43_LLCE_Externals.h"
#include "Can_Llce_Types.h"
#include "Can_Callback.h"
#include "SchM_Can_43_LLCE.h"

#include "OsIf.h"
#include "Mcal.h"
#include "Llce_InterfaceFifo.h"
#include "Llce_FwVersion.h"
#include "Llce_SwFifo.h"
#include "Llce_InterfaceCanUtils.h"

#if ((LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON))
 /* memset */
 #include <string.h>
 /* PFE interface enabled */
 #include <pfe_minihif_drv.h>
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Can_Llce.c
*/
#define CAN_LLCE_VENDOR_ID_C                    43
#define CAN_LLCE_AR_RELEASE_MAJOR_VERSION_C     4
#define CAN_LLCE_AR_RELEASE_MINOR_VERSION_C     4
#define CAN_LLCE_AR_RELEASE_REVISION_VERSION_C  0
#define CAN_LLCE_SW_MAJOR_VERSION_C             1
#define CAN_LLCE_SW_MINOR_VERSION_C             0
#define CAN_LLCE_SW_PATCH_VERSION_C             11

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and CAN header file are of the same vendor */
#if (CAN_LLCE_VENDOR_ID_C != CAN_LLCE_VENDOR_ID_H)
    #error "Can_Llce.c and Can_Llce.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_LLCE_AR_RELEASE_MAJOR_VERSION_C    != CAN_LLCE_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_LLCE_AR_RELEASE_MINOR_VERSION_C    != CAN_LLCE_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_LLCE_AR_RELEASE_REVISION_VERSION_C != CAN_LLCE_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_Llce.c and Can_Llce.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_LLCE_SW_MAJOR_VERSION_C != CAN_LLCE_SW_MAJOR_VERSION_H) || \
     (CAN_LLCE_SW_MINOR_VERSION_C != CAN_LLCE_SW_MINOR_VERSION_H) || \
     (CAN_LLCE_SW_PATCH_VERSION_C != CAN_LLCE_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_Llce.c and Can_Llce.h are different"
#endif


/* Check if current file and CAN_IPW header file are of the same vendor */
#if (CAN_LLCE_VENDOR_ID_C != CAN_IPW_VENDOR_ID_H)
    #error "Can_43_LLCE.c and Can_43_LLCE_IPW.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_LLCE_AR_RELEASE_MAJOR_VERSION_C    != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_LLCE_AR_RELEASE_MINOR_VERSION_C    != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_LLCE_AR_RELEASE_REVISION_VERSION_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_43_LLCE.c and Can_43_LLCE_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_LLCE_SW_MAJOR_VERSION_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_LLCE_SW_MINOR_VERSION_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_LLCE_SW_PATCH_VERSION_C != CAN_IPW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_43_LLCE.c and Can_43_LLCE_IPW.h are different"
#endif

/* Check if current file and CANIF_CBK header file are of the same version */
#if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_LLCE_AR_RELEASE_MAJOR_VERSION_C != CANIF_CAN_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_LLCE_AR_RELEASE_MINOR_VERSION_C != CANIF_CAN_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_43_LLCE.c and CanIf_Can.h are different"
    #endif
  #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define LLCE_BCAN_SR_FLTCONF_MASK_U32             ((uint32)0x0000000CU)
#define LLCE_BCAN_SR_FLTCONF_ERROR_ACTIVE_U32     ((uint32)0x00000000U)
#define LLCE_BCAN_SR_FLTCONF_ERROR_PASSIVE_U32    ((uint32)0x00000004U)
#define LLCE_BCAN_SR_FLTCONF_BUSOFF10_U32         ((uint32)0x00000008U)
#define LLCE_BCAN_SR_FLTCONF_BUSOFF11_U32         ((uint32)0x0000000CU)
#define LLCE_BCAN_ECR_REC_MASK_U32                ((uint32)0x000000FFU)
#define LLCE_BCAN_ECR_TEC_MASK_U32                ((uint32)0x0000FF00U)
#define LLCE_BCAN_ECR_REC_SHIFT_U8                ((uint8)0U)
#define LLCE_BCAN_ECR_TEC_SHIFT_U8                ((uint8)8U)

#define LLCE_CAN_MB_29BIT_MASK_U32                ((uint32)0x1FFFFFFFU)

#define PFE_HIF_RING_CFG_LENGTH         128U /*number of BD*/
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0) && ((LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0))
 #define CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
 #include "Can_43_LLCE_MemMap.h"

 /* Array to store mapping between destination indexes at configuration and runtime */
 static uint8 Can_au8DestinationIdxMap[LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT];
 
 
 #define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
 #include "Can_43_LLCE_MemMap.h"
#endif /*  (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0) && ((LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0)) */

#if ((LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON))
 #define CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
 #include "Can_43_LLCE_MemMap.h"

 /* PFE interface enabled */
 static pfe_minihif_drv_t llce_minihif;
 
 #define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
 #include "Can_43_LLCE_MemMap.h"
#endif /* ((LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON)) */

#define CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"
/**
* @brief          Array holding current status/run-time configuration of individual hardware controllers
* @details        Array holding current status/run-time configuration of individual hardware controllers
*                 - information like Guard bits, Pre-calculated MB INT masks, Storage space for id, INT nesting level,
*                 Index of MB buffer being canceled,  Controller Options.
*
*
*/
static Can_43_LLCE_ControllerStatusType Can_43_LLCE_ControllerStatuses[LLCE_CAN_CONFIG_MAXCTRL_COUNT];

static uint8 au8VersionStringBuf[LLCE_VERSION_MAX_LENGTH];
static uint8 u8VersionLength = 0;

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
  /* Counters used for HRH-filter mapping */
  #if defined(S32G2XX)
    static uint16 Can_Llce_u16RxLutExactMatchCounter = 0U, Can_Llce_u16RxLutConfigurableCounter = 512U;
  #elif defined(S32G3XX)
    static uint16 Can_Llce_au16RxLutCounter[LLCE_CAN_CONFIG_MAXCTRL_COUNT];
  #endif

    static boolean Can_Llce_bHeadlessInitDone_InitPlatform = FALSE;
    static boolean Can_Llce_bHeadlessInitDone_InitController = FALSE;
    static boolean Can_Llce_bHeadlessInitDone_SetConfiguredReceiveFilters = FALSE;
    static boolean Can_Llce_bHeadlessInitDone_AfInit = FALSE;
    static boolean Can_Llce_bHeadlessInitDone_SetControllerToStartMode[LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
        { FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE  };


#endif /* CAN_LLCE_USE_HEADLESSMODE == STD_ON */

#define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_SHAREDMEMORY
#include "Can_43_LLCE_MemMap.h"

static volatile Llce_Can_SharedMemoryType Can_SharedMemory;
    
#define CAN_43_LLCE_STOP_SEC_SHAREDMEMORY
#include "Can_43_LLCE_MemMap.h"

/** @brief   STM timer used for performance measurements. */
#ifdef CAN_43_LLCE_STM_MEASUREMENT_ENABLE
/* Status variable used to get feedback from Llce when the boot has ended */
extern volatile uint32 Stm_Measurement;
#endif

#define CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

static uint16 Can_u16NotifIntrEnable[LLCE_CAN_CONFIG_HIF_COUNT];

#if (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U) || (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0)
static uint16 Can_Llce_au16RxHrh2FilterAddr[CAN_43_LLCE_MAXHRH_CONFIGURED];
#endif

#if (CAN_43_LLCE_CUSTOM_RX_CALLBACK_USED == STD_ON)
  static Llce_Can_AdvancedFilterType* Can_Llce_apRxHrh2AfFilterCfg[CAN_43_LLCE_MAXHRH_CONFIGURED];
#endif


#if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
/* Buffer table for notification errors reported in polling mode */
static Llce_Can_NotificationType Can_Llce_aNotif1_Table[LLCE_CAN_CONFIG_NOTIF_TABLE_SIZE];
/* Sw fifo for errors buffering */
static Llce_SwFifo_Type Can_Llce_xNotifSwFifo;
#endif

/* Number of interrupt enable requests per interface. Helps to disable the interface interrupt
   only when all the controllers assigned to that interface are being requested to interrupt disable.  */
static uint8 Can_Llce_au8FifoSetIntEnCnt[LLCE_CAN_CONFIG_MAXCTRL_COUNT];

#define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"


#define CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

static const Can_43_LLCE_ConfigType * Can_Llce_pxGlobalConfigs[CAN_43_LLCE_MAX_PARTITIONS];

#define CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"


#define CAN_43_LLCE_START_SEC_CODE
#include "Can_43_LLCE_MemMap.h"


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
static const Can_43_LLCE_ConfigType* Can_Llce_GetCurrentConfig(void);

#if (CAN_43_LLCE_BUSOFF_RECOVERY_ENABLED == STD_OFF)
static void Can_Llce_ControllerBusOff(uint8 u8HwCtrl);
#endif

static inline void Can_Llce_DisableInterrupts (uint8 u8HwCtrl);
static inline void Can_Llce_EnableInterrupts (uint8 u8HwCtrl);
static inline void Can_Llce_ResetIntFlags (uint8 u8HwCtrl);

static Std_ReturnType Can_Llce_SetControllerToStopMode(uint8 u8HwCtrl);
static Std_ReturnType Can_Llce_SetControllerToStartMode(uint8 u8HwCtrl, const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr);
static Std_ReturnType Can_Llce_SetControllerToSleepMode(uint8 u8HwCtrl);
static Std_ReturnType Can_Llce_GetLlceControllerMode(uint8 u8HwCtrl, Llce_Can_CtrlStateType *eLlceControllerMode);
static Llce_Fw_ReturnType Can_Llce_ExecuteIfCommand(uint8 u8HwCtrl);
static void Can_Llce_UpdateMB(const Can_43_LLCE_TxFrameInfoType* TxFrameInfo);
static void Can_Llce_ProcessFilterIdMaskType(Llce_Can_IdLengthType eIdType, volatile Llce_Can_ReceiveFilterType * pxFilter);
static Llce_Fw_ReturnType Can_Llce_InitPlatform(const Can_43_LLCE_ConfigType * pxCurrentConfig, uint8 u8ControllersCount);
static Llce_Fw_ReturnType Can_Llce_InitController(void);
static void Can_Llce_SetConfiguredReceiveFilters(void);
#if (RXLUT2_ENABLE == STD_ON)
static void Can_Llce_SetConfiguredAuxReceiveFilters(void);
#endif
static Std_ReturnType Can_Llce_SendSetFilterCommand(const volatile Llce_Can_ReceiveFilterType *pRxFilters, uint8 filterLoadedCount, uint8 u8HwCtrl);
static Llce_Fw_ReturnType Can_Llce_SendStopCmd(uint8 u8HwCtrl);
static void Can_Llce_ComputeMbConfig(uint32 SduLength, uint32 u32MessageId, boolean bEnabledFD, uint32* pu32MbConfig, uint8* pu8RealDataLength);
static void Can_Llce_ResetFifoContent(uint8 u8Interface);
static inline Std_ReturnType Can_Llce_CheckCommandAvailable(void);
static Std_ReturnType Can_Llce_UpdateToStartMode(uint8 u8HwCtrl, const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr);

#if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0) && ((LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0))
static Llce_Fw_ReturnType Can_Llce_CreateConfiguredAfDestinations(void);
#endif

#if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0)
static void Can_Llce_AfInit( void );
static void Can_Llce_SetConfiguredAfFilters(void);
#endif

static Std_ReturnType Can_Llce_SendSetAfFilterCommand(const volatile Llce_Can_AdvancedFilterType *pAfFilters, uint8 filterLoadedCount, uint8 u8HwCtrl);

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
static void Can_Llce_EmulateSetConfiguredReceiveFilters(void);
  #if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0)
  static void Can_Llce_EmulateSetConfiguredAfFilters(void);
  #endif
#endif

#if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)
static void Can_Llce_ProcessTxPollingClass( uint8 u8PollClassIdx );
#endif

#if (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON)
static void Can_Llce_ProcessRxPollingClass( uint8 u8PollClassIdx );
#endif

#if (CAN_43_LLCE_CUSTOM_RX_CALLBACK_USED == STD_ON)
static boolean Can_Llce_CheckCustomCallback(uint16 u16HrhId, uint32 u32MbMessageId, uint8 u8MbDataLength, uint8* u8FramePayload, uint16 u16RxMbDescIdx);
#endif

/*================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/
static const Can_43_LLCE_ConfigType* Can_Llce_GetCurrentConfig(void)
{
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
    return Can_Llce_pxGlobalConfigs[Can_43_LLCE_GetCoreID()];
#else
    return Can_Llce_pxGlobalConfigs[0];
#endif
}

static inline Std_ReturnType Can_Llce_CheckCommandAvailable(void)
{
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Check if the command buffer is not already used by other command request. */
    if (LLCE_FIFO_FNEMTY_U32 != (Reg_Read32(LLCE_FIFO_STATUS0(LLCE_FIFO_CMD_BASE_ADDRESS(pxConfig->u8ActiveHif))) & (uint32)(LLCE_FIFO_FNEMTY_U32)))    
    {
        eReturnValue = (Std_ReturnType)E_OK;
    }

    return eReturnValue;
}

static Std_ReturnType Can_Llce_UpdateToStartMode(uint8 u8HwCtrl, const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Make sure no pending message was left in the FIFOs after the interrupts were disabled. */
    Can_Llce_ResetFifoContent(u8HwCtrl);

    /* (CAN384) Each time the CAN controller state machine is triggered with the state transition value CAN_CS_STARTED, the function
    Can_43_LLCE_SetControllerMode shall re-initialize the CAN controller with the same controller configuration set previously used by functions
    Can_43_LLCE_Init.*/
    if ((Std_ReturnType)E_OK == Can_Llce_ChangeBaudrate( u8HwCtrl, pxBaudrateConfigPtr))
    {
        /*
        (CAN261) The function Can_43_LLCE_SetControllerMode(CAN_CS_STARTED) shall set the hardware registers in a way that makes the CAN controller participating on the network.
        */
        /* Check if the command buffer is not already used by other command request */
        SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
        if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
        {
            /* Configure the command id. */
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETCONTROLLERMODE;

            /* Add command parameter. */
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetControllerMode.eTransition = LLCE_CAN_T_START;
            /* Send the command prepared above to the LLCE in order to be executed. */
            if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( u8HwCtrl ))
            {
                eReturnValue = (Std_ReturnType)E_OK;
            }
        }
        SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief  Disable LLCE_FIFO_FNEMTY_U32 interrupt for the FIFO interface assigned to a given controller.
*/
static inline void Can_Llce_DisableInterrupts (uint8 u8HwCtrl)
{

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    uint32 u32DrvControllerOptions = pxConfig->aHwControllerDescriptors[u8HwCtrl].u32DrvControllerOptions;
    /* Determine physical FIFO Interface assigned to HwCtrl. */
    uint8 u8FifoInterface = pxConfig->aHwControllerDescriptors[u8HwCtrl].u8FifoInterface;

    if (CAN_INTERRUPT_ENABLED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eSetIntEnRequest)
    {
        Can_43_LLCE_ControllerStatuses[u8HwCtrl].eSetIntEnRequest = CAN_INTERRUPT_DISABLED;
        /*Decrement only once per controller interrupt disable request*/
        if (Can_Llce_au8FifoSetIntEnCnt[u8FifoInterface] > 0U)
        {
            Can_Llce_au8FifoSetIntEnCnt[u8FifoInterface]--;
        }
    }

    /* Clear IER only when all controllers assigned to this interface are being requested to disable interrupts. */
    if (0U == Can_Llce_au8FifoSetIntEnCnt[u8FifoInterface])
    {
        if(LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32))
        {
            #ifdef CAN_LLCE_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Llce_Sema42_Lock, Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, pxConfig->u8ActiveHif), LLCE_HOST_CORE_SEMA42_DOMAIN);
            #else
            Llce_Sema42_Lock( Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, pxConfig->u8ActiveHif), LLCE_HOST_CORE_SEMA42_DOMAIN);
            #endif
            
            /* Disable needed interrupt. */
            Reg_Bit_Clear32( LLCE_FIFO_IER(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8FifoInterface)), LLCE_FIFO_FNEMTY_U32);

            #ifdef CAN_LLCE_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Llce_Sema42_Unlock, Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, pxConfig->u8ActiveHif));
            #else
            Llce_Sema42_Unlock( Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, pxConfig->u8ActiveHif));
            #endif
        }

        if(LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32))
        {
            #ifdef CAN_LLCE_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Llce_Sema42_Lock, Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, pxConfig->u8ActiveHif), LLCE_HOST_CORE_SEMA42_DOMAIN);
            #else
            Llce_Sema42_Lock(Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, pxConfig->u8ActiveHif), LLCE_HOST_CORE_SEMA42_DOMAIN);
            #endif

            /* Disable needed interrupt. */
            Reg_Bit_Clear32( LLCE_FIFO_IER(LLCE_FIFO_TXACK_BASE_ADDRESS(u8FifoInterface)), LLCE_FIFO_FNEMTY_U32);

            #ifdef CAN_LLCE_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Llce_Sema42_Unlock, Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, pxConfig->u8ActiveHif));
            #else
            Llce_Sema42_Unlock(Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, pxConfig->u8ActiveHif));
            #endif
        }
    }

    if(LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32))
    {
        /* Clear every bit before disabling the interrupt */
        Can_u16NotifIntrEnable[pxConfig->u8ActiveHif] &= ~(((uint16)1U) << u8HwCtrl);

        Can_Llce_DisableNotifInterrupt(pxConfig->u8ActiveHif);
    }
}

static inline void Can_Llce_ResetIntFlags (uint8 u8HwCtrl)
{
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    uint32 u32DrvControllerOptions = pxConfig->aHwControllerDescriptors[u8HwCtrl].u32DrvControllerOptions;
   /* Determine physical FIFO Interface assigned to HwCtrl. */
    uint8 u8FifoInterface = pxConfig->aHwControllerDescriptors[u8HwCtrl].u8FifoInterface;

    if(LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32))
    {   
        /* Clear all interrupt status flags. */
        Reg_Write32(LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8FifoInterface)),Reg_Read32(LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8FifoInterface))));
    }

     if(LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32))
    {
        /* Clear all interrupt status flags. */
        Reg_Write32(LLCE_FIFO_STATUS1(LLCE_FIFO_TXACK_BASE_ADDRESS(u8FifoInterface)),Reg_Read32(LLCE_FIFO_STATUS1(LLCE_FIFO_TXACK_BASE_ADDRESS(u8FifoInterface))));
    }

}
/*================================================================================================*/
/**
* @brief  Enable LLCE_FIFO_FNEMTY_U32 interrupt for the FIFO interface assigned to a given controller.
*/
static inline void Can_Llce_EnableInterrupts (uint8 u8HwCtrl)
{
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    uint32 u32DrvControllerOptions = pxConfig->aHwControllerDescriptors[u8HwCtrl].u32DrvControllerOptions;
   /* Determine physical FIFO Interface assigned to HwCtrl. */
    uint8 u8FifoInterface = pxConfig->aHwControllerDescriptors[u8HwCtrl].u8FifoInterface;

    if (CAN_INTERRUPT_DISABLED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eSetIntEnRequest)
    {
        Can_43_LLCE_ControllerStatuses[u8HwCtrl].eSetIntEnRequest = CAN_INTERRUPT_ENABLED;
        /*Increment only once per controller interrupt enable request*/
        Can_Llce_au8FifoSetIntEnCnt[u8FifoInterface]++;
    }
    
    if(LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32))
    {   
        #ifdef CAN_LLCE_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Llce_Sema42_Lock, Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, pxConfig->u8ActiveHif), LLCE_HOST_CORE_SEMA42_DOMAIN);
        #else
        Llce_Sema42_Lock( Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, pxConfig->u8ActiveHif), LLCE_HOST_CORE_SEMA42_DOMAIN);
        #endif
        
        /* Enable needed interrupt. */
        Reg_Bit_Set32( LLCE_FIFO_IER(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8FifoInterface)), LLCE_FIFO_FNEMTY_U32);

        #ifdef CAN_LLCE_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Llce_Sema42_Unlock, Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, pxConfig->u8ActiveHif));
        #else
        Llce_Sema42_Unlock( Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, pxConfig->u8ActiveHif));
        #endif
    }
    
    if(LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32))
    {
        #ifdef CAN_LLCE_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Llce_Sema42_Lock, Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, pxConfig->u8ActiveHif), LLCE_HOST_CORE_SEMA42_DOMAIN);
        #else
        Llce_Sema42_Lock(Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, pxConfig->u8ActiveHif), LLCE_HOST_CORE_SEMA42_DOMAIN);
        #endif

        /* Enable needed interrupt. */
        Reg_Bit_Set32( LLCE_FIFO_IER(LLCE_FIFO_TXACK_BASE_ADDRESS(u8FifoInterface)), LLCE_FIFO_FNEMTY_U32);

        #ifdef CAN_LLCE_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Llce_Sema42_Unlock, Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, pxConfig->u8ActiveHif));
        #else
        Llce_Sema42_Unlock(Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, pxConfig->u8ActiveHif));
        #endif
    }
      
    if(LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32))
    {
        Can_Llce_EnableNotifInterrupt(pxConfig->u8ActiveHif);

        Can_u16NotifIntrEnable[pxConfig->u8ActiveHif] |= (((uint16)1U) << u8HwCtrl);
    }

}

/*================================================================================================*/
/**
* @brief  Enable LLCE_FIFO_FNEMTY_U32 interrupt for the FIFO NOTIF of the given Hif.
*/
void Can_Llce_EnableNotifInterrupt(uint8 u8ActiveHif)
{
    if (0U == Can_u16NotifIntrEnable[u8ActiveHif])
    {
        /* Enable NOTIF interrupt. */
        Reg_Bit_Set32( LLCE_FIFO_IER(LLCE_NOTIF_FIFO0_BASE_ADDRESS(u8ActiveHif)), LLCE_FIFO_FNEMTY_U32);
    }
}

/*================================================================================================*/
/**
* @brief  Disable LLCE_FIFO_FNEMTY_U32 interrupt for the FIFO NOTIF of the given Hif.
*/
void Can_Llce_DisableNotifInterrupt(uint8 u8ActiveHif)
{
    if (0U == Can_u16NotifIntrEnable[u8ActiveHif])
    {
        /* Disable NOTIF interrupt. */
        Reg_Bit_Clear32( LLCE_FIFO_IER(LLCE_NOTIF_FIFO0_BASE_ADDRESS(u8ActiveHif)), LLCE_FIFO_FNEMTY_U32);
    }
}

/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to Stop state/mode.
*
*                 This routine is called by:
*                  - Can_Llce_SetControllerMode()
*
* @param[in]      u8HwCtrl CAN controller for which the init shall be done.
*
* @return         Std_ReturnType
* @retval         E_OK transition initiated
* @retval         E_NOT_OK development or production error
*
*/
static Std_ReturnType Can_Llce_SetControllerToStopMode(uint8 u8HwCtrl)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue;
    
    Can_ControllerStateType eCtrlState = CAN_CS_UNINIT;

    if((Std_ReturnType)E_OK == Can_Llce_GetControllerMode(u8HwCtrl, &eCtrlState))
    {
        /*
           (PR-MCAL-3057) The Can driver shall not create a development error if the CanIf requests a transition to a state that was already reached.
        */
        if ( CAN_CS_STOPPED == eCtrlState)
        {
            /* Notify the CanIf about a successfully transition. */
            Can_43_LLCE_ControllerModeIndication(u8HwCtrl, CAN_CS_STOPPED);
            /* If the controller is already in STOP state, return E_OK. */
            eReturnValue = E_OK;
        }
        else
        {
            /* Evaluate transition */
            if ( CAN_CS_STARTED == eCtrlState)
            {
                /*
                  (CAN263) The function Can_43_LLCE_SetControllerMode(CAN_CS_STOPPED) shall set the bits inside the CAN hardware such that the CAN controller
                           stops participating on the network.
                */
                eCommandReturnValue = Can_Llce_SendStopCmd( u8HwCtrl );
                if(LLCE_FW_SUCCESS == eCommandReturnValue)
                {
                    eReturnValue = E_OK;
                }
            }
            else if (CAN_CS_SLEEP == eCtrlState)
            {
                /*
                   (CAN267) If the CAN HW does not support a sleep mode, the transition from SLEEP to STOPPED shall return from the logical sleep mode
                */
                SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState= CAN_CS_STOPPED;
                SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
                /* Notify the CanIf about a successfully transition. */
                Can_43_LLCE_ControllerModeIndication(u8HwCtrl, CAN_CS_STOPPED);

                /* Set API return code.*/
                eReturnValue = E_OK;
            }
            /* Report invalid transition */
            else
            {
                (void)Can_43_LLCE_ReportError((uint8)CAN_43_LLCE_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_LLCE_E_TRANSITION);
            }
        }
    }

    return eReturnValue;
}


static Llce_Fw_ReturnType Can_Llce_SendStopCmd(uint8 u8HwCtrl)
{

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Variable for return status. */
    Llce_Fw_ReturnType eCommandReturnValue = LLCE_FW_NOTRUN;
    
    /* Timeout counter. */
    uint32          u32timeStart = 0U;
    uint32          u32timeElapsed = 0U;
    uint32          u32TicksDelayDuration = 0U;

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    /* Check if the command buffer is not already used by other command request */
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETCONTROLLERMODE;  

        /* Add command parameter. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetControllerMode.eTransition = LLCE_CAN_T_STOP;

        /* Send the command prepared above to the LLCE in order to be executed */
        eCommandReturnValue = Can_Llce_ExecuteIfCommand( u8HwCtrl );
    }
 
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    if (LLCE_FW_SUCCESS == eCommandReturnValue)
    {
        u32TicksDelayDuration = OsIf_MicrosToTicks(CAN_43_LLCE_TIMEOUT_DURATION, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
        
        u32timeStart = OsIf_GetCounter(CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);

        /* 
        [SWS_Can_00372] 
        In case the flag signals that the change takes no effect and the maximum time CanTimeoutDuration is elapsed,
        the function Can_SetControllerMode shall be left and the function Can_Mainfunction_Mode shall continue to poll the flag. 
        */
        do
        {
            u32timeElapsed += OsIf_GetElapsed(&u32timeStart, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
            Can_Llce_MainFunctionMode(u8HwCtrl);
        } while ( (u32timeElapsed < u32TicksDelayDuration) && (CAN_CS_STOPPED != Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState) );
        
        #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(CAN_43_LLCE_FIP_1_STOP_MODE_WHILE_LOOP);
        #endif
    }

    return eCommandReturnValue;
}

/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to Start state/mode.
*
*                 This routine is called by:
*                  - Can_Llce_SetControllerMode()
*
* @param[in]      u8HwCtrl CAN controller for which the init shall be done.
* @param[in]      pxBaudrateConfigPtr Configuration parameters for the controller baud rate settings
*
* @return         Std_ReturnType
* @retval         E_OK transition initiated
* @retval         E_NOT_OK development or production error
*
*/
static Std_ReturnType Can_Llce_SetControllerToStartMode(uint8 u8HwCtrl, const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue;
    /* Timeout counter. */
    uint32          u32timeStart = 0U;
    uint32          u32timeElapsed = 0U;
    uint32          u32TicksDelayDuration = 0U;
    Llce_Can_CtrlStateType eLlceControllerMode = LLCE_CAN_UNINIT_CTRL;
    Can_ControllerStateType eCachedStateCopy;
    
#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();
#endif

    eReturnValue = Can_Llce_GetLlceControllerMode(u8HwCtrl, &eLlceControllerMode);

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
  if((FALSE == pxConfig->bHeadlessModeEnabled) || (TRUE == Can_Llce_bHeadlessInitDone_SetControllerToStartMode[u8HwCtrl]) )
  {
#endif

    if((Std_ReturnType)E_OK == eReturnValue)
    {
        eCachedStateCopy = Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState;
        if ((LLCE_CAN_START_PENDING == eLlceControllerMode) || 
            ((LLCE_CAN_STARTED == eLlceControllerMode) && (CAN_CS_STOPPED == eCachedStateCopy)))
        {
            /* FW is still performing START transition or has switched to START meanwhile  */
            eReturnValue = E_OK;
        }
        else
        {
            /* Valid transitions to Start mode are allowed only from Stop state. */
            if (( LLCE_CAN_STOPPED != eLlceControllerMode) || (CAN_CS_SLEEP == eCachedStateCopy))
            {
                (void)Can_43_LLCE_ReportError((uint8)CAN_43_LLCE_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_LLCE_E_TRANSITION);
                eReturnValue = E_NOT_OK;
            }
            else
            {
               eReturnValue = Can_Llce_UpdateToStartMode(u8HwCtrl, pxBaudrateConfigPtr);
            }
        }
    }

    if ((Std_ReturnType)E_OK == eReturnValue)
    {
        u32TicksDelayDuration = OsIf_MicrosToTicks(CAN_43_LLCE_TIMEOUT_DURATION, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
        u32timeStart = OsIf_GetCounter(CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);

        /*
        [SWS_Can_00372]
        In case the flag signals that the change takes no effect and the maximum time CanTimeoutDuration is elapsed,
        the function Can_SetControllerMode shall be left and the function Can_Mainfunction_Mode shall continue to poll the flag. 
        */
        do
        {
            u32timeElapsed += OsIf_GetElapsed(&u32timeStart, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
            Can_Llce_MainFunctionMode(u8HwCtrl);
        } while ( (u32timeElapsed < u32TicksDelayDuration) && (CAN_CS_STARTED != Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState) );
        
        #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(CAN_43_LLCE_FIP_2_START_MODE_WHILE_LOOP);
        #endif
    }

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
  }
  else
  {
    Can_Llce_bHeadlessInitDone_SetControllerToStartMode[u8HwCtrl] = TRUE;

    Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState= CAN_CS_STARTED;
    
    /* Notify the CanIf about a successfully transition. */
    Can_43_LLCE_ControllerModeIndication(u8HwCtrl, CAN_CS_STARTED);

    /* (CAN196) The function Can_43_LLCE_SetControllerMode shall enable interrupts that are needed in the new state.
    (CAN425)   Enabling of CAN interrupts shall not be executed, when CAN interrupts have been disabled by function CAN_DisableControllerInterrupts.
    */
    if ( CAN_INTERRUPT_ENABLED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eInterruptMode )
    {
        Can_Llce_EnableInterrupts(u8HwCtrl);
    }

    eReturnValue = E_OK;
  }
#endif

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to Sleep state/mode.
*
*                 This routine is called by:
*                  - Can_Llce_SetControllerMode()
*
* @param[in]      u8HwCtrl CAN controller for which the init shall be done.
*
* @return         Std_ReturnType
* @retval         E_OK transition initiated
* @retval         E_NOT_OK development or production error
*
*/
static Std_ReturnType Can_Llce_SetControllerToSleepMode(uint8 u8HwCtrl)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue;
    Can_ControllerStateType eCtrlState = CAN_CS_UNINIT;

    if((Std_ReturnType)E_OK == Can_Llce_GetControllerMode(u8HwCtrl, &eCtrlState))
    {
        /*
           (PR-MCAL-3057) The Can driver shall not create a development error if the CanIf requests a transition to a state that was already reached.
        */
        if ( CAN_CS_SLEEP == eCtrlState )
        {
            /* If the controller is already in SLEEP state, return E_OK. */
            eReturnValue = E_OK;
        }
        else
        {
            /* Valid transitions to Sleep state are only from Stop state. */
            if ( CAN_CS_STOPPED != eCtrlState)
            {
               (void)Can_43_LLCE_ReportError((uint8)CAN_43_LLCE_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_LLCE_E_TRANSITION);
            }
            else
            {
                /* Send stop command to cover intermediate states (e.g. START_PENDING) */
                eCommandReturnValue = Can_Llce_SendStopCmd(u8HwCtrl);

                /* Stop command may return success for START_PENDING or fail if already stopped */
                if( (LLCE_FW_SUCCESS == eCommandReturnValue) ||  (LLCE_ERROR_COMMAND_NOTACCEPTED == eCommandReturnValue) )
                {
                    eReturnValue = E_OK;

                    /*[CAN290]If the CAN HW does not support a sleep mode, the function Can_43_LLCE_SetControllerMode(CAN_CS_SLEEP) shall set the CAN controller to the logical sleep mode*/
                    /*[CAN405] This logical sleep mode shall left only, if function Can_43_LLCE_SetControllerMode(CAN_CS_STOPPED) is called.*/
                    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
                    Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState = CAN_CS_SLEEP;
                    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
                }
            }
        }
    }

    if((Std_ReturnType)E_OK == eReturnValue)
    {
        Can_43_LLCE_ControllerModeIndication(u8HwCtrl, CAN_CS_SLEEP);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief          Service to write data into the Message buffer for transition
* @details        This routine is used in case enabled FD feature.
*
*                 This routine is called by:
*                  - Can_Llce_Write()
*
* @param[in]     TxMbDesc - Tx message buffer descriptor
*                u32MessageId - message id
*                SduDataPtr - Pointer to Sdu data
*                SduLength  - Sdu length
*                u16HohIndex - The index of HOH in the structure array which stores the information of configured HOHs
*                bEnabledFD - Be TRUE if CAN FD is enabled, otherwise it is FALSE
*                u8FdPaddingValue - FD padding value
*
* @return        void
*/
static void Can_Llce_UpdateMB(const Can_43_LLCE_TxFrameInfoType* TxFrameInfo)
{
    /* Variable for byte index of the MB data. */
    uint32 u32MbDataIdx = 0U;
    /* The length of data which will be filled in MB */
    uint8  u8RealDataLength = (uint8)8U;
    /* Index of MB to be filled */
    uint16 u16MbFrameIdx = 0U;
    /* Variable for storing the ConfigReg of the MB. */
    uint32 u32MbConfig = 0U;

    uint32 u32Word0 = 0U;

    uint16 u16TxMbDescIdx = 0U;

    /* Pointer to the frame payload to be sent. */
    volatile uint8 * u8FramePayload = NULL_PTR;

    /* Retrieve Tx Mb Descriptor. TX Mb descriptor index delivered by LLCE in the caller is stored in u16MbFrameIdx inside TxMbDesc.*/
    u16TxMbDescIdx = TxFrameInfo->u16MbFrameIdx;
    
    /* Set-up the MB content for Tx. */
    /* Remember the PduId for reporting back to host core when the frame is really transmitted. */
    Can_SharedMemory.Can_Tx_aMbDesc[u16TxMbDescIdx].u16FrameTag2 = TxFrameInfo->u16FrameTag2;

    /* Remember the index into the configured hardware object configuration array in order to be used later for HTH management. */
    Can_SharedMemory.Can_Tx_aMbDesc[u16TxMbDescIdx].u16FrameTag1 = TxFrameInfo->u16FrameTag1;

    /* The options for ack interface are: 0-15 for interrupt processing, 16-21 for polling classes. */
    Can_SharedMemory.Can_Tx_aMbDesc[u16TxMbDescIdx].u8AckInterface = TxFrameInfo->u8AckInterface;

    Can_SharedMemory.Can_Tx_aMbDesc[u16TxMbDescIdx].u8EnableTxFrameMac = (TxFrameInfo->bEnableTxFrameMac) ? 1U : 0U;
    
    u32Word0 = ((uint32)TxFrameInfo->u32MessageId & CAN_LPDU_ID_MASK_U32);

    if ( CAN_LPDU_IDE_U32 == ((uint32)TxFrameInfo->u32MessageId & CAN_LPDU_IDE_U32))
    {
        /* Set the IDE field in the tx message buffer. */
        u32Word0 |= (LLCE_CAN_MB_IDE_U32);
    }
    else
    {
       /* Standard ID - need to shift left 18 bits. */
       u32Word0 <<= LLCE_CAN_MB_IDSTD_SHIFT_U32;
    }
    
    u16MbFrameIdx = Can_SharedMemory.Can_Tx_aMbDesc[u16TxMbDescIdx].u16MbFrameIdx;
    Can_SharedMemory.Can_aMb[u16MbFrameIdx].u32Word0 = u32Word0;

    u8FramePayload = Can_SharedMemory.Can_aMb[u16MbFrameIdx].u8Payload;
    /* Copy the data into the MB memory. The driver will not read from a null pointer SDU. */
    for ( u32MbDataIdx = 0U; u32MbDataIdx < TxFrameInfo->u32SduLength; u32MbDataIdx++)
    {
       ((volatile uint8*)u8FramePayload)[u32MbDataIdx] = ((const uint8*)TxFrameInfo->u8SduDataPtr)[u32MbDataIdx];
    }

    Can_Llce_ComputeMbConfig(TxFrameInfo->u32SduLength, TxFrameInfo->u32MessageId, TxFrameInfo->bFdEnabled, &u32MbConfig, &u8RealDataLength);

    /* Pad with configured value if applicable */
    if (TRUE == TxFrameInfo->bFdEnabled)
    {
        for ( u32MbDataIdx = (uint8)TxFrameInfo->u32SduLength; u32MbDataIdx < u8RealDataLength ; u32MbDataIdx++)
        {
            u8FramePayload[u32MbDataIdx] = TxFrameInfo->u8FdPaddingValue;
        }
    }
    /* Add BRS feature to the message buffer. */
    Can_SharedMemory.Can_aMb[u16MbFrameIdx].u32Word1 = u32MbConfig;

    /* Timestamp buffer is not used for Tx frames. Storing HSE KeyHandle here. */
    /* KeyHandle shall be stored only if TxFrameMac is active */
    if(TRUE == TxFrameInfo->bEnableTxFrameMac)
    {
        Can_SharedMemory.Can_aMb[u16MbFrameIdx].u32Timestamp = TxFrameInfo->u32TxHseKeyHandle;
    }
}


static void Can_Llce_ComputeMbConfig(uint32 SduLength, uint32 u32MessageId, boolean bEnabledFD, uint32* pu32MbConfig, uint8* pu8RealDataLength)
{
    /*u8DataLengthMax, u8DataLengthMin, u8LengthIndex index counter*/
    uint8  u8DataLengthCount = 0U;
    /*maximum threshold values for DLC*/
    const uint8 u8DataLengthMax[8] = {8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    /*minimum threshold values for DLC*/
    const uint8 u8DataLengthMin[8] = {0U, 9U, 13U, 17U, 21U, 25U, 33U, 49U};

    if (((uint8)SduLength) <= (uint8)u8DataLengthMax[0])
    {
        *pu32MbConfig |= (uint32)SduLength ;
        *pu8RealDataLength = (uint8)SduLength;
    }
    else
    {
        if ((((uint32)u32MessageId) & (uint32)CAN_LPDU_FD_U32) == CAN_LPDU_FD_U32 )
        {
            for (u8DataLengthCount=1U; u8DataLengthCount<8U; u8DataLengthCount++)
            {
                if ((((uint8)SduLength)<=(uint8)u8DataLengthMax[u8DataLengthCount])&&(((uint8)SduLength)>=(uint8)u8DataLengthMin[u8DataLengthCount]))
                {
                    *pu32MbConfig |= ((uint32)((uint32)8U+(uint32)u8DataLengthCount));
                    *pu8RealDataLength = (uint8)u8DataLengthMax[u8DataLengthCount];
                    break;
                }
            }
        }
    }

    /*check to see if CanIf bit send from the user enables FD*/
    if ((TRUE == bEnabledFD) && ((((uint32)u32MessageId) & (uint32)CAN_LPDU_FD_U32) == CAN_LPDU_FD_U32 ))
    {
        /* Configure the tx mb as a CAN FD frame. */
        *pu32MbConfig |= LLCE_CAN_MB_FDF_U32;

        /* Enable BRS feature in order to allow receiving of all CAN Fd frames.*/
        *pu32MbConfig |= LLCE_CAN_MB_BRS_U32;
    }

}

/**
* @brief          Initialization of indicator, statuses, etc.
* @details        Initialization of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
* @implements     Can_Llce_ExecuteIfCommand_Activity
*
*/
static Llce_Fw_ReturnType Can_Llce_ExecuteIfCommand(uint8 u8HwCtrl)
{
    uint32 u32timeStart = 0U;
    /* Timeout counter. */
    uint32          u32timeElapsed = 0U;
    uint32          u32TicksDelayDuration = 0U;
    Std_ReturnType  temp;
    Llce_Fw_ReturnType eReturnValue;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eReturnValue = LLCE_FW_NOTRUN;
    /* Trigger an interrupt to LLCE and wait until LLCE finishes ISR processing by checking non-dynamic flags. */
    Reg_Write32( LLCE_FIFO_PUSH0(LLCE_FIFO_CMD_BASE_ADDRESS(pxConfig->u8ActiveHif)), (uint32)u8HwCtrl);
    
    u32timeStart = OsIf_GetCounter(CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
    u32TicksDelayDuration = OsIf_MicrosToTicks(CAN_43_LLCE_TIMEOUT_DURATION, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);

    do
    {
        u32timeElapsed += OsIf_GetElapsed(&u32timeStart, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
        temp = Can_Llce_CheckCommandAvailable();
    }
    while ((u32timeElapsed < u32TicksDelayDuration) && ( (Std_ReturnType)E_NOT_OK == temp));

    #ifdef MCAL_ENABLE_FAULT_INJECTION
    MCAL_FAULT_INJECTION_POINT(CAN_43_LLCE_FIP_3_EXECUTE_CMD_WHILE_LOOP);
    #endif

    if (u32timeElapsed < u32TicksDelayDuration)
    {
        eReturnValue = Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eReturnValue;
    }
    else
    {
        eReturnValue = LLCE_FW_NOTRUN;
    }

    return eReturnValue;
}

/**
* @brief          Send CREATE_AF_DESTINATION command.
* @details        Create a new destination rule for LLCE Advanced Feature.
*
* @param[in]      destRule - The destination to add to the LLCE destination list
* @param[out]     pu8RuleIdx - The index of the new destination in the LLCE list. Needed for SetAdvancedFilter.
*
* @return        Std_ReturnType. Result of the request.
* @retval        E_OK  Destination created
* @retval        E_NOT_OK  Error
*/
Std_ReturnType Can_Llce_CreateAfDestination(Can_Af_DestRulesType destRule, uint8* pu8RuleIdx)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {      
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_CREATE_AF_DESTINATION;
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.CreateAfDest.rule = destRule;       
        /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( pxConfig->u8DefaultController ))
        {
            *(pu8RuleIdx) = Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.CreateAfDest.u8Idx;
        }
        else
        {
            eReturnValue = E_NOT_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

/**
* @brief          Send REMOVE_AF_DESTINATION command.
* @details        This service removes an existing destination for advanced features
*
* @param[in]     u8RuleIdx - The index of the destination to be removed from the LLCE list.
*
* @return        Std_ReturnType. Result of the request.
* @retval        E_OK  Destination removed
* @retval        E_NOT_OK  Error
*/

Std_ReturnType Can_Llce_RemoveAfDestination(uint8 u8RuleIdx)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {      
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_REMOVE_AF_DESTINATION;
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.RemoveAfDest = u8RuleIdx;
        /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( pxConfig->u8DefaultController ))
        {
            /* Set the return value. */
            eReturnValue = E_OK;
        }
        else
        {
            eReturnValue = E_NOT_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}


#if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0U) && ((LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT > 0U) || (LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0U) || (LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0U))
/**
* @brief          Create AF Destinations from driver configuration
* @details        Initialization of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
static Llce_Fw_ReturnType Can_Llce_CreateConfiguredAfDestinations(void)
{
    /* Variable for indexing all the MBs from hardware unit chain (all controllers). */
    uint16 i = 0U;
    Llce_Fw_ReturnType eReturnValue = LLCE_FW_SUCCESS;
    volatile Can_Af_DestRulesType* pAfRule;

#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
    const uint32 u32CoreId = Can_43_LLCE_GetCoreID();
#endif

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();
    pAfRule = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.CreateAfDest.rule);

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Load the destination rule lists. Use any controller. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_CREATE_AF_DESTINATION;

        for(i=0; i < (LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT); i++)
        {
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            /* Multicore: create only destinations mapped to this core */
            if(u32CoreId == Llce_Can_AfDestOwnerCoreId[i])
            {
#endif
                *pAfRule = Llce_Can_AfRoutingTable[i];
                #if ((LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0U) || (LLCE_CAN_ADVANCED_FEATURE_CAN2PCIE_CNT > 0U))
                    switch (pAfRule->eAfDestId)
                    {
                    case CAN_AF_CAN2ETH:
                        pAfRule->AfDest.Can2Eth.pu8Can2EthBuffAddr = (uint32)pLlce_Can_AfBuffer[i];
                        break;
                    case CAN_AF_CAN2PCIE:
                        pAfRule->AfDest.Can2Pcie.pu8Can2PcieBuffAddr = (uint32)pLlce_Can_AfBuffer[i];
                        break;
                    default:
                        /* Copying the buffer is only required for CAN2ETH and CAN2OTHER */
                        break;
                    }
                #endif
                /* Send the command prepared above to the LLCE in order to be executed */
                eReturnValue = Can_Llce_ExecuteIfCommand( pxConfig->u8DefaultController );
                if(LLCE_FW_SUCCESS == eReturnValue)
                {
                    Can_au8DestinationIdxMap[i] = Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.CreateAfDest.u8Idx;
                }
                else
                {
                    break;
                }
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            }
#endif
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;

}
#endif

/**
* @brief          Send SETADVANCEDFILTER command.
* @details        Initialization of filters which include AF rules.
*                 This routine is called by:
*                 - Can_Llce_AfInit from Can_Llce.c file.
*
* @pre            The AF rules must be set in advance.
* @post           Set the filters and AF rules as generated in configuration.
*
*/
#if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0)
static void Can_Llce_SetConfiguredAfFilters(void)
{
    uint8 u8HwCtrl = 0U;
    uint8 u8CtrlIndex;
    uint16 crtFilter = 0U;
    uint8 filterLoadedCount = 0U;
    Llce_Can_AdvancedFilterType * filterList;
    volatile Llce_Can_SetAdvancedFilterCmdType * pSAFCmd;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    for ( u8CtrlIndex = 0U; u8CtrlIndex < CAN_43_LLCE_MAXCTRL_CONFIGURED; u8CtrlIndex++)
    {
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
        if(Can_43_LLCE_GetCoreID() == pxConfig->aControllerDescriptors[u8CtrlIndex].u32CoreId)
        {
#endif
            u8HwCtrl = pxConfig->aControllerDescriptors[u8CtrlIndex].u8HwCtrl;

            /* Skip disabled controllers */
            if(LLCE_NULL_OFFSET_U8 != u8HwCtrl)
            {
                /*Configure the command id for all controllers which are used. */
                Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETADVANCEDFILTER;
                
                pSAFCmd = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter);

                filterList = pxConfig->paAdvancedFilters[u8HwCtrl];
                filterLoadedCount = 0U;

                for(crtFilter = 0U; crtFilter < pxConfig->pPlatfInitConfig->au16MaxAdvancedFilterCount[u8HwCtrl]; crtFilter++)
                {
                    /* Copy the AF filter to the shared memory */
                    pSAFCmd->aAdvancedFilters[filterLoadedCount] = filterList[crtFilter];

                  #if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0) && ((LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0))
                    /* Update the destination index to the actual value in FW */
                    if(LLCE_CAN_ADVANCED_FILTER_NOT_USED != filterList[crtFilter].Llce_Can_AdvancedFeature.u8Can2CanRoutingTableIdx)
                    {
                        pSAFCmd->aAdvancedFilters[filterLoadedCount].Llce_Can_AdvancedFeature.u8Can2CanRoutingTableIdx = Can_au8DestinationIdxMap[filterList[crtFilter].Llce_Can_AdvancedFeature.u8Can2CanRoutingTableIdx];
                    }
                    if(LLCE_CAN_ADVANCED_FILTER_NOT_USED != filterList[crtFilter].Llce_Can_AdvancedFeature.u8Can2EthRoutingTableIdx)
                    {
                        pSAFCmd->aAdvancedFilters[filterLoadedCount].Llce_Can_AdvancedFeature.u8Can2EthRoutingTableIdx = Can_au8DestinationIdxMap[filterList[crtFilter].Llce_Can_AdvancedFeature.u8Can2EthRoutingTableIdx];
                    }
                  #endif

                    /* Increase the count of the filters.*/
                    filterLoadedCount++;

                    /* Check if the command buffer for filters is full. */
                    if (LLCE_CAN_CONFIG_ADVANCED_FILTERS_COUNT == filterLoadedCount)
                    {
                        pSAFCmd->u16RxFiltersCount = filterLoadedCount;

                        (void)Can_Llce_SendSetAfFilterCommand(pSAFCmd->aAdvancedFilters, filterLoadedCount, u8HwCtrl);

                        /* Reset the number of filters. */
                        filterLoadedCount = 0;
                    }

                    #if (CAN_43_LLCE_CUSTOM_RX_CALLBACK_USED == STD_ON)
                      /* Save reference to filter config for later usage. */
                      Can_Llce_apRxHrh2AfFilterCfg[filterList[crtFilter].Llce_Can_RxFilter.u16FilterId] = &(filterList[crtFilter]);
                    #endif
                }

                /* Load remaining filters if any*/
                if (filterLoadedCount > 0U)
                {
                    pSAFCmd->u16RxFiltersCount = filterLoadedCount;

                    (void)Can_Llce_SendSetAfFilterCommand(pSAFCmd->aAdvancedFilters, filterLoadedCount, u8HwCtrl);

                    /* Reset the number of filters. */
                    filterLoadedCount = 0;
                }
            }
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
        }
#endif
    }
}
#endif /* LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0 */

static Std_ReturnType Can_Llce_SendSetAfFilterCommand(const volatile Llce_Can_AdvancedFilterType *pAfFilters, uint8 filterLoadedCount, uint8 u8HwCtrl)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue = LLCE_FW_NOTRUN;

    #if (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U)
    uint8 i = 0U;
    #endif

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {             
        /* Send the command prepared above to the LLCE in order to be executed */
        eCommandReturnValue =  Can_Llce_ExecuteIfCommand(u8HwCtrl);
    }

    if (LLCE_FW_SUCCESS == eCommandReturnValue)
    {
        #if (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U)
        /* Copy the hw filter addr for later usage. */
        for(i = 0; i < filterLoadedCount; i++)
        {  
            Can_Llce_au16RxHrh2FilterAddr[pAfFilters[i].Llce_Can_RxFilter.u16FilterId] = pAfFilters[i].Llce_Can_RxFilter.u16FilterAddr;                                
        }
        #else
        (void)pAfFilters;
        (void)filterLoadedCount;
        #endif
        eReturnValue = E_OK;
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}





/**
* @brief          Check user callback
* @details        Check if the RX filter is configured with custom user callback, and execute it if so
*
* @return         TRUE if frame should be delivered (no custom processing or custom callback returned TRUE), FALSE otherwise
*/
#if (CAN_43_LLCE_CUSTOM_RX_CALLBACK_USED == STD_ON)
static boolean Can_Llce_CheckCustomCallback(uint16 u16HrhId, uint32 u32MbMessageId, uint8 u8MbDataLength, uint8* u8FramePayload, uint16 u16RxMbDescIdx)
{
    boolean returnValue = TRUE;
    const Llce_Can_AdvancedFilterType * pAfFilter;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Custom processing can only apply to Advanced Filters */
    if(CAN_43_LLCE_RECEIVE_AF == pxConfig->aHohList[u16HrhId].eMBType)
    {
        pAfFilter = Can_Llce_apRxHrh2AfFilterCfg[u16HrhId];

        /* Check if custom processing is enabled */
        if(LLCE_AF_CUSTOMPROCESSING_ENABLED == pAfFilter->Llce_Can_AdvancedFeature.eCanCustomProcessing)
        {
            returnValue = Can_43_LLCE_CustomRxCallback((uint8)u16HrhId, u32MbMessageId, u8MbDataLength, u8FramePayload, u16RxMbDescIdx);
        }
    }

    return returnValue;
}
#endif
/*=================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          Removes receive filter.
* @details        Removes a single filter and make it unavailable for filtering..
*                 This routine is called by:
*
* @param[in]     Hrh - Hardware receive handler configured by user.
* @param[in]     u16FilterAddr - address of the removed filter, to be later used by Can_Llce_SetFilterAtAddress.
*
* @pre            Platform shall be insialized and the related controller initialized.
* @post           The related controller acept frames received by the filter if is started.
*
*/
Std_ReturnType Can_Llce_RemoveFilter(Can_HwHandleType Hrh, uint16* u16FilterAddr)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;

#if (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U)
    uint8 u8HwCtrl;
    uint8 u8LogicCtrl;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

  if((CAN_43_LLCE_FIRST_HTH_CONFIGURED > Hrh) && (NULL_PTR != u16FilterAddr))
  {
      /* Get the logical controller id corresponding to the above hrh */
      u8LogicCtrl = pxConfig->aHohList[Hrh].u8ControllerId;

      /* Get the hardware controller corresponding to above logical controller */
      u8HwCtrl = pxConfig->aControllerDescriptors[u8LogicCtrl].u8HwCtrl;

      if(Can_Llce_au16RxHrh2FilterAddr[Hrh] != CAN_LLCE_FILTER_DEFAULT_EMPTY_ADDRESS_U16)
      {
          SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
          if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
          {                
              /*Configure the command id for all controllers which are used. */
              Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_REMOVE_FILTER;

              /*Initialize the number of filters for all controllers which are used. */
               Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.ChangeFilter.u16FilterAddr = Can_Llce_au16RxHrh2FilterAddr[Hrh]; 
               /* Return the filter address from LLCE RxLut so that the SetFilterAtAddress function can use it */
               *u16FilterAddr = Can_Llce_au16RxHrh2FilterAddr[Hrh]; 
       
              /* Send the command prepared above to the LLCE in order to be executed */
              if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( u8HwCtrl ))
              {                      
                  Can_Llce_au16RxHrh2FilterAddr[Hrh] = CAN_LLCE_FILTER_DEFAULT_EMPTY_ADDRESS_U16;
                  /* Set the return value. */
                  eReturnValue = E_OK;
              }
          }
          
          SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
      }
  }

#else /* (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U) */
        (void)Hrh;
        (void)eReturnValue;
        (void)u16FilterAddr;
#endif /* (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U) */

    return eReturnValue;
}

/**
* @brief          Set receive filter.
* @details        Set a single filter inside hw module.
*                 This routine is called by:
*                 - Can_43_LLCE_SetFilter() from Can_43_LLCE.c file.
*
* @pre            Platform shall be initialized and the related controller initialized.
* @post           The related controller accepts frames received by the filter if is started.
*
*
*/
Std_ReturnType Can_Llce_SetFilter(const Can_SetFilterType * pCanFilter)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    uint8 u8HwCtrl;
    uint8 u8LogicCtrl;
    volatile Llce_Can_ReceiveFilterType * pRxFilter = NULL_PTR;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Get the logical controller id corresponding to the current HRH */
    u8LogicCtrl = pxConfig->aHohList[pCanFilter->Hrh].u8ControllerId;

    /* Get the hardware controller corresponding to above logical controller */
    u8HwCtrl = pxConfig->aControllerDescriptors[u8LogicCtrl].u8HwCtrl;
   
    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    /* Check if the command buffer is not already used by other command request. */
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /*Configure the command id for all controllers which are used. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETFILTER;

        pRxFilter = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetFilter.aRxFilters[0U]);
        /*Set a single receive filter inside LLCE for timing reasons. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetFilter.u16RxFiltersCount = 1U; 

        pRxFilter->eEntryType = pCanFilter->eFilterType;

        pRxFilter->u16FilterId = pCanFilter->Hrh;

        pRxFilter->uIdMask = pCanFilter->uIdMask;

        /* Set Rx interface for current filter. First 16 interfaces (0-15) are reserved for interrupt processing, next 6 interfaces (16-21) are for polling classes. */
        pRxFilter->u8RxDestInterface = pCanFilter->u8RWInterface;

        pRxFilter->uMessageId = pCanFilter->uMessageId;
        
        pRxFilter->u16MbCount = pCanFilter->u16MbCount;

        pRxFilter->eFilterMbLength = pCanFilter->eFilterMbLength;

        Can_Llce_ProcessFilterIdMaskType(pCanFilter->eIdType, pRxFilter);

        eReturnValue = Can_Llce_SendSetFilterCommand(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetFilter.aRxFilters, 1U /* filterLoadedCount */, u8HwCtrl);
    }
   
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

/**
* @brief          Set receive filter.
* @details        Set a single filter inside hw module.
*                 This routine is called by:
*                 - Can_43_LLCE_SetFilter() from Can_43_LLCE.c file.
*
* @pre            Platform shall be initialized and the related controller initialized.
* @post           The related controller accepts frames received by the filter if is started.
*
*
*/
Std_ReturnType Can_Llce_SetFilterAtAddress(const Can_SetFilterType * pCanFilter, const uint16 u16FilterAddr)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    uint8 u8HwCtrl;
    uint8 u8LogicCtrl;
    volatile Llce_Can_ReceiveFilterType * pRxFilter = NULL_PTR;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Get the logical controller id corresponding to the current HRH */
    u8LogicCtrl = pxConfig->aHohList[pCanFilter->Hrh].u8ControllerId;

    /* Get the hardware controller corresponding to above logical controller */
    u8HwCtrl = pxConfig->aControllerDescriptors[u8LogicCtrl].u8HwCtrl;
   
    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    /* Check if the command buffer is not already used by other command request. */
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /*Configure the command id for all controllers which are used. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETFILTER_AT_ADDRESS;
        /*TDO : memorise the filter id*/

        pRxFilter = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetFilter.aRxFilters[0U]);
        /*Set a single receive filter inside LLCE for timing reasons. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetFilter.u16RxFiltersCount = 1U; 

        pRxFilter->u16FilterAddr = u16FilterAddr;

        pRxFilter->eEntryType = pCanFilter->eFilterType;

        pRxFilter->u16FilterId = pCanFilter->Hrh;

        pRxFilter->uIdMask = pCanFilter->uIdMask;

        /* Set Rx interface for current filter. First 16 interfaces (0-15) are reserved for interrupt processing, next 6 interfaces (16-21) are for polling classes. */
        pRxFilter->u8RxDestInterface = pCanFilter->u8RWInterface;

        pRxFilter->uMessageId = pCanFilter->uMessageId;
        
        pRxFilter->u16MbCount = pCanFilter->u16MbCount;

        pRxFilter->eFilterMbLength = pCanFilter->eFilterMbLength;

        Can_Llce_ProcessFilterIdMaskType(pCanFilter->eIdType, pRxFilter);

        eReturnValue = Can_Llce_SendSetFilterCommand(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetFilter.aRxFilters, 1U /* filterLoadedCount */, u8HwCtrl);
    }
   
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

/**
* @brief          Set advanced receive filter.
* @details        Set a single advanced filter inside hw module.
*                 This routine is called by:
*                 - Can_43_LLCE_SetAfFilter() from Can_43_LLCE.c file.
*
* @pre            Platform shall be initialized and the related controller initialized.
* @post           The related controller accepts frames received by the filter if is started.
*
*
*/
Std_ReturnType Can_Llce_SetAfFilter(const Can_SetAfFilterType * pAfFilter)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue;
    uint8 u8HwCtrl;
    uint8 u8LogicCtrl;
    volatile Llce_Can_ReceiveFilterType * pRxFilter = NULL_PTR;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Get the logical controller id corresponding to the current HRH */
    u8LogicCtrl = pxConfig->aHohList[pAfFilter->Filter.Hrh].u8ControllerId;

    /* Get the hardware controller corresponding to above logical controller */
    u8HwCtrl = pxConfig->aControllerDescriptors[u8LogicCtrl].u8HwCtrl;
   
    /*Configure the command id for all controllers which are used. */
    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETADVANCEDFILTER;

    /*Set a single receive filter inside LLCE for timing reasons. */
    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter.u16RxFiltersCount = 1U; 

    pRxFilter = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter.aAdvancedFilters[0U].Llce_Can_RxFilter);

    pRxFilter->eEntryType = pAfFilter->Filter.eFilterType;

    pRxFilter->u16FilterId = pAfFilter->Filter.Hrh;        

    pRxFilter->uIdMask = pAfFilter->Filter.uIdMask;

    /* Set Rx interface for current filter. First 16 interfaces (0-15) are reserved for interrupt processing, next 6 interfaces (16-21) are for polling classes. */
    pRxFilter->u8RxDestInterface = pAfFilter->Filter.u8RWInterface;

    pRxFilter->uMessageId = pAfFilter->Filter.uMessageId;
    
    pRxFilter->u16MbCount = pAfFilter->Filter.u16MbCount;

    Can_Llce_ProcessFilterIdMaskType(pAfFilter->Filter.eIdType, pRxFilter);
    
    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter.aAdvancedFilters[0U].Llce_Can_AdvancedFeature = pAfFilter->AdvancedFeature;

    eReturnValue = Can_Llce_SendSetAfFilterCommand(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter.aAdvancedFilters, 1U /* filterLoadedCount */, u8HwCtrl);

    return eReturnValue;
}

/**
* @brief          Set advanced receive filter at given address.
* @details        Set a single advanced filter inside hw module.
*                 This routine is called by:
*                 - Can_43_LLCE_SetAfFilterAtAddress from Can_43_LLCE.c file.
*
* @pre            Platform shall be initialized and the related controller initialized.
* @post           The related controller accepts frames received by the filter if it is started.
*
*
*/
Std_ReturnType Can_Llce_SetAfFilterAtAddress(const Can_SetAfFilterType * pAfFilter, const uint16 u16FilterAddr)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue;
    uint8 u8HwCtrl;
    uint8 u8LogicCtrl;
    volatile Llce_Can_ReceiveFilterType * pRxFilter = NULL_PTR;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Get the logical controller id corresponding to the current HRH */
    u8LogicCtrl = pxConfig->aHohList[pAfFilter->Filter.Hrh].u8ControllerId;

    /* Get the hardware controller corresponding to above logical controller */
    u8HwCtrl = pxConfig->aControllerDescriptors[u8LogicCtrl].u8HwCtrl;
   
    /*Configure the command id for all controllers which are used. */
    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETADVANCEDFILTER_AT_ADDRESS;
    
    /*Set a single receive filter inside LLCE for timing reasons. */
    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter.u16RxFiltersCount = 1U; 

    pRxFilter = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter.aAdvancedFilters[0U].Llce_Can_RxFilter);

    pRxFilter->u16FilterAddr = u16FilterAddr;

    pRxFilter->eEntryType = pAfFilter->Filter.eFilterType;

    pRxFilter->u16FilterId = pAfFilter->Filter.Hrh;        

    pRxFilter->uIdMask = pAfFilter->Filter.uIdMask;

    /* Set Rx interface for current filter. First 16 interfaces (0-15) are reserved for interrupt processing, next 6 interfaces (16-21) are for polling classes. */
    pRxFilter->u8RxDestInterface = pAfFilter->Filter.u8RWInterface;

    pRxFilter->uMessageId = pAfFilter->Filter.uMessageId;
    
    pRxFilter->u16MbCount = pAfFilter->Filter.u16MbCount;

    Can_Llce_ProcessFilterIdMaskType(pAfFilter->Filter.eIdType, pRxFilter);
    
    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter.aAdvancedFilters[0U].Llce_Can_AdvancedFeature = pAfFilter->AdvancedFeature;

    eReturnValue = Can_Llce_SendSetAfFilterCommand(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAdvancedFilter.aAdvancedFilters, 1U /* filterLoadedCount */, u8HwCtrl);

    return eReturnValue;
}

/**
* @brief          Enable/disable receive filter.
* @details        Set enabled state for a single filter. Its configuration is still in LLCE and my be 
*                 reactivated later.
*/
Std_ReturnType Can_Llce_SetFilterState(Can_HwHandleType Hrh, Can_43_LLCE_FilterStateType eState)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U)
    uint8 u8HwCtrl;
    uint8 u8LogicCtrl;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

  if(CAN_43_LLCE_FIRST_HTH_CONFIGURED > Hrh )
  {
      /* Get the logical controller id corresponding to the above hrh */
      u8LogicCtrl = pxConfig->aHohList[Hrh].u8ControllerId;

      /* Get the hardware controller corresponding to above logical controller */
      u8HwCtrl = pxConfig->aControllerDescriptors[u8LogicCtrl].u8HwCtrl;

      if(Can_Llce_au16RxHrh2FilterAddr[Hrh] != CAN_LLCE_FILTER_DEFAULT_EMPTY_ADDRESS_U16)
      {
          SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
          if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
          { 
              /*Configure the command id for all controllers which are used. */
              Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETFILTERENABLESTATUS;

              /*Initialize the number of filters for all controllers which are used. */
              Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.ChangeFilter.u16FilterAddr = Can_Llce_au16RxHrh2FilterAddr[Hrh]; 
              Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.ChangeFilter.u8FilterEnabled = (uint8)eState;
          
              /* Send the command prepared above to the LLCE in order to be executed */
              if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( u8HwCtrl ))
              {                      
                  /* Set the return value. */
                  eReturnValue = E_OK;
              }
          }
          SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
      }
  }

#else /* (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U) */
        (void)Hrh;
        (void)eReturnValue;
        (void)eState;
#endif /* (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U) */

    return eReturnValue;
}

/**
* @brief          Enable/disable channel.
* @details        Set state of controller in a multicast routing configuration. 
* 
*/
Std_ReturnType Can_Llce_SetChannelRoutingOutputState(uint8 u8HwCtrl, Can_43_LLCE_ChannelStateType eChannelStatus)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /*Configure the command id. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETCHANNELROUTINGOUTPUTSTATE;

        if(CAN_43_LLCE_CHANNELSTATE_ENABLED == eChannelStatus)
        {
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.eBinaryValue = LLCE_TRUE;
        }
        else
        {
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.eBinaryValue = LLCE_FALSE;
        }

        /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( u8HwCtrl ))
        {                      
            /* Set the return value. */
            eReturnValue = E_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}
/**
* @brief          Initialization of indicator, statuses, etc.
* @details        Initialization of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
static void Can_Llce_InitVariables(const Can_43_LLCE_ConfigType * pxCurrentConfig, uint8 u8ControllersCount)
{
    /* Index CAN controllers from configuration. */
    uint8 u8CtrlIndex = 0U;
    /* Set local pointer to configuration structure */
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();
    Can_Llce_pxGlobalConfigs[u32CoreId] = pxCurrentConfig;
#else
    Can_Llce_pxGlobalConfigs[0] = pxCurrentConfig;
#endif

    uint8 u8HwCtrl = 0U;

    /* Init all global varibales/statuses for all controllers. */
    for ( u8CtrlIndex = 0U; u8CtrlIndex < u8ControllersCount; u8CtrlIndex++)
    {
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
        if(pxCurrentConfig->aControllerDescriptors[u8CtrlIndex].u32CoreId == u32CoreId )
        {    
#endif
            u8HwCtrl = pxCurrentConfig->aControllerDescriptors[u8CtrlIndex].u8HwCtrl;
            /* check for enabled controller */
            if(CAN_43_LLCE_NULL_OFFSET != u8HwCtrl)
            {
                /* Init INT Disable nesting indicator. It is incremented after every call of Can_43_LLCE_DisableControllerInterrupts().
                The function Can_43_LLCE_EnableControllerInterrupts() shall perform no action when Can_43_LLCE_DisableControllerInterrupts() has not been called before. */
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].u8IntDisableLevel = (uint8)0;

                /* Set  interrupt mode status to interrupt enabled mode.
                This is needed in order to support the implementation of requirements CAN425 and CAN426 into Can_43_LLCE_SetControllerMode API. */
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].eInterruptMode= CAN_INTERRUPT_ENABLED;

                Can_43_LLCE_ControllerStatuses[u8HwCtrl].eSetIntEnRequest= CAN_INTERRUPT_DISABLED;

                Can_Llce_au8FifoSetIntEnCnt[u8HwCtrl] = 0U;
            }
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
        }
#endif
    }

#if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
    /* Init sw fifo used for errors buffering */
    (void)Llce_SwFifo_Init(Can_Llce_aNotif1_Table, (uint8)(sizeof(Llce_Can_NotificationType)), (uint16)(LLCE_CAN_CONFIG_NOTIF_TABLE_SIZE), &Can_Llce_xNotifSwFifo);
#endif

}


static void Can_Llce_ProcessFilterIdMaskType(Llce_Can_IdLengthType eIdType, volatile Llce_Can_ReceiveFilterType * pxFilter)
{
    /* Range filters must not have values changed */
    if(pxFilter->eEntryType != LLCE_CAN_ENTRY_CFG_RANGED)
    {
        /* Mask the ID and Mask in order to not allow the user to configure more than 29 bits. */
        pxFilter->uIdMask &= LLCE_CAN_MB_29BIT_MASK_U32;
        pxFilter->uMessageId &= LLCE_CAN_MB_29BIT_MASK_U32;

        switch(eIdType)
        {
        case LLCE_CAN_STANDARD:
            /* Add IDE to Mask.*/
            pxFilter->uIdMask |= LLCE_CAN_MB_IDE_U32;
            break;

        case LLCE_CAN_EXTENDED:
            /* Add IDE to Mask.*/
            pxFilter->uIdMask |= LLCE_CAN_MB_IDE_U32;
            /* Add IDE bit to ID. Only Extended ID. */
            pxFilter->uMessageId |= LLCE_CAN_MB_IDE_U32;
            break;

        case LLCE_CAN_MIXED:
            /* Remove IDE from Mask.*/
            pxFilter->uIdMask &= ~(LLCE_CAN_MB_IDE_U32);
            break;

        default:
            /* Bad identifier type  */
            break; 
        }
    }
}
/**
* @brief          Perform INIT_HSE command.
* @details        Enable HSE support in the firmware if hardware support it for MAC generation and verification.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
* @pre            
* @post           
*/
#if (CAN_43_LLCE_HSE_SUPPORT_ENABLE == STD_ON)
static Llce_Fw_ReturnType Can_Llce_InitHse( void )
{
    Llce_Fw_ReturnType eReturnValue = LLCE_FW_ERROR;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Prepare command.*/
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId  = LLCE_CAN_CMD_INIT_HSE;

        /* Execute command.*/
        eReturnValue = Can_Llce_ExecuteIfCommand( pxConfig->u8DefaultController );
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}
#endif

/**
* @brief          Perform standard Autosar initialization flow.
* @details        Service which initializes LLCE using multiple commands, as expected by LLCE firmware:
*                 LLCE_CAN_CMD_INIT_PLATFORM - initialization of common LLCE services and buffer reservation 
*                 LLCE_CAN_CMD_INIT_HSE - initialization of HSE advanced service. Enabled only with FDK LLCE sw package.
*                 LLCE_CAN_CMD_INIT - initialization of each controller in configuration with default baudrate as per configuration
*                 LLCE_CAN_CMD_SETFILTER - configuration of filters for each channel, as per configuration
*                 LLCE_CAN_CMD_CREATE_AF_DESTINATION - creation of destinations for the messages to be forwarded to
*                 LLCE_CAN_CMD_SETADVANCEDFILTER - configuration of advanced filters, mapped to the AF destinations created previously
*                 This routine is called by:
*                 - Can_43_LLCE_IPW_Init from Can_43_LLCE_IPW.c file.
*
* @pre            LLCE is not initialized
* @post           LLCE is initialized using the Autosar configuration. The controllers are in STOP state
*/
Llce_Fw_ReturnType Can_Llce_Init(const Can_43_LLCE_ConfigType * pxCurrentConfig)
{
    Llce_Fw_ReturnType eReturnValue;
#if (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON)
    uint8 i;
#endif

    eReturnValue = Can_Llce_InitPlatform(pxCurrentConfig, CAN_43_LLCE_MAXCTRL_CONFIGURED);

    if(LLCE_FW_SUCCESS == eReturnValue)
    {

        #if (CAN_43_LLCE_HSE_SUPPORT_ENABLE == STD_ON)
        eReturnValue = Can_Llce_InitHse();

        if(LLCE_FW_SUCCESS == eReturnValue)
        {
        #endif
            eReturnValue = Can_Llce_InitController();
            if(LLCE_FW_SUCCESS == eReturnValue)
            {
                Can_Llce_SetConfiguredReceiveFilters();
                #if (RXLUT2_ENABLE == STD_ON)
                Can_Llce_SetConfiguredAuxReceiveFilters();
                #endif
                #if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0)
                Can_Llce_AfInit();
                #endif
                #if (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON)
                for(i = 0U; i < LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_FORMAT_CNT; i++)
                {
                    eReturnValue = Can_Llce_SetEth2CanFormatState(Llce_Eth2Can_EnabledFormats[i], CAN_LLCE_ETH2CAN_ENABLED);
                }
                #endif
            }
        #if (CAN_43_LLCE_HSE_SUPPORT_ENABLE == STD_ON)
        }
        #endif
    }

    return eReturnValue;
}
/**
* @brief          Perform INIT_PLATFORM command.
* @details        Write variables from interface into shared memory.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
static Llce_Fw_ReturnType Can_Llce_InitPlatform(const Can_43_LLCE_ConfigType * pxCurrentConfig, uint8 u8ControllersCount)
{
    Llce_Fw_ReturnType eReturnValue = LLCE_FW_ERROR;
#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
  #if defined(S32G3XX)
    uint8 u8HwCtrl;
  #endif
#endif

    /* Initialize local variable used by the driver. */
    Can_Llce_InitVariables(pxCurrentConfig, u8ControllersCount);

    /* Reset the notification interrupt enable. */
    Can_u16NotifIntrEnable[pxCurrentConfig->u8ActiveHif] = 0;

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
    if((FALSE == pxCurrentConfig->bHeadlessModeEnabled) || (TRUE == Can_Llce_bHeadlessInitDone_InitPlatform) )
    {
#endif
    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Prepare command for initialization of common elements of the platform.*/
        Can_SharedMemory.aCanCmd[pxCurrentConfig->u8ActiveHif].eCmdId  = LLCE_CAN_CMD_INIT_PLATFORM;

        Can_SharedMemory.aCanCmd[pxCurrentConfig->u8ActiveHif].CmdList.InitPlatform =  *(pxCurrentConfig->pPlatfInitConfig);

        eReturnValue = Can_Llce_ExecuteIfCommand( pxCurrentConfig->u8DefaultController );
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
    } else {
    #if defined(S32G3XX)
        /* Calculate filter intervals in RXLUT */
        Can_Llce_au16RxLutCounter[0] = 0U;
        for(u8HwCtrl = 0U; u8HwCtrl < LLCE_CAN_CONFIG_MAXCTRL_COUNT - 1U; u8HwCtrl++)
        {
            Can_Llce_au16RxLutCounter[u8HwCtrl + 1U] = Can_Llce_au16RxLutCounter[u8HwCtrl] + 
                                                      pxCurrentConfig->pPlatfInitConfig->au16MaxRegularFilterCount[u8HwCtrl] +
                                                      pxCurrentConfig->pPlatfInitConfig->au16MaxAdvancedFilterCount[u8HwCtrl]; 
        }
    #endif /* defined(S32G3XX) */
    eReturnValue = LLCE_FW_SUCCESS;    
    Can_Llce_bHeadlessInitDone_InitPlatform = TRUE;
    }
#endif

    return eReturnValue;
}

/**
* @brief          Perform INIT command.
* @details        Initialization of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
static Llce_Fw_ReturnType Can_Llce_InitController(void)
{
    uint8 u8HwCtrl = 0U;
    uint8 u8CtrlIndex = 0u;
    /* Variable for return status. */
    Llce_Fw_ReturnType eReturnValue = LLCE_FW_SUCCESS;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    while((u8CtrlIndex < (uint8)CAN_43_LLCE_MAXCTRL_CONFIGURED) && (LLCE_FW_SUCCESS == eReturnValue))
    {
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
        if(Can_43_LLCE_GetCoreID() == pxConfig->aControllerDescriptors[u8CtrlIndex].u32CoreId)
        {
#endif
            /* Skip the initialization for the controllers that are not enabled. */
            if ( pxConfig->aControllerDescriptors[u8CtrlIndex].u8HwCtrl != (uint8)LLCE_NULL_OFFSET_U8 )
            {
                u8HwCtrl = pxConfig->aControllerDescriptors[u8CtrlIndex].u8HwCtrl;
                /* Init INT Disable nesting indicator. It is incremented after every call of Can_43_LLCE_DisableControllerInterrupts().
                The function Can_43_LLCE_EnableControllerInterrupts() shall perform no action when Can_43_LLCE_DisableControllerInterrupts() has not been called before. */
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].u8IntDisableLevel = (uint8)0U;

                /* Set  interrupt mode status to interrupt enabled mode.
                This is needed in order to support the implementation of requirements CAN425 and CAN426 into Can_43_LLCE_SetControllerMode API. */
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].eInterruptMode= CAN_INTERRUPT_ENABLED;

              #if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
              if((FALSE == pxConfig->bHeadlessModeEnabled) || (TRUE == Can_Llce_bHeadlessInitDone_InitController) )
              {
              #endif
                /*Reset Interrupt Status Flags*/
                Can_Llce_ResetIntFlags(u8HwCtrl);

                SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
                /* Check if a previous command is ongoing. */
                if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
                {                     
                    /* Configure the command id */
                    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId  = LLCE_CAN_CMD_INIT;
                    
                    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.Init = pxConfig->pChannelInitConfig[u8HwCtrl];

                    eReturnValue = Can_Llce_ExecuteIfCommand(u8HwCtrl);

                    if (LLCE_FW_SUCCESS == eReturnValue)
                    {
                        Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState = CAN_CS_STOPPED;
                    }
                }

                SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

              #if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
              }
              #endif
            }
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
        }
#endif
        u8CtrlIndex++;
    }

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
    Can_Llce_bHeadlessInitDone_InitController = TRUE;
#endif

    return eReturnValue;
}

/**
* @brief          Writes configuration to memory and sends SETFILTER for all enabled controllers.
* @details        Initialization of indicator, statuses, etc.
*                 This function is non-reentrant and does not provide thread safety
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
static void Can_Llce_SetConfiguredReceiveFilters(void)
{
    uint8 u8HwCtrl = 0U;
    uint8 u8CtrlIndex;
    uint16 crtFilter;
    uint8 filterLoadedCount = 0U;
    const Llce_Can_ReceiveFilterType * filterList;
    volatile Llce_Can_SetFilterCmdType * pSFCmd;
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
    uint32 u32CoreId;
#endif

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
  /* Skip first entry for headless mode */
  if((FALSE == pxConfig->bHeadlessModeEnabled) || (TRUE == Can_Llce_bHeadlessInitDone_SetConfiguredReceiveFilters) )
  {
#endif
    /* Check if the command buffer is not already used by other command request. */
    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        for (u8CtrlIndex = 0U; (u8CtrlIndex < CAN_43_LLCE_MAXCTRL_CONFIGURED); u8CtrlIndex++)
        {
            u8HwCtrl = pxConfig->aControllerDescriptors[u8CtrlIndex].u8HwCtrl;

            /* Skip disabled controllers */
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            u32CoreId = Can_43_LLCE_GetCoreID();
            if((u32CoreId == pxConfig->aControllerDescriptors[u8CtrlIndex].u32CoreId) && (LLCE_NULL_OFFSET_U8 != u8HwCtrl))
#else
            if(LLCE_NULL_OFFSET_U8 != u8HwCtrl)
#endif
            {
                /*Configure the command id for all controllers which are used. */
                Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETFILTER;
                pSFCmd = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetFilter);
                
                filterList = pxConfig->paReceiveFilters[u8HwCtrl];
                filterLoadedCount = 0U;
                crtFilter = 0u;
                while((crtFilter < pxConfig->pPlatfInitConfig->au16MaxRegularFilterCount[u8HwCtrl]) && ((Std_ReturnType)E_OK == eReturnValue))
                {
                    pSFCmd->aRxFilters[filterLoadedCount] = filterList[crtFilter];
                    #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
                        if(FALSE == pxConfig->aHohList[filterList[crtFilter].u16FilterId].bDummyHRH)
                        {
                    #endif
                            filterLoadedCount++;
                            /* Check if the command buffer for filters is full. */
                            if (LLCE_CAN_CONFIG_MAX_FILTERS_COUNT == filterLoadedCount)
                            {
                                pSFCmd->u16RxFiltersCount = filterLoadedCount;
                                eReturnValue = Can_Llce_SendSetFilterCommand(pSFCmd->aRxFilters, filterLoadedCount, u8HwCtrl);
                                /* Reset the number of filters. */
                                filterLoadedCount = 0;
                            }
                    #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
                        }
                    #endif
                    crtFilter++;
                }

                /* Load remaining filters if any*/            
                if (filterLoadedCount > 0U)
                {
                    pSFCmd->u16RxFiltersCount = filterLoadedCount;
                    eReturnValue = Can_Llce_SendSetFilterCommand(pSFCmd->aRxFilters, filterLoadedCount, u8HwCtrl);
                    /* Reset the number of filters. */
                    filterLoadedCount = 0;
                }
            }
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
  }
  else 
  {
    Can_Llce_EmulateSetConfiguredReceiveFilters();
    Can_Llce_bHeadlessInitDone_SetConfiguredReceiveFilters = TRUE;
  }
#endif
}

static Std_ReturnType Can_Llce_SendSetFilterCommand(const volatile Llce_Can_ReceiveFilterType *pRxFilters, uint8 filterLoadedCount, uint8 u8HwCtrl)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    uint8 i = 0U;
             
    /* Send the command prepared above to the LLCE in order to be executed */
    if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( u8HwCtrl ))
    {
        /* Copy the hw filter addr for later usage. */
        for(i = 0; i < filterLoadedCount; i++)
        {  
            #if (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0U) || (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0)
                Can_Llce_au16RxHrh2FilterAddr[pRxFilters[i].u16FilterId] = pRxFilters[i].u16FilterAddr;
            #else
            (void)pRxFilters;
            #endif
        }

        eReturnValue = E_OK;
    }

    return eReturnValue;

}

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
/**
* @brief          Calculates where filters would be loaded inside LLCE
* @details        When LLCE is started in headless mode, calculate HRH-filter mapping, to allow
*                 removal or disabling.
*/
static void Can_Llce_EmulateSetConfiguredReceiveFilters(void)
{
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();
    const Llce_Can_ReceiveFilterType * filterList;
    uint8 u8HwCtrl;
    uint16 u16CrtFilter, u16HrhId;

    /* FW loads filters based on physical controller */
    for(u8HwCtrl = 0U; u8HwCtrl < LLCE_CAN_CONFIG_MAXCTRL_COUNT; u8HwCtrl++)
    {
        filterList = pxConfig->paReceiveFilters[u8HwCtrl];

        for(u16CrtFilter = 0U; u16CrtFilter < pxConfig->pPlatfInitConfig->au16MaxRegularFilterCount[u8HwCtrl]; u16CrtFilter++)
        {
            u16HrhId = filterList[u16CrtFilter].u16FilterId;

           #if defined(S32G2XX)
            /* On G2 filters are assigned based on type */
            if(LLCE_CAN_ENTRY_EXACT_MATCH == filterList[u16CrtFilter].eEntryType)
            {
                Can_Llce_au16RxHrh2FilterAddr[u16HrhId] = Can_Llce_u16RxLutExactMatchCounter;
                Can_Llce_u16RxLutExactMatchCounter++;
            }
            else
            {
                Can_Llce_au16RxHrh2FilterAddr[u16HrhId] = Can_Llce_u16RxLutConfigurableCounter;
                Can_Llce_u16RxLutConfigurableCounter++;
            }
           #elif defined(S32G3XX)
            /* On G3 filters are simply loaded sequentially */
            Can_Llce_au16RxHrh2FilterAddr[u16HrhId] = Can_Llce_au16RxLutCounter[u8HwCtrl];
            Can_Llce_au16RxLutCounter[u8HwCtrl]++;
           #endif
        }
    }
}
#endif /* CAN_LLCE_USE_HEADLESSMODE == STD_ON */

/**
* @brief          Writes configuration to memory and sends SETAUXFILTER for all enabled controllers.
* @details        Initialization of indicator, statuses, etc.
*                 This function is non-reentrant and does not provide thread safety
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
#if (RXLUT2_ENABLE == STD_ON)
static void Can_Llce_SetConfiguredAuxReceiveFilters(void)
{
    uint8 u8HwCtrl = 0U;
    uint8 u8CtrlIndex= 0U;
    uint16 crtFilter = 0U;
    uint8 filterLoadedCount = 0U;
    const Llce_Can_AuxFilterType * filterList;
    volatile Llce_Can_SetAuxFilterCmdType * pSFCmd;
    Llce_Fw_ReturnType eReturnValue = LLCE_FW_SUCCESS;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        while((u8CtrlIndex < CAN_43_LLCE_MAXCTRL_CONFIGURED) && (LLCE_FW_SUCCESS == eReturnValue))
        {
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            if(Can_43_LLCE_GetCoreID() == pxConfig->aControllerDescriptors[u8CtrlIndex].u32CoreId)
            {
#endif

                /* Skip disabled controllers */
                if(LLCE_NULL_OFFSET_U8 != u8HwCtrl)
                {
                    u8HwCtrl = pxConfig->aControllerDescriptors[u8CtrlIndex].u8HwCtrl;
                    /*Configure the command id for all controllers which are used. */
                    Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETAUXFILTER;
                    pSFCmd = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetAuxFilter);
                    
                    filterList = pxConfig->paAuxFilters[u8HwCtrl];
                    filterLoadedCount = 0U;

                    crtFilter = 0U;
                    while((crtFilter < pxConfig->paLlce_MaxAuxilliaryFilterCount[u8HwCtrl]) && (LLCE_FW_SUCCESS == eReturnValue))
                    {
                        pSFCmd->aRxAuxFilters[filterLoadedCount] = filterList[crtFilter];
                        filterLoadedCount++;

                        /* Check if the command buffer for filters is full. */
                        if (LLCE_CAN_CONFIG_MAX_FILTERS_COUNT == filterLoadedCount)
                        {
                            pSFCmd->u16RxAuxFiltersCount = filterLoadedCount;
                
                            /* Send the command prepared above to the LLCE in order to be executed */
                            eReturnValue = Can_Llce_ExecuteIfCommand( u8HwCtrl );

                            /* Reset the number of filters. */
                            filterLoadedCount = 0;
                        }
                        crtFilter++;
                    }

                    /* Load remaining filters if any*/            
                    if (filterLoadedCount > 0U)
                    {
                        pSFCmd->u16RxAuxFiltersCount = filterLoadedCount;
                    
                        /* Send the command prepared above to the LLCE in order to be executed */
                        eReturnValue = Can_Llce_ExecuteIfCommand( u8HwCtrl );
                        /* Reset the number of filters. */
                        filterLoadedCount = 0;
                    }
                }
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            }
#endif
            u8CtrlIndex++;
        }
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
}
#endif



/**
* @brief          Initialize advanced feature.
* @details        Initialization of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
#if (LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0)
static void Can_Llce_AfInit(void)
{
#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
    uint16 u16Idx;
    
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    if((FALSE == pxConfig->bHeadlessModeEnabled) || (TRUE == Can_Llce_bHeadlessInitDone_AfInit) )
    {
#endif
        /* Send CREATE_AF_DESTINATION command*/
        #if (LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0)
            if(LLCE_FW_SUCCESS == Can_Llce_CreateConfiguredAfDestinations())
            {
        #endif
                /* Send SETADVANCEDFILTER command. */
                Can_Llce_SetConfiguredAfFilters();
        #if (LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0)
            }
        #endif
#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
    }
    else
    {
        for (u16Idx = 0U; u16Idx < (LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT); u16Idx++)
        {           
            /* Assume destinations are created in order */
            Can_au8DestinationIdxMap[u16Idx] = (uint8)u16Idx;
        }

        Can_Llce_EmulateSetConfiguredAfFilters();
        
        Can_Llce_bHeadlessInitDone_AfInit = TRUE;
    }
#endif
}

#if (CAN_LLCE_USE_HEADLESSMODE == STD_ON)
/**
* @brief          Calculates where filters would be loaded inside LLCE
* @details        When LLCE is started in headless mode, calculate HRH-filter mapping, to allow
*                 removal or disabling.
*/
static void Can_Llce_EmulateSetConfiguredAfFilters(void)
{
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();
    const Llce_Can_AdvancedFilterType * filterList;
    uint8 u8HwCtrl;
    uint16 u16CrtFilter, u16HrhId;

    /* FW loads filters based on physical controller */
    for(u8HwCtrl = 0U; u8HwCtrl < LLCE_CAN_CONFIG_MAXCTRL_COUNT; u8HwCtrl++)
    {
        filterList = pxConfig->paAdvancedFilters[u8HwCtrl];

        for(u16CrtFilter = 0U; u16CrtFilter < pxConfig->pPlatfInitConfig->au16MaxAdvancedFilterCount[u8HwCtrl]; u16CrtFilter++)
        {
            u16HrhId = filterList[u16CrtFilter].Llce_Can_RxFilter.u16FilterId;

          #if defined(S32G2XX)
            /* On G2 filters are assigned based on type */
            if(LLCE_CAN_ENTRY_EXACT_MATCH == filterList[u16CrtFilter].Llce_Can_RxFilter.eEntryType)
            {
                Can_Llce_au16RxHrh2FilterAddr[u16HrhId] = Can_Llce_u16RxLutExactMatchCounter;
                Can_Llce_u16RxLutExactMatchCounter++;
            }
            else
            {
                Can_Llce_au16RxHrh2FilterAddr[u16HrhId] = Can_Llce_u16RxLutConfigurableCounter;
                Can_Llce_u16RxLutConfigurableCounter++;
            }
          #elif defined(S32G3XX)
            /* On G3 filters are simply loaded sequentially */
            Can_Llce_au16RxHrh2FilterAddr[u16HrhId] = Can_Llce_au16RxLutCounter[u8HwCtrl];
            Can_Llce_au16RxLutCounter[u8HwCtrl]++;
          #endif

          #if (CAN_43_LLCE_CUSTOM_RX_CALLBACK_USED == STD_ON)
            /* Save reference to filter config for later usage. */
            Can_Llce_apRxHrh2AfFilterCfg[u16HrhId] = &(pxConfig->paAdvancedFilters[u8HwCtrl][u16CrtFilter]);
          #endif
        }
    }
}
#endif /* CAN_LLCE_USE_HEADLESSMODE == STD_ON */

#endif /* LLCE_CAN_ADVANCED_FEATURE_AF_CNT > 0 */

#if((LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON))

/* Utility function to get PFE physical interface enum from uint */
static inline pfe_ct_phy_if_id_t Can_Llce_PfeIf_GetPhyIf(uint8 Hif)
{
    pfe_ct_phy_if_id_t pfe_hif_id;
    const pfe_ct_phy_if_id_t pfe_hif_id_list[] = {
        PFE_PHY_IF_ID_EMAC0,
        PFE_PHY_IF_ID_EMAC1,
        PFE_PHY_IF_ID_EMAC2,
        PFE_PHY_IF_ID_HIF,
        PFE_PHY_IF_ID_HIF_NOCPY,
        PFE_PHY_IF_ID_UTIL,
        PFE_PHY_IF_ID_HIF0,
        PFE_PHY_IF_ID_HIF1,
        PFE_PHY_IF_ID_HIF2,
        PFE_PHY_IF_ID_HIF3,
    };

    if(Hif > (uint8)PFE_PHY_IF_ID_MAX)
    {
        pfe_hif_id = PFE_PHY_IF_ID_INVALID;
    }
    else
    {
        pfe_hif_id = pfe_hif_id_list[Hif];
    }

    return pfe_hif_id;
}

/** @implements    Can_Llce_Init_PfeIf_Activity */
Std_ReturnType Can_Llce_Init_PfeIf(uint8 Hif)
{
    uint32 u32ringSize;
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue = LLCE_FW_NOTRUN;
    #if (LLCE_USE_EXTERNAL_RING_BUF == STD_ON)
        volatile Llce_Can_InitPfeWithExternRingCmdType* pfeInitCmd = NULL_PTR;
    #else
        volatile Llce_Can_InitPfeCmdType* pfeInitCmd = NULL_PTR;
    #endif
    pfe_ct_phy_if_id_t pfe_hif_id;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Init LLCE-PFE interface */
        #if (LLCE_USE_EXTERNAL_RING_BUF == STD_ON)
            pfeInitCmd = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.InitPfeWithExternRing);

            pfeInitCmd->pRxRing = (uint32)&Llce_PfeIf_RxRing;
            pfeInitCmd->pRxWbRing = (uint32)&Llce_PfeIf_RxWbRing;
            pfeInitCmd->pTxRing = (uint32)&Llce_PfeIf_TxRing;
            pfeInitCmd->pTxWbRing = (uint32)&Llce_PfeIf_TxWbRing;
            pfeInitCmd->pHeader = (uint32)&Llce_PfeIf_Hdr;
            pfeInitCmd->u8HeaderSize = LLCE_PFE_TX_HDR_COUNT;
            pfeInitCmd->u32RingSize = LLCE_PFE_HIF_RING_CFG_LENGTH;

            u32ringSize = pfeInitCmd->u32RingSize;
            
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_INIT_PFE_EXT_RING_BUF;
        #else
            pfeInitCmd = &(Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.InitPfe);
            u32ringSize = PFE_HIF_RING_CFG_LENGTH;
            
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_INIT_PFE;
        #endif

        pfeInitCmd->u8Hif = Hif;
#if LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON
        pfeInitCmd->pRxBuffers = (uint32)&Llce_Eth2Can_Buffer;
        pfeInitCmd->u16RxBufSize = LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_BUF_SIZE;
        pfeInitCmd->u8RxBufCount = LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_BUF_CNT;        
#else
        pfeInitCmd->pRxBuffers = 0U;
        pfeInitCmd->u16RxBufSize = 0U;
        pfeInitCmd->u8RxBufCount = 0U;        
#endif

        eCommandReturnValue = Can_Llce_ExecuteIfCommand(pxConfig->u8DefaultController);
    }

    if (LLCE_FW_SUCCESS == eCommandReturnValue )
    {
        /* Set the contents of llce_minihif to known values */
        (void)memset(&llce_minihif, 0, sizeof(llce_minihif));

        pfe_hif_id = Can_Llce_PfeIf_GetPhyIf(Hif);

        if((Std_ReturnType)E_OK == (Std_ReturnType)pfe_minihif_drv_create(&llce_minihif, pfe_hif_id, FALSE))
        {
            if((Std_ReturnType)E_OK == (Std_ReturnType)pfe_minihif_drv_attach_ring(&llce_minihif, TRUE,  (void*)(pfeInitCmd->pRxRing), (void*)(pfeInitCmd->pRxWbRing), u32ringSize))
            {
                if((Std_ReturnType)E_OK == (Std_ReturnType)pfe_minihif_drv_attach_ring(&llce_minihif, FALSE, (void*)(pfeInitCmd->pTxRing), (void*)(pfeInitCmd->pTxWbRing), u32ringSize))
                {
                    if((Std_ReturnType)E_OK == (Std_ReturnType)pfe_minihif_drv_init(&llce_minihif))
                    {
                        eReturnValue = E_OK;
                    }
                }
            }
        }
    }

    if((Std_ReturnType)E_OK == eReturnValue)
    {
        /* If this application was reloaded with PFE still running, the pfe_minihif calls above 
         * could have altered the state of the rings. Call the INIT_PFE command again to trigger
         * a reinit of the minihif in LLCE */
        eCommandReturnValue = Can_Llce_ExecuteIfCommand(pxConfig->u8DefaultController);

        if (LLCE_FW_SUCCESS != eCommandReturnValue )
        {
            eReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    return eReturnValue;
}

/**
* @brief          Start of PFE.
* @details        Initialization of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
Std_ReturnType Can_Llce_Start_PfeIf(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;

    if((Std_ReturnType)E_OK == (Std_ReturnType)pfe_minihif_drv_start_rx(&llce_minihif))
    {
        if((Std_ReturnType)E_OK == (Std_ReturnType)pfe_minihif_drv_start_tx(&llce_minihif))
        {
            eReturnValue = E_OK;
        }
    }

    return eReturnValue;
}
#endif /* ((LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0) || (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON)) */

#if(LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0)
/**
* @brief          Set current Can2Eth state
* @details        Initialization of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
* @implements     Can_Llce_SetCan2EthState_Activity
*
*/
Std_ReturnType Can_Llce_SetCan2EthState(Can_Llce_Can2EthStateType eState)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue = LLCE_FW_NOTRUN;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    /* Check if command is available */
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETCAN2ETHSTATE;

        if(CAN_LLCE_CAN2ETH_ENABLED == eState)
        {
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.eBinaryValue = LLCE_TRUE;
        }
        else
        {
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.eBinaryValue = LLCE_FALSE;
        }

        eCommandReturnValue = Can_Llce_ExecuteIfCommand(pxConfig->u8DefaultController);
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    if (LLCE_FW_SUCCESS == eCommandReturnValue)
    {
        eReturnValue = (Std_ReturnType)E_OK;
    }

    return eReturnValue;
}
#endif /* LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0 */

#if (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON)
/**
* @brief          Enable/disable Eth2Can decapsulation for a particular format.
* @details        Sends command to FW to start/stop decapsulation Eth2Can frames of a particular type
*                 This routine is called by:
*                 - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
*/
Llce_Fw_ReturnType Can_Llce_SetEth2CanFormatState(Llce_Can_EthEncapsulationFormat eFormat, Can_Llce_Eth2CanStateType eState)
{
    Llce_Fw_ReturnType eReturnValue = LLCE_FW_NOTRUN;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    /* Check if command is available */
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETETH2CANFORMATSTATE;
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetEth2CanFormatState.eFormat = eFormat;
        if(CAN_LLCE_ETH2CAN_ENABLED == eState)
        {
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetEth2CanFormatState.eState = LLCE_TRUE;
        }
        else
        {
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetEth2CanFormatState.eState = LLCE_FALSE;
        }

        eReturnValue = Can_Llce_ExecuteIfCommand(pxConfig->u8DefaultController);
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}
#endif /* (LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED == STD_ON) */

#if LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0
/**
* @brief          Set current Can2Pcie state
* @details        Enable/disable Can2Pcie in LLCE FW
*
* @pre            At least one controller must be configured in the Driver structure.
* @implements     Can_Llce_SetCan2PcieState_Activity
*
*/
Std_ReturnType Can_Llce_SetCan2PcieState(Can_Llce_Can2PcieStateType eState)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue = LLCE_FW_NOTRUN;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    /* Check if command is available */
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETCAN2PCIESTATE;

        if(CAN_LLCE_CAN2PCIE_ENABLED == eState)
        {
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.eBinaryValue = LLCE_TRUE;
        }
        else
        {
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.eBinaryValue = LLCE_FALSE;
        }

        eCommandReturnValue = Can_Llce_ExecuteIfCommand(pxConfig->u8DefaultController);
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    if (LLCE_FW_SUCCESS == eCommandReturnValue)
    {
        eReturnValue = (Std_ReturnType)E_OK;
    }

    return eReturnValue;
}
#endif /* LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT > 0 */


/*================================================================================================*/
/**
* @brief          Service for de-initializing only CAN controller specific settings.
* @details        CAN controller de-initialization.
*                 This routine is called by:
*                  - Can_43_LLCE_DeInit() from Can.c file.
*
* @param[in]      u8HwCtrl: CAN controller for which the initialization shall be done.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           De-initialization controller's configuration.
*
*/
Std_ReturnType Can_Llce_DeInitController(uint8 u8HwCtrl)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_DEINIT;
        
        /* Send the command prepared above to the LLCE in order to be executed */
        eCommandReturnValue = Can_Llce_ExecuteIfCommand( u8HwCtrl );

        if(LLCE_FW_SUCCESS == eCommandReturnValue)
        {
            /* Update status in order to discard tx/rx processing */
            SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
            Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState = CAN_CS_UNINIT;
            SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
            eReturnValue = (Std_ReturnType)E_OK;
        }
    }
    
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

Std_ReturnType Can_Llce_DeInitPlatform(void)
{   
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;
    uint8 u8Interface;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /*All the FIFOs corresponding to a given HIF are reset at once due to the flexible FIFO allocation feature*/
    for (u8Interface = 0U; u8Interface < LLCE_CAN_CONFIG_MAXCTRL_COUNT; u8Interface++)
    {   
        /*check alive RX int interfaces that shall be cleaned in case the data was not consumed*/
        if (0U != pxConfig->pPlatfInitConfig->au16MaxIntMbCount[u8Interface])
        {
            Can_Llce_ResetFifoContent(u8Interface);
        }
    }

    for (u8Interface = 0U; u8Interface < LLCE_CAN_MAX_POLLING_CLASSES; u8Interface++)
    {   
        /*check alive RX poll interfaces that shall be cleaned in case the data was not consumed*/
        if (0U != pxConfig->pPlatfInitConfig->au16MaxPollMbCount[u8Interface])
        {
            Can_Llce_ResetFifoContent(u8Interface + LLCE_CAN_CONFIG_MAXCTRL_COUNT);
        }
    }

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_DEINIT_PLATFORM;
        
        /* Send the command prepared above to the LLCE in order to be executed */
        if(LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( pxConfig->u8DefaultController ))
        {
            eReturnValue = (Std_ReturnType)E_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    /*Disable the Notif FIFO interrupt*/
    Can_Llce_DisableNotifInterrupt(pxConfig->u8ActiveHif);

    return eReturnValue;
}

/**
* @brief          Send LLCE shutdown command 
* @details        Shut down LLCE before doing a partition reset
*
* @pre            Both HIFs are uninitialized/deinitialized.
* @post           LLCE is shut down and must be reset.
*
* @implements     Can_Llce_Shutdown_Activity
*/
Std_ReturnType Can_Llce_Shutdown(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue = LLCE_FW_NOTRUN;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    /* Check if command is available */
    if ((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SHUTDOWN;

        eCommandReturnValue = Can_Llce_ExecuteIfCommand(pxConfig->u8DefaultController);
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    if (LLCE_FW_SUCCESS == eCommandReturnValue)
    {
        eReturnValue = (Std_ReturnType)E_OK;
    }

    return eReturnValue;
}

/**
* @brief          Routine for resetting FIFO content
* @details        In case of a message sent by LLCE firmware just after the SetControllerMode(STOP) command,
*                 the driver shall cancel the pending message.                  
*                 This routine is called by Can_Llce_SetControllerToStartMode and it makes sure about a
*                 clean FIFO content before the controller is requested to start.
*
* @param[in]      u8Interface FIFO interface to be reset
*
*/
static void Can_Llce_ResetFifoContent(uint8 u8Interface)
{
    uint16 u16Token;
    uint16 u16SafetyLoopEscapeCnt = 0U;
    /* Timeout counter. */
    uint32 u32timeStart = 0U;
    uint32 u32timeElapsed = 0U;
    uint32 u32TicksDelayDuration = 0U;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    if (u8Interface < (LLCE_CAN_CONFIG_MAXCTRL_COUNT + LLCE_CAN_MAX_POLLING_CLASSES))
    {
        if (u8Interface < LLCE_CAN_CONFIG_MAXCTRL_COUNT)
        {
            u16SafetyLoopEscapeCnt = pxConfig->pPlatfInitConfig->au16MaxIntMbCount[u8Interface];
        }
        else
        {
            u16SafetyLoopEscapeCnt = pxConfig->pPlatfInitConfig->au16MaxPollMbCount[u8Interface - LLCE_CAN_CONFIG_MAXCTRL_COUNT];
        }

        /* Abort RX messages and return the token to LLCE */
        while (( LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8Interface))) & (uint32)(LLCE_FIFO_FEMTYD_U32)) ) && \
               (u16SafetyLoopEscapeCnt > 0U))
        {
            u16SafetyLoopEscapeCnt--;

            /* Read data from the fifo. */
            u16Token = (uint16)Reg_Read32( LLCE_FIFO_POP0(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8Interface)));

            u32timeStart = OsIf_GetCounter(CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
            u32TicksDelayDuration = OsIf_MicrosToTicks(CAN_43_LLCE_TIMEOUT_DURATION, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
            u32timeElapsed = 0U;

            /* Wait for LLCE to consume the tokens before DEINIT_PLATFORM cmd is issued */
            while ( (0U == (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif))) & (uint32)(LLCE_FIFO_FEMTYD_U32)) ) && (u32timeElapsed < u32TicksDelayDuration))
            {
                u32timeElapsed += OsIf_GetElapsed(&u32timeStart, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
            }
            
            Reg_Write32( LLCE_FIFO_PUSH0(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif)), (uint32)u16Token);
        }
        
        /* Abort TX confirmations. */
        Reg_Bit_Set32(LLCE_FIFO_CONFIG(LLCE_FIFO_TXACK_BASE_ADDRESS(u8Interface)), LLCE_FIFO_FCR_FLUSH_U32);
    }

}

#if (CAN_43_LLCE_BUSOFF_RECOVERY_ENABLED == STD_OFF)
/*================================================================================================*/
/**
* @brief          API for servicing the bus-off event.
* @details        CAN controller bus-off reaction.
*                 This routine is called by:
*                  
*
* @param[in]      Controller CAN controller for which the bus-off was generated.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           
*
*
*/
static void Can_Llce_ControllerBusOff(uint8 u8HwCtrl)
{
    uint16 u16RxMbDescIdx;
    uint16 u16SafetyLoopEscapeCnt;
    uint32 u32DrvControllerOptions;
    /* Timeout counter. */
    uint32 u32timeStart = 0U;
    uint32 u32timeElapsed = 0U;
    uint32 u32TicksDelayDuration = 0U;
    
    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Update status */
    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
    Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState = CAN_CS_STOPPED;
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();

    u16SafetyLoopEscapeCnt = pxConfig->pPlatfInitConfig->au16MaxIntMbCount[u8HwCtrl];
    u32DrvControllerOptions = pxConfig->aHwControllerDescriptors[u8HwCtrl].u32DrvControllerOptions;

    /* In case of polling classes, the outdated messages are detected at MainFunction_Read/Write by checking the controller state. */
    if(LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32))
    {
        while ( (LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8HwCtrl))) & (uint32)(LLCE_FIFO_FEMTYD_U32)) ) && \
                (u16SafetyLoopEscapeCnt > 0U))
        {
            u16SafetyLoopEscapeCnt --;
            /* Read data from the fifo. */
            u16RxMbDescIdx = (uint16)Reg_Read32( LLCE_FIFO_POP0(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8HwCtrl)));

            u32timeStart = OsIf_GetCounter(CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
            u32TicksDelayDuration = OsIf_MicrosToTicks(CAN_43_LLCE_TIMEOUT_DURATION, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
            u32timeElapsed = 0U;

            /* Wait for LLCE to consume the tokens before next token is pushed */
            while ( (0U == (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif))) & (uint32)(LLCE_FIFO_FEMTYD_U32)) ) && (u32timeElapsed < u32TicksDelayDuration))
            {
                u32timeElapsed += OsIf_GetElapsed(&u32timeStart, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
            }

            Reg_Write32( LLCE_FIFO_PUSH0(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif)), (uint32)u16RxMbDescIdx);
        }
    }

    if(LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 == (u32DrvControllerOptions & LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32))
    {
        /* Process all the ACK before notify BusOff event. */
        Can_Llce_ProcessTx(u8HwCtrl);
    }
    
    Can_43_LLCE_ControllerBusOff(u8HwCtrl);

}
#endif /* #if (CAN_43_LLCE_BUSOFF_RECOVERY_ENABLED == STD_OFF) */

/*================================================================================================*/
/**
* @brief          Service for (re)initializing only CAN controller specific settings.
* @details        CAN controller (re-)initialization.
*                 This routine is called by:
*                  - Can_43_LLCE_Init() from Can_43_LLCE.c file.
*
* @param[in]      Controller CAN controller (HW) for which the init shall be done.
* @param[in]      pxBaudrateConfigPtr The baud rate configuration (contains baud rate parameters for arbitration phase).
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set the MBs and interrupts into predefinite state for Can bus communication.
*
*
*/

Std_ReturnType Can_Llce_ChangeBaudrate(uint8 u8HwCtrl, const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = E_NOT_OK;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if(NULL_PTR != pxBaudrateConfigPtr) 
    {
        eReturnValue = Can_Llce_CheckCommandAvailable();
        if((Std_ReturnType)E_OK == eReturnValue)
        {
            /* Configure the command id */
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_SETBAUDRATE;

            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.SetBaudrate = *pxBaudrateConfigPtr;

            /* Send the command prepared above to the LLCE in order to be executed */
            if(LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( u8HwCtrl ))
            {
                eReturnValue = E_OK;
            }
            else
            {
                eReturnValue = E_NOT_OK;
            }
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief          Return the mode of the CAN controller
* @details        Retrieve the mode of the specified controller from firmware and update the local state.
*                 Exception: (logical) sleep mode is stored in the driver. In Sleep state, no request is made to FW.
*                 This routine is called by:
*                  - Can_43_LLCE_GetControllerMode() from Can_43_LLCE.c file.
*
* @param[in]      u8HwCtrl CAN controller for which the status shall be requested.
* @param[out]     ControllerModePtr Current AUTOSAR state of the CAN controller will be stored.
*
* @return         Std_ReturnType
* @retval         E_OK Controller mode request has been accepted.
* @retval         E_NOT_OK Controller mode request has not been accepted.
*
* @pre            
* @post           
*
* @requirements   
* @implements     Can_Llce_GetControllerMode_Activity
*/
Std_ReturnType Can_Llce_GetControllerMode(uint8 u8HwCtrl, Can_ControllerStateType * ControllerModePtr)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;

    Llce_Can_CtrlStateType eLlceControllerMode;

    /* Sleep state is "logical" and stored internally */
    if(CAN_CS_SLEEP == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState )
    {
        *ControllerModePtr = CAN_CS_SLEEP;
        eReturnValue = E_OK;
    }
    else
    {
        /* Send the command prepared above to the LLCE in order to be executed */
        if((Std_ReturnType)E_OK == Can_Llce_GetLlceControllerMode(u8HwCtrl, &eLlceControllerMode))
        {
            /* Update local status as well */
            switch(eLlceControllerMode)
            {
                case LLCE_CAN_UNINIT_CTRL:
                    *ControllerModePtr = CAN_CS_UNINIT;
                    break;
#if (CAN_43_LLCE_CONTROLLER_START_NOSYNC == STD_ON)
                case LLCE_CAN_START_PENDING:
                    *ControllerModePtr = CAN_CS_STARTED;
                    break;
#endif
                case LLCE_CAN_STARTED:
                    *ControllerModePtr = CAN_CS_STARTED;
                    break;
                case LLCE_CAN_STOPPED:
                    *ControllerModePtr = CAN_CS_STOPPED;
                    break;
                default:
                    /* If the state is pending or there are no changes to current status, retrieve the last state. */
                    *ControllerModePtr = Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState;
                    break;
            }

            eReturnValue = E_OK;
        }
    }

    return (eReturnValue);
}

/*================================================================================================*/
/**
* @brief          Return the internal state of LLCE controller
* @details        Retrieve the mode of the specified controller from firmware.
*                 According to the LLCE interface, multiple states are possible for a given controller which may be
*                 needed for the CAN driver to comply with the internal LLCE state machine.
*
* @param[in]      Controller CAN controller for which the status shall be requested. Based on configuration order list (CanControllerId).
* @param[out]     eLlceControllerMode Pointer to a memory location, where the current internal mode of the CAN controller will be stored.
*
* @return         Std_ReturnType
* @retval         E_OK Controller mode request has been accepted.
* @retval         E_NOT_OK Controller mode request has not been accepted.
*
*/
static Std_ReturnType Can_Llce_GetLlceControllerMode(uint8 u8HwCtrl,  Llce_Can_CtrlStateType *eLlceControllerMode)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_GETCONTROLLERMODE;  

        /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand( u8HwCtrl ))
        {
            *eLlceControllerMode = Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.GetControllerMode.eControllerState;

            eReturnValue = E_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to another state/mode.
*                 This routine is called by:
*                  - Can_43_LLCE_SetControllerMode() from Can_43_LLCE.c file.
*                  - Can_43_LLCE_IPW_ProcessBusOff() from Can_IPW.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done.
* @param[in]      Transition Possible transitions
* @param[in]      pxBaudrateConfigPtr Configuration parameters for the controller baud rate settings
*
* @return         Std_ReturnType
* @retval         E_OK transition initiated
* @retval         E_NOT_OK development or production error
*
* @pre            Controller is configured and must be into a state that permit the valid transition to another different state.
* @post           Shall enable interrupts that are needed in the new state. Shall disable interrupts that are not allowed in the new state.
*
* @requirements   CAN283
*
* @implements     Can_Llce_SetControllerMode_Activity
*/
Std_ReturnType Can_Llce_SetControllerMode(uint8 u8HwCtrl, Can_ControllerStateType Transition, const Llce_Can_SetBaudrateCmdType* pxBaudrateConfigPtr)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;

    /*
      (CAN017) The function Can_43_LLCE_SetControllerMode shall perform software triggered state transitions of the CAN controller State machine.
    */
    switch (Transition)
    {
        /* CAN_CS_STARTED -> CAN_CS_STOPPED. */
        case (CAN_CS_STOPPED):
            eReturnValue = Can_Llce_SetControllerToStopMode(u8HwCtrl);
            break;

        /* CAN_CS_STOPPED -> CAN_CS_STARTED. */
        case (CAN_CS_STARTED):
            eReturnValue = Can_Llce_SetControllerToStartMode(u8HwCtrl, pxBaudrateConfigPtr);
            break;

        /* CAN_CS_STOPPED -> CAN_CS_SLEEP. */
        case (CAN_CS_SLEEP):
            eReturnValue = Can_Llce_SetControllerToSleepMode(u8HwCtrl);
            break;

        /* Unknown transition requested. */
        default:
        /*
           (CAN200) If development error detection for the Can module is enabled: if an invalid transition has been requested, the function Can_43_LLCE_SetControllerMode shall raise the error CAN_43_LLCE_E_TRANSITION and return E_NOT_OK.
        */
            (void)Can_43_LLCE_ReportError((uint8)CAN_43_LLCE_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_LLCE_E_TRANSITION);

            break;

        } /* end switch */

    return (eReturnValue);
}

/*================================================================================================*/
/**
* @brief          Send a frame to the hardware.
* @details        Checks if hardware transmit object that is identified by the HTH is free.
*                     Can_43_LLCE_Write checks if another Can_43_LLCE_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers/buffers.
*                         All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with E_OK.
*                     b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_43_LLCE_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                         The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                         The transmission of the previous L-PDU is cancelled (asynchronously).
*                         The function returns with CAN_BUSY.
*                         This routine is called by:
*                         - Can_43_LLCE_Write() from Can_43_LLCE.c file.
*                     Algorithm Description:
*                     Case1: TxMUX supported = ON
*                           Can_43_LLCE_Write receive the Hth handle and the PduInfo for transmission. It starts to check from the first MBs of the
*                           current controller to search for a free MB. On the first free MB it stops and place the PduInfo and activate the transmission.
*                           In this case function set E_OK for return value and all other functionality is skipped.
*                           If no MB is finded as free then the lowest priority MB is selected for comparing with the priority of the current PduInfo.
*                           If the current PduInfo has a higher priority than the current lower priority (from all MBs) then this lower priority MB is canceled.
*                    Case2: TxMUX supported = OFF
*                          CanWrite() receive the Hth handle and the PduInfo for transmission. It checks if MB with the same index as Hth is free and if yes prepare
*                          and sends the current PduInfo data. If that MB is busy with another data then it checks the priority between these 2 structures.
*                          Depending by the last evaluation it decides what MB data to cancel.
*
* @param[in]      Hth information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use
*                 because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier
*
* @return          Std_ReturnType
* @retval          E_OK write command has been accepted
* @retval          E_NOT_OK development error occurred
* @retval          CAN_BUSY no TX hardware buffer available or preemtive call of Can_43_LLCE_Write() that can't be implemented reentrant
*
* @pre            The MB must be configured for Tx.
* @post           Transmit the data or ignore it in case of MB is full with another task.
*
*/
    Std_ReturnType Can_Llce_Write(uint8 u8HwCtrl, Can_43_LLCE_TxFrameInfoType* TxFrameInfo)
    {
        /* Variable for the TX MB descriptor */
        uint32 u32TxMbDescIdx = 0U;
        /* Variable for return status. */
        Std_ReturnType eReturnValue = (Std_ReturnType)CAN_BUSY;

    #ifdef CAN_43_LLCE_MEASURE_WRITE_LATENCY       
        Reg_Write32(LLCE_STM_CR,0x00);/* Disable STM counter. */ 
        Reg_Write32(LLCE_STM_CNT,0);/* Clear STM counter. */   
        Reg_Write32(LLCE_STM_CR,0x01);/* Enable STM counter. */ 
    #endif

        /* Attempt to get address of a free message buffer*/
        /* Read data from the fifo. */
        u32TxMbDescIdx = Reg_Read32( LLCE_FIFO_POP0(LLCE_FIFO_BLROUT_BASE_ADDRESS(u8HwCtrl)));

        /* Check if buffer ID is valid */
        if (LLCE_FIFO_NULL_VALUE != u32TxMbDescIdx)
        {  
            /* Apply mask to get the correct fifo entry value */
            u32TxMbDescIdx = u32TxMbDescIdx & LLCE_CAN_CONFIG_FIFO_FIXED_MASK_U32;

            /* Share TX MB descriptor to Can_Llce_UpdateMB using u16MbFrameIdx field*/
            TxFrameInfo->u16MbFrameIdx = (uint16)u32TxMbDescIdx;

            /* Write data into the Message buffer for transition. */
            Can_Llce_UpdateMB(TxFrameInfo);

            /*Check if the pointer to the full tx message buffer can be sent to the LLCE*/
            if ( LLCE_FIFO_FFULLD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_BLRIN_BASE_ADDRESS(u8HwCtrl))) & (uint32)(LLCE_FIFO_FFULLD_U32)) )
            {
                #if (CAN_43_LLCE_CUSTOM_WRITE_CALLBACK_USED == STD_ON)
                
                Can_43_LLCE_CustomWriteCallback(TxFrameInfo->u16FrameTag1 /*HoH*/, TxFrameInfo->u16FrameTag2 /*swPduHandle*/, (uint16)u32TxMbDescIdx /*TxMbDescIdx*/);

                #endif

                /* Write data to the fifo. */
                Reg_Write32( LLCE_FIFO_PUSH0(LLCE_FIFO_BLRIN_BASE_ADDRESS(u8HwCtrl)),u32TxMbDescIdx);

        #ifdef CAN_43_LLCE_MEASURE_WRITE_LATENCY  
    #ifndef CAN_43_LLCE_MEASURE_WRITE_BUS_LATENCY         
        Stm_Measurement = Reg_Read32(LLCE_STM_CNT) - Stm_Measurement;
    #endif
        host_write_label:
    #endif
                /* The request was successfully sent to the LLCE. */
                eReturnValue = E_OK;
            }
            else /* Defensive action against hardware FIFO communication fail. */
            {
                /* The pointer to the full tx mb can not be sent to the LLCE. Token lost. Requires controller restart. */
                eReturnValue = E_NOT_OK;

                #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                (void)Can_43_LLCE_ReportError((uint8)CAN_43_LLCE_SID_WRITE, (uint8)CAN_43_LLCE_E_LLCE_FAILED);
                #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            }

        }
        else
        {
            /* No pointer available to a free message buffer */
            eReturnValue = CAN_BUSY;
        }

        return (eReturnValue);
    }

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer from ISR when Interrupt mode selected.
* @details        Processes Tx interrupt flags.
*               This routine is called by:
*                - Can_43_LLCE_IPW_ProcessTx() from Can_43_LLCE.c file.
*                - Can_IsrFC##FC##_UNI() / Can_IsrFC##FC##_##Name() from Can_Irq.c file.
*
* @param[in]      u8AckInterface Fifo Interface [0-15] which generated interrupt for ACK event.
*
* @pre            MB is configured for Tx.
* @post           CanIf is informed with cancellation or transmit success.
*
*/
void Can_Llce_ProcessTx(const uint8 u8AckInterface)
{
    #ifdef MCAL_ENABLE_FAULT_INJECTION
    MCAL_FAULT_INJECTION_POINT(CAN_43_LLCE_FIP_4_MODIFY_IER_WHILE_PROCESSTX);
    #endif

    uint16 u16HohIndex;
    uint16 u16SafetyLoopEscapeCnt;
    uint16 u16AckEntry = 0U;
    uint8 u8HwCtrl;
    uint8 u8ControllerId;
    uint32 u32IER = Reg_Read32(LLCE_FIFO_IER(LLCE_FIFO_TXACK_BASE_ADDRESS(u8AckInterface)));
    uint32 u32Status = Reg_Read32(LLCE_FIFO_STATUS1(LLCE_FIFO_TXACK_BASE_ADDRESS(u8AckInterface)));
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

#if (CAN_43_LLCE_ACK_TIMESTAMP == STD_ON)
    uint16 u16FrameTag2 = 0u;
#endif

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Check for spurious interrupt and for initialized driver. */
    if ( (CAN_43_LLCE_READY == Can_43_LLCE_eDriverStatus[u32CoreId]) &&
        (LLCE_FIFO_FNEMTY_U32 == (u32IER & LLCE_FIFO_FNEMTY_U32)) && \
        (LLCE_FIFO_FNEMTY_U32 == (u32Status & LLCE_FIFO_FNEMTY_U32)) )
    {
        u16SafetyLoopEscapeCnt = pxConfig->pPlatfInitConfig->au16MaxIntTxAckCount[u8AckInterface];

        /* Process all entries from the TXACK FIFO. They can be originated by multiple hardware controllers. */
        while ((LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_TXACK_BASE_ADDRESS(u8AckInterface))) & (uint32)(LLCE_FIFO_FEMTYD_U32))) && \
               (u16SafetyLoopEscapeCnt > 0U))
        {
            u16SafetyLoopEscapeCnt--;
            /* Read the index into the circular buffer containing the ack info.*/
            u16AckEntry = (uint16)(Reg_Read32( LLCE_FIFO_POP0(LLCE_FIFO_TXACK_BASE_ADDRESS(u8AckInterface))) & LLCE_CAN_CONFIG_FIFO_FIXED_MASK_U32);
            
            u16HohIndex = Can_SharedMemory.Can_Tx_aAckInfo[u16AckEntry].u16FrameTag1;

            Can_Hth_FreeTxObject(u16HohIndex, 1U);

            u8ControllerId = pxConfig->aHohList[u16HohIndex].u8ControllerId;
  
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            if(Can_43_LLCE_GetCoreID() == pxConfig->aControllerDescriptors[u8ControllerId].u32CoreId)
            {
#endif
                /* Get the hardware offset for this controller. */
                u8HwCtrl = pxConfig->aControllerDescriptors[u8ControllerId].u8HwCtrl;
           
                if ( CAN_CS_STARTED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState )
                {
                    /* Check if corresponding controller is started and the hoh is configured for reporting through interrupt mode */
                    if (LLCE_CAN_REFERENCE_NOT_USED == pxConfig->aHohList[u16HohIndex].u8CanMainFuncRWPeriodRef)
                    {
                        #if (CAN_43_LLCE_CUSTOM_CONFIRMATION_CALLBACK == STD_ON)
                    
                        Can_43_LLCE_CustomTxConfirmationCallback(u16HohIndex /*HoH*/, Can_SharedMemory.Can_Tx_aAckInfo[u16AckEntry].u16FrameTag2 /*swPduHandle*/);

                        #endif
                        /*
                        (CAN058) The Can module interacts among other modules (eg. Diagnostic Event Manager (DEM), Development Error Tracer (DET)) with the CanIf module in a direct way.
                                The driver only sees the CanIf module as origin and destination.
                        */
                        Can_43_LLCE_TxConfirmation( Can_SharedMemory.Can_Tx_aAckInfo[u16AckEntry].u16FrameTag2 );

                        /* Get Frame Tag */
                        #if (CAN_43_LLCE_ACK_TIMESTAMP == STD_ON)
                            u16FrameTag2 = Can_SharedMemory.Can_Tx_aAckInfo[u16AckEntry].u16FrameTag2;
                            Can_43_LLCE_TxTimestampNotification(u16HohIndex, u16FrameTag2, Can_SharedMemory.Can_Tx_aAckInfo[u16AckEntry].u32TxTimestamp);
                        #endif
                    }
                }
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            }
#endif
        }
    }

    /* Clear the interrupt status flag. */
    Reg_Write32( LLCE_FIFO_STATUS1(LLCE_FIFO_TXACK_BASE_ADDRESS(u8AckInterface)), LLCE_FIFO_FNEMTY_U32); 
    
}

/*================================================================================================*/
/**
* @brief          This routine accesses the notification interface configured in interrupt mode.
* @details        This routine accesses the notification interface configured in interrupt mode using indexes popped from NOTIF FIFO
*                 to retrieve the event information from notification table filled up by Llce firmware.
* @pre            
* @post           CanIf is notified about the bus-off events reported by the Llce firmware.
* @implements     Can_Isr_X_Activity
*/
void Can_Llce_ProcessNotificationISR(void)
{   
    uint8 u8NotifIdx = 0U;
    uint8 u8HwCtrl = 0U;
    uint16 u16SafetyLoopEscapeCnt = 0U;
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    #if (CAN_43_LLCE_ERROR_NOTIF_ENABLE == STD_ON)
    CanErrorNotificationType CanError;
    #endif

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    uint32 u32IER = Reg_Read32( LLCE_FIFO_IER(LLCE_NOTIF_FIFO0_BASE_ADDRESS(pxConfig->u8ActiveHif)));
    uint32 u32Status = Reg_Read32( LLCE_FIFO_STATUS1(LLCE_NOTIF_FIFO0_BASE_ADDRESS(pxConfig->u8ActiveHif)));

    /* Check for spurious interrupt and for initialized driver. */
    if ( (CAN_43_LLCE_READY == Can_43_LLCE_eDriverStatus[u32CoreId]) &&
            (LLCE_FIFO_FNEMTY_U32 == (u32IER & LLCE_FIFO_FNEMTY_U32)) && \
            (LLCE_FIFO_FNEMTY_U32 == (u32Status & LLCE_FIFO_FNEMTY_U32)) )
    {
        u16SafetyLoopEscapeCnt = LLCE_CAN_CONFIG_NOTIF_TABLE_SIZE;
        while ( (LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_NOTIF_FIFO0_BASE_ADDRESS(pxConfig->u8ActiveHif))) & (uint32)(LLCE_FIFO_FEMTYD_U32))) &&
                (u16SafetyLoopEscapeCnt > 0U))
        {
            u16SafetyLoopEscapeCnt--;
            u8NotifIdx = (uint8)Reg_Read32( LLCE_FIFO_POP0(LLCE_NOTIF_FIFO0_BASE_ADDRESS(pxConfig->u8ActiveHif)));

            if (LLCE_CAN_NOTIF_CHANNELERROR == Can_SharedMemory.Can_NotificationTable.Can_aNotif0_Table[pxConfig->u8ActiveHif][u8NotifIdx].eNotifId)
            {
                u8HwCtrl = Can_SharedMemory.Can_NotificationTable.Can_aNotif0_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.ChannelError.u8HwCtrl;
                /* Treat cases defined by Autosar spec. Rest of them are only sent through the user-defined callback */
                switch (Can_SharedMemory.Can_NotificationTable.Can_aNotif0_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.ChannelError.ErrorInfo.eErrorCode)
                {
                    case (LLCE_ERROR_BUSOFF):
                    #if (CAN_43_LLCE_BUSOFF_RECOVERY_ENABLED == STD_ON)
                        /* LLCE issues bus-off notification, but does not freeze the controller. */
                        Can_43_LLCE_ControllerBusOffCallback(pxConfig->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId);
                    #else
                        /* LLCE issues bus-off notification after controller freezes. AUTOSAR required behavior */
                        Can_Llce_ControllerBusOff(u8HwCtrl);
                    #endif
                    break;

                    /* DATALOST root causes */
                    case (LLCE_ERROR_RXOUT_FIFO_FULL):
                    case (LLCE_ERROR_MB_NOTAVAILABLE):
                    case (LLCE_ERROR_FRAME_NOT_DELIVERED_TO_HOST):
                    case (LLCE_ERROR_BCAN_RXFIFO_OVERRUN):
                        (void)Can_43_LLCE_ReportRuntimeError((uint8)CAN_43_LLCE_SID_PROCESS_NOTIFICATION_ISR, (uint8)CAN_43_LLCE_E_DATALOST);
                        break;

                    default:
                        /* Switch must handle all states. No action, just appease MISRA */
                        break;
                }

                #if (CAN_43_LLCE_ERROR_NOTIF_ENABLE == STD_ON)
                /* Report a channel error */
                CanError.u8CanIfCtrlId = pxConfig->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId;
                CanError.eNotifId = Can_SharedMemory.Can_NotificationTable.Can_aNotif0_Table[pxConfig->u8ActiveHif][u8NotifIdx].eNotifId;
                CanError.ErrorInfo = &(Can_SharedMemory.Can_NotificationTable.Can_aNotif0_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.ChannelError.ErrorInfo);
                Can_43_LLCE_ErrorNotificationCallback(&CanError);
                #endif
            }
            else if (LLCE_CAN_NOTIF_PLATFORMERROR == Can_SharedMemory.Can_NotificationTable.Can_aNotif0_Table[pxConfig->u8ActiveHif][u8NotifIdx].eNotifId)
            {
                #if (CAN_43_LLCE_ERROR_NOTIF_ENABLE == STD_ON)
                /* Report a platform error */
                CanError.u8CanIfCtrlId = CAN_43_LLCE_NULL_OFFSET;
                CanError.eNotifId = Can_SharedMemory.Can_NotificationTable.Can_aNotif0_Table[pxConfig->u8ActiveHif][u8NotifIdx].eNotifId;
                CanError.ErrorInfo = &(Can_SharedMemory.Can_NotificationTable.Can_aNotif0_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.PlatformError);
                Can_43_LLCE_ErrorNotificationCallback(&CanError);
                #endif
            }
            else
            {
                /* Unknown error. */
            }
            
        }
        
    }

    /* Clear the interrupt status flag. */
    Reg_Write32( LLCE_FIFO_STATUS1(LLCE_NOTIF_FIFO0_BASE_ADDRESS(pxConfig->u8ActiveHif)), LLCE_FIFO_FNEMTY_U32); 
}

#if (CAN_43_LLCE_BUSOFFPOLL_SUPPORTED == STD_ON)
/*================================================================================================*/
/**
* @brief          This routine accesses the notification interface configured in polling mode.
* @details        This routine accesses the notification interface configured in polling mode using indexes popped from NOTIF FIFO
*                 to retrieve the bus-off events from notification table filled up by Llce firmware.
* @pre            
* @post           CanIf is notified about the bus-off events reported by the Llce firmware.
* @implements     Can_Isr_X_Activity
*/
void Can_Llce_ProcessBusOffNotification(void)
{   
    uint8 u8NotifIdx = 0U;
    uint8 u8HwCtrl = 0U;
    uint16 u16SafetyLoopEscapeCnt = LLCE_CAN_CONFIG_NOTIF_TABLE_SIZE;
    Llce_Fw_ReturnType eErrorCode;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    while ( (LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_NOTIF_FIFO1_BASE_ADDRESS(pxConfig->u8ActiveHif))) & (uint32)(LLCE_FIFO_FEMTYD_U32))) && \
           (u16SafetyLoopEscapeCnt > 0U))
    {
        u16SafetyLoopEscapeCnt--;
        u8NotifIdx = (uint8)Reg_Read32( LLCE_FIFO_POP0(LLCE_NOTIF_FIFO1_BASE_ADDRESS(pxConfig->u8ActiveHif)));

        /* Get error code */
        eErrorCode = Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.ChannelError.ErrorInfo.eErrorCode;

        if ((LLCE_CAN_NOTIF_CHANNELERROR == Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].eNotifId) && \
                (LLCE_ERROR_BUSOFF == eErrorCode))
        {
            /* Get hw controller (BCAN instance) which raised the bus-off notification. */
            u8HwCtrl = Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.ChannelError.u8HwCtrl;

            /* Make sure the controller is configured to get bus-off events in polling mode. */
            if (LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 != (LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 & (uint32)(pxConfig->aHwControllerDescriptors[u8HwCtrl].u32DrvControllerOptions)))
            {
                #if (CAN_43_LLCE_BUSOFF_RECOVERY_ENABLED == STD_ON)
                    /* LLCE issues bus-off notification, but does not freeze the controller. */
                    Can_43_LLCE_ControllerBusOffCallback(pxConfig->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId);
                #else
                    /* LLCE issues bus-off notification after controller freezes. AUTOSAR required behavior */
                    Can_Llce_ControllerBusOff(u8HwCtrl);
                #endif
            }
        }
        #if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
        else
        {
            if ( LLCE_SWFIFO_FULL != Can_Llce_xNotifSwFifo.eFifoStatus )
            {
                (void)Llce_SwFifo_Push((const void*)&(Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx]) , &Can_Llce_xNotifSwFifo);
            }
        }
        #endif

    }
}
#endif /* (CAN_43_LLCE_BUSOFFPOLL_SUPPORTED == STD_ON) */

#if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
/**
* @brief          This routine accesses the notification interface configured in polling mode.
* @details        This routine accesses the notification interface configured in polling mode using indexes popped from NOTIF FIFO
*                 to retrieve the event information from notification table filled up by Llce firmware.
* @pre            
* @post           CanIf is notified about the bus-off events reported by the Llce firmware. User-defined callback for errors is called if defined.
* @implements     Can_Isr_X_Activity
*/
void Can_Llce_ProcessErrorNotification(void)
{   
    uint8 u8NotifIdx = 0U;
    uint8 u8HwCtrl = 0U;

    uint16 u16SafetyLoopEscapeCnt;

    Llce_Can_NotificationType genericError;
    CanErrorNotificationType CanError;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Report the possible buffered errors */
    while (LLCE_SWFIFO_EMPTY != Can_Llce_xNotifSwFifo.eFifoStatus)
    {
        (void)Llce_SwFifo_Pop(&genericError , &Can_Llce_xNotifSwFifo);

        if (LLCE_CAN_NOTIF_CHANNELERROR == genericError.eNotifId)
        {
            #if (CAN_43_LLCE_ERROR_NOTIF_ENABLE == STD_ON)
            /* Get hw controller id */
            u8HwCtrl = genericError.NotifList.ChannelError.u8HwCtrl;
            /* Report a channel error */
            CanError.u8CanIfCtrlId = pxConfig->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId;
            CanError.eNotifId = genericError.eNotifId;
            CanError.ErrorInfo = &(genericError.NotifList.ChannelError.ErrorInfo);
            Can_43_LLCE_ErrorNotificationCallback(&CanError);
            #endif
        }
        else
        {
            #if (CAN_43_LLCE_ERROR_NOTIF_ENABLE == STD_ON)
            /* Report a platform error */
            CanError.u8CanIfCtrlId = CAN_43_LLCE_NULL_OFFSET;
            CanError.eNotifId = genericError.eNotifId;
            CanError.ErrorInfo = &(genericError.NotifList.PlatformError);
            Can_43_LLCE_ErrorNotificationCallback(&CanError);
            #endif
        }
            
    }

    u16SafetyLoopEscapeCnt = LLCE_CAN_CONFIG_NOTIF_TABLE_SIZE;

    while ( (LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_NOTIF_FIFO1_BASE_ADDRESS(pxConfig->u8ActiveHif))) & (uint32)(LLCE_FIFO_FEMTYD_U32))) && \
            (u16SafetyLoopEscapeCnt > 0U) )
    {
        u16SafetyLoopEscapeCnt--;
        u8NotifIdx = (uint8)Reg_Read32( LLCE_FIFO_POP0(LLCE_NOTIF_FIFO1_BASE_ADDRESS(pxConfig->u8ActiveHif)));

        /* Report busoff through the standard CanIf callback.  */
        if (LLCE_CAN_NOTIF_CHANNELERROR == Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].eNotifId)
        {   
            /* Get hw controller (BCAN instance) which raised the bus-off notification. */
            u8HwCtrl = Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.ChannelError.u8HwCtrl;
            if (LLCE_ERROR_BUSOFF == Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.ChannelError.ErrorInfo.eErrorCode)
            {
                /* Make sure the controller is configured to get bus-off events in polling mode. */
                if (LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 != (LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 & (uint32)(pxConfig->aHwControllerDescriptors[u8HwCtrl].u32DrvControllerOptions)))
                {
                    #if (CAN_43_LLCE_BUSOFF_RECOVERY_ENABLED == STD_ON)
                        /* LLCE issues bus-off notification, but does not freeze the controller. */
                        Can_43_LLCE_ControllerBusOffCallback(pxConfig->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId);
                    #else
                        /* LLCE issues bus-off notification after controller freezes. AUTOSAR required behavior */
                        Can_Llce_ControllerBusOff(u8HwCtrl);
                    #endif
                }
            }
            else /* Report the rest of possible errors through the user-defined callback */
            {
                #if (CAN_43_LLCE_ERROR_NOTIF_ENABLE == STD_ON)
                /* Report a channel error */
                CanError.u8CanIfCtrlId = pxConfig->aHwControllerDescriptors[u8HwCtrl].u8CanIfCtrlId;
                CanError.eNotifId = Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].eNotifId;
                CanError.ErrorInfo = &(Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.ChannelError.ErrorInfo);
                Can_43_LLCE_ErrorNotificationCallback(&CanError);
                #endif
            }
        }
        else
        {
            #if (CAN_43_LLCE_ERROR_NOTIF_ENABLE == STD_ON)
            /* Report a platform error */
            CanError.u8CanIfCtrlId = CAN_43_LLCE_NULL_OFFSET;
            CanError.eNotifId = Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].eNotifId;
            CanError.ErrorInfo = &(Can_SharedMemory.Can_NotificationTable.Can_aNotif1_Table[pxConfig->u8ActiveHif][u8NotifIdx].NotifList.PlatformError);
            Can_43_LLCE_ErrorNotificationCallback(&CanError);
            #endif
        }
    }
}
#endif /* (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON) */

#if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)
static void Can_Llce_ProcessTxPollingClass(uint8 u8PollClassIdx)
{
    uint8 u8ControllerId = 0U;
    uint8 u8HwCtrl = 0U;

    uint16 u16HohIndex = 0U;

    uint16 u16AckEntry = 0U;
    uint16 u16SafetyLoopEscapeCnt;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    u16SafetyLoopEscapeCnt = pxConfig->pPlatfInitConfig->au16MaxPollTxAckCount[u8PollClassIdx];
    /* Process all entries from the TXACK FIFO corresponding to a polling class. Their order number starts with 16 (LLCE_CAN_CONFIG_MAXCTRL_COUNT) */
    while ((LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_TXACK_BASE_ADDRESS((LLCE_CAN_CONFIG_MAXCTRL_COUNT + u8PollClassIdx)))) & (uint32)(LLCE_FIFO_FEMTYD_U32))) && \
           (u16SafetyLoopEscapeCnt > 0U) )
    {
        u16SafetyLoopEscapeCnt--;
        /* Read the index into the circular buffer containing the ack info.*/
        u16AckEntry = (uint16)(Reg_Read32( LLCE_FIFO_POP0(LLCE_FIFO_TXACK_BASE_ADDRESS((LLCE_CAN_CONFIG_MAXCTRL_COUNT + u8PollClassIdx)))) & LLCE_CAN_CONFIG_FIFO_FIXED_MASK_U32);
        
        u16HohIndex = Can_SharedMemory.Can_Tx_aAckInfo[u16AckEntry].u16FrameTag1;
        
        Can_Hth_FreeTxObject(u16HohIndex, 1U);

        u8ControllerId = pxConfig->aHohList[u16HohIndex].u8ControllerId;
        
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
        if(Can_43_LLCE_GetCoreID() == pxConfig->aControllerDescriptors[u8ControllerId].u32CoreId)
        {
#endif
            /* Get the hardware offset for this controller. */
            u8HwCtrl = pxConfig->aControllerDescriptors[u8ControllerId].u8HwCtrl;

            /* Filter outdated Acks gathered as a consequence of bus-off event or STOP command. */
            if (CAN_CS_STARTED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState)
            {
                /*
                (CAN108) The function Can_43_LLCE_MainFunction_Write shall perform the polling of TX indications when CanTxProcessing is set to POLLING or Mixed.
                In case of MIXED processing only the hardware objects for which CanHardwareObjectUsesPolling is set to TRUE shall be polled
                */
                if (LLCE_CAN_REFERENCE_NOT_USED != pxConfig->aHohList[u16HohIndex].u8CanMainFuncRWPeriodRef)
                {
                    /*
                    (CAN058) The Can module interacts among other modules (eg. Diagnostic Event Manager (DEM), Development Error Tracer (DET)) with the CanIf module in a direct way.
                            The driver only sees the CanIf module as origin and destination.
                    */
                    Can_43_LLCE_TxConfirmation( Can_SharedMemory.Can_Tx_aAckInfo[u16AckEntry].u16FrameTag2 );
                }
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            }
#endif
        }
    }
}
#endif /* (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON) */



static void Can_Llce_ProcessRxMb(const uint16 u16RxMbDescIdx)
{
    /* Number of data bytes. */
    uint8      u8MbDataLength = 0U;
    /* Variables for storing the CanID. */
    Can_IdType u32MbMessageId = 0U;
    /* Variable for storing the ConfigReg of the MB. */
    uint32     u32MbConfig = 0U;

    uint16  u16FilterId = 0U;

    #if (RXLUT2_ENABLE == STD_ON)
        uint16 u16AuxSearchResult = 0U;
    #endif

    uint32 u32Timestamp = 0U;

    uint32 u32Word1 = 0U;

    /* Pointer to the received frame payload. */
    uint8 * u8FramePayload = NULL_PTR;

    Llce_Can_GetMbData(&Can_SharedMemory, u16RxMbDescIdx, &u32MbConfig /*u32Word0*/, &u32Word1, &u8FramePayload, &u32Timestamp);

    /* Read the precalculated payload length; this is encoded in word1 of the MB */
    u8MbDataLength = (uint8)(u32Word1 >> LLCE_CAN_MB_PRECALC_LEN_SHIFT_U32);

    /* Get the ID of the message. */
    if(LLCE_CAN_MB_IDE_U32 == (u32MbConfig & LLCE_CAN_MB_IDE_U32))
    {
        /* For extended IDs the most significant bit must be set - according to Can_IdType requirement - chapter 8.2.3 of SWS CAN.*/
        u32MbMessageId = (Can_IdType)((u32MbConfig & LLCE_CAN_MB_ID_MASK_U32) | CAN_LPDU_IDE_U32 );
    }
    else
    {
        u32MbMessageId = (Can_IdType)((u32MbConfig & LLCE_CAN_MB_ID_MASK_U32) >> LLCE_CAN_MB_IDSTD_SHIFT_U32);
    }

    /* For FD the second most significant bit must be set - according to Can_IdType requirement - chapter 8.2.3 of SWS CAN.*/

   if(LLCE_CAN_MB_FDF_U32 == (u32Word1 & LLCE_CAN_MB_FDF_U32))
   {
        u32MbMessageId |= CAN_LPDU_FD_U32;
   }

    u16FilterId = Can_SharedMemory.Can_Rx_aMbDesc[u16RxMbDescIdx].u16FilterId;
    #if (RXLUT2_ENABLE == STD_ON)
        u16AuxSearchResult = Can_SharedMemory.Can_Rx_aMbDesc[u16RxMbDescIdx].u16AuxSearchResult;
    #endif

#if (CAN_43_LLCE_LPDU_NOTIFICATION_ENABLE == STD_ON)
     /*[CAN444] If the L-PDU call out returns false, the L-PDU shall not be processed any further. */
#if (CAN_43_LLCE_LPDU_CALLOUT_EXTENSION == STD_ON)
    if (TRUE == Can_43_LLCE_LPduReceiveCalloutFunction(u16FilterId, u32MbMessageId, u8MbDataLength, u8FramePayload))
#else
    if (TRUE == Can_43_LLCE_LPduReceiveCalloutFunction((uint8)u16FilterId, u32MbMessageId, u8MbDataLength, u8FramePayload))
#endif
    {
#endif
  #if (CAN_43_LLCE_CUSTOM_RX_CALLBACK_USED == STD_ON)
        if (TRUE == Can_Llce_CheckCustomCallback(u16FilterId, u32MbMessageId, u8MbDataLength, u8FramePayload, u16RxMbDescIdx))
        {
  #endif
            Can_43_LLCE_RxIndication(u32MbMessageId, u16FilterId, u8FramePayload, u8MbDataLength);
            #if (RXLUT2_ENABLE == STD_ON)
                Can_43_LLCE_CanAuxFilterCallback(u16FilterId, u16AuxSearchResult);
            #endif
            #if (CAN_43_LLCE_RX_TIMESTAMP == STD_ON)
            Can_43_LLCE_RxTimestampNotification(u16FilterId, u32Timestamp);
            #else
            (void) u32Timestamp; /* Timestamp notification is disabled */
            #endif

  #if (CAN_43_LLCE_CUSTOM_RX_CALLBACK_USED == STD_ON)
        }
  #endif
#if (CAN_43_LLCE_LPDU_NOTIFICATION_ENABLE == STD_ON)
    }
#endif

}

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer from ISR when Interrupt mode selected.
* @details        Processes Rx interrupt flags.
                  This routine is called by:
                    - Can_43_LLCE_IPW_ProcessRx() from Can_43_LLCE.c file
                    - Can_IsrFC##FC##_UNI() / Can_IsrFC##FC##_##Name() from Can_Irq.c file
*
* @param[in]      u8RxInterface Fifo Interface [0-15] which generated interrupt for RX event.
*
* @pre            MB is configured for Rx.
* @post           Inform CanIf in case a data frame was received.
*
*
*/
void Can_Llce_ProcessRx(const uint8 u8RxInterface)
{
    uint8 u8ControllerId = 0U;
    uint8 u8HwCtrl = 0U;

    /* Index to the full receive message buffer */
    uint16 u16RxMbDescIdx = 0U;
    uint16 u16HohIndex = 0U;
    uint16 u16SafetyLoopEscapeCnt = 0U;
    uint32 u32FifoStatus = 0U;
    uint32 u32IER = Reg_Read32(LLCE_FIFO_IER(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8RxInterface)));
    uint32 u32Status = Reg_Read32(LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8RxInterface)));
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    /* Check for spurious interrupt and for initialized driver. */
    if ( (CAN_43_LLCE_READY == Can_43_LLCE_eDriverStatus[u32CoreId]) &&
            (LLCE_FIFO_FNEMTY_U32 == (u32IER & LLCE_FIFO_FNEMTY_U32)) && \
            (LLCE_FIFO_FNEMTY_U32 == (u32Status & LLCE_FIFO_FNEMTY_U32)) )
    {      
        u32FifoStatus = (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif))));

        u16SafetyLoopEscapeCnt = pxConfig->pPlatfInitConfig->au16MaxIntMbCount[u8RxInterface];

        /* Add the behavior for the else branch when one of FIFOs are empty of full.*/
        /*Check if there is available any pointer to a full rx message buffer*/
        while (( LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8RxInterface))) & (uint32)(LLCE_FIFO_FEMTYD_U32))) && \
                ( LLCE_FIFO_FFULLD_U32 != (u32FifoStatus & (uint32)(LLCE_FIFO_FFULLD_U32)) ) && \
                (u16SafetyLoopEscapeCnt > 0U ))
        {
            u16SafetyLoopEscapeCnt--;
            /* Read data from the fifo. */
            u16RxMbDescIdx = (uint16)Reg_Read32( LLCE_FIFO_POP0(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8RxInterface)));

            u16HohIndex = Can_SharedMemory.Can_Rx_aMbDesc[u16RxMbDescIdx].u16FilterId;

            u8ControllerId = pxConfig->aHohList[u16HohIndex].u8ControllerId;

            /* Get the hardware offset for this controller. */
            u8HwCtrl = pxConfig->aControllerDescriptors[u8ControllerId].u8HwCtrl;
             
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            if(Can_43_LLCE_GetCoreID() == pxConfig->aControllerDescriptors[u8ControllerId].u32CoreId)
            {
#endif
                if ( CAN_CS_STARTED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState ) 
                {   
                    /* Check if corresponding controller is started and the hoh is configured for reporting through interrupt mode. */
                    if (LLCE_CAN_REFERENCE_NOT_USED == pxConfig->aHohList[u16HohIndex].u8CanMainFuncRWPeriodRef)
                    {
                        Can_Llce_ProcessRxMb(u16RxMbDescIdx);
                    }
                }

                /* Write address of RX message buffer back to the LLCE */
                Reg_Write32( LLCE_FIFO_PUSH0(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif)), (uint32)u16RxMbDescIdx);
                u32FifoStatus = (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif))));
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            }
#endif
        }
        
    }

    /* Clear the interrupt status flag. */
    Reg_Write32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8RxInterface)), LLCE_FIFO_FNEMTY_U32); 

}

#if (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON)
    static void Can_Llce_ProcessRxPollingClass(uint8 u8PollClassIdx)
    {
        uint8 u8ControllerId = 0U;
        uint8 u8HwCtrl = 0U;

        uint16 u16RxMbDescIdx = 0U;

        uint16 u16HohIndex = 0U;

        uint16 u16SafetyLoopEscapeCnt;
        /* Timeout counter. */
        uint32 u32timeStart = 0U;
        uint32 u32timeElapsed = 0U;
        uint32 u32TicksDelayDuration = 0U;

        const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

        u16SafetyLoopEscapeCnt = pxConfig->pPlatfInitConfig->au16MaxPollMbCount[u8PollClassIdx];

        /* Process all entries from the RxOut FIFO corresponding to a polling class. Their order number starts with 16 (LLCE_CAN_CONFIG_MAXCTRL_COUNT) */
        while ((LLCE_FIFO_FEMTYD_U32 != (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS((LLCE_CAN_CONFIG_MAXCTRL_COUNT + u8PollClassIdx)))) & (uint32)(LLCE_FIFO_FEMTYD_U32))) && \
               (u16SafetyLoopEscapeCnt > 0U ) )
        {
            u16SafetyLoopEscapeCnt--;
            /* Read data from the fifo. */
            u16RxMbDescIdx = (uint16)Reg_Read32( LLCE_FIFO_POP0(LLCE_FIFO_RXOUT_BASE_ADDRESS((LLCE_CAN_CONFIG_MAXCTRL_COUNT + u8PollClassIdx))));
            u16HohIndex = Can_SharedMemory.Can_Rx_aMbDesc[u16RxMbDescIdx].u16FilterId;

            u8ControllerId = pxConfig->aHohList[u16HohIndex].u8ControllerId;
            
            /* Get the hardware offset for this controller. */
            u8HwCtrl = pxConfig->aControllerDescriptors[u8ControllerId].u8HwCtrl;

#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            if(Can_43_LLCE_GetCoreID() == pxConfig->aControllerDescriptors[u8ControllerId].u32CoreId)
            {
#endif
                /* Filter outdated frames gathered as a consequence of bus-off event or STOP command. */
                if (CAN_CS_STARTED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState)
                {
                    /*
                    (CAN108) The function Can_43_LLCE_MainFunction_Read shall perform the polling of RX indications when CanRxProcessing is set to POLLING or Mixed.
                    In case of MIXED processing only the hardware objects for which CanHardwareObjectUsesPolling is set to TRUE shall be polled
                    */
                    if (LLCE_CAN_REFERENCE_NOT_USED != pxConfig->aHohList[u16HohIndex].u8CanMainFuncRWPeriodRef)
                    {
                        Can_Llce_ProcessRxMb(u16RxMbDescIdx);
                    }
                }

                u32timeStart = OsIf_GetCounter(CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
                u32TicksDelayDuration = OsIf_MicrosToTicks(CAN_43_LLCE_TIMEOUT_DURATION, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
                u32timeElapsed = 0U;

                /* Wait for LLCE to consume the tokens before next token is pushed */
                while ( (0U == (uint32)(Reg_Read32( LLCE_FIFO_STATUS1(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif))) & (uint32)(LLCE_FIFO_FEMTYD_U32)) ) && (u32timeElapsed < u32TicksDelayDuration))
                {
                    u32timeElapsed += OsIf_GetElapsed(&u32timeStart, CAN_43_LLCE_SERVICE_TIMEOUT_TYPE);
                }

                /* Write address of RX message buffer back to the LLCE */
                Reg_Write32( LLCE_FIFO_PUSH0(LLCE_FIFO_RXIN_BASE_ADDRESS(pxConfig->u8ActiveHif)), (uint32)u16RxMbDescIdx);
#if CAN_43_LLCE_MULTICORE_ENABLED == (STD_ON)
            }
#endif
        }
    }
#endif

#if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)
    #ifdef CAN_43_LLCE_MAINFUNCTION_MULTIPLE_WRITE
       #if (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_WRITE == STD_OFF)
            /*================================================================================================*/
            /**
            * @brief          Service to perform the polling of TX confirmation and TX cancellation confirmation
            * @details        This routine is called by:
            *               - Can_43_LLCE_MainFunction_Write() from Can_43_LLCE.c file.
            *
            * @pre            The controller must be configured for transmit in polling mode and at least one MB is configured for Tx.
            * @post           Process the transmission data in case of availability.
            *
            *
            */
            void Can_Llce_MainFunctionWrite(void)
            {   
                uint8  u8PollClassIdx;

                const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

                if ( NULL_PTR != pxConfig )
                {   
                    for ( u8PollClassIdx = 0U; u8PollClassIdx < LLCE_CAN_MAX_POLLING_CLASSES; u8PollClassIdx++)
                    {   
                        /* Check only the polling classes which have been configured */
                        if (0U != pxConfig->pPlatfInitConfig->au16MaxPollTxAckCount[u8PollClassIdx])
                        {
                            Can_Llce_ProcessTxPollingClass(u8PollClassIdx);
                        }
                    }
                }
            }
        #else
            /*================================================================================================*/
            /**
            * @brief          Function called at fixed cyclic time, with polling of all the MessageBuffer referenced to writepoll
            * @details        Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
            *                 This routine is called by:
            *                 - CanIf or an upper layer according to Autosar requirements.
            *
            * @api
            *
            * @pre            Driver must be initialized.
            * @post           Send the data from that MB that is configured for Tx.
            */
            void Can_Llce_MainFunctionMultipleWritePoll(uint8 writepoll)
            {

                const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

                if ( NULL_PTR != pxConfig )
                {   
                    Can_Llce_ProcessTxPollingClass(writepoll);
                }
            }
            #endif /* End CAN_43_LLCE_MAINFUNCTION_MULTIPLE_WRITE */
    #endif /*ifdef (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_WRITE)*/
#endif /* (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON) */



#if (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON)
    #ifdef CAN_43_LLCE_MAINFUNCTION_MULTIPLE_READ
        #if (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_READ == STD_OFF)
            /*================================================================================================*/
            /**
            * @brief          Service to perform the polling of RX indications.
            * @details        Processes Rx interrupt flags.
            *                 This routine is called by:
            *                    - Can_43_LLCE_MainFunction_Read() from Can_43_LLCE.c file.
            *
            * @pre            The controller must be configured for receive in polling mode and at least one MB is configured for Rx.
            * @post           Process the reception data in case of availability.
            *
            *
            */
            void Can_Llce_MainFunctionRead(void)
            {   
                uint8  u8PollClassIdx;

                const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

                if ( NULL_PTR != pxConfig )
                {   
                    for ( u8PollClassIdx = 0U; u8PollClassIdx < LLCE_CAN_MAX_POLLING_CLASSES; u8PollClassIdx++)
                    {   
                        /* Check only the polling classes which have been configured */
                        if (0U != pxConfig->pPlatfInitConfig->au16MaxPollMbCount[u8PollClassIdx])
                        {
                            Can_Llce_ProcessRxPollingClass(u8PollClassIdx);
                        }
                    }
                }
            }
        #else
            /*================================================================================================*/
            /**
            * @brief          Function called at fixed cyclic time, with polling of all the MessageBuffer referenced to .readpoll
            * @details        Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
            *                 This routine is called by:
            *                 - CanIf or an upper layer according to Autosar requirements.
            *
            * @api
            * @pre            Driver must be initialized.
            * @post           Receive the data from that MB that is configured for Rx.
            *
            */
            void Can_Llce_MainFunctionMultipleReadPoll(uint8 readpoll)
            {
                const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();


                if ( NULL_PTR != pxConfig )
                {   
                    Can_Llce_ProcessRxPollingClass(readpoll);
                }
            }
        #endif  /* (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_READ == STD_OFF) */   
    #endif /* ifdef (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_READ)*/
#endif /* (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON) */


/*================================================================================================*/
/**
* @brief          Service to perform the polling of CAN status register flags to detect transition of CAN Controller state
* @details        The function Can_43_LLCE_MainFunction_Mode shall implement the polling of CAN status register flags to detect transition of CAN Controller state
*
* @param[in]      u8HwCtrl    CAN controller for which the polling shall be done.
*
* @pre
* @post
*
*/

void Can_Llce_MainFunctionMode(uint8 u8HwCtrl)
{
    /* Variable for updated mode */
    Can_ControllerStateType crtControllerMode = CAN_CS_UNINIT;
    
    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
    /* Update mode indicator */
    (void)Can_Llce_GetControllerMode(u8HwCtrl, &crtControllerMode);

    /* Check for state changes */
    if(crtControllerMode != Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState) 
    {
        switch(crtControllerMode)
        {
            case CAN_CS_UNINIT:
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState = CAN_CS_UNINIT;
                Can_43_LLCE_ControllerModeIndication(u8HwCtrl, CAN_CS_UNINIT);
                break;

            case CAN_CS_SLEEP:
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState = CAN_CS_SLEEP;
                Can_43_LLCE_ControllerModeIndication(u8HwCtrl, CAN_CS_SLEEP);
                break;

            case CAN_CS_STARTED:
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState = CAN_CS_STARTED;
                Can_43_LLCE_ControllerModeIndication(u8HwCtrl, CAN_CS_STARTED);
                /*
                (CAN425)   Enabling of CAN interrupts shall not be executed, when CAN interrupts have been disabled by function CAN_DisableControllerInterrupts.
                */
                if ( CAN_INTERRUPT_ENABLED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eInterruptMode )
                {
                    Can_Llce_EnableInterrupts(u8HwCtrl);
                }
                break;

            case CAN_CS_STOPPED:
                /* Check if interrupts are enabled */
                if ( CAN_INTERRUPT_ENABLED == Can_43_LLCE_ControllerStatuses[u8HwCtrl].eInterruptMode )
                {
                    Can_Llce_DisableInterrupts(u8HwCtrl);
                }
                Can_43_LLCE_ControllerStatuses[u8HwCtrl].eCachedControllerState = CAN_CS_STOPPED;
                Can_43_LLCE_ControllerModeIndication(u8HwCtrl, CAN_CS_STOPPED);
                break;

            default:
                /* Switch must handle all states. No action, just appease MISRA */
                break;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_03();
}

/*================================================================================================*/
/**
* @brief          Service disables all interrupts for the given CAN controller.
* @details        This routine is called by:
*                 - Can_43_LLCE_DisableControllerInterrupts() from Can_43_LLCE.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done.
*
* @pre            Disable interrupts must be called prior to enable interrupts.
* @post           Clear all flags/bits that are needed for disabling the interrupts.
*
*
*/
void Can_Llce_DisableControllerInterrupts(uint8 u8HwCtrl)
{
    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_00();
    /*
       (CAN202) When Can_43_LLCE_DisableControllerInterrupts has been called several times, Can_43_LLCE_EnableControllerInterrupts must be called
                as many times before the interrupts are re-enabled.
    */
    Can_43_LLCE_ControllerStatuses[u8HwCtrl].u8IntDisableLevel++;

    /*
       (CAN049) The function Can_43_LLCE_DisableControllerInterrupts shall disable all interrupts for this CAN controller only at the first call of this function.
    */
    if ( (uint8)1 == Can_43_LLCE_ControllerStatuses[u8HwCtrl].u8IntDisableLevel )
    {
        /* Switch to disabled mode. */
        Can_43_LLCE_ControllerStatuses[u8HwCtrl].eInterruptMode = CAN_INTERRUPT_DISABLED;
        Can_Llce_DisableInterrupts(u8HwCtrl);
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_00();
}


/*================================================================================================*/
/**
* @brief          Service enables all interrupts that shall be enabled according the current software status.
* @details        This routine is called by:
*                  - Can_43_LLCE_EnableControllerInterrupts() from Can_43_LLCE.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done.
*
* @pre            Can be executed only if disable interrupts was called before.
* @post           Enable all interrupts that must be enabled according the current sw status.
*
*
*/
void Can_Llce_EnableControllerInterrupts(uint8 u8HwCtrl )
{
    /* Variable that tells if disable ints was called at least once before. */
    uint8   u8DisCalledBefore = 0U;

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_01();
    /*
       (CAN202) When Can_43_LLCE_DisableControllerInterrupts has been called several times, Can_43_LLCE_EnableControllerInterrupts must be called as many
               times before the interrupts are re-enabled.
    */

    if ( Can_43_LLCE_ControllerStatuses[u8HwCtrl].u8IntDisableLevel > (uint8)0 )
    {
        /* When u8IntDisableLevel is greater than 0  means Can_43_LLCE_DisableControllerInterrupts was called at least once before this call of current function. */

        /* Decrement the nesting level. */
        Can_43_LLCE_ControllerStatuses[u8HwCtrl].u8IntDisableLevel--;

        u8DisCalledBefore = (uint8)0x1U;
    }

    /* Can_43_LLCE_DisableControllerInterrupts and Can_43_LLCE_EnableControllerInterrupts do not modify the software flags. */

    /*
       (CAN208) The function Can_43_LLCE_EnableControllerInterrupts shall perform no action when Can_43_LLCE_DisableControllerInterrupts has not been called before.
    */
    if ( ((uint8)0 == Can_43_LLCE_ControllerStatuses[u8HwCtrl].u8IntDisableLevel) && ((uint8)0x1U == u8DisCalledBefore) )
    {

        /* Switch to enabled mode. */
        Can_43_LLCE_ControllerStatuses[u8HwCtrl].eInterruptMode = CAN_INTERRUPT_ENABLED;
        Can_Llce_EnableInterrupts(u8HwCtrl);
    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_01();
}


Std_ReturnType Can_Llce_GetControllerErrorState(uint8 u8HwCtrl, Can_ErrorStateType * ErrorStatePtr)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue;
    /* The value Error State of Controller */
    uint32  u32ErrorState = 0U;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_GETSTATUS;

        /* Send the command prepared above to the LLCE in order to be executed */
        eCommandReturnValue = Can_Llce_ExecuteIfCommand(u8HwCtrl);
        /* Read the BCAN error state */
        u32ErrorState =  Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.GetStatus.u32SR & LLCE_BCAN_SR_FLTCONF_MASK_U32;

        if (LLCE_FW_SUCCESS == eCommandReturnValue)
        {            
            switch(u32ErrorState)
            {
                case (LLCE_BCAN_SR_FLTCONF_ERROR_ACTIVE_U32):
                    *ErrorStatePtr = CAN_ERRORSTATE_ACTIVE;
                    eReturnValue = E_OK;
                    break;
                case (LLCE_BCAN_SR_FLTCONF_ERROR_PASSIVE_U32):
                    *ErrorStatePtr = CAN_ERRORSTATE_PASSIVE;
                    eReturnValue = E_OK;
                    break;
                case (LLCE_BCAN_SR_FLTCONF_BUSOFF10_U32):
                    *ErrorStatePtr = CAN_ERRORSTATE_BUSOFF;
                    eReturnValue = E_OK;
                    break;
                case (LLCE_BCAN_SR_FLTCONF_BUSOFF11_U32):
                    *ErrorStatePtr = CAN_ERRORSTATE_BUSOFF;
                    eReturnValue = E_OK;
                    break;
                default:
                    eReturnValue = E_NOT_OK;
                    break;
            }
        }
    }
    
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    
    return eReturnValue;
}

/**
*   @brief      Get Controller Rx Error Counter
*/
Std_ReturnType Can_Llce_GetControllerRxErrorCounter(uint8 u8HwCtrl, uint8 * RxErrorCounterPtr)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_GETSTATUS;

         /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand(u8HwCtrl) )
        {
            /* Read the BCAN Rx Error Counter */
            *RxErrorCounterPtr = (uint8)((Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.GetStatus.u32ECR & LLCE_BCAN_ECR_REC_MASK_U32) >> LLCE_BCAN_ECR_REC_SHIFT_U8);
            eReturnValue = E_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

/**
*   @brief      Get Controller Tx Error Counter
*/
Std_ReturnType Can_Llce_GetControllerTxErrorCounter(uint8 u8HwCtrl, uint8 * TxErrorCounterPtr)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_GETSTATUS;

         /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand(u8HwCtrl) )
        {
            /* Read the BCAN Tx Error Counter */
            *TxErrorCounterPtr = (uint8)((Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.GetStatus.u32ECR & LLCE_BCAN_ECR_TEC_MASK_U32) >> LLCE_BCAN_ECR_TEC_SHIFT_U8);
            eReturnValue = E_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

Std_ReturnType Can_Llce_GetControllerStatus(uint8 u8HwCtrl, Llce_Can_GetStatusCmdType * StatusPtr)
{
    /* Variable for return status. */
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_GETSTATUS;

         /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand(u8HwCtrl) )
        {
            *StatusPtr = Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.GetStatus;
            eReturnValue = E_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}

Std_ReturnType Can_Llce_GetFwVersion(const uint8 ** pVersionString, uint8 * pStringLength)
{
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue;

    uint8 u8Idx = 0;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    if(0U == u8VersionLength)
    {
        SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
        /* Read version from LLCE */
        if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
        {
            /* Configure the command id. */
            Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_GETFWVERSION;

            /* Send the command prepared above to the LLCE in order to be executed */
            eCommandReturnValue = Can_Llce_ExecuteIfCommand(pxConfig->u8DefaultController);

            u8VersionLength = Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.GetFwVersion.stringLength;

            for(u8Idx = 0; u8Idx < u8VersionLength; u8Idx++)
            {
                au8VersionStringBuf[u8Idx] = Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.GetFwVersion.versionString[u8Idx];
            }

            if (LLCE_FW_SUCCESS == eCommandReturnValue)
            {
                eReturnValue = E_OK;
            }
        }
       
        SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    }
    else 
    {
        eReturnValue = E_OK;
    }
        
    *pVersionString = au8VersionStringBuf;
    *pStringLength = u8VersionLength;

    return eReturnValue;
   
}

Std_ReturnType Can_Llce_ExecuteCustomCommand(const void* const argument)
{
    Std_ReturnType  eReturnValue = (Std_ReturnType)E_NOT_OK;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_CUSTOM;
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.pCustomCmdArg= (uint32)argument;

         /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand(pxConfig->u8DefaultController) )
        {
            eReturnValue = E_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    
    return eReturnValue;
}


#if (CAN_43_LLCE_API_ENABLE_ABORT_MB == STD_ON)
/*================================================================================================*/
/**
* @brief          This service requests LLCE to abort lowest priority pending transmission
* @details        This service requests LLCE to abort lowest priority pending transmission
*                 belonging to a specific HTH. The MB will be released if the command succeeds.
*
* @param[in]      Hth - HW-transmit handler
*
* @return         Std_ReturnType
* @retval         E_OK MB has been aborted
* @retval         E_NOT_OK MB could not be aborted
*/
Std_ReturnType Can_Llce_AbortMb( Can_HwHandleType Hth)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    Llce_Fw_ReturnType eCommandReturnValue = LLCE_FW_NOTRUN;
    uint8 u8HwCtrl = 0U;
    uint8 u8CtrlId = 0U;
    uint8 u8AbortedFrameCnt = 0U;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    u8CtrlId = pxConfig->aHohList[Hth].u8ControllerId;

    /* Get the hardware offset for this controller. */
    u8HwCtrl = pxConfig->aControllerDescriptors[u8CtrlId].u8HwCtrl;

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_ABORT_MB;

        /* Configure the MB tag in order for the LLCE firmware to find the MB. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.AbortMb.u16FrameTag = Hth;

#if (CAN_43_LLCE_ABORT_ONLY_ONE_MB == STD_ON)
        /* Configure the MB tag in order for the LLCE firmware to find the MB. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.AbortMb.eAbortMbType = ABORT_ONLY_ONE_MB;
#else
        /* Configure the MB tag in order for the LLCE firmware to find the MB. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.AbortMb.eAbortMbType = ABORT_ALL_MB;
#endif 
         /* Send the command prepared above to LLCE in order to be executed */
        eCommandReturnValue =  Can_Llce_ExecuteIfCommand(u8HwCtrl);
        
        u8AbortedFrameCnt = Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].CmdList.AbortMb.u8AbortedFrameCnt;
    }
    
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    if (LLCE_FW_SUCCESS == eCommandReturnValue)
    {
        eReturnValue = E_OK;

        Can_Hth_FreeTxObject(Hth, u8AbortedFrameCnt);
    }

    return eReturnValue;
}
#endif


#if (CAN_43_LLCE_API_MANUAL_BUSOFF_RECOVERY == STD_ON)
/*================================================================================================*/
/**
* @brief          This service requests LLCE to recover the given controller from bus-off state.
* @details        This synchronous service requests bus-off recovery when the controller is configured
*                 in manual bus-off recovery mode. No outstanding TX or RX frames are discarded.
*
* @param[in]      u8HwCtrl - hw controller
*
* @return         Std_ReturnType
* @retval         E_OK command acknowledged by LLCE
* @retval         E_NOT_OK command not acknowledged by LLCE
*/
Std_ReturnType Can_Llce_ManualBusOffRecovery(uint8 u8HwCtrl)
{
    /* Variable for return status. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;

    const Can_43_LLCE_ConfigType* const pxConfig = Can_Llce_GetCurrentConfig();

    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();
    if((Std_ReturnType)E_OK == Can_Llce_CheckCommandAvailable())
    {
        /* Configure the command id. */
        Can_SharedMemory.aCanCmd[pxConfig->u8ActiveHif].eCmdId = LLCE_CAN_CMD_MANUAL_BUSOFF_RECOVERY;

         /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_FW_SUCCESS == Can_Llce_ExecuteIfCommand(u8HwCtrl) )
        {
            eReturnValue = E_OK;
        }
    }
    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_04();

    return eReturnValue;
}
#endif


#define CAN_43_LLCE_STOP_SEC_CODE
#include "Can_43_LLCE_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
