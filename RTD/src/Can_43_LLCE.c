/**
*   @internal
*   @file    Can_43_LLCE.c
*   @implements Can.c_Artifact
*   @version 1.0.11
*   @file    Can_43_LLCE.c
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details API implementation for CAN driver.
*
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


/*
Driver Limitations:
    1. The maximum number of Can_43_LLCE_DisableControllerInterrupts levels of nesting is 255.
    2. This file contains 2 types of functions: first are the Autosar APIs and then are some user defined functions.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Can_43_LLCE.c
*/
#include "Can_43_LLCE.h"
#include "Can_43_LLCE_IPW.h"
#include "CanIf_Can.h"
#include "CanIf.h"
#include "Std_Types.h"

#include "SchM_Can_43_LLCE.h"

#if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*  (CAN111) Can_43_LLCE.c shall check if the correct version of Can_43_LLCE.h is included.
            This shall be done by a preprocessor check of the version numbers CAN_43_LLCE_SW_MAJOR_VERSION, CAN_43_LLCE_SW_MINOR_VERSION and CAN_43_LLCE_SW_PATCH_VERSION.
*/
/**
* @file           Can_43_LLCE.c
*/
#define CAN_43_LLCE_VENDOR_ID_C                      43
#define CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C       4
#define CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_C       4
#define CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_C    0
#define CAN_SW_MAJOR_VERSION_C               1
#define CAN_SW_MINOR_VERSION_C               0
#define CAN_SW_PATCH_VERSION_C               11


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_C != CAN_43_LLCE_VENDOR_ID)
    #error "Can_43_LLCE.c and Can_43_LLCE.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C    != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_C    != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_C != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_43_LLCE.c and Can_43_LLCE.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_C != CAN_43_LLCE_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_C != CAN_43_LLCE_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_C != CAN_43_LLCE_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_43_LLCE.c and Can_43_LLCE.h are different"
#endif


/* Check if current file and CAN_IPW header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_C != CAN_IPW_VENDOR_ID_H)
    #error "Can_43_LLCE.c and Can_43_LLCE_IPW.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C    != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_C    != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_43_LLCE.c and Can_43_LLCE_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_C != CAN_IPW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_43_LLCE.c and Can_43_LLCE_IPW.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_43_LLCE.c and Det.h are different"
    #endif
  #endif
#endif

/* Check if current file and CANIF_CBK header file are of the same version */
#if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C != CANIF_CAN_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_C != CANIF_CAN_AR_RELEASE_MINOR_VERSION))
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
#if (STD_ON == CAN_43_LLCE_PRECOMPILE_SUPPORT)
#define CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

#define CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"
#endif /* (STD_ON == CAN_43_LLCE_PRECOMPILE_SUPPORT) */

#define CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

volatile uint16 Can_au16TransmitHwObjectCnt[CAN_43_LLCE_MAXHTH_CONFIGURED];

#define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

#define CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"


/**
* @brief          This variable holds the state of the driver.
* @details        This variable holds the state of the driver. After reset is UNINIT. The output of Can_43_LLCE_Init() function
*                 (only to first call) should set this variable into READY state.
*                  CAN_43_LLCE_UNINIT = The CAN controller is not initialized. All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
*                  The CAN Controller is not participating on the CAN bus.
*                  The Can module must only implement a variable for the module state, when the development error tracing is switched on.
*                  When the development error tracing is switched off, the Can module does not need to implement this 'state machine',
*                  because the state information is only needed to check if Can_43_LLCE_Init was called prior to any Can module function.
*
*/
Can_43_LLCE_StatusType Can_43_LLCE_eDriverStatus[CAN_43_LLCE_MAX_PARTITIONS];

/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by Can_43_LLCE_Init(). */
const Can_43_LLCE_ConfigType * Can_43_LLCE_pCurrentConfig[CAN_43_LLCE_MAX_PARTITIONS];

#define CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
static boolean Can_ValidateController(uint8 u8Controller, uint8 u8Sid);
#endif

static Std_ReturnType Can_43_LLCE_SendWriteCmd(Can_HwHandleType Hth, const Can_PduType * PduInfo);

#ifdef CAN_43_LLCE_SET_BAUDRATE_API
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
static Std_ReturnType Can_43_LLCE_SendSetBaudrateCmd(uint8 Controller, const uint16 BaudRateConfigID);
#endif
#endif

static void Can_43_LLCE_InitializeControllers(const uint32* u32CoreId);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_CODE
#include "Can_43_LLCE_MemMap.h"

static boolean Can_ValidateController(uint8 u8Controller, uint8 u8Sid)
{
    boolean bValid = TRUE;
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

#if (CAN_43_LLCE_DEV_ERROR_DETECT != STD_ON)
    /* Suppress warning */
    (void)u8Sid;
#endif

    /* Check if the driver was initialised */
    if (CAN_43_LLCE_UNINIT == Can_43_LLCE_eDriverStatus[u32CoreId] )
    {
        /*
        (CAN089) The Can module environment shall indicate development errors only in the return values of a function of the Can module when DET
                 is switched on and the function provides a return value. The returned value is E_NOT_OK.
        */
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /*
           (CAN198) If development error detection for the Can module is enabled: if the module is not yet initialized, the
                   function Can_43_LLCE_SetControllerMode shall raise development error CAN_43_LLCE_E_UNINIT and return E_NOT_OK.
        */

        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, u8Sid, (uint8)CAN_43_LLCE_E_UNINIT);
        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */

        bValid = FALSE;
    }
    else if ( (u8Controller >= CAN_43_LLCE_MAXCTRL_CONFIGURED) ||
             (CAN_43_LLCE_NULL_OFFSET == (Can_43_LLCE_pCurrentConfig[u32CoreId]->aControllerDescriptors[u8Controller].u8HwCtrl)))
        /* Controller ID must be within range and the selected Controller must be configured for use in the config tool. */
    {
        /*
           (CAN199) If development error detection for the Can module is enabled: if the parameter Controller is out of range,
                   the function Can_43_LLCE_SetControllerMode shall raise development error CAN_43_LLCE_E_PARAM_CONTROLLER and return E_NOT_OK.
        */
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, u8Sid, (uint8)CAN_43_LLCE_E_PARAM_CONTROLLER);
        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */

        bValid = FALSE;
    }
    #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
    else if(Can_43_LLCE_pCurrentConfig[u32CoreId]->aControllerDescriptors[u8Controller].u32CoreId != u32CoreId)
    {
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, u8Sid, (uint8)CAN_43_LLCE_E_PARAM_CONFIG);
        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */

        bValid = FALSE;
    }
    #endif /* (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
    else
    {
        ;/* Do nothing */
    }
    
    return bValid;
}

static void Can_43_LLCE_InitializeControllers(const uint32* u32CoreId)
{
    /* Variable for indexing the controllers. */
    uint8 can_controller;
    /* Status variable for platform init. */
    Llce_Fw_ReturnType eReturnValue;
                
    eReturnValue = Can_43_LLCE_IPW_Init(Can_43_LLCE_pCurrentConfig[*(u32CoreId)]);

    if(LLCE_FW_SUCCESS == eReturnValue)
    {
        /* Loop through all Can controllers configured based CanControllerId parameter. */
        for (can_controller = 0U; can_controller < CAN_43_LLCE_MAXCTRL_CONFIGURED; can_controller++)
        {
          #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
          if(Can_43_LLCE_pCurrentConfig[*(u32CoreId)]->aControllerDescriptors[can_controller].u32CoreId == *(u32CoreId))
          {
          #endif
            /* The initialization is skipped for the controllers that are not enabled. */
            if (CAN_43_LLCE_NULL_OFFSET != (Can_43_LLCE_pCurrentConfig[*(u32CoreId)]->aControllerDescriptors[can_controller].u8HwCtrl))
            {
                /*
                (CAN250) The function Can_43_LLCE_Init shall initialize: static variables, including flags, Common setting for the
                         complete CAN HW unit, CAN controller specific settings for each CAN controller.
                (CAN245) The function Can_43_LLCE_Init shall initialize all CAN controllers according to their configuration.
                (CAN053) Can module/controller initialization - registers of CAN controller hardware resources that are not used.
                */
                (void)Can_43_LLCE_IPW_ChangeBaudrate( can_controller, Can_43_LLCE_ControllerBaudRateIndexes[can_controller].u8CurrentBaudRateIndex);
            }
          #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
          }
          #endif
        }
        /*
        (CAN246) After initializing all controllers inside the HW Unit, the function Can_43_LLCE_Init shall change the module state to CAN_43_LLCE_READY.
        */
        Can_43_LLCE_eDriverStatus[*(u32CoreId)] = CAN_43_LLCE_READY;

        /*If any of the Error reporting category is set to interrupt, then turn on the unique Interrupt Notif Fifo*/
        if ((NOTIF_FIFO0 == Can_43_LLCE_pCurrentConfig[*(u32CoreId)]->pPlatfInitConfig->CanErrorReporting.eCanProtocolErr) || 
            (NOTIF_FIFO0 == Can_43_LLCE_pCurrentConfig[*(u32CoreId)]->pPlatfInitConfig->CanErrorReporting.eDataLostErr) || 
            (NOTIF_FIFO0 == Can_43_LLCE_pCurrentConfig[*(u32CoreId)]->pPlatfInitConfig->CanErrorReporting.eInitErr) || 
            (NOTIF_FIFO0 == Can_43_LLCE_pCurrentConfig[*(u32CoreId)]->pPlatfInitConfig->CanErrorReporting.eInternalErr) || 
            (NOTIF_FIFO0 == Can_43_LLCE_pCurrentConfig[*(u32CoreId)]->pPlatfInitConfig->CanErrorReporting.eCanProtocolWarn))
        {
            /*Enable the Notif FIFO interrupt after fw initializes the FIFO*/
            Can_43_LLCE_IPW_EnableNotifInterrupt(Can_43_LLCE_pCurrentConfig[*(u32CoreId)]->u8ActiveHif);
        }
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/*================================================================================================*/


/*
(CAN252) The function Can_43_LLCE_GetVersionInfo shall be pre compile time configurable (ON/Off) by the configuration parameter: CanVersionInfoApi
*/

#if (CAN_43_LLCE_VERSION_INFO_API == STD_ON)
/**
* @brief          Returns the version information of this module. SID is 0x07
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      versioninfo A pointer to location to store version info
*                             Must be omitted if the function does not have parameters.
*
* @return         void
*
*
* @pre            The CAN_43_LLCE_VERSION_INFO_API define must be configured on.
* @post           The version information is return if the parameter versionInfo is not a null pointer.
*
* @implements     Can_GetVersionInfo_Activity
*/
void Can_43_LLCE_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
    if (NULL_PTR == versioninfo)
    {
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /*
        (CAN177) If development error detection for the Can module is enabled: The function Can_43_LLCE_GetVersionInfo shall
                    raise the error CAN_43_LLCE_E_PARAM_POINTER if the parameter versionInfo is a null pointer.
        */
        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_GET_VERSION_INFO, (uint8)CAN_43_LLCE_E_PARAM_POINTER);
        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */

    }
    else
    {
        /*
        (CAN105) The function Can_43_LLCE_GetVersionInfo shall return the version information of this module. The version information
                     includes: Module Id, Vendor Id, Vendor specific version numbers.
        */
        versioninfo->vendorID         = (uint16)CAN_43_LLCE_VENDOR_ID;
        versioninfo->moduleID         = (uint16)CAN_43_LLCE_MODULE_ID;
        versioninfo->sw_major_version = (uint8)CAN_43_LLCE_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)CAN_43_LLCE_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)CAN_43_LLCE_SW_PATCH_VERSION;
    }
}
#endif /* (CAN_43_LLCE_VERSION_INFO_API == STD_ON) */

/*================================================================================================*/
/**
* @brief          Initialize the CAN driver. SID is 0x00.
* @details        Initialize all the controllers.
*                 The CAN module shall be initialized by Can_43_LLCE_Init(<&Can_Configuration>) service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      pxConfig Pointer to driver configuration.
*
* @return         void
*
*
* @pre            Can_43_LLCE_Init shall be called at most once during runtime.
* @post           Can_43_LLCE_Init shall initialize all the controllers and set the driver in READY state.
*
* @implements     Can_Init_Activity
*/
void Can_43_LLCE_Init(const Can_43_LLCE_ConfigType * pxConfig)
{

#if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
    boolean bCoreValid = FALSE;
#endif 

    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    if (CAN_43_LLCE_READY == Can_43_LLCE_eDriverStatus[u32CoreId])
    {    
        /*
        (CAN027) Detected development errors shall be reported to the Det_ReportError service of the Development Error Tracer (DET)
                 if the pre-processor switch CanDevErrorDetect is set.
        (CAN083) If the CanDevErrorDetect switch is enabled API parameter checking is enabled.
        (CAN028)Development Errors call the Development Error Tracer when DET is switched on and the Can module detects an error.

        */
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /*
        (CAN247) The Can module environment shall call Can_43_LLCE_Init at most once during runtime.
        (CAN091) After return of the DET the Can module function that raised the development error shall return immediately.
        (CAN174) If development error detection for the Can module is enabled: The function Can_43_LLCE_Init shall raise the
                   error CAN_43_LLCE_E_TRANSITION if the driver is not in 'uninitialized' state.
        (CAN248) The function Can_43_LLCE_Init shall report the error CAN_43_LLCE_E_UNINIT, if Can_43_LLCE_Init was called prior to any Can module function.
        */

        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_INIT, (uint8)CAN_43_LLCE_E_TRANSITION);
        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
#if (CAN_43_LLCE_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != pxConfig)
#else
        if (NULL_PTR == pxConfig)
#endif /* CAN_43_LLCE_PRECOMPILE_SUPPORT */
        {
            #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_INIT, (uint8)CAN_43_LLCE_E_INIT_FAILED);
            #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {

#if (CAN_43_LLCE_PRECOMPILE_SUPPORT == STD_ON)
    #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
            /* Sanity check for Ecuc definitions */
            if(u32CoreId < CAN_43_LLCE_MAX_PARTITIONS)
            {
                /* Update config pointer with default configuration if precompile support on. */
                Can_43_LLCE_pCurrentConfig[u32CoreId] = Can_43_LLCE_Config[u32CoreId];
                bCoreValid = TRUE;
            }
    #else
            /* Update config pointer with default configuration if precompile support on. */
            Can_43_LLCE_pCurrentConfig[u32CoreId] = &Can_43_LLCE_Config;
    #endif /*  (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
            /* Suppress "unused argument" warning */
            (void)pxConfig;
#else
    #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
            if((u32CoreId < CAN_43_LLCE_MAX_PARTITIONS) && (pxConfig->u32CoreId == u32CoreId))
            {
    #endif /*  (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
              /* Copy pointer to current Can Driver configuration. */
              Can_43_LLCE_pCurrentConfig[u32CoreId] = pxConfig;
    #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
              bCoreValid = TRUE;
            }
    #endif /*  (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */

#endif /* CAN_43_LLCE_PRECOMPILE_SUPPORT */
    #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
            if(TRUE == bCoreValid)
            {
    #endif /*  (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
                /*
                   (CAN239) The function Can_43_LLCE_Init shall initialize all on-chip hardware resources that are used by the CAN controller.
                */
               Can_43_LLCE_InitializeControllers(&u32CoreId);

    #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
            }
            else
            {
            #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_INIT, (uint8)CAN_43_LLCE_E_PARAM_CONFIG);
            #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            }
    #endif /*  (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
        }
    }
}


/*================================================================================================*/
/**
* @brief          De-initialize the CAN driver. SID is 0x10.
* @details        De-initialize all the controllers.
*                 The CAN module shall be de-initialized by Can_DeInit() service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Before controller de-initialization, the driver must be initialized and the controllers must be not in Start state.
* @post           Can_DeInit shall de-initialize all the controllers and set the driver in UNINIT state.
*
* @implements     Can_DeInit_Activity
*/
void Can_43_LLCE_DeInit(void)
{
    /* Variable for indexing the controllers. */
    uint8 can_controller = 0U;
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    /* Returns the result of CAN APIs */
    Std_ReturnType eReturnGetCtrlModeValue;
    Can_ControllerStateType eCtrlState = CAN_CS_UNINIT;
    
    /* The flag of checking of Can Controller status */
    boolean bIsCanCtrlBusy = FALSE;
    /* Return status */
    Std_ReturnType  eReturnValue;
       
    if (CAN_43_LLCE_READY != Can_43_LLCE_eDriverStatus[u32CoreId])
    {
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* 
            (SWS_Can_91011) If development error detection for the Can module is enabled: The function Can_DeInit shall raise the error CAN_E_TRANSITION 
            if the driver is not in state CAN_READY.
        */
        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_DEINIT, (uint8)CAN_43_LLCE_E_TRANSITION);
        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */           
    }
    else
    {
        /* Loop through all Can controllers configured based CanControllerId parameter. */
        for (can_controller = 0U; can_controller < CAN_43_LLCE_MAXCTRL_CONFIGURED; can_controller++)
        {
        #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
            if(Can_43_LLCE_pCurrentConfig[u32CoreId]->aControllerDescriptors[can_controller].u32CoreId == u32CoreId)
            {
        #endif /* (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
                /* Skipping controllers that are not configured. */
                if (CAN_43_LLCE_NULL_OFFSET != (Can_43_LLCE_pCurrentConfig[u32CoreId]->aControllerDescriptors[can_controller].u8HwCtrl))
                {      
                    eReturnGetCtrlModeValue = Can_43_LLCE_IPW_GetControllerMode(can_controller, &eCtrlState);

                    if (((uint8)E_OK == eReturnGetCtrlModeValue) && ( CAN_CS_STARTED == eCtrlState ))
                    {
                        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                        /* 
                            (SWS_Can_91012) If development error detection for the Can module is enabled: The function Can_DeInit shall raise the error CAN_E_TRANSITION 
                            if any of the CAN controllers is in state STARTED.
                        */
                        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_DEINIT, (uint8)CAN_43_LLCE_E_TRANSITION);
                        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */           
                        
                        /* Controller is busy */
                        bIsCanCtrlBusy =  TRUE;

                        /* Skipping the loop if any of Can Controller is in state STARTED */
                        break;
                    }
                }
        #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
        }
        /* No controller is busy */
        if (FALSE == bIsCanCtrlBusy)
        {
            /* Update state of Can driver */
            /* [SWS_Can_ 91009] The function Can_DeInit shall change the module state to
                CAN_UNINIT before de-initializing all controllers inside the HW unit */
            Can_43_LLCE_eDriverStatus[u32CoreId] = CAN_43_LLCE_UNINIT;
            eReturnValue = (Std_ReturnType)E_OK;
            /* Loop through all Can controllers configured based CanControllerId parameter. */
            for ( can_controller = 0U; can_controller < CAN_43_LLCE_MAXCTRL_CONFIGURED; can_controller++)
            {
            #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
                if(Can_43_LLCE_pCurrentConfig[u32CoreId]->aControllerDescriptors[can_controller].u32CoreId == u32CoreId)
                {
            #endif /* (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
                    /* Skipping controllers that are not configured. */
                    if (((Std_ReturnType)E_OK == eReturnValue) && ( CAN_43_LLCE_NULL_OFFSET != (Can_43_LLCE_pCurrentConfig[u32CoreId]->aControllerDescriptors[can_controller].u8HwCtrl)))
                    {
                            eReturnValue = Can_43_LLCE_IPW_DeInitController(can_controller);
                    }
            #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
                }
            #endif /* (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
            }
            
            if ((Std_ReturnType)E_OK == eReturnValue)
            {   
                /*Ignore the fw status since the DeInit must be always performed*/
                (void)Can_43_LLCE_IPW_DeInitPlatform();
               
                Can_43_LLCE_pCurrentConfig[u32CoreId] = NULL_PTR;
            }
        }
    }
}

/*================================================================================================*/
/**
* @brief          Shut down LLCE
* @details        Send the shutdown command to LLCE.
*                 Can only be called if both HIFs are deinitialized. LLCE becomes unusable until reset.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Both LLCE HIFs must be uninitialized 
* @post           LLCE is disabled
*
* @implements     Can_ShutDown_Activity
*/
Std_ReturnType Can_43_LLCE_Shutdown(void)
{
    Std_ReturnType eReturnValue = E_NOT_OK;
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    /* It is only possible to check state of current driver */
    /* LLCE will reject the command if the other HIF is active */
    if(CAN_43_LLCE_UNINIT == Can_43_LLCE_eDriverStatus[u32CoreId])
    {
        eReturnValue = Can_43_LLCE_IPW_Shutdown();
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief          Put the controller into a required state. SID is 0x03.
* @details        Switch the controller from one state to another.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller - Can controller for which the status shall be changed - based on configuration order list (CanControllerId).
* @param[in]      Transition - Possible transitions (CAN_CS_STOPPED , CAN_CS_STARTED , CAN_CS_SLEEP , CAN_T_WAKEUP)
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK   Transition initiated.
* @retval         E_NOT_OK  Development or production error.
*
*
* @pre            Before changing the controller state the driver must be initialized.
* @post           After the transition to the new state the interrupts required for that state must be enabled.
*
* @implements     Can_SetControllerMode_Activity
*/
Std_ReturnType Can_43_LLCE_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition)
{
    /* Returns the result of transition mode. */
    Std_ReturnType  eReturnValue = E_NOT_OK;
    uint8           u8HthIndex = 0U;
    uint8           u8CtrlId = 0U;

    if(TRUE == Can_ValidateController(Controller, (uint8)CAN_43_LLCE_SID_SET_CONTROLLER_MODE))
    {
        if (CAN_CS_STARTED == Transition)
        {
            /* Reset the hw obj count for HTH of  Controller */
            for (u8HthIndex = 0U; u8HthIndex < (uint8)CAN_43_LLCE_MAXHTH_CONFIGURED; u8HthIndex++ )
            {
                u8CtrlId = Can_43_LLCE_GetCurrentConfig()->aHohList[CAN_43_LLCE_FIRST_HTH_CONFIGURED + u8HthIndex].u8ControllerId;
                
                if (Controller == u8CtrlId)
                {
                    /* Copy the number of MB of each HTH. The HTHs are always grouped after the HRHs. */
                    Can_au16TransmitHwObjectCnt[u8HthIndex] = Can_43_LLCE_GetCurrentConfig()->aHohList[CAN_43_LLCE_FIRST_HTH_CONFIGURED + u8HthIndex].u16MbCount;
                }
            }
        }

        /* Call the IPW function for transition execution. */
        eReturnValue = (Std_ReturnType)Can_43_LLCE_IPW_SetControllerMode(Controller, Transition);
    }

    return (eReturnValue);
}

/*================================================================================================*/
/**
* @brief          Reports about the current status of the requested CAN controller. SID is 0x12
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller: CAN controller for which the status shall be requested.
*
* @param[out]     ControllerModePtr: Pointer to a memory location, where the current mode of the CAN controller will be stored.
*
* @retval         E_OK : Controller mode request has been accepted.
* @retval         E_NOT_OK : Controller mode request has not been accepted.
*
* @pre            Controller is initialized
* @post           The host has got the current controller state.
*
* @implements     Can_GetControllerMode_Activity
*/
Std_ReturnType Can_43_LLCE_GetControllerMode(uint8 Controller, Can_ControllerStateType * ControllerModePtr)
{
    /* Return the result of GetControllerMode */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;

    if(TRUE == Can_ValidateController(Controller, (uint8)CAN_43_LLCE_SID_GETCONTROLLERMODE))
    {
        if (NULL_PTR == ControllerModePtr)
        {
            #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* 
            [SWS_Can_91018] If parameter ControllerModePtr of Can_GetControllerMode() has an null pointer, 
            the CanDrv shall report development error code CAN_E_PARAM_POINTER to the Det_ReportError service of the DET.
            */
            (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_GETCONTROLLERMODE, (uint8)CAN_43_LLCE_E_PARAM_POINTER);
            #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            eReturnValue = Can_43_LLCE_IPW_GetControllerMode(Controller, ControllerModePtr);
        }
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief          Disable INTs. SID is 0x04.
* @details        Switch OFF the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
*
* @pre            Driver must be initalzied before changing the interrupts state (en or dis).
* @post           Controller must not respond to any interrupt assertion.
*
* @implements     Can_DisableControllerInterrupts_Activity
*/
void Can_43_LLCE_DisableControllerInterrupts(uint8 Controller)
{
    if(TRUE == Can_ValidateController(Controller, (uint8)CAN_43_LLCE_SID_DISABLE_CONTROLLER_INTERRUPTS))
    {
        /* Call the IPW function for disabling interrupts. */
        Can_43_LLCE_IPW_DisableControllerInterrupts( Controller);
    }
}


/*================================================================================================*/
/**
* @brief          Enable INTs. SID is 0x05.
* @details        Switch ON the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
*
* @pre            Driver must be initalzied before changing the interrupts state (en or dis).
* @post           Controller must respond to interrupt assertion.
*
* @implements     Can_EnableControllerInterrupts_Activity
*/
void Can_43_LLCE_EnableControllerInterrupts( uint8 Controller)
{
    if(TRUE == Can_ValidateController(Controller, (uint8)CAN_43_LLCE_SID_ENABLE_CONTROLLER_INTERRUPTS))
    {
        /* Call the IPW function for enabling interrupts. */
        Can_43_LLCE_IPW_EnableControllerInterrupts( Controller);
    }
}


/*================================================================================================*/
/**
* @brief          Transmit information on CAN bus. SID is 0x06.
* @details        Can_43_LLCE_Write checks if hardware transmit object that is identified by the HTH is free.
*                    Can_43_LLCE_Write checks if another Can_43_LLCE_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers or buffers.
*                        All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with E_OK.
*                    b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_43_LLCE_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                        The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                        The transmission of the previous L-PDU is cancelled (asynchronously).
*                        The function returns with CAN_BUSY.
*                   This routine is called by:
*                   - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth Information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier.
* @return         Std_ReturnType   Result of the write operation.
* @retval         E_OK   Write command has been accepted.
* @retval         E_NOT_OK  Development error occurred.
* @retval         CAN_BUSY   No of TX hardware buffer available or preemtive call of Can_43_LLCE_Write() that can't be implemented reentrant.
*
*
* @pre            Driver must be initialized and MB must be configured for Tx.
* @post           The data can be transmitted or rejected because of another data with a higher priority.
*
* @implements     Can_Write_Activity
*/
Std_ReturnType Can_43_LLCE_Write(Can_HwHandleType Hth, const Can_PduType * PduInfo)
{
    /* Variable for return status */
    Std_ReturnType  eReturnValue = E_NOT_OK;

    uint8 u8CtrlId = 0U;
    /* Used to store the FD feature enable or disable. */
    boolean bFdEnable;  
    uint8 u8BaudrateIndex = 0U;
    const Can_43_LLCE_ControllerDescriptorType * pxCanControllerDescriptor;
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();
    
    /* If Can_43_LLCE_pCurrentConfig[u32CoreId] is NULL_PTR then the driver was not initialised yet. */
    if (CAN_43_LLCE_UNINIT == Can_43_LLCE_eDriverStatus[u32CoreId] )
    {
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /*
           (CAN216) If development error detection for the Can module is enabled: The function Can_43_LLCE_Write shall raise the error CAN_43_LLCE_E_UNINIT if
                   the driver not yet initialized.
        */

        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_WRITE, (uint8)CAN_43_LLCE_E_UNINIT);
        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        /* Hth must be below CanMaxObjectId and should be a Tx MB type. */
    #if (CAN_43_LLCE_FIRST_HTH_CONFIGURED != 0)
        if ( (Hth <  CAN_43_LLCE_FIRST_HTH_CONFIGURED) ||
             (Hth >= CAN_43_LLCE_MAXHOH_CONFIGURED)
           )
    #else
        if (Hth >= CAN_43_LLCE_MAXHOH_CONFIGURED)
    #endif
        {
            #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /*
               (CAN217) If development error detection for the Can module is enabled: The function Can_43_LLCE_Write shall raise the error CAN_43_LLCE_E_PARAM_HANDLE
                       if the parameter Hth is not a configured Hardware Transmit Handle.
            */

            (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_WRITE, (uint8)CAN_43_LLCE_E_PARAM_HANDLE);
            #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {

        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
            /* Report Error if Protocol Data Unit information pointer is NULL. */
            if ( (NULL_PTR == PduInfo) )
        #else
            if ( (NULL_PTR == PduInfo) || (NULL_PTR == PduInfo->sdu) )
        #endif
            {
                #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                /*
                (CAN219) If development error detection for the Can module is enabled: The function Can_43_LLCE_Write shall raise the
                        error CAN_43_LLCE_E_PARAM_POINTER if the parameter PduInfo or the SDU pointer inside PduInfo is a null-pointer.
                */

                (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_WRITE, CAN_43_LLCE_E_PARAM_POINTER);
                #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                u8CtrlId = Can_43_LLCE_GetCurrentConfig()->aHohList[Hth].u8ControllerId;

                pxCanControllerDescriptor = &(Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[u8CtrlId]);

                #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
                if(pxCanControllerDescriptor->u32CoreId != u32CoreId)
                {
                    #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_WRITE, (uint8)CAN_43_LLCE_E_PARAM_CONFIG);
                    #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                #endif /* (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */


                /* Get the index of the current baud rate */
                u8BaudrateIndex = Can_43_LLCE_ControllerBaudRateIndexes[u8CtrlId].u8CurrentBaudRateIndex;

                /* Get the status of the FD feature */
                bFdEnable = (pxCanControllerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].baudrateConfig.ControllerFD.u8FdEnable != 0U);

                    /* Report error if length > 8 bytes. */
                    if ( \
                            ( ((boolean)FALSE == bFdEnable) && ((PduInfo->length) > (uint8)8U) ) || \
                            ( ((boolean)TRUE  == bFdEnable) && ((PduInfo->length) > (uint8)64U) ) || \
                            (( (((uint32)PduInfo->id) & (uint32)CAN_LPDU_FD_U32) != CAN_LPDU_FD_U32) && ( (PduInfo->length) > (uint8)8U )) \
                    )
                    {
                        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                        
                            (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_WRITE, CAN_43_LLCE_E_PARAM_DATA_LENGTH);
                        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                    }
                    else
                    {
                        eReturnValue = Can_43_LLCE_SendWriteCmd(Hth, PduInfo);
                    }
                #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
                }
                #endif
            }
        }
    }
        
    return eReturnValue;
}

static Std_ReturnType Can_43_LLCE_SendWriteCmd(Can_HwHandleType Hth, const Can_PduType * PduInfo)
{
    /* Variable for return status */
    Std_ReturnType  eReturnValue = E_NOT_OK;

    #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
    /* Temporary buffer for Trigger Transmit */
    uint8 aTempSdu[LLCE_CAN_CONFIG_PAYLOAD_MAX_SIZE];
    #endif

    PduInfoType PduInfoTriggerTransmit;

    /* Enter into EA in order to protect access to Can_au16TransmitHwObjectCnt array */
    SchM_Enter_Can_43_LLCE_CAN_EXCLUSIVE_AREA_02();

    /* Check if the maximum Tx objects for the current HTH has been exhausted */
    if (0U == Can_au16TransmitHwObjectCnt[Hth - CAN_43_LLCE_FIRST_HTH_CONFIGURED] )
    {
        /* No Tx object available */
        eReturnValue = CAN_BUSY;
    }
    else
    {
        /* Reserve a new MB in advance, assuming that this flows is E_OK */
        Can_au16TransmitHwObjectCnt[Hth - CAN_43_LLCE_FIRST_HTH_CONFIGURED]--;

        /* Create the PduInfoTriggerTransmit information */
        PduInfoTriggerTransmit.SduLength = PduInfo->length;
        PduInfoTriggerTransmit.SduDataPtr = (uint8 *)PduInfo->sdu;
        
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        /* Check if this is a trigger transmit frame */
        if (NULL_PTR == PduInfoTriggerTransmit.SduDataPtr )
        {
            if(TRUE == Can_43_LLCE_GetCurrentConfig()->aHohList[Hth].CanTriggerTransmitEnable)
            {
                /* this HTH enables the trigger transmit feature */
                /* [SWS_CAN_00503] Can_43_LLCE_Write() shall accept a null pointer as SDU
                        (Can_PduType.Can_SduPtrType = NULL_PTR) if the trigger transmit API is enabled
                        for this hardware object (CanTriggerTransmitEnable = TRUE). */
                /* [SWS_CAN_00504] If the trigger transmit API is enabled for the hardware object, Can_43_LLCE_Write() shall interpret a null pointer as SDU
                        (Can_PduType.Can_SduPtrType = NULL_PTR) as request for using the trigger transmit interface.
                        If so and the hardware object is free, Can_43_LLCE_Write() shall call CanIf_TriggerTransmit() to acquire the PDU’s data. */
                PduInfoTriggerTransmit.SduLength = LLCE_CAN_CONFIG_PAYLOAD_MAX_SIZE;
                PduInfoTriggerTransmit.SduDataPtr = aTempSdu;

                    if ((Std_ReturnType)E_OK != CanIf_TriggerTransmit(PduInfo->swPduHandle, &PduInfoTriggerTransmit))
                    {
                        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)

                        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_WRITE, CAN_43_LLCE_E_PARAM_POINTER);
                        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                        
                        eReturnValue = E_NOT_OK;
                    }
                    else
                    {
                        if(PduInfoTriggerTransmit.SduLength > LLCE_CAN_CONFIG_PAYLOAD_MAX_SIZE) 
                        {
                            eReturnValue = E_NOT_OK;
                        }
                        else
                        {
                            eReturnValue = E_OK;
                        }
                    }
            }
            else /* this MB do not enable the trigger transmit feature */
            {
                #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)

                (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_WRITE, CAN_43_LLCE_E_PARAM_POINTER);
                #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        
                eReturnValue = E_NOT_OK;
            }
        }
        if ((Std_ReturnType)E_OK == eReturnValue)
        {
        #endif
            /* Call the IPW function for transmitting data. */
            eReturnValue = Can_43_LLCE_IPW_Write( Hth, PduInfo, PduInfoTriggerTransmit);
        #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)    
        }
        #endif

        if ((Std_ReturnType)E_OK != eReturnValue)
        {
            /* On the error case, release the buffer reserved in advance. */
            Can_au16TransmitHwObjectCnt[Hth - CAN_43_LLCE_FIRST_HTH_CONFIGURED]++;
        }

    }

    SchM_Exit_Can_43_LLCE_CAN_EXCLUSIVE_AREA_02();

    return eReturnValue;
}


/*================================================================================================*/
/*================================================================================================*/
#if (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_WRITE == STD_OFF)
    /**
    * @brief          Function called at fixed cyclic time. SID is 0x01.
    * @details        Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
    *                 This routine is called by:
    *                 - CanIf or an upper layer according to Autosar requirements.
    *
    *
    * @pre            Driver must be initialized.
    * @post           Send the data from that MB that is configured for Tx.
    *
    * @implements     Can_MainFunction_Write_Activity
    */
    void Can_43_LLCE_MainFunction_Write(void)
    {
        #if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)
        uint32 u32CoreId = Can_43_LLCE_GetCoreID();

        /* Test whether the driver is already initialised. */
        /* As per CPR_RTD_00662, no action should be taken in case of error*/
        if (CAN_43_LLCE_UNINIT != Can_43_LLCE_eDriverStatus[u32CoreId] )
        {
            /* Poll all controllers for Tx MB statuses. */
            Can_43_LLCE_IPW_MainFunctionWrite();
        }

        #endif /*(CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)   */
    }

#else

    /**
    * @brief          Function called at fixed cyclic time. SID is 0x01.
    * @details        Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
    *                 This routine is called by:
    *                 - CanIf or an upper layer according to Autosar requirements.
    *
    *
    * @pre            Driver must be initialized.
    * @post           Send the data from that MB that is configured for Tx.
    *
    * @implements     Can_MainFunction_Multiple_Write_Activity
    */
        #if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)
        void Can_43_LLCE_MainFunction_Multiple_Write(uint8 writepoll)
        {
            uint32 u32CoreId = Can_43_LLCE_GetCoreID();

            /* Test whether the driver is already initialised. */
            if (CAN_43_LLCE_UNINIT != Can_43_LLCE_eDriverStatus[u32CoreId] )
            {
                /* Poll all controllers for Tx MB statuses. */
                Can_43_LLCE_IPW_MainFunctionMultipleWritePoll(writepoll);
            }
        }
        #endif /*#if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)*/

#endif /*ifdef (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_WRITE == STD_OFF)*/


/*================================================================================================*/

#if (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_READ == STD_OFF)
    /**
    * @brief          Function called at fixed cyclic time.  SID is 0x08.
    * @details        Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
    *                 This routine is called by:
    *                 - CanIf or an upper layer according to Autosar requirements.
    *
    *
    * @pre            Driver must be initialized.
    * @post           Receive the data from that MB that is configured for Rx.
    *
    * @implements     Can_MainFunction_Read_Activity
    */
    void Can_43_LLCE_MainFunction_Read(void)
    {
        #if (CAN_43_LLCE_RXPOLL_SUPPORTED  == STD_ON)
            uint32 u32CoreId = Can_43_LLCE_GetCoreID();
            /* Test whether the driver is already initialised. */
            if (CAN_43_LLCE_UNINIT != Can_43_LLCE_eDriverStatus[u32CoreId] )
            {
                /* Poll all controllers for Rx MB statuses. */
                Can_43_LLCE_IPW_MainFunctionRead();
            }
        #endif /* (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON) */
    }

#else

    /**
    * @brief          Function called at fixed cyclic time.  SID is 0x08.
    * @details        Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
    *                 This routine is called by:
    *                 - CanIf or an upper layer according to Autosar requirements.
    *
    *
    * @pre            Driver must be initialized.
    * @post           Receive the data from that MB that is configured for Rx.
    *
    * @implements     Can_MainFunction_Multiple_Read_Activity
    */
        #if (CAN_43_LLCE_RXPOLL_SUPPORTED  == STD_ON)
        void Can_43_LLCE_MainFunction_Multiple_Read(uint8 readpoll)
        {
            uint32 u32CoreId = Can_43_LLCE_GetCoreID();
            /* Test whether the driver is already initialised. */
            if ( CAN_43_LLCE_UNINIT != Can_43_LLCE_eDriverStatus[u32CoreId] )
            {
                /* Poll all controllers for Rx MB statuses. */
                Can_43_LLCE_IPW_MainFunctionMultipleReadPoll(readpoll);
            }
        }
        #endif /* #if (CAN_43_LLCE_RXPOLL_SUPPORTED  == STD_ON) */
#endif /* ifdef (CAN_43_LLCE_MAINFUNCTION_MULTIPLE_READ == STD_OFF)*/



/*================================================================================================*/

/**
* @brief          Function called at fixed cyclic time. SID is 0x09.
* @details        Service for performs the polling of BusOff events that are configured statically as 'to be polled'.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
*
* @pre            Driver must be initialized.
* @post           Handle the Busoff event.
*
* @implements     Can_MainFunction_BusOff_Activity
*/
void Can_43_LLCE_MainFunction_BusOff(void)
{
#if (CAN_43_LLCE_BUSOFFPOLL_SUPPORTED == STD_ON)
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    /* Test whether the driver is already initialised. */
    if ( CAN_43_LLCE_UNINIT != Can_43_LLCE_eDriverStatus[u32CoreId] )
    {
        /*
            (CAN109) The function Can_43_LLCE_MainFunction_BusOff shall perform the polling of bus-off events that are configured statically as 'to be polled'.
                     The bus-off events are triggered by LLCE firmware only to the controllers configured statically as 'to be polled', since it has this information.
        */
        Can_43_LLCE_IPW_ProcessBusOffPoll();
        
    }

#endif /* (CAN_43_LLCE_BUSOFFPOLL_SUPPORTED == STD_ON) */
}


#if (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON)
/**
* @brief          Function called at fixed cyclic time.
* @details        This Service performs the polling of Error notifications that are configured as 'to be polled'.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
*
* @pre            Driver must be initialized.
* @post           Handle the Error notifications in polling.
*
* @implements     Can_MainFunction_ErrorNotification_Activity
*/
void Can_43_LLCE_MainFunction_ErrorNotification(void)
{
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    /* Test whether the driver is already initialised. */
    if ( CAN_43_LLCE_UNINIT != Can_43_LLCE_eDriverStatus[u32CoreId] )
    {
        Can_43_LLCE_IPW_ProcessErrorNotification();
    }
}

#endif /* (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON) */

/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time. SIDis 0x0C.
* @details        Service for performs performs the polling of CAN status register flags to detect transition of CAN Controller state
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
*
* @pre            Driver must be initialized.
* @post           Handle the transition of Can Controller state.
*
* @implements     Can_MainFunction_Mode_Activity
*/
void Can_43_LLCE_MainFunction_Mode(void)
{
    /* Variable for indexing the controllers. */
    uint8  u8CtrlIndex = 0U;
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    /* Test whether the driver is already initialised. */
    if (CAN_43_LLCE_UNINIT != Can_43_LLCE_eDriverStatus[u32CoreId] )
    {
        /* Loop through all configured controller descriptors. */
        for (u8CtrlIndex = (uint8)0U; u8CtrlIndex < CAN_43_LLCE_MAXCTRL_CONFIGURED; u8CtrlIndex++)
        {
            #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
            if(Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[u8CtrlIndex].u32CoreId == u32CoreId)
            {
            #endif /* (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */

                /* Skipping controllers that are not configured. */
                if (CAN_43_LLCE_NULL_OFFSET != (Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[u8CtrlIndex].u8HwCtrl))
                {
                    /* Check for main function mode. */
                    Can_43_LLCE_IPW_MainFunctionMode(u8CtrlIndex);
                }
            #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON)
            }
            #endif /* (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) */
        }
    }
}

/*================================================================================================*/
/**
* @brief          Process check of WakeUp condition. SID is 0x0B.
* @details        This service shall evaluate the WakeupSource parameter to get the information,
*                 which dedicate wakeup source needs to be checked, either a CAN transceiver or controller device.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      controller Can controller ID - based on configuration order list (CanControllerId).
* @return         Std_ReturnType Result of the wakeup verification.
* @retval         E_OK  Wakeup was detected for the given controller.
* @retval         E_NOT_OK  No wakeup was detected for the given controller.
*
*
* @pre            Driver must be initialized.
* @post           Return the Wakeup event occurrence.
*
* @implements     Can_CheckWakeup_Activity
*/
Std_ReturnType Can_43_LLCE_CheckWakeup(uint8 controller)
{
    /* E_NOT_OK is defined as (uint8)0x01 */
    Std_ReturnType eReturnValue = E_NOT_OK;

    if(TRUE == Can_ValidateController(controller,  (uint8)CAN_43_LLCE_SID_CBK_CHECK_WAKEUP))
    {
        eReturnValue = E_NOT_OK;
    }

    return (eReturnValue);
}


#ifdef CAN_43_LLCE_SET_BAUDRATE_API
#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief         This function set baudrate
* @details       This routine is called by an upper layer.
*
* @param[in]     Controller controller ID
* @param[in]     BaudRateConfigID baudrateID selection
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  Switch baudrate operation was ok.
* @retval        E_NOT_OK  Switch baudrate operation was not ok.
*
* @pre           Driver must be initialized.
* @implements    Can_SetBaudrate_Activity
*/
Std_ReturnType Can_43_LLCE_SetBaudrate(uint8 Controller, const uint16 BaudRateConfigID)
{
    /* Returns the result of CAN set baudrate */
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;
    Can_ControllerStateType eCtrlState = CAN_CS_UNINIT;

    if(TRUE == Can_ValidateController(Controller, (uint8)CAN_43_LLCE_SID_SET_BAUDRATE))
    {
        eReturnValue = Can_43_LLCE_IPW_GetControllerMode(Controller, &eCtrlState);

        if ((uint8)E_OK == eReturnValue)
        {
            if (CAN_CS_STOPPED != eCtrlState)
            {
                /*
                        (SWS_Can_00256) If the call of Can_SetBaudrate() would cause a re-initialization
                                of the CAN Controller and the CAN Controller is not in state STOPPED, it shall return E_NOT_OK.
                */
                eReturnValue = (uint8)E_NOT_OK;
            }
            else
            {
                eReturnValue = Can_43_LLCE_SendSetBaudrateCmd(Controller, BaudRateConfigID);
            }
        }
    }

    return eReturnValue;
}


static Std_ReturnType Can_43_LLCE_SendSetBaudrateCmd(uint8 Controller, const uint16 BaudRateConfigID)
{
    /* Returns the result of CAN set baudrate */
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;
    uint8 u8BaudrateIndex = 0U;

    /* Check the Baudrate */
    for (u8BaudrateIndex = 0U; u8BaudrateIndex < Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].u8MaxBaudRateCount; u8BaudrateIndex++)
    {
        /* Check the Baudrate */
        if (BaudRateConfigID == (uint16)(Can_43_LLCE_GetCurrentConfig()->aControllerDescriptors[Controller].pControllerBaudrateConfigsPtr[u8BaudrateIndex].u16ControllerBaudRateConfigID))
        {
            /* Baudrate is Valid */
            /* SWS_Can_00062 Check if a baudrate change is required */
            if (Can_43_LLCE_ControllerBaudRateIndexes[Controller].u8CurrentBaudRateIndex != u8BaudrateIndex)
            {
                /* Copy the index of Valid Baudrate into the Can_43_LLCE_ControllerBaudRateIndexes as u8CurrentBaudRateIndex */
                Can_43_LLCE_ControllerBaudRateIndexes[Controller].u8CurrentBaudRateIndex = u8BaudrateIndex;
                
                eReturnValue = Can_43_LLCE_IPW_ChangeBaudrate(Controller, u8BaudrateIndex);
            }
            else
            {
                eReturnValue = (uint8)E_OK;
            }
            break;
        }
    }

    if ((uint8)E_OK != eReturnValue )
    {
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_SET_BAUDRATE, (uint8)CAN_43_LLCE_E_PARAM_BAUDRATE);
        #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
    }

    return eReturnValue;
}

#endif
#endif


/*================================================================================================*/
/**
* @brief         This service obtains the error state of the CAN controller.
* @details       This service shall read the error state register of Can Controller and shall return the error status to upper layer.
*
* @param[in]     Controller - Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested for ErrorState.
* @param[out]    ErrorStatePtr - Pointer to a memory location, where the error state of the CAN controller will be stored.
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  Error state request has been accepted.
* @retval        E_NOT_OK  Error state request has not been accepted.
*
* @pre           Driver must be initialized.
*
* @implements     Can_GetControllerErrorState_Activity
*/
Std_ReturnType Can_43_LLCE_GetControllerErrorState(uint8 Controller, Can_ErrorStateType * ErrorStatePtr)
{
    /* Returns the result of CAN GetControllerErrorState */
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(Controller, (uint8)CAN_43_LLCE_SID_GETCONTROLLERERRORSTATE))
    {
        /* 
            [SWS_Can_91007] If default error detection for the Can module is enabled: if the parameter ErrorStatePtr is a null pointer, 
                    the function Can_GetControllerErrorState shall raise default error CAN_E_PARAM_POINTER and return E_NOT_OK. 
        */
        if ( NULL_PTR == ErrorStatePtr )
        {
            #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_GETCONTROLLERERRORSTATE, (uint8)CAN_43_LLCE_E_PARAM_POINTER);
            #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            eReturnValue = Can_43_LLCE_IPW_GetControllerErrorState(Controller, ErrorStatePtr);
        }
    }

    return (eReturnValue);
}

/*================================================================================================*/
/**
* @brief         This service obtains the number of RX errors of the CAN controller.
* @details       This service shall read the error state register of Can Controller and shall return the number of rx errors to upper layer.
*
* @param[in]     ControllerId - Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested for rx error counter.
* @param[out]    RxErrorCounterPtr - Pointer to a memory location, where the rx error counter of the CAN controller will be stored.
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  Error state request has been accepted.
* @retval        E_NOT_OK  Error state request has not been accepted.
*
* @pre           Driver must be initialized.
* @implements    Can_GetControllerRxErrorCounter_Activity
*/
Std_ReturnType Can_43_LLCE_GetControllerRxErrorCounter (uint8 ControllerId, uint8 * RxErrorCounterPtr)
{
    /* Returns the result of CAN GetControllerRxErrorCounter */
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;
 
    if(TRUE == Can_ValidateController(ControllerId, (uint8)CAN_43_LLCE_SID_GET_CTRL_RX_ERROR_COUNTER))
    {
        if (NULL_PTR == RxErrorCounterPtr)
        {
            #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* 
            *   [SWS_Can_00514]: If development error detection for the Can module is enabled:
            *   if the parameter RxErrorCounterPtr is a null pointer, the function Can_GetControllerRxErrorCounter shall
            *   raise development error CAN_E_PARAM_POINTER and return E_NOT_OK.
            */
            (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_GET_CTRL_RX_ERROR_COUNTER, (uint8)CAN_43_LLCE_E_PARAM_POINTER);
            #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            /* 
            *   [SWS_Can_00515]: When the API Can_GetControllerRxErrorCounter is called with
            *   Controller Id as input parameter then Can driver shall read the Rx error counter
            *   register of Can Controller and shall return the Rx error count to upper layer.
            */
            eReturnValue = Can_43_LLCE_IPW_GetControllerRxErrorCounter(ControllerId, RxErrorCounterPtr);
        }
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service obtains the number of Tx errors of the CAN controller.
* @details       This service shall read the error state register of Can Controller and shall return the number of Tx errors to upper layer.
*
* @param[in]     ControllerId - Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested for rx error counter.
* @param[out]    TxErrorCounterPtr - Pointer to a memory location, where the tx error counter of the CAN controller will be stored.
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  Error state request has been accepted.
* @retval        E_NOT_OK  Error state request has not been accepted.
*
* @pre           Driver must be initialized.
* @implements    Can_GetControllerTxErrorCounter_Activity
*/
Std_ReturnType Can_43_LLCE_GetControllerTxErrorCounter (uint8 ControllerId, uint8 * TxErrorCounterPtr)
{
    /* Returns the result of CAN GetControllerRxErrorCounter */
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(ControllerId, (uint8)CAN_43_LLCE_SID_GET_CTRL_TX_ERROR_COUNTER))
    {
        if (NULL_PTR == TxErrorCounterPtr)
        {
            #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* 
            *   [SWS_Can_00519]: If development error detection for the Can module is enabled:
            *   if the parameter TxErrorCounterPtr is a null pointer, the function Can_GetControllerTxErrorCounter shall
            *   raise development error CAN_E_PARAM_POINTER and return E_NOT_OK.
            */
            (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_GET_CTRL_TX_ERROR_COUNTER , (uint8)CAN_43_LLCE_E_PARAM_POINTER);
            #endif /* (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            /* 
            *   [SWS_Can_00520]: When the API Can_GetControllerTxErrorCounter is called with
            *   Controller Id as input parameter then Can driver shall read the Tx error counter
            *   register of Can Controller and shall return the Tx error count to upper layer.
            */
            eReturnValue = Can_43_LLCE_IPW_GetControllerTxErrorCounter(ControllerId, TxErrorCounterPtr);
        }
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service obtains the Llce Can controller status.
* @details       This service obtains a structure containing values from HW registers of the specified channel.
*
* @param[in]     ControllerId - Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested for status
* @param[out]    TxErrorCounterPtr - Pointer to a memory location, where the status of the CAN controller will be stored.
*
* @return        Std_ReturnType.  Result of the check.
* @retval        E_OK  Error state request has been accepted.
* @retval        E_NOT_OK  Error state request has not been accepted.
*
* @pre           Llce firmware must be loaded.
*   
*/
Std_ReturnType Can_43_LLCE_GetControllerStatus(uint8 ControllerId, Llce_Can_GetStatusCmdType * StatusPtr)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(ControllerId, CAN_43_LLCE_SID_GETCONTROLLERERRORSTATE))
    {
        eReturnValue = Can_43_LLCE_IPW_GetControllerStatus(ControllerId, StatusPtr);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service obtains the Llce firmware version.
* @details       This service obtains a string which encapsulates all of the components versions for the Llce firmware.
*
* @param[out]    pVersionString - The string with all the components versions for the Llce firmware. 
* @param[out]    pStringLength - Length of the string.
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  Error state request has been accepted.
* @retval        E_NOT_OK  Error state request has not been accepted.
*
* @pre           Llce firmware must be loaded.
* @implements    Can_GetFwVersion_Activity
*/
Std_ReturnType Can_43_LLCE_GetFwVersion(const uint8 ** pVersionString, uint8 * pStringLength)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    eReturnValue = Can_43_LLCE_IPW_GetFwVersion(pVersionString, pStringLength);

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service set a single standard filter.
* @details       This service set a single standard filter.
*
* @param[in]     pCanFilter - parameter of Can_SetFilterType, containing filter type and message buffer related configuration data
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully set.
* @retval        E_NOT_OK  filter was not successfully set.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetFilter_Activity
*/
Std_ReturnType Can_43_LLCE_SetFilter(const Can_SetFilterType * pCanFilter)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(Can_43_LLCE_GetCurrentConfig()->aHohList[pCanFilter->Hrh].u8ControllerId, (uint8)CAN_43_LLCE_SID_SET_FILTER))
    {
        /* Pass only one filter at a time, for timing concerns, hence only the first value in the filter array is used, the one with index "0U". */
        eReturnValue = Can_43_LLCE_IPW_SetFilter(pCanFilter);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service set a single standard filter at a given address.
* @details       This service set a single standard filter at a given address.
*
* @param[in]     pCanFilter - parameter of Can_SetFilterType, containing filter type and message buffer related configuration data
* @param[in]     u16FilterAddr - Address in RxLut for filter. Must be free. 
*                An address can be freed either by calling the RemoveFilter function or leaving extra free filters via host configuration.
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully set.
* @retval        E_NOT_OK  filter was not successfully set.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetFilter_Activity
*/
Std_ReturnType Can_43_LLCE_SetFilterAtAddress(const Can_SetFilterType * pCanFilter, const uint16 u16FilterAddr)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(Can_43_LLCE_GetCurrentConfig()->aHohList[pCanFilter->Hrh].u8ControllerId, (uint8)CAN_43_LLCE_SID_SET_FILTER))
    {
        /* Pass only one filter at a time, for timing concerns, hence only the first value in the filter array is used, the one with index "0U". */
        eReturnValue = Can_43_LLCE_IPW_SetFilterAtAddress(pCanFilter, u16FilterAddr);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service set a single advanced filter at a given address.
* @details       This service set a single advanced filter at a given address.
*
* @param[in]     pAfFilter - parameter of Can_SetAfFilterType, containing filter type and message buffer related configuration data along with routing rules and other advanced features
* @param[in]     u16FilterAddr - address returned by the RemoveFilter function
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully set.
* @retval        E_NOT_OK  filter was not successfully set.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetAfFilterAtAddress_Activity
*/
Std_ReturnType Can_43_LLCE_SetAfFilterAtAddress(const Can_SetAfFilterType * pAfFilter, const uint16 u16FilterAddr)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(Can_43_LLCE_GetCurrentConfig()->aHohList[pAfFilter->Filter.Hrh].u8ControllerId, (uint8)CAN_43_LLCE_SID_SET_FILTER))
    {
        /* Pass only one filter at a time, for timing concerns, hence only the first value in the filter array is used, the one with index "0U". */
        eReturnValue = Can_43_LLCE_IPW_SetAfFilterAtAddress(pAfFilter, u16FilterAddr);
    }

    return eReturnValue;
}
/*================================================================================================*/
/**
* @brief         This service set a single advanced filter.
* @details       This service set a single advanced filter.
*
* @param[in]     pAfFilter - parameter of Can_SetAfFilterType, containing advanced filter type and message buffer related configuration data
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully set.
* @retval        E_NOT_OK  filter was not successfully set.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetAfFilter_Activity
*/
Std_ReturnType Can_43_LLCE_SetAfFilter(const Can_SetAfFilterType * pAfFilter)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(Can_43_LLCE_GetCurrentConfig()->aHohList[pAfFilter->Filter.Hrh].u8ControllerId, (uint8)CAN_43_LLCE_SID_SET_FILTER))
    {
        /* Pass only one filter at a time, for timing concerns, hence only the first value in the filter array is used, the one with index "0U". */
        eReturnValue = Can_43_LLCE_IPW_SetAfFilter(pAfFilter);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service a new destination for advanced features
* @details       This service a new destination for advanced features
**
* @param[in]      destRule - The destination to add to the LLCE destination list
* @param[out]     pu8RuleIdx - The index of the new destination in the LLCE list. Needed for SetAdvancedFilter.
*
* @return        Std_ReturnType. Result of the request.
* @retval        E_OK  Destination created
* @retval        E_NOT_OK  Error
*
* @pre           Llce firmware must be loaded and the controller initialized
*/
Std_ReturnType Can_43_LLCE_CreateAfDestination(const Can_Af_DestRulesType destRule, uint8* pu8RuleIdx)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    if (CAN_43_LLCE_READY != Can_43_LLCE_eDriverStatus[u32CoreId] )
    {
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_CREATE_DESTINATION, (uint8)CAN_43_LLCE_E_UNINIT);
        #endif
    }
    else
    {
        /* Pass the destination rule to be added and the pointer for the index to be returned. */
        eReturnValue = Can_43_LLCE_IPW_CreateAfDestination(destRule, pu8RuleIdx);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service removes an existing destination for advanced features
* @details       This service removes an existing destination for advanced features
**
* @param[in]     u8RuleIdx - The index of the destination to be removed from the LLCE list.
*
* @return        Std_ReturnType. Result of the request.
* @retval        E_OK  Destination removed
* @retval        E_NOT_OK  Error
*
* @pre           Llce firmware must be loaded and the controller initialized
*/
Std_ReturnType Can_43_LLCE_RemoveAfDestination(uint8 u8RuleIdx)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    if (CAN_43_LLCE_READY != Can_43_LLCE_eDriverStatus[u32CoreId] )
    {
        #if (CAN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError( (uint16)CAN_43_LLCE_MODULE_ID, (uint8)CAN_43_LLCE_INSTANCE, (uint8)CAN_43_LLCE_SID_REMOVE_DESTINATION, (uint8)CAN_43_LLCE_E_UNINIT);
        #endif
    }
    else
    {
        /* Pass the index of the destination to be removed */
        eReturnValue = Can_43_LLCE_IPW_RemoveAfDestination(u8RuleIdx);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service removes a single standard filter.
* @details       This service removes a single standard filter.
*
* @param[in]     Hrh - HRH to which the filter is attached.
* @param[in]     u16FilterAddr - address of the removed filter, to be later used by Can_43_LLCE_SetFilterAtAddress.
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully set.
* @retval        E_NOT_OK  filter was not successfully set.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_RemoveFilter_Activity
*/
Std_ReturnType Can_43_LLCE_RemoveFilter(Can_HwHandleType Hrh, uint16 *u16FilterAddr)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(Can_43_LLCE_GetCurrentConfig()->aHohList[Hrh].u8ControllerId, (uint8)CAN_43_LLCE_SID_REMOVE_FILTER))
    {
        eReturnValue = Can_43_LLCE_IPW_RemoveFilter(Hrh, u16FilterAddr);    
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service enables or disables a single standard filter.
* @details       This service enables or disables a single standard filter.
*
* @param[in]     Hrh - HRH to which the filter is attached.
* @param[in]     State - Logical value to select if filter is enabled or disabled
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully enabled/disabled.
* @retval        E_NOT_OK  filter was not successfully enabled/disabled.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetFilterState_Activity 
*/
Std_ReturnType Can_43_LLCE_SetFilterState(Can_HwHandleType Hrh, Can_43_LLCE_FilterStateType eState)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(Can_43_LLCE_GetCurrentConfig()->aHohList[Hrh].u8ControllerId, (uint8)CAN_43_LLCE_SID_SET_FILTER_ENABLE_STATE))
    {
        eReturnValue = Can_43_LLCE_IPW_SetFilterState(Hrh, eState);    
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service sets the state of controller in a multicast routing configuration.
* @details       
*
* @param[in]     ControllerId - controller to be enabled or disabled.
* @param[in]     eChannelStatus - enable or disable channel
*
* @return        Std_ReturnType.  Result of the command.
* @retval        E_OK  channel was successfully enabled/disabled.
* @retval        E_NOT_OK  channel was not successfully enabled/disabled.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetChannelRoutingOutputState_Activity
*/
Std_ReturnType Can_43_LLCE_SetChannelRoutingOutputState(uint8 ControllerId, Can_43_LLCE_ChannelStateType eChannelStatus)
{
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(ControllerId, (uint8)CAN_43_LLCE_SID_SETCHANNEL_ROUTING_OUTPUTSTATE))
    {
        eReturnValue = Can_43_LLCE_IPW_SetChannelRoutingOutputState(ControllerId, eChannelStatus);    
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         This service forces a deinit of the driver
* @details       When LLCE is not responding and must be reset, this service may be used to allow another init call. 
*
* @implements    Can_ForceDeInit_Activity
*/
void Can_43_LLCE_ForceDeInit(void)
{
    uint32 u32CoreId = Can_43_LLCE_GetCoreID();

    Can_43_LLCE_eDriverStatus[u32CoreId] = CAN_43_LLCE_UNINIT;
    Can_43_LLCE_pCurrentConfig[u32CoreId] = NULL_PTR;
}


#if (CAN_43_LLCE_API_ENABLE_ABORT_MB == STD_ON)
/**
* @brief          Process a pending transmission abort
* @details        This function requests aborting of the lowest priority pending transmission
*                 of controller ControllerId and returns the hardware transmis handler Hth which
*                 has been freed along with the message tracking information swPduHandle
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      ControllerId - Logical Id of the hardware controller 
* @param[out]     Hth - HW-transmit handler
* @param[out]     swPduHandle - tracking information of the aborted MB
*
* @return         Std_ReturnType.  Result of the abort lowest priority MB service.
* @retval         E_OK  Lowest Priority Message Buffer has been discarded
* @retval         E_NOT_OK  Lowest Priority Message Buffer has not been discarded
*
* @pre            Driver must be initialized; Hardware channel of ControllerId must be started
*
* @note           Not AUTOSAR required. This is user implementation.
* @implements     Can_AbortMb_Activity
*/
Std_ReturnType Can_43_LLCE_AbortMb(Can_HwHandleType Hth)
{

    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;

    if(TRUE == Can_ValidateController(Can_43_LLCE_GetCurrentConfig()->aHohList[Hth].u8ControllerId, (uint8)CAN_43_LLCE_SID_ABORT_LOWEST_PRIO_MB))
    {
        eReturnValue = Can_43_LLCE_Ipw_AborMb(Hth);
    }

    return eReturnValue;
}

#endif


#if (CAN_43_LLCE_API_MANUAL_BUSOFF_RECOVERY == STD_ON)
/**
* @brief          Service for requesting recovery from bus-off event
* @details        This service requires preconfiguration of LLCE in bus-off recovery mode
*                 for the given ControllerId. In this mode, the bus-off event (LLCE_ERROR_BUSOFF)
*                 is not escalated to CanIf bus-off callout.
*                 The user may request the synchronization of controller on the bus after it 
*                 switched to bus-off state using this API.
*
* @param[in]      ControllerId - Logical Id of the hardware controller 
*
* @return         Std_ReturnType.
* @retval         E_OK  Command accepted by LLCE and recovery requested for the given ctrl.
* @retval         E_NOT_OK  Command not accepted due to misconfiguration.
*
* @pre            Driver must be initialized; ControllerId must be started
*                 ControllerId must be set in manual bus-off request mode.
*
* @note           Not AUTOSAR required.
*/
Std_ReturnType Can_43_LLCE_ManualBusOffRecovery(uint8 ControllerId )
{
    Std_ReturnType eReturnValue = E_NOT_OK;
    
    if(TRUE == Can_ValidateController(ControllerId, (uint8)CAN_43_LLCE_SID_MANUAL_BUSOFF_RECOVERY))
    {
        eReturnValue = Can_43_LLCE_Ipw_ManualBusOffRecovery(ControllerId);
    }

    return eReturnValue;
}

#endif

#define CAN_43_LLCE_STOP_SEC_CODE

#include "Can_43_LLCE_MemMap.h"


#ifdef __cplusplus
}
#endif


/** @} */
