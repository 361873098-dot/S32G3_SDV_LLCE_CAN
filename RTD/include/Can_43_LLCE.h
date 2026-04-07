/**
*   @internal
*   @file    Can_43_LLCE.h
*   @implements Can.h_Artifact
*   @version 1.0.11
*
*   @brief   AUTOSAR Can_43_LLCE - module interface.
*   @details API header for CAN driver.
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


#ifndef CAN_43_LLCE_H
#define CAN_43_LLCE_H

#ifdef __cplusplus
extern "C"{
#endif

/*
(CAN043) The file Can_43_LLCE.h contains the declaration of the Can module API.
(CAN037) The file Can_43_LLCE.h only contains 'extern' declarations of constants, global data, type definitions and services
            that are specified in the Can module SWS.
*/

/**
* @file           Can_43_LLCE.h
*/



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Can_43_LLCE.h
*/
#include "ComStackTypes.h"
#include "Can_43_LLCE_Cfg.h"
#include "Can_GeneralTypes.h"
#include "Can_Llce_Types.h"
#include "Soc_Ips.h"
#include "Llce_FwVersion.h"
#include "Llce_InterfaceCanTypes.h"
#include "Mcal.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
/**
* @{
* @file           Can_43_LLCE.h
*/
#define CAN_43_LLCE_VENDOR_ID                   43
#define CAN_43_LLCE_MODULE_ID                   80
#define CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION    4
#define CAN_43_LLCE_AR_RELEASE_MINOR_VERSION    4
#define CAN_43_LLCE_AR_RELEASE_REVISION_VERSION 0
#define CAN_43_LLCE_SW_MAJOR_VERSION            1
#define CAN_43_LLCE_SW_MINOR_VERSION            0
#define CAN_43_LLCE_SW_PATCH_VERSION            11
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID != CAN_43_LLCE_VENDOR_ID_CFG_H)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can configuration header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_CFG_H))
  #error "AutoSar Version Numbers of Can_43_LLCE.h and Can_43_LLCE_Cfg.h are different"
#endif

/* Check if current file and CAN configuration header file are of the same software version */
#if ((CAN_43_LLCE_SW_MAJOR_VERSION != CAN_43_LLCE_SW_MAJOR_VERSION_CFG_H) || \
     (CAN_43_LLCE_SW_MINOR_VERSION != CAN_43_LLCE_SW_MINOR_VERSION_CFG_H) || \
     (CAN_43_LLCE_SW_PATCH_VERSION != CAN_43_LLCE_SW_PATCH_VERSION_CFG_H))
  #error "Software Version Numbers of Can_43_LLCE.h and Can_43_LLCE_Cfg.h are different"
#endif
/* Check if current file and CAN configuration header file are of the same software version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) )
  #error "Software Version Numbers of Can_43_LLCE.h and ComStackTypes.h are different"
#endif
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
* @brief          Can_43_LLCE_ObjType
* @details        Used for value received by Tressos interface configuration.
*                 Describes the HOH configuration.
*
*/
typedef enum
    {
        CAN_43_LLCE_RECEIVE = 0U,    /**< @brief Regular Receive */
        CAN_43_LLCE_RECEIVE_AF,      /**< @brief Receive with Advanced Features*/
        CAN_43_LLCE_TRANSMIT    /**< @brief Transmit MB */
    } Can_43_LLCE_ObjType;


    
/**
* @brief          Can_43_LLCE_StatusType
* @details        CAN Driver status used for checking and preventing double driver initialization.
*                 CAN_43_LLCE_UNINIT = The CAN controller is not initialized. The CAN Controller is not participating on the CAN bus.
*                              All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
*                 CAN_43_LLCE_READY = Controller has initialized: static variables, including flags;
*                             Common setting for the complete CAN HW unit; CAN controller specific settings for each CAN controller.
*
*/
typedef enum
    {
        CAN_43_LLCE_UNINIT = 0U, /**< @brief Driver not initialized */
        CAN_43_LLCE_READY       /**< @brief Driver ready */
    } Can_43_LLCE_StatusType;



/**
* @brief          Can_43_LLCE_FilterStateType
* @details        Used for enabling or disabling filters at runtime.
*
*/
typedef enum
    {
        CAN_43_LLCE_FILTERSTATE_DISABLED = 0U, /**< @brief Filter disabled at runtime */
        CAN_43_LLCE_FILTERSTATE_ENABLED        /**< @brief Filter enabled at runtime */
    } Can_43_LLCE_FilterStateType;

/**
* @brief          Can_43_LLCE_ChannelStateType
* @details        Used for enabling or disabling channels in multicast routing configuration.
*
*/
typedef enum
    {
        CAN_43_LLCE_CHANNELSTATE_DISABLED = 0U, /**< @brief Channel disabled */
        CAN_43_LLCE_CHANNELSTATE_ENABLED        /**< @brief Channel enabled */
    } Can_43_LLCE_ChannelStateType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          Configuration of BCAN controller.
* @details        This structure is initialized by Tresos considering user settings.
*                 Used by Can_43_LLCE_SetBaudrate() API to set the default baudrate after initialization.
*                 and to change the baudrate when the BCAN is in stopped mode.
*
*/
typedef struct
    {
        const Llce_Can_SetBaudrateCmdType baudrateConfig;

#if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
        const uint16 u16ControllerBaudRateConfigID;
#endif
    } Can_43_LLCE_ControllerBaudrateConfigType;


/**
* @brief          Can_43_LLCE_HOHType
* @details        Type for storing information about hardware objects.
*                 Used by Can_43_LLCE_MBConfigContainerType.
*
*/
typedef struct
    {
        Can_43_LLCE_ObjType eMBType; /**< @brief Receive/ Receive AF / Transmit */

        const uint16 u16MbCount; /**< @brief Maximum number of message buffers for this HOH */

        const uint8 u8ControllerId; /**< @brief Controller ID (index into controller address array containing Can_ControllerPtrType). */

        uint8 u8FdPaddingValue; /**< @brief Padding value for MB > 8 bytes */

        const uint8 u8CanMainFuncRWPeriodRef; /**< @brief read write period reference */

        const uint8 u8RWInterface; /**< @brief Rx/Ack interface. Specifies which interface to be used for current HOH. */

        const boolean bEnableTxFrameMac; /**< @brief The parameter is used to enable adding of MAC code to transmitted frames.*/

        const uint32 u32TxHseKeyHandle; /**< @brief The parameter is used to add the key handle for generation of MAC code to transmitted frames.*/

#if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
        const boolean CanTriggerTransmitEnable; /**< @brief The parameter is used to detect the MB which run with trigger transmit feature*/
#endif
#if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
        const boolean bDummyHRH; /**< @brief True for dummy HRH */
#endif
    } Can_43_LLCE_HOHType;

/**
* @brief          Structure for describing individual BCAN controllers on the chip.
* @details        HRH = Hardware Receive Handle (HRH) is defined and provided by the CAN driver.
*                       Each HRH represents exactly one hardware object.
*                       The HRH can be used to optimize software filtering.
*                 HTH = The Hardware Transmit Handle (HTH) is defined and provided by the CAN driver.
*                       Each HTH represents one or several hardware objects, that are
*                       configured as hardware transmit pool.
*
*/
typedef struct
    {
        const uint8 u8MaxBaudRateCount; /**< @brief Max BaudRate number. */
        const uint8 u8DefaultBaudRateIndex; /**< @brief Default baudrate index. */
        const Can_43_LLCE_ControllerBaudrateConfigType * const pControllerBaudrateConfigsPtr; /**< @brief Pointer to the Configuration of Baudrate timing parameter for BCAN baudrate controller ( CTRL value register). */
        const uint32 u32CoreId;  /**< @brief ID of the application core this is assigned to */ 
        const uint8 u8HwCtrl; /**< @brief Hardware ID for BCAN controller */
    } Can_43_LLCE_ControllerDescriptorType;

/**
* @brief          Structure for describing individual Hardware controllers.
* @details        This structure is initialized by Tresos/Design Studio considering user settings. It generates an array (HwControllerDescriptors_PB) that is indexed
*                 using the Hardware ID of the BCAN controller. 
*                 The structure contains data needed by the driver (Event Trigger Mode / CanIf ID).
*
*/
typedef struct
    {
        const uint32 u32DrvControllerOptions; /*< @brief Variable used only by driver. Event Trigger Mode TxProcessing/RxProcessing/BusoffProcessing. */
        const uint8 u8CanIfCtrlId; /**< @brief Controller ID defined by CanIf */
        const uint8 u8FifoInterface; /**< @brief LLCE FIFO Interface used for interrupt processing. Default is 1 to 1 mapped with Can Hardware Channel. */
    }Can_43_LLCE_HwControllerDescriptorType;

/**
* @brief          Top Level structure containing all Driver configuration.
* @details        A pointer to this structure is transmitted to Can_43_LLCE_Init() to initialize the driver at startup.
*                 The application selects one of the configurations by using a pointer to one of the elements
*                 of this array as a parameter of the Can_43_LLCE_Init function.
*
*/
typedef struct
    {

        const Llce_Can_InitPlatformCmdType * const pPlatfInitConfig; /**< @brief Configuration used by platform init command.(e.g Maximum number of filters or MB/channel) */

        const Llce_Can_InitCmdType * const pChannelInitConfig; /**< @brief Configuration used by channel init command. */

        Llce_Can_ReceiveFilterType** paReceiveFilters;
        
        Llce_Can_AdvancedFilterType** paAdvancedFilters;

        Llce_Can_AuxFilterType** paAuxFilters; /**< @brief Pointer to the list of auxilliary filters */

        uint16* paLlce_MaxAuxilliaryFilterCount; /**< @brief Pointer to an array with the number of auxilliary filters per controller */

        const Can_43_LLCE_HOHType * const aHohList; /**< @brief Pointer to the list of hardware objects */

        const Can_43_LLCE_ControllerDescriptorType * const aControllerDescriptors; /**< @brief Pointer to the first BCAN Controller description. */

        const Can_43_LLCE_HwControllerDescriptorType * const aHwControllerDescriptors; /**< @brief Pointer to the Hardware Controller description. */

        const uint32* CanFilterId2CustomIdx; /**< @brief Mapping array CanObjectId <-> CustomProcessingIndex */

        const boolean bHeadlessModeEnabled; /**< @brief True when LLCE is started in headless mode */

        const uint32 u32CoreId; /** @brief Configuration Core ID */

        const uint8 u8ActiveHif;  /**< @brief LLCE Host interface used by this driver instance */

        const uint8 u8DefaultController;  /**< @brief Controller used when sending generic commands to LLCE */
    } Can_43_LLCE_ConfigType;

/**
* @brief          Structure containing filter configuration data.
* @details        
*
*/
typedef struct
    {
        uint32 uMessageId; /**< @brief Configuration used by platform init command.(e.g Maximum number of filters or MB/channel) */

        uint32 uIdMask; /**< @brief Mask to use (for Mask filter) or Range End */

        uint16 u16MbCount; /**< @brief Number of message buffers to allocate to new filter */

        Can_HwHandleType Hrh; /**< @brief HRH to which to attach the filter */

        uint8 u8RWInterface; /**< @brief Rx interface for current filter. First 16 interfaces (0-15) are reserved for interrupt processing, next 6 interfaces (16-21) are for polling classes. */

        Llce_Can_IdLengthType eIdType; /**< @brief Standard or Extended Can ID */

        Llce_Can_EntryType eFilterType; /**< @brief Filter type (Exact Match, Mask or Range) */

        Llce_CanRx_MbLengthType eFilterMbLength; /**< @brief Message buffer payload length: 8 or 64 bytes */
    } Can_SetFilterType;

/**
* @brief          Structure containing advanced filter configuration data.
*/
typedef struct
{
    Can_SetFilterType Filter;
    Llce_Can_AdvancedFeatureType AdvancedFeature;
} Can_SetAfFilterType;

/**
* @brief          CanErrorNotification callback input type.
* @details        
*
*/
typedef struct
    {
        volatile Llce_Can_ErrorNotifType* ErrorInfo; /**< @brief Error description */

        uint8 u8CanIfCtrlId; /**< @brief Controller Id */

        Llce_Can_NotificationIdType eNotifId; /**< @brief Error type */
    } CanErrorNotificationType;

/**
* @brief          Structure containing the baudrate index.
* @details        
*
*/
typedef struct 
    {
        uint8 u8CurrentBaudRateIndex; /*< @brief Current controller baud rate */
    }Can_43_LLCE_ControllerBaudRate;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

/*
    Holds current status/run-time of CAN driver: CAN_43_LLCE_UNINIT or CAN_43_LLCE_READY (declared as global variable in "Can_43_LLCE.c" file).
    (CAN103) After power-up/reset, the Can module shall be in the state CAN_43_LLCE_UNINIT.
    Covers CAN103
*/
extern Can_43_LLCE_StatusType Can_43_LLCE_eDriverStatus[CAN_43_LLCE_MAX_PARTITIONS];

/*
    Holds the baudrate index of every configured controller. Declared as a global variable in Can_IPW.c file.
*/
extern Can_43_LLCE_ControllerBaudRate   Can_43_LLCE_ControllerBaudRateIndexes[CAN_43_LLCE_MAXCTRL_CONFIGURED];

/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by Can_43_LLCE_Init(). */
extern const Can_43_LLCE_ConfigType * Can_43_LLCE_pCurrentConfig[CAN_43_LLCE_MAX_PARTITIONS];

#define CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

#define CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

/* Export Driver configuration */
CAN_43_LLCE_CONFIG_EXT

#define CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

#define CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

extern volatile uint16 Can_au16TransmitHwObjectCnt[CAN_43_LLCE_MAXHTH_CONFIGURED];

#define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define CAN_43_LLCE_START_SEC_CODE
#include "Can_43_LLCE_MemMap.h"
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
Std_ReturnType Can_43_LLCE_GetControllerErrorState( uint8 Controller,
                                                Can_ErrorStateType * ErrorStatePtr
                                              );

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
Std_ReturnType Can_43_LLCE_GetControllerRxErrorCounter ( uint8 ControllerId, uint8 * RxErrorCounterPtr );

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
Std_ReturnType Can_43_LLCE_GetControllerTxErrorCounter ( uint8 ControllerId, uint8 * TxErrorCounterPtr);

/*================================================================================================*/
/**
* @brief         This service obtains the Llce Can controller status.
* @details       This service obtains a structure containing values from HW registers of the specified channel.
*
* @param[in]     component - The component to be queried.
* @param[out]    value - The version of the fw component.
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  Error state request has been accepted.
* @retval        E_NOT_OK  Error state request has not been accepted.
*
* @pre           Llce firmware must be loaded.
*   
*/
Std_ReturnType Can_43_LLCE_GetControllerStatus( uint8 ControllerId, Llce_Can_GetStatusCmdType * StatusPtr);

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
void Can_43_LLCE_Init( const Can_43_LLCE_ConfigType * pxConfig);

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
void Can_43_LLCE_DeInit(void);

/*================================================================================================*/
/**
* @brief          Shut down LLCE
* @details        Send the shutdown command to LLCE.
*                 Can only be called if both HIFs are deinitialized. LLCE becomes unusable until reset.
*
* @param[in]      None
*
* @return         E_OK if command accepted, E_NOT_OK otherwise
*
*
* @pre            Both LLCE HIFs must be uninitialized 
* @post           LLCE is disabled
*
*/
Std_ReturnType Can_43_LLCE_Shutdown(void);

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
Std_ReturnType Can_43_LLCE_GetControllerMode( uint8 Controller, Can_ControllerStateType * ControllerModePtr);

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
void Can_43_LLCE_GetVersionInfo( Std_VersionInfoType * versioninfo);
#endif /* (CAN_43_LLCE_VERSION_INFO_API == STD_ON) */

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
Std_ReturnType Can_43_LLCE_SetBaudrate( uint8 Controller,
                                                       const uint16 BaudRateConfigID
                                                     );
#endif /* (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON) */

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
Std_ReturnType Can_43_LLCE_SetControllerMode( uint8 Controller,
                                                             Can_ControllerStateType Transition
                                                           );

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
void Can_43_LLCE_DisableControllerInterrupts( uint8 Controller);

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
void Can_43_LLCE_EnableControllerInterrupts( uint8 Controller);

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
Std_ReturnType Can_43_LLCE_Write( Can_HwHandleType Hth,
                                                 const Can_PduType * PduInfo
                                               );

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
* Compiler_Warning: This warning is thrown because it doesn't exist hardware support for Wakeup, and parameter "controller" it is not used.
*
* @implements     Can_CheckWakeup_Activity
*/
Std_ReturnType Can_43_LLCE_CheckWakeup( uint8 controller);

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
Std_ReturnType Can_43_LLCE_GetFwVersion( const uint8 ** pVersionString, \
                                                                                  uint8 * pStringLength);

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
Std_ReturnType Can_43_LLCE_SetFilter(const Can_SetFilterType * pCanFilter);

/*================================================================================================*/
/**
* @brief         This service set a single standard filter.
* @details       This service set a single standard filter.
*
* @param[in]     pCanFilter - parameter of Can_SetFilterType, containing filter type and message buffer related configuration data
* @param[in]     u16FilterAddr - address returned by the RemoveFilter function
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully set.
* @retval        E_NOT_OK  filter was not successfully set.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetFilter_Activity
*/
Std_ReturnType Can_43_LLCE_SetFilterAtAddress(const Can_SetFilterType * pCanFilter, const uint16 u16FilterAddr);

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
Std_ReturnType Can_43_LLCE_SetAfFilterAtAddress(const Can_SetAfFilterType * pAfFilter, const uint16 u16FilterAddr);

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
Std_ReturnType Can_43_LLCE_SetAfFilter(const Can_SetAfFilterType * pAfFilter);

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
Std_ReturnType Can_43_LLCE_CreateAfDestination(const Can_Af_DestRulesType destRule, uint8* pu8RuleIdx);

/*================================================================================================*/
/**
* @brief         This service removes an existing destination for advanced features
* @details       This service removes an existing destination for advanced features
*
* @param[in]     u8RuleIdx - The index of the destination to be removed from the LLCE list.
*
* @return        Std_ReturnType. Result of the request.
* @retval        E_OK  Destination removed
* @retval        E_NOT_OK  Error
*
* @pre           Llce firmware must be loaded and the controller initialized
*/
Std_ReturnType Can_43_LLCE_RemoveAfDestination(uint8 u8RuleIdx);

/*================================================================================================*/
/**
* @brief         This service removes a single standard filter.
* @details       This service removes a single standard filter.
*
* @param[in]     Hrh - HRH to which the filter is attached.
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully set.
* @retval        E_NOT_OK  filter was not successfully set.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_RemoveFilter_Activity
*/
Std_ReturnType Can_43_LLCE_RemoveFilter(Can_HwHandleType Hrh, uint16 *u16FilterAddr);

/*================================================================================================*/
/**
* @brief         This service enables or disables a single standard filter.
* @details       This service enables or disables a single standard filter.
*
* @param[in]     Hrh - HRH to which the filter is attached.
* @param[in]     Enabled - Logical value to select if filter is enabled or disabled
*
* @return        Std_ReturnType.  Result of the transition.
* @retval        E_OK  filter was successfully enabled/disabled.
* @retval        E_NOT_OK  filter was not successfully enabled/disabled.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetFilterState_Activity
*/
Std_ReturnType Can_43_LLCE_SetFilterState(Can_HwHandleType Hrh, Can_43_LLCE_FilterStateType eState);

/*================================================================================================*/
/**
* @brief         This service sets the state of controller in a multicast routing configuration.
* @details       
*
* @param[in]     ControllerId - hardware controller to be enabled or disabled.
* @param[in]     eChannelStatus - enable or disable channel
*
* @return        Std_ReturnType.  Result of the command.
* @retval        E_OK  channel was successfully enabled/disabled.
* @retval        E_NOT_OK  channel was not successfully enabled/disabled.
*
* @pre           Llce firmware must be loaded and the controller initialized
* @implements    Can_SetChannelRoutingOutputState_Activity
*/
Std_ReturnType Can_43_LLCE_SetChannelRoutingOutputState(uint8 ControllerId, Can_43_LLCE_ChannelStateType eChannelStatus);

/*================================================================================================*/
/**
* @brief         This service forces a deinit of the driver
* @details       When LLCE is not responding and must be reset, this service may be used to allow another init call. 
*
*/
void Can_43_LLCE_ForceDeInit(void);

/*================================================================================================*/

#if (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON)
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
void Can_43_LLCE_MainFunction_Multiple_Write( uint8 writepoll);
#endif /* (CAN_43_LLCE_TXPOLL_SUPPORTED == STD_ON) */

#if (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON)
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
void Can_43_LLCE_MainFunction_Multiple_Read( uint8 readpoll);
#endif /* (CAN_43_LLCE_RXPOLL_SUPPORTED == STD_ON) */

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
void Can_43_LLCE_MainFunction_ErrorNotification(void);
#endif /* (CAN_43_LLCE_ERRORNOTIFPOLL_SUPPORTED == STD_ON) */

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
Std_ReturnType Can_43_LLCE_AbortMb( Can_HwHandleType Hth);
#endif

#if (CAN_43_LLCE_API_MANUAL_BUSOFF_RECOVERY == STD_ON)
Std_ReturnType Can_43_LLCE_ManualBusOffRecovery( uint8 ControllerId );
#endif

/* Function used to read the ID of the core currently in use */
static inline uint32 Can_43_LLCE_GetCoreID(void)
{
    uint32 u32CoreId;

    #if (CAN_43_LLCE_MULTICORE_ENABLED == STD_ON) 
        u32CoreId = (uint32)OsIf_GetCoreID();

        /* Check if the CoreId is within range and send 0 if not */
        if(u32CoreId >= CAN_43_LLCE_MAX_PARTITIONS)
        {
            u32CoreId = 0U;
        }
    #else
        u32CoreId = (uint32)0U;
    #endif

    return u32CoreId;
}

/* Utility function to handle reading the global configuration */
static inline const Can_43_LLCE_ConfigType* Can_43_LLCE_GetCurrentConfig(void)
{
    const Can_43_LLCE_ConfigType* pxTempCurrentConfig;
    
    pxTempCurrentConfig = Can_43_LLCE_pCurrentConfig[Can_43_LLCE_GetCoreID()];
    
    return pxTempCurrentConfig;
}

#define CAN_43_LLCE_STOP_SEC_CODE
#include "Can_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CAN_43_LLCE_H */

/** @} */
