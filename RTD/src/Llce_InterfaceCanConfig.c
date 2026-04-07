/**
*   @file    Llce_InterfaceConfig.c
*
*   @version 1.0.0
*   @brief   LLCE defines used to configure the LLCE firmware and interface regarding FIFO usage.
*   @details LLCE  defines used to configure the LLCE firmware and interface regarding FIFOs. Those configuration parameters are used both by LLCE firmware and host software.
*
*
*   @addtogroup Llce_interface_configuration Configuration of FIFOs used as host interface.
*   @{
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


#ifdef __cplusplus
extern "C"
{
#endif
#ifndef __DOXYGEN__
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* This violation is due to the AUTOSAR requirement [SWS_BSW_00036] (perform inter module checks).
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* This rule does not apply if either identifier is a macro identifier, because this case is covered
* by Rule 5.4 and Rule 5.5.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The identifier clash is between macro identifiers. Therefore, this rule is incorrectly reported by the tool.
* 
*@section [global]
* Violates MISRA 2012 Advisory Rule 8.9, Objects shall be defined at block scope if they are only accessed from within a single function
* Some macros are used either in FW or driver, or provided as API
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 8.7, Functions and objects should not be defined with external linkage if they are referenced in only one translation unit.
* Some macros are used either in FW or driver, or provided as API
*
*/
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Llce_InterfaceCanConfig.h"
#include "Llce_InterfaceFifo.h"
#include "Llce_InterfaceMemLayoutCheck.h"
#include "Llce_InterfaceCanTypes.h"
#include "Llce_InterfaceCanUtils.h"

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
/** @brief    Configuration of FIFOs used for BLRIN role. 
 *  @details  It is used to configure which FIFOs are used to send indexes to full tx mb descriptors from host to LLCE.
 **/ 

const uint32 Llce_Can_u32BlrinBaseAddress[LLCE_CAN_CONFIG_MAXCTRL_COUNT] = {
    LLCE_FIFO_42_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO0*/
    LLCE_FIFO_43_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO1*/
    LLCE_FIFO_44_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO2*/
    LLCE_FIFO_45_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO3*/
    LLCE_FIFO_46_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO4*/
    LLCE_FIFO_47_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO5*/
    LLCE_FIFO_48_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO6*/
    LLCE_FIFO_49_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO7*/
    LLCE_FIFO_50_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO8*/
    LLCE_FIFO_51_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO9*/
    LLCE_FIFO_52_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO10*/
    LLCE_FIFO_53_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO11*/
    LLCE_FIFO_54_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO12*/
    LLCE_FIFO_55_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO13*/
    LLCE_FIFO_56_BASE_ADDRESS,  /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO14*/
    LLCE_FIFO_57_BASE_ADDRESS   /**< @brief   Base address of the hardware FIFO having the role of BLRINx FIFO15*/
    };
   

 /** @brief    Configuration of FIFOs used for RXOUT role. 
 *   @details  It is used to configure which FIFOs are used to send indexes to full rx mb descriptors from LLCE to host.
 **/  
const uint32 Llce_Can_u32RxoutBaseAddress[LLCE_CAN_CONFIG_MAXCTRL_COUNT + LLCE_CAN_MAX_POLLING_CLASSES] = {
    LLCE_FIFO_21_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO0*/
    LLCE_FIFO_22_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO1*/
    LLCE_FIFO_23_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO2*/
    LLCE_FIFO_24_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO3*/
    LLCE_FIFO_25_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO4*/
    LLCE_FIFO_26_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO5*/
    LLCE_FIFO_27_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO6*/
    LLCE_FIFO_28_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO7*/
    LLCE_FIFO_29_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO8*/
    LLCE_FIFO_30_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO9*/
    LLCE_FIFO_31_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO10*/
    LLCE_FIFO_32_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO11*/
    LLCE_FIFO_33_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO12*/
    LLCE_FIFO_34_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO13*/
    LLCE_FIFO_35_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO14*/
    LLCE_FIFO_36_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO15*/
    LLCE_FIFO_2_BASE_ADDRESS,    /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO16*/
    LLCE_FIFO_3_BASE_ADDRESS,    /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO17*/
    LLCE_FIFO_4_BASE_ADDRESS,    /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO18*/
    LLCE_FIFO_5_BASE_ADDRESS,    /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO19*/
    LLCE_FIFO_6_BASE_ADDRESS,    /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO20*/
    LLCE_FIFO_7_BASE_ADDRESS     /**< @brief   Base address of the hardware FIFO having the role of RXOUTx FIFO21*/
    };

/** @brief    Configuration of FIFOs used for either NOTIF_INTR or NOTIF_POLL role. 
 *  @details  It is used to configure for each host which FIFOs are used to send notifications from LLCE to host in interrupt mode.
 **/ 
const uint32 Llce_Can_u32NotifFifo0BaseAddress[LLCE_CAN_CONFIG_HIF_COUNT] = {
    LLCE_FIFO_0_BASE_ADDRESS,     /**< @brief   Base address of the hardware FIFO having the role of NOTIF_INTR FIFO for HIF0 */
    LLCE_FIFO_8_BASE_ADDRESS      /**< @brief   Base address of the hardware FIFO having the role of NOTIF_INTR FIFO for HIF1 */
    };

 /** @brief    Configuration of FIFOs used for either NOTIF_INTR or NOTIF_POLL role. 
 *   @details  It is used to configure for each host which FIFOs are used to send notifications from LLCE to host in polling mode.
 **/    
const uint32 Llce_Can_u32NotifFifo1BaseAddress[LLCE_CAN_CONFIG_HIF_COUNT] = {
    LLCE_FIFO_1_BASE_ADDRESS,     /**< @brief   Base address of the hardware FIFO having the role of NOTIF_POLL FIFO for HIF0 */
    LLCE_FIFO_9_BASE_ADDRESS,     /**< @brief   Base address of the hardware FIFO having the role of NOTIF_POLL FIFO for HIF1 */
    };    

/** @brief    Configuration of FIFOs used for TXACK role. 
 *  @details  It is used to configure which FIFOs are used to send tx confirmations from LLCE to host.
 **/ 
const uint32 Llce_Can_u32TxackBaseAddress[LLCE_CAN_RX_TX_INTERFACES] = {
    LLCE_FIFO_84_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK0 FIFO*/
    LLCE_FIFO_85_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK1 FIFO*/
    LLCE_FIFO_86_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK2 FIFO*/
    LLCE_FIFO_87_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK3 FIFO*/
    LLCE_FIFO_88_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK4 FIFO*/
    LLCE_FIFO_89_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK5 FIFO*/
    LLCE_FIFO_90_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK6 FIFO*/
    LLCE_FIFO_91_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK7 FIFO*/
    LLCE_FIFO_92_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK8 FIFO*/
    LLCE_FIFO_93_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK9 FIFO*/
    LLCE_FIFO_94_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK10 FIFO*/
    LLCE_FIFO_95_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK11 FIFO*/
    LLCE_FIFO_96_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK12 FIFO*/
    LLCE_FIFO_97_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK13 FIFO*/
    LLCE_FIFO_98_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK14 FIFO*/
    LLCE_FIFO_99_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK15 FIFO*/
    LLCE_FIFO_10_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK16 FIFO*/
    LLCE_FIFO_11_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK17 FIFO*/
    LLCE_FIFO_12_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK18 FIFO*/
    LLCE_FIFO_13_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK19 FIFO*/
    LLCE_FIFO_14_BASE_ADDRESS,   /**< @brief   Base address of the hardware FIFO having the role of TXACK20 FIFO*/
    LLCE_FIFO_15_BASE_ADDRESS    /**< @brief   Base address of the hardware FIFO having the role of TXACK21 FIFO*/
    };


/** @brief    Configuration of FIFOs used for BLROUT role. 
 *  @details  It is used to configure which FIFOs are used to send indexes to empty tx mb descriptors from LLCE to host.
 **/ 
const uint32 Llce_Can_u32BlroutBaseAddress[LLCE_CAN_CONFIG_MAXCTRL_COUNT] = {
    LLCE_FIFO_63_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT0 FIFO*/
    LLCE_FIFO_64_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT1 FIFO*/
    LLCE_FIFO_65_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT2 FIFO*/
    LLCE_FIFO_66_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT3 FIFO*/
    LLCE_FIFO_67_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT4 FIFO*/
    LLCE_FIFO_68_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT5 FIFO*/
    LLCE_FIFO_69_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT6 FIFO*/
    LLCE_FIFO_70_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT7 FIFO*/
    LLCE_FIFO_71_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT8 FIFO*/
    LLCE_FIFO_72_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT9 FIFO*/
    LLCE_FIFO_73_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT10 FIFO*/
    LLCE_FIFO_74_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT11 FIFO*/
    LLCE_FIFO_75_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT12 FIFO*/
    LLCE_FIFO_76_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT13 FIFO*/
    LLCE_FIFO_77_BASE_ADDRESS,      /**< @brief   Base address of the hardware FIFO having the role of BLROUT14 FIFO*/
    LLCE_FIFO_78_BASE_ADDRESS       /**< @brief   Base address of the hardware FIFO having the role of BLROUT15 FIFO*/
    };

/** @brief    Configuration of FIFOs used for RXIN role. 
 *  @details  It is used to configure for each host  which FIFOs are used to send indexes to empty rx mb descriptors from host to LLCE.
 **/   
const uint32 Llce_Can_u32RxinBaseAddress[LLCE_CAN_CONFIG_HIF_COUNT] = {
    LLCE_FIFO_16_BASE_ADDRESS,/**< @brief   Base address of the FIFO having the role of RXIN FIFO for HIF0*/
    LLCE_FIFO_18_BASE_ADDRESS /**< @brief   Base address of the FIFO having the role of RXIN FIFO for HIF1*/
    };

/** @brief    Configuration of FIFOs used for commands. 
 *  @details  It is used to configure which FIFOs are used to send commands from host to LLCE.
 **/ 
const uint32 Llce_Can_u32CmdBaseAddress[LLCE_CAN_CONFIG_HIF_COUNT] = {
    LLCE_FIFO_101_BASE_ADDRESS, /**< @brief   Base address of the CMD FIFO for HIF0   */
    LLCE_FIFO_102_BASE_ADDRESS  /**< @brief   Base address of the CMD FIFO for HIF1   */
    };



/** @brief    Configuration of FIFO used for logging interface. 
 *  @details  It is used to configure which FIFO is used to send indexes to full rx mb descriptors from logging host core  back to LLCE.
 **/ 
const uint32 Llce_Can_u32RxinLogBaseAddress[1] = {
    LLCE_FIFO_37_BASE_ADDRESS  /**< @brief   Base address of the RXINLOG FIFO. */
    }; 

    
/** @brief    Configuration of FIFO used for logging interface. 
 *  @details  It is used to configure which FIFO is used to send indexes to  full rx mb descriptors from LLCE to logging host core.
 **/  
const uint32 Llce_Can_u32RxoutLogBaseAddress[1] = {
    LLCE_FIFO_38_BASE_ADDRESS  /**< @brief   Base address of the RXOUTLOG FIFO. */
    };

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

/*================================================================================================*/


/**
* @brief          Disable FNEMPTY interrupt for TXACK and RXOUT fifos, thus disabling ACK and RX frames to be processed on interrupt.
* @details        Recommended API to disable FIFO interrupt for host processing
*
* @param[in]      u8FifoInterface Fifo interface mapped to the hw controller (1 to 1 default mapping).
* @param[in]      u8Hif Host Interface
*
* @return         void
*
*/
void DisableFifoInterrupts (uint8 u8FifoInterface, uint8 u8Hif)
{
    Llce_Sema42_Lock( Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, u8Hif), LLCE_HOST_CORE_SEMA42_DOMAIN);
    /* Disable RXOUT interrupt. */
    Reg_Bit_Clear32( LLCE_FIFO_IER(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8FifoInterface)), LLCE_FIFO_FNEMTY_U32);
    Llce_Sema42_Unlock( Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, u8Hif));


    Llce_Sema42_Lock( Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, u8Hif), LLCE_HOST_CORE_SEMA42_DOMAIN);
    /* Disable TXACK interrupt. */
    Reg_Bit_Clear32( LLCE_FIFO_IER(LLCE_FIFO_TXACK_BASE_ADDRESS(u8FifoInterface)), LLCE_FIFO_FNEMTY_U32);
    Llce_Sema42_Unlock( Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, u8Hif));

}


/**
* @brief          Enable FNEMPTY interrupt for TXACK and RXOUT fifos, thus enabling ACK and RX frames to be processed on interrupt.
* @details        Recommended API to enable FIFO interrupt for host processing
*
* @param[in]      u8FifoInterface Fifo interface mapped to the hw controller (1 to 1 default mapping).
* @param[in]      u8Hif Host Interface
*
* @return         void
*
*/
void EnableFifoInterrupts (uint8 u8FifoInterface, uint8 u8Hif)
{
    /* Clear all interrupt status flags. */
    Reg_Write32(LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8FifoInterface)), Reg_Read32(LLCE_FIFO_STATUS1(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8FifoInterface))));

    Llce_Sema42_Lock( Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, u8Hif), LLCE_HOST_CORE_SEMA42_DOMAIN);
    /* Enable needed interrupt. */
    Reg_Bit_Set32( LLCE_FIFO_IER(LLCE_FIFO_RXOUT_BASE_ADDRESS(u8FifoInterface)), LLCE_FIFO_FNEMTY_U32);
    Llce_Sema42_Unlock( Llce_GetSema42Gate(LLCE_FIFO_RXOUT_INDEX, u8Hif));

    /* Clear all interrupt status flags. */
    Reg_Write32(LLCE_FIFO_STATUS1(LLCE_FIFO_TXACK_BASE_ADDRESS(u8FifoInterface)),Reg_Read32(LLCE_FIFO_STATUS1(LLCE_FIFO_TXACK_BASE_ADDRESS(u8FifoInterface))));

    Llce_Sema42_Lock( Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, u8Hif), LLCE_HOST_CORE_SEMA42_DOMAIN);
    /* Enable needed interrupt. */
    Reg_Bit_Set32( LLCE_FIFO_IER(LLCE_FIFO_TXACK_BASE_ADDRESS(u8FifoInterface)), LLCE_FIFO_FNEMTY_U32);
    Llce_Sema42_Unlock( Llce_GetSema42Gate(LLCE_FIFO_TXACK_INDEX, u8Hif));

}



#ifdef __cplusplus
}
#endif

/** @} */

