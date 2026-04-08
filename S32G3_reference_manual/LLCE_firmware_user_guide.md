## UserGuide

for LLCEfirmware

Document Number: Rev1.0.11

| 1 LLCE firmware documentation . . . . . . . .                                                  |   2 |
|------------------------------------------------------------------------------------------------|-----|
| 1.1 Introduction . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .                 |   2 |
| 1.1.1 Changelog . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .      |   2 |
| 1.1.2 Release 1.0.11 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     |   2 |
| 1.1.3 Release 1.0.11 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     |   2 |
| 1.1.4 Release 1.0.9 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .      |   2 |
| 1.1.5 Release 1.0.8 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .      |   3 |
| 1.1.6 Release 1.0.7 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .      |   3 |
| 1.1.7 Release 1.0.6 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .      |   3 |
| 1.1.8 Release 1.0.5 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .      |   4 |
| 1.1.9 Release 1.0.4 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .      |   4 |
| 1.1.10 Release 1.0.3 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     |   5 |
| 1.1.11 Release 1.0.2 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     |   5 |
| 1.1.12 Release 1.0.1 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     |   5 |
| 1.2 LLCE features . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  |   6 |
| 1.3 LLCE CAN firmware . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .    |   8 |
| 1.3.1 LLCE CAN firmware architecture . . . . . . . . . . . . . . . . . . . . . . .             |   8 |
| 1.3.2 LLCE Internal CAN state machine . . . . . . . . . . . . . . . . . . . . . . .            |  10 |
| 1.3.3 LLCE CAN firmware interface . . . . . . . . . . . . . . . . . . . . . . . . .            |  11 |
| 1.3.4 Authentication of CAN and CAN FD frames using HSE services . . . . . .                   |  24 |
| 1.3.5 CAN traffic routing destinations . . . . . . . . . . . . . . . . . . . . . . . .         |  25 |
| 1.3.6 CAN to CAN internal routing . . . . . . . . . . . . . . . . . . . . . . . . . .          |  25 |
| 1.3.7 Ethernet communication . . . . . . . . . . . . . . . . . . . . . . . . . . . . .         |  27 |
| 1.3.8 PCIe routing . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .       |  30 |
| 1.3.9 Headless Mode . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .        |  31 |
| 1.3.10 Typical scenario regarding LLCE CAN firmware usage . . . . . . . . . . .                |  32 |
| 1.3.11 Usage of host IRQs for CAN firmware . . . . . . . . . . . . . . . . . . . .             |  38 |
| 1.3.12 Default routing of interrupt lines . . . . . . . . . . . . . . . . . . . . . . .        |  40 |
| 1.3.13 Settings needed on the host side before to start using LLCE CAN firmware                |  41 |
| 1.3.14 Shared memory layout . . . . . . . . . . . . . . . . . . . . . . . . . . . . .          |  41 |
| 1.3.15 Customizing the firmware . . . . . . . . . . . . . . . . . . . . . . . . . . .          |  42 |
| 1.3.16 CAN RxLut2 Interrupt Forwarding . . . . . . . . . . . . . . . . . . . . . .             |  43 |
| 1.3.17 Fault detection of LLCE cores Rx, Tx and Frpe . . . . . . . . . . . . . . .             |  43 |
| 1.3.18 Counters for reception and transmission . . . . . . . . . . . . . . . . . . .           |  44 |
| 1.4 LLCE priority inversion handling . . . . . . . . . . . . . . . . . . . . . . . . . . . .   |  48 |
| 1.5 LLCE LIN firmware . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .    |  48 |
| 1.5.1 LLCE LIN firmware architecture . . . . . . . . . . . . . . . . . . . . . . . .           |  48 |
| 1.5.2 LLCE LIN firmware interface . . . . . . . . . . . . . . . . . . . . . . . . . .          |  49 |
| 1.5.3 LIN Interrupt Forwarding . . . . . . . . . . . . . . . . . . . . . . . . . . . .         |  51 |
| 1.6 Flexray firmware . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . |  51 |

1.6.1 LLCE Flexray firmware architecture

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

.

51

| 1.7 SPI firmware . . . . . . . . . . . . . . . . . .   | . 52   |
|--------------------------------------------------------|--------|
| 1.7.1 SPI Interrupt Forwarding . . . . . . .           | . 52   |
| 1.8 Base addresses of the shared memory areas .        | . 53   |
| 1.9 Clocking . . . . . . . . . . . . . . . . . . . . . | . 54   |
| 1.10 Build options for the host applications . . .     | . 54   |
| 1.11 Recommendations for host application . . .        | . 55   |
| 1.11.1 Timestamp activation . . . . . . . . .          | . 55   |
| 1.12 Frequently asked questions . . . . . . . . . .    | . 55   |
| 1.13 External Assumptions . . . . . . . . . . . .      | . 56   |
| 2 Module Index                                         | 57     |
| 2.1 Software Specification . . . . . . . . . . . . .   | . 57   |
| 3 Module Documentation                                 | 58     |
| 3.1 LLCE CAN firmware interface . . . . . . . .        | . 58   |
| 3.1.1 Detailed Description . . . . . . . . . .         | . 58   |
| 3.1.2 Data Structure Documentation . . . .             | . 70   |
| 3.1.3 Macro Definition Documentation . . .             | . 98   |
| 3.1.4 Types Reference . . . . . . . . . . . .          | . 163  |
| 3.1.5 Enum Reference . . . . . . . . . . . .           | . 163  |
| 3.1.6 Variable Documentation . . . . . . . .           | . 173  |
| 3.2 LLCE precompile configuration parameters .         | . 175  |
| 3.2.1 Detailed Description . . . . . . . . . .         | . 175  |
| 3.2.2 Data Structure Documentation . . . .             | . 177  |
| 3.2.3 Macro Definition Documentation . . .             | . 177  |
| 3.2.4 Enum Reference . . . . . . . . . . . .           | . 184  |
| 3.2.5 Function Reference . . . . . . . . . . .         | . 190  |
| 3.3 LLCE LIN firmware interface . . . . . . . . .      | . 191  |
| 3.3.1 Detailed Description . . . . . . . . . .         | . 191  |
| 3.3.2 Data Structure Documentation . . . .             | . 192  |
| 3.3.3 Macro Definition Documentation . . .             | . 195  |
| 3.3.4 Enum Reference . . . . . . . . . . . .           | . 195  |
| 3.4 Platform types used by LLCE firmware . . .         | . 200  |
| 3.4.1 Detailed Description . . . . . . . . . .         | . 200  |
| 3.4.2 Types Reference . . . . . . . . . . . .          | . 200  |
| 3.5 LLCE headless mode . . . . . . . . . . . . . .     | . 202  |
| 3.5.1 Detailed Description . . . . . . . . . .         | . 202  |
| 3.5.2 Data Structure Documentation . . . .             | . 202  |
| 3.5.3 Macro Definition Documentation . . .             | . 202  |

1

## Chapter 1

## LLCE firmware documentation

## 1.1 Introduction

Low Latency Communication Engine(LLCE) firmware is intended to support CAN, LIN and FLEXRAY communication protocols. This document is focused on the software aspects and it will cover only the hardware topics which are needed in order to understand the firmware architecture. Both STANDARD and FDK package features are supported inside this document.

## 1.1.1 Changelog

## 1.1.2 Release 1.0.11

Features highlights:

- Added error feedback to headless boot
- Added IPv6 support for Can2Eth (UDP)

## 1.1.3 Release 1.0.11

Features highlights:

- Minor internal improvements

## 1.1.4 Release 1.0.9

Features highlights:

- Added a command to remove existing destination entries on the fly (at runtime) without stopping the reception, in order to replace them.

## 1.1.5 Release 1.0.8

Features highlights:

- Support HIF3 reset when CAN2ETH is enabled.

## 1.1.6 Release 1.0.7

Features highlights:

- Added set of Rx, Tx, Can2Can, Can2Eth, Eth2Can counters for every controller to monitor the number of messages that have been received or transmitted
- Added a command to initialize LLCE-PFE communication using ring buffers defined in system SRAM
- Added Can2Pcie and an option for other types of routing (Can2Other)
- Authentication of CAN and CAN FD frames using HSE services section updated. Keys shall be defined and uploaded into HSE by the host. Added capability to associate a key to a Rx filter
- Added a command to shut down LLCE in preparation for a reset.

Functional changes:

- Potential breaking change: Added an option for other types of routing (Can2Other). When setting an Advanced Filter, the new Can2Other fields must be initialized to a valid destination or LLCE\_CAN\_ADVANCED\_FILTER\_NOT\_USED to avoid unpredictable behavior.
- Added new destination for can2eth.
- uint8 u8Can2EthPhyIfList (bit list) converted to uint16 u16Can2EthPhyIfList in order to increase number of possible ethernet physical interfaces.

## 1.1.7 Release 1.0.6

Features highlights:

- FIFOs renamed in accordance with namings from R.M. (Reference Manual)
- Added a command to disable/enable Can2Can routing to a given channel
- Added a command to disable/enable Can2Eth routing entirely

## 1.1.8 Release 1.0.5

Features highlights:

- Added flexible allocation of CAN controllers to host interfaces in interrupt mode. The firmware can deliver frames to host through a configurable FIFO interface using datatypes: Llce\_Can\_ReceiveFilterType-&gt; u8Rx ← ↩ DestInterface/ Llce\_Can\_TxMbDescriptorType-&gt; u8AckInterface. This features allows grouping of any CAN controllers to the same HIF based on common FIFO interface selection.

Functional changes:

- replaced Can\_Sema4\_Ier (used for locking the access to common resource IER reg of FIFO) with Llce\_Get ← ↩ Sema42Gate function from Llce\_InterfaceCanUtils.h
- added Hif interface as input param for DisableFifoInterrupts/EnableFifoInterrupts

## 1.1.9 Release 1.0.4

Features highlights:

- (S32G3 only) Enabled the usage of second searching accelerator (12k entries), which provides a second search result for a message buffer based on the filters added using LLCE\_CAN\_CMD\_SETAUXFILTER command. If no AUXFILTER is set, no result is provided.
- Added Manual Bus-off Recovery command. See LLCE\_CAN\_CMD\_MANUAL\_BUSOFF\_RECOVERY. Both bus-off recovery modes (Automatic and Manual request) notify the LLCE\_ERROR\_BUSOFF to the host.
- Addition of extra formats for Can-Eth features: UDP and AVTP timestamp formats (TSCF header and ACF-CAN messages).
- Overhaul of underlying Can-Eth FW code.

Functional changes:

- START transition request returns LLCE\_FW\_SUCCESS when LLCE acknowledges the command. The synchronization status shall be monitored using LLCE\_CAN\_CMD\_GETCONTROLLERMODE command.
- Added specific Release version (REL\_LLCE) in the firmware image. It is returned by the LLCE\_CAN\_C ← ↩ MD\_GETFWVERSION. Check Table 1.1 in the firmware user guide.
- Added reporting option for Passive state and Tx/Rx warning state as independent category. This is a coarser error reporting category compared to the CAN Protocol bit level errors.
- u16MbFrameIdx was replaced with u16AuxSearchResult inside Llce\_Can\_RxMbDescriptorType structure. This is possible because there is now a one-to-one mapping between message buffers and descriptors. Using the descriptor popped from the FIFO interface, the host can retrieve u16FilterId and u16AuxSearchResult from the descriptor table and the message buffer from Mb tables. See Llce\_Can\_GetMbData function for retrieving the message buffer and its fields.

## 1.1.10 Release 1.0.3

Features highlights:

- Increased number of message buffers to 4096, using two pools of buffers of long and short payloads.
- Allowed advanced filters to be modified at runtime (SetAfFilter, CreateDestination, SetFilterEnableState, RemoveFilter).
- Allowed multiple interfaces for each Can2Eth destination, ability to use HIFs as well.

## 1.1.11 Release 1.0.2

Features highlights:

- Upgrade to PFE minidriver 0.0.1 (compatible with PFE\_MCAL\_094).
- Add support for transmission in FIFO mode.
- Add support for LIN interrupt forwarding.
- Added support for compile-time crosscheck of host interface binary map.

## 1.1.12 Release 1.0.1

Features highlights:

- S32CT support in S32DS NXP tool for all the drivers.
- Added mechanism for sending user-defined commands for customization in FDK. Commands are processed on Core 3 (FRPE).
- Added custom index in LLCE\_AF plugin, working as a constant mapping layer over the AUTOSAR defined HRH numbers.
- Added SPI interrupt forwarding from LLCE firmware to the host. This can be enabled by setting the last bit of the CORE2CORE module from HOST2RX (C1INTHR)
- Add user-defined callbacks for Write and Confirmation routines in CAN\_LLCE driver in order to help the user identify the MB and log it on the host side.
- Add user-defined callbacks for RX event on CAN\_DRIVER, when the filter is marked as custom. This helps in providing more parameters and allows customization without interfering with CanIf module.
- Added more flexible internal routing for changing the CAN format to CAN-FD where the destinations allow and for forcing the extended ID when remapping to a ID smaller than 0x7FF.
- Added support for auto bus-off recovery in CAN\_LLCE driver

## 1.2 LLCE features

## LLCE CAN firmware features:

- transmission and reception of CAN2.0 and CAN-FD frames
- supporting up to 16 CAN channels
- 320 KB of shared memory
- back-to-back transmission in order to prevent outer priority inversion
- arbitration support for maximum 16 transmission message buffers for each CAN controller
- allocation up to 16 transmission message buffers for each CAN controller
- allocation up to 16 transmission message buffers for each CAN controller used for direct CAN-to-CAN routing
- allocation up to 2396 reception message buffers for each reception filter
- support for up to 4096 reception message buffers, including 1700 buffers of 64 bytes size and 2396 buffers of 8 bytes size.
- support for 512 acknowledgement buffers
- flexible allocation of the reception buffers and the acknowledgement buffers along all the 16 channels
- servicing of the received frames on the host side by using 22 independent paths
- servicing of the received transmission confirmations on the host side by using 22 independent paths
- supporting internal routing for CAN/CAN-FD protocols. CANFD to CAN internal routing is available only for frames having the payload length less than or equal to 8 bytes
- frame id remapping for the CAN2CAN internal routing
- supporting internal routing from CAN to Ethernet
- deliver the received frames to multiple destinations(other CAN controllers through internal CAN routing, Ethernet through PFE (Packet Forwarding Engine) subsystem)
- disable filter entries on the fly for frames delivered by the host
- configure new filter entries on the fly (at runtime) without stopping the reception
- replace existing destination entries on the fly (at runtime) without stopping the reception
- reception validated throughput is 150000 CAN frames/second
- transmission validated throughput is 200000 CAN frames/second

Moreover, depending on the platform:

- LLCE on S32G2 platform:
- -support for 512 mask or range filters for reception
- -support for 512 exact match filters for reception
- -4 Mbps maximum baudrate supported across all the 16 channels

- LLCE on S32G3 platform:
- -support for 4096 mask filters for reception (can be used as either exact match, mask or range)
- -low receive latency due to filtering started when CAN ID is available from the bus and capability to decode it internally
- -5 Mbps maximum baudrate supported across all the 16 channels

## LLCE CAN firmware features available only in the FDK package:

- deliver the received frames to extra destinations(a logging core, HSE (Hardware Security Engine) for frame authentication)
- logging frames to a specific logging core
- supporting authentication of the received CAN or CAN FD frames by using AES-CMAC algorithm based on Hardware Security Engine(HSE) services
- supporting generation and adding of AES-CMAC codes to the transmitted CAN or CAN FD frames using Hardware Security Engine(HSE) services
- firmware source code and flexibility for customization

Moreover, depending on the platform:

- LLCE on S32G2 platform:
- -(8,32,32,64) KB of private programmable memory for (Core 0 - DTE, Core 1 - RxPPE, Core 2 - TxPPE, Core 3 - FRPE) cores.
- LLCE on S32G3 platform:
- -access to a 2nd instance of filtering accelerator with 12k entries (can be used as either exact match, mask or range) and its own memory, usable for custom processing
- -(16,96,32,256) KB of private programmable memory for (Core 0 - DTE, Core 1 - RxPPE, Core 2 - TxPPE, Core 3 - FRPE) cores.

## LLCE CAN firmware limitations:

- Remote Transmission Request(RTR) frames are not supported

## LLCE LIN firmware features:

- transmission of LIN master headers and master responses
- reception of LIN slave response
- master to slave and slave to slave communication
- configurability of up to 4 Master or 4 Slave nodes

## LLCE SPI features:

## LLCE firmware documentation

- forward interrupts from SPI modules to host through CORE2CORE module.

Setting of bit 0 of CORE2CORE module from host to Core 1 (RXPPE) enables interrupt forwarding (C1INTHR). LLCE Firmware will clear the bit after the command has been processed.

LLCE Flexray features:

- forward interrupts related to Protocol Flag event from Flexray controller to host.

The functionality of LLCE firmware is divided among various software modules running on 4 different M0+ cores. Each of them implements specific task(s) belonging to one of covered communication protocols: CAN, LIN or FLE ← ↩ XRAY. The behavior of firmware servicing CAN, LIN or Flexray protocols are fully independent. Also the firmware interface for each of the protocols is independent and use different hardware components. Anyway, even the behavior of firmware for CAN, LIN and Flexray protocols is fully separated for each protocol, all the source files are compiled together and a single firmware image is generated and loaded for all protocols.

Figure 1.1 LLCE firmware architecture - high level view.

<!-- image -->

The following sections describes the LLCE functionality focusing on the LLCE interface in order to allow development of software components running on the host side.

## 1.3 LLCE CAN firmware

## 1.3.1 LLCE CAN firmware architecture

As it is presented in the picture from below, the LLCE CAN firmware is distributed and runs on 4 identical M0+ cores. Each core has a name and a specific role:

- Core 0 - Data Transfer Engine(DTE) transfer frame chunks of 32bits between shared memory and the FIFOs of the BCAN controller.
- Core 1 - Reception Protocol Processing Engine(RX PPE) has the following roles:
1. implements the configuration operations delegated by the TX PPE core
2. implements the reception flow
3. implements part of the CAN2CAN routing feature
4. error reporting
- Core 2 - Transmission Protocol Processing Engine(TX PPE) has the following roles:
1. implements configuration interface with the host
2. implements the transmission flow
3. implements part of the CAN to CAN routing feature
4. error reporting
- Core 3 - FRPE core is used to implement:
1. advanced feature CAN2ETH internal routing
2. frame authentication using Hardware Security Engine(HSE) support
3. customer specific use cases

Interface of the LLCE CAN firmware with the outside world is implemented by using the following hardware modules:

- Hardware FIFOs used for transmission/reception flows and for configuration/status reporting. Specific FIFOs are used to transfer indexes of message buffers between host cores and LLCE internal cores. Other FIFOs are used to transfer commands/notification codes between host cores and LLCE CORE 2 (TxPPE).
- Shared memory used for exchanging commands, error/status code and message buffer contents. This memory is accessible by all internal LLCE cores and also by the host cores.

In order to decrease the number of memory copy operations needed for message buffers, it was implemented a software architecture based on transferring indexes to the message buffers between LLCE and host cores. Transfer of message buffer indexes between cores is done by using the hardware FIFOs. The content of the message buffers is stored only once into the shared memory during the entire processing flow and is accessed in an efficient way by the host cores and LLCE module.

## LLCECANFIRMWAREARCHITECTURE-INTERNALDETAILS

Figure 1.2 LLCE CAN firmware architecture.

<!-- image -->

## 1.3.2 LLCE Internal CAN state machine

Figure 1.3 LLCE CAN firmware internal state machine.

<!-- image -->

## 1.3.3 LLCE CAN firmware interface

Host software interacts with the CAN firmware by using different hardware resources based on the requested behavior or operation. The CAN firmware interface can be divided into multiple independent components:

1. Start up interface
2. Configuration interface
3. Receive interface
4. Transmit interface
5. Acknowledgement interface
6. Notification interface
7. Logging interface

The memory shared between host and LLCE CAN firmware shall be accessed by using the data type Llce\_Can\_SharedMemoryType .

## 1.3.3.1 Start up interface

It is the very first interface the user can interact with immediately after loading the firmware image. The host shall initialize each core's flag in Llce\_Mgr\_StatusType structure to LLCE\_FW\_NOT\_RUN, start the cores and poll the flags waiting for each core to boot and write LLCE\_FW\_SUCCESS in their own variable. Only after that, the host can consider the boot phase finished. In case of a failure during booting phase, the boot variable will be updated with an error code. In case of adding new values in Llce\_Fw\_ReturnType enumeration, make sure both the firmware and the host application is recompiled.

## 1.3.3.2 Configuration interface

It is used by the host software to configure the LLCE CAN firmware functionalities. It is enabled by default when the LLCE firmware start to run. Configuration interface is composed of:

- 2 shared memory areas mapped 1:1 to each Host. Every shared memory area is used to transfer commands and parameters regarding a specific host core to LLCE. Every command area is accessed through an union data type, which streamlines the memory used.
- 1(one) CMD FIFO for each host core. CMD FIFO is used to trigger LLCE firmware in order to process a specific command. Every host core which needs to configure LLCE CAN firmware shall use exclusively its own CMD FIFO. The CMD FIFO can have maximum 1 entry at a time, meaning that the host must wait for LLCE to finish the command processing for the targeted controller. The host detects the end of the command execution by waiting for the 'non-empty' flag of the CMD FIFO to be cleared by LLCE firmware. Afterwards, the host reads the command return status which is a specific error code or 'success'.

The configuration and status report is done by using several commands. The list of available commands exchanged between host and LLCE are enumerated below:

1. INIT - initialize a specific CAN channel. See Llce\_Can\_InitCmdType for more details about command parameters.
2. SETBAUDRATE - change the parameters related to the nominal and data baud rate for a specific CAN controller. See Llce\_Can\_SetBaudrateCmdType for more details about command parameters. There are 2 things to consider when configuring the BCAN controllers of LLCE subsystem:

Note

Controller Prescaller and Controller Prescaller FD should have the same value to minimize the errors. The sample point should ideally be around 75-85%

3. SETCONTROLLERMODE-start or stop a specific CAN controller. See Llce\_Can\_SetControllerModeCmdTyp for more details about command parameters. Note

After a SETCONTROLLERMODE command requested for START transition, the driver must issue GETCONTROLLERMODE command repeatedly until the firmware confirms the transition finalized.

4. GETCONTROLLERMODE - read from the LLCE the state of a specific CAN controller. See Llce\_Can\_GetControllerModeCmdType for more details about command parameters.
5. GETSTATUS -get the content of all status registers of a specific CAN controller. See Llce\_Can\_GetStatusCmdType for more details about command parameters.
6. SET\_FILTER - configure one or multiple reception filters for a specific CAN channel. It returns to host application the address of the configured filters in order to be used later if needed. See Llce\_Can\_SetFilterCmdType for more details about command parameters.

Overlapping filters will result in undefined behavior.

7. SETFILTER\_AT\_ADDRESS - configure a filter at a specific address which was either previously removed by the REMOVE\_FILTER command or an address which was intentionally left empty in the configuration for later filter additions.
8. SET\_ADVANCED\_FILTER - configure one or multiple filters for a specific CAN channel used for advanced firmware features like CAN2CAN internal routing, logging, CAN2ETH internal routing, etc. It returns to host application the address of the configured filters in order to be used later if needed. See Llce\_Can\_SetAdvancedFilterCmdType and its sub-structures for more details about command parameters.

Note

Note

Overlapping filters will result in undefined behavior.

9. (S32G3 only): SET\_AUXFILTER - This features enables the configuration of a granular filter on top of a regular filter. The regular filter is set to a coarse range, and the AUXFILTER allows for a more specific filtering within the regular filter range. See Llce\_Can\_SetAuxFilterCmdType and its sub-structures for more details about command parameters. These filters depend on the standard filters configured and the results will only get delivered when the standard filters have accepted the frames.
10. GET\_FWVERSION - get the firmware version.See Llce\_Can\_GetFwVersionType and its substructures for more details about command parameters.

Note

The string stored in the Llce\_Can\_GetFwVersionType:

Table 1.1 GetFwVersion returned data

| Data       |   Number of bytes |   Offset (bytes) | Content                           |
|------------|-------------------|------------------|-----------------------------------|
| Version    |                 8 |                0 | Interface (1 byte)                |
| Version    |                 8 |                0 | Basic_func (1 byte)               |
| Version    |                 8 |                0 | Routing CAN2CAN (1 byte)          |
| Version    |                 8 |                0 | Routing CAN2ETH (1 byte)          |
| Version    |                 8 |                0 | Logging (1 byte)                  |
| Version    |                 8 |                0 | Target Chip (1 byte)              |
| Version    |                 8 |                0 | LIN (1 byte)                      |
| Version    |                 8 |                0 | Routing CAN2PCIE (1 byte)         |
| Release ID |                17 |                8 | REL_LLCE                          |
| Release ID |                17 |                8 | Release version (9 bytes)         |
| Build ID   |                18 |               25 | BLD_                              |
| Build ID   |                18 |               25 | Developer ID                      |
| Build ID   |                18 |               25 | Build time (y/m/d/H/M) (10 bytes) |

There are two more ways to retrieve the firmware version:

- (b) Reading the elf file ( readelf batch command): readelf -p.version\_info ppe\_rx.elf
- (a) Reading the structure Llce\_Mgr\_Status.LlceFwVersion .
11. DEINIT - de-initialize a specific CAN controller. There are no command parameters.
12. INIT\_PLATFORM - initialize platform related parameters which are used by all BCAN controllers.See Llce\_Can\_InitPlatformCmdType for more details about command parameters. This command shall be executed only once by a host core on behalf of channel #LLCE\_CAN\_CONFIG\_DEFAULT\_CA ← ↩ N\_CTRL\_U8.
13. DEINIT\_PLATFORM - de-initialize platform related parameters which are used by all BCAN controllers. This command shall be executed only once by a host core on behalf of controller #LLCE\_CAN\_CON ← ↩ FIG\_DEFAULT\_CAN\_CTRL\_U8.
14. INIT\_PFE -get addresses of the memory used to interface with PFE hw module. See Llce\_Can\_InitPfeCmdType for more details about command parameters.
15. REMOVE\_FILTER - remove a specific existing filter in order to not be used anymore by filtering process. The entry released by the disabled filter can be used to configure other different filter by using SET\_FILTER, SETFILTER\_AT\_ADDRESS or SET\_ADVANCED\_FILTER commands. See Llce\_Can\_ChangeFilterType for more details about command parameters.

## LLCE firmware documentation

16. SETFILTERENABLESTATUS - disable or re-enable a specific existing filter, given by its address. u8FilterEnabled = 0 = &gt; Disable the filter. The filter entry is kept configured, but the RX lookup will skip it during the filtering.

u8FilterEnabled = 1 = &gt; Re-enable the filter. The RX lookup will consider it during the filtering. See Llce\_Can\_ChangeFilterType for more details about command parameters.

17. CREATE\_AF\_DESTINATION - create a new destination rule to be used for frames which are accepted by specific filters. Those rules are used by the advanced features in order to deliver received frames to other destinations than standard host(can2can, can2eth, logging, etc.) This command return a rule id which shall be used by command SET\_ADVANCED\_FILTER. See Llce\_Can\_CreateAfDestination for more details about command parameters.
18. LLCE\_CAN\_CMD\_ABORT\_MB - aborts of the lowest priority pending transmission of a specific CAN controller. The host could specify through the command structure Llce\_Can\_AbortMbType if one or all pending transmissions should be discarded. The effect is that one or more tranmission message buffers will be immediately freed.
19. LLCE\_CAN\_CMD\_INIT\_PFE-activates the LLCE-PFE interface. See Llce\_Can\_InitPfeCmdType for more details about command parameters.
20. LLCE\_CAN\_CMD\_INIT\_PFE\_EXT\_RING\_BUF - activates the LLCE-PFE interface using external rings. Rings are structures for management of communication between LLCE and PFE. The default memory where rings are defined is LLCE memory, while the external ones are defined in system SR ← ↩ AM. The purpose of using external rings is to reduce latency by 20% based on our profiling, by freeing significant kB of memory. See Llce\_Can\_InitPfeWithExternRingCmdType for more details about command parameters.
21. LLCE\_CAN\_CMD\_INIT\_HSE - activates HSE cryptographic services inside LLCE related to CMAC generation and verification. See configuration parameters inside Llce\_Can\_TxMbDescriptorType for the transmission flow and inside Llce\_Can\_AdvancedFilterType Llce\_Can\_AdvancedFeatureType for the reception flow. This command shall be executed before any cryptographic service to be used by the LLCE firmware.
22. LLCE\_CAN\_CMD\_MANUAL\_BUSOFF\_RECOVERY - manually request for recovering from busoff confinement state without dropping outstanding transmissions. For this to be accepted, the INIT command must specify LLCE\_CAN\_CMD\_MANUAL\_BUSOFF\_RECOVERY option per controller. This command doesn't need extra arguments to be provided.
23. LLCE\_CAN\_CMD\_SETCHANNELROUTINGOUTPUTSTATE - enables or disables a channel in a routing multicast configuration.
24. LLCE\_CAN\_CMD\_SETCAN2ETHSTATE - enables or disables Can2Eth routing entirely
25. LLCE\_CAN\_CMD\_REMOVE\_AF\_DESTINATION-removes an existing destination rule. Those rules are used by the advanced features in order to deliver received frames to other destinations than the standard hosts (can2can, can2eth, can2pcie). The buffers of the destinations are not cleared upon removal, but will be overwritten if the host adds a new destination. See Llce\_Can\_RemoveAfDestination for more details about command parameters.

Figure 1.4 Configuration interface for LLCE CAN firmware.

<!-- image -->

The steps done by a host core to send a command to LLCE CAN firmware are:

1. Write command ID and command parameters as they are defined by Llce\_Can\_CommandType into the shared memory allocated to that Host core.
2. Write the channel ID into the host's CMD FIFO.
3. Check in polling way(busy waiting) if the NOT\_EMPTY interrupt flag of the CMD FIFO is cleared by the firmware in order to detect the completion of the command processing by the LLCE firmware.
4. Read the command completion status having type Llce\_Fw\_ReturnType

## Limitations to be considered:

1. When working in a multi-threaded environment, the application should take care to send a single command at a time. (i.e. the check for Empty Fifo and Push a new command index should be done atomically).
2. When using multiple hosts at the same time, each host should be aware of the other host, in the sense that the timeouts shall be increased when waiting for LLCE firmware to finish a command.
3. For mutihost configuration in interrupt mode, the controllers assigned to a particular HIF must belong to the same interface group (0-7 or 8-15). If a configuration different than controllers 0-7 to one HIF and controllers 8-15 to the other HIF is needed, the FIFO\_INTERFACE field should be overwritten so that it lays in the mentioned ranges. For the polling processing, the fifos corresponding to polling classes (fifos 16-21) can be shared across the multiple hosts where each of them should be aware of the polling classes' allocation of the other host.

## LLCE firmware documentation

4. Regarding the order of filters in configuration, for G2 , first 512 filters are exact match filters, next 512 are configurable. Overlapping filters shall ideally not exist, otherwise the matching filter might not be the one expected. The matching filter is always the one with the lowest address, thus an exact match will match before a configurable (mask/range) one, no matter the order of filters defined in configuration. In case of multiple overlapping configurable filters, the first one that matches is the one that was first passed to LLCE firmware. For G3 , all filters are configurable, the matching filter is always the one with the lowest address.
5. The number of message buffers are split in 1700 buffers of 64B and 2396 of 8B. The short buffers cannot be assigned to advanced filters (filters with advanced references). They work only for simple receive communication (both FD or STD CAN).

Possible causes for a command to fail, example for LLCE\_CAN\_CMD\_SETADVANCEDFILTER :

1. CMD flow is not correctly followed by the application. The error raised in this case is LLCE\_ERROR\_CO ← ↩ MMAND\_NOTACCEPTED
2. CMD params are invalid. e.g. hwctrl sent using the CMD fifo is not in range (0-15), the number of filters exceeds the maximum number preallocated at LLCE\_CAN\_CMD\_INIT\_PLATFORM command etc. In all these cases, LLCE firmware raises LLCE\_ERROR\_COMMAND\_INVALID\_PARAMS error.
3. CMD is not supported when the application doesn't use the values from Llce\_Can\_CommandIdType enum, or due to the fact the LLCE fw is not fully-feature compiled. The standard firmware doesn't support setting of filters which are configured to authenticate frames using HSE services and filters configured to report frames to a logging core. If a single filter in the entire command definition is not supported (due to the fw version), the command is rejected with LLCE\_ERROR\_COMMAND\_NOTSUPPORTED error.

## 1.3.3.3 Notification interface

Note

In case of multiple hosts use-case, each of them is assigned to a separate notification interface and it can configure independently which errors to be notified about.

It is used by the host software to service the notification events sent by the LLCE firmware to the host core(e.g. BUS OFF, CAN protocol errors, configuration errors, runtime errors). It is composed of:

- 2 hardware FIFOs for each host core having a capacity of 16 entries each one. Those 2 FIFOS are used to send from LLCE to host indexes into 2 different tables containing notification parameters. The FIFOs are named generically NOTIF\_FIFO0 and NOTIF\_FIFO1. They are intended to be used one in interrupt (urgent notifications) and one in polling (not urgent notifications), but their role is set by the host by enabling/disabling the FIFO interrupt in either way, including more sophisticated ways (e.g. watermark interrupt) A number of 5 notification categories can be independently configured at INIT\_PLATFORM command: CAN Protocol notification, Configuration errors, Internal runtime errors, DATA\_LOST error and Bus off notification. Of all these, only the bus off notification is selectable per channel.
- 1 shared memory area containing 2 identical tables for each host mapped 1:1 with the 2 hardware FIFO from above. Every table in the shared memory area is used to transfer notification parameters corresponding to the categories mentioned above. For more details regarding the structure of the 2 notification tables see Llce\_Can\_NotificationTableType.

Bus-off behavior is configurable at interface level. Hence, the user has the following exclusive options:

- the default method, which brings the controller into STOP state, flushes the outstanding Tx transfers, rejects any new transmission request by flushing the TX indexes and automatically freezes the peripheral as soon as the outgoing transaction finishes. This is the approach followed by AutoSar CAN\_LLCE driver. In order to participate at the bus transactions the CAN controller shall be started again by using the SETCONTROLL ← ↩ ERMODE command. The notification sent by LLCE is LLCE\_ERROR\_BUSOFF and is sent only after the controller completely freezes.
- the auto-recovery method ( see LLCE\_CAN\_CONTROLLERCONFIG\_ABR\_EN\_U32), which doesn't flush the outstanding Tx transfers, accepts and stores new TX requests from host and recovers the controller as quick as possible. In this case, LLCE notifies the host as soon as bus-off is detected using LLCE\_ERROR\_BUS ← ↩ OFF. As soon as the controller is ready to leave the bus-off state (128 occurrences of 11 recessive bits), LLCE notifies the host using the LLCE\_NOTIF\_BUSOFF\_DONE notification. If the user requests a transition into STOP state for the controller, the LLCE\_NOTIF\_BUSOFF\_DONE notification won't be issued until the user requests a transition to START state and 128 occurrences of 11 recessive bits have passed.
- the manual-recovery method ( see LLCE\_CAN\_CONTROLLERCONFIG\_MBR\_EN\_U32), which doesn't flush the outstanding Tx transfers, accepts and stores new TX requests from host, notifies the host as soon as bus-off is detected using LLCE\_ERROR\_BUSOFF, and exposes a new command ( see LLCE\_CAN\_CMD\_MANUAL\_BUSOFF\_RECOVERY) which let the user manually request the recovery from bus-off confinement state. This method might be useful when the offending condition persists on the bus and recovering automatically will generate new bus-off events frequently.

Figure 1.5 Notification interface for LLCE CAN firmware - interrupt mode.

<!-- image -->

The steps done by the host software in order to process a notification event configured to be serviced in INTERRUPT mode (considering one of the NOTIF FIFOs has interrupts enabled):

1. Read the next entry from the NOTIF\_INTR FIFO inside host ISR servicing NOT\_EMPTY event.

## LLCE firmware documentation

2. Use the previous read entry value in order to access the notification parameters from the corresponding table as they are defined by Llce\_Can\_NotificationTableType and process the notification event.
3. Clear the interrupt status flag NOT\_EMPTY of the NOTIF\_INTR FIFO.

Figure 1.6 Notification interface for LLCE CAN firmware - polling mode.

<!-- image -->

The steps done by the host software in order to process a notification event configured to be serviced in POLLING mode (considering one of the NOTIF FIFOs has interrupts disabled):

1. Read an entry from the NOTIF\_POLL FIFO. It is the responsibility of the host software to prevent that fifo NOTIF\_POLL FIFO to become full by checking periodically in polling mode.
2. Use the previous read entry value in order to access the notification parameters from the corresponding table as they are defined by Llce\_Can\_NotificationTableType and then process the notification event.

For each of the mentioned error categories, the user can choose to ignore the notifications from that category, or to report it through one of the 2 fifos. The configuration errors category is a redundant way of checking the eventual errors because the return status of each issued command already contains the error code. The asynchronous reporting of configuration errors might make sense only in certain use cases (e.g. keeping a log of the errors in the notif table), otherwise it is advisable to configure this category as ignore. It is highly recommended to set only the bus-off and protocol warnings as interrupts, the rest of them being either ignored or set to polling, if the user intends to check them as well. If all errors are set to interrupts, there is a high chance that overflow will occur and bus-off will be lost. Protocol errors are not recommended to be configured as interrupt, as the number of potential triggers (e.g., multiple bit errors) is very high and could cause overflow of the FIFO, leading to loss of other potentially critical errors, such as buss-off.

## 1.3.3.4 Reception interface

It is used by the host software to get received CAN frames from the LLCE firmware. The implemented method use a ring model based on hw FIFOs in order to allow host to get full reception buffers from LLCE and send them back to LLCE after consuming them. The hardware FIFOs exchange indexes (tokens) to message buffers. These indexes must not be lost in the process, otherwise the system will decrease the number of usable message buffers at a time. The indexes are used by pointing to a memory address in the Llce\_Can\_RxMbDescriptorType and Llce\_Can\_MbType data structures.

Reception interface is composed of:

- 2 shared memory areas containing the reception descriptor table, respectively CAN message buffer table.
- 22 RXOUT FIFOs mapped to specific filters during configuration phase as it is described by Llce\_Can\_SetFilterCmdType and Llce\_Can\_SetAdvancedFilterCmdType . Each RXOUT FI ← ↩ FO contains indexes into the reception descriptor table which includes a reference to the full reception message buffer. Each RXOUT FIFO will support delivery to host of received frames only for the configured filters. This frame delivery approach is very flexible in the sense that it allows host user to process received frames by grouping them based on defined filter criteria.
- 1(one) RXIN FIFO for each host core. The RXIN fifo is used to send back to LLCE all indexes of the reception descriptor table consumed by the host in order to be reused. Every host core use exclusively its own RXIN FIFO.

Figure 1.7 Reception interface for LLCE CAN firmware.

<!-- image -->

The steps done by the host software in order to receive a CAN frame from LLCE are:

1. Read an index to a full receive descriptor from an RXOUT FIFO as it defined by the filter configuration. This operation can be done in poling or in interrupt mode by the host user. Be aware that the read value shall be masked with the configured value because the width of the FIFO is 19 bits.

## LLCE firmware documentation

2. Read the reception descriptor content as it is defined by Llce\_Can\_RxMbDescriptorType and extract the reference to the full reception message buffer.
3. Read the content of the full reception message buffer as it is defined by Llce\_Can\_MbType and process it.
4. Write the index of the receive descriptor to the unique RXIN FIFO for that host in order to send it back to the LLCE to be reused.

During reception process the frames are reported as accepted by the first filter which matches the frame id. The search operation start from low filter addresses and continue to the high addresses. During filter configuration the filter address is returned to the host side for tracking.

It is the responsibility of the host user to define filters without overlapping values in order to prevent that some filters to be never reported as receiving filters.

The correlation between the number of FIFOs (22) and the number of physical channels (16) is predetermined by the processing way the host can choose. The flexibility level of each controller with regards to the processing method is as follows: the host can configure, for any channel, filters whose frames are delivered by LLCE firmware on a configurable hardware FIFO. Thus, the host can apply for a channel multiple filters, each of them reporting the message buffer indexes through a different FIFO. This way, by enabling the interrupts on a FIFO but keeping them disabled on another FIFO for the same channel, the interrupt processing is called mixed. Another thing the host can do is to group the frames from different filters, belonging to different controllers, into the same interface fifo, based on certain criteria. The number of 22 independent paths (See Llce\_Can\_u32TxackBaseAddress for their base addresses) are organized as follows:

1. First 16 FIFOS (0-15) are split into 2 groups of 8 FIFO. Each group has a single interrupt line which is routed towards the host. Any FIFO of the group can trigger the interrupt to the host, which needs to figure out which of the 8 FIFOs has actually the corresponding interrupt flag enabled. Therefore, the recommendation is to map the first 16 FIFOs to the same number of channels only for interrupt processing. When the FIFO RXOUT 'n' becomes not empty and triggers an interrupt, the host will know there is a frame received by CAN channel 'n'. The host will process the interrupt FIFO events as follows: Pop the elements from FIFO and clear the interrupt flag. The FIFO must be empty and then the flag cleared, otherwise the interrupt will trigger again until all the elements in FIFO are exhausted.
2. The rest of FIFOs (16-21) are part of a group whose interrupt line is intended to be used for another service. Therefore, the recommendation is to keep the interrupt disabled for these fifos and to use them as polling classes. The host can configure filters with the receive interface set to one of these 6 FIFOs, which can be shared across all of the channels. In this case, the host can figure out which channel actually delivered the message by looking at the filterID which accepted the message (written by LLCE firmware in the descriptor table, See Llce\_Can\_RxMbDescriptorType ) and map it to the channel to which it was applied.

The IER (interrupt enable register) of any FIFO shall be manipulated (for enabling/disabling the host interrupts) using the recommended API DisableFifoInterrupts(interface) and EnableFifoInterrupts(interface) available in LLCE interface source files. In case of first FIFO group (0-15), the interface argument is the same as the controller. For the second group (16-21) the interface is the actual FIFO number from the group (16-21).

If these APIs are not used, care shall be taken to lock and unlock Sema4 gates LLCE\_FIFO\_RXOUT\_INDEX and LLCE\_FIFO\_TXACK\_INDEX before and after manipulating the IER register, respectively. This is required in order to avoid a race condition with the Firmware.

## 1.3.3.5 Transmission interface

It is used by the host software to transmit CAN frames to the LLCE firmware. For transmitting frames it is used a ring model based on hw FIFOs in order to allow host to get empty transmission message buffers from LLCE and send them back to LLCE after filling them with a new frame. For getting tx confirmation from LLCE it is used a more simple way based on FIFO model. It is composed of:

- 3 shared memory areas containing the transmission descriptor table, CAN message buffer table, acknowledge information table.
- 16 BLROUT FIFOs mapped 1:1 to each CAN channel (LLCE\_FIFO\_70\_63, LLCE\_FIFO\_78\_71) . The FIFO of each CAN channel transfers indexes to empty entries into the transmission descriptor table from LLCE to host.
- 16 BLRIN FIFOs mapped 1:1 to each CAN channel (LLCE\_FIFO\_49\_42, LLCE\_FIFO\_57\_50). The FIFO of each CAN channel transfers indexes to full entries into the transmission descriptor table from host to LLCE.
- 22 TXACK FIFOs mapped to a specific frame according the transmission request described by Llce\_Can\_TxMbDescriptorType (LLCE\_FIFO\_91\_84, LLCE\_FIFO\_99\_92, LLCE\_FIFO\_103\_ ← ↩ 100, LLCE\_FIFO\_104). Each TXACK fifo will deliver to host the ack information based on the configuration defined by the host application in the transmission request structure of each frame. The TXACK FIFO transfers indexes to full entries into the acknowledge information table from LLCE to host. This ack delivery approach is very flexible in the sense that the host user can decide how to service groups of tx confirmations.

Figure 1.8 Transmission interface for LLCE CAN firmware.

<!-- image -->

The steps done by the host software in order to transmit a CAN frame to LLCE and get confirmation are presented below:

1. Read an index to an empty transmit descriptor from channel's BLROUT FIFO. This operation can be done in poling or in interrupt mode. Be aware that the read value shall be masked with the configuration value because the width of the FIFO element is smaller than 32 bits.
2. Write the fields of transmission descriptor as they are defined by Llce\_Can\_TxMbDescriptorType including the TXACK fifo used to get back the tx confirmation.Read the field from the tx mb descriptor in order to access the related tx mb.
3. Write the CAN frame content into the referred tx message buffer entry as it is defined by Llce\_Can\_MbType .
4. Write the index of the transmission descriptor read at step 1 into the channel's BLRIN FIFO in order to trigger the transmission inside LLCE.
5. Read an index into acknowledge information table from the frame corresponding TXACK FIFO. This operation can be done either in polling either in interrupt mode by the host user.
6. Read the content of the referred entry from the acknowledge information table as it is defined by Llce\_Can\_Tx2HostAckInfoType and process it. The tx ack processing shall be done 1 by 1 in order to prevent LLCE to reuse an ack slot which was not yet released by the host.

## LLCE firmware documentation

During transmission process the frame which lost the arbitration is retransmitted continuously until it wins the bus or until other frame is selected for transmission during the arbitration phase.

The correlation between the number of FIFOs (22) for acknowledgement (TXACK) and the number of physical channels (16) is predetermined by the processing way the host can choose, in the same way as for the reception interface. The difference is that the interface is not TXACK fifo, and the host can additionally choose to disable the acknowledgment at the level of every sent message. (See Llce\_Can\_TxMbDescriptorType )

Limitations to be considered:

- Due to the hardware restrictions, each channel can use up to 16 transmission indexes at a time. This transmissions can be part of normal host transmission or internal routing. When configuring a channel, the host shall specify how many transmission buffers wants to be available for it at any moment. If the host configures an advanced filter with the option of routing to another destination channel, it needs to make sure the destination channel has enough message buffers available for routing. This number of message buffers used for routing is the difference between 16 and the number of host reserved message buffers. The last one shall be configured at INIT command for each channel (see Llce\_Can\_InitCmdType structure).
- When using the transmission interface in a multi-threaded system, the mutual exclusion is ensured by the FIFOs capability to be popped even when the fifo is empty. The result is a specific fifo null value which will be checked by the host to see whether the popped element is actually a valid entry or not. The same trick can ensures the reentrancy when accessing the transmission interface.
- After a LLCE\_CAN\_CMD\_SETCONTROLLERMODE command for a START request, the driver must issue a LLCE\_CAN\_CMD\_GETCONTROLLERMODE command.

## 1.3.3.6 Logging interface

It is used by the logging host software to receive CAN frames and other information from the LLCE firmware. It is implemented by using a ring model in the sense that logging host gets from LLCE the frame references and send them back to LLCE in order to be reused. Logging operation can be configured inside the filter settings. Logging interface is composed of:

- 3 shared memory areas containing: the reception descriptor table, CAN message buffer table, extension of the reception descriptor table. Entries of the extension of the rx descriptor table are mapped 1:1 with the entries of the rx descriptor table.
- RXOUTLOG hw fifo is used to send full rx mb descriptors to logging host.
- RXINLOG hw fifo is used to send back from logging host to LLCE the indexes of rx mb descriptors for which the logging process was done.

Figure 1.9 Logging interface for LLCE CAN firmware.

<!-- image -->

The steps done by the logging host software in order to log the CAN frames:

1. Logging core read an index to a full receive descriptor from the unique RXOUTLOG FIFO. This operation can be done in poling or in interrupt mode.
2. Using the previous read index access the corresponding RX mb descriptor as it is defined by Llce\_Can\_RxMbDescriptorType and extract from it the index to the CAN message buffer. Using the same index access also the corresponding entry from the extension of the RX mb descriptor table and extract the controller ID which received the frame.
3. Read the content of the full reception message buffer as it is defined by Llce\_Can\_MbType and process it.
4. Write the index of the receive descriptor to the unique RXINLOG FIFO in order to send it back to the LLCE to be reused.

The logging host needs to access the shared memory area by using data type Llce\_Can\_SharedMemoryType .

LLCE has only 1 logging interface, where only logging of RX frames is possible, with the limitation of missing buffering. (only 16 frames can be buffered for logging interface). The logging interface transfers RX descriptors from LLCE to Host (RXOUT(17)) and from Host to LLCE (RXOUT(16)). In order for the host to determine to which controller the newly logged frame belongs, it has to resolve this mapping using an array (of 1byte/entry) mapped into shared memory at address 0x43840050. The array declaration is similar to: uint8 Can\_Rx\_a ← ↩ MbHwCtrlExtension[LLCE\_CAN\_CONFIG\_MAXRXMB]; This array has LLCE\_CAN\_CONFIG\_MAX ← ↩ RXMB entries, each of them is a frame index and contains the CAN channel where the RX frame originates. LLCE sends an RX descriptor towards different destinations (e.g. host, logging fifo interface), based on which the frame index is decoded. An example of decoding is provided in the sample app folder from the release package.

## 1.3.3.7 Shutdown interface

It is possible to request a shutdown of the LLCE cores, such that they enter an inactive state. This puts LLCE in a state where it can be safely reset at any time.

## LLCE firmware documentation

To trigger a shutdown, send the LLCE\_CAN\_CMD\_SHUTDOWN command. The command is only valid if both host interfaces are uninitialized/de-initialized. Once the command is accepted, each core executes the WFI instruction - as specified in the reference manual - and stops code execution. Note that, to prevent unexpected returns to activity from e.g. an interrupt, each core disables its interrupts before executing WFI. The only way to bring LLCE back to a usable state is to perform a partition reset, followed by a firmware reload along with memory initialization.

The status of LLCE is updated in Start up interface. When the command is accepted, the status of each core changes to LLCE\_SHUTDOWN\_REQUESTED. The actual shutdown happens when the main loop is executed again. Just before shutdown, each core updates its status to LLCE\_SHUTDOWN\_ENTERED. If an unexpected event happens and the core cannot stay in sleep mode, it will enter an endless loop to keep it isolated; its status is updated to LLCE\_SHUTDOWN\_FAILED.

## 1.3.4 Authentication of CAN and CAN FD frames using HSE services

In order to activate authentication services inside LLCE firmware it is needed to send command LLCE\_CAN\_ ← ↩ CMD\_INIT\_HSE before any cryptographic operation to be used. Also the HSE hardware and firmware shall be already up and running when the activation command is sent from host to LLCE.

The LLCE firmware uses the algorithm AES-CMAC with a 16 byte length key in order to generate 8 byte length authentication codes for the configured transmitted frames and to verify them for the configured received frames.

Using short(truncated) CMAC authentication codes allows that both standard and CAN-FD frames to be supported with authentication services.

Current LLCE firmware generates and verifies the generated CMAC using a key handle passed from the host. The key handle is configureable individually for each Tx and Rx hardware object.

The keys and their respective key handles are defined and loaded in the HSE firmware by the host. This information shall be present in the HSE before using crypthograpic operation of the LLCE firmware.

## 1.3.4.1 CMAC generation for transmitted frames

Adding CMAC codes inside transmitted frames is enabled by using a configuration parameter defined inside each transmission message buffer descriptor as it is defined by Llce\_Can\_TxMbDescriptorType . Additionally it enables the option to set the key handle, which shall be stored in the Timestamp buffer of the frame. For the transmission flow the host application shall allocate and reserve 8 bytes length space at the end of transmitted CAN FD frames payload in order to allow the LLCE firmware to insert the generated CMAC code.

## 1.3.4.2 CMAC verification for the received frames

Verification of MAC codes of the received frames is enabled by using a configuration parameter defined inside Llce\_Can\_AdvancedFeatureType and Llce\_Can\_AdvancedFilterType as part of advanced filter configuration process. In that way, after the filtering is done and the CAN-FD frame is accepted based on the frame id rules, the verification of the CMAC code placed in the last 8 bytes of the payload is done by the LLCE firmware, if enabled in the accepting filter rule.

The host application will receive the complete CAN or CAN-FD frame payload including also the CMAC code.

## 1.3.5 CAN traffic routing destinations

The LLCE communication is frame-based and controls the flow of incoming traffic (CAN and ETH) based on the AF filter settings configured by SET\_ADVANCED\_FILTER command and on the list of destinations created by CREATE\_AF\_DESTINATION command.

The routing of CAN traffic is flexible and can be set up to forward the incoming frames that pass a configured filter to the specified destinations. The list of possible destinations is: Host (corresponding HIF), Authentication component (HSE subsystem), Logging interface, other outgoing CAN bus(es), and ETH interface (for CAN tunneling over Ethernet).See Llce\_Can\_AdvancedFeatureType for data structure. See the picture below for visual interpretation.

Figure 1.10 CAN traffic routing destinations.

<!-- image -->

A particular case is the routing of incoming ETH frames to a configured outgoing CAN bus, after decapsulation of the ETH frame based on its format. More details in Eth2Can flow.

## 1.3.6 CAN to CAN internal routing

Internal CAN routing, also called CAN to CAN routing, is one of the most versatile features of LLCE in consequence of the low latencies and variety of configuration options, such as:

- unicast routing

## LLCE firmware documentation

- multicast routing
- frame conversion from CAN to CAN-FD (by adding FDF and BRS bits)
- frame conversion from CAN-FD to CAN (by removing FDF and BRS bits), for frames with payload length less than 8 bytes
- frame ID remapping and control of extended format
- enabling/disabling/adding new AF filters at runtime
- adding new destination rules at runtime
- enabling/disabling of channel routing in a routing multicast configuration using LLCE\_CAN\_CMD\_SETCHANNELROU command at runtime
- capability of working with faulty outgoing CANs without disrupting the rest of routing rules

Limitations and pitfalls:

- in a routing configuration, the outgoing channel shall have enough message buffers for transmission. The field u8TxMbCount in Llce\_Can\_InitCmdType indicates the TX message buffers reserved for host. The difference up to 16 represents the TX buffers used for routing on that outgoing channel. User shall keep in mind that a TX channel which is unable to send (e.g. due to arbitration lost) will keep the corresponding MB blocked until successful transmission.
- in a routing configuration, the matching advanced filter shall have enough RX message buffers assigned to accomodate the eventual delay caused by outgoing TX channel being unable to send. The RX MB will be kept blocked until all the destinations are served.
- in a routing process, the filters are processed in the ascending order of u16FilterAddr. The filtering process stops at first match, if any. See also the limitations of config\_interface\_sec
- no payload manipulation is implemented (e.g. payload split)
- signal routing is not supported
- the removal of Advanced Destinations is not supported. They can be only added. To skip an advanced destination, the Advanced filter shall simply not refence it anymore.

See the picture below for visual interpretation of CAN2CAN routing.

Figure 1.11 CAN to CAN flow.

<!-- image -->

Note: The filtering is applied only to the incoming frames. Based on the advanced destinations linked to the matching filter, the frames are forwarded to the configured CAN buses and are arbitrated with the corresponding outbound traffic on the respective channel.

## 1.3.7 Ethernet communication

LLCE is able to communicate directly with the Packet Forwarding Engine (PFE) system to allow direct routing between CAN buses and specially encapsulated Ethernet frames. This link is bidirectional: CAN frames received by LLCE can be encapsulated and sent to PFE for transmission (Can2Eth); or Ethernet frames can be transferred by PFE to LLCE for decoding and transmission on the respective CAN bus(es) (Eth2Can).

## 1.3.7.1 Supported formats

Currently there are 2 formats supported: AVTP Control Format, and User Datagram Protocol (UDP).

AVTP format is described in IEEE 1722-2016, Chapter 9. Both Non-Time-Synchronous Control Format and TimeSynchronous Control Format headers are supported. ACF messages can be ACF\_CAN\_BRIEF or ACF\_CAN

## LLCE firmware documentation

(referred in LLCE interface as ACF\_CAN\_FULL to prevent confusion). For formats that use timestamp, the timestamp is taken from the Timestamp Module as described in the S32G reference manuals. For CAN frames, the timestamp is generated by hardware and has high accuracy. For TSCF headers, the timestamp is read by software as close as possible to transmission time, but noticeable jitter may occur.

UDP encapsulation uses a more customized format. The UDP frame has the structure described in IETF RFC 768, with most fields provided by the host. There are sub-types for UDP over IPv4 (no suffix) or IPv6 (\_IPV6 suffix).

The payload encapsulates a CAN frame in one of two selectable formats, as described in the picture below. Currently only 1 CAN frame per UDP frame is supported.

For backward compatibility, UDP format A is referred to simply as "UDP" in e.g. the interface headers.

Figure 1.13 UDP encapsulation, format B.

<!-- image -->

## Note

UDP formats A and B may overlap - certain data can match either format. To prevent issues when using the decapsulation mechanism (Eth2Can), take care to not activate both formats using the LLCE\_CAN\_CMD\_SE ← ↩ TETH2CANFORMATSTATE command. If both UDP formats are activated, decapsulation of UDP frames may be unpredictable.

## 1.3.7.2 Initial setup

The LLCE-PFE bridge works autonomously, but it does require the host to perform initial setup steps.

- First, PFE must be started and configured by the host. Only after both PFE and LLCE have booted can the bridge be set up.
- Second, the bridge must be initialized. Due to hardware limitations, LLCE cannot register itself with PFE as a client. The host must send the LLCE command LLCE\_CAN\_CMD\_INIT\_PFE or LLCE\_CAN\_CMD\_INIT\_PF ← ↩ E\_EXT\_RING\_BUF to trigger initialization of the PFE minidriver inside LLCE. Using LLCE\_CAN\_CMD\_INI ← ↩ T\_PFE results in obtaining the addresses of 4 ring buffers, stored in LLCE memory, that the host must register with PFE. Using LLCE\_CAN\_CMD\_INIT\_PFE\_EXT\_RING\_BUF the host will provide the FW the addresses of the ring buffers, stored in system SRAM. The AUTOSAR driver contains code that may be used as a template. After PFE has successfully registered the ring buffers and host interface used by LLCE, the 2 subsystems can communicate independently.
- Finally, routing rules must be set up. For Can2Eth, these take the form of advanced filters. For Eth2Can, routing rules for PFE must be set up by the host.

Figure 1.14 LLCE-PFE configuration.

<!-- image -->

## Note

More recent versions of the PFE software support re-initialization of the bridge, if either LLCE of PFE were restarted without the other one. In this case, the PFE driver may change the ring buffers, bringing them out of sync with the LLCE minidriver. This can be fixed by calling LLCE\_CAN\_CMD\_INIT\_PFE a second time, which synchronizes the internal minidriver to the rings. This second call is not known to have drawbacks, so it can be used routinely.

## 1.3.7.3 Can2Eth flow

Can2Eth routing uses the same basic principle as Can2Can: advanced destinations referenced by advanced filters. These may be created at any time, but receiving CAN frames for Can2Eth before the bridge is initialized may cause data loss.

The first step is to create advanced destinations (see Llce\_Can\_CreateAfDestination ) with type CAN\_AF ← ↩ \_CAN2ETH. UDP-specific fields such as ports are ignored for AVTP. After the destinations are successfully created, they may be attached to one or more advanced filters. Once the filters are created, configuration is finished. Frames accepted through these advanced filters will be autonomously processed in LLCE and sent to PFE for transmission when buffers are filled.

Using Can2Eth requires the host to provide buffer space. Llce\_Can\_CreateAfDestination allows and requires specification of a memory area, buffer count and size of each buffer (thus the area reserved is (buffer count) ∗ (buffer size)). This area must be accessible to both LLCE and PFE, non-cacheable, and at least 16-bit aligned. LLCE will pre-initialize all buffers for a destination when it is created, so some latency may be seen when providing a large number of buffers. Incoming Can2Eth frames are packed into the next non-full buffer for that destination. When a buffer cannot accept another 64-byte CAN frame (maximum size), that buffer is considered full, the respective Ethernet frame is finalized and handed over to PFE for transmission, and the next buffer is selected.

## 1.3.7.4 Eth2Can flow

Eth2Can works in reverse to Can2Eth, accepting Ethernet frames in compatible formats, decapsulating CAN messages, and sending these CAN frames on the respective buses.

Eth2Can is activated by specifying non-zero values to RX fields in Llce\_Can\_InitPfeCmdType when sending the INIT\_PFE command. Due to PFE restrictions, at least 73 Ethernet buffers must be specified at bridge setup time, with the memory for these buffers provided by the host. These buffers may have arbitrary size, but the user must ensure incoming Ethernet frames will fit into a single buffer. Frame (de)fragmentation is not supported by LLCE.

Decapsulation of each supported format may be enabled or disabled at any time using the LLCE\_CAN\_CMD\_S ← ↩ ETETH2CANFORMATSTATE command. All formats are disabled by default.

For AVTP format, LLCE will parse and transmit all CAN messages in a frame until frame end or a parsing error occurs. For UDP format, only one CAN frame per UDP frame is currently supported.

The host must configure PFE to divert relevant Ethernet frames towards LLCE (specifically, to the HIF configured for LLCE during bridge setup). An example on how to do this using the PFE MCAL driver is provided in the LLCE sample app. LLCE will attempt to decapsulate and send any well-formed Ethernet frames in supported and activated formats, with no extra filtering.

## 1.3.7.5 Controlling Ethernet communication

Can2Eth and Eth2Can are active by default. A command is available to control their state: LLCE\_CAN\_CMD ← ↩ \_SETCAN2ETHSTATE. It takes a binary argument specifying whether Ethernet communication should be turned on or off. Calling LLCE\_CAN\_CMD\_SETCAN2ETHSTATE with an argument of LLCE\_FALSE will cause all future processing of Can2Eth and Eth2Can frames to be aborted. In addition, all Can2Eth buffers are reset, allowing existing data to be flushed before it becomes stale. The state of the internal PFE minidriver is not changed.

## 1.3.8 PCIe routing

LLCE is able to collect CAN frames and trigger a PCIe DMA controller to write the buffered data to an external device.

This function works similarly to Can2Eth: for each "destination", a number of (contiguous) buffers of a certain size are allocated by the host. CAN frames that are routed to a destination are packed in a format similar to UDP A, but supporting multiple CAN frames per buffer. When the buffer has less than 72 bytes (64 byte CAN payload + overhead) remaining, LLCE triggers the specified PCIe DMA controller to transfer the data to the external device. Each buffer is transferred to the external device with the same offset as the local buffer; for example, if a Can2Pcie destination uses buffers starting at local address 0x3450 0000, of size 256 each, mapped to external address 0x4500 0000, then the buffers will the transferred to the following addresses: buffer 0 (at 0x3450 0000) to 0x4500 0000, buffer 1 (at 0x3450 0100) to 0x4500 0100, buffer 2 (at 0x3450 0200) to 0x4500 0200 etc.

Optionally, an MSI may be triggered on the RC on each transmission. The configured MSI ID is checked against those allowed by the RC and skipped if higher than allowed.

Can2Pcie is disabled by default and may be enabled or disabled at any time using the LLCE\_CAN\_CMD\_SET ← ↩ CAN2PCIESTATE command. Disabling the functionality will not affect transfers already in progress. On disable, the state of the internal buffers is reset, meaning currently buffered data is lost. On enable, the list of allowed MSI is updated.

Note that LLCE will write to the DMA controller(s) at unpredictable moments. Using DMA controllers allocated to Can2Pcie after enabling it may cause unpredictable behavior.

## 1.3.9 Headless Mode

(A prototype of this feature was earlier known as "Default Configuration")

LLCE provides a method to load a configuration set on LLCE boot, without host intervention. This removes the dependency on having the host ready and sending the configuration data via the driver. In turn, this reduces LLCE startup time when the host application is slow to start, allowing LLCE to buffer incoming messages which can later be received by the host, or start routing.

Headless mode entry is triggered by writing two 32-bit values in the LLCE Shared Memory area:

- LLCE\_HEADLESSMODE\_MAGICVALUE
- address of the configuration structure (described below)

The configuration structure must be in an area accessible (read-only or full access) to LLCE.

Writing to the shared memory in this way is only safe to do while the LLCE cores are held in reset. Once the cores are released from reset, they will attempt to load the given configuration. If this is successful, LLCE will operate normally and does not require any other initialization.

After a successful headless boot, the LLCE behaves as if it had received the corresponding configuration commands from a host. This means that attempting a normal init flow from the host will cause errors to be generated (e. ← ↩ g. PlatformInit is already done, configured channels are already started). The host driver should bypass sending initialization commands to LLCE when the headless startup is used.

## 1.3.9.1 Generating a configuration for headless start

The headless configuration structure shall have this layout:

- descriptor ( Llce\_Headless\_Descriptor ), including another instance of LLCE\_HEADLESSMODE\_MAGICVALUE
- platform init ( Llce\_Can\_InitPlatformCmdType )
- a number of "channel init" ( Llce\_Can\_InitCmdType ) structures equal to the number of channels declared in the descriptor (u8ChannelCount)
- a number of baudrate ( Llce\_Can\_SetBaudrateCmdType ) configurations equal to the number of channels declared in the descriptor (u8ChannelCount)
- a number of advanced destinations ( Can\_Af\_DestRulesType ) equal to the number of destinations declared in the descriptor (u8DestinationCount)
- a number of regular filters ( Llce\_Can\_ReceiveFilterType ) equal to the total number of regular filters declared in the descriptor (sum of au16RegularFilterCount elements), ordered by channel (BCAN0, BCAN1 etc.). The filter-channel matching is done by counting against the elements of au16RegularFilterCount
- a number of advanced filters ( Llce\_Can\_AdvancedFilterType ) equal to the total number of advanced filters declared in the descriptor (sum of au16AdvancedFilterCount elements), ordered by channel (BCAN0, BCAN1 etc.). The filter-channel matching is done by counting against the elements of au16AdvancedFilter ← ↩ Count

## LLCE firmware documentation

This structure shall be 32-bit aligned.

It is strongly recommended that the configuration used for headless startup be generated based on the driver configuration. Mismatched configurations may result in apparently strange behavior, such as frames being received from channels that the driver considers inactive. The NXP-provided CAN driver contains a feature to automatically generate a headless configuration from the driver configuration, if the option is enabled.

To help the user, a stub is provided in this interface, which helps transform the configuration from C source into FWreadable binary. To use it, copy the configuration file as Can\_43\_LLCE\_HeadlessCfg.c into the 'headless' directory, and call "make headlessconfig". A binary file named LLCE\_HeadlessConfig.bin and a C-like binary named LLCE ← ↩ \_HeadlessConfig\_bin.c will be generated in the output directory. The 'headless' directory may be copied outside the llce\_interface location, and the location of the interface given to 'make' as "LLCE\_INTERFACE\_LOCATION=[...]"

## 1.3.9.2 Error reporting in headless mode

Errors detected during headless boot are reported in the Llce\_Mgr\_StatusType field of the respective core, as well as using the Notification interface if enabled. Errors found in PlatformInit are always reported on Notification Interface 0, otherwise according to the settings in Platform Init.

Cores that perform a special flow for headless boot (currently RX and TX) will populate Llce\_Mgr\_StatusType with LLCE\_HEADLESS\_SUCCESS instead of a normal LLCE\_FW\_SUCCESS to show that the headless configuration was detected and successfully applied.

Note that each core checks different parameters. LLCE can only be considered successfully booted if all cores report success.

## 1.3.9.3 Limitations of headless mode

Can2Eth and Eth2Can features are not useable for headless start. These features can still be accessed after host boot, by calling the respective APIs to initialized the PFE bridge, create advanced destinations and create advanced filters using these destinations.

## 1.3.10 Typical scenario regarding LLCE CAN firmware usage

A possible sequence of commands/operations using LLCE interface for an ENABLEMENT scenario is described below:

1. Send INIT\_PLATFORM command from host to LLCE in order to initialize platform related components and to setup the maximum number of resources intended to be used per channel. A single command is needed to be sent by a host.
2. Send INIT command from host to LLCE in order to initialize a specific CAN controller. Multiple commands might be needed for multiple controllers.
3. Send SET\_FILTER command from host to LLCE in order to set reception filters for frames consumed only by the host applications. Multiple commands might be sent if needed.
4. Send SETBAUDRATE command from host to LLCE in order to configure baud rate for a specific CAN controller. Multiple commands might be needed for multiple controllers.

5. Send SETCONTROLLERMODE from host to LLCE in order to request that a specific CAN controller to start participating at bus transactions. Multiple commands might be needed for multiple controllers.
6. Send or receive frames on the bus.
7. Send REMOVE\_FILTER from host to LLCE in order to request that a specific filter for a specific CAN controller to be disabled. Multiple commands might be sent if needed.
8. Send SETCONTROLLERMODE from host to LLCE in order to request that a specific CAN controller to stop participating at bus transactions. Multiple commands might be needed if multiple controllers are used.
9. Send DEINIT command from host to LLCE in order to de-initialize a specific CAN controller. Multiple commands might be needed for multiple controllers.
10. Send DEINIT\_PLATFORM command from host to LLCE in order to de-initialize platform related components. A single command is needed from each host.

A possible sequence of commands/operations using LLCE interface for an advanced feature scenario is described below:

1. Send INIT\_PLATFORM command from host to LLCE in order to initialize platform related components and to setup the maximum number of resources intended to be used per channel. A single command is needed to be sent by a host.
2. Send INIT command from host to LLCE in order to initialize a specific CAN controller. Multiple commands might be needed for multiple controllers.
3. Send SET\_FILTER command from host to LLCE in order to set reception filters for frames consumed only by the host applications. Multiple commands might be sent if needed.
4. Send SET\_AF\_DESTINATION command from host to LLCE in order to set a destination rule for the configured filters. A rule index is returned by the command and it shall be used by the SET\_ADVANCED ← ↩ \_FILTER command.Multiple commands might be sent if needed.
5. Send SET\_ADVANCED\_FILTER command from host to LLCE in order to set reception filters for frames which are not consumed by host applications. Multiple commands might be needed for multiple controllers.
6. Send SETBAUDRATE command from host to LLCE in order to configure baud rate for a specific CAN controller. Multiple commands might be sent if needed.
7. Send SETCONTROLLERMODE from host to LLCE in order to request that a specific CAN controller to start participating at bus transactions. Multiple commands might be needed for multiple controllers.
8. Send or receive frames on the bus based on remaining filters or just monitor the error notifications for the advanced features.(can2can internal routing, can2eth, etc.).
9. Send REMOVE\_FILTER from host to LLCE in order to request that a specific filter for a specific CAN controller to be disabled. Multiple commands might be sent if needed.
10. Send or receive frames on the bus or just monitor the error notifications when advanced features are configured(can2can internal routing, can2eth, etc.) based on enabled filters.
11. Send SETCONTROLLERMODE from host to LLCE in order to request that a specific CAN controller to stop participating at bus transactions. Multiple commands might be needed if multiple controllers are used.
12. Send DEINIT command from host to LLCE in order to de-initialize a specific CAN controller. Multiple commands might be needed for multiple controllers.
13. Send DEINIT\_PLATFORM command from host to LLCE in order to de-initialize platform related components. A single command is needed from each host.

## LLCE firmware documentation

Table 1.2 LLCE commands error codes description

| Command                                                                                     | Error code                             | Description                                                                                                                                        |
|---------------------------------------------------------------------------------------------|----------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_CAN_CMD_INIT                                                                           | LLCE_ERROR_COMMAND_I ← ↩ NVALID_PARAMS | More than 16 transmission indexes were configured on the given con- troller                                                                        |
|                                                                                             | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | The host or the controller on which the command was issued is uninitial- ized                                                                      |
|                                                                                             | LLCE_ERROR_BCAN_LPM_ ← ↩ EXIT          | see LLCE_ERROR_BCAN_SRT_EN ← ↩ TER                                                                                                                 |
|                                                                                             | LLCE_ERROR_BCAN_SRT_ ← ↩ ENTER         | see LLCE_ERROR_BCAN_SRT_EN ← ↩ TER                                                                                                                 |
| LLCE_CAN_CMD_DEINIT                                                                         | LLCE_ERROR_TXACK_NOT ← ↩ _READ         | Not all the ACKs were consumed by the host for the current controller.                                                                             |
|                                                                                             | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | The controller does not belong to the host on which the command was issued, or the controller is in a dif- ferent state than LLCE_CAN_S ← ↩ TOPPED |
| LLCE_CAN_CMD_SETBAUD ← ↩ RATE                                                               | LLCE_ERROR_COMMAND_I ← ↩ NVALID_PARAMS | The FdEnable option is in an unde- fined state                                                                                                     |
|                                                                                             | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | The controller must be in LLCE_ ← ↩ CAN_STOPPED state. This error is issued if this is not satisfied.                                              |
| LLCE_CAN_CMD_SETCONT ← ↩ ROLLERMODE                                                         | LLCE_ERROR_COMMAND_I ← ↩ NVALID_PARAMS | User requested an undefined transi- tion                                                                                                           |
|                                                                                             | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | Internal state machine is not re- spected, see internal_state_sec                                                                                  |
| LLCE_CAN_CMD_SETFILTER, LLCE_CAN_CMD_SETADVA ← ↩ NCEDFILTER, LLCE_CAN_C ← ↩ MD_SETAUXFILTER | LLCE_ERROR_COMMAND_I ← ↩ NVALID_PARAMS | No filter to configure was given                                                                                                                   |
|                                                                                             | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | The controller on which the com- mand is performed is in an unde- fined state (neither LLCE_CAN ← ↩ _STOPPED nor LLCE_CAN_S ← ↩ TARTED)            |
| LLCE_CAN_CMD_SETFILTE ← ↩ RENABLESTATUS, LLCE_CA ← ↩ N_CMD_REMOVE_FILTER                    | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | The controller on which the com- mand is performed is in an unde- fined state (neither LLCE_CAN ← ↩ _STOPPED nor LLCE_CAN_S ← ↩ TARTED)            |
| LLCE_CAN_CMD_SETCHAN ← ↩ NELROUTINGOUTPUTSTATE, LLCE_CAN_CMD_SETCAN2 ← ↩ ETHSTATE           | LLCE_ERROR_COMMAND_I ← ↩ NVALID_PARAMS | A value different than LLCE_TR ← ↩ UE or LLCE_FALSE was given to the status variable                                                               |
|                                                                                             | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | The command was issued without enabling the CAN routing feature                                                                                    |

## LLCE firmware documentation

Table 1.4 Critical LLCE error codes

| Command                           | Error code                             | Description                                                                                                                                                                           |
|-----------------------------------|----------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_CAN_CMD_INIT_PLA ← ↩ TFORM   | LLCE_ERROR_COMMAND_I ← ↩ NVALID_PARAMS | HIF0 must use at least controller in- stance 0. HIF1 must use at least controller instance 8.                                                                                         |
|                                   | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | The host or any of the controllers were already initialized or any Tx or Rx Polling class is already used either by current host or the other one                                     |
| LLCE_CAN_CMD_DEINIT_P ← ↩ LATFORM | LLCE_ERROR_COMMAND_I ← ↩ NVALID_PARAMS | HIF0 must use at least controller in- stance 0. HIF1 must use at least controller instance 8.                                                                                         |
|                                   | LLCE_ERROR_COMMAND_ ← ↩ NOTACCEPTED    | The current host was not previously initialized, or there still are initial- ized controllers belonging to the cur- rent host or the command was al- ready issued on the current host |
|                                   | LLCE_ERROR_TXACK_NOT ← ↩ _READ         | Not all of the ACKs were consumed by the host for one of the polling interfaces.                                                                                                      |

Table 1.6 LLCE error codes for warnings

| Error code                      | User reaction                                                                                   |
|---------------------------------|-------------------------------------------------------------------------------------------------|
| LLCE_ERROR_TXACK_FIFO_FULL      | Abnormal behaviour : reset fw (stop cores, reset memory and reload firmware image, start cores) |
| LLCE_ERROR_RXOUT_FIFO_FULL      |                                                                                                 |
| LLCE_ERROR_HW_FIFO_FULL         |                                                                                                 |
| LLCE_ERROR_SW_FIFO_EMPTY        |                                                                                                 |
| LLCE_ERROR_SW_FIFO_FULL         |                                                                                                 |
| LLCE_SHUTDOWN_FAILED            |                                                                                                 |
| LLCE_ERROR_RXLUT_ACCESS_MODE    |                                                                                                 |
| LLCE_ERROR_RXLUT_SEARCH_MODE    |                                                                                                 |
| LLCE_ERROR_RXLUT_SLOW_OPERATION |                                                                                                 |
| LLCE_ERROR_RXLUT_INCOMPLETE_OP  |                                                                                                 |
| LLCE_ERROR_RXLUT_OPERATING_MODE |                                                                                                 |
| LLCE_ERROR_RXLUT_INIT_SLOW_OP   |                                                                                                 |
| LLCE_ERROR_FATAL                |                                                                                                 |
| LLCE_ERROR_PFEIF                | PFE Init failed. Reset PFE module.                                                              |
| LLCE_ERROR_HSEIF                | HSE Init failed. HSE firmware not correctly flashed. Reflash the right version of HSE.          |
| LLCE_ERROR_UNKNOWN_SRC          | Abnormal behaviour likely indicating memory corruption. Reset fw.                               |
| LLCE_ERROR_UNKNOWN_DEST         |                                                                                                 |
| LLCE_ERROR_UNKNOWN_REQUEST      |                                                                                                 |

## LLCE firmware documentation

| Error code                                 | User reaction                                                                                                                                            |
|--------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_ERROR_MB_NOTAVAILABLE                 | The configured number of MB has been exhausted for this filter, likely a configuration issue. Please check uint16 u16MbCount.                            |
| LLCE_ERROR_SHORT_MB_NOTAVAILABLE           | Likely a configuration issue, the filter has been config- ured to receive short frames but actually received a long frame. Please check eFilterMbLength. |
| LLCE_ERROR_BCAN_RXFIFO_OVERRUN             | Frame lost, fw operation can continue.                                                                                                                   |
| LLCE_ERROR_RXTOKENS_UNRETURNED             | Retry SetControllerMode command.                                                                                                                         |
| LLCE_ERROR_INDEX_NOT_RECOVERED             | Retry SetControllerMode command.                                                                                                                         |
| LLCE_ERROR_RESET_PENDING                   | Retry SetControllerMode command.                                                                                                                         |
| LLCE_ERROR_COMMAND_RXPPE_NORESP ← ↩ ONSE   | Reset FW, try command again.                                                                                                                             |
| LLCE_ERROR_COMMAND_AF_NORESPONSE           | Reset FW, try command again.                                                                                                                             |
| LLCE_ERROR_INTERNALDESC_FIFO_FULL          | Frame routing failed, operation can be continued.                                                                                                        |
| LLCE_ERROR_INTERNALDESC_NOTAVAIL           | Frame routing failed, reset fw.                                                                                                                          |
| LLCE_ERROR_INTERNALDESC_NOT_DELIV ← ↩ ERED | Frame routing failed, operation can be continued.                                                                                                        |
| LLCE_ERROR_INTERNALDESC_NOT_RETU ← ↩ RNED  | Frame routing failed, operation can be continued.                                                                                                        |
| LLCE_ERROR_CMD_PROCESSING                  | Likely invalid input, such as command id. Check input and retry command.                                                                                 |
| LLCE_ERROR_DATA_LOST                       | Reported in case CANframes don't fit in the Eth or Pcie buffers. Check input for frame size and retry transmis- sion.                                    |
| LLCE_ERROR_TXLUT_FULL                      | TxLut resources are starved. Retry tranmission at a later time.                                                                                          |
| LLCE_ERROR_CTRL_NOT_READY                  | Likely the controller enetered bus-off, restart controller.                                                                                              |
| LLCE_ERROR_BUSOFF                          |                                                                                                                                                          |
| LLCE_ERROR_FIFO_LOG_FULL                   | Mb index skipped on host side, operation can be con- tinued.                                                                                             |
| LLCE_ERROR_COMMAND_DEINIT_NOTSTOP          | Set controller to stop state and retry command.                                                                                                          |
| LLCE_ERROR_TXACK_NOT_READ                  | Some TxAcks were skipped, operation can be continued.                                                                                                    |
| LLCE_ERROR_COMMAND_NOTSUPPORTED            | Check command id, use one of the available ids and retry the command                                                                                     |
| LLCE_ERROR_COMMAND_NOTACCEPTED             | Command flow was broken, likely controller is in an improper state. Restart controller and try command again.                                            |
| LLCE_ERROR_COMMAND_INVALID_PARAMS          | Likely incorrect input. Check e.g. that no more than 16 transmission indexes were configured on the given controller, and retry command.                 |
| LLCE_ERROR_FILTERS_FULL                    | Check the number of configured filters. Filtering capac- ity is exceeded.                                                                                |
| LLCE_ERROR_FILTERS_NOTEXIST                | Check if the filter was created or if it was already re- moved.                                                                                          |
| LLCE_ERROR_FILTERS_MASK_EMPTY              | Check the number of configured filters. Filtering capac- ity is exceeded.                                                                                |
| LLCE_ERROR_FILTERS_RANGE_EMPTY             | Check the number of configured range filters. Filtering capacity is exceeded.                                                                            |

## LLCE firmware documentation

| Error code                         | User reaction                                                                                                                            |
|------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_ERROR_FILTERS_EM_EMPTY        | Check the number of configured exact match filters. Fil- tering capacity is exceeded.                                                    |
| LLCE_ERROR_IDX_NOT_VALID_HOST      | Invalid index from host, operation can be continued. If the error persists, reset host.                                                  |
| LLCE_ERROR_IDX_NOT_VALID_LOG       | Invalid index from host, operation can be continued. If the error persists, reset host.                                                  |
| LLCE_ERROR_TXFRAME_MAC_GEN_ERROR   | Routing failed, operation can be continued. This is caused by a corrupted frame or incorrect HSE keys con- figuration.                   |
| LLCE_ERROR_RXFRAME_AUTH_ERROR      | Routing failed because of currupt frame or frame is not authentic, operation can be continued. Reset HSE mod- ule if the issue persists. |
| LLCE_ERROR_RX_SW_FIFO_EMPTY        | Frame could not be received, operation can be contin- ued. Reset fw if the issue persists.                                               |
| LLCE_ERROR_MB_NOTAVAIL             | Frame routing failed, operation can be continued.                                                                                        |
| LLCE_ERROR_MB_FIFO_FULL            | Frame routing failed, operation can be continued.                                                                                        |
| LLCE_ERROR_NO_MB_AVAILABLE         | Frame routing failed, operation can be continued.                                                                                        |
| LLCE_ERROR_CONVERSION              | Likely faulty configuration. This error occurs when try- ing to send a frame larger than 8 bytes without config- uring FD.               |
| LLCE_ERROR_NO_MB_TO_ABORT          | The frame was already sent, operation can be continued.                                                                                  |
| LLCE_ERROR_ROUTINGCHANNEL_DISABLED | Likely faulty configuration. Check the used channel and enable it.                                                                       |

Table 1.8 Informative LLCE error codes

| Error code                    | User reaction                                                                                                      |
|-------------------------------|--------------------------------------------------------------------------------------------------------------------|
| LLCE_ERROR_BCAN_FRZ_EXIT      | For debug purposes, it is advisable to keep the protocol errors disabled, due to quick flooding of the error table |
| LLCE_ERROR_BCAN_SYNC          | LLCE_ERROR_BCAN_SYNC                                                                                               |
| LLCE_ERROR_BCAN_FRZ_ENTER     | LLCE_ERROR_BCAN_FRZ_ENTER                                                                                          |
| LLCE_ERROR_BCAN_LPM_EXIT      | LLCE_ERROR_BCAN_LPM_EXIT                                                                                           |
| LLCE_ERROR_BCAN_SRT_ENTER     | LLCE_ERROR_BCAN_SRT_ENTER                                                                                          |
| LLCE_ERROR_BCAN_UNKNOWN_ERROR | LLCE_ERROR_BCAN_UNKNOWN_ERROR                                                                                      |
| LLCE_ERROR_BCAN_ACKERR        | LLCE_ERROR_BCAN_ACKERR                                                                                             |
| LLCE_ERROR_BCAN_CRCERR        | LLCE_ERROR_BCAN_CRCERR                                                                                             |
| LLCE_ERROR_BCAN_BIT0ERR       | LLCE_ERROR_BCAN_BIT0ERR                                                                                            |
| LLCE_ERROR_BCAN_BIT1ERR       | LLCE_ERROR_BCAN_BIT1ERR                                                                                            |
| LLCE_ERROR_BCAN_DPBIT1ERR     | LLCE_ERROR_BCAN_DPBIT1ERR                                                                                          |
| LLCE_ERROR_BCAN_DPBIT0ERR     | LLCE_ERROR_BCAN_DPBIT0ERR                                                                                          |
| LLCE_ERROR_BCAN_DPSTFERR      | LLCE_ERROR_BCAN_DPSTFERR                                                                                           |
| LLCE_ERROR_BCAN_DPFRMERR      | LLCE_ERROR_BCAN_DPFRMERR                                                                                           |
| LLCE_ERROR_BCAN_DPCRCERR      | LLCE_ERROR_BCAN_DPCRCERR                                                                                           |
| LLCE_ERROR_BCAN_FRMERR        | LLCE_ERROR_BCAN_FRMERR                                                                                             |
| LLCE_ERROR_BCAN_STFERR        | LLCE_ERROR_BCAN_STFERR                                                                                             |

## LLCE firmware documentation

| Error code                         | User reaction   |
|------------------------------------|-----------------|
| LLCE_ERROR_BCAN_TDCFAIL            |                 |
| LLCE_ERROR_BCAN_TXWRN              |                 |
| LLCE_ERROR_BCAN_RXWRN              |                 |
| LLCE_ERROR_BCAN_PASSERR            |                 |
| LLCE_NOTIF_BCAN_EXIT_PASSIVE_STATE |                 |

The "Critical LLCE error codes" table lists the errors which appear when there is an abnormal operation, likely a hardware malfunction or memory corruption scenario.

The "LLCE error codes for warnings" table lists erros which are not critical, such as a frame lost. In these cases communication can continue even if a frame was lost for various reasons. If these errors persist, they signal a more serious issue and fw reset might be needed, as in the critical errors case.

The "Informative LLCE error codes" are BCAN protocol erors. These do not signal a LLCE software issue, they are present for debug purposes and in some cases it's advisable to disable them in order not to hide other critical errors by flooding the output.

## 1.3.11 Usage of host IRQs for CAN firmware

The host interface is composed of multiple hardware FIFOs and shared memory. Some of the FIFOs generate interrupts to the host which need to be serviced. The list of interrupts which needs to be serviced by the host software are marked with yellow in the picture from below. In order to know which are right used FIFO please see chapter config\_interface\_sec Also, on the host side it is needed to configure IRSPRC registers of the MSCM module included into S32Gxx chip in order to select which host core will service a specific interrupt.

Figure 1.15 Usage of IRQs on the host side.

| FIFO group                              | Concentrator register   | Host NVicinterrupt line   | Role                                              |
|-----------------------------------------|-------------------------|---------------------------|---------------------------------------------------|
| LLCEFIFO70                              | ICSR14                  | 174                       | IRQused toprocess notifications from LLCE         |
| LLCEFIFO 158                            | ICSR15                  | 175                       | IRQused toprocess notifications from M7 host core |
| LLCE FIFO 2821                          | ICSR16                  | 176                       | IRQused to process received frames from LLCE      |
| LLCEFIFO 3629                           | ICSR17                  | 177                       | IRQused to process received frames from LLCE      |
| LLCE FIFO 49 42                         | ICSR18                  | 178                       |                                                   |
| LLCE_FIFO_57_50                         | ICSR19                  | 179                       |                                                   |
| LLCE_FIFO_70_63                         | ICSR20                  | 180                       |                                                   |
| LLCEFIFO 7871                           | ICSR21                  | 181                       |                                                   |
| LLCEFIFO 9184                           | ICSR22                  | 182                       | IRQused toprocess tx confirmations from LLCE      |
| LLCEFIFO9992                            | ICSR23                  | 183                       | IRQ used to process tx confirmations from LLCE    |
| LLCEFIFO_5_2, LLCE FIFO 19 16           | ICSR24                  | 184                       |                                                   |
| LLCE_FIFO_82_79, LLCE FIFO 6158         | ICSR25                  | 185                       |                                                   |
| LLCE FIFO 103 100                       | ICSR26                  | 186                       |                                                   |
| LLCE_FIFO_104 LLCE FIFO 83 LLCE_FIFO_62 |                         |                           |                                                   |
| LLCE_FIFO_41                            |                         |                           |                                                   |
| LLCE FIFO 20                            | ICSR27                  | 187                       |                                                   |

## 1.3.12 Default routing of interrupt lines

The table below shows how the FIFO events are routed by default. The user should only enable the required interrupt.

Table 1.10 Fifo interrupt route

| Fifo                                            | Interrupt event   | Routed to   |
|-------------------------------------------------|-------------------|-------------|
| LLCE_FIFO_49_42, LLCE_FIFO_57_50, LLCE_FIFO_62  | FNEMTY            | LLCE        |
| LLCE_FIFO_49_42, LLCE_FIFO_57_50, LLCE_FIFO_62  | PUSHOVR           | Host        |
| LLCE_FIFO_49_42, LLCE_FIFO_57_50, LLCE_FIFO_62  | FNFULL            | Host        |
| LLCE_FIFO_49_42, LLCE_FIFO_57_50, LLCE_FIFO_62  | FFULL             | Host        |
| LLCE_FIFO_70_63, LLCE_FIFO_78_71, LLCE_FIFO_83  | FNEMTY            | Host        |
| LLCE_FIFO_70_63, LLCE_FIFO_78_71, LLCE_FIFO_83  | POPUND            | Host        |
| LLCE_FIFO_70_63, LLCE_FIFO_78_71, LLCE_FIFO_83  | WMKEM             | Host        |
| LLCE_FIFO_70_63, LLCE_FIFO_78_71, LLCE_FIFO_83  | WMKFL             | Host        |
| LLCE_FIFO_7_0, LLCE_FIFO_15_8, LLCE_FIFO_20     | FNEMTY            | LLCE        |
| LLCE_FIFO_7_0, LLCE_FIFO_15_8, LLCE_FIFO_20     | PUSHOVR           | Host        |
| LLCE_FIFO_7_0, LLCE_FIFO_15_8, LLCE_FIFO_20     | FNFULL            | Host        |
| LLCE_FIFO_7_0, LLCE_FIFO_15_8, LLCE_FIFO_20     | FFULL             | Host        |
| LLCE_FIFO_28_21, LLCE_FIFO_36_29, LLCE_FIFO_41  | FNEMTY            | Host        |
| LLCE_FIFO_28_21, LLCE_FIFO_36_29, LLCE_FIFO_41  | FNFULL            | LLCE        |
| LLCE_FIFO_28_21, LLCE_FIFO_36_29, LLCE_FIFO_41  | POPUND            | Host        |
| LLCE_FIFO_28_21, LLCE_FIFO_36_29, LLCE_FIFO_41  | WMKEM             | Host        |
| LLCE_FIFO_28_21, LLCE_FIFO_36_29, LLCE_FIFO_41  | WMKFL             | Host        |
| LLCE_FIFO_91_84, LLCE_FIFO_92_99, LLCE_FIFO_104 | FNEMTY            | Host        |
|                                                 | FNFULL            | LLCE        |
|                                                 | POPUND            | Host        |
|                                                 | WMKEM             | Host        |
|                                                 | WMKFL             | Host        |
| LLCE_FIFO_101, LLCE_FIFO_102                    | FNEMTY            | LLCE        |
|                                                 | FEMTY             | Host        |
|                                                 | FNEMTY            | Host        |
| LLCE_FIFO_38                                    | POPUND            | Host        |
|                                                 | WMKEM             | Host        |
|                                                 | WMKFL             | Host        |
|                                                 | FNEMTY            | LLCE        |
| LLCE_FIFO_37                                    | PUSHOVR           | Host        |
|                                                 | FNFULL            | Host        |
|                                                 | FFULL             | Host        |
| LLCE_FIFO_0, LLCE_FIFO_1                        | FNEMTY            | Host        |
| LLCE_FIFO_8, LLCE_FIFO_9                        | FNEMTY            | Host        |

- PUSHOVR:

PUSH overflow

-

POPUND:

POP underflow

-

WMKEM:

Watermark empty

-

WMKFL:

Watermark full

-

FNEMTY:

FIFO not empty

-

FEMTY:

FIFO empty

-

FNFULL:

FIFO not full

-

FFULL:

FIFO full

## 1.3.13 Settings needed on the host side before to start using LLCE CAN firmware

Supposing that the LLCE CAN firmware is already loaded and started, it is needed to do the following configurations on the host side before to start using LLCE module in interrupt mode:

1. Register interrupt service routines in order to be used by the FIFOs to send data from LLCE to host:(RXOUT, TXACK, NOTIF\_INTR).Be aware that multiple FIFOs interrupts are grouped together by using concentrator registers. Enable those interrupt inside interrupt controller used by the host core.
2. Configure interrupt routing on the host core by using MSCM module.
3. Enable interrupts events for corresponding channel's (RXOUT,TXACK,NOTIF\_INTR) FIFOs.
4. If LLCE CAN firmware needs to be used by 2 host cores simultaneously, it is needed that each host core to configure and use different FIFO interface group (group 0-7 and group 8-15) in case of interrupt processing. Output interface for a particular filter is configured at SetFilter command, and per TX message at Ack interface selection.

## 1.3.14 Shared memory layout

The shared memory is part of the host interface between firmware and host. It is implemented with SRAM stored in LLCE. The shared memory is mostly used for exchanging message buffer content (communication frames), commands and error or status information between LLCE and the host core. Shared memory is 320KB in size, split into 2 blocks of 160KB each. Each block has its own SRAM controller. From the programming point of view, this splitting doesn't make any difference. This memory is accessible by all internal LLCE cores and also by the host cores, HSE and Gateway masters. In order to be compatible with both 32bit and 64bit compilers, the data types is designed to meet the constraints by taking the next actions:

1. Avoid pointers which are architecture-dependent. Where it is really needed, replace them with uint32 types for portability.
2. Align every structure to 4-bytes boundary (the shared memory does not support unaligned accesses) and pack them for minimum size.
3. Pack the enumeration types for minimum size and portability.

LLCE interface ensures the compatibility with driver host application by letting the host app know when the interface footprint in memory (structures/enums/unions) compiled with the host target compiler is not the same as the one expected by the LLCE firmware. This is achieved at compile time in the Llce\_InterfaceMemLayoutCheck header file. This check is provided to the user as a defensive check against eventual incompatibility in binary generation of LLCE interface memory layout on the host application side. The LLCE interface contains compile-time cross checks against precalculated values which will stop the compilation process with error similar to "size of array 'LLCE\_ ← ↩ CHECK\_TYPE\_SIZE' is negative" if any difference found, because this will break the application binary interface compatibility. These cross checks use compile-time operators sizeof and offsetof. For the second one, the stddef.h header is included as per C99 Standard specification. If the user's compiler does not follow C99 Standard, or any reason against including stddef.h, the user shall compile his application adding -DDISABLE\_MEM\_LAYOUT\_ ← ↩ CHECK in order to disable LLCE interface memory layout cross check.

LLCE Shared Memory needs to be configured as Device Memory (Strong Ordered, No Caching).

Limitation to be considered: Shared memory does not support unaligned memory accesses and the M0+ cores either.

## 1.3.15 Customizing the firmware

Note

Customization is only possible for the FDK package.

The LLCE CAN firmware contains helper code to aid in customization and integration of customer-designed logic and components. These helpers are designed to work in two ways: custom commands from host, and filters for custom processing of received CAN frames.

The customization framework aims to help with writing small changes, that have little impact on the operation of the rest of LLCE. For this purpose, callback functions with names ending in 'User' are provided. These functions are provided for convenience, to provide an easy hook in simple scenarios. It is possible to attach customizations higher in the call chain, for more powerful customization possibilities; however, this requires deeper understanding of the LLCE flows, and a greater risk of disrupting normal LLCE operation.

## 1.3.15.1 Custom commands

Custom commands from the host may be used to trigger on-demand special actions inside LLCE. For example, a custom command may be used to provide extra configuration data for a new component integrated into LLCE firmware. A custom command may have an arbitrary 32-bit argument. The usage of this argument is left to the customizer: it may be used as a literal number, or as a pointer to a larger block of data.

When a custom command (LLCE\_CAN\_CMD\_CUSTOM) is sent to LLCE, it triggers the execution of callback functions on each core, except Core 0 (DTE), in this order:

1. Can\_TxCustom\_CustomCmd(User)
2. Can\_RxCustom\_CustomCmd(User)
3. Can\_AfCustom\_CustomCmd(User)

Each callback may prevent the execution of the next one(s) by returning something other than LLCE\_FW\_SUC ← ↩ CESS; in this case, further execution is aborted on the following cores. If a callback is not needed on a particular core, it should be left as the provided stub.

Note

Hint: it is possible to multiplex the custom command, allowing the user to have an arbitrary number of possible custom commands to implement. To do this, use the provided argument slot as a pointer to a structure containing a command code, and arbitrary argument(s), similarly to how LLCE commands work.

## 1.3.15.2 Custom processing filters

It is possible to set up special reception filters, such that the frames they match are directed to a user callback for analysis. To do this, set up an advanced filter with "Custom Processing" enabled, either using the provided drivers, or by generating your own configuration data.

CAN frames matching this filter will be routed to the AF (sometimes called Core 3 - FRPE) core. After processing on the Core 3 (AF), the index is returned to the Core 1 (RXPPE), where another callback allows for post-processing of the earlier result, and further action. The callbacks involved are:

1. Can\_AfCustom\_ProcessMb(User): called on the Core 3 (AF). Convenience parameters are provided to help transform the frame data to a more generic format
2. Can\_AfRx\_ProcessCustomResult(User): called on the Core 1 (RXPPE). May be left as a stub.

Note

Hint: this custom processing is executed after HSE validation (if enabled), but before any other LLCE processing, such as routing or forwarding to host. This way, it is possible for the customizer to selectively prevent actions by manipulating the Served Destinations field for the given message buffer. This is an example of powerful, but risky, options that customization opens.

## 1.3.16 CAN RxLut2 Interrupt Forwarding

When activated, this feature forwards all the interrupts of the CAN RxLut2 from LLCE to the host cores using C ← ↩ ORE2CORE module. The CAN RxLut2 interrupt forwarding is running on the same internal core as the Reception Protocol Processing Engine(RXPPE) - CORE 1. To enable the CAN RxLut2 Interrupt Forwarding:

- Set the second last bit (bit 1) of the CORE2CORE module from Host to Core 1 (RXPPE) - C1INTHR - to enable the interrupt forwarding
- LLCE Firmware will clear the bit after the command is processed.

After an interrupt is detected by the FW, it will set the corresponding bit of the channel into the CORE2CORE module LLCE\_RX2HOST using the bit 4.

## 1.3.17 Fault detection of LLCE cores Rx, Tx and Frpe

This feature periodically reads the value of the Global Timestamp Register for each core except Core0. The value read is written in a dedicated area of the Shared Memory.

When LLCE clock is operating at maximum speed and no CAN frames are being processed, the period is 1ms. The period can vary substantially based on the work load of the LLCE.

The host application shall decide how to drive the Global Timestamp Register.

The memory shared between host and LLCE firmware for timestamps shall be accessed using the data type Llce\_Mgr\_TimeStampCoresType, defined in Llce\_InterfaceFwMgr.h.

The timestamps are located at the following addresses:

Figure 1.16 Timestamp address for each core

<!-- image -->

## 1.3.18 Counters for reception and transmission

This feature stores the number of messages that have been received or transmitted for every of the 16 BCAN controllers.

The counters defined for each BCAN are:

GeneralRx - all CAN frames received by the controller

GeneralTx - all CAN frames sent by the controller and acknowledged on the bus

Can2CanIn - all CAN frames received by the controller from other controllers via CAN

Can2CanOut - all CAN frames sent by the controller to other controller via CAN

Can2Eth - all CAN frames received by controller to be encapsulated in Ethernet format and sent to PFE for transmission over ethernet

Eth2Can - all Ethernet frames transfered from PFE to LLCE controller for decoding and transmission over CAN

The memory shared between host and LLCE firmware for counters shall be accessed using the data type Llce\_Can\_RxTxCountType, defined in Llce\_InterfaceCanTypes.h.

The counters overflow when the top limit is reached. All counters of a BCAN are reset to 0 when the BCAN enters into START state.

The counters are located at the following addresses:

Figure 1.17 Address map for BCANs 0-5.

<!-- image -->

Figure 1.18 Address map for BCANs 6-11.

<!-- image -->

Figure 1.19 Address map for BCANs 12-15.

<!-- image -->

## 1.4 LLCE priority inversion handling

The concept of priority inversion handled by LLCE firmware covers both of these 2 situations:

1. Outer priority inversion: a lower priority message, from another node, interleaves the traffic generated by S32G because LLCE firmware cannot issue a new (higher priority) TX frame within those 3 IFS bits (i.e the stream of high priority messages is disrupted by other node because LLCE is too slow). This risk is mitigated with the help of BCAN controller which is ready to prepare a new transmission much earlier (65 bit time) before the EOF of the ongoing transmission. As soon as the firmware detects the TX frame ready BCAN state, it arbitrates the existing frames, picks the next frame to be transmitted based on the arbitration output and starts loading the frame words into the hardware. The transmission process of a new frame is considered begun even if the effect is not visible on the bus. Early frame arbitration is needed in order to cover the system overall delays, fulfill the back-to-back transmission requirement and avoid priority inversion.

Note

If there is 1 ongoing transmission, no others pending, and 2 new transmissions are requested one next to the other from the host side, and the first one is issued around 65 bit time before the end of the ongoing transmission (i.e before first IFS bit), the chances are that first frame will be directly fed into the hardware, and it will not be arbitrated with the second frame. This is not a case of outer priority inversion.

2. Inner priority inversion: LLCE buffers are full with low priority messages, no new (and higher priority) frame can be issued by S32G to be transmitted on the bus (because a higher priority back-to-back traffic is taking place on the bus). This risk is mitigated by using the cancellation service command: LLCE\_CAN\_CMD\_ABORT\_MB

## 1.5 LLCE LIN firmware

## 1.5.1 LLCE LIN firmware architecture

The Lin LLCE firmware is composed of 4 independent interfaces, one for every channel. All the Lin nodes support Master and Slave configuration. The interface used between the Host and the LLCE firmware is based on Core2Core module. There is only one interrupt line that can be routed to a single Host. All the channels shall be used on the same host. The Lin LLCE firmware is running on the same internal core as the Transmission Protocol Processing Engine(TXPPE) - CORE 2.

There are 3 distinct data areas in the Shared Memory (see Llce\_Lin\_SharedMemoryType ) used for the Lin Interface:

- Commands from Host to LLCE
- Notifications from LLCE to Host
- Data Buffers

The data flow from Host to Lin Firmware and Lin Firmware to Host is exemplified in the following picture:

Figure 1.20 LLCE LIN firmware architecture.

<!-- image -->

## 1.5.2 LLCE LIN firmware interface

In order to configure or interact with the LINFlex controllers the Host and LIN Firmware is communicating via LLCE Interface by using a command mechanism.

The list of available commands exchanged between host and LLCE LIN firmware are enumerated below:

1. LLCE\_LIN\_CMD\_INIT - Initializes the LINFlex controllers. A single INIT command is used to initialize all the LIN channels. This command transfers the configuration from host to LLCE for all LINFlex controllers from one shot using the shared memory of a default channel. See Llce\_Lin\_InitCmdType for more details about command parameters.
2. LLCE\_LIN\_CMD\_GOTOSLEEP - Host sets LIN channel to sleep state. This command affects only one LIN channel. See Llce\_Lin\_WakeupCmdType for more details about command parameters.
3. LLCE\_LIN\_CMD\_GOTOSLEEPINTERNAL - Host sets LIN channel to internal sleep state. This command affects only one LIN channel. See Llce\_Lin\_WakeupCmdType for more details about command parameters.
4. LLCE\_LIN\_CMD\_WAKEUP - Host sends wakeup command to LIN channel. This command affects only one LIN channel. See Llce\_Lin\_WakeupCmdType for more details about command parameters.

## LLCE firmware documentation

5. LLCE\_LIN\_CMD\_WAKEUPINTERNAL - Host sends internal wakeup command to LIN channel. This command affects only one LIN channel. See Llce\_Lin\_WakeupCmdType for more details about command parameters.
6. LLCE\_LIN\_CMD\_GETSTATUS - Host requests the status of LIN channel. This command affects only one LIN channel. See Llce\_Lin\_GetStatusCmdType for more details about command parameters.
7. LLCE\_LIN\_CMD\_SENDFRAME - Host sends a frame on a LIN channel. This command affects only one LIN channel. See Llce\_Lin\_SendFrameCmdType for more details about command parameters.

The notifications generated by the Lin firmware using the Core2Core Module are:

1. LLCE\_LIN\_CMD\_WAKEUP\_CONFIRMATION - Notify the host that the bus was woken up
2. LLCE\_LIN\_CMD\_HEADER\_INDICATION (only for Slave nodes) - Notify the host, that the Lin Slave received a Header. The host needs to decide if the Slave receives or responds to the message.
3. LLCE\_LIN\_CMD\_ERROR\_INDICATION (only for Slave nodes) - Notify the Host about an error detected by the Slave.
4. LLCE\_LIN\_CMD\_RX\_INDICATION (only for Slave nodes) - Notify the Host about an successfully received frame.
5. LLCE\_LIN\_CMD\_TX\_CONFIRMATION (only for Slave nodes) - Notify the Host about an successfully transmitted frame.

Lin firmware is designed to work only in interrupt mode for notifications due to its close relation with the stack running on Host core. After a LLCE\_LIN\_CMD\_HEADER\_INDICATION the Host core must respond quickly enough in order to inform the slave what to do with the received PID. The host response timeout value is given in bit time and represents the maximum amount of time in which the host must fill the slave response. Also, if the Slave needs to respond to the request, the Host core has to complete the rest of the message (payload, length, etc.). The payload is stored in the shared memory in the Lin Data Buffers. The other fields can be found in the Llce\_Lin\_HeaderIndicationCmdType .

An example of using the command interface is sending a frame on the LIN bus. Host software needs to implement the following steps:

1. Host writes a command into the shared memory allocated to a specific channel. See Llce\_Lin\_SendFrameCmdType Write the content of the frame into the shared memory using the Llce\_Lin\_SendFrameCmdType as data type.
2. Host generates an interrupt to Core 2 (TXPPE) for a specific channel by using CORE2CORE hardware module. Flag 0 of each CORE2CORE register is allocated to channel 0 and so on for other channels.
3. Host waits that the command to be executed by the Core 2 (TXPPE) by checking the state of the corresponding flag of CORE2CORE module.
4. LLCE executes the requested command and writes a status code of type Llce\_Lin\_ReturnType from command data type Possible statuses are:
- LLCE\_LIN\_SUCCESS - The command was successfully executed. Note: any ongoing transmission is canceled
- LLCE\_LIN\_ERROR\_STATE - The LIN channel is SLEEP state.
- LLCE\_LIN\_ERROR\_TIMEOUT - There was a timeout condition when communicating with the hardware.

- LLCE\_LIN\_ERROR - There was an error.

Note: Any ongoing transmission is canceled when SendFrame command is executed.

In order to receive a response from a Slave, host needs to implement the following steps:

1. Host polls the LLCE\_LIN\_CMD\_GETSTATUS command until the response is LLCE\_LIN\_RX\_OK .
2. If the response is LLCE\_LIN\_RX\_OK the received data is stored into the shared memory. The LLCE\_LI ← ↩ N\_RXBUFF section contains an array of 4 elements with the Llce\_Lin\_RxMbType , each of the elements corresponds to a hardware channel.

## 1.5.3 LIN Interrupt Forwarding

This feature is designed to completely disable the LIN Firmware of the LLCE and to replace it with a task that forwards the interrupts

To enable the LIN interrupt forwarding:

- Set the Lin\_SharedMemory command ID (eCmdId) field to: LLCE\_LIN\_CMD\_ENABLEINTRFORWARD
- Trigger an interrupt using CORE2CORE module: LLCE\_HOST2TX\_ASSERT\_INTERRUPT on the bit (0,1,2, or 3) of the command, corresponding to the LIN instance
- Check the status in Lin\_SharedMemory eReturnValue value

Lin interrupt forwarding is activated for all the channels and can't be deactivated until a reset of the core. Any other commands are not accepted after the forwarding is enabled. If any other command is sent to LLCE before the forwarding command, it will be ignored. LLCE\_LIN\_CMD\_ENABLEINTRFORWARD must be the first command for the LIN LLCE firmware in order to be accepted.

The LIN interrupt forwarding is implemented with the lowest priority on Core 2 (TXPPE). CAN processing has higher priority due to the timing constrains.

After an interrupt is detected by the FW, it will set the corresponding bit of the channel into the CORE2CORE module LLCE\_TX2HOST using the last 4 bits.

## 1.6 Flexray firmware

## 1.6.1 LLCE Flexray firmware architecture

The LLCE Flexray firmware does not interact actively with the Flexray(FR) peripheral. All Flexray-related code runs on the host core, with direct access to the FR peripheral registers. The LLCE firmware does only help compensate for a limitation of the FR controller hardware - interrupts.

The FR interrupts cannot be directly routed to host cores; instead, a trampoline ISR in the firmware receives the interrupt request from the peripheral, and triggers another interrupt to the host core, via the CORE2CORE module. To reduce complexity, only the Protocol Flag interrupt is forwarded.

In order to forward the interrupt from Flexray controller to host the 4th core (FRPE) included into LLCE hardware architecture will be used.

On startup, the firmware sets up interrupt routing so that it receives the FR Protocol Interrupt request, and to be able to assert the Host from Core 3 interrupt. When a Protocol Interrupt is generated, the firmware sets bit 0 of HINT3CR, causing IRQ 173 to be triggered on the host (if enabled).

## LLCE firmware documentation

Note

Because there is another layer between peripheral and host core, clearing the bit in HINT3CR without removing its cause (i.e. clearing the respective flag in the peripheral) will cause the FW to immediately re-assert the interrupt; the IRQ will trigger twice on the host. To avoid this, clear the interrupt cause before clearing the CORE2CORE flag.

Figure 1.21 LLCE Flexray firmware architecture.

<!-- image -->

## 1.7 SPI firmware

## 1.7.1 SPI Interrupt Forwarding

When activated, this feature forwards all the interrupts of the SPI modules from LLCE to the host cores using CORE2CORE module. The SPI interrupt forwarding is running on the same internal core as the Reception Protocol Processing Engine(RXPPE) - CORE 1.

Figure 1.22 LLCE SPI firmware architecture.

<!-- image -->

To enable the SPI Interrupt Forwarding:

- Set the last bit of the CORE2CORE module from Host to Core 1 (RXPPE) - C1INTHR - to enable the interrupt forwarding
- LLCE Firmware will clear the bit after the command is processed.

After an interrupt is detected by the FW, it will set the corresponding bit of the channel into the CORE2CORE module LLCE\_RX2HOST using the last 4 bits.

## 1.8 Base addresses of the shared memory areas

The host application shall not access at all shared memory area before to be configured(set clock tree, etc.) e.g. Do not define initialized global variable inside shared memory which are initialized by application startup code.

The shared memory range accessible by the host and LLCE: 0x43800000-0x4384FFFF

In order to access the data provided by the LLCE firmware via the shared memory the host software needs to know the following base addresses and access them only by using the data structures presented below and included in the LLCE software interface:

## LLCE firmware documentation

- 0x43800000 The base address of the shared memory area used by the host software and LLCE CAN firmware. Type of variable declared in this area is Llce\_Can\_SharedMemoryType
- 0x4383C8F0 The base address of shared memory area used by the logging host and LLCE CAN firmware. Variable declared in this area: uint32 Llce\_RxMbExtension[4096]. Last byte of each entry can be decoded as the hardware CAN controller which received the frame.
- 0x4383C800 The base address of the shared memory area used by the host software and LLCE LIN firmware. Type of variable declared in this area is Llce\_Lin\_SharedMemoryType
- 0x4383C8A0 The base address of the shared memory area used by the host software and LLCE internal cores for checking LLCE boot completion. Type of variable declared in this area is Llce\_Mgr\_StatusType

## 1.9 Clocking

LLCE uses a system clock (LLCE\_SYS\_CLK) derived from the chip's core clock (XBAR\_DIV2\_CLK). In addition, each peripheral is clocked by its own source: CAN\_PE\_CLK for CAN, LINFLEXD\_CLK and LIN\_BAUD\_CLK for LIN, FLEXRAY\_PE\_CLK for Flexray, PER\_CLK for LPSPI. For details on the clock structure and how to set each clock speed, see the 'Clocking' chapter of the RM.

Note that the system clock (LLCE\_SYS\_CLK = XBAR\_DIV2\_CLK) is required for all operations with LL ← ↩ CE, including loading the firmware. LLCE performance (e.g. reduction of latencies for reception or routing) is proportional to the rate of the system clock. It is recommended that this clock is always set to the maximum allowed speed for optimum performance. Setting the system clock too low may cause operational issues, such as data loss from slow processing of incoming communication.

## 1.10 Build options for the host applications

In order that the host software to be compliant with the LLCE firmware it is needed that the host software to use the following compiler options in order to build the host application:

```
-c -Osize -ansi -G -preprocess_assembly_files --no_exceptions -dual_debug --prototype_errors -Wundef -noslashcomment -Wimplicit-int -Wshadow -Wtrigraphs -nostartfile --no_commons --incorrect_pragma_warnings -keeptempfiles -list --short_enum --gnu_asm --ghstd=last
```

## 1.11 Recommendations for host application

1. The memory controller servicing shared memory shall be enabled/clocked before to access the shared memory area.
2. In order to access the shared memory by using the data structure types presented in the next chapter, it is needed to align all their members to 4 byte boundary. This can be done by using pragma compiler directives.
3. Unaligned accesses to the shared memory area are not supported.
4. Host shall use a timeout condition for commands sent to LLCE for processing. The recommended safe timeout value is: 1ms.
5. It is not recommended for host application to access directly any location in the shared memory, without using the data structures included in the provided LLCE interface.

## 1.11.1 Timestamp activation

The timestamp activation is fully under user control. LLCE does not enable or configure any global register on its own. Thus, the user has to select the timestamp source (recommended STM7 - clock driven XBAR\_DIV2\_CLK), enable the timestamp module in Timestamp Control Register and start the timer.

For bit settings, please see Timestamp Control (Timestamp\_Control\_Register) chapter in Reference Manual.

The block diagram of Timestamp module and all the possible timestamp sources that can be selected, please see Timestamp chapter in Reference Manual.

For configuring STM module, please see System Timer Module (STM) chapter in Reference Manual.

## 1.12 Frequently asked questions

1. Q: Is there separate interrupt for each of RXOUT FIFO NOT\_EMPTY or only an aggregated interrupt which goes to the Host?

A: The hardware FIFOs are organized in groups of 8. Each group has a set of interrupts which are aggregated/concentrated (OR-ed) in a single register (ICSR - interrupt concentrator status register). Each group generates a single interrupt (e.g. for FIFO NOT\_EMPTY) and the host application should read that ICSR register and figure out which is the FIFO which generated the interrupt.

2. Q: Is there a way to recall a TX message that didn't go out from LLCE? A: Yes, The host command eAbortMbType can request cancelling a single tranmission or all pending transmissions with a certain u16FrameTag. In case of S32G2 derivative, if the Tx queue is only 1 element left, it cannot be removed to avoid a race condition. In case of S32G3 derivative, all the queue entries can be removed and cancelled. The number of succesfull cancelled transmissions is notified to the host (u8AbortedFrameCnt), and the indexes are made available to host for new tranmission(s). Due to the intermediate buffers, the Tx message may be in preparation for the next bus transaction, which means that it didn't go out from LLCE, but also that it cannot be recalled.

3. Q: How to identify the receiving CAN controller for a received frame? A: The filter id returned by the LLCE to the host as part of rx descriptor shall be used to identify the related CAN controller based on the filter configuration which is also known to the host side. The filter configuration includes also the controller id.

4. Q: What tools are needed for firmware development? A: LLCE firmware has support for GHS and GCC compilers. Please check the release notes of the FDK product release for the exact versions.

5. Q: How is the timeout detected by LLCE firmware? A: LLCE firmware enables the core's internal Systick timer which is used to detect hardware/software timeouts. The timer is configured to issue an interrupt every 100us. The resolution is high enough to not affect significantly the core load ( ∼ 1%).

6. Q: What happens if LLCE M0+ cores are reset ? A: LLCE cores can be reset without the reloading the code. It will boot again, and the state machine of commands is reinitialized.
7. Q: Why is there a file called PlatformTypes.h which conflicts with AUTOSAR typedefs from Base module ? A: PlatformTypes.h (from llce\_interface) is not meant to be included in the Autosar Drivers. This is used only

in firmware and eventually for non-Autosar drivers.

8. Q: Is it possible to configure e.g. controllers 0-2 to HIF0 and controllers 3-15 to HIF1 in interrupt mode ? A: LLCE allows flexible allocation of CAN controllers to any HIF. This concept enables the mapping of CAN

channels (BCAN, hw channel, CAN controller) to any output FIFO (output interface) for RX and TXACK events. (e.g CAN controllers0,1,2 can be serviced by Llce\_Can\_u32RxoutBaseAddress[0] and by Llce\_Can ← ↩ \_u32TxackBaseAddress[0] (or any of the group FIFOs RXOUT 0-7 and TXACK 0-7 that is routed to HIF0 in the corresponding IRSPRC) and CAN controllers 3,4,..,15 can be serviced by Llce\_Can\_u32RxoutBase ← ↩ Address[8] and by Llce\_Can\_u32TxackBaseAddress[8] (or any of the group RXOUT 8-15 and TXACK 8-15 that is routed to HIF1 in the corresponding IRSPRC) The input FIFOs for TX messages are linked to the corresponding CAN controllers based on 1:1 mapping (e.g FIFOs Llce\_Can\_u32BlroutBaseAddress[3] and Llce\_Can\_u32BlrinBaseAddress[3] are dedicated to CAN controller 3)

9. Q: How to deliver one received CAN message to M7-0, M7-1 and A53 ?

A: LLCE has an unique RXOUT path to delived the RX message to the host and a logging path (FIFO Llce\_Can\_u32RxinLogBaseAddress[0]) used to deliver to a logging core. By design, LLCE can send an RX message to a single host core only, and this was driven by Autosar world where a CAN controller can belong to a unique host software stack. However, the firmware can be customized to support specific customer usecases.

Possible workaround: Configure a filter which delivers the message to the host core (this can be M7-0), to the logging core (this can be A53) and configures a CAN2CAN routing rule that forwards the RX frame to another controller which belongs to M7-1 host and it's configured in self-receive and (optionally) internal loopback mode.

10. Q: Given the shared FIFO which multiplex the RX frame indexes from N CAN controllers, how to decode the BCAN id of each rx message?

A: Use the method described in interface chapter (i.e. Can\_Rx\_aMbHwCtrlExtension[LLCE\_CAN\_CON ← ↩ FIG\_MAXRXMB] array)

## 1.13 External Assumptions

1. Host user shall return in time to the LLCE firmware all indexes read from it.
2. User shall create a network design in order to allow LLCE firmware to send in time the pending CAN frames. In the next chapter are described all software elements shared by LLCE firmware and host software: data types, configuration parameters, etc.

## Chapter 2

## Module Index

## 2.1 Software Specification

Here is a list of all modules:

| LLCE CAN firmware interface . . . . . . .                      |   58 |
|----------------------------------------------------------------|------|
| LLCE precompile configuration parameters . . . . . . .         |  175 |
| LLCE LIN firmware interface .                                  |  191 |
| Platform types used by LLCE firmware . . . . . . . . . . . . . |  200 |
| LLCE headless mode . .                                         |  202 |

## Chapter 3

## Module Documentation

## 3.1 LLCE CAN firmware interface

## 3.1.1 Detailed Description

## Data Structures

- struct Llce\_Can\_MbType
- CAN message buffer. More...
- struct Llce\_Can\_RxMbDescriptorType
- struct Llce\_Can\_ShortMbType
- Reception message buffer descriptor. More...
- struct Llce\_Can\_TxMbDescriptorType

Transmission message buffer descriptor. More...

- struct Llce\_Can\_Tx2HostAckInfoType
- Acknowledge transmission information send from LLCE to host. More...
- struct Llce\_Can\_GetControllerModeCmdType

Command for polling of controller state . More...

- struct Llce\_Can\_SetControllerModeCmdType

Set controller mode command. More...

- struct Llce\_Can\_ControllerFdConfigType

Data baud rate settings for a CAN FD controller. More...

- struct Llce\_Can\_SetBaudrateCmdType

Set baud rate command. More...

- struct Llce\_Can\_ReceiveFilterType

Filter element settings. More...

- struct Llce\_Can\_AuxFilterType

Filter element settings for RxLut2. More...

- struct Llce\_Can\_SetFilterCmdType
- Set filter command. More...
- struct Llce\_Can\_SetAuxFilterCmdType
- Set filter command. More...
- struct Llce\_Can\_Can2CanRoutingTableType

CAN to CAN routing filter configuration. More...

- struct Llce\_Can\_Can2EthRoutingTableType

Data structure type containing CAN to Ethernet destination rule configuration. More...

- struct Llce\_Can\_Can2PcieRoutingTableType

Data structure type containing CAN to PCIe destination rule configuration. More...

- struct Llce\_Can\_Can2HseRoutingTableType

Data structure type containing CAN to HSE destination rule configuration. More...

- struct Can\_Af\_DestRulesType

Data structure type representing destination rule used by Advanced Features(AF) More...

- union Can\_Af\_DestRulesType.AfDest

Destination rule content. More...

- struct Llce\_Can\_AdvancedFeatureType

Advanced filter configuration. More...

- struct Llce\_Can\_AdvancedFilterType

Advanced filter element configuration. More...

- struct Llce\_Can\_SetAdvancedFilterCmdType

Set advanced filter command. More...

- struct Llce\_Can\_ErrorCategoryType

Configurable errors that LLCE Firmware handles. More...

- struct Llce\_Can\_InitPlatformCmdType

Platform initialization command. More...

- struct Llce\_Can\_InitCmdType

Initialization command. More...

- struct Llce\_Can\_InitPfeCmdType

LLCE-PFE Initialization command. More...

- struct Llce\_Can\_InitPfeWithExternRingCmdType

LLCE-PFE Configurable Ring Initialization command. More...

- struct Llce\_Can\_GetStatusCmdType

Get status command. More...

- struct Llce\_Can\_ChangeFilterType

Filter address identifier. More...

- struct Llce\_Can\_CreateAfDestination

Add AF destination command structure. More...

- struct Llce\_Can\_AbortMbCmdType

Abort MB command structure. More...

- struct Llce\_Can\_SetEth2CanFormatStateCmdType

Set Eth2Can decapsulation state. More...

- union Llce\_Can\_CommandListType

List of commands used by host. More...

- struct Llce\_Can\_CommandType

Command used by host. More...

- struct Llce\_Can\_CtrlModeNotifType

Set controller mode notification. More...

- struct Llce\_Can\_ErrorNotifType

Platform specific error. More...

- struct Llce\_Can\_ChannelErrorNotifType

Channel specific error. More...

## Module Documentation

- union Llce\_Can\_NotificationListType
- struct Llce\_Can\_NotificationType

Notifications used by LLCE. More...

- struct Llce\_Can\_NotificationTableType

Notification tables. More...

- struct Llce\_Can\_SharedMemoryType

Shared memory structure. More...

- struct Llce\_Can\_Word0
- struct Llce\_Can\_RxTxCountType

Word0 of a CAN frame. More...

- struct Llce\_Can\_Word1
- Word1 of a CAN frame. More...

## Macros

- #define LLCE\_CAN\_CONTROLLERCONFIG\_CTRL\_EN\_U32

Controller option used by the initialization command in order to inform LLCE firmware that a specific controller shall be initialized. See Llce\_Can\_InitCmdType.

- #define LLCE\_CAN\_CONTROLLERCONFIG\_PE\_EN\_U32

CAN controller option used to enable reporting of the Protocol Exception errors. See Llce\_Can\_GetStatusCmdType.

- #define LLCE\_CAN\_CONTROLLERCONFIG\_TST\_END\_U32

CAN controller option used to enable Timestamp feature.

- #define LLCE\_CAN\_CONTROLLERCONFIG\_TST\_START\_U32
- CAN controller option used to enable Timestamp feature at the start of the CAN frame.
- #define LLCE\_CAN\_CONTROLLERCONFIG\_TST\_FD\_U32
- CAN controller option used to enable Timestamp feature in the start of frame for classical CAN frames and in the res bit for CAN FD frames.
- #define LLCE\_CAN\_CONTROLLERCONFIG\_LOM\_EN\_U32

CAN controller option used to enable Listen-Only mode.

- #define LLCE\_CAN\_CONTROLLERCONFIG\_LPB\_EN\_U32
- CAN controller option used to enable internal LoopBack mode.
- #define LLCE\_CAN\_CONTROLLERCONFIG\_SRX\_EN\_U32
- CAN controller option used to enable self-reception mode.
- #define LLCE\_CAN\_CONTROLLERCONFIG\_ABR\_EN\_U32
- CAN controller option used to enable TX FIFO mode.
- #define LLCE\_CAN\_CONTROLLERCONFIG\_TXFIFO\_EN\_U32

CAN controller option used to enable manual bus-off recovery.

- #define LLCE\_CAN\_RX\_TX\_INTERFACES
- #define LLCE\_CAN\_CONTROLLERCONFIG\_MBR\_EN\_U32
- Number of interfaces used for interrupt reporting (one per channel) + number of polling classes.
- #define LLCE\_CAN\_ACK\_DISABLED
- Default value in the transmission request informing LLCE that tx confirmation is not needed for that frame.
- #define LLCE\_CAN\_MB\_DLC\_MASK\_U32
- #define LLCE\_CAN\_PARAM\_NOT\_USED

Frame DLC field mask.

- #define LLCE\_CAN\_MB\_ID\_MASK\_U32
- Frame ID field mask.

- #define LLCE\_CAN\_MB\_FDF\_U32 Frame FDF field mask. · #define LLCE\_CAN\_MB\_BRS\_U32 Frame BRS field mask. · #define LLCE\_CAN\_MB\_ESI\_U32 Frame ESI field mask. · #define LLCE\_CAN\_MB\_IDE\_U32 Frame IDE field mask. · #define LLCE\_CAN\_MB\_RTR\_U32 Frame RTR field mask. · #define LLCE\_CAN\_MB\_IDSTD\_MASK\_U32 Frame standard ID field mask. · #define LLCE\_CAN\_MB\_IDEXT\_MASK\_U32 Frame extended ID field mask. · #define LLCE\_CAN\_ROUTING\_OPTION\_DEFAULT\_CONFIG Routing feature default configuration. · #define LLCE\_CAN\_ROUTING\_NOCHANGE Routing feature mask for non-converting frame. · #define LLCE\_CAN\_ROUTING\_CAN Routing feature mask for converting frame (CANFD-&gt; CAN). · #define LLCE\_CAN\_ROUTING\_CANFD Routing feature mask for converting frame (CAN-&gt; CANFD). · #define LLCE\_CAN\_ROUTING\_ID\_REMAPPING\_EN Routing feature mask for id remapping. · #define LLCE\_CAN\_MB\_FDF\_SHIFT\_U32 Shift value for extracting FD flag from CAN frame. · #define LLCE\_CAN\_MB\_BRS\_SHIFT\_U32 Shift value for extracting Baud Rate Switch flag from CAN frame. · #define LLCE\_CAN\_MB\_ESI\_SHIFT\_U32 Shift value for extracting ESI flag feature from CAN frame. · #define LLCE\_CAN\_MB\_IDSTD\_SHIFT\_U32 Shift value for extracting frame ID from CAN frame. · #define LLCE\_CAN\_MB\_IDE\_SHIFT\_U32 Shift value for extracting IDE flag from CAN frame. · #define LLCE\_CAN\_MB\_RTR\_SHIFT\_U32 Shift value for extracting RTR flag from CAN frame. · #define LLCE\_CAN\_MB\_PRECALC\_LEN\_SHIFT\_U32 Shift value for extracting precalculated length from CAN frame. · #define LLCE\_CAN\_FULLCAN\_MASK\_U32 Constant used to identify a reserved mask id. · #define LLCE\_CAN2ETH\_PFE\_EMAC0 · #define LLCE\_CAN2ETH\_PFE\_EMAC1 · #define LLCE\_CAN2ETH\_PFE\_EMAC2 · #define LLCE\_CAN2ETH\_PFE\_HIF0 · #define LLCE\_CAN2ETH\_PFE\_HIF1 · #define LLCE\_CAN2ETH\_PFE\_HIF2 · #define LLCE\_CAN2ETH\_PFE\_HIF3

## Module Documentation

```
· #define LLCE_CAN2ETH_PFE_HIFNOCPY · #define LLCE_CAN2ETH_PFE_AUX · #define LLCE_CORE2CORE_BASEADDR Base address for the CORE2CORE module. · #define LLCE_CORE2CORE_HINTC0R · #define LLCE_CORE2CORE_HINTC1R · #define LLCE_CORE2CORE_HINTC2R · #define LLCE_CORE2CORE_HINTC3R · #define LLCE_CORE2CORE_C0INTHR · #define LLCE_CORE2CORE_C1INTHR · #define LLCE_CORE2CORE_C2INTHR · #define LLCE_CORE2CORE_C3INTHR · #define LLCE_CORE2CORE_C0INTCR · #define LLCE_CORE2CORE_C1INTCR · #define LLCE_CORE2CORE_C2INTCR · #define LLCE_CORE2CORE_C3INTCR · #define LLCE_CORE2CORE_HINTC0ER · #define LLCE_CORE2CORE_HINTC1ER · #define LLCE_CORE2CORE_HINTC2ER · #define LLCE_CORE2CORE_HINTC3ER · #define LLCE_CORE2CORE_C0INTHER · #define LLCE_CORE2CORE_C1INTHER · #define LLCE_CORE2CORE_C2INTHER · #define LLCE_CORE2CORE_C3INTHER · #define LLCE_CORE2CORE_C0INTCER · #define LLCE_CORE2CORE_C1INTCER · #define LLCE_CORE2CORE_C2INTCER · #define LLCE_CORE2CORE_C3INTCER · #define LLCE_CORE2CORE_C1INTHR_RXLUT_FLAG · #define LLCE_CORE2CORE_HINTC1R_RXLUT_FLAG · #define LLCE_CORE2DTE_ASSERT_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2DTE_GET_STATUS_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2DTE_CLEAR_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2DTE_ENABLE_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2DTE_DISABLE_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2RX_ASSERT_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2RX_GET_STATUS_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2RX_CLEAR_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2RX_ENABLE_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2RX_DISABLE_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2TX_ASSERT_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2TX_GET_STATUS_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2TX_CLEAR_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2TX_ENABLE_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2TX_DISABLE_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2FRPE_ASSERT_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2FRPE_GET_STATUS_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2FRPE_CLEAR_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2FRPE_ENABLE_INTERRUPT(u8HwCtrl) · #define LLCE_CORE2FRPE_DISABLE_INTERRUPT(u8HwCtrl)
```

- #define LLCE\_HOST2RX\_ASSERT\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2RX\_CLEAR\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2RX\_GET\_STATUS\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2RX\_ENABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_RX2HOST\_ASSERT\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2RX\_DISABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_RX2HOST\_GET\_STATUS\_INTERRUPT(u8HwCtrl)
- #define LLCE\_RX2HOST\_ENABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_RX2HOST\_CLEAR\_INTERRUPT(u8HwCtrl)
- #define LLCE\_RX2HOST\_DISABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2TX\_GET\_STATUS\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2TX\_ASSERT\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2TX\_CLEAR\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2TX\_DISABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2TX\_ENABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_TX2HOST\_ASSERT\_INTERRUPT(u8HwCtrl)
- #define LLCE\_TX2HOST\_CLEAR\_INTERRUPT(u8HwCtrl)
- #define LLCE\_TX2HOST\_GET\_STATUS\_INTERRUPT(u8HwCtrl)
- #define LLCE\_TX2HOST\_ENABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_TX2HOST\_GET\_ENABLE\_STATUS\_INTERRUPT(u8HwCtrl)
- #define LLCE\_TX2HOST\_DISABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2FRPE\_ASSERT\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2FRPE\_CLEAR\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2FRPE\_GET\_STATUS\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2FRPE\_ENABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_FRPE2HOST\_ASSERT\_INTERRUPT(u8HwCtrl)
- #define LLCE\_HOST2FRPE\_DISABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_FRPE2HOST\_GET\_STATUS\_INTERRUPT(u8HwCtrl)

• #define LLCE\_FRPE2HOST\_ENABLE\_INTERRUPT(u8HwCtrl)

- #define LLCE\_FRPE2HOST\_CLEAR\_INTERRUPT(u8HwCtrl)
- #define LLCE\_FRPE2HOST\_DISABLE\_INTERRUPT(u8HwCtrl)
- #define LLCE\_CORE2CORE\_ASSERT\_INTERRUPT(u32BaseAddr, u8HwCtrl)
- #define LLCE\_FRPE2HOST\_GET\_ENABLE\_STATUS\_INTERRUPT(u8HwCtrl)
- #define LLCE\_CORE2CORE\_GET\_STATUS\_INTERRUPT(u32BaseAddr, u8HwCtrl)
- #define LLCE\_CORE2CORE\_ENABLE\_INTERRUPT(u32BaseAddr, u8HwCtrl)
- #define LLCE\_CORE2CORE\_CLEAR\_INTERRUPT(u32BaseAddr, u8HwCtrl)
- #define LLCE\_CORE2CORE\_DISABLE\_INTERRUPT(u32BaseAddr, u8HwCtrl)
- #define LLCE\_CAN\_MB\_RTR\_UNPACKED\_U32
- #define LLCE\_CORE2CORE\_GET\_ENABLE\_STATUS\_INTERRUPT(u32BaseAddr, u8HwCtrl)
- Frame RTR field mask unpacked.
- #define LLCE\_CAN\_MB\_IDE\_UNPACKED\_U32

Frame IDE field mask unpacked.

- #define LLCE\_CAN\_MB\_IDSTD\_MASK\_UNPACKED\_U32

Frame standard ID field mask unpacked.

- #define LLCE\_CAN\_MB\_BRS\_UNPACKED\_U32
- Frame BRS field mask unpacked.
- #define LLCE\_CAN\_MB\_FDF\_UNPACKED\_U32
- Frame FDF field mask unpacked.
- #define LLCE\_CAN\_MB\_ESI\_UNPACKED\_U32

## Module Documentation

```
Frame ESI field mask unpacked. · #define LLCE_GENERIC_FIFO_BASEADDR Base address for Generic FIFO 0. · #define LLCE_ICSR_BASEADDR Base address for the interrupt concentrator registers. · #define LLCE_CONFIG_FIFO_DEPTH_U8 · #define LLCE_FIFO_FFULLD_U32 · #define LLCE_FIFO_FEMTYD_U32 · #define LLCE_FIFO_SR_QCOUNT_SHIFT_U8 · #define LLCE_FIFO_FCR_FIFOEN_U32 · #define LLCE_FIFO_FCR_FLENOWEN_U32 · #define LLCE_FIFO_FCR_POPEN_U32 · #define LLCE_FIFO_FCR_PUSHEN_U32 · #define LLCE_FIFO_FCR_FLUSH_U32 · #define LLCE_FIFO_FCR_RESET_U32 · #define LLCE_FIFO_FFULL_U32 · #define LLCE_FIFO_FNFULL_U32 · #define LLCE_FIFO_FEMTY_U32 · #define LLCE_FIFO_FNEMTY_U32 · #define LLCE_FIFO_POPEVT_U32 · #define LLCE_FIFO_WMKFL_U32 · #define LLCE_FIFO_WMKEM_U32 · #define LLCE_FIFO_POPUND_U32 · #define LLCE_FIFO_PUSHOVR_U32 · #define LLCE_FIFO_MSBNOMT_U32 · #define LLCE_FIFO_NULL_VALUE · #define LLCE_FIFO_0_BASE_ADDRESS · #define LLCE_FIFO_1_BASE_ADDRESS · #define LLCE_FIFO_2_BASE_ADDRESS · #define LLCE_FIFO_3_BASE_ADDRESS · #define LLCE_FIFO_4_BASE_ADDRESS · #define LLCE_FIFO_5_BASE_ADDRESS · #define LLCE_FIFO_6_BASE_ADDRESS · #define LLCE_FIFO_7_BASE_ADDRESS · #define LLCE_FIFO_8_BASE_ADDRESS · #define LLCE_FIFO_9_BASE_ADDRESS · #define LLCE_FIFO_10_BASE_ADDRESS · #define LLCE_FIFO_11_BASE_ADDRESS · #define LLCE_FIFO_12_BASE_ADDRESS · #define LLCE_FIFO_13_BASE_ADDRESS · #define LLCE_FIFO_14_BASE_ADDRESS · #define LLCE_FIFO_15_BASE_ADDRESS · #define LLCE_FIFO_16_BASE_ADDRESS · #define LLCE_FIFO_17_BASE_ADDRESS · #define LLCE_FIFO_18_BASE_ADDRESS · #define LLCE_FIFO_19_BASE_ADDRESS · #define LLCE_FIFO_20_BASE_ADDRESS · #define LLCE_FIFO_21_BASE_ADDRESS · #define LLCE_FIFO_22_BASE_ADDRESS · #define LLCE_FIFO_23_BASE_ADDRESS
```

- #define LLCE\_FIFO\_24\_BASE\_ADDRESS
- #define LLCE\_FIFO\_26\_BASE\_ADDRESS
- #define LLCE\_FIFO\_25\_BASE\_ADDRESS
- #define LLCE\_FIFO\_27\_BASE\_ADDRESS
- #define LLCE\_FIFO\_29\_BASE\_ADDRESS
- #define LLCE\_FIFO\_28\_BASE\_ADDRESS
- #define LLCE\_FIFO\_30\_BASE\_ADDRESS
- #define LLCE\_FIFO\_32\_BASE\_ADDRESS
- #define LLCE\_FIFO\_31\_BASE\_ADDRESS
- #define LLCE\_FIFO\_33\_BASE\_ADDRESS
- #define LLCE\_FIFO\_35\_BASE\_ADDRESS
- #define LLCE\_FIFO\_34\_BASE\_ADDRESS
- #define LLCE\_FIFO\_35\_BASE\_ADDRESS
- #define LLCE\_FIFO\_36\_BASE\_ADDRESS
- #define LLCE\_FIFO\_36\_BASE\_ADDRESS
- #define LLCE\_FIFO\_37\_BASE\_ADDRESS
- #define LLCE\_FIFO\_38\_BASE\_ADDRESS
- #define LLCE\_FIFO\_37\_BASE\_ADDRESS
- #define LLCE\_FIFO\_38\_BASE\_ADDRESS
- #define LLCE\_FIFO\_39\_BASE\_ADDRESS
- #define LLCE\_FIFO\_39\_BASE\_ADDRESS
- #define LLCE\_FIFO\_40\_BASE\_ADDRESS
- #define LLCE\_FIFO\_41\_BASE\_ADDRESS
- #define LLCE\_FIFO\_40\_BASE\_ADDRESS
- #define LLCE\_FIFO\_41\_BASE\_ADDRESS
- #define LLCE\_FIFO\_42\_BASE\_ADDRESS
- #define LLCE\_FIFO\_42\_BASE\_ADDRESS
- #define LLCE\_FIFO\_43\_BASE\_ADDRESS
- #define LLCE\_FIFO\_44\_BASE\_ADDRESS
- #define LLCE\_FIFO\_43\_BASE\_ADDRESS
- #define LLCE\_FIFO\_44\_BASE\_ADDRESS
- #define LLCE\_FIFO\_45\_BASE\_ADDRESS
- #define LLCE\_FIFO\_45\_BASE\_ADDRESS
- #define LLCE\_FIFO\_46\_BASE\_ADDRESS
- #define LLCE\_FIFO\_47\_BASE\_ADDRESS
- #define LLCE\_FIFO\_46\_BASE\_ADDRESS
- #define LLCE\_FIFO\_47\_BASE\_ADDRESS
- #define LLCE\_FIFO\_48\_BASE\_ADDRESS
- #define LLCE\_FIFO\_48\_BASE\_ADDRESS
- #define LLCE\_FIFO\_49\_BASE\_ADDRESS
- #define LLCE\_FIFO\_50\_BASE\_ADDRESS
- #define LLCE\_FIFO\_49\_BASE\_ADDRESS
- #define LLCE\_FIFO\_50\_BASE\_ADDRESS
- #define LLCE\_FIFO\_51\_BASE\_ADDRESS
- #define LLCE\_FIFO\_51\_BASE\_ADDRESS
- #define LLCE\_FIFO\_52\_BASE\_ADDRESS
- #define LLCE\_FIFO\_53\_BASE\_ADDRESS
- #define LLCE\_FIFO\_52\_BASE\_ADDRESS
- #define LLCE\_FIFO\_53\_BASE\_ADDRESS
- #define LLCE\_FIFO\_54\_BASE\_ADDRESS

## Module Documentation

```
· #define LLCE_FIFO_54_BASE_ADDRESS · #define LLCE_FIFO_55_BASE_ADDRESS · #define LLCE_FIFO_55_BASE_ADDRESS · #define LLCE_FIFO_56_BASE_ADDRESS · #define LLCE_FIFO_56_BASE_ADDRESS · #define LLCE_FIFO_57_BASE_ADDRESS · #define LLCE_FIFO_57_BASE_ADDRESS · #define LLCE_FIFO_58_BASE_ADDRESS · #define LLCE_FIFO_58_BASE_ADDRESS · #define LLCE_FIFO_59_BASE_ADDRESS · #define LLCE_FIFO_59_BASE_ADDRESS · #define LLCE_FIFO_60_BASE_ADDRESS · #define LLCE_FIFO_60_BASE_ADDRESS · #define LLCE_FIFO_61_BASE_ADDRESS · #define LLCE_FIFO_61_BASE_ADDRESS · #define LLCE_FIFO_62_BASE_ADDRESS · #define LLCE_FIFO_62_BASE_ADDRESS · #define LLCE_FIFO_63_BASE_ADDRESS · #define LLCE_FIFO_63_BASE_ADDRESS · #define LLCE_FIFO_64_BASE_ADDRESS · #define LLCE_FIFO_64_BASE_ADDRESS · #define LLCE_FIFO_65_BASE_ADDRESS · #define LLCE_FIFO_65_BASE_ADDRESS · #define LLCE_FIFO_66_BASE_ADDRESS · #define LLCE_FIFO_66_BASE_ADDRESS · #define LLCE_FIFO_67_BASE_ADDRESS · #define LLCE_FIFO_67_BASE_ADDRESS · #define LLCE_FIFO_68_BASE_ADDRESS · #define LLCE_FIFO_68_BASE_ADDRESS · #define LLCE_FIFO_69_BASE_ADDRESS · #define LLCE_FIFO_69_BASE_ADDRESS · #define LLCE_FIFO_70_BASE_ADDRESS · #define LLCE_FIFO_70_BASE_ADDRESS · #define LLCE_FIFO_71_BASE_ADDRESS · #define LLCE_FIFO_71_BASE_ADDRESS · #define LLCE_FIFO_72_BASE_ADDRESS · #define LLCE_FIFO_72_BASE_ADDRESS · #define LLCE_FIFO_73_BASE_ADDRESS · #define LLCE_FIFO_74_BASE_ADDRESS · #define LLCE_FIFO_75_BASE_ADDRESS · #define LLCE_FIFO_76_BASE_ADDRESS · #define LLCE_FIFO_77_BASE_ADDRESS · #define LLCE_FIFO_78_BASE_ADDRESS · #define LLCE_FIFO_79_BASE_ADDRESS · #define LLCE_FIFO_80_BASE_ADDRESS · #define LLCE_FIFO_81_BASE_ADDRESS · #define LLCE_FIFO_82_BASE_ADDRESS · #define LLCE_FIFO_83_BASE_ADDRESS · #define LLCE_FIFO_84_BASE_ADDRESS · #define LLCE_FIFO_85_BASE_ADDRESS
```

```
· #define LLCE_FIFO_86_BASE_ADDRESS · #define LLCE_FIFO_87_BASE_ADDRESS · #define LLCE_FIFO_88_BASE_ADDRESS · #define LLCE_FIFO_89_BASE_ADDRESS · #define LLCE_FIFO_90_BASE_ADDRESS · #define LLCE_FIFO_91_BASE_ADDRESS · #define LLCE_FIFO_92_BASE_ADDRESS · #define LLCE_FIFO_93_BASE_ADDRESS · #define LLCE_FIFO_94_BASE_ADDRESS · #define LLCE_FIFO_95_BASE_ADDRESS · #define LLCE_FIFO_96_BASE_ADDRESS · #define LLCE_FIFO_97_BASE_ADDRESS · #define LLCE_FIFO_98_BASE_ADDRESS · #define LLCE_FIFO_99_BASE_ADDRESS · #define LLCE_FIFO_100_BASE_ADDRESS · #define LLCE_FIFO_101_BASE_ADDRESS · #define LLCE_FIFO_102_BASE_ADDRESS · #define LLCE_FIFO_103_BASE_ADDRESS · #define LLCE_FIFO_104_BASE_ADDRESS · #define LLCE_GENERIC_FIFO_0_BASE_ADDRESS · #define LLCE_GENERIC_FIFO_1_BASE_ADDRESS · #define LLCE_GENERIC_FIFO_2_BASE_ADDRESS · #define LLCE_GENERIC_FIFO_3_BASE_ADDRESS · #define LLCE_GET_GENERIC_FIFO_BASE_ADDRESS(u8GenFfo) · #define LLCE_GENERIC_FIFO_CONFIG(u8GenFfo) · #define LLCE_GENERIC_FIFO_STATUS0(u8GenFfo) · #define LLCE_GENERIC_FIFO_STATUS1(u8GenFfo) · #define LLCE_GENERIC_FIFO_IER(u8GenFfo) · #define LLCE_GENERIC_FIFO_ILR(u8GenFfo) · #define LLCE_GENERIC_FIFO_PUSH0(u8GenFfo) · #define LLCE_GENERIC_FIFO_POP0(u8GenFfo) · #define LLCE_GENERIC_FIFO_FMR(u8GenFfo) · #define LLCE_FIFO_CONFIG(u32BaseAddr) · #define LLCE_FIFO_STATUS0(u32BaseAddr) · #define LLCE_FIFO_STATUS1(u32BaseAddr) · #define LLCE_FIFO_IER(u32BaseAddr) · #define LLCE_FIFO_ILR(u32BaseAddr) · #define LLCE_FIFO_PUSH0(u32BaseAddr) · #define LLCE_FIFO_POP0(u32BaseAddr) · #define LLCE_FIFO_FMR(u32BaseAddr) · #define LLCE_FIFO_BLRIN_BASE_ADDRESS(u8HwCtrl) · #define LLCE_FIFO_RXOUT_BASE_ADDRESS(u8HwCtrl) · #define LLCE_FIFO_TXACK_BASE_ADDRESS(u8HwCtrl) · #define LLCE_FIFO_BLROUT_BASE_ADDRESS(u8HwCtrl) · #define LLCE_NOTIF_FIFO0_BASE_ADDRESS(u8HostCore) · #define LLCE_NOTIF_FIFO1_BASE_ADDRESS(u8HostCore) · #define LLCE_FIFO_RXIN_BASE_ADDRESS(u8HostCore) · #define LLCE_FIFO_CMD_BASE_ADDRESS(u8HostCore) · #define LLCE_FIFO_RXINLOG_BASE_ADDRESS() · #define LLCE_FIFO_RXOUTLOG_BASE_ADDRESS()
```

## Module Documentation

```
· #define LLCE_ICSR_ADDR(u8RegNo) · #define LLCE_ICSR_RIFA16_U32 · #define LLCE_ICSR_ROFA16_U32 · #define LLCE_ICSR_TAFA16_U32 · #define LLCE_ICSR_GF0AINT_U32 · #define LLCE_ICSR_GF1AINT_U32 · #define LLCE_ICSR_GF2AINT_U32 · #define LLCE_ICSR_GF3AINT_U32 · #define LLCE_ICSR_GF0BINT_U32 · #define LLCE_ICSR_GF1BINT_U32 · #define LLCE_ICSR_GF2BINT_U32 · #define LLCE_ICSR_GF3BINT_U32 · #define LLCE_ICSR_INTFLAG_00 · #define LLCE_ICSR_INTFLAG_01 · #define LLCE_ICSR_INTFLAG_02 · #define LLCE_ICSR_INTFLAG_03 · #define LLCE_ICSR_INTFLAG_04 · #define LLCE_ICSR_INTFLAG_05 · #define LLCE_ICSR_INTFLAG_06 · #define LLCE_ICSR_INTFLAG_07
```

## Types Reference

```
· typedef Llce_Fw_VersionType Llce_Can_GetFwVersionType Get firmware version command. · typedef uint8 Llce_Can_RemoveAfDestination Remove AF destination command.
```

## Enum Reference

- enum Llce\_Can\_NotificationIdType

```
Notification IDs used to interface with LLCE. · enum Llce_Can_CommandIdType Command IDs used to interface with LLCE. · enum Llce_Can_IdLengthType CAN frame ID type. · enum Llce_Can_StateTransitionType Requested transitions of a CAN controller. · enum Llce_Can_CtrlStateType CAN controller states. · enum Llce_Can_ModuleType CAN firmware components IDs. · enum Llce_Af_LoggingOptionsType CAN Logging options. · enum Llce_Can_HostReceiveOptionsType · enum Llce_Af_AuthenticationOptionsType · enum Llce_Af_CustomProcessingOptionsType
```

· enum Llce\_Can\_EntryType RXLUT entries type. · enum Llce\_Af\_RuleIdType Type of Advanced Feature(AF) rule. · enum Llce\_Can\_EthEncapsulationFormat Type of Can2Eth routing. · enum Llce\_Can\_StatusType Initialization status of the controllers. · enum Llce\_Can\_ErrorProcessingType Processing type of a specific error. · enum Llce\_Can\_AbortMbType AbortMB Type. · enum Llce\_CanRx\_MbLengthType MB length accepted by a filter. · enum Llce\_Can\_BinaryValueType Generic binary type.

## Variables

```
· const uint32 Llce_Can_u32BlrinBaseAddress [(16U)] · const uint32 Llce_Can_u32BlroutBaseAddress [(16U)] · const uint32 Llce_Can_u32TxackBaseAddress [(16U)+(6U)] · const uint32 Llce_Can_u32RxoutBaseAddress [(16U)+(6U)] · const uint32 Llce_Can_u32NotifFifo0BaseAddress [(2U)] · const uint32 Llce_Can_u32NotifFifo1BaseAddress [(2U)] · const uint32 Llce_Can_u32RxinBaseAddress [(2U)] · const uint32 Llce_Can_u32CmdBaseAddress [(2U)] · const uint32 Llce_Can_u32RxinLogBaseAddress [1] · const uint32 Llce_Can_u32RxoutLogBaseAddress [1] · #define LLCE_NCBT_NPRESDIV_SHIFT_U8 Offset bits for NCBT register. · #define LLCE_NCBT_NRJW_SHIFT_U8 · #define LLCE_NCBT_NTSEG2_SHIFT_U8 · #define LLCE_DCBT_DPRESDIV_SHIFT_U8 Offset bits for DCBT register. · #define LLCE_DCBT_DRJW_SHIFT_U8 · #define LLCE_DCBT_DTSEG2_SHIFT_U8
```

## 3.1.2 Data Structure Documentation

## 3.1.2.1 struct Llce\_Can\_MbType

CAN message buffer.

CAN message buffer is a memory area placed in the shared memory which is used by the LLCE firmware to receive/transmit from/to BCAN controller. LLCE firmware transmit/receive the frame in a word by word way so the content of the 4 structure fields contains the frame fields as they are described in the picture from below. For the reception process the LLCE firmware store inside message buffer frame the time stamp read from the hardware CAN controller.

Figure 3.1 LLCE message buffer structure.

<!-- image -->

## Precondition

Before to use any message buffer it is needed to initialize, configure and start a CAN controller

Definition at line 682 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | u32Word0   | INPUT/OUTPUT: The first word of a frame as it is expected/provided by the CAN controller.   |
|----------|------------|---------------------------------------------------------------------------------------------|

## Data Fields

| uint32   | u32Word1         | INPUT/OUTPUT: The second word of a frame as it is expected/provided by the CAN controller.   |
|----------|------------------|----------------------------------------------------------------------------------------------|
| uint8    | u8Payload[(64U)] | INPUT/OUTPUT: Frame payload needed for the maximum payload size case.                        |
| uint32   | u32Timestamp     | INPUT: Time stamp of the received frames.It is not used for the transmitted frames.          |

## 3.1.2.2 struct Llce\_Can\_ShortMbType

Definition at line 708 of file Llce\_InterfaceCanTypes.h.

## Data Fields

| uint32   | u32Word0        | INPUT/OUTPUT: The first word of a frame as it is expected/provided by the CAN controller.   |
|----------|-----------------|---------------------------------------------------------------------------------------------|
| uint32   | u32Word1        | INPUT/OUTPUT: The second word of a frame as it is expected/provided by the CAN controller.  |
| uint8    | u8Payload[(8U)] | INPUT/OUTPUT: Frame payload needed for the short payload size case.                         |
| uint32   | u32Timestamp    | INPUT: Time stamp of the received frames.It is not used for the transmitted frames.         |

## 3.1.2.3 struct Llce\_Can\_RxMbDescriptorType

Reception message buffer descriptor.

Reception message buffer descriptor is a memory area placed in the shared memory which is written by the LLCE firmware with the specific runtime info needed by the host software.(e.g.matching filter ID ). Also it includes an index to a CAN message buffer allocated during initialization to each descriptor. After reception, the host shall copy the content of the reception message buffer descriptor and the referred message buffer by this descriptor from the shared memory into the host memory in order to be processed later by the host software and to allow the current message buffer descriptor to be used by LLCE firmware for the reception of a new frame.

## Precondition

Before to use any receive message buffer descriptor it is needed to initialize, configure and start a CAN controller

Definition at line 750 of file Llce\_InterfaceCanTypes.h.

## Data Fields

| uint16   | u16FilterId        | OUTPUT: Filter identifier resulted at the end of filtering process. This field is completed by the LLCE filtering mechanism with a value which was configured during initialization time. It is used in order to map a received frame to a specific filter defined by the host.   |
|----------|--------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint16   | u16AuxSearchResult | OUTPUT: Result of RxLut2 filtering. See Llce_Can_MbType.                                                                                                                                                                                                                          |

## Module Documentation

## 3.1.2.4 struct Llce\_Can\_TxMbDescriptorType

Transmission message buffer descriptor.

Transmission message buffer descriptor is a memory area placed in the shared memory which is written by the host software with other additional info (e.g. frame tag IDs) which is sent back to the host by the LLCE firmware as acknowledge information. Those internal tags are not changed/used by the LLCE firmware.

## Precondition

Before to use any transmission message buffer descriptor it is needed to initialize, configure and start a CAN controller

Definition at line 781 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint16   | u16FrameTag1       | INPUT: Host defined tag used to track a specific frame. This field is not changed by the LLCE firmware and is returned back to the host as it is. See Llce_Can_Tx2HostAckInfoType   |
|----------|--------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint16   | u16FrameTag2       | INPUT: Host defined tag used to track a specific frame. This field is not changed by the LLCE firmware and is returned back to the host as it is. See Llce_Can_Tx2HostAckInfoType   |
| uint16   | u16MbFrameIdx      | OUTPUT: Index to the frame message buffer. See Llce_Can_MbType.                                                                                                                     |
| uint8    | u8AckInterface     | INPUT: Host defined interface used to select the acknowledge interface of a specific frame. This field is not changed by the LLCE firmware.                                         |
| uint8    | u8EnableTxFrameMac | INPUT: Request firmware to add MAC code to the transmitted frame payload.                                                                                                           |

## 3.1.2.5 struct Llce\_Can\_Tx2HostAckInfoType

Acknowledge transmission information send from LLCE to host.

It is used in order to send from LLCE to host needed information in order to identify and confirm that a specific frame was transmitted on the CAN bus. This data structure type is used in order to implement a circular buffer for each channel which is accessed by using indexes transferred from LLCE to host by using TXACK FIFOs. This approach allows usage of existing hardware FIFOs even the size of the transferred data is higher than the FIFO element width size.

## Precondition

Before to read any acknowledge information, it is needed to do a transmission request.

Definition at line 832 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | u32TxTimestamp   | OUTPUT: Transmission time stamp.   |
|----------|------------------|------------------------------------|

Data Fields

| uint16   | u16FrameTag1   | OUTPUT: Host defined tag used to track a specific frame. This field is not changed by the LLCE firmware and is returned back to the host as it is. See Llce_Can_TxMbDescriptorType.   |
|----------|----------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint16   | u16FrameTag2   | OUTPUT: Host defined tag used to track a specific frame. This field is not changed by the LLCE firmware and is returned back to the host as it is. See Llce_Can_TxMbDescriptorType.   |

## 3.1.2.6 struct Llce\_Can\_GetControllerModeCmdType

Command for polling of controller state .

It is sent from host to LLCE to query it for the controller state.

Definition at line 857 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_CtrlStateType   | eControllerState OUTPUT: Current state of the CAN controller.   |
|--------------------------|-----------------------------------------------------------------|

## 3.1.2.7 struct Llce\_Can\_SetControllerModeCmdType

Set controller mode command.

It is sent from host to LLCE module in order request changing the state of a CAN controller. Currently it allows only to start and stop a controller. When a controller is started it allows to transmit and receive frames from the bus. When the controller is stopped it ignores all frames from the bus and it doesn't transmit any frame.

Precondition

Before changing the controller state it must be initialized.

Definition at line 874 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_StateTransitionType   | eTransition INPUT: The new state which is requested.   |
|--------------------------------|--------------------------------------------------------|

## 3.1.2.8 struct Llce\_Can\_ControllerFdConfigType

Data baud rate settings for a CAN FD controller.

It is used to configure the CAN FD settings including baud rate used during data phase.

## Module Documentation

Definition at line 886 of file Llce\_InterfaceCanTypes.h.

## Data Fields

| uint32   | u32DataBaudrateConfig       | INPUT: Configuration of data phase baud rate: • Prescaler divisor: (bit 23-27) • Resynchronization Jump Width: (bit 16-19) • Time Segment 2: (bit 9-12) • Time Segment 1: (bit 0-4) Each parameter value shall be decreased by 1 when it is written into this data structure field.                                                                                  |
|----------|-----------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint8    | u8FdEnable                  | INPUT: Enable or disable FD related features of the CAN controller.                                                                                                                                                                                                                                                                                                  |
| uint8    | u8ControllerTxBitRateSwitch | INPUT: Enable or disable baud rate switch (BRS) at the level of CAN controller.                                                                                                                                                                                                                                                                                      |
| uint8    | u8TrcvDelayCompEnable       | INPUT: Enable or disable Transceiver Delay Compensation: • TRUE: enabled • FALSE: disabled.                                                                                                                                                                                                                                                                          |
| uint8    | u8TrcvDelayMeasEnable       | INPUT: Enable or disable Transceiver Delay Measurement: • TRUE: enabled • FALSE: disabled. When it is enabled, the secondary sample point is determined by the sum of the transceiver delay measurement plus transceiver delay compensation offset. When it is disabled, the secondary sample point is determined only by the transceiver delay compensation offset. |
| uint8    | u8TrcvDelayCompOffset       | INPUT: Value of Transceiver Delay Compensation Offset.                                                                                                                                                                                                                                                                                                               |

## 3.1.2.9 struct Llce\_Can\_SetBaudrateCmdType

Set baud rate command.

It is sent from host to LLCE module in order to configure baud rate parameters for arbitration phase.

Definition at line 936 of file Llce\_InterfaceCanTypes.h.

## Module Documentation

Data Fields

| uint32                          | u32NominalBaudrateConfig   | INPUT: Configuration parameters for nominal baud rate: • Prescaler divisor: (bit 23-31) • Resynchronization Jump Width (bit 16-22) • Time Segment 2 (bit 9-15) • Time Segment 1 (bit 0-7) Each parameter value shall be decreased by 1 when it is written into this data structure field.   |
|---------------------------------|----------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Llce_Can_ControllerFdConfigType | ControllerFD               | INPUT: Configuration parameters for data baud rate of the CAN controller.                                                                                                                                                                                                                   |

## 3.1.2.10 struct Llce\_Can\_ReceiveFilterType

Filter element settings.

It is used to define a specific filter.Current filtering process suppose to accept a frame if it's frame ID match the filter ID masked with the mask value. At the end of filtering process an internal filter ID is mapped to the accepted frame in order to track it later by the host software. A maximum number of frames accepted by a specific filter can be managed by LLCE at each point in time.

Definition at line 966 of file Llce\_InterfaceCanTypes.h.

Data Fields

|        | uint32 uIdMask   | INPUT: • For MASK filters: Frame id mask value. Bit fields containing 0 means don't care. • For RANGE filters: Maximum accepted id value. • For EXACT MATCH: not used. Set LLCE_CAN_MB_IDE_U32 to match only standard/extended, unset for mixed   |
|--------|------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint32 | uMessageId       | INPUT: • For MASK filters: CAN frame ID value. • For RANGE filters: Minimum accepted id value. • For EXACT MATCH: id value Bit LLCE_CAN_MB_IDE_U32 controls extended/standard if enabled in mask.                                                 |

Data Fields

| uint16                  | u16FilterId       | INPUT: Filter identifier used to track frames after filtering process on the reception side. See also Llce_Can_RxMbDescriptorType.                                                                                                                                                                                                                                                                                     |
|-------------------------|-------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint16                  | u16MbCount        | INPUT: Maximum number of message buffers which can be used to store frames accepted by this filter at each specific point in time. When the maximum value is reached the firmware will begin to drop the received frames accepted by that filter.It is used also in order to prevent that the frames accepted by a specific filter do not overload the LLCE internal hardware resources (e.g. message buffers, FIFOs). |
| uint16                  | u16FilterAddr     | OUTPUT: Filter address inside hardware filtering accelerator where the filter fields are stored. Host side application can use this to track used filter entries. The search operation start from low filter addresses and continue to the high filter addresses.                                                                                                                                                      |
| uint8                   | u8RxDestInterface | INPUT: Reception interface id used to deliver frames accepted by that filter to the host.                                                                                                                                                                                                                                                                                                                              |
| Llce_Can_EntryType      | eEntryType        | INPUT: Filter entry type: mask, range, exact match.                                                                                                                                                                                                                                                                                                                                                                    |
| Llce_CanRx_MbLengthType | eFilterMbLength   | INPUT: Message buffer payload length: 8 or 64 bytes.                                                                                                                                                                                                                                                                                                                                                                   |

## 3.1.2.11 struct Llce\_Can\_AuxFilterType

Filter element settings for RxLut2.

It is used to define a specific filter.Current filtering process supposes to accept a frame if its frame ID matches the filter ID masked with the mask value. At the end of the filtering process, an internal filter ID is mapped to the accepted frame in order to track it later by the host software. A maximum number of frames accepted by a specific filter can be managed by LLCE at each point in time.

Definition at line 1033 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | uIdMask   | INPUT:                                                                                                                                                                                                                                   |
|----------|-----------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|          |           | • For MASK filters: Frame id mask value. Bit fields containing 0 means don't care. • For RANGE filters: Maximum accepted id value. • For EXACT MATCH: not used. Set LLCE_CAN_MB_IDE_U32 to match only standard/extended, unset for mixed |

## Module Documentation

Data Fields

| uint32             | uMessageId         | INPUT: • For MASK filters: CAN frame ID value. • For RANGE filters: Minimum accepted id value. • For EXACT MATCH: id value Bit LLCE_CAN_MB_IDE_U32 controls extended/standard if enabled in mask.   |
|--------------------|--------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint16             | u16AuxSearchResult | INPUT: Custom value configured by the user.                                                                                                                                                         |
| Llce_Can_EntryType | eEntryType         | INPUT: Filter entry type: mask, range, exact match.                                                                                                                                                 |

## 3.1.2.12 struct Llce\_Can\_SetFilterCmdType

Set filter command.

It is sent by the host to LLCE in order to configure one or more reception filters inside LLCE.

Definition at line 1068 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_ReceiveFilterType   | aRxFilters[((uint16) 20U)]   | INPUT: Array containing configuration for reception filters.   |
|------------------------------|------------------------------|----------------------------------------------------------------|
| uint16                       | u16RxFiltersCount            | INPUT: Number of configured filters.                           |

## 3.1.2.13 struct Llce\_Can\_SetAuxFilterCmdType

Set filter command.

It is sent by the host to LLCE in order to configure one or more auxiliary reception filters inside LLCE.

Definition at line 1085 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_AuxFilterType   | aRxAuxFilters[((uint16) 20U)]   | INPUT: Array containing configuration for reception filters.   |
|--------------------------|---------------------------------|----------------------------------------------------------------|
| uint16                   | u16RxAuxFiltersCount            | INPUT: Number of configured filters.                           |

## 3.1.2.14 struct Llce\_Can\_Can2CanRoutingTableType

CAN to CAN routing filter configuration.

It is used to define a specific routing filter. Current routing implementation suppose to accept a received frame for a specific ID and ID mask combination, then route that frame to one or more transmission channels.

Definition at line 1104 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | u32Can2CanRoutingOptions   | INPUT: Special options for advanced routing. See LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG LLCE_CAN_ROUTING_NOCHANGE LLCE_CAN_ROUTING_CAN LLCE_CAN_ROUTING_CANFD LLCE_CAN_ROUTING_ID_REMAPPING_EN.   |
|----------|----------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint32   | u32CanIdRemapValue         | INPUT: Can Id Remap Value. Copied into u32Word0 of outgoing frame, except RTR flag. See Llce_Can_MbType.                                                                                          |
| uint8    | u8DestHwChList[(16U)]      | INPUT: List of destination CAN controllers for the accepted frame.                                                                                                                                |
| uint8    | u8DestHwChListCount        | INPUT: Length of the destination CAN controller list.                                                                                                                                             |

## 3.1.2.15 struct Llce\_Can\_Can2EthRoutingTableType

Data structure type containing CAN to Ethernet destination rule configuration.

It is used to define a specific destination rule for Can2Eth internal routing.

Definition at line 1133 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32                          | pu8Can2EthBuffAddr   | INPUT: Base address of the buffer area for this destination.              |
|---------------------------------|----------------------|---------------------------------------------------------------------------|
| uint16                          | u16Can2EthBuffSize   | INPUT: Size of each buffer for this destination.                          |
| uint8                           | u8Can2EthBuffCount   | INPUT: Number of buffers of size u16Can2EthBuffSize for this destination. |
| Llce_Can_EthEncapsulationFormat | eFormat              | INPUT: Type of encapsulation.                                             |
| uint8                           | u8Can2EthDestMac[6]  | INPUT: Ethernet MAC destination address.                                  |
| uint8                           | u8Can2EthSrcMac[6]   | INPUT: Ethernet MAC source address.                                       |
| uint8                           | u8Can2EthDstIp[16]   | INPUT: Destination IP address (UDP only)                                  |
| uint8                           | u8Can2EthSrcIp[16]   | INPUT: Source IP address (UDP only)                                       |
| uint16                          | u8Can2EthDstPort     | INPUT: Destination port (UDP only)                                        |
| uint16                          | u8Can2EthSrcPort     | INPUT: Source port (UDP only)                                             |
| uint16                          | u16Can2EthPhyIfList  | INPUT: Ethernet physical interface (bit list) - see LLCE_CAN2ETH_PFE_ ∗ . |

## 3.1.2.16 struct Llce\_Can\_Can2PcieRoutingTableType

Data structure type containing CAN to PCIe destination rule configuration.

## Module Documentation

It is used to define a specific destination rule for Can2Pcie routing.

Definition at line 1165 of file Llce\_InterfaceCanTypes.h.

## Data Fields

| uint64   | u64Can2PcieRcBuffAddr   | INPUT: Base address of the buffer area on the RC side.                     |
|----------|-------------------------|----------------------------------------------------------------------------|
| uint32   | pu8Can2PcieBuffAddr     | INPUT: Base address of the local buffer area for this destination.         |
| uint16   | u16Can2PcieBuffSize     | INPUT: Size of each buffer for this destination.                           |
| uint8    | u8Can2PcieBuffCount     | INPUT: Number of buffers of size u16Can2PcieBuffSize for this destination. |
| uint8    | u8Can2PcieController    | INPUT: PCIe controller used.                                               |
| uint8    | u8Can2PcieDmaChannel    | INPUT: PCIe DMA channel used.                                              |
| uint8    | u8Can2PcieMsiId         | INPUT: MSI to trigger on transmission; 0xFF to disable.                    |

## 3.1.2.17 struct Llce\_Can\_Can2HseRoutingTableType

Data structure type containing CAN to HSE destination rule configuration.

It is used to define a specific destination rule for Can2Hse routing.

Definition at line 1189 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | u32Can2HseKeyHandle   | INPUT: Key handle required to compute key on HSE side.   |
|----------|-----------------------|----------------------------------------------------------|

## 3.1.2.18 struct Can\_Af\_DestRulesType

Data structure type representing destination rule used by Advanced Features(AF)

Used to hold a generic type of AF destination rule

Definition at line 1202 of file Llce\_InterfaceCanTypes.h.

Data Fields

| union Can_Af_DestRulesType   | AfDest    | Destination rule content.     |
|------------------------------|-----------|-------------------------------|
| Llce_Af_RuleIdType           | eAfDestId | INPUT: Destination rule type. |

## 3.1.2.19 union Can\_Af\_DestRulesType.AfDest

Destination rule content.

Definition at line 1205 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_Can2CanRoutingTableType   | Can2Can   | INPUT: Destination rule for Can2Can internal routing use case.   |
|------------------------------------|-----------|------------------------------------------------------------------|
| Llce_Can_Can2EthRoutingTableType   | Can2Eth   | INPUT: Destination rule for Can2Eth use case.                    |
| Llce_Can_Can2PcieRoutingTableType  | Can2Pcie  | INPUT: Destination rule for Can2Pcie use case.                   |
| Llce_Can_Can2HseRoutingTableType   | Can2Hse   | INPUT: Destination rule for Can2Hse use case.                    |

## 3.1.2.20 struct Llce\_Can\_AdvancedFeatureType

Advanced filter configuration.

It is used to define an advanced filter. It contains references to the individual features configured by the host.

Definition at line 1228 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Af_AuthenticationOptionsType   | eCanAuthenticationFeature   | INPUT: Option for frame authentication feature.                                                                |
|-------------------------------------|-----------------------------|----------------------------------------------------------------------------------------------------------------|
| Llce_Can_HostReceiveOptionsType     | eHostReceive                | INPUT: Option for host receive feature.                                                                        |
| Llce_Af_LoggingOptionsType          | eCanLoggingFeature          | INPUT: Option for logging feature.                                                                             |
| Llce_Af_CustomProcessingOptionsType | eCanCustomProcessing        | INPUT: Option for custom processing.                                                                           |
| uint8                               | u8Can2CanRoutingTableIdx    | INPUT: CAN2CAN routing table index. Reference to the routing table rule. See Llce_Can_Can2CanRoutingTableType. |
| uint8                               | u8Can2EthRoutingTableIdx    | INPUT: CAN2ETH routing table index. Reference to the routing table rule. See Llce_Can_Can2EthRoutingTableType. |
| uint8                               | u8OtherRoutingTableIdx      | INPUT: Other destination routing table index. Reference to a routing table rule.                               |

## 3.1.2.21 struct Llce\_Can\_AdvancedFilterType

Advanced filter element configuration.

It is used to define a specific filter. Current filtering suppose to accept a frame for processing if it's frame ID match the filter ID masked with the mask value. At the end of filtering process the frame is processed according to the advanced configuration of the filter.

Definition at line 1265 of file Llce\_InterfaceCanTypes.h.

## Module Documentation

Data Fields

| Llce_Can_ReceiveFilterType   | Llce_Can_RxFilter        | INPUT: Standard filter configuration.            |
|------------------------------|--------------------------|--------------------------------------------------|
| Llce_Can_AdvancedFeatureType | Llce_Can_AdvancedFeature | INPUT: Can advanced features used by the filter. |

## 3.1.2.22 struct Llce\_Can\_SetAdvancedFilterCmdType

Set advanced filter command.

It is sent by the host to LLCE in order to set one or more advanced filters.

Definition at line 1278 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_AdvancedFilterType   | aAdvancedFilters[(8U)]   | INPUT: Array containing configuration for one or more filters.   |
|-------------------------------|--------------------------|------------------------------------------------------------------|
| uint16                        | u16RxFiltersCount        | INPUT: Number of configured filters.                             |

## 3.1.2.23 struct Llce\_Can\_ErrorCategoryType

Configurable errors that LLCE Firmware handles.

Configurable errors that LLCE Firmware handles using different types of processing.It is part of platform initialization command. Only BusOff processing type is selectable per channel.

Definition at line 1296 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_ErrorProcessingType   | eCanProtocolErr   | CAN Protocol errors supported by CAN controller.                                                                                                                        |
|--------------------------------|-------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Llce_Can_ErrorProcessingType   | eDataLostErr      | DATALOST event as described by Autosar standard.                                                                                                                        |
| Llce_Can_ErrorProcessingType   | eInitErr          | Initialization errors, like resources overflow, bad commands flow, bad command parameters, invalid indexes or any other errors caused by bad usage or a malicious host. |
| Llce_Can_ErrorProcessingType   | eInternalErr      | Internal errors, like timeouts.                                                                                                                                         |
| Llce_Can_ErrorProcessingType   | eBusOffErr[(16U)] | BusOff processing is selectable per channel.                                                                                                                            |
| Llce_Can_ErrorProcessingType   | eCanProtocolWarn  | Passive state + TX/RX WRN.                                                                                                                                              |

## 3.1.2.24 struct Llce\_Can\_InitPlatformCmdType

Platform initialization command.

It is sent by the host to LLCE in order to configure the platform related parameters. It is the first command which shall be send to LLCE module after booting in order to configure common LLCE components. Most important operations done by LLCE firmware at platform initialization are:

- initializes all common internal LLCE components (hardware and software).
- prepare filter management data structures

Definition at line 1327 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_StatusType        | eCtrlInitStatus[(16U)]            | INPUT: Array containing the initialization status of the controllers.                                                                                                                      |                      |
|----------------------------|-----------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------|
| uint16                     | au16MaxRegularFilterCount[(16U)]  | INPUT: Array containing maximum number of regular filters per channel. See LLCE_CAN_CONTROLLERCONFIG_CTRL_ as a controller option example.                                                 |                      |
| uint16                     | au16MaxAdvancedFilterCount[(16U)] | INPUT: Array containing maximum number of advanced filters per channel. See LLCE_CAN_CONTROLLERCONFIG_CTRL_ as a controller option example.                                                |                      |
| uint16                     | au16MaxIntMbCount[(16U)]          | INPUT: Array containing maximum number of RX message buffers per output interface, considering interrupt processing.                                                                       |                      |
| uint16                     | au16MaxPollMbCount[(6U)]          | INPUT: Array containing maximum number of RX message buffers per polling class, considering polling processing. There are a number of LLCE_CAN_MAX_POLLING_CLASSES provided.               |                      |
| uint16                     | au16MaxIntTxAckCount[(16U)]       | INPUT: Array containing number of reserved TX buffers per output interface, considering interrupt processing.                                                                              | maximum confirmation |
| uint16                     | au16MaxPollTxAckCount[(6U)]       | INPUT: Array containing maximum number of reserved TX confirmation buffers per polling class, considering polling processing. There are a number of LLCE_CAN_MAX_POLLING_CLASSES provided. |                      |
| Llce_Can_ErrorCategoryType | CanErrorReporting                 | INPUT: Structure describing the of processing each errors category. This can be: INTERRUPT, POLLING or IGNORE.                                                                             | way                  |

## Module Documentation

## 3.1.2.25 struct Llce\_Can\_InitCmdType

Initialization command.

It is sent by the host to LLCE in order to load and configure all needed parameters inside LLCE. Most important operations done by LLCE firmware at initialization are:

- when this command is executed for the first CAN channel it initialize also all internal LLCE components.
- configure the hardware features of a CAN controller.
- set a CAN controller in the stop state.

Definition at line 1391 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | u32CtrlConfig   | INPUT: Configuration options for a hardware CAN controller. See LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32 as a controller option example.                                   |
|----------|-----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint8    | u8TxMbCount     | INPUT: Number of transmission message buffer descriptors used for transmissions initialized by the host.The remaining elements are used for internal routing scenarios. |

## 3.1.2.26 struct Llce\_Can\_InitPfeCmdType

LLCE-PFE Initialization command.

It is sent by the host to LLCE in order to activate the LLCE-PFE interface, and obtain the addresses of the relevant data structures.

Note

Use uint32 instead of void ∗ , for portability

Definition at line 1414 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | pRxRing      | OUTPUT: Address of the PFE RX Ring in LLCE memory.           |
|----------|--------------|--------------------------------------------------------------|
| uint32   | pRxWbRing    | OUTPUT: Address of the PFE RX Writeback Ring in LLCE memory. |
| uint32   | pTxRing      | OUTPUT: Address of the PFE TX Ring in LLCE memory.           |
| uint32   | pTxWbRing    | OUTPUT: Address of the PFE TX Writeback Ring in LLCE memory. |
| uint32   | pRxBuffers   | INPUT: Pointer to the buffers used for RX.                   |
| uint16   | u16RxBufSize | INPUT: Size of the buffers used for RX.                      |
| uint8    | u8RxBufCount | INPUT: Number of buffers used for RX.                        |
| uint8    | u8Hif        | INPUT: Index of the PFE HIF to use in LLCE.                  |

## 3.1.2.27 struct Llce\_Can\_InitPfeWithExternRingCmdType

LLCE-PFE Configurable Ring Initialization command.

It is sent by the host to LLCE in order to activate the LLCE-PFE interface, use the addresses of the relevant data structures provided by the host.

Note

Use uint32 instead of void ∗ , for portability

Definition at line 1441 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | pRxRing      | INPUT: Address of the PFE RX Ring in LLCE memory.           |
|----------|--------------|-------------------------------------------------------------|
| uint32   | pRxWbRing    | INPUT: Address of the PFE RX Writeback Ring in LLCE memory. |
| uint32   | pTxRing      | INPUT: Address of the PFE TX Ring in LLCE memory.           |
| uint32   | pTxWbRing    | INPUT: Address of the PFE TX Writeback Ring in LLCE memory. |
| uint32   | pRxBuffers   | INPUT: Pointer to the buffers used for RX.                  |
| uint32   | u32RingSize  | INPUT: Ring size of the PFE Rx Ring.                        |
| uint32   | pHeader      | INPUT: Pointer to the header.                               |
| uint16   | u16RxBufSize | INPUT: Size of the buffers used for RX.                     |
| uint8    | u8RxBufCount | INPUT: Number of buffers used for RX.                       |
| uint8    | u8HeaderSize | INPUT: Size of the header.                                  |
| uint8    | u8Hif        | INPUT: Index of the PFE HIF to use in LLCE.                 |

## 3.1.2.28 struct Llce\_Can\_GetStatusCmdType

Get status command.

It is sent by the host to LLCE in order to get the content of all status registers of a specific CAN controller. This command makes only a read operation on the status registers of CAN controller.

## Module Documentation

| Fleld       | Function                |
|-------------|-------------------------|
| 31-24 DPTEC | DataPhaseTxErrorCounter |
| 23-16 DPREC | DataPhaseRxErrorCounter |
| 15-8 TEC    | TxErrorCounter          |
| 7-0 REC     | RxErrorCounter          |

Figure 3.2 LLCE BCAN ECR.

<!-- image -->

Figure 3.3 LLCE BCAN CRC.

<!-- image -->

Figure 3.4 LLCE BCAN ISR.

<!-- image -->

|                                                              | 30                                                           | 28                                                           | 27                                                                                                                                                                                                                                                                        | 26                                                                                                                                                                                                                                                                        | 25                                                                                                                                                                                                                                                                        | 24                                                                                                                                                                                                                                                                        | 22                                                                                                                                                                                                                                                                        | 21                                                                                                                                                                                                                                                                        | 20                                                                                                                                                                                                                                                                        | 19                                                                                                                                                                                                                                                                        | 18                                                                                                                                                                                                                                                                        | 17                                                                                                                                                                                                                                                                        | 16                                                                                                                                                                                                                                                                        |                                                                                                                                                                                                                                                                           |
|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              | TXWRN RXWRN BDONE PASSER FRZI DPER BOF ER R R Field Function                                                                                                                                                                                                              |
| 30 FRZI                                                      | 30 FRZI                                                      | 30 FRZI                                                      | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       | FreezeModeInterrupt FRZIissetwhenBCANentersFreezemode.If IE[FRZIE]isset,aninterrupt isgeneratedtothehost. FRZIisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence                                                                                       |
| 23 PREXC                                                     | 23 PREXC                                                     | 23 PREXC                                                     | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            | 1b-BCANenteredFreezemode Protocol Exception PREXCindicatesthataprotocolexceptioneventoccurredonCANbusduringaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Protocol exceptionoccurred                                                                            |
| 22 DPERR                                                     | 22 DPERR                                                     | 22 DPERR                                                     | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         | DataPhaseError DPERRindicatesthatoneerroroccurredontheCANbusduringthedataphaseofaCANFDframe.lf zerohasnoeffect. Ob-No such occurrence 1b-Erroroccurredindataphase                                                                                                         |
| 21 TXWRN                                                     | 21 TXWRN                                                     | 21 TXWRN                                                     | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   | TxErrorWarning TXWRNissetwhentheTxerrorcounterECR[TEC]reached96.If IE[TXWRNIE]isset,aninterruptis generated tothehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence                                                                   |
| 20 RXWRN                                                     | 20 RXWRN                                                     | 20 RXWRN                                                     | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      | 1b-Txerrorcounterreached96 RxErrorWarning RXWRNissetwhentheRxerrorcounterECR[REC]reached96.IfIE[RXWRNIE]isset,aninterruptis generated to the host. This field is cleared by writing one to it. Writing zero has no effect. Thisfield isnot updated duringFreezemode.      |
| 19 BDONE                                                     | 19 BDONE                                                     | 19 BDONE                                                     | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate | 1b-RxErrorCounterreached96 Bus-OffDone BDONEissetwhentheTxerrorcounterECR[TEC]hasfinishedcounting128occurrencesof11 set,aninterruptisgeneratedtothehost.Thisfieldisclearedbywritingonetoit.Writingzerohasno effect. Ob-Nosuchoccurrence 1b-BCANisreadytoleaveBus-Offstate |
| 18 BOFF                                                      | 18 BOFF                                                      | 18 BOFF                                                      | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          | Bus-OffState BOFFissetwhenBCANentersBus-Offstate.If IE[BOFFIE]isset,aninterruptisgeneratedtothehost. Thisfieldisclearedbywritingonetoit.Writingzerohasnoeffect. Ob-No such occurrence 1b-BCANenteredBus-Offstate                                                          |
| 17 PASSERR                                                   | 17 PASSERR                                                   | 17 PASSERR                                                   | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               | PassiveErrorState PASSERRissetwhenBCANentersPassivestate.If IE[PASSERRIE]isset,aninterruptisgenerated to thehost.Thisfield isclearedbywritingonetoit.Writingzerohasnoeffect. Ob-Nosuchoccurrence 1b-BCANenteredPassivestate                                               |
| 16 ERR                                                       | 16 ERR                                                       | 16 ERR                                                       | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  | ErrorFlag ERRindicatesthatoneerroroccurredinaCANframeduringthearbitrationphaseordataphase.lf zerohasnoeffect. Ob-Nosuchoccurence 1b-ACANbuserroroccurred                                                                                                                  |

## Module Documentation

| Field        | Function                                                                                                                                                                                                            |
|--------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 31           | LowPowerModeAcknowledge                                                                                                                                                                                             |
| 30 FRZACK    | FreezeModeAcknowledge Ob-BCANisnotinFreezemode 1b-BCANisinFreezemode                                                                                                                                                |
| 29 SRST_PEND | SoftResetPending Ob-Thereisnosoftresetpending 1b-Softreset ispending                                                                                                                                                |
| 14           | Ob-No such occurrence 1b-Overrunhasoccurred DataPhaseCyclicRedundancyCheckError CANFDframe,thatis,thecalculatedCRCisdifferentfromthereceived.                                                                       |
| DPCRCERR     | DPCRCERRindicatesthataCRCerrorhasbeendetectedbythereceivernodeinthedataphaseofa Ob-No such occurrence 1b-ACRCerrorhasoccurred                                                                                       |
| 13 DPFRMERR  | DataPhaseFormError DPFRMERRindicatesthataformerrorhasbeendetectedbythereceivernodeinthedataphaseofa CANFDframe,thatis,afixed-formbitfieldcontainsatleastoneillegalbit. Ob-Nosuchoccurrence 1b-Aformerrorhasoccurred |
| 12 DPSTFERR  | DataPhaseStuffError DPSTFERRindicatesthatastuffingerrorhasbeendetectedbythereceivernodeinthedataphaseofa CANFDframe. Ob-Nosuch occurrence 1b-Astuffingerrorhasoccurred                                              |
| 11 DPBITOERR | DataPhaseBitoError DPBIToERRindicateswhenaninconsistencyoccursbetweenthetransmittedandthereceivedbitinthe dataphaseofaCANFDframe. Ob-Nosuchoccurrence 1b-Abitsentasdominantwasreceivedasrecessive                   |
| 10 DPBIT1ERR | DataPhaseBit1Error DPBIT1ERRindicateswhenaninconsistencyoccursbetweenthetransmittedandthereceivedbitinthe dataphaseofaCANFDframe. Ob-Nosuchoccurrence 1b-Abitsentasrecessivewasreceivedasdominant                   |
| 9 BIT1ERR    | Bit1Error BIT1ERRindicateswhenaninconsistencyoccursbetweenthetransmittedandthereceivedbitinaCAN frame. Ob-Nosuchoccurrence 1b-Abitsentasrecessivewasreceivedasdominant                                              |
| 8 BITOERR    | BitoError BIToERRindicateswhenaninconsistencyoccursbetweenthetransmittedandthereceivedbitinaCAN frame. Ob-Nosuchoccurrence 1b-Abitsentasdominantwasreceivedasrecessive                                              |

<!-- image -->

Figure 3.6 LLCE BCAN SR-2.

| Field       | Function                                                                                                                                                                                                                                                                                                                                                                                                  |
|-------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 7 ACKERR    | AcknowledgeError ACKERRindicatesthatanacknowledgeerrorhasbeendetectedbythetransmitternode,thatis,a dominantbithasnotbeendetectedduringtheACKSLoT. Ob-Nosuchoccurrence 1b-Anacknowledgeerrorhasoccurred                                                                                                                                                                                                    |
| 6 CRCERR    | CyclicRedundancyCheckError calculatedCRCisdifferentfromthereceived. Ob-No suchoccurrence 1b-A CRCerrorhasoccurred                                                                                                                                                                                                                                                                                         |
| 5 FRMERR    | FormError FRMERRindicatesthataformerrorhasbeendetectedbythereceivernodeinaCANframe,thatis,a fixed-formbitfieldcontainsatleastoneillegalbit. Ob-Nosuchoccurrence 1b-Aformerrorhasoccurred                                                                                                                                                                                                                  |
| 4 STFERR    | StuffingError STFERRindicatesthatastuffingerrorhasbeendetectedbythereceivernodeinaCANframe. Ob-Nosuchoccurrence 1b-Astuffingerrorhasoccurred                                                                                                                                                                                                                                                              |
| 3-2 FLTCONF | FaultConfinement FLTCONFindicatestheconfinementstateoftheBCANmodule. 00b-Error active 01b-Errorpassive 1xb-BusOff                                                                                                                                                                                                                                                                                         |
| 1-0 CANCS   | CANCommunicationState CANcSindicateswhichisthecurrentCANcommunicationstate.IntegratingstatemeansthatBCANis detecting11recessivebitstosynchronizewithCANbus,thatis,BCANhasjustleftFreezemodeorBus- OffstatetostartCANbuscommunication,orBCANisinProtocol Exceptionstate.Idleconditionmeans thatthereisnoCANbuscommunicationafteraninterframespace. oob-Integrating 01b-ldle 10b-Receiving 11b-Transmitting |

Definition at line 1500 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | u32ECR   | OUTPUT: Register ECR of CAN controller.   |
|----------|----------|-------------------------------------------|
| uint32   | u32ISR   | OUTPUT: Register ISR of CAN controller.   |
| uint32   | u32SR    | OUTPUT: Register SR of CAN controller.    |
| uint32   | u32CRC   | OUTPUT: Register CRC of CAN controller.   |

## 3.1.2.29 struct Llce\_Can\_ChangeFilterType

Filter address identifier.

It is sent by the host to LLCE in order to disable/enable a specific filter, identified by its address

| Type   | Direction   | Name            | Disable filter   | Enable filter   |
|--------|-------------|-----------------|------------------|-----------------|
| uint8  | in          | u8FilterEnabled | 0U               | 1U              |

## Module Documentation

Definition at line 1530 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint16   | u16FilterAddr   | INPUT: Address of the filter which shall be removed/disabled/enabled.                                                     |
|----------|-----------------|---------------------------------------------------------------------------------------------------------------------------|
| uint8    | u8FilterEnabled | INPUT: Request new state (0 - disable filter / 1 - enable filter) of the filter when using SetFilterEnableStatus command. |

## 3.1.2.30 struct Llce\_Can\_CreateAfDestination

Add AF destination command structure.

It is sent by the host to LLCE in order add a destination to be used by AF

Definition at line 1547 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Can_Af_DestRulesType   | rule   | INPUT: Destination to add to the list.                     |
|------------------------|--------|------------------------------------------------------------|
| uint8                  | u8Idx  | OUTPUT: Index in LLCE list where destination was inserted. |

## 3.1.2.31 struct Llce\_Can\_AbortMbCmdType

Abort MB command structure.

It is sent by the host to LLCE in order to abort the lowest priority pending transmission of a specific controller.

Definition at line 1570 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint16               | u16FrameTag       | INPUT: Host defined tag used to track a specific frame. See Llce_Can_TxMbDescriptorType.   |
|----------------------|-------------------|--------------------------------------------------------------------------------------------|
| uint8                | u8AbortedFrameCnt | OUTPUT: Number of Tx pending transmissions aborted.                                        |
| Llce_Can_AbortMbType | eAbortMbType      | INPUT: Specifies the type of AbortMB command.                                              |

## 3.1.2.32 struct Llce\_Can\_SetEth2CanFormatStateCmdType

Set Eth2Can decapsulation state.

It is sent by the host to LLCE in order to turn on or off decapsulation for a given format.

Definition at line 1589 of file Llce\_InterfaceCanTypes.h.

## Data Fields

| Llce_Can_EthEncapsulationFormat   | eFormat   | INPUT: Encapsulation format.   |
|-----------------------------------|-----------|--------------------------------|
| Llce_Can_BinaryValueType          | eState    | INPUT: State to set.           |

## 3.1.2.33 union Llce\_Can\_CommandListType

List of commands used by host.

It is used in order to use the same memory area for all commands send from host to LLCE.

Definition at line 1604 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_InitCmdType                  | Init                  | Command for initializing a specific CAN channel.                                                               |
|---------------------------------------|-----------------------|----------------------------------------------------------------------------------------------------------------|
| Llce_Can_GetStatusCmdType             | GetStatus             | Command for getting the hardware status information for a specific CAN controller.                             |
| Llce_Can_SetFilterCmdType             | SetFilter             | Command for configuring filters for a specific CAN controller in order to deliver frames to the host.          |
| Llce_Can_SetAdvancedFilterCmdType     | SetAdvancedFilter     | Command for configuring filters in order to route frames to other destinations than host.                      |
| Llce_Can_ChangeFilterType             | ChangeFilter          | Hardware address of filter to disable/enable/remove.                                                           |
| Llce_Can_SetBaudrateCmdType           | SetBaudrate           | Command for configuring baud rate parameters for a specific CAN controller.                                    |
| Llce_Can_GetControllerModeCmdType     | GetControllerMode     | Command for getting the status of a specific CAN controller.                                                   |
| Llce_Can_SetControllerModeCmdType     | SetControllerMode     | Command for changing the status of a specific CAN controller.                                                  |
| Llce_Can_GetFwVersionType             | GetFwVersion          | Command for getting the firmware version.                                                                      |
| Llce_Can_InitPlatformCmdType          | InitPlatform          | Command for configuring platform related parameters and common HW components used by all CAN channels.         |
| Llce_Can_InitPfeCmdType               | InitPfe               | Command for initializing the LLCE-PFE interface and getting buffer locations.                                  |
| Llce_Can_InitPfeWithExternRingCmdType | InitPfeWithExternRing | Command for initializing the LLCE-PFE interface using user's ring buffer input.                                |
| Llce_Can_CreateAfDestination          | CreateAfDest          | Command for creating a destination for AF.                                                                     |
| Llce_Can_RemoveAfDestination          | RemoveAfDest          | Command for removing a destination for AF.                                                                     |
| Llce_Can_AbortMbCmdType               | AbortMb               | Command for aborting either the lowest priority message buffer or all the message buffers with a specific tag. |

## Module Documentation

Data Fields

| uint32                                | pCustomCmdArg         | Pointer to argument for custom command.                                                                      |
|---------------------------------------|-----------------------|--------------------------------------------------------------------------------------------------------------|
| Llce_Can_SetAuxFilterCmdType          | SetAuxFilter          | Command for configuring custom filters for a specific CAN controller in order to deliver frames to the host. |
| Llce_Can_BinaryValueType              | eBinaryValue          | Generic argument for binary values.                                                                          |
| Llce_Can_SetEth2CanFormatStateCmdType | SetEth2CanFormatState | Command for turning Eth2Can on or off for a certain format.                                                  |

## 3.1.2.34 struct Llce\_Can\_CommandType

Command used by host.

It is used in order to send commands from host to LLCE using shared memory.

Definition at line 1685 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_CommandListType   | CmdList      | INPUT: Command parameters.                           |
|----------------------------|--------------|------------------------------------------------------|
| Llce_Can_CommandIdType     | eCmdId       | INPUT: Command ID.                                   |
| Llce_Fw_ReturnType         | eReturnValue | OUTPUT: Return status code after command completion. |

## 3.1.2.35 struct Llce\_Can\_CtrlModeNotifType

Set controller mode notification.

Notification send from LLCE to host in order to inform about a specific controller state change.

Definition at line 1701 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_CtrlStateType   | eControllerState   | OUTPUT: Current state of the CAN controller. See also Llce_Can_CtrlStateType.   |
|--------------------------|--------------------|---------------------------------------------------------------------------------|
| uint8                    | u8HwCtrl           | OUTPUT: CAN controller id.                                                      |

## 3.1.2.36 struct Llce\_Can\_ErrorNotifType

Platform specific error.

Platform error details send to host in order to report an internal LLCE error.

Definition at line 1718 of file Llce\_InterfaceCanTypes.h.

## Module Documentation

Data Fields

| Llce_Can_ModuleType   | eModuleId            | OUTPUT: LLCE firmware component id. See also Llce_Can_ModuleType.   |
|-----------------------|----------------------|---------------------------------------------------------------------|
| Llce_Fw_ReturnType    | eErrorCode           | OUTPUT: LLCE error code. See also Llce_Fw_ReturnType.               |
|                       | uint16 u16ErrorCount | OUTPUT: Number of occurrences of the last error.                    |

## 3.1.2.37 struct Llce\_Can\_ChannelErrorNotifType

Channel specific error.

Channel error details send to host in order to report an internal LLCE error.

Definition at line 1738 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_ErrorNotifType   | ErrorInfo   |                        |
|---------------------------|-------------|------------------------|
| uint8                     | u8HwCtrl    | OUTPUT: Controller ID. |

## 3.1.2.38 union Llce\_Can\_NotificationListType

List of notifications send by LLCE to host, used by host.

It is used by LLCE to notify host about specific events inside LLCE.

Definition at line 1750 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_CtrlModeNotifType     | CtrlMode      | OUTPUT: Notification parameters for controller state changes. See also Llce_Can_CtrlModeNotifType.   |
|--------------------------------|---------------|------------------------------------------------------------------------------------------------------|
| Llce_Can_ErrorNotifType        | PlatformError | OUTPUT: Notification parameters for platform errors. See also Llce_Can_ErrorNotifType.               |
| Llce_Can_ChannelErrorNotifType | ChannelError  | OUTPUT: Notification parameters for channel errors. See also Llce_Can_ChannelErrorNotifType.         |

## 3.1.2.39 struct Llce\_Can\_NotificationType

Notifications used by LLCE.

It is used in order to send notifications from LLCE to host by using shared memory.

Definition at line 1774 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_NotificationListType   | NotifList   | OUTPUT: Notification parameters. See also Llce_Can_NotificationListType.   |
|---------------------------------|-------------|----------------------------------------------------------------------------|
| Llce_Can_NotificationIdType     | eNotifId    | OUTPUT: Notification ID. See also Llce_Can_NotificationIdType.             |

## 3.1.2.40 struct Llce\_Can\_NotificationTableType

Notification tables.

Notification tables used to store the details of the notifications. The index of entries are sent to host cores.The two tables are related to reporting method:interrupt or polling.

Definition at line 1795 of file Llce\_InterfaceCanTypes.h.

Data Fields

| Llce_Can_NotificationType   | Can_aNotif0_Table[(2U)][(17U)]   | OUTPUT: Table used to report notifications in interrupt mode. See also Llce_Can_NotificationType.   |
|-----------------------------|----------------------------------|-----------------------------------------------------------------------------------------------------|
| Llce_Can_NotificationType   | Can_aNotif1_Table[(2U)][(17U)]   | OUTPUT: Table used to report notifications in polling mode. See also Llce_Can_NotificationType.     |

## 3.1.2.41 struct Llce\_Can\_SharedMemoryType

Shared memory structure.

Structure that encapsulates all the shared memory with LLCE on the CAN side.

Definition at line 1818 of file Llce\_InterfaceCanTypes.h.

## Data Fields

- Llce\_Can\_RxMbDescriptorType Can\_Rx\_aMbDesc [(1732U)+(2396U)]
- Receive message buffer descriptors.
- Llce\_Can\_TxMbDescriptorType Can\_Tx\_aMbDesc [(256U)]

Transmit message buffer descriptors.

- Llce\_Can\_MbType Can\_aMb [(1732U)+(256U)+(256U)]

Shared memory used to store the LONG CAN message buffers (64B).

- Llce\_Can\_ShortMbType Can\_aSMb [(2396U)]

Shared memory used to store the SHORT CAN message buffers (8B).

- Llce\_Can\_CommandType aCanCmd [(2U)]

## Module Documentation

Shared memory used to send commands from Host to LLCE .

- Llce\_Can\_NotificationTableType Can\_NotificationTable

Shared memory used to store notifications from LLCE to host.

- Llce\_Can\_Tx2HostAckInfoType Can\_Tx\_aAckInfo [((uint16)(512U+((uint8)((16U)+(6U)))))]

Circular buffer used to send ACK info from TX core to HOST core. Reserved 1 extra buffer for each interface for consistency purposes.

## 3.1.2.41.1 Field Documentation

```
3.1.2.41.1.1 Can_Rx_aMbDesc Llce_Can_RxMbDescriptorType Can_Rx_aMbDesc[(1732U)+(2396U)]
```

Receive message buffer descriptors.

Definition at line 1821 of file Llce\_InterfaceCanTypes.h.

```
3.1.2.41.1.2 Can_Tx_aMbDesc Llce_Can_TxMbDescriptorType Can_Tx_aMbDesc[(256U)]
```

Transmit message buffer descriptors.

Definition at line 1823 of file Llce\_InterfaceCanTypes.h.

```
3.1.2.41.1.3 Can_aMb Llce_Can_MbType Can_aMb[(1732U)+(256U)+(256U)]
```

Shared memory used to store the LONG CAN message buffers (64B).

Definition at line 1825 of file Llce\_InterfaceCanTypes.h.

```
3.1.2.41.1.4 Can_aSMb Llce_Can_ShortMbType Can_aSMb[(2396U)]
```

Shared memory used to store the SHORT CAN message buffers (8B).

Definition at line 1829 of file Llce\_InterfaceCanTypes.h.

```
3.1.2.41.1.5 aCanCmd Llce_Can_CommandType aCanCmd[(2U)]
```

Shared memory used to send commands from Host to LLCE .

Definition at line 1832 of file Llce\_InterfaceCanTypes.h.

## 3.1.2.41.1.6 Can\_NotificationTable Llce\_Can\_NotificationTableType Can\_NotificationTable

Shared memory used to store notifications from LLCE to host.

Definition at line 1835 of file Llce\_InterfaceCanTypes.h.

3.1.2.41.1.7 Can\_Tx\_aAckInfo Llce\_Can\_Tx2HostAckInfoType Can\_Tx\_aAckInfo[((uint16)(512U+((uint8)((16U)+(6U)))

Circular buffer used to send ACK info from TX core to HOST core. Reserved 1 extra buffer for each interface for consistency purposes.

Definition at line 1841 of file Llce\_InterfaceCanTypes.h.

## 3.1.2.42 struct Llce\_Can\_RxTxCountType

Definition at line 1844 of file Llce\_InterfaceCanTypes.h.

Data Fields

| uint32   | u32GeneralRxCount   | Shows the number of CAN frames received by each controller.                                                                 |
|----------|---------------------|-----------------------------------------------------------------------------------------------------------------------------|
| uint32   | u32GeneralTxCount   | Shows the number of CAN frames sent by each controller and acknowledged on the bus.                                         |
| uint32   | u32Can2CanInCount   | All CAN frames received by the controller from other controllers via CAN.                                                   |
| uint32   | u32Can2CanOutCount  | All CAN frames sent by the controller to other controller via CAN.                                                          |
| uint32   | u32Can2EthCount     | All CAN frames received by controller to be encapsulated in Ethernet format and sent to PFE for transmission over ethernet. |
| uint32   | u32Eth2CanCount     | All Ethernet frames transfered from PFE to LLCE controller for decoding and transmission over CAN.                          |
| uint32   | u32ReservedCount1   | Reserved for future use.                                                                                                    |
| uint32   | u32ReservedCount2   | Reserved for future use.                                                                                                    |
| uint32   | u32ReservedCount3   | Reserved for future use.                                                                                                    |
| uint32   | u32ReservedCount4   | Reserved for future use.                                                                                                    |

## 3.1.2.43 struct Llce\_Can\_Word0

Word0 of a CAN frame.

It contains the message ID and related configurations.

Definition at line 106 of file Llce\_InterfaceCanUtils.h.

## Module Documentation

Data Fields

| uint32   | u32Id   | INPUT/OUTPUT: Can frame Standard or Extended ID field. In base frame format, only the 11 most significant bits (28-18) are used for frame identification. The 18 least significant bits are ignored. In extended frame format, all bits (0-28) are used for frame identification.                                                                                                                                    |
|----------|---------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint8    | u8Rtr   | INPUT/OUTPUT: Can frame Remote Transmission Request field. If BCAN transmits this bit as one (recessive) and receives it as zero (dominant), it is interpreted as an arbitration loss. If this bit is transmitted as zero (dominant), then if it is received as one (recessive), BCAN treats it as a bit error. If the value received matches the value transmitted, it is considered a successful bit transmission. |
| uint8    | u8Ide   | INPUT/OUTPUT: Can frame Identifier Extension field. This field identifies whether the frame format is base (standard ID) or extended.                                                                                                                                                                                                                                                                                |

## 3.1.2.44 struct Llce\_Can\_Word1

Word1 of a CAN frame.

It contains CAN frame format and bit rate related configurations.

Definition at line 141 of file Llce\_InterfaceCanUtils.h.

Data Fields

| uint8   | u8Dlc   | INPUT/OUTPUT: Can frame Data Length Code field. This 4-bit field defines the number of bytes in the data field of a CAN frame (DATA BYTE 0 to DATA BYTE 63). When RTR = 1, the frame is a remote request and does not include the data field, regardless of the DLC field.   |
|---------|---------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| uint8   | u8Fdf   | INPUT/OUTPUT: Can frame FD Format Indicator field. This bit distinguishes between classical CAN format and CAN FD format frames.                                                                                                                                             |
| uint8   | u8Brs   | INPUT/OUTPUT: Can frame Bit Rate Switch field. This bit defines whether the bit rate is switched inside a CAN FD frame. This bit is meaningful only if FDF = 1, otherwise it is not used by BCAN.                                                                            |
| uint8   | u8Esi   | INPUT/OUTPUT: Can frame Error State Indicator field. This bit indicates if the transmitting node is error active or error passive. This bit is meaningful only if FDF = 1, otherwise it is not used by BCAN.                                                                 |

## 3.1.3 Macro Definition Documentation

## 3.1.3.1 LLCE\_NCBT\_NPRESDIV\_SHIFT\_U8

#define LLCE\_NCBT\_NPRESDIV\_SHIFT\_U8

Offset bits for NCBT register.

Definition at line 118 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.2 LLCE\_NCBT\_NRJW\_SHIFT\_U8

#define LLCE\_NCBT\_NRJW\_SHIFT\_U8

Definition at line 119 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.3 LLCE\_NCBT\_NTSEG2\_SHIFT\_U8

#define LLCE\_NCBT\_NTSEG2\_SHIFT\_U8

Definition at line 120 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.4 LLCE\_DCBT\_DPRESDIV\_SHIFT\_U8

#define LLCE\_DCBT\_DPRESDIV\_SHIFT\_U8

Offset bits for DCBT register.

Definition at line 127 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.5 LLCE\_DCBT\_DRJW\_SHIFT\_U8

#define LLCE\_DCBT\_DRJW\_SHIFT\_U8

Definition at line 128 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.6 LLCE\_DCBT\_DTSEG2\_SHIFT\_U8

#define LLCE\_DCBT\_DTSEG2\_SHIFT\_U8

Definition at line 129 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.7 LLCE\_CAN\_CONTROLLERCONFIG\_CTRL\_EN\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_CTRL\_EN\_U32

Controller option used by the initialization command in order to inform LLCE firmware that a specific controller shall be initialized. See Llce\_Can\_InitCmdType.

Definition at line 140 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.8 LLCE\_CAN\_CONTROLLERCONFIG\_PE\_EN\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_PE\_EN\_U32

CANcontroller option used to enable reporting of the Protocol Exception errors. See Llce\_Can\_GetStatusCmdType.

Definition at line 146 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.9 LLCE\_CAN\_CONTROLLERCONFIG\_TST\_END\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_TST\_END\_U32

CAN controller option used to enable Timestamp feature.

Definition at line 148 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.10 LLCE\_CAN\_CONTROLLERCONFIG\_TST\_START\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_TST\_START\_U32

CAN controller option used to enable Timestamp feature at the start of the CAN frame.

Definition at line 153 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.11 LLCE\_CAN\_CONTROLLERCONFIG\_TST\_FD\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_TST\_FD\_U32

CAN controller option used to enable Timestamp feature in the start of frame for classical CAN frames and in the res bit for CAN FD frames.

Definition at line 158 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.12 LLCE\_CAN\_CONTROLLERCONFIG\_LOM\_EN\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_LOM\_EN\_U32

CAN controller option used to enable Listen-Only mode.

Definition at line 160 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.13 LLCE\_CAN\_CONTROLLERCONFIG\_LPB\_EN\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_LPB\_EN\_U32

CAN controller option used to enable internal LoopBack mode.

Definition at line 162 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.14 LLCE\_CAN\_CONTROLLERCONFIG\_SRX\_EN\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_SRX\_EN\_U32

CAN controller option used to enable self-reception mode.

CAN controller option used to enable automatic bus-off recovery.

Definition at line 165 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.15 LLCE\_CAN\_CONTROLLERCONFIG\_ABR\_EN\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_ABR\_EN\_U32

CAN controller option used to enable TX FIFO mode.

Definition at line 167 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.16 LLCE\_CAN\_CONTROLLERCONFIG\_TXFIFO\_EN\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_TXFIFO\_EN\_U32

CAN controller option used to enable manual bus-off recovery.

Definition at line 169 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.17 LLCE\_CAN\_CONTROLLERCONFIG\_MBR\_EN\_U32

#define LLCE\_CAN\_CONTROLLERCONFIG\_MBR\_EN\_U32

Definition at line 170 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.18 LLCE\_CAN\_RX\_TX\_INTERFACES

#define LLCE\_CAN\_RX\_TX\_INTERFACES

Number of interfaces used for interrupt reporting (one per channel) + number of polling classes.

Definition at line 175 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.19 LLCE\_CAN\_ACK\_DISABLED

#define LLCE\_CAN\_ACK\_DISABLED

Default value in the transmission request informing LLCE that tx confirmation is not needed for that frame.

Definition at line 181 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.20 LLCE\_CAN\_PARAM\_NOT\_USED

#define LLCE\_CAN\_PARAM\_NOT\_USED

Definition at line 182 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.21 LLCE\_CAN\_MB\_DLC\_MASK\_U32

#define LLCE\_CAN\_MB\_DLC\_MASK\_U32

Frame DLC field mask.

Definition at line 188 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.22 LLCE\_CAN\_MB\_ID\_MASK\_U32

#define LLCE\_CAN\_MB\_ID\_MASK\_U32

Frame ID field mask.

Definition at line 190 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.23 LLCE\_CAN\_MB\_FDF\_U32

#define LLCE\_CAN\_MB\_FDF\_U32

Frame FDF field mask.

Definition at line 192 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.24 LLCE\_CAN\_MB\_BRS\_U32

#define LLCE\_CAN\_MB\_BRS\_U32

Frame BRS field mask.

Definition at line 194 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.25 LLCE\_CAN\_MB\_ESI\_U32

#define LLCE\_CAN\_MB\_ESI\_U32

Frame ESI field mask.

Definition at line 196 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.26 LLCE\_CAN\_MB\_IDE\_U32

#define LLCE\_CAN\_MB\_IDE\_U32

Frame IDE field mask.

Definition at line 198 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.27 LLCE\_CAN\_MB\_RTR\_U32

#define LLCE\_CAN\_MB\_RTR\_U32

Frame RTR field mask.

Definition at line 200 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.28 LLCE\_CAN\_MB\_IDSTD\_MASK\_U32

#define LLCE\_CAN\_MB\_IDSTD\_MASK\_U32

Frame standard ID field mask.

Definition at line 202 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.29 LLCE\_CAN\_MB\_IDEXT\_MASK\_U32

#define LLCE\_CAN\_MB\_IDEXT\_MASK\_U32

Frame extended ID field mask.

Definition at line 204 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.30 LLCE\_CAN\_ROUTING\_OPTION\_DEFAULT\_CONFIG

#define LLCE\_CAN\_ROUTING\_OPTION\_DEFAULT\_CONFIG

Routing feature default configuration.

Definition at line 206 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.31 LLCE\_CAN\_ROUTING\_NOCHANGE

#define LLCE\_CAN\_ROUTING\_NOCHANGE

Routing feature mask for non-converting frame.

Definition at line 208 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.32 LLCE\_CAN\_ROUTING\_CAN

#define LLCE\_CAN\_ROUTING\_CAN

Routing feature mask for converting frame (CANFD-&gt; CAN).

Definition at line 210 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.33 LLCE\_CAN\_ROUTING\_CANFD

#define LLCE\_CAN\_ROUTING\_CANFD

Routing feature mask for converting frame (CAN-&gt; CANFD).

Definition at line 212 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.34 LLCE\_CAN\_ROUTING\_ID\_REMAPPING\_EN

#define LLCE\_CAN\_ROUTING\_ID\_REMAPPING\_EN

Routing feature mask for id remapping.

Definition at line 214 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.35 LLCE\_CAN\_MB\_FDF\_SHIFT\_U32

#define LLCE\_CAN\_MB\_FDF\_SHIFT\_U32

Shift value for extracting FD flag from CAN frame.

Definition at line 217 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.36 LLCE\_CAN\_MB\_BRS\_SHIFT\_U32

#define LLCE\_CAN\_MB\_BRS\_SHIFT\_U32

Shift value for extracting Baud Rate Switch flag from CAN frame.

Definition at line 219 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.37 LLCE\_CAN\_MB\_ESI\_SHIFT\_U32

#define LLCE\_CAN\_MB\_ESI\_SHIFT\_U32

Shift value for extracting ESI flag feature from CAN frame.

Definition at line 221 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.38 LLCE\_CAN\_MB\_IDSTD\_SHIFT\_U32

#define LLCE\_CAN\_MB\_IDSTD\_SHIFT\_U32

Shift value for extracting frame ID from CAN frame.

Definition at line 223 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.39 LLCE\_CAN\_MB\_IDE\_SHIFT\_U32

#define LLCE\_CAN\_MB\_IDE\_SHIFT\_U32

Shift value for extracting IDE flag from CAN frame.

Definition at line 225 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.40 LLCE\_CAN\_MB\_RTR\_SHIFT\_U32

#define LLCE\_CAN\_MB\_RTR\_SHIFT\_U32

Shift value for extracting RTR flag from CAN frame.

Definition at line 227 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.41 LLCE\_CAN\_MB\_PRECALC\_LEN\_SHIFT\_U32

#define LLCE\_CAN\_MB\_PRECALC\_LEN\_SHIFT\_U32

Shift value for extracting precalculated length from CAN frame.

Definition at line 230 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.42 LLCE\_CAN\_FULLCAN\_MASK\_U32

#define LLCE\_CAN\_FULLCAN\_MASK\_U32

Constant used to identify a reserved mask id.

Definition at line 233 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.43 LLCE\_CAN2ETH\_PFE\_EMAC0

#define LLCE\_CAN2ETH\_PFE\_EMAC0

Definition at line 238 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.44 LLCE\_CAN2ETH\_PFE\_EMAC1

#define LLCE\_CAN2ETH\_PFE\_EMAC1

Definition at line 239 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.45 LLCE\_CAN2ETH\_PFE\_EMAC2

#define LLCE\_CAN2ETH\_PFE\_EMAC2

Definition at line 240 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.46 LLCE\_CAN2ETH\_PFE\_HIF0

#define LLCE\_CAN2ETH\_PFE\_HIF0

Definition at line 241 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.47 LLCE\_CAN2ETH\_PFE\_HIF1

#define LLCE\_CAN2ETH\_PFE\_HIF1

Definition at line 242 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.48 LLCE\_CAN2ETH\_PFE\_HIF2

#define LLCE\_CAN2ETH\_PFE\_HIF2

Definition at line 243 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.49 LLCE\_CAN2ETH\_PFE\_HIF3

#define LLCE\_CAN2ETH\_PFE\_HIF3

Definition at line 244 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.50 LLCE\_CAN2ETH\_PFE\_HIFNOCPY

#define LLCE\_CAN2ETH\_PFE\_HIFNOCPY

Definition at line 245 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.51 LLCE\_CAN2ETH\_PFE\_AUX

#define LLCE\_CAN2ETH\_PFE\_AUX

Definition at line 246 of file Llce\_InterfaceCanTypes.h.

## 3.1.3.52 LLCE\_CORE2CORE\_BASEADDR

#define LLCE\_CORE2CORE\_BASEADDR

Base address for the CORE2CORE module.

Definition at line 77 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.53 LLCE\_CORE2CORE\_HINTC0R

#define LLCE\_CORE2CORE\_HINTC0R

Definition at line 79 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.54 LLCE\_CORE2CORE\_HINTC1R

#define LLCE\_CORE2CORE\_HINTC1R

Definition at line 80 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.55 LLCE\_CORE2CORE\_HINTC2R

#define LLCE\_CORE2CORE\_HINTC2R

Definition at line 81 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.56 LLCE\_CORE2CORE\_HINTC3R

#define LLCE\_CORE2CORE\_HINTC3R

Definition at line 82 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.57 LLCE\_CORE2CORE\_C0INTHR

#define LLCE\_CORE2CORE\_C0INTHR

Definition at line 84 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.58 LLCE\_CORE2CORE\_C1INTHR

#define LLCE\_CORE2CORE\_C1INTHR

Definition at line 85 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.59 LLCE\_CORE2CORE\_C2INTHR

#define LLCE\_CORE2CORE\_C2INTHR

Definition at line 86 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.60 LLCE\_CORE2CORE\_C3INTHR

#define LLCE\_CORE2CORE\_C3INTHR

Definition at line 87 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.61 LLCE\_CORE2CORE\_C0INTCR

#define LLCE\_CORE2CORE\_C0INTCR

Definition at line 89 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.62 LLCE\_CORE2CORE\_C1INTCR

#define LLCE\_CORE2CORE\_C1INTCR

Definition at line 90 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.63 LLCE\_CORE2CORE\_C2INTCR

#define LLCE\_CORE2CORE\_C2INTCR

Definition at line 91 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.64 LLCE\_CORE2CORE\_C3INTCR

#define LLCE\_CORE2CORE\_C3INTCR

Definition at line 92 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.65 LLCE\_CORE2CORE\_HINTC0ER

#define LLCE\_CORE2CORE\_HINTC0ER

Definition at line 94 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.66 LLCE\_CORE2CORE\_HINTC1ER

#define LLCE\_CORE2CORE\_HINTC1ER

Definition at line 95 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.67 LLCE\_CORE2CORE\_HINTC2ER

#define LLCE\_CORE2CORE\_HINTC2ER

Definition at line 96 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.68 LLCE\_CORE2CORE\_HINTC3ER

#define LLCE\_CORE2CORE\_HINTC3ER

Definition at line 97 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.69 LLCE\_CORE2CORE\_C0INTHER

#define LLCE\_CORE2CORE\_C0INTHER

Definition at line 99 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.70 LLCE\_CORE2CORE\_C1INTHER

#define LLCE\_CORE2CORE\_C1INTHER

Definition at line 100 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.71 LLCE\_CORE2CORE\_C2INTHER

#define LLCE\_CORE2CORE\_C2INTHER

Definition at line 101 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.72 LLCE\_CORE2CORE\_C3INTHER

#define LLCE\_CORE2CORE\_C3INTHER

Definition at line 102 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.73 LLCE\_CORE2CORE\_C0INTCER

#define LLCE\_CORE2CORE\_C0INTCER

Definition at line 104 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.74 LLCE\_CORE2CORE\_C1INTCER

#define LLCE\_CORE2CORE\_C1INTCER

Definition at line 105 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.75 LLCE\_CORE2CORE\_C2INTCER

#define LLCE\_CORE2CORE\_C2INTCER

Definition at line 106 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.76 LLCE\_CORE2CORE\_C3INTCER

#define LLCE\_CORE2CORE\_C3INTCER

Definition at line 107 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.77 LLCE\_CORE2CORE\_C1INTHR\_RXLUT\_FLAG

#define LLCE\_CORE2CORE\_C1INTHR\_RXLUT\_FLAG

Definition at line 109 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.78 LLCE\_CORE2CORE\_HINTC1R\_RXLUT\_FLAG

#define LLCE\_CORE2CORE\_HINTC1R\_RXLUT\_FLAG

Definition at line 110 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.79 LLCE\_CORE2DTE\_ASSERT\_INTERRUPT

<!-- formula-not-decoded -->

Definition at line 112 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.80 LLCE\_CORE2DTE\_GET\_STATUS\_INTERRUPT

#define LLCE\_CORE2DTE\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 115 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.81 LLCE\_CORE2DTE\_CLEAR\_INTERRUPT

#define LLCE\_CORE2DTE\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 118 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.82 LLCE\_CORE2DTE\_ENABLE\_INTERRUPT

<!-- formula-not-decoded -->

Definition at line 120 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.83 LLCE\_CORE2DTE\_DISABLE\_INTERRUPT

<!-- formula-not-decoded -->

Definition at line 123 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.84 LLCE\_CORE2RX\_ASSERT\_INTERRUPT

#define LLCE\_CORE2RX\_ASSERT\_INTERRUPT( u8HwCtrl )

Definition at line 128 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.85 LLCE\_CORE2RX\_GET\_STATUS\_INTERRUPT

#define LLCE\_CORE2RX\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 131 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.86 LLCE\_CORE2RX\_CLEAR\_INTERRUPT

#define LLCE\_CORE2RX\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 134 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.87 LLCE\_CORE2RX\_ENABLE\_INTERRUPT

#define LLCE\_CORE2RX\_ENABLE\_INTERRUPT( u8HwCtrl )

Definition at line 136 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.88 LLCE\_CORE2RX\_DISABLE\_INTERRUPT

#define LLCE\_CORE2RX\_DISABLE\_INTERRUPT( u8HwCtrl )

Definition at line 139 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.89 LLCE\_CORE2TX\_ASSERT\_INTERRUPT

#define LLCE\_CORE2TX\_ASSERT\_INTERRUPT( u8HwCtrl )

Definition at line 143 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.90 LLCE\_CORE2TX\_GET\_STATUS\_INTERRUPT

#define LLCE\_CORE2TX\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 146 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.91 LLCE\_CORE2TX\_CLEAR\_INTERRUPT

#define LLCE\_CORE2TX\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 149 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.92 LLCE\_CORE2TX\_ENABLE\_INTERRUPT

#define LLCE\_CORE2TX\_ENABLE\_INTERRUPT( u8HwCtrl )

Definition at line 151 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.93 LLCE\_CORE2TX\_DISABLE\_INTERRUPT

<!-- formula-not-decoded -->

Definition at line 154 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.94 LLCE\_CORE2FRPE\_ASSERT\_INTERRUPT

#define LLCE\_CORE2FRPE\_ASSERT\_INTERRUPT( u8HwCtrl )

Definition at line 158 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.95 LLCE\_CORE2FRPE\_GET\_STATUS\_INTERRUPT

```
#define LLCE_CORE2FRPE_GET_STATUS_INTERRUPT( u8HwCtrl )
```

Definition at line 161 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.96 LLCE\_CORE2FRPE\_CLEAR\_INTERRUPT

#define LLCE\_CORE2FRPE\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 164 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.97 LLCE\_CORE2FRPE\_ENABLE\_INTERRUPT

#define LLCE\_CORE2FRPE\_ENABLE\_INTERRUPT( u8HwCtrl )

Definition at line 166 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.98 LLCE\_CORE2FRPE\_DISABLE\_INTERRUPT

<!-- formula-not-decoded -->

Definition at line 169 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.99 LLCE\_HOST2RX\_ASSERT\_INTERRUPT

#define LLCE\_HOST2RX\_ASSERT\_INTERRUPT( u8HwCtrl )

Definition at line 173 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.100 LLCE\_HOST2RX\_GET\_STATUS\_INTERRUPT

#define

LLCE\_HOST2RX\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 176 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.101 LLCE\_HOST2RX\_CLEAR\_INTERRUPT

#define LLCE\_HOST2RX\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 179 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.102 LLCE\_HOST2RX\_ENABLE\_INTERRUPT

#define LLCE\_HOST2RX\_ENABLE\_INTERRUPT( u8HwCtrl )

Definition at line 181 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.103 LLCE\_HOST2RX\_DISABLE\_INTERRUPT

#define LLCE\_HOST2RX\_DISABLE\_INTERRUPT( u8HwCtrl )

Definition at line 184 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.104 LLCE\_RX2HOST\_ASSERT\_INTERRUPT

#define LLCE\_RX2HOST\_ASSERT\_INTERRUPT( u8HwCtrl )

Definition at line 187 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.105 LLCE\_RX2HOST\_GET\_STATUS\_INTERRUPT

#define LLCE\_RX2HOST\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 190 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.106 LLCE\_RX2HOST\_CLEAR\_INTERRUPT

#define LLCE\_RX2HOST\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 193 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.107 LLCE\_RX2HOST\_ENABLE\_INTERRUPT

#define LLCE\_RX2HOST\_ENABLE\_INTERRUPT( u8HwCtrl )

Definition at line 195 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.108 LLCE\_RX2HOST\_DISABLE\_INTERRUPT

#define LLCE\_RX2HOST\_DISABLE\_INTERRUPT( u8HwCtrl )

Definition at line 198 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.109 LLCE\_HOST2TX\_ASSERT\_INTERRUPT

#define LLCE\_HOST2TX\_ASSERT\_INTERRUPT( u8HwCtrl )

Definition at line 202 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.110 LLCE\_HOST2TX\_GET\_STATUS\_INTERRUPT

#define LLCE\_HOST2TX\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 205 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.111 LLCE\_HOST2TX\_CLEAR\_INTERRUPT

#define LLCE\_HOST2TX\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 208 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.112 LLCE\_HOST2TX\_ENABLE\_INTERRUPT

#define LLCE\_HOST2TX\_ENABLE\_INTERRUPT( u8HwCtrl )

Definition at line 210 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.113 LLCE\_HOST2TX\_DISABLE\_INTERRUPT

#define LLCE\_HOST2TX\_DISABLE\_INTERRUPT( u8HwCtrl )

Definition at line 213 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.114 LLCE\_TX2HOST\_ASSERT\_INTERRUPT

#define LLCE\_TX2HOST\_ASSERT\_INTERRUPT( u8HwCtrl )

Definition at line 217 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.115 LLCE\_TX2HOST\_GET\_STATUS\_INTERRUPT

#define LLCE\_TX2HOST\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 220 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.116 LLCE\_TX2HOST\_CLEAR\_INTERRUPT

#define LLCE\_TX2HOST\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 223 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.117 LLCE\_TX2HOST\_ENABLE\_INTERRUPT

#define LLCE\_TX2HOST\_ENABLE\_INTERRUPT( u8HwCtrl )

Definition at line 225 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.118 LLCE\_TX2HOST\_DISABLE\_INTERRUPT

<!-- formula-not-decoded -->

Definition at line 228 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.119 LLCE\_TX2HOST\_GET\_ENABLE\_STATUS\_INTERRUPT

#define LLCE\_TX2HOST\_GET\_ENABLE\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 231 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.120 LLCE\_HOST2FRPE\_ASSERT\_INTERRUPT

#define

LLCE\_HOST2FRPE\_ASSERT\_INTERRUPT( u8HwCtrl )

Definition at line 235 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.121 LLCE\_HOST2FRPE\_GET\_STATUS\_INTERRUPT

#define LLCE\_HOST2FRPE\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 238 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.122 LLCE\_HOST2FRPE\_CLEAR\_INTERRUPT

#define LLCE\_HOST2FRPE\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 241 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.123 LLCE\_HOST2FRPE\_ENABLE\_INTERRUPT

<!-- formula-not-decoded -->

Definition at line 243 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.124 LLCE\_HOST2FRPE\_DISABLE\_INTERRUPT

#define LLCE\_HOST2FRPE\_DISABLE\_INTERRUPT( u8HwCtrl )

Definition at line 246 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.125 LLCE\_FRPE2HOST\_ASSERT\_INTERRUPT

```
#define LLCE_FRPE2HOST_ASSERT_INTERRUPT( u8HwCtrl )
```

Definition at line 250 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.126 LLCE\_FRPE2HOST\_GET\_STATUS\_INTERRUPT

#define LLCE\_FRPE2HOST\_GET\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 253 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.127 LLCE\_FRPE2HOST\_CLEAR\_INTERRUPT

#define LLCE\_FRPE2HOST\_CLEAR\_INTERRUPT( u8HwCtrl )

Definition at line 256 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.128 LLCE\_FRPE2HOST\_ENABLE\_INTERRUPT

#define LLCE\_FRPE2HOST\_ENABLE\_INTERRUPT( u8HwCtrl )

Definition at line 258 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.129 LLCE\_FRPE2HOST\_DISABLE\_INTERRUPT

#define LLCE\_FRPE2HOST\_DISABLE\_INTERRUPT( u8HwCtrl )

Definition at line 261 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.130 LLCE\_FRPE2HOST\_GET\_ENABLE\_STATUS\_INTERRUPT

#define LLCE\_FRPE2HOST\_GET\_ENABLE\_STATUS\_INTERRUPT( u8HwCtrl )

Definition at line 264 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.131 LLCE\_CORE2CORE\_ASSERT\_INTERRUPT

```
#define LLCE_CORE2CORE_ASSERT_INTERRUPT( u32BaseAddr, u8HwCtrl )
```

Definition at line 268 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.132 LLCE\_CORE2CORE\_GET\_STATUS\_INTERRUPT

```
#define LLCE_CORE2CORE_GET_STATUS_INTERRUPT( u32BaseAddr, u8HwCtrl )
```

Definition at line 270 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.133 LLCE\_CORE2CORE\_CLEAR\_INTERRUPT

```
#define LLCE_CORE2CORE_CLEAR_INTERRUPT( u32BaseAddr, u8HwCtrl )
```

Definition at line 272 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.134 LLCE\_CORE2CORE\_ENABLE\_INTERRUPT

```
#define LLCE_CORE2CORE_ENABLE_INTERRUPT( u32BaseAddr, u8HwCtrl )
```

Definition at line 274 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.135 LLCE\_CORE2CORE\_DISABLE\_INTERRUPT

```
#define LLCE_CORE2CORE_DISABLE_INTERRUPT( u32BaseAddr, u8HwCtrl )
```

Definition at line 276 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.136 LLCE\_CORE2CORE\_GET\_ENABLE\_STATUS\_INTERRUPT

```
#define LLCE_CORE2CORE_GET_ENABLE_STATUS_INTERRUPT( u32BaseAddr, u8HwCtrl )
```

Definition at line 278 of file Llce\_InterfaceCore2Core.h.

## 3.1.3.137 LLCE\_CAN\_MB\_RTR\_UNPACKED\_U32

#define LLCE\_CAN\_MB\_RTR\_UNPACKED\_U32

Frame RTR field mask unpacked.

Definition at line 84 of file Llce\_InterfaceCanUtils.h.

## 3.1.3.138 LLCE\_CAN\_MB\_IDE\_UNPACKED\_U32

#define LLCE\_CAN\_MB\_IDE\_UNPACKED\_U32

Frame IDE field mask unpacked.

Definition at line 86 of file Llce\_InterfaceCanUtils.h.

## 3.1.3.139 LLCE\_CAN\_MB\_IDSTD\_MASK\_UNPACKED\_U32

#define LLCE\_CAN\_MB\_IDSTD\_MASK\_UNPACKED\_U32

Frame standard ID field mask unpacked.

Definition at line 88 of file Llce\_InterfaceCanUtils.h.

## 3.1.3.140 LLCE\_CAN\_MB\_BRS\_UNPACKED\_U32

#define LLCE\_CAN\_MB\_BRS\_UNPACKED\_U32

Frame BRS field mask unpacked.

Definition at line 90 of file Llce\_InterfaceCanUtils.h.

## 3.1.3.141 LLCE\_CAN\_MB\_FDF\_UNPACKED\_U32

#define LLCE\_CAN\_MB\_FDF\_UNPACKED\_U32

Frame FDF field mask unpacked.

Definition at line 92 of file Llce\_InterfaceCanUtils.h.

## 3.1.3.142 LLCE\_CAN\_MB\_ESI\_UNPACKED\_U32

#define LLCE\_CAN\_MB\_ESI\_UNPACKED\_U32

Frame ESI field mask unpacked.

Definition at line 94 of file Llce\_InterfaceCanUtils.h.

## 3.1.3.143 LLCE\_GENERIC\_FIFO\_BASEADDR

#define LLCE\_GENERIC\_FIFO\_BASEADDR

Base address for Generic FIFO 0.

Definition at line 87 of file Llce\_InterfaceFifo.h.

## 3.1.3.144 LLCE\_ICSR\_BASEADDR

#define LLCE\_ICSR\_BASEADDR

Base address for the interrupt concentrator registers.

Definition at line 89 of file Llce\_InterfaceFifo.h.

## 3.1.3.145 LLCE\_CONFIG\_FIFO\_DEPTH\_U8

#define LLCE\_CONFIG\_FIFO\_DEPTH\_U8

Definition at line 91 of file Llce\_InterfaceFifo.h.

## 3.1.3.146 LLCE\_FIFO\_FFULLD\_U32

#define LLCE\_FIFO\_FFULLD\_U32

Definition at line 93 of file Llce\_InterfaceFifo.h.

## 3.1.3.147 LLCE\_FIFO\_FEMTYD\_U32

#define LLCE\_FIFO\_FEMTYD\_U32 Definition at line 94 of file Llce\_InterfaceFifo.h.

## 3.1.3.148 LLCE\_FIFO\_SR\_QCOUNT\_SHIFT\_U8

#define LLCE\_FIFO\_SR\_QCOUNT\_SHIFT\_U8 Definition at line 95 of file Llce\_InterfaceFifo.h.

## 3.1.3.149 LLCE\_FIFO\_FCR\_FIFOEN\_U32

#define LLCE\_FIFO\_FCR\_FIFOEN\_U32 Definition at line 97 of file Llce\_InterfaceFifo.h.

## 3.1.3.150 LLCE\_FIFO\_FCR\_FLENOWEN\_U32

#define LLCE\_FIFO\_FCR\_FLENOWEN\_U32 Definition at line 98 of file Llce\_InterfaceFifo.h.

## 3.1.3.151 LLCE\_FIFO\_FCR\_POPEN\_U32

#define LLCE\_FIFO\_FCR\_POPEN\_U32 Definition at line 99 of file Llce\_InterfaceFifo.h.

## 3.1.3.152 LLCE\_FIFO\_FCR\_PUSHEN\_U32

#define LLCE\_FIFO\_FCR\_PUSHEN\_U32 Definition at line 100 of file Llce\_InterfaceFifo.h.

## 3.1.3.153 LLCE\_FIFO\_FCR\_FLUSH\_U32

#define LLCE\_FIFO\_FCR\_FLUSH\_U32

Definition at line 101 of file Llce\_InterfaceFifo.h.

## 3.1.3.154 LLCE\_FIFO\_FCR\_RESET\_U32

#define LLCE\_FIFO\_FCR\_RESET\_U32

Definition at line 103 of file Llce\_InterfaceFifo.h.

## 3.1.3.155 LLCE\_FIFO\_FFULL\_U32

#define LLCE\_FIFO\_FFULL\_U32

Definition at line 106 of file Llce\_InterfaceFifo.h.

## 3.1.3.156 LLCE\_FIFO\_FNFULL\_U32

#define LLCE\_FIFO\_FNFULL\_U32

Definition at line 107 of file Llce\_InterfaceFifo.h.

## 3.1.3.157 LLCE\_FIFO\_FEMTY\_U32

#define LLCE\_FIFO\_FEMTY\_U32

Definition at line 108 of file Llce\_InterfaceFifo.h.

## 3.1.3.158 LLCE\_FIFO\_FNEMTY\_U32

#define LLCE\_FIFO\_FNEMTY\_U32

Definition at line 109 of file Llce\_InterfaceFifo.h.

## 3.1.3.159 LLCE\_FIFO\_POPEVT\_U32

#define LLCE\_FIFO\_POPEVT\_U32

Definition at line 110 of file Llce\_InterfaceFifo.h.

## 3.1.3.160 LLCE\_FIFO\_WMKFL\_U32

#define LLCE\_FIFO\_WMKFL\_U32

Definition at line 111 of file Llce\_InterfaceFifo.h.

## 3.1.3.161 LLCE\_FIFO\_WMKEM\_U32

#define LLCE\_FIFO\_WMKEM\_U32

Definition at line 112 of file Llce\_InterfaceFifo.h.

## 3.1.3.162 LLCE\_FIFO\_POPUND\_U32

#define LLCE\_FIFO\_POPUND\_U32

Definition at line 113 of file Llce\_InterfaceFifo.h.

## 3.1.3.163 LLCE\_FIFO\_PUSHOVR\_U32

#define LLCE\_FIFO\_PUSHOVR\_U32

Definition at line 114 of file Llce\_InterfaceFifo.h.

## 3.1.3.164 LLCE\_FIFO\_MSBNOMT\_U32

#define LLCE\_FIFO\_MSBNOMT\_U32

Definition at line 115 of file Llce\_InterfaceFifo.h.

## 3.1.3.165 LLCE\_FIFO\_NULL\_VALUE

#define LLCE\_FIFO\_NULL\_VALUE

Definition at line 118 of file Llce\_InterfaceFifo.h.

## 3.1.3.166 LLCE\_FIFO\_0\_BASE\_ADDRESS

#define LLCE\_FIFO\_0\_BASE\_ADDRESS

Definition at line 120 of file Llce\_InterfaceFifo.h.

## 3.1.3.167 LLCE\_FIFO\_1\_BASE\_ADDRESS

#define LLCE\_FIFO\_1\_BASE\_ADDRESS

Definition at line 121 of file Llce\_InterfaceFifo.h.

## 3.1.3.168 LLCE\_FIFO\_2\_BASE\_ADDRESS

#define LLCE\_FIFO\_2\_BASE\_ADDRESS

Definition at line 122 of file Llce\_InterfaceFifo.h.

## 3.1.3.169 LLCE\_FIFO\_3\_BASE\_ADDRESS

#define LLCE\_FIFO\_3\_BASE\_ADDRESS

Definition at line 123 of file Llce\_InterfaceFifo.h.

## 3.1.3.170 LLCE\_FIFO\_4\_BASE\_ADDRESS

#define LLCE\_FIFO\_4\_BASE\_ADDRESS

Definition at line 124 of file Llce\_InterfaceFifo.h.

## 3.1.3.171 LLCE\_FIFO\_5\_BASE\_ADDRESS

#define LLCE\_FIFO\_5\_BASE\_ADDRESS

Definition at line 125 of file Llce\_InterfaceFifo.h.

## 3.1.3.172 LLCE\_FIFO\_6\_BASE\_ADDRESS

#define LLCE\_FIFO\_6\_BASE\_ADDRESS

Definition at line 126 of file Llce\_InterfaceFifo.h.

## 3.1.3.173 LLCE\_FIFO\_7\_BASE\_ADDRESS

#define LLCE\_FIFO\_7\_BASE\_ADDRESS

Definition at line 127 of file Llce\_InterfaceFifo.h.

## 3.1.3.174 LLCE\_FIFO\_8\_BASE\_ADDRESS

#define LLCE\_FIFO\_8\_BASE\_ADDRESS

Definition at line 128 of file Llce\_InterfaceFifo.h.

## 3.1.3.175 LLCE\_FIFO\_9\_BASE\_ADDRESS

#define LLCE\_FIFO\_9\_BASE\_ADDRESS

Definition at line 129 of file Llce\_InterfaceFifo.h.

## 3.1.3.176 LLCE\_FIFO\_10\_BASE\_ADDRESS

#define LLCE\_FIFO\_10\_BASE\_ADDRESS

Definition at line 130 of file Llce\_InterfaceFifo.h.

## 3.1.3.177 LLCE\_FIFO\_11\_BASE\_ADDRESS

#define LLCE\_FIFO\_11\_BASE\_ADDRESS

Definition at line 131 of file Llce\_InterfaceFifo.h.

## 3.1.3.178 LLCE\_FIFO\_12\_BASE\_ADDRESS

#define LLCE\_FIFO\_12\_BASE\_ADDRESS

Definition at line 132 of file Llce\_InterfaceFifo.h.

## 3.1.3.179 LLCE\_FIFO\_13\_BASE\_ADDRESS

#define LLCE\_FIFO\_13\_BASE\_ADDRESS

Definition at line 133 of file Llce\_InterfaceFifo.h.

## 3.1.3.180 LLCE\_FIFO\_14\_BASE\_ADDRESS

#define LLCE\_FIFO\_14\_BASE\_ADDRESS

Definition at line 134 of file Llce\_InterfaceFifo.h.

## 3.1.3.181 LLCE\_FIFO\_15\_BASE\_ADDRESS

#define LLCE\_FIFO\_15\_BASE\_ADDRESS

Definition at line 135 of file Llce\_InterfaceFifo.h.

## 3.1.3.182 LLCE\_FIFO\_16\_BASE\_ADDRESS

#define LLCE\_FIFO\_16\_BASE\_ADDRESS

Definition at line 136 of file Llce\_InterfaceFifo.h.

## 3.1.3.183 LLCE\_FIFO\_17\_BASE\_ADDRESS

#define LLCE\_FIFO\_17\_BASE\_ADDRESS Definition at line 137 of file Llce\_InterfaceFifo.h.

## 3.1.3.184 LLCE\_FIFO\_18\_BASE\_ADDRESS

#define LLCE\_FIFO\_18\_BASE\_ADDRESS Definition at line 138 of file Llce\_InterfaceFifo.h.

## 3.1.3.185 LLCE\_FIFO\_19\_BASE\_ADDRESS

#define LLCE\_FIFO\_19\_BASE\_ADDRESS Definition at line 139 of file Llce\_InterfaceFifo.h.

## 3.1.3.186 LLCE\_FIFO\_20\_BASE\_ADDRESS

#define LLCE\_FIFO\_20\_BASE\_ADDRESS Definition at line 140 of file Llce\_InterfaceFifo.h.

## 3.1.3.187 LLCE\_FIFO\_21\_BASE\_ADDRESS

#define LLCE\_FIFO\_21\_BASE\_ADDRESS Definition at line 141 of file Llce\_InterfaceFifo.h.

## 3.1.3.188 LLCE\_FIFO\_22\_BASE\_ADDRESS

#define LLCE\_FIFO\_22\_BASE\_ADDRESS Definition at line 142 of file Llce\_InterfaceFifo.h.

## 3.1.3.189 LLCE\_FIFO\_23\_BASE\_ADDRESS

#define LLCE\_FIFO\_23\_BASE\_ADDRESS

Definition at line 143 of file Llce\_InterfaceFifo.h.

## 3.1.3.190 LLCE\_FIFO\_24\_BASE\_ADDRESS

#define LLCE\_FIFO\_24\_BASE\_ADDRESS

Definition at line 144 of file Llce\_InterfaceFifo.h.

## 3.1.3.191 LLCE\_FIFO\_25\_BASE\_ADDRESS

#define LLCE\_FIFO\_25\_BASE\_ADDRESS

Definition at line 145 of file Llce\_InterfaceFifo.h.

## 3.1.3.192 LLCE\_FIFO\_26\_BASE\_ADDRESS

#define LLCE\_FIFO\_26\_BASE\_ADDRESS

Definition at line 146 of file Llce\_InterfaceFifo.h.

## 3.1.3.193 LLCE\_FIFO\_27\_BASE\_ADDRESS

#define LLCE\_FIFO\_27\_BASE\_ADDRESS

Definition at line 147 of file Llce\_InterfaceFifo.h.

## 3.1.3.194 LLCE\_FIFO\_28\_BASE\_ADDRESS

#define LLCE\_FIFO\_28\_BASE\_ADDRESS

Definition at line 148 of file Llce\_InterfaceFifo.h.

## 3.1.3.195 LLCE\_FIFO\_29\_BASE\_ADDRESS

#define LLCE\_FIFO\_29\_BASE\_ADDRESS

Definition at line 149 of file Llce\_InterfaceFifo.h.

## 3.1.3.196 LLCE\_FIFO\_30\_BASE\_ADDRESS

#define LLCE\_FIFO\_30\_BASE\_ADDRESS Definition at line 150 of file Llce\_InterfaceFifo.h.

## 3.1.3.197 LLCE\_FIFO\_31\_BASE\_ADDRESS

#define LLCE\_FIFO\_31\_BASE\_ADDRESS Definition at line 151 of file Llce\_InterfaceFifo.h.

## 3.1.3.198 LLCE\_FIFO\_32\_BASE\_ADDRESS

#define LLCE\_FIFO\_32\_BASE\_ADDRESS Definition at line 152 of file Llce\_InterfaceFifo.h.

## 3.1.3.199 LLCE\_FIFO\_33\_BASE\_ADDRESS

#define LLCE\_FIFO\_33\_BASE\_ADDRESS

Definition at line 153 of file Llce\_InterfaceFifo.h.

## 3.1.3.200 LLCE\_FIFO\_34\_BASE\_ADDRESS

#define LLCE\_FIFO\_34\_BASE\_ADDRESS

Definition at line 154 of file Llce\_InterfaceFifo.h.

## 3.1.3.201 LLCE\_FIFO\_35\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_35\_BASE\_ADDRESS

Definition at line 193 of file Llce\_InterfaceFifo.h.

## 3.1.3.202 LLCE\_FIFO\_35\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_35\_BASE\_ADDRESS

Definition at line 193 of file Llce\_InterfaceFifo.h.

## 3.1.3.203 LLCE\_FIFO\_36\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_36\_BASE\_ADDRESS Definition at line 194 of file Llce\_InterfaceFifo.h.

## 3.1.3.204 LLCE\_FIFO\_36\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_36\_BASE\_ADDRESS

Definition at line 194 of file Llce\_InterfaceFifo.h.

## 3.1.3.205 LLCE\_FIFO\_37\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_37\_BASE\_ADDRESS

Definition at line 195 of file Llce\_InterfaceFifo.h.

## 3.1.3.206 LLCE\_FIFO\_37\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_37\_BASE\_ADDRESS

Definition at line 195 of file Llce\_InterfaceFifo.h.

## 3.1.3.207 LLCE\_FIFO\_38\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_38\_BASE\_ADDRESS

Definition at line 196 of file Llce\_InterfaceFifo.h.

## 3.1.3.208 LLCE\_FIFO\_38\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_38\_BASE\_ADDRESS

Definition at line 196 of file Llce\_InterfaceFifo.h.

## 3.1.3.209 LLCE\_FIFO\_39\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_39\_BASE\_ADDRESS

Definition at line 197 of file Llce\_InterfaceFifo.h.

## 3.1.3.210 LLCE\_FIFO\_39\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_39\_BASE\_ADDRESS

Definition at line 197 of file Llce\_InterfaceFifo.h.

## 3.1.3.211 LLCE\_FIFO\_40\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_40\_BASE\_ADDRESS

Definition at line 198 of file Llce\_InterfaceFifo.h.

## 3.1.3.212 LLCE\_FIFO\_40\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_40\_BASE\_ADDRESS

Definition at line 198 of file Llce\_InterfaceFifo.h.

## 3.1.3.213 LLCE\_FIFO\_41\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_41\_BASE\_ADDRESS

Definition at line 199 of file Llce\_InterfaceFifo.h.

## 3.1.3.214 LLCE\_FIFO\_41\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_41\_BASE\_ADDRESS

Definition at line 199 of file Llce\_InterfaceFifo.h.

## 3.1.3.215 LLCE\_FIFO\_42\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_42\_BASE\_ADDRESS

Definition at line 200 of file Llce\_InterfaceFifo.h.

## 3.1.3.216 LLCE\_FIFO\_42\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_42\_BASE\_ADDRESS

Definition at line 200 of file Llce\_InterfaceFifo.h.

## 3.1.3.217 LLCE\_FIFO\_43\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_43\_BASE\_ADDRESS

Definition at line 201 of file Llce\_InterfaceFifo.h.

## 3.1.3.218 LLCE\_FIFO\_43\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_43\_BASE\_ADDRESS

Definition at line 201 of file Llce\_InterfaceFifo.h.

## 3.1.3.219 LLCE\_FIFO\_44\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_44\_BASE\_ADDRESS

Definition at line 202 of file Llce\_InterfaceFifo.h.

## 3.1.3.220 LLCE\_FIFO\_44\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_44\_BASE\_ADDRESS

Definition at line 202 of file Llce\_InterfaceFifo.h.

## 3.1.3.221 LLCE\_FIFO\_45\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_45\_BASE\_ADDRESS

Definition at line 203 of file Llce\_InterfaceFifo.h.

## 3.1.3.222 LLCE\_FIFO\_45\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_45\_BASE\_ADDRESS

Definition at line 203 of file Llce\_InterfaceFifo.h.

## 3.1.3.223 LLCE\_FIFO\_46\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_46\_BASE\_ADDRESS

Definition at line 204 of file Llce\_InterfaceFifo.h.

## 3.1.3.224 LLCE\_FIFO\_46\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_46\_BASE\_ADDRESS

Definition at line 204 of file Llce\_InterfaceFifo.h.

## 3.1.3.225 LLCE\_FIFO\_47\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_47\_BASE\_ADDRESS

Definition at line 205 of file Llce\_InterfaceFifo.h.

## 3.1.3.226 LLCE\_FIFO\_47\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_47\_BASE\_ADDRESS

Definition at line 205 of file Llce\_InterfaceFifo.h.

## 3.1.3.227 LLCE\_FIFO\_48\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_48\_BASE\_ADDRESS

Definition at line 206 of file Llce\_InterfaceFifo.h.

## 3.1.3.228 LLCE\_FIFO\_48\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_48\_BASE\_ADDRESS

Definition at line 206 of file Llce\_InterfaceFifo.h.

## 3.1.3.229 LLCE\_FIFO\_49\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_49\_BASE\_ADDRESS

Definition at line 207 of file Llce\_InterfaceFifo.h.

## 3.1.3.230 LLCE\_FIFO\_49\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_49\_BASE\_ADDRESS

Definition at line 207 of file Llce\_InterfaceFifo.h.

## 3.1.3.231 LLCE\_FIFO\_50\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_50\_BASE\_ADDRESS

Definition at line 208 of file Llce\_InterfaceFifo.h.

## 3.1.3.232 LLCE\_FIFO\_50\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_50\_BASE\_ADDRESS Definition at line 208 of file Llce\_InterfaceFifo.h.

## 3.1.3.233 LLCE\_FIFO\_51\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_51\_BASE\_ADDRESS Definition at line 209 of file Llce\_InterfaceFifo.h.

## 3.1.3.234 LLCE\_FIFO\_51\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_51\_BASE\_ADDRESS

Definition at line 209 of file Llce\_InterfaceFifo.h.

## 3.1.3.235 LLCE\_FIFO\_52\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_52\_BASE\_ADDRESS

Definition at line 210 of file Llce\_InterfaceFifo.h.

## 3.1.3.236 LLCE\_FIFO\_52\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_52\_BASE\_ADDRESS

Definition at line 210 of file Llce\_InterfaceFifo.h.

## 3.1.3.237 LLCE\_FIFO\_53\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_53\_BASE\_ADDRESS

Definition at line 211 of file Llce\_InterfaceFifo.h.

## 3.1.3.238 LLCE\_FIFO\_53\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_53\_BASE\_ADDRESS

Definition at line 211 of file Llce\_InterfaceFifo.h.

## 3.1.3.239 LLCE\_FIFO\_54\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_54\_BASE\_ADDRESS

Definition at line 212 of file Llce\_InterfaceFifo.h.

## 3.1.3.240 LLCE\_FIFO\_54\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_54\_BASE\_ADDRESS

Definition at line 212 of file Llce\_InterfaceFifo.h.

## 3.1.3.241 LLCE\_FIFO\_55\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_55\_BASE\_ADDRESS

Definition at line 213 of file Llce\_InterfaceFifo.h.

## 3.1.3.242 LLCE\_FIFO\_55\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_55\_BASE\_ADDRESS

Definition at line 213 of file Llce\_InterfaceFifo.h.

## 3.1.3.243 LLCE\_FIFO\_56\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_56\_BASE\_ADDRESS

Definition at line 214 of file Llce\_InterfaceFifo.h.

## 3.1.3.244 LLCE\_FIFO\_56\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_56\_BASE\_ADDRESS

Definition at line 214 of file Llce\_InterfaceFifo.h.

## 3.1.3.245 LLCE\_FIFO\_57\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_57\_BASE\_ADDRESS

Definition at line 215 of file Llce\_InterfaceFifo.h.

## 3.1.3.246 LLCE\_FIFO\_57\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_57\_BASE\_ADDRESS

Definition at line 215 of file Llce\_InterfaceFifo.h.

## 3.1.3.247 LLCE\_FIFO\_58\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_58\_BASE\_ADDRESS

Definition at line 216 of file Llce\_InterfaceFifo.h.

## 3.1.3.248 LLCE\_FIFO\_58\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_58\_BASE\_ADDRESS

Definition at line 216 of file Llce\_InterfaceFifo.h.

## 3.1.3.249 LLCE\_FIFO\_59\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_59\_BASE\_ADDRESS

Definition at line 217 of file Llce\_InterfaceFifo.h.

## 3.1.3.250 LLCE\_FIFO\_59\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_59\_BASE\_ADDRESS

Definition at line 217 of file Llce\_InterfaceFifo.h.

## 3.1.3.251 LLCE\_FIFO\_60\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_60\_BASE\_ADDRESS

Definition at line 218 of file Llce\_InterfaceFifo.h.

## 3.1.3.252 LLCE\_FIFO\_60\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_60\_BASE\_ADDRESS

Definition at line 218 of file Llce\_InterfaceFifo.h.

## 3.1.3.253 LLCE\_FIFO\_61\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_61\_BASE\_ADDRESS

Definition at line 219 of file Llce\_InterfaceFifo.h.

## 3.1.3.254 LLCE\_FIFO\_61\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_61\_BASE\_ADDRESS

Definition at line 219 of file Llce\_InterfaceFifo.h.

## 3.1.3.255 LLCE\_FIFO\_62\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_62\_BASE\_ADDRESS

Definition at line 220 of file Llce\_InterfaceFifo.h.

## 3.1.3.256 LLCE\_FIFO\_62\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_62\_BASE\_ADDRESS

Definition at line 220 of file Llce\_InterfaceFifo.h.

## 3.1.3.257 LLCE\_FIFO\_63\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_63\_BASE\_ADDRESS

Definition at line 221 of file Llce\_InterfaceFifo.h.

## 3.1.3.258 LLCE\_FIFO\_63\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_63\_BASE\_ADDRESS

Definition at line 221 of file Llce\_InterfaceFifo.h.

## 3.1.3.259 LLCE\_FIFO\_64\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_64\_BASE\_ADDRESS

Definition at line 222 of file Llce\_InterfaceFifo.h.

## 3.1.3.260 LLCE\_FIFO\_64\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_64\_BASE\_ADDRESS

Definition at line 222 of file Llce\_InterfaceFifo.h.

## 3.1.3.261 LLCE\_FIFO\_65\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_65\_BASE\_ADDRESS

Definition at line 223 of file Llce\_InterfaceFifo.h.

## 3.1.3.262 LLCE\_FIFO\_65\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_65\_BASE\_ADDRESS

Definition at line 223 of file Llce\_InterfaceFifo.h.

## 3.1.3.263 LLCE\_FIFO\_66\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_66\_BASE\_ADDRESS

Definition at line 224 of file Llce\_InterfaceFifo.h.

## 3.1.3.264 LLCE\_FIFO\_66\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_66\_BASE\_ADDRESS

Definition at line 224 of file Llce\_InterfaceFifo.h.

## 3.1.3.265 LLCE\_FIFO\_67\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_67\_BASE\_ADDRESS

Definition at line 225 of file Llce\_InterfaceFifo.h.

## 3.1.3.266 LLCE\_FIFO\_67\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_67\_BASE\_ADDRESS

Definition at line 225 of file Llce\_InterfaceFifo.h.

## 3.1.3.267 LLCE\_FIFO\_68\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_68\_BASE\_ADDRESS

Definition at line 226 of file Llce\_InterfaceFifo.h.

## 3.1.3.268 LLCE\_FIFO\_68\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_68\_BASE\_ADDRESS

Definition at line 226 of file Llce\_InterfaceFifo.h.

## 3.1.3.269 LLCE\_FIFO\_69\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_69\_BASE\_ADDRESS

Definition at line 227 of file Llce\_InterfaceFifo.h.

## 3.1.3.270 LLCE\_FIFO\_69\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_69\_BASE\_ADDRESS

Definition at line 227 of file Llce\_InterfaceFifo.h.

## 3.1.3.271 LLCE\_FIFO\_70\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_70\_BASE\_ADDRESS

Definition at line 228 of file Llce\_InterfaceFifo.h.

## 3.1.3.272 LLCE\_FIFO\_70\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_70\_BASE\_ADDRESS

Definition at line 228 of file Llce\_InterfaceFifo.h.

## Module Documentation

## 3.1.3.273 LLCE\_FIFO\_71\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_71\_BASE\_ADDRESS

Definition at line 229 of file Llce\_InterfaceFifo.h.

## 3.1.3.274 LLCE\_FIFO\_71\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_71\_BASE\_ADDRESS Definition at line 229 of file Llce\_InterfaceFifo.h.

## 3.1.3.275 LLCE\_FIFO\_72\_BASE\_ADDRESS [1/2]

#define LLCE\_FIFO\_72\_BASE\_ADDRESS Definition at line 230 of file Llce\_InterfaceFifo.h.

## 3.1.3.276 LLCE\_FIFO\_72\_BASE\_ADDRESS [2/2]

#define LLCE\_FIFO\_72\_BASE\_ADDRESS

Definition at line 230 of file Llce\_InterfaceFifo.h.

## 3.1.3.277 LLCE\_FIFO\_73\_BASE\_ADDRESS

#define LLCE\_FIFO\_73\_BASE\_ADDRESS

Definition at line 231 of file Llce\_InterfaceFifo.h.

## 3.1.3.278 LLCE\_FIFO\_74\_BASE\_ADDRESS

#define LLCE\_FIFO\_74\_BASE\_ADDRESS

Definition at line 232 of file Llce\_InterfaceFifo.h.

## 3.1.3.279 LLCE\_FIFO\_75\_BASE\_ADDRESS

#define LLCE\_FIFO\_75\_BASE\_ADDRESS

Definition at line 233 of file Llce\_InterfaceFifo.h.

## 3.1.3.280 LLCE\_FIFO\_76\_BASE\_ADDRESS

#define LLCE\_FIFO\_76\_BASE\_ADDRESS Definition at line 234 of file Llce\_InterfaceFifo.h.

## 3.1.3.281 LLCE\_FIFO\_77\_BASE\_ADDRESS

#define LLCE\_FIFO\_77\_BASE\_ADDRESS Definition at line 235 of file Llce\_InterfaceFifo.h.

## 3.1.3.282 LLCE\_FIFO\_78\_BASE\_ADDRESS

#define LLCE\_FIFO\_78\_BASE\_ADDRESS Definition at line 236 of file Llce\_InterfaceFifo.h.

## 3.1.3.283 LLCE\_FIFO\_79\_BASE\_ADDRESS

#define LLCE\_FIFO\_79\_BASE\_ADDRESS

Definition at line 237 of file Llce\_InterfaceFifo.h.

## 3.1.3.284 LLCE\_FIFO\_80\_BASE\_ADDRESS

#define LLCE\_FIFO\_80\_BASE\_ADDRESS Definition at line 238 of file Llce\_InterfaceFifo.h.

## 3.1.3.285 LLCE\_FIFO\_81\_BASE\_ADDRESS

#define LLCE\_FIFO\_81\_BASE\_ADDRESS

Definition at line 239 of file Llce\_InterfaceFifo.h.

## 3.1.3.286 LLCE\_FIFO\_82\_BASE\_ADDRESS

#define LLCE\_FIFO\_82\_BASE\_ADDRESS Definition at line 240 of file Llce\_InterfaceFifo.h.

## 3.1.3.287 LLCE\_FIFO\_83\_BASE\_ADDRESS

#define LLCE\_FIFO\_83\_BASE\_ADDRESS Definition at line 241 of file Llce\_InterfaceFifo.h.

## 3.1.3.288 LLCE\_FIFO\_84\_BASE\_ADDRESS

#define LLCE\_FIFO\_84\_BASE\_ADDRESS

Definition at line 242 of file Llce\_InterfaceFifo.h.

## 3.1.3.289 LLCE\_FIFO\_85\_BASE\_ADDRESS

#define LLCE\_FIFO\_85\_BASE\_ADDRESS

Definition at line 243 of file Llce\_InterfaceFifo.h.

## 3.1.3.290 LLCE\_FIFO\_86\_BASE\_ADDRESS

#define LLCE\_FIFO\_86\_BASE\_ADDRESS

Definition at line 244 of file Llce\_InterfaceFifo.h.

## 3.1.3.291 LLCE\_FIFO\_87\_BASE\_ADDRESS

#define LLCE\_FIFO\_87\_BASE\_ADDRESS

Definition at line 245 of file Llce\_InterfaceFifo.h.

## 3.1.3.292 LLCE\_FIFO\_88\_BASE\_ADDRESS

#define LLCE\_FIFO\_88\_BASE\_ADDRESS Definition at line 246 of file Llce\_InterfaceFifo.h.

## 3.1.3.293 LLCE\_FIFO\_89\_BASE\_ADDRESS

#define LLCE\_FIFO\_89\_BASE\_ADDRESS Definition at line 247 of file Llce\_InterfaceFifo.h.

## 3.1.3.294 LLCE\_FIFO\_90\_BASE\_ADDRESS

#define LLCE\_FIFO\_90\_BASE\_ADDRESS Definition at line 248 of file Llce\_InterfaceFifo.h.

## 3.1.3.295 LLCE\_FIFO\_91\_BASE\_ADDRESS

#define LLCE\_FIFO\_91\_BASE\_ADDRESS Definition at line 249 of file Llce\_InterfaceFifo.h.

## 3.1.3.296 LLCE\_FIFO\_92\_BASE\_ADDRESS

#define LLCE\_FIFO\_92\_BASE\_ADDRESS Definition at line 250 of file Llce\_InterfaceFifo.h.

## 3.1.3.297 LLCE\_FIFO\_93\_BASE\_ADDRESS

#define LLCE\_FIFO\_93\_BASE\_ADDRESS

Definition at line 251 of file Llce\_InterfaceFifo.h.

## 3.1.3.298 LLCE\_FIFO\_94\_BASE\_ADDRESS

#define LLCE\_FIFO\_94\_BASE\_ADDRESS

Definition at line 252 of file Llce\_InterfaceFifo.h.

## 3.1.3.299 LLCE\_FIFO\_95\_BASE\_ADDRESS

#define LLCE\_FIFO\_95\_BASE\_ADDRESS

Definition at line 253 of file Llce\_InterfaceFifo.h.

## 3.1.3.300 LLCE\_FIFO\_96\_BASE\_ADDRESS

#define LLCE\_FIFO\_96\_BASE\_ADDRESS

Definition at line 254 of file Llce\_InterfaceFifo.h.

## 3.1.3.301 LLCE\_FIFO\_97\_BASE\_ADDRESS

#define LLCE\_FIFO\_97\_BASE\_ADDRESS

Definition at line 255 of file Llce\_InterfaceFifo.h.

## 3.1.3.302 LLCE\_FIFO\_98\_BASE\_ADDRESS

#define LLCE\_FIFO\_98\_BASE\_ADDRESS

Definition at line 256 of file Llce\_InterfaceFifo.h.

## 3.1.3.303 LLCE\_FIFO\_99\_BASE\_ADDRESS

#define LLCE\_FIFO\_99\_BASE\_ADDRESS Definition at line 257 of file Llce\_InterfaceFifo.h.

## 3.1.3.304 LLCE\_FIFO\_100\_BASE\_ADDRESS

#define LLCE\_FIFO\_100\_BASE\_ADDRESS Definition at line 258 of file Llce\_InterfaceFifo.h.

## 3.1.3.305 LLCE\_FIFO\_101\_BASE\_ADDRESS

#define LLCE\_FIFO\_101\_BASE\_ADDRESS Definition at line 259 of file Llce\_InterfaceFifo.h.

## 3.1.3.306 LLCE\_FIFO\_102\_BASE\_ADDRESS

#define LLCE\_FIFO\_102\_BASE\_ADDRESS Definition at line 260 of file Llce\_InterfaceFifo.h.

## 3.1.3.307 LLCE\_FIFO\_103\_BASE\_ADDRESS

#define LLCE\_FIFO\_103\_BASE\_ADDRESS Definition at line 261 of file Llce\_InterfaceFifo.h.

## 3.1.3.308 LLCE\_FIFO\_104\_BASE\_ADDRESS

#define LLCE\_FIFO\_104\_BASE\_ADDRESS Definition at line 262 of file Llce\_InterfaceFifo.h.

## 3.1.3.309 LLCE\_GENERIC\_FIFO\_0\_BASE\_ADDRESS

#define LLCE\_GENERIC\_FIFO\_0\_BASE\_ADDRESS

Definition at line 263 of file Llce\_InterfaceFifo.h.

## 3.1.3.310 LLCE\_GENERIC\_FIFO\_1\_BASE\_ADDRESS

#define LLCE\_GENERIC\_FIFO\_1\_BASE\_ADDRESS

Definition at line 264 of file Llce\_InterfaceFifo.h.

## 3.1.3.311 LLCE\_GENERIC\_FIFO\_2\_BASE\_ADDRESS

#define LLCE\_GENERIC\_FIFO\_2\_BASE\_ADDRESS

Definition at line 265 of file Llce\_InterfaceFifo.h.

## 3.1.3.312 LLCE\_GENERIC\_FIFO\_3\_BASE\_ADDRESS

#define LLCE\_GENERIC\_FIFO\_3\_BASE\_ADDRESS

Definition at line 266 of file Llce\_InterfaceFifo.h.

## 3.1.3.313 LLCE\_GET\_GENERIC\_FIFO\_BASE\_ADDRESS

#define LLCE\_GET\_GENERIC\_FIFO\_BASE\_ADDRESS( u8GenFfo )

Definition at line 270 of file Llce\_InterfaceFifo.h.

## 3.1.3.314 LLCE\_GENERIC\_FIFO\_CONFIG

#define LLCE\_GENERIC\_FIFO\_CONFIG( u8GenFfo )

Definition at line 274 of file Llce\_InterfaceFifo.h.

## 3.1.3.315 LLCE\_GENERIC\_FIFO\_STATUS0

#define LLCE\_GENERIC\_FIFO\_STATUS0( u8GenFfo )

Definition at line 276 of file Llce\_InterfaceFifo.h.

## 3.1.3.316 LLCE\_GENERIC\_FIFO\_STATUS1

#define LLCE\_GENERIC\_FIFO\_STATUS1( u8GenFfo )

Definition at line 278 of file Llce\_InterfaceFifo.h.

## 3.1.3.317 LLCE\_GENERIC\_FIFO\_IER

#define LLCE\_GENERIC\_FIFO\_IER( u8GenFfo )

Definition at line 280 of file Llce\_InterfaceFifo.h.

## 3.1.3.318 LLCE\_GENERIC\_FIFO\_ILR

#define LLCE\_GENERIC\_FIFO\_ILR( u8GenFfo )

Definition at line 282 of file Llce\_InterfaceFifo.h.

## 3.1.3.319 LLCE\_GENERIC\_FIFO\_PUSH0

#define LLCE\_GENERIC\_FIFO\_PUSH0( u8GenFfo )

Definition at line 284 of file Llce\_InterfaceFifo.h.

## 3.1.3.320 LLCE\_GENERIC\_FIFO\_POP0

#define LLCE\_GENERIC\_FIFO\_POP0( u8GenFfo )

Definition at line 286 of file Llce\_InterfaceFifo.h.

## 3.1.3.321 LLCE\_GENERIC\_FIFO\_FMR

#define LLCE\_GENERIC\_FIFO\_FMR( u8GenFfo )

Definition at line 288 of file Llce\_InterfaceFifo.h.

## 3.1.3.322 LLCE\_FIFO\_CONFIG

```
#define LLCE_FIFO_CONFIG( u32BaseAddr )
```

Definition at line 291 of file Llce\_InterfaceFifo.h.

## 3.1.3.323 LLCE\_FIFO\_STATUS0

```
#define LLCE_FIFO_STATUS0( u32BaseAddr )
```

Definition at line 292 of file Llce\_InterfaceFifo.h.

## 3.1.3.324 LLCE\_FIFO\_STATUS1

```
#define LLCE_FIFO_STATUS1( u32BaseAddr )
```

Definition at line 293 of file Llce\_InterfaceFifo.h.

## 3.1.3.325 LLCE\_FIFO\_IER

```
#define LLCE_FIFO_IER( u32BaseAddr )
```

Definition at line 294 of file Llce\_InterfaceFifo.h.

## 3.1.3.326 LLCE\_FIFO\_ILR

```
#define LLCE_FIFO_ILR( u32BaseAddr )
```

Definition at line 295 of file Llce\_InterfaceFifo.h.

## 3.1.3.327 LLCE\_FIFO\_PUSH0

```
#define LLCE_FIFO_PUSH0( u32BaseAddr )
```

Definition at line 296 of file Llce\_InterfaceFifo.h.

## 3.1.3.328 LLCE\_FIFO\_POP0

```
#define LLCE_FIFO_POP0( u32BaseAddr )
```

Definition at line 297 of file Llce\_InterfaceFifo.h.

## 3.1.3.329 LLCE\_FIFO\_FMR

```
#define LLCE_FIFO_FMR( u32BaseAddr )
```

Definition at line 298 of file Llce\_InterfaceFifo.h.

## 3.1.3.330 LLCE\_FIFO\_BLRIN\_BASE\_ADDRESS

#define LLCE\_FIFO\_BLRIN\_BASE\_ADDRESS( u8HwCtrl )

Definition at line 300 of file Llce\_InterfaceFifo.h.

## 3.1.3.331 LLCE\_FIFO\_RXOUT\_BASE\_ADDRESS

#define LLCE\_FIFO\_RXOUT\_BASE\_ADDRESS( u8HwCtrl )

Definition at line 302 of file Llce\_InterfaceFifo.h.

## 3.1.3.332 LLCE\_FIFO\_TXACK\_BASE\_ADDRESS

#define LLCE\_FIFO\_TXACK\_BASE\_ADDRESS( u8HwCtrl )

Definition at line 304 of file Llce\_InterfaceFifo.h.

## 3.1.3.333 LLCE\_FIFO\_BLROUT\_BASE\_ADDRESS

#define LLCE\_FIFO\_BLROUT\_BASE\_ADDRESS( u8HwCtrl )

Definition at line 306 of file Llce\_InterfaceFifo.h.

## 3.1.3.334 LLCE\_NOTIF\_FIFO0\_BASE\_ADDRESS

#define LLCE\_NOTIF\_FIFO0\_BASE\_ADDRESS( u8HostCore )

Definition at line 309 of file Llce\_InterfaceFifo.h.

## 3.1.3.335 LLCE\_NOTIF\_FIFO1\_BASE\_ADDRESS

#define LLCE\_NOTIF\_FIFO1\_BASE\_ADDRESS( u8HostCore )

Definition at line 311 of file Llce\_InterfaceFifo.h.

## 3.1.3.336 LLCE\_FIFO\_RXIN\_BASE\_ADDRESS

#define LLCE\_FIFO\_RXIN\_BASE\_ADDRESS( u8HostCore )

Definition at line 314 of file Llce\_InterfaceFifo.h.

## 3.1.3.337 LLCE\_FIFO\_CMD\_BASE\_ADDRESS

#define LLCE\_FIFO\_CMD\_BASE\_ADDRESS( u8HostCore )

Definition at line 316 of file Llce\_InterfaceFifo.h.

## 3.1.3.338 LLCE\_FIFO\_RXINLOG\_BASE\_ADDRESS

#define LLCE\_FIFO\_RXINLOG\_BASE\_ADDRESS( )

Definition at line 319 of file Llce\_InterfaceFifo.h.

## 3.1.3.339 LLCE\_FIFO\_RXOUTLOG\_BASE\_ADDRESS

#define LLCE\_FIFO\_RXOUTLOG\_BASE\_ADDRESS( )

Definition at line 320 of file Llce\_InterfaceFifo.h.

## 3.1.3.340 LLCE\_ICSR\_ADDR

#define LLCE\_ICSR\_ADDR( u8RegNo )

Definition at line 74 of file Llce\_InterfaceIcsr.h.

## 3.1.3.341 LLCE\_ICSR\_RIFA16\_U32

#define LLCE\_ICSR\_RIFA16\_U32

Definition at line 76 of file Llce\_InterfaceIcsr.h.

## 3.1.3.342 LLCE\_ICSR\_ROFA16\_U32

#define LLCE\_ICSR\_ROFA16\_U32

Definition at line 77 of file Llce\_InterfaceIcsr.h.

## 3.1.3.343 LLCE\_ICSR\_TAFA16\_U32

#define LLCE\_ICSR\_TAFA16\_U32

Definition at line 78 of file Llce\_InterfaceIcsr.h.

## 3.1.3.344 LLCE\_ICSR\_GF0AINT\_U32

#define LLCE\_ICSR\_GF0AINT\_U32

Definition at line 80 of file Llce\_InterfaceIcsr.h.

## 3.1.3.345 LLCE\_ICSR\_GF1AINT\_U32

#define LLCE\_ICSR\_GF1AINT\_U32

Definition at line 81 of file Llce\_InterfaceIcsr.h.

## 3.1.3.346 LLCE\_ICSR\_GF2AINT\_U32

#define LLCE\_ICSR\_GF2AINT\_U32 Definition at line 82 of file Llce\_InterfaceIcsr.h.

## 3.1.3.347 LLCE\_ICSR\_GF3AINT\_U32

#define LLCE\_ICSR\_GF3AINT\_U32 Definition at line 83 of file Llce\_InterfaceIcsr.h.

## 3.1.3.348 LLCE\_ICSR\_GF0BINT\_U32

#define LLCE\_ICSR\_GF0BINT\_U32 Definition at line 84 of file Llce\_InterfaceIcsr.h.

## 3.1.3.349 LLCE\_ICSR\_GF1BINT\_U32

#define LLCE\_ICSR\_GF1BINT\_U32 Definition at line 85 of file Llce\_InterfaceIcsr.h.

## 3.1.3.350 LLCE\_ICSR\_GF2BINT\_U32

#define LLCE\_ICSR\_GF2BINT\_U32 Definition at line 86 of file Llce\_InterfaceIcsr.h.

## 3.1.3.351 LLCE\_ICSR\_GF3BINT\_U32

#define LLCE\_ICSR\_GF3BINT\_U32 Definition at line 87 of file Llce\_InterfaceIcsr.h.

## 3.1.3.352 LLCE\_ICSR\_INTFLAG\_00

#define LLCE\_ICSR\_INTFLAG\_00

Definition at line 89 of file Llce\_InterfaceIcsr.h.

## 3.1.3.353 LLCE\_ICSR\_INTFLAG\_01

#define LLCE\_ICSR\_INTFLAG\_01 Definition at line 90 of file Llce\_InterfaceIcsr.h.

## 3.1.3.354 LLCE\_ICSR\_INTFLAG\_02

#define LLCE\_ICSR\_INTFLAG\_02 Definition at line 91 of file Llce\_InterfaceIcsr.h.

## 3.1.3.355 LLCE\_ICSR\_INTFLAG\_03

#define LLCE\_ICSR\_INTFLAG\_03 Definition at line 92 of file Llce\_InterfaceIcsr.h.

## 3.1.3.356 LLCE\_ICSR\_INTFLAG\_04

#define LLCE\_ICSR\_INTFLAG\_04 Definition at line 93 of file Llce\_InterfaceIcsr.h.

## 3.1.3.357 LLCE\_ICSR\_INTFLAG\_05

#define LLCE\_ICSR\_INTFLAG\_05 Definition at line 94 of file Llce\_InterfaceIcsr.h.

## 3.1.3.358 LLCE\_ICSR\_INTFLAG\_06

#define LLCE\_ICSR\_INTFLAG\_06

Definition at line 95 of file Llce\_InterfaceIcsr.h.

## 3.1.3.359 LLCE\_ICSR\_INTFLAG\_07

#define LLCE\_ICSR\_INTFLAG\_07

Definition at line 96 of file Llce\_InterfaceIcsr.h.

## 3.1.4 Types Reference

## 3.1.4.1 Llce\_Can\_GetFwVersionType

typedef Llce\_Fw\_VersionType Llce\_Can\_GetFwVersionType

Get firmware version command.

It is sent by the host to LLCE in order to get the firmware version string. It is copied in the response.

Definition at line 1518 of file Llce\_InterfaceCanTypes.h.

## 3.1.4.2 Llce\_Can\_RemoveAfDestination

typedef uint8 Llce\_Can\_RemoveAfDestination

Remove AF destination command.

It is sent by the host to LLCE in order remove a destination used by AF. It is the index in LLCE list of destination to be removed.

Definition at line 1560 of file Llce\_InterfaceCanTypes.h.

## 3.1.5 Enum Reference

## 3.1.5.1 Llce\_Can\_NotificationIdType

enum Llce\_Can\_NotificationIdType

Notification IDs used to interface with LLCE.

Notifications send by LLCE to host core.

## Module Documentation

## Enumerator

| LLCE_CAN_NOTIF_NOERROR       | No error.                                             |
|------------------------------|-------------------------------------------------------|
| LLCE_CAN_NOTIF_PLATFORMERROR | Error related to the common platform area.            |
| LLCE_CAN_NOTIF_CHANNELERROR  | Error related to a specific channel.                  |
| LLCE_CAN_NOTIF_CTRLMODE      | Notification related to changing CAN controller mode. |

Definition at line 257 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.2 Llce\_Can\_CommandIdType

enum Llce\_Can\_CommandIdType

Command IDs used to interface with LLCE.

Some of those commands are sent by the host to LLCE module and others are sent by LLCE module to the host.

## Enumerator

| LLCE_CAN_CMD_INIT                        | Host initializes LLCE module.                                                                                          |
|------------------------------------------|------------------------------------------------------------------------------------------------------------------------|
| LLCE_CAN_CMD_DEINIT                      | Host deinitializes a specific CAN controller.                                                                          |
| LLCE_CAN_CMD_SETBAUDRATE                 | Host sets a baud rate for a specific CAN controller.                                                                   |
| LLCE_CAN_CMD_GETCONTROLLERMODE           | Host checks the state for a specific CAN controller.                                                                   |
| LLCE_CAN_CMD_SETCONTROLLERMODE           | Host changes the state for a specific CAN controller.                                                                  |
| LLCE_CAN_CMD_MANUAL_BUSOFF_RECO ← ↩ VERY | Host requests the recovery from bus-off state transmission of a specific CAN controller.                               |
| LLCE_CAN_CMD_GETSTATUS                   | LLCE delivers to the host the content of all status registers of the CAN controller.                                   |
| LLCE_CAN_CMD_SETFILTER                   | The host configures multiple filters on the reception side.                                                            |
| LLCE_CAN_CMD_SETADVANCEDFILTER           | The host configures multiple advanced feature filters on reception side.                                               |
| LLCE_CAN_CMD_SETFILTERENABLESTATUS       | The host enables/disables the already set filter.                                                                      |
| LLCE_CAN_CMD_REMOVE_FILTER               | The host invalidates a specific filter.                                                                                |
| LLCE_CAN_CMD_GETFWVERSION                | Request version string from FW.                                                                                        |
| LLCE_CAN_CMD_INIT_PLATFORM               | Host request for platform initialization.                                                                              |
| LLCE_CAN_CMD_INIT_PLATFORM_COMMON        | LLCE internal command request for initialization of common resources.                                                  |
| LLCE_CAN_CMD_DEINIT_PLATFORM             | Host request for platform deinitialization.                                                                            |
| LLCE_CAN_CMD_INIT_PFE                    | Host request for platform initialization regarding CAN2ETH-ETH2CAN use case.                                           |
| LLCE_CAN_CMD_INIT_PFE_EXT_RING_BUF       | Host request for platform initialization regarding CAN2ETH-ETH2CAN use case using ring buffers generated on host side. |

## Enumerator

| LLCE_CAN_CMD_INIT_HSE                          | Host request for platform initialization regarding HSE bridge use case.                                                 |
|------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
| LLCE_CAN_CMD_CREATE_AF_DESTINATION             | Host creates a destination to be used by the advanced routing filters.                                                  |
| LLCE_CAN_CMD_ABORT_MB                          | Host requests the abortion of the lowest priority pending transmission of a specific CAN controller.                    |
| LLCE_CAN_CMD_CUSTOM                            | Custom command to be implemented by user in FDK.                                                                        |
| LLCE_CAN_CMD_SETAUXFILTER                      | The host configures multiple filters on the reception side for rxlut2 on g3.                                            |
| LLCE_CAN_CMD_SETFILTER_AT_ADDRESS              | The host requests the addition of a new filter by specifying filter address.                                            |
| LLCE_CAN_CMD_SETCHANNELROUTINGO ← ↩ UTPUTSTATE | The host enables or disables a channel in a routing multicast configuration.                                            |
| LLCE_CAN_CMD_SETCAN2ETHSTATE                   | The host enables or disables Can2Eth processing entirely.                                                               |
| LLCE_CAN_CMD_SETETH2CANFORMATST ← ↩ ATE        | The host enables or disables Eth2Can processing for a format.                                                           |
| LLCE_CAN_CMD_SETADVANCEDFILTER_A ← ↩ T_ADDRESS | The host requests the addition of a new advanced filter by specifying filter address.                                   |
| LLCE_CAN_CMD_SETCAN2PCIESTATE                  | The host enables or disables Can2Pcie processing entirely.                                                              |
| LLCE_CAN_CMD_SHUTDOWN                          | The host requests all LLCE cores to execute WFI and shut down.                                                          |
| LLCE_CAN_CMD_REMOVE_AF_DESTINATI ← ↩ ON        | Host removes a destination which is used by the advanced routing filters. Stored data of this destination will be lost. |

Definition at line 275 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.3 Llce\_Can\_IdLengthType

enum Llce\_Can\_IdLengthType

CAN frame ID type.

Specifies the CAN frame ID type based on it's length as it is defined by the CAN specification.

## Enumerator

| LLCE_CAN_EXTENDED   | Extended ID (29 bits)   |
|---------------------|-------------------------|
| LLCE_CAN_STANDARD   | Standard ID (11 bits)   |
| LLCE_CAN_MIXED      | Mixed ID (29 bits)      |

## Module Documentation

Definition at line 369 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.4 Llce\_Can\_StateTransitionType

```
enum Llce_Can_StateTransitionType
```

Requested transitions of a CAN controller.

These controller state transitions are requested by the host in a specific order.

## Enumerator

| LLCE_CAN_T_STOP   | Request transition from START state into STOP state.   |
|-------------------|--------------------------------------------------------|
| LLCE_CAN_T_START  | Request transition from STOP state into START state.   |

Definition at line 385 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.5 Llce\_Can\_CtrlStateType

```
enum Llce_Can_CtrlStateType
```

## CAN controller states.

CAN controller states as they are reported by the LLCE firmware as a result of state transition requests.

Enumerator

| LLCE_CAN_UNINIT_CTRL         | Controller is uninitialised (default)                                                                        |
|------------------------------|--------------------------------------------------------------------------------------------------------------|
| LLCE_CAN_UNINIT_CTRL_PENDING | Controller is in a pending state of unitialization, waiting for the resources to be restored (e.g Rx tokens) |
| LLCE_CAN_STOP_PENDING        | Controller is stopping, but not offline yet.                                                                 |
| LLCE_CAN_BUSOFF_PENDING      | Controller is in the BUSOFF_PENDING state which means that it does not do any bus transactions.              |
| LLCE_CAN_STOPPED             | Controller is in the STOPPED state which means that it does not do any bus transactions.                     |
| LLCE_CAN_START_PENDING       | Controller is starting, but cannot do bus transactions yet.                                                  |
| LLCE_CAN_STARTED             | Controller is in the STARTED state which means that it do bus transactions.                                  |
| LLCE_CAN_IDLE                | Controller is in the IDLE state. This state is not used by LLCE module.                                      |
| LLCE_CAN_UNINIT_PLATFORM     | Controller is in state when the common components of the platform are not initialized.                       |

Definition at line 399 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.6 Llce\_Can\_ModuleType

enum Llce\_Can\_ModuleType

CAN firmware components IDs.

CAN firmware components IDs used to identify the component which generated a specific error.

Enumerator

| LLCE_TX            | CAN TX firmware component.                     |
|--------------------|------------------------------------------------|
| LLCE_RX            | CAN RX firmware component.                     |
| LLCE_DTE           | CAN DTE firmware component.                    |
| LLCE_FRPE          | CAN FRPE firmware component.                   |
| LLCE_CAN2CAN_TX    | CAN2CAN TX firmware component.                 |
| LLCE_CAN2CAN_RX    | CAN2CAN RX firmware component.                 |
| LLCE_CAN2CAN_FRPE  | CAN2CAN FRPE firmware component.               |
| LLCE_AF_ETH_TX     | AF ETH2CAN TX firmware component.              |
| LLCE_AF_ETH_RX     | AF CAN2ETH RX firmware component.              |
| LLCE_AF_ETH_FRPE   | AF CAN2ETH or ETH2CAN FRPE firmware component. |
| LLCE_AF_HSE_TX     | HSE TX firmware component.                     |
| LLCE_AF_HSE_RX     | HSE RX firmware component.                     |
| LLCE_AF_HSE_FRPE   | HSE FRPE firmware component.                   |
| LLCE_AF_TX         | AF TX firmware component.                      |
| LLCE_AF_RX         | AF RX firmware component.                      |
| LLCE_AF_FRPE       | AF FRPE firmware component.                    |
| LLCE_HEADLESS_TX   | Headless TX boot firmware component.           |
| LLCE_HEADLESS_RX   | Headless RX boot firmware component.           |
| LLCE_HEADLESS_FRPE | Headless FRPE boot firmware component.         |

Definition at line 445 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.7 Llce\_Af\_LoggingOptionsType

enum Llce\_Af\_LoggingOptionsType

CAN Logging options.

CAN options for logging frames feature.

## Module Documentation

Enumerator

| LLCE_AF_LOGGING_DISABLED   | Logging of CAN frame is disabled.   |
|----------------------------|-------------------------------------|
| LLCE_AF_LOGGING_ENABLED    | Logging of CAN frame is enabled.    |

Definition at line 492 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.8 Llce\_Can\_HostReceiveOptionsType

enum Llce\_Can\_HostReceiveOptionsType

Enumerator

| LLCE_AF_HOSTRECEIVE_DISABLED   | Reception of the CAN frame by the host is disabled.   |
|--------------------------------|-------------------------------------------------------|
| LLCE_AF_HOSTRECEIVE_ENABLED    | Reception of the CAN frame by the host is enabled.    |

Definition at line 500 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.9 Llce\_Af\_AuthenticationOptionsType

enum Llce\_Af\_AuthenticationOptionsType

Enumerator

| LLCE_AF_AUTHENTICATION_DISABLED      | Authentication of CAN frame is disabled.   |
|--------------------------------------|--------------------------------------------|
| LLCE_AF_AUTHENTICATION_ENABLED       | Authentication of CAN frame is enabled.    |
| LLCE_AF_AUTHENTICATION_NOT_SUPPORTED |                                            |

Definition at line 508 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.10 Llce\_Af\_CustomProcessingOptionsType

enum Llce\_Af\_CustomProcessingOptionsType

Enumerator

| LLCE_AF_CUSTOMPROCESSING_DISABLED   | Custom processing of CAN frame is disabled.   |
|-------------------------------------|-----------------------------------------------|
| LLCE_AF_CUSTOMPROCESSING_ENABLED    | Custom processing of CAN frame is enabled.    |

Definition at line 517 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.11 Llce\_Can\_EntryType

```
enum Llce_Can_EntryType
```

RXLUT entries type.

Specifies the type of entry in the table.

Enumerator

| LLCE_CAN_ENTRY_EXACT_MATCH   | Exact match entry type.   |
|------------------------------|---------------------------|
| LLCE_CAN_ENTRY_CFG_MASKED    | Masked match entry type.  |
| LLCE_CAN_ENTRY_CFG_RANGED    | Range match entry type.   |

Definition at line 530 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.12 Llce\_Af\_RuleIdType

enum Llce\_Af\_RuleIdType

Type of Advanced Feature(AF) rule.

Specifies the type of entry in the destination rule table.

Enumerator

| CAN_AF_CAN2CAN   | Destination rule type used for Can2Can use case.   |
|------------------|----------------------------------------------------|
| CAN_AF_CAN2ETH   | Destination rule type used for Can2Eth use case.   |
| CAN_AF_CAN2PCIE  | Destination rule type used for Can2Pcie use case.  |
| CAN_AF_CAN2HSE   | Destination rule type used for Can2Hse use case.   |

Definition at line 545 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.13 Llce\_Can\_EthEncapsulationFormat

enum Llce\_Can\_EthEncapsulationFormat

## Module Documentation

Type of Can2Eth routing.

Speccifies the type of packing to apply for Can2Eth

Enumerator

| LLCE_AF_CAN2AVTP_NTSCF_BRIEF   | IEEE1722-2016 AVPT non-time-synchronous CAN brief format.   |
|--------------------------------|-------------------------------------------------------------|
| LLCE_AF_CAN2AVTP_NTSCF_FULL    | IEEE1722-2016 AVPT non-time-synchronous CAN regular format. |
| LLCE_AF_CAN2AVTP_TSCF_BRIEF    | IEEE1722-2016 AVPT time-synchronous CAN brief format.       |
| LLCE_AF_CAN2AVTP_TSCF_FULL     | IEEE1722-2016 AVPT time-synchronous CAN regular format.     |
| LLCE_AF_CAN2UDP                | UDP format, over IPv4.                                      |
| LLCE_AF_CAN2UDP_B              | UDP format, type B, over IPv4.                              |
| LLCE_AF_CAN2UDP_IPV6           | UDP format, over IPv6.                                      |
| LLCE_AF_CAN2UDP_B_IPV6         | UDP format, type B, over IPv6.                              |
| LLCE_AF_CAN2ETH_FORMAT_MAX     | Placeholder for maximum value.                              |

Definition at line 562 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.14 Llce\_Can\_StatusType

enum Llce\_Can\_StatusType

Initialization status of the controllers.

Initialization status of the controllers. See Llce\_Can\_InitPlatformCmdType.

Enumerator

| INITIALIZED   | Entity is initialised.            |
|---------------|-----------------------------------|
| UNINITIALIZED | Entity is uninitialised (default) |

Definition at line 589 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.15 Llce\_Can\_ErrorProcessingType

enum Llce\_Can\_ErrorProcessingType

Processing type of a specific error.

Processing type of a specific error. See Llce\_Can\_InitPlatformCmdType.

Enumerator

| IGNORE                         | LLCE Firmware does not report the error.                                                                                             |
|--------------------------------|--------------------------------------------------------------------------------------------------------------------------------------|
| NOTIF_FIFO0                    | LLCE Firmware reports the error through the notification table corresponding to processing type configured by host.                  |
| NOTIF_FIFO1 NXP Semiconductors | LLCE Firmware reports the error through the notification table corresponding to processing type configured by host. LLCEfirmware 171 |

## Module Documentation

## Module Documentation

Definition at line 603 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.16 Llce\_Can\_AbortMbType

```
enum Llce_Can_AbortMbType
```

AbortMB Type.

Specifies the type of AbortMB command. It can be either Single MB abort or All MBs abort

Enumerator

| ABORT_ONLY_ONE_MB   | Request aborting of a single MB with a specific MB tag.   |
|---------------------|-----------------------------------------------------------|
| ABORT_ALL_MB        | Request aborting of all the MBs with a specific MB tag.   |

Definition at line 625 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.17 Llce\_CanRx\_MbLengthType

```
enum Llce_CanRx_MbLengthType
```

MB length accepted by a filter.

MB length (8/64 bytes) configured to be accepted by a filter. No mixed mode available.

Enumerator

| USE_LONG_MB   | Opt for 64 bytes MB size accepted by a filter.   |
|---------------|--------------------------------------------------|
| USE_SHORT_MB  | Opt for 8 bytes MB size accepted by a filter.    |

Definition at line 638 of file Llce\_InterfaceCanTypes.h.

## 3.1.5.18 Llce\_Can\_BinaryValueType

```
enum Llce_Can_BinaryValueType
```

Generic binary type.

Logical binary type. Redefined for consistency.

Enumerator

| LLCE_FALSE   |
|--------------|
| LLCE_TRUE    |

Definition at line 651 of file Llce\_InterfaceCanTypes.h.

## 3.1.6 Variable Documentation

## 3.1.6.1 Llce\_Can\_u32BlrinBaseAddress

```
const uint32 Llce_Can_u32BlrinBaseAddress[(16U)] [extern]
```

## 3.1.6.2 Llce\_Can\_u32BlroutBaseAddress

```
const uint32 Llce_Can_u32BlroutBaseAddress[(16U)] [extern]
```

## 3.1.6.3 Llce\_Can\_u32TxackBaseAddress

```
const uint32 Llce_Can_u32TxackBaseAddress[(16U)+(6U)] [extern]
```

## 3.1.6.4 Llce\_Can\_u32RxoutBaseAddress

```
const uint32 Llce_Can_u32RxoutBaseAddress[(16U)+(6U)] [extern]
```

## 3.1.6.5 Llce\_Can\_u32NotifFifo0BaseAddress

```
const uint32 Llce_Can_u32NotifFifo0BaseAddress[(2U)] [extern]
```

## Module Documentation

## 3.1.6.6 Llce\_Can\_u32NotifFifo1BaseAddress

```
const uint32 Llce_Can_u32NotifFifo1BaseAddress[(2U)] [extern]
```

## 3.1.6.7 Llce\_Can\_u32RxinBaseAddress

```
const uint32 Llce_Can_u32RxinBaseAddress[(2U)] [extern]
```

## 3.1.6.8 Llce\_Can\_u32CmdBaseAddress

```
const uint32 Llce_Can_u32CmdBaseAddress[(2U)] [extern]
```

## 3.1.6.9 Llce\_Can\_u32RxinLogBaseAddress

```
const uint32 Llce_Can_u32RxinLogBaseAddress[1] [extern]
```

## 3.1.6.10 Llce\_Can\_u32RxoutLogBaseAddress

```
const uint32 Llce_Can_u32RxoutLogBaseAddress[1] [extern]
```

## 3.2 LLCE precompile configuration parameters

## 3.2.1 Detailed Description

## Data Structures

- struct Llce\_Mgr\_StatusType

Boot sequence data type. More...

- struct Llce\_Mgr\_TimeStampCoresType

Structure for the timestamps of cores 1, 2, and 3. More...

## Macros

- #define LLCE\_CAN\_CONFIG\_DEFAULT\_CAN\_CTRL\_HOST0\_U8
- Default controller ID needed by the host 0 interface in order to transmit INIT\_PLATFORM and DEINIT\_PLA ← ↩ TFORM commands from host to LLCE.
- #define LLCE\_CAN\_CONFIG\_DEFAULT\_CAN\_CTRL\_HOST1\_U8
- Default controller ID needed by the host 1 interface in order to transmit INIT\_PLATFORM and DEINIT\_PLA ← ↩ TFORM commands from host to LLCE.
- #define LLCE\_CAN\_CONFIG\_NOTIF\_TABLE\_SIZE

Maximum number of notifications which can be reported by LLCE to host.

- #define LLCE\_CAN\_CONFIG\_PAYLOAD\_MAX\_SIZE

Maximum buffer size used to store the CAN FD frame payload. See Llce\_Can\_MbType.

- #define LLCE\_CAN\_CONFIG\_SHORT\_PAYLOAD\_MAX\_SIZE

Maximum buffer size used to store the short CAN FD frame payload. See Llce\_Can\_ShortMbType.

- #define LLCE\_CAN\_CONFIG\_MAXCTRL\_COUNT
- Maximum number of hardware controllers usable inside LLCE. See Llce\_Can\_InitCmdType.
- #define LLCE\_CAN\_MAX\_POLLING\_CLASSES
- Maximum number of polling classes usable inside LLCE. A polling class is used to tie together multiple filters which report the received frames in polling. See Llce\_Can\_InitCmdType.
- #define LLCE\_CAN\_CONFIG\_MAXTXMB
- Maximum number of transmission message buffers. See Llce\_Can\_TxMbDescriptorType.
- #define LLCE\_CAN\_CONFIG\_MAXRXMB
- Maximum number of 64B reception message buffers. Note: 32 from those are reserved for internal usage and are not available to the host. See Llce\_Can\_RxMbDescriptorType.
- #define LLCE\_CAN\_CONFIG\_MAX\_SHORTRXMB
- Maximum number of 8B reception message buffers. for internal usage and are not available to the host. See Llce\_Can\_RxMbDescriptorType.
- #define LLCE\_CAN\_CONFIG\_MAXAFRXMB

Number of AF descriptors reserved for each internal path within LLCE frame routing.

- #define LLCE\_CAN\_CONFIG\_MAXAFTXMB
- #define LLCE\_CAN\_CONFIG\_MAX\_FILTERS\_COUNT
- #define LLCE\_CAN\_CONFIG\_MAXAFFRMB
- Maximum number of standard filters which can be configured using using a single command. Multiple commands can be executed when more filters are needed. See Llce\_Can\_ReceiveFilterType.
- #define LLCE\_CAN\_CONFIG\_MAX\_TXACKINFO

## Module Documentation

Number of entries of the circular buffer used to send ack information from TX core to host core. There is 1 extra buffer for each interface for consistency purpose.

- #define LLCE\_CAN\_CONFIG\_FIFO\_FIXED\_MASK\_U32

Mask used to get the right data from FIFOs. See FMR config register of FIFO.

- #define LLCE\_CAN\_CONFIG\_ADVANCED\_FILTERS\_COUNT

Maximum number of advanced filters which can be configured using a single command. Multiple commands can be executed when more filters are needed. See Llce\_Can\_AdvancedFilterType.

- #define LLCE\_CAN\_CONFIG\_CTRL\_SHARED\_MEMORY\_SIZE

Shared memory size allocated for each channel for commands exchange.

- #define LLCE\_CAN\_ADVANCED\_FILTER\_NOT\_USED

Reserved value in order to detect if an advanced filter entry is not used.

- #define LLCE\_CAN\_HIF0

Interface ID used by different hosts for multihost scenarios.

- #define LLCE\_CAN\_HIF1

Interface ID used by different hosts for multihost scenarios.

- #define LLCE\_CAN\_CONFIG\_HIF\_COUNT

Number of interfaces which can be used by host cores.

- #define LLCE\_CAN\_CONFIG\_IER\_SEMA4\_COUNT

Number of semaphores for each HIF.

- #define LLCE\_FIFO\_RXOUT\_INDEX

Index of FIFO\_RXOUT inside Can\_Sema4\_Ier array.

- #define LLCE\_FIFO\_TXACK\_INDEX
- Index of FIFO\_TXACK inside Can\_Sema4\_Ier array.
- #define LLCE\_CAN\_HIF0\_FIFO\_CNT

Number of FIFOs used by first HIF.

- #define LLCE\_HOST\_CORE\_SEMA42\_DOMAIN

Semaphore core domain.

- #define LLCE\_RXLUT2\_NO\_RESULT

No result from RxLut2.

- #define LLCE\_LIN\_CONFIG\_PAYLOAD\_MAX\_SIZE
- Maximum buffer size used to store the LIN frame payload.
- #define LLCE\_LIN\_CONFIG\_MAXTXBUFF
- Maximum number of LIN transmission buffers.
- #define LLCE\_LIN\_CONFIG\_MAXRXBUFF
- Maximum number of LIN reception buffers.

## Enum Reference

- enum Llce\_Fw\_Notification\_Category

CAN firmware notification categories.

- enum Llce\_Fw\_ReturnType

CAN firmware error values.

## Function Reference

- void DisableFifoInterrupts (uint8 u8FifoInterface, uint8 u8Hif)
- void EnableFifoInterrupts (uint8 u8FifoInterface, uint8 u8Hif)

## 3.2.1.1 MISRA-C:2012 violations

## 3.2.2 Data Structure Documentation

## 3.2.2.1 struct Llce\_Mgr\_StatusType

Boot sequence data type.

Data type used to access shared memory area for managing LLCE boot sequence

Definition at line 530 of file Llce\_InterfaceFwMgr.h.

Data Fields

| Llce_Fw_ReturnType   | eTxBootStatus   | OUTPUT: Boot Status of TXPPE. This can be NOTRUN, SUCCESS, or a specific ERROR information.   |
|----------------------|-----------------|-----------------------------------------------------------------------------------------------|
| Llce_Fw_ReturnType   | eRxBootStatus   | OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or a specific ERROR information.   |
| Llce_Fw_ReturnType   | eDteBootStatus  | OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or a specific ERROR information.   |
| Llce_Fw_ReturnType   | eFrpeBootStatus | OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or a specific ERROR information.   |
| Llce_Fw_VersionType  | LlceFwVersion   | OUTPUT: LLCE FW version structure.                                                            |

## 3.2.2.2 struct Llce\_Mgr\_TimeStampCoresType

Structure for the timestamps of cores 1, 2, and 3.

Structure contains the timestamps for the cores 1, 2, and 3 and shall be read by host in order to verify if a crash, or high delay has occurred or not.

Definition at line 563 of file Llce\_InterfaceFwMgr.h.

Data Fields

| uint32   | timeStampCore1   | Timestamp for Core 1.   |
|----------|------------------|-------------------------|
| uint32   | timeStampCore2   | Timestamp for Core 2.   |
| uint32   | timeStampCore3   | Timestamp for Core 3.   |

## 3.2.3 Macro Definition Documentation

## 3.2.3.1 LLCE\_CAN\_CONFIG\_DEFAULT\_CAN\_CTRL\_HOST0\_U8

#define LLCE\_CAN\_CONFIG\_DEFAULT\_CAN\_CTRL\_HOST0\_U8

Default controller ID needed by the host 0 interface in order to transmit INIT\_PLATFORM and DEINIT\_PLA ← ↩ TFORM commands from host to LLCE.

Definition at line 100 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.2 LLCE\_CAN\_CONFIG\_DEFAULT\_CAN\_CTRL\_HOST1\_U8

#define LLCE\_CAN\_CONFIG\_DEFAULT\_CAN\_CTRL\_HOST1\_U8

Default controller ID needed by the host 1 interface in order to transmit INIT\_PLATFORM and DEINIT\_PLA ← ↩ TFORM commands from host to LLCE.

Definition at line 105 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.3 LLCE\_CAN\_CONFIG\_NOTIF\_TABLE\_SIZE

#define LLCE\_CAN\_CONFIG\_NOTIF\_TABLE\_SIZE

Maximum number of notifications which can be reported by LLCE to host.

Definition at line 111 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.4 LLCE\_CAN\_CONFIG\_PAYLOAD\_MAX\_SIZE

#define LLCE\_CAN\_CONFIG\_PAYLOAD\_MAX\_SIZE

Maximum buffer size used to store the CAN FD frame payload. See Llce\_Can\_MbType.

Definition at line 116 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.5 LLCE\_CAN\_CONFIG\_SHORT\_PAYLOAD\_MAX\_SIZE

#define LLCE\_CAN\_CONFIG\_SHORT\_PAYLOAD\_MAX\_SIZE

Maximum buffer size used to store the short CAN FD frame payload. See Llce\_Can\_ShortMbType.

Definition at line 121 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.6 LLCE\_CAN\_CONFIG\_MAXCTRL\_COUNT

#define LLCE\_CAN\_CONFIG\_MAXCTRL\_COUNT

Maximum number of hardware controllers usable inside LLCE. See Llce\_Can\_InitCmdType.

Definition at line 126 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.7 LLCE\_CAN\_MAX\_POLLING\_CLASSES

#define LLCE\_CAN\_MAX\_POLLING\_CLASSES

Maximum number of polling classes usable inside LLCE. A polling class is used to tie together multiple filters which report the received frames in polling. See Llce\_Can\_InitCmdType.

Definition at line 133 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.8 LLCE\_CAN\_CONFIG\_MAXTXMB

#define LLCE\_CAN\_CONFIG\_MAXTXMB

Maximum number of transmission message buffers. See Llce\_Can\_TxMbDescriptorType.

Definition at line 139 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.9 LLCE\_CAN\_CONFIG\_MAXRXMB

#define LLCE\_CAN\_CONFIG\_MAXRXMB

Maximum number of 64B reception message buffers. Note: 32 from those are reserved for internal usage and are not available to the host. See Llce\_Can\_RxMbDescriptorType.

Definition at line 146 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.10 LLCE\_CAN\_CONFIG\_MAX\_SHORTRXMB

#define LLCE\_CAN\_CONFIG\_MAX\_SHORTRXMB

Maximum number of 8B reception message buffers. for internal usage and are not available to the host. See Llce\_Can\_RxMbDescriptorType.

Definition at line 153 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.11 LLCE\_CAN\_CONFIG\_MAXAFRXMB

#define LLCE\_CAN\_CONFIG\_MAXAFRXMB

Number of AF descriptors reserved for each internal path within LLCE frame routing.

Definition at line 160 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.12 LLCE\_CAN\_CONFIG\_MAXAFTXMB

#define LLCE\_CAN\_CONFIG\_MAXAFTXMB

Definition at line 161 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.13 LLCE\_CAN\_CONFIG\_MAXAFFRMB

#define LLCE\_CAN\_CONFIG\_MAXAFFRMB

Definition at line 162 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.14 LLCE\_CAN\_CONFIG\_MAX\_FILTERS\_COUNT

#define LLCE\_CAN\_CONFIG\_MAX\_FILTERS\_COUNT

Maximum number of standard filters which can be configured using using a single command. Multiple commands can be executed when more filters are needed. See Llce\_Can\_ReceiveFilterType.

Definition at line 170 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.15 LLCE\_CAN\_CONFIG\_MAX\_TXACKINFO

#define LLCE\_CAN\_CONFIG\_MAX\_TXACKINFO

Number of entries of the circular buffer used to send ack information from TX core to host core. There is 1 extra buffer for each interface for consistency purpose.

Definition at line 176 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.16 LLCE\_CAN\_CONFIG\_FIFO\_FIXED\_MASK\_U32

#define LLCE\_CAN\_CONFIG\_FIFO\_FIXED\_MASK\_U32

Mask used to get the right data from FIFOs. See FMR config register of FIFO.

Definition at line 181 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.17 LLCE\_CAN\_CONFIG\_ADVANCED\_FILTERS\_COUNT

#define LLCE\_CAN\_CONFIG\_ADVANCED\_FILTERS\_COUNT

Maximum number of advanced filters which can be configured using a single command. Multiple commands can be executed when more filters are needed. See Llce\_Can\_AdvancedFilterType.

Definition at line 188 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.18 LLCE\_CAN\_CONFIG\_CTRL\_SHARED\_MEMORY\_SIZE

#define LLCE\_CAN\_CONFIG\_CTRL\_SHARED\_MEMORY\_SIZE

Shared memory size allocated for each channel for commands exchange.

Definition at line 193 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.19 LLCE\_CAN\_ADVANCED\_FILTER\_NOT\_USED

#define LLCE\_CAN\_ADVANCED\_FILTER\_NOT\_USED

Reserved value in order to detect if an advanced filter entry is not used.

Definition at line 198 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.20 LLCE\_CAN\_HIF0

#define LLCE\_CAN\_HIF0

Interface ID used by different hosts for multihost scenarios.

Definition at line 200 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.21 LLCE\_CAN\_HIF1

#define LLCE\_CAN\_HIF1

Interface ID used by different hosts for multihost scenarios.

Definition at line 202 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.22 LLCE\_CAN\_CONFIG\_HIF\_COUNT

#define LLCE\_CAN\_CONFIG\_HIF\_COUNT

Number of interfaces which can be used by host cores.

Definition at line 204 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.23 LLCE\_CAN\_CONFIG\_IER\_SEMA4\_COUNT

#define LLCE\_CAN\_CONFIG\_IER\_SEMA4\_COUNT

Number of semaphores for each HIF.

Definition at line 206 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.24 LLCE\_FIFO\_RXOUT\_INDEX

#define LLCE\_FIFO\_RXOUT\_INDEX

Index of FIFO\_RXOUT inside Can\_Sema4\_Ier array.

Definition at line 208 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.25 LLCE\_FIFO\_TXACK\_INDEX

#define LLCE\_FIFO\_TXACK\_INDEX

Index of FIFO\_TXACK inside Can\_Sema4\_Ier array.

Definition at line 210 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.26 LLCE\_CAN\_HIF0\_FIFO\_CNT

#define LLCE\_CAN\_HIF0\_FIFO\_CNT

Number of FIFOs used by first HIF.

Definition at line 212 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.27 LLCE\_HOST\_CORE\_SEMA42\_DOMAIN

#define LLCE\_HOST\_CORE\_SEMA42\_DOMAIN

Semaphore core domain.

Definition at line 214 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.28 LLCE\_RXLUT2\_NO\_RESULT

#define LLCE\_RXLUT2\_NO\_RESULT

No result from RxLut2.

Definition at line 216 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.29 LLCE\_LIN\_CONFIG\_PAYLOAD\_MAX\_SIZE

#define LLCE\_LIN\_CONFIG\_PAYLOAD\_MAX\_SIZE

Maximum buffer size used to store the LIN frame payload.

Definition at line 221 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.30 LLCE\_LIN\_CONFIG\_MAXTXBUFF

#define LLCE\_LIN\_CONFIG\_MAXTXBUFF

Maximum number of LIN transmission buffers.

Definition at line 223 of file Llce\_InterfaceCanConfig.h.

## 3.2.3.31 LLCE\_LIN\_CONFIG\_MAXRXBUFF

#define LLCE\_LIN\_CONFIG\_MAXRXBUFF

Maximum number of LIN reception buffers.

Definition at line 225 of file Llce\_InterfaceCanConfig.h.

## 3.2.4 Enum Reference

## 3.2.4.1 Llce\_Fw\_Notification\_Category

```
enum Llce_Fw_Notification_Category
```

CAN firmware notification categories.

Contains the notification categories of the values returned by the LLCE Firmware.

See also

Llce\_Fw\_ReturnType

Enumerator

| LLCE_NOTIFCAT_CAN_PROTOCOL                |
|-------------------------------------------|
| LLCE_NOTIFCAT_DATA_LOST                   |
| LLCE_NOTIFCAT_CONFIGURATION               |
| LLCE_NOTIFCAT_INTERNAL                    |
| LLCE_NOTIFCAT_BUSOFF                      |
| LLCE_NOTIFCAT_FW_STATUS                   |
| LLCE_NOTIFCAT_CAN_PROTOCOL_CRITICAL_STATE |

Definition at line 113 of file Llce\_InterfaceFwMgr.h.

## 3.2.4.2 Llce\_Fw\_ReturnType

enum Llce\_Fw\_ReturnType

CAN firmware error values.

CAN error values as they are reported by the LLCE firmware. Some of them are channel related and other are platform related.

Enumerator

| LLCE_ERROR_TXACK_FIFO_FULL       | CAN firmware error: BOTH SW AND HW TXACK FIFOS are full.                                                                                               |
|----------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_ERROR_RXOUT_FIFO_FULL       | CAN firmware error: RXOUT SW FIFO is full.                                                                                                             |
| LLCE_ERROR_CODE_RESERVED_0       | CAN firmware error: Reserved for future use.                                                                                                           |
| LLCE_ERROR_HW_FIFO_FULL          | CAN firmware error: The system lost indexes or HW FIFO was not cleared and it is full.                                                                 |
| LLCE_ERROR_SW_FIFO_EMPTY         | CAN firmware error: There was an attempt to perform a pop operation on an empty SW FIFO.                                                               |
| LLCE_ERROR_SW_FIFO_FULL          | CAN firmware error: There was an attempt to perform a push operation on a full SW FIFO.                                                                |
| LLCE_ERROR_MB_NOTAVAILABLE       | CAN firmware error: The maximum hardware object count on the reception side was reached.                                                               |
| LLCE_ERROR_SHORT_MB_NOTAVAILABLE | CAN firmware error: Short Message buffer is configured but a long frame is received.                                                                   |
| LLCE_ERROR_BCAN_FRZ_EXIT         | CAN firmware error: Reserved for future use.                                                                                                           |
| LLCE_ERROR_BCAN_SYNC             | CAN firmware error: Reserved for future use.                                                                                                           |
| LLCE_ERROR_BCAN_FRZ_ENTER        | CAN firmware error: Reserved for future use.                                                                                                           |
| LLCE_ERROR_BCAN_LPM_EXIT         | CAN firmware error: CAN protocol error due to inability to enter in low-power mode.                                                                    |
| LLCE_ERROR_BCAN_SRT_ENTER        | CAN firmware error: CAN protocol error due to inability to enter in soft reset.                                                                        |
| LLCE_ERROR_BCAN_UNKNOWN_ERROR    | CAN firmware error: An error callback was called, but no error code matches : unknown CAN protocol error.                                              |
| LLCE_ERROR_BCAN_ACKERR           | CAN firmware error: ACKERR indicates that an acknowledge error has been detected by the transmitter node.                                              |
| LLCE_ERROR_BCAN_CRCERR           | CAN firmware error: CRCERR indicates that a CRC error has been detected by the receiver node in a CAN frame.                                           |
| LLCE_ERROR_BCAN_BIT0ERR          | CAN firmware error: BIT0ERR indicates when an inconsistency occurs between the transmitted and the received bit in a CAN frame.                        |
| LLCE_ERROR_BCAN_BIT1ERR          | CAN firmware error: BIT1ERR indicates when an inconsistency occurs between the transmitted and the received bit in a CAN frame.                        |
| LLCE_ERROR_BCAN_DPBIT1ERR        | CAN firmware error: DPBIT1ERR indicates when an inconsistency occurs between the transmitted and the received bit in the data phase of a CAN-FD frame. |
| LLCE_ERROR_BCAN_DPBIT0ERR        | CAN firmware error: DPBIT0ERR indicates when an inconsistency occurs between the transmitted and the received bit in the data phase of a CAN-FD frame. |
| LLCE_ERROR_BCAN_DPSTFERR         | CAN firmware error: DPSTFERR indicates that a stuffing error has been detected by the receiver node in the data phase of a CAN-FD frame.               |

Enumerator

| LLCE_ERROR_BCAN_DPFRMERR        | CAN firmware error: DPFRMERR indicates that a form error has been detected by the receiver node in the data phase of a CAN-FD frame. • a fixed-form bit field contains at least one illegal bit.   |
|---------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_ERROR_BCAN_DPCRCERR        | CAN firmware error: DPCRCERR indicates that a CRC error has been detected by the receiver node in the data phase of a CAN-FD frame.                                                                |
| LLCE_ERROR_BCAN_FRMERR          | CAN firmware error: FRMERR indicates that a form error has been detected by the receiver node in a CAN frame - a fixed-form bit field contains at least one illegal bit.                           |
| LLCE_ERROR_BCAN_STFERR          | CAN firmware error: STFERR indicates that a stuffing error has been detected by the receiver node in a CAN frame.                                                                                  |
| LLCE_ERROR_BCAN_TDCFAIL         | CAN firmware error: TDC mechanism is out of range, unable to compensate the transceiver's loop delay.                                                                                              |
| LLCE_ERROR_BCAN_RXFIFO_OVERRUN  | CAN firmware error: DataLost event caused by BCAN RX Fifo Overrun.                                                                                                                                 |
| LLCE_ERROR_DATA_LOST            | CAN firmware error: Reports data lost event due to resources exceeded after the frame was received.                                                                                                |
| LLCE_ERROR_TXLUT_FULL           | CAN firmware error: The number of Message Buffers available for transmission arbitration was exceeded or the status register indicates that the TXLUT accelerator is full.                         |
| LLCE_ERROR_CMD_PROCESSING       | CAN firmware error: A command with an unknown id was issued or the current host tried to overlap the other host's resources at initialization.                                                     |
| LLCE_ERROR_CODE_RESERVED_1      | CAN firmware error: Reserved for future use.                                                                                                                                                       |
| LLCE_ERROR_RXLUT_ACCESS_MODE    | CAN firmware error: Indicates hardware malfunction when trying to perform a read or write operation on RXLUT registers.                                                                            |
| LLCE_ERROR_RXLUT_SEARCH_MODE    | CAN firmware error: Indicates hardware malfunction when trying to perform a read or write operation on RXLUT registers.                                                                            |
| LLCE_ERROR_RXLUT_SLOW_OPERATION | CAN firmware error: Indicates hardware malfunction when trying to perform a read on RXLUT registers and no value was obtained within a configured timeout.                                         |
| LLCE_ERROR_RXLUT_INCOMPLETE_OP  | CAN firmware error: Indicates hardware malfunction when trying to perform a read on the RXLUT status register during search operation and no value was obtained within a configured timeout.       |
| LLCE_ERROR_RXLUT_OPERATING_MODE | CAN firmware error: Indicates hardware malfunction when trying to perform a read on the RXLUT status register during flush operation and no value was obtained within a configured timeout.        |

## Enumerator

| LLCE_ERROR_RXLUT_INIT_SLOW_OP               | CAN firmware error: Failed to configure the filter entry address and issue write command.                                                             |
|---------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_ERROR_CODE_RESERVED_2                  | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_CODE_RESERVED_3                  | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_CODE_RESERVED_4                  | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_CODE_RESERVED_5                  | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_CODE_RESERVED_6                  | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_CTRL_NOT_READY                   | CAN firmware error: Controller is not started or bus-off event has occured.                                                                           |
| LLCE_ERROR_BUSOFF                           | CAN firmware error: A bus off event was triggered. This notification is skipped in case of auto-recovery.                                             |
| LLCE_ERROR_FIFO_LOG_FULL                    | CAN firmware error: Logging FIFO is full.                                                                                                             |
| LLCE_ERROR_CODE_RESERVED_7                  | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_CODE_RESERVED_8                  | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_COMMAND_RXPPE_NORESP ← ↩ ONSE    | CAN firmware error: Error reported due to the rx core not responding.                                                                                 |
| LLCE_ERROR_COMMAND_AF_NORESPONSE            | CAN firmware error: Error reported due to frpe core not responding.                                                                                   |
| LLCE_ERROR_COMMAND_DEINIT_NOTSTOP           | CAN firmware error: Error reported because the controller is not stopped.                                                                             |
| LLCE_ERROR_RXTOKENS_UNRETURNED              | CAN firmware error: Error reported because the host didn't read all the RX tokens (indexes in fifos). LLCE waits for indexes to be read and returned. |
| LLCE_ERROR_TXACK_NOT_READ                   | CAN firmware error: Error reported because the host didn't read all the ACKs (indexes in fifos). LLCE waits for indexes to be read.                   |
| LLCE_ERROR_COMMAND_NOTSUPPORTED             | CAN firmware error: Error reported because the requested command is not in the list of supported commands.                                            |
| LLCE_ERROR_COMMAND_NOTVALIDATED             | CAN firmware error: Error reported because command is not validated by the command flow.                                                              |
| LLCE_ERROR_COMMAND_NOTACCEPTED              | CAN firmware error: Error reported because the requested command is correct but it not accepted.                                                      |
| LLCE_ERROR_COMMAND_INVALID_PARAMS           | CAN firmware error: Error reported because the requested command parameters are invalid.                                                              |
| LLCE_ERROR_CODE_RESERVED_9                  | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_FRAME_NOT_DELIVERED              | CAN firmware error: Reports frame accepted, but not delivered to host because of filters misconfiguration.                                            |
| LLCE_ERROR_CODE_RESERVED_10                 | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_FRAME_NOT_DELIVERED_T ← ↩ O_HOST | CAN firmware error: Reports frame accepted, but not delivered to host due to lack of descriptors in software FIFO.                                    |
| LLCE_ERROR_CODE_RESERVED_12                 | CAN firmware error: Reserved for future use.                                                                                                          |
| LLCE_ERROR_FILTERS_FULL                     | CAN firmware error: Error reported because there are no filters available to be set for a specific controller.                                        |
| LLCE_ERROR_FILTERS_NOTEXIST                 | CAN firmware error: The filter pointed by the related address is not used by the related controller.                                                  |

## Module Documentation

## Enumerator

| LLCE_ERROR_FILTERS_MASK_EMPTY              | CAN firmware error: There are no free configuration filters.                                                       |
|--------------------------------------------|--------------------------------------------------------------------------------------------------------------------|
| LLCE_ERROR_FILTERS_RANGE_EMPTY             | CAN firmware error: There are no free configuration filters.                                                       |
| LLCE_ERROR_FILTERS_EM_EMPTY                | CAN firmware error: There are no free exact match filters.                                                         |
| LLCE_ERROR_IDX_NOT_VALID_HOST              | CAN firmware error: The index returned by host is not valid, possibly a duplicate index.                           |
| LLCE_ERROR_IDX_NOT_VALID_LOG               | CAN firmware error: The index returned by logging is not valid, the associated destination didn't match.           |
| LLCE_ERROR_CODE_RESERVED_13                | CAN firmware error: Reserved for future use.                                                                       |
| LLCE_ERROR_CODE_RESERVED_14                | CAN firmware error: Reserved for future use. to HSE because of full FIFO.                                          |
| LLCE_ERROR_TXFRAME_MAC_GEN_ERROR           | CAN firmware error: Tx frame was dropped because MAC generation failed.                                            |
| LLCE_ERROR_RXFRAME_AUTH_ERROR              | CAN firmware error: Rx frame was dropped because it is not authentic.                                              |
| LLCE_ERROR_CODE_RESERVED_16                | CAN firmware error: Reserved for future use. TX core.                                                              |
| LLCE_ERROR_CODE_RESERVED_17                | CAN firmware error: Reserved for future use.                                                                       |
| LLCE_ERROR_RX_SW_FIFO_EMPTY                | CAN firmware error: RX Software FIFO is empty.                                                                     |
| LLCE_ERROR_PFEIF                           | AF error : error communicating with PFE due to PFE internal error.                                                 |
| LLCE_ERROR_HSEIF                           | AF error : error communicating with HSE due to HSE internal error.                                                 |
| LLCE_FW_SUCCESS                            | Generic firmware code: Command was executed successfully by LLCE Firmware.                                         |
| LLCE_FW_ERROR                              | Generic firmware error: During command execution an error condition was detected.                                  |
| LLCE_FW_NOTRUN                             | Generic firmware code: Default value of command return status, set by the host before to send it to LLCE firmware. |
| LLCE_ERROR_INTERNALDESC_NOT_RETU ← ↩ RNED  | CAN firmware error: Internal Descriptor was not returned to the source.                                            |
| LLCE_ERROR_INTERNALDESC_NOT_DELI ← ↩ VERED | CAN firmware error: Internal Descriptor was not delivered to the destination.                                      |
| LLCE_ERROR_INTERNALDESC_NOTAVAIL           | CAN firmware error: Internal Descriptor is not available because the internal LLCE software FIFO is empty.         |
| LLCE_ERROR_INTERNALDESC_FIFO_FULL          | CAN firmware error: Internal Descriptor software FIFO is full.                                                     |
| LLCE_ERROR_MB_NOTAVAIL                     | CAN firmware error: Message Buffer is not available. the internal message buffer software FIFO is empty.           |
| LLCE_ERROR_MB_FIFO_FULL                    | CAN firmware error: Message Buffer software FIFO is full.                                                          |
| LLCE_ERROR_NO_MB_AVAILABLE                 | CAN firmware error: Maximum number of Tx MB per controller for AF is reached.                                      |
| LLCE_ERROR_UNKNOWN_SRC                     | CAN firmware error: The source of the request did not match any of the LLCE cores ids.                             |

Enumerator

| LLCE_ERROR_UNKNOWN_DEST                     | CAN firmware error: Unknown destination of the request : it's neither a CAN or ETHERNET channel, nor the host.   |
|---------------------------------------------|------------------------------------------------------------------------------------------------------------------|
| LLCE_ERROR_UNKNOWN_REQUEST                  | CAN firmware error: Unknown request in intercore communication.                                                  |
| LLCE_ERROR_CONVERSION                       | CAN firmware error: Issued for frames with DLC greater than 8 where destination is not FD .                      |
| LLCE_ERROR_NO_MB_TO_ABORT                   | CAN firmware error: AbortMB request failed due to no pending transmission that can be aborted.                   |
| LLCE_ERROR_INDEX_NOT_RECOVERED              | CAN firmware error: Index not recovered from DTE after Stop or busoff event.                                     |
| LLCE_ERROR_RESET_PENDING                    | CAN firmware error: The controller did not exit from freeze mode within a conifgured timeout.                    |
| LLCE_ERROR_FATAL                            | CAN firmware fatal error: core has entered an error state and is not recoverable.                                |
| LLCE_NOTIF_BUSOFF_DONE                      | CAN firmware notification: BCAN is ready to leave bus-off state after the automatic recovery procedure.          |
| LLCE_ERROR_BCAN_TXWRN                       | CAN firmware error: TXWRN is set when the Tx error counter ECR[TEC] reached 96.                                  |
| LLCE_ERROR_BCAN_RXWRN                       | CAN firmware error: RXWRN is set when the Rx error counter ECR[REC] reached 96.                                  |
| LLCE_ERROR_BCAN_PASSERR                     | CAN firmware error: PASSERR is set when BCAN enters Passive state.                                               |
| LLCE_NOTIF_BCAN_EXIT_PASSIVE_STATE          | CAN firmware notification: BCAN exits Passive state.                                                             |
| LLCE_ERROR_ROUTINGCHANNEL_DISABLED          | CAN firmware notification: There was an attempt to perform routing to a disabled destination.                    |
| LLCE_SHUTDOWN_REQUESTED                     | CAN firmware notification: Shutdown request received from host.                                                  |
| LLCE_SHUTDOWN_ENTERED                       | CAN firmware notification: Core has entered shutdown state.                                                      |
| LLCE_SHUTDOWN_FAILED                        | CAN firmware notification: Core has received an unexpected event during shutdown and is halted but awake.        |
| LLCE_HEADLESS_SUCCESS                       | Generic firmware code: FW successfully booted in headless mode.                                                  |
| LLCE_HEADLESS_INITPLATFORM_ERROR            | Generic firmware error: Invalid InitPlatform section in headless configuration.                                  |
| LLCE_HEADLESS_INITCTRL_ERROR                | Generic firmware error: Invalid controller Init section in headless configuration.                               |
| LLCE_HEADLESS_CREATEDESTINATIONS_ ← ↩ ERROR | Generic firmware error: Invalid advanced destinations section in headless configuration.                         |
| LLCE_HEADLESS_SETFILTER_ERROR               | Generic firmware error: Invalid regular filter section in headless configuration.                                |
| LLCE_HEADLESS_SETADVANCEDFILTER_E ← ↩ RROR  | Generic firmware error: Invalid advanced filter section in headless configuration.                               |
| LLCE_FW_RETURNTYPE_COUNT                    | Number of enum elements. It must be kept as the last member of the list.                                         |

## Module Documentation

Definition at line 131 of file Llce\_InterfaceFwMgr.h.

## 3.2.5 Function Reference

## 3.2.5.1 DisableFifoInterrupts()

```
void DisableFifoInterrupts ( uint8 u8FifoInterface, uint8 u8Hif )
```

## 3.2.5.2 EnableFifoInterrupts()

```
void EnableFifoInterrupts ( uint8 u8FifoInterface, uint8 u8Hif )
```

## 3.3 LLCE LIN firmware interface

## 3.3.1 Detailed Description

## Data Structures

- struct Llce\_Lin\_ChannelConfigType
- LIN channel configuration type structure. More...
- struct Llce\_Lin\_InitCmdType
- LIN initialization command. More...
- struct Llce\_Lin\_GetStatusCmdType

Get LIN status command. More...

- struct Llce\_Lin\_WakeupCmdType

LIN sleep/wakeup management commands. More...

- struct Llce\_Lin\_SendFrameCmdType
- LIN send frame commands. More...
- struct Llce\_Lin\_ErrorIndicationCmdType
- struct Llce\_Lin\_HeaderIndicationCmdType
- union Llce\_Lin\_CommandListType

List of commands used by host. More...

- struct Llce\_Lin\_CommandType

Command used by host. More...

- struct Llce\_Lin\_SharedMemoryType

Shared memory structure. More...

## Macros

```
· #define LLCE_LIN_MAXCTRL_COUNT Maximum number of hardware LIN controllers usable inside LLCE. · #define LLCE_LIN_CONFIG_PAYLOAD_MAX_SIZE
```

## Enum Reference

- enum Llce\_Lin\_NodeType

Type of the LIN node.

- enum Llce\_Lin\_SlaveErrorType

Lin Slave error codes.

- enum Llce\_Lin\_ReturnType

Return status codes reported at the end of each command execution.

- enum Llce\_Lin\_CommandIdType

LIN command IDs used to interface with LLCE.

- enum Llce\_Lin\_FrameCsModelType
- Checksum models for the LIN Frame.
- enum Llce\_Lin\_FrameResponseType

Frame response types.

- enum Llce\_Lin\_StatusType

LIN Frame and Channel states operation.

## 3.3.2 Data Structure Documentation

## 3.3.2.1 struct Llce\_Lin\_ChannelConfigType

LIN channel configuration type structure.

This is the type of the external data structure containing the overall initialization data for one LIN Channel.

Definition at line 299 of file Llce\_InterfaceLinTypes.h.

Data Fields

| uint32            | u32LinBaudRateRegValue          | LIN baud rate value.                                 |
|-------------------|---------------------------------|------------------------------------------------------|
| uint8             | u8LinChannelWakeupSupport       | Wakeup enable.                                       |
| uint8             | u8LinChannelDisableFrameTimeout | Disable frame timeout.                               |
| uint8             | u8LinChannelBrkLengthMaster     | These bits indicate the Break length in Master mode. |
| uint8             | u8LinChannelBrkLengthSlave      | These bits indicate the Break length in Slave mode.  |
| uint8             | u8ResponseTimeout               | Response timeout value LINTOCR[RTO] in bit time.     |
| uint8             | u8HeaderTimeout                 | Header timeout value LINTOCR[HTO].                   |
| Llce_Lin_NodeType | eLinNodeType                    | LIN Node Type.                                       |

## 3.3.2.2 struct Llce\_Lin\_InitCmdType

LIN initialization command.

It is sent by the host to LLCE in order to load and configure all needed parameters for the LIN channels inside LLCE.

Definition at line 325 of file Llce\_InterfaceLinTypes.h.

Data Fields

| Llce_Lin_ChannelConfigType   | CtrlConfig   | INPUT: Configuration options for all hardware LIN controllers.   |
|------------------------------|--------------|------------------------------------------------------------------|

## 3.3.2.3 struct Llce\_Lin\_GetStatusCmdType

Get LIN status command.

It is sent by the host to LLCE in order to get the status of a LIN controller.

Definition at line 338 of file Llce\_InterfaceLinTypes.h.

Data Fields

| uint8               | u8LinChStatus               | OUTPUT: LIN channel state.       |
|---------------------|-----------------------------|----------------------------------|
| uint8               | u8LinChFrameStatus          | OUTPUT: LIN frame state.         |
| uint8               | u8LinChFrameErrorStatus     | OUTPUT: LIN Frame error status.  |
| uint8               | Lin_u8TransmitHeaderCommand | OUTPUT: LIN header command type. |
| Llce_Lin_StatusType | u8ControllerStatus          | OUTPUT: LIN controller status.   |

## 3.3.2.4 struct Llce\_Lin\_WakeupCmdType

LIN sleep/wakeup management commands.

It is sent by the host to LLCE in order to manage sleep/wakeup for a specific channel.

Definition at line 358 of file Llce\_InterfaceLinTypes.h.

Data Fields

| uint8   | u8LinChannelWakeupSupport   | INPUT: Wake-up support enabled.   |
|---------|-----------------------------|-----------------------------------|
| uint8   | u8LinChStatus               | OUTPUT: LIN channel state.        |

## 3.3.2.5 struct Llce\_Lin\_SendFrameCmdType

LIN send frame commands.

It is sent by the host to LLCE in order to send a frame on a specific channel. This Type is used to provide PID, checksum model, data length and SDU pointer from the LIN Driver to the LIN controllers inside LLCE.

Definition at line 374 of file Llce\_InterfaceLinTypes.h.

Data Fields

| uint8                      | Sdu[(8U)]   | Pointer to Sdu.       |
|----------------------------|-------------|-----------------------|
| uint8                      | Pid         | LIN frame identifier. |
| uint8                      | Dl          | Data length.          |
| Llce_Lin_FrameCsModelType  | Cs          | Checksum model type.  |
| Llce_Lin_FrameResponseType | Drc         | Response type.        |

## 3.3.2.6 struct Llce\_Lin\_HeaderIndicationCmdType

Definition at line 388 of file Llce\_InterfaceLinTypes.h.

## Module Documentation

Data Fields

| uint8                      | Pid   | LIN frame identifier.   |
|----------------------------|-------|-------------------------|
| uint8                      | Dl    | Data length.            |
| Llce_Lin_FrameCsModelType  | Cs    | Checksum model type.    |
| Llce_Lin_FrameResponseType | Drc   | Response type.          |

## 3.3.2.7 struct Llce\_Lin\_ErrorIndicationCmdType

Definition at line 400 of file Llce\_InterfaceLinTypes.h.

Data Fields

| Llce_Lin_SlaveErrorType   | eSlaveError Response   |
|---------------------------|------------------------|

## 3.3.2.8 union Llce\_Lin\_CommandListType

List of commands used by host.

It is used in order to use the same memory area for all commands send from host to LLCE.

Definition at line 412 of file Llce\_InterfaceLinTypes.h.

Data Fields

| Llce_Lin_InitCmdType             | Init             | Init Command.                   |
|----------------------------------|------------------|---------------------------------|
| Llce_Lin_GetStatusCmdType        | GetStatus        | Get Status Command.             |
| Llce_Lin_WakeupCmdType           | Wakeup           | Wakeup Command.                 |
| Llce_Lin_SendFrameCmdType        | SendFrame        | Send Frame Command.             |
| Llce_Lin_HeaderIndicationCmdType | HeaderIndication | Header Indication Notification. |
| Llce_Lin_ErrorIndicationCmdType  | ErrorIndication  | Error Notification.             |

## 3.3.2.9 struct Llce\_Lin\_CommandType

Command used by host.

It is used in order to send commands from host to LLCE using shared memory.

Definition at line 433 of file Llce\_InterfaceLinTypes.h.

Data Fields

| union Llce_Lin_CommandListType   | CmdList                                                                                                               | INPUT/OUTPUT: Command parameters.                                                                                     |
|----------------------------------|-----------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
| Llce_Lin_CommandIdType           | eCmdId                                                                                                                | INPUT: Command ID.                                                                                                    |
| 194                              | Llce_Lin_ReturnType eReturnValue OUTPUT: Return status code after command completion. LLCEfirmware NXP Semiconductors | Llce_Lin_ReturnType eReturnValue OUTPUT: Return status code after command completion. LLCEfirmware NXP Semiconductors |

## 3.3.2.10 struct Llce\_Lin\_SharedMemoryType

Shared memory structure.

Structure that encapsulates all the shared memory with LlCE on the LIN side.

Definition at line 448 of file Llce\_InterfaceLinTypes.h.

Data Fields

| Llce_Lin_CommandType   | Lin_aCmd[(4U)]     | Array used to exchange commands between host and firmware for each LIN channel.   |
|------------------------|--------------------|-----------------------------------------------------------------------------------|
| Llce_Lin_CommandType   | Lin_aNotif[(4U)]   | Array used to exchange commands between firmware and host for each LIN channel.   |
| uint8                  | aLinMb[(4U)][(8U)] | Reception message buffers located in the shared memory.                           |

## 3.3.3 Macro Definition Documentation

## 3.3.3.1 LLCE\_LIN\_MAXCTRL\_COUNT

#define LLCE\_LIN\_MAXCTRL\_COUNT

Maximum number of hardware LIN controllers usable inside LLCE.

Maximum buffer size used to store the LIN frame payload

Definition at line 76 of file Llce\_InterfaceLinTypes.h.

## 3.3.3.2 LLCE\_LIN\_CONFIG\_PAYLOAD\_MAX\_SIZE

#define LLCE\_LIN\_CONFIG\_PAYLOAD\_MAX\_SIZE

Definition at line 77 of file Llce\_InterfaceLinTypes.h.

## 3.3.4 Enum Reference

## 3.3.4.1 Llce\_Lin\_NodeType

enum Llce\_Lin\_NodeType

Type of the LIN node.

Type of the LIN node. Master or Slave.

## Module Documentation

Enumerator

| LLCE_LIN_MASTER_NODE   | This is used for Master node.   |
|------------------------|---------------------------------|
| LLCE_LIN_SLAVE_NODE    | This is used for Slave node.    |

Definition at line 88 of file Llce\_InterfaceLinTypes.h.

## 3.3.4.2 Llce\_Lin\_SlaveErrorType

enum Llce\_Lin\_SlaveErrorType

Lin Slave error codes.

Lin Slave error codes.

Enumerator

| LLCE_LIN_ERR_HEADER       | Error in header.                                      |
|---------------------------|-------------------------------------------------------|
| LLCE_LIN_ERR_RESP_STOPBIT | Framing error in response.                            |
| LLCE_LIN_ERR_RESP_CHKSUM  | Checksum error.                                       |
| LLCE_LIN_ERR_RESP_DATABIT | Monitoring error of transmitted data bit in response. |
| LLCE_LIN_ERR_NO_RESP      | No response.                                          |
| LLCE_LIN_ERR_INC_RESP     | Incomplete response.                                  |

Definition at line 101 of file Llce\_InterfaceLinTypes.h.

## 3.3.4.3 Llce\_Lin\_ReturnType

enum Llce\_Lin\_ReturnType

Return status codes reported at the end of each command execution.

Return status codes reported at the end of each command execution. The meaning of these codes are command dependent.

Enumerator

| LLCE_LIN_NOTRUN        | Default state of the command.                                    |
|------------------------|------------------------------------------------------------------|
| LLCE_LIN_SUCCESS       | Command was executed successfully.                               |
| LLCE_LIN_ERROR         | During command execution it was detected an error condition.     |
| LLCE_LIN_ERROR_TIMEOUT | Command was executed, but a timeout was present.                 |
| LLCE_LIN_ERROR_STATE   | Command was executed, but LIN channel is in wrong state.         |
| LLCE_LIN_ERROR_FALSE   | Command was executed, but LIN channel returned a FALSE response. |
| 196                    | LLCEfirmware NXP Semiconductors                                  |

Definition at line 123 of file Llce\_InterfaceLinTypes.h.

## 3.3.4.4 Llce\_Lin\_CommandIdType

enum Llce\_Lin\_CommandIdType

LIN command IDs used to interface with LLCE.

Some of these commands are sent by the host to LLCE module and others are sent by LLCE module to the host.

Enumerator

| LLCE_LIN_CMD_INIT                | Host initializes LIN channels inside LLCE.                            |
|----------------------------------|-----------------------------------------------------------------------|
| LLCE_LIN_CMD_GOTOSLEEP           | Host sets LIN channel to sleep state.                                 |
| LLCE_LIN_CMD_GOTOSLEEPINTERNAL   | Host sets LIN channel to internal sleep state.                        |
| LLCE_LIN_CMD_WAKEUP              | Host sends wakeup command to LIN channel.                             |
| LLCE_LIN_CMD_WAKEUPINTERNAL      | Host sends internal wakeup command to LIN channel.                    |
| LLCE_LIN_CMD_GETSTATUS           | Host requests the status of LIN channel.                              |
| LLCE_LIN_CMD_SENDFRAME           | Host sends a frame to a LIN channel.                                  |
| LLCE_LIN_CMD_WAKEUP_CONFIRMATION | LLCE notifies host about wakeup event.                                |
| LLCE_LIN_CMD_HEADER_INDICATION   | LLCE notifies host about Reception of a header. Only for Slave nodes. |
| LLCE_LIN_CMD_ERROR_INDICATION    | LLCE notifies host about an error occurred. Only for Slave nodes.     |
| LLCE_LIN_CMD_RX_INDICATION       | LLCE notifies host about Reception event. Only for Slave nodes.       |
| LLCE_LIN_CMD_TX_CONFIRMATION     | LLCE notifies host about Transmission Event. Only for Slave nodes.    |
| LLCE_LIN_CMD_ENABLEINTRFORWARD   | Enables interrupt forwarding for all LIN Channels.                    |

Definition at line 151 of file Llce\_InterfaceLinTypes.h.

## 3.3.4.5 Llce\_Lin\_FrameCsModelType

enum Llce\_Lin\_FrameCsModelType

Checksum models for the LIN Frame.

This type is used to specify the Checksum model to be used

Enumerator

| LLCE_LIN_ENHANCED_CS   | Enhanced checksum model.   |
|------------------------|----------------------------|
| LLCE_LIN_CLASSIC_CS    | Classic checksum model.    |

## Module Documentation

Definition at line 198 of file Llce\_InterfaceLinTypes.h.

## 3.3.4.6 Llce\_Lin\_FrameResponseType

enum Llce\_Lin\_FrameResponseType

Frame response types.

This type is used to specify whether the frame processor is required to transmit the response part of the LIN frame.

Enumerator

| LLCE_LIN_FRAMERESPONSE_TX     | Response is generated from this (master) node.                                                                                                  |
|-------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_LIN_FRAMERESPONSE_RX     | Response is generated from a remote slave node.                                                                                                 |
| LLCE_LIN_FRAMERESPONSE_IGNORE | Response is generated from one slave to another slave. For the master the response will be anonymous, it does not have to receive the response. |

Definition at line 212 of file Llce\_InterfaceLinTypes.h.

## 3.3.4.7 Llce\_Lin\_StatusType

enum Llce\_Lin\_StatusType

LIN Frame and Channel states operation.

LIN operation states for a LIN channel or frame

Enumerator

| LLCE_LIN_NOT_OK          | Development or production error occurred.                                                                                         |
|--------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
| LLCE_LIN_TX_OK           | Successful transmission.                                                                                                          |
| LLCE_LIN_TX_BUSY         | Ongoing transmission (Header or Response).                                                                                        |
| LLCE_LIN_TX_HEADER_ERROR | Erroneous header transmission such as: • Mismatch between sent and read back data • Identifier parity error • Physical bus error. |
| LLCE_LIN_TX_ERROR        | Erroneous transmission such as: • Mismatch between sent and read back data • Physical bus error.                                  |

## Enumerator

| LLCE_LIN_RX_OK          | Reception of correct response.                                                                                                                    |
|-------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| LLCE_LIN_RX_BUSY        | Ongoing reception: at least one response byte has been received, but the checksum byte has not been received.                                     |
| LLCE_LIN_RX_ERROR       | Erroneous reception such as: • Framing error • Overrun error • Checksum error • Short response.                                                   |
| LLCE_LIN_RX_NO_RESPONSE | No response byte has been received so far. Frame status is mixed with channel status but it's kept here only because of LIN168.                   |
| LLCE_LIN_OPERATIONAL    | Normal operation: • The related LIN channel is ready to transmit next header • No data from previous frame available (e.g. after initialization). |
| LLCE_LIN_CH_SLEEP       | Sleep mode operation: • In this mode wake-up detection from slave nodes is enabled.                                                               |

Definition at line 232 of file Llce\_InterfaceLinTypes.h.

## 3.4 Platform types used by LLCE firmware

## 3.4.1 Detailed Description

## Types Reference

- typedef unsigned char uint8

Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 8 bit.

- typedef unsigned short uint16

Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 16 bit.

- typedef unsigned long uint32

Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 32 bit.

- typedef unsigned long long uint64

Unsigned 64 bit integer with range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF)64 bit.

- typedef signed char sint8

Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 7 bit + 1 sign bit.

- typedef signed short sint16

Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit.

- typedef signed long sint32

Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit.

- typedef signed long long sint64
- Signed 64 bit integer with range of -9223372036854775808..9223372036854775807 : (0x8000000000000000..0x7F ← ↩ FFFFFFFFFFFFFF ) : 63 bit + 1 sign bit.

## 3.4.2 Types Reference

## 3.4.2.1 uint8

```
typedef unsigned char uint8 Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 8 bit. Definition at line 69 of file PlatformTypes.h.
```

## 3.4.2.2 uint16

```
typedef unsigned short uint16 Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 16 bit. Definition at line 75 of file PlatformTypes.h.
```

## 3.4.2.3 uint32

typedef unsigned long uint32

Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 32 bit.

Definition at line 81 of file PlatformTypes.h.

## 3.4.2.4 uint64

```
typedef unsigned long long uint64
```

Unsigned 64 bit integer with range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF)64 bit.

Definition at line 88 of file PlatformTypes.h.

## 3.4.2.5 sint8

typedef signed char sint8 Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 7 bit + 1 sign bit. Definition at line 94 of file PlatformTypes.h.

## 3.4.2.6 sint16

```
typedef signed short sint16
```

Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit.

Definition at line 100 of file PlatformTypes.h.

## 3.4.2.7 sint32

typedef signed long sint32

Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit. Definition at line 106 of file PlatformTypes.h.

## 3.4.2.8 sint64

```
typedef signed long long sint64
```

Signed 64 bit integer with range of -9223372036854775808..9223372036854775807 : (0x8000000000000000..0x7FF ← ↩ FFFFFFFFFFFFF ) : 63 bit + 1 sign bit.

Definition at line 114 of file PlatformTypes.h.

## 3.5 LLCE headless mode

## 3.5.1 Detailed Description

LLCE Headless mode data structures and defines.

This file contains the LLCE Headless Mode data structures, defines and function declarations to let LLCE boot without a host

## Data Structures

- struct Llce\_Headless\_Descriptor

Headless configuration descriptor It contains the information required for LLCE to recognize headless mode, and to correctly parse the configuration given. More...

## Macros

- #define LLCE\_\_ALIGNED\_\_PACKED

- #define LLCE\_HEADLESSMODE\_MAGICVALUE

## 3.5.2 Data Structure Documentation

## 3.5.2.1 struct Llce\_Headless\_Descriptor

Headless configuration descriptor It contains the information required for LLCE to recognize headless mode, and to correctly parse the configuration given.

Definition at line 67 of file Llce\_Headless.h.

Data Fields

| uint32   | u32MagicNumber                                         | "Magic number" used to detect headless mode                     |
|----------|--------------------------------------------------------|-----------------------------------------------------------------|
| uint8    | u8ChannelCount                                         | Number of channels used.                                        |
| uint8    | u8DestinationCount                                     | Number of routing destinations used. Used for advanced filters. |
| uint16   | au16RegularFilterCount[LLCE_CAN_CONFIG_MAXCTRL_COUNT]  | Number of regular filters used.                                 |
| uint16   | au16AdvancedFilterCount[LLCE_CAN_CONFIG_MAXCTRL_COUNT] | Number of advanced filters used.                                |
| uint8    | padding[2]                                             |                                                                 |

## 3.5.3 Macro Definition Documentation

- 3.5.3.1 LLCE\_\_ALIGNED\_\_PACKED

#define LLCE\_\_ALIGNED\_\_PACKED Definition at line 47 of file Llce\_Headless.h.

## 3.5.3.2 LLCE\_HEADLESSMODE\_MAGICVALUE

#define LLCE\_HEADLESSMODE\_MAGICVALUE Definition at line 53 of file Llce\_Headless.h.

## How to Reach Us:

## Home Page:

nxp.com

## Web Support:

nxp.com/support

Information in this document is provided solely to enable system and software implementers to use NXP products. There are no express or implied copyright licenses granted hereunder to design or fabricate any integrated circuits based on the information in this document. NXP reserves the right to make changes without further notice to any products herein. NXP makes no warranty, representation, or guarantee regarding the suitability of its products for any particular purpose, nor does NXP assume any liability arising out of the application or use of any product or circuit, and specifically disclaims any and all liability, including without limitation consequential or incidental damages. 'Typical' parameters that may be provided in NXP data sheets and/or specifications can and do vary in different applications, and actual performance may vary over time. All operating parameters, including 'typicals,' must be validated for each customer application by customer's technical experts. NXP does not convey any license under its patent rights nor the rights of others. NXP sells products pursuant to standard terms and conditions of sale, which can be found at the following address: nxp.com/SalesTermsandConditions. NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX, EMBRACE, GREENCHIP, HITAG, I2C BUS, ICODE, JCOP, LIFE VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, Freescale, the Freescale logo, AltiVec, C-5, CodeTEST, CodeWarrior, ColdFire, ColdFire+, C-Ware, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, mobileGT, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, Ready Play, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, SMARTMOS, Tower, TurboLink, and UMEMS are trademarks of NXP B.V. All other product or service names are the property of their respective owners. ARM, AMBA, ARM Powered, Artisan, Cortex, Jazelle, Keil, SecurCore, Thumb, TrustZone, and Vision are registered trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. ARM7, ARM9, ARM11, big.LITTLE, CoreLink, CoreSight, DesignStart, Mali, mbed, NEON, POP, Sensinode, Socrates, ULINK and Versatile are trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. All rights reserved. Oracle and Java are registered trademarks of Oracle and/or its affiliates. The Power Architecture and Power.org word marks and the Power and Power.org logos and related marks are trademarks and service marks licensed by Power.org. © 2025 NXP B.V.

<!-- image -->