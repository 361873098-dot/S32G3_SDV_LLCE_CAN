## S32G2 - LOW LATENCY COMMUNICATION ENGINE: LLCE

VCNS SOLUTIONS &amp; APPLICATIONS

APRIL 2021

<!-- image -->

<!-- image -->

<!-- image -->

## OBJECTIVE

- Introduction to Low Latency Communication Engine
- LLCE SW product
- LLCE Integration with AUTOSAR ®
- LLCE Features in Enablement Release
- LLCE Host Interface
- LLCE Enablement Sample Application

<!-- image -->

## Introduction To Low Latency Communication Engine

<!-- image -->

PUBLIC

3

## LLCE - LOW LATENCY COMMUNICATION ENGINE

LLCE is a communication engine, a combination of cores, memory, hardware acceleration IP blocks and firmware to provide acceleration for standard automotive communication interfaces.

Fully programmable engine with firmware supporting:

- Offload of host CPU for all communication interface related tasks
- Reduced interrupt load on the host core
- Advanced software filtering
- Direct data transfer to/from HSE for security related tasks
- Flexible control and data interface exposed to the Host cores
- Efficient support of security over network protocols and global time synchronisation
- Hardware acceleration for filtering and prioritization of messages

Integrated into AUTOSAR ® Communication stack via AUTOSAR MCAL drivers (CAN, FlexRay™, LIN)

<!-- image -->

<!-- image -->

## LOW LATENCY COMMUNICATIONS ENGINE HW ARCHITECTURE

## LLCE features

- -4x Arm ® Cortex ® M0+ cores
- Each with dedicated instruction/data RAM
- 16x BCAN (CAN 2.0 and CAN-FD)
- -4x LIN
- -1x FlexRay
- -4x SPI hardware interfaces enabled by LLCE firmware
- -Global Time base
- -Shared memory 2x 160 kB
- -FIFOs to manage pointers for message buffers
- -Comms HW accelerators (RX-LUT, TX-LUT)
- -Watchdogs, CRC, Core2core, Semaphore

## LLCE connectivity

- -Host cores (M7 and A53)
- -Ethernet
- -HSE (Security)

<!-- image -->

<!-- image -->

## KEY ADVANTAGE OF LLCE VS TRADITIONAL APPROACH

## Flexibility to Customer Application

- Flexible host interface (F/W based)
- -Can be customised to specific customer use case

## Host CPU Offload possibilities

- Function offload from main core
- -Advanced filtering (Bitwise, range, ..)
- E.g., Removes Host Look up (100+ cycles)
- -Low latency frame gateway functions
- E.g., Mirroring functions, Protocol conversion
- Reduced interrupt loading on the host core

## Host interface

- Standard interface for CAN, FlexRay™, LIN
- Back-to-back messages supported
- Reduction in host buffer management
- -Fire and forget interface
- Dynamic 'MB'
- -Only limited by data RAM size

## Enhanced Feature Support

- Security offload
- Global timestamping

<!-- image -->

## HOST OFFLOADING BY LLCE INTERNAL ROUTING

<!-- image -->

SW-C

RTE

Signals

Diagnostic

Comm.

Manager

AUTOSAR

COM

I-PDU

I-PDU

PDU Router

I-PDU

CAN Tp

N-PDU

CAN Interface

L-PDU

IPDU

Multiplexer

I-PDU

Routing

Table

I-PDU

Routing

I-PDU

J1939Tp

N-PDU

Communication

HW Abstraction

Communication

CAN Driver

Drivers

Can/Can-FD Frame

LLCE (S32G)

Table

BCAN

BCAN

0

1

T4

Routing without  host

System

Services

Debugging

I-PDU

Routing latency (using host) : 2xT1 + 2xT2 + 2xT3

Routing latency (without host) : T4

Routing Latency reduces by using LLCE internal routing as it saves time in high level SW stacks, interrupts overheads, etc.

<!-- image -->

## LLCE SW Product

<!-- image -->

PUBLIC

8

## LLCE PRODUCT

## · LLCE enablement

- CAN, LIN, FlexRay communication controller (used by CAN/LIN/FlexRay AUTOSAR drivers on host)
- Firmware binaries
- Timestamping
- CAN, LIN loopback sample application
- CAN2CAN, CAN2ETH, ETH2CAN internal routing + a CDD on the host to configure/monitor the routes
- Multi-host sample application

<!-- image -->

## LLCE RELEASE PACKAGE CONTENTS

- Available on Flexera
- Enablement (binary) release
- AUTOSAR drivers for CAN, LIN, FlexRay
- Firmware binaries for the 4 cores (DTE, PPE\_RX, PPE\_TX, FRPE)
- LLCE host interface header files + data structures
- Sample applications (CAN, LIN loopback, CAN2CAN internal routing, multihost, CAN2ETH, ETH2CAN)
- LLCE firmware user guide
- Getting Started Guide
- Release notes

<!-- image -->

<!-- image -->

## FEATURES IN LLCE ENABLEMENT RELEASE

- ❖ CAN LOOPBACK
- Simple sending and receiving frames from one channel to the other connected through wire.
- ❖ LIN LOOPBACK
- Creates a master-slave communication between 2 nodes.
- ❖ CAN Multihost
- Deliver received frames to multiple hosts
- ❖ CAN to CAN routing
- Receive a frame from a BCAN and send it to one or multiple configured BCAN
- Receive a frame from a BCAN, change the ID and send it to one or multiple configured BCAN.
- Convert a received standard CAN frame to CAN FD frame
- Convert a CAN FD frame to CAN frame if payload length is less than 8 bytes.
- ❖ CAN to Ethernet routing
- Packing selected CAN frames into an IEEE1722 AVTP protocol and sending over PFE on the Ethernet network
- ❖ Ethernet to CAN routing
- Sending an IEEE1722 compliant frame to the specified RGMII port.
- Valid CAN frames contained in the Ethernet frame will be unpacked and sent to the respective channels.

<!-- image -->

## LLCE Integration with AUTOSAR

<!-- image -->

PUBLIC

1 3

<!-- image -->

## NXP Basic AUTOSAR Software

<!-- image -->

- NXP Standard Products - MCAL (source code), OS (source code) and Configuration Tool (executable) for MCAL and OS
- Partner Products (Elektrobit, Vector, KPIT, etc.) - The rest of AUTOSAR basic software as needed &amp; Integration Services (NXP IP + Partner IP + Customer IP)
- Complex Drivers - custom software offered by NXP Consulting &amp; Professional Engineering Services

<!-- image -->

<!-- image -->

## S32G MCAL AND LLCE DRIVERS

<!-- image -->

## I N T E GRATING LLCE WITH FLEXCAN

- Autosar specification supports multiple communication drivers
- CAN\_LLCE and FlexCAN drivers can run in parallel
- Changes are needed in CAN Interface
- Partners can easily integrate LLCE CAN/LIN/FR standard functionalities in Autosar Stack
- Usage of advanced features of LLCE requires moving features from PDU Router and other components to LLCE firmware

<!-- image -->

PUBLIC

1 6

<!-- image -->

## LLCE FEATURES IN ENABLEMENT RELEASE

<!-- image -->

PUBLIC

1 7

## LLCE CAN LOOPBACK

<!-- image -->

<!-- image -->

## LLCE LIN LOOPBACK

<!-- image -->

<!-- image -->

## LLCE CAN MULTIHOST

<!-- image -->

<!-- image -->

## CAN-CAN ROUTING W/O ID REMAPPING

<!-- image -->

## CAN-CAN ROUTING WITH ID REMAPPING

<!-- image -->

## CAN-ETH ROUTING

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LLCE HOST INTERFACE

<!-- image -->

PUBLIC

2 5

## LLCE FIRMWARE ARCHITECTURE - HIGH LEVEL VIEW

<!-- image -->

- Host side applications interacts with LLCE firmware by using 3 different/independent interfaces for each type of buses: CAN, LIN and FlexRay
- The host interface for each bus is composed from independent HW elements.
- All the source files servicing each bus behavior are compiled together and the execution is distributed between multiple internal cores.

<!-- image -->

## LLCE CAN FIRMWARE ARCHITECTURE

<!-- image -->

- LLCE CAN firmware is distributed and runs on all 4 internal cores
- Interactions between host applications and CAN firmware is done by using multiple custom interfaces composed from different shared memory areas and HW FIFOs
- Hardware FIFOs are used also as inter-core communication mechanism inside LLCE
- DTE(Data Transfer Engine) core run fully in polling mode in order to get all frames from all BCANs

<!-- image -->

## LLCE LIN FIRMWARE ARCHITECTURE

<!-- image -->

- LLCE LIN firmware is running fully on the Rx PPE core.
- LIN firmware enables LIN node to act either as master or slave on the bus
- LIN firmware reacts only by responding to the host commands
- Host driver writes into shared memory the command parameters and notify LIN firmware by raising a flag inside Core2Core module

<!-- image -->

## LLCE FLEXRAY FIRMWARE ARCHITECTURE

<!-- image -->

<!-- image -->

## HW ACCELERATOR: TRANSMIT LOOKUP TABLE (TX LUT)

- LLCE has a dedicated hardware module to make decisions based on CAN ID for Transmitting CAN channel
- One TX-LUT per CAN channel =&gt; 16x TX-LUT
- Searches for highest and lowest priority message

<!-- image -->

<!-- image -->

## HW ACCELERATOR: RECEIVE LOOKUP ACCELERATOR (RX-LUT)

- LLCE has a dedicated hardware module to make decisions based on receiving CAN channel and CAN ID
- One RX-LUT for all 16 CAN channels
- LLCE supports 1024 filter entries:
- 512 'exact match' type filter
- 512 'masked or range' type filter

<!-- image -->

<!-- image -->

## HOST - LLCE FIFO

- Host interacts with LLCE using below HW FIFOs
- -RX-OUT FIFO
- -RX-IN FIFO
- -BLR-OUT FIFO
- -BLR-IN FIFO
- -TX-ACK FIFO
- LLCE provides 16 Tx, 22 Rx and 22 Tx Ack interfaces - 16 interrupts and 6 polling classes
- Interfaces from 0-15 are configured to work in interrupt mode and 16-21 in polling mode
- Tx Ack and Rx interface can be configured in tresos in interrupt, polling or mixed mode

<!-- image -->

Selecting Processing Type as mixed, gives the flexibility to configure each HW object independently in interrupt or polling mode.

<!-- image -->

| Rx Interface   | Rx Interface    |
|----------------|-----------------|
| RXOUT FIFO     | RXIN FIFO (2-7) |
| (0-15)         |                 |
| 16x INTR       | 6x POLL         |

<!-- image -->

<!-- image -->

## LLCE CAN INTERFACE - CONFIGURATION FLOWS

<!-- image -->

1. Write command ID and command parameters into the shared memory.
2. Write the channel ID into the CMD FIFO.
3. Check in polling way if the NOT\_EMPTY interrupt flag of the CMD FIFO is cleared by the firmware in order to detect the completion of the command processing by the LLCE firmware.
4. Read the command completion status from the same shared memory location.

<!-- image -->

## LLCE CAN INTERFACE - TRANSMISSION FLOW

<!-- image -->

1. Read an index to an empty transmit descriptor from channel's BLROUT FIFO. This operation can be done in poling or in interrupt mode.
2. Write the fields of transmission descriptor and extract the index to the message buffer table.
3. Write the CAN frame content into the message buffer.
4. Write the index of the transmission descriptor into the channel's BLRIN FIFO in order to trigger the transmission inside LLCE.
5. Read an index into acknowledge information table from the channel's TXACK FIFO. This operation can be done either in polling or interrupt mode.
6. Read the content of the referred entry from the acknowledge information table and process it.

<!-- image -->

## LLCE CAN INTERFACE - RECEPTION FLOW

<!-- image -->

1. Read an index to a full receive descriptor from channel's RXOUT FIFO. This operation can be done in poling or in interrupt mode.
2. Read reception descriptor content and extract from it the index into the CAN message buffer table.
3. Read the content of the full reception message buffer and process it.
4. Write the index of the receive descriptor to the RXIN FIFO in order to send it back to the LLCE to be reused.

<!-- image -->

## LLCE CAN INTERFACE - NOTIFICATION FLOW: INTERRUPT MODE

<!-- image -->

1. For notifications serviced by interrupt read an entry/index if available from the NOTIF\_INTR FIFO.
2. Use the previous read index in order to access the notification parameters from the corresponding table and process the notification event.
3. Clear the interrupt status flag NOT\_EMPTY of the NOTIF\_INTR FIFO.

## Notification examples:

LLCE\_ERROR\_FIFO\_FULL

LLCE\_ERROR\_FIFO\_EMPTY

LLCE\_ERROR\_MB\_NOTAVAILABLE

LLCE\_ERROR\_CAN\_PROTOCOL

LLCE\_ERROR\_HOH\_NOTAVAILABLE

LLCE\_ERROR\_TXLUT\_FULL

LLCE\_ERROR\_CMD\_PROCESSING

LLCE\_ERROR\_HARDWARE\_COMMAND

LLCE\_ERROR\_HARDWARE\_RXLUT

LLCE\_ERROR\_HARDWARE\_TXLUT

LLCE\_ERROR\_HARDWARE\_BCAN

LLCE\_ERROR\_HARDWARE\_BUSOFF

LLCE\_ERROR\_CTRL\_NOT\_READY

LLCE\_ERROR\_BUSOFF

LLCE\_ERROR\_FIFO\_LOG\_FULL

LLCE\_ERROR\_CAN2CAN

<!-- image -->

## LLCE Enablement Sample Applications

<!-- image -->

PUBLIC

3 7

## LLCE SAMPLE APPLICATIONS

Several demos are provided as part of LLCE SW to demonstrate the LLCE functionality and to provide various examples of LLCE usage. There is a README in the installation folder describing each demo. The source code also contains useful comments. For more details refer to LLCE\_getting\_started\_guide available with the release.

1. Enablement LLCE package:
- CAN Loopback
- LIN Loopback
- CAN2CAN routing
- CAN Multihost
- Packing selected CAN frames into an ethernet frame and sending over PFE
- Sending valid Can frames contained in the Ethernet frame

<!-- image -->

## CAN2CAN INTERNAL ROUTING EXAMPLE

<!-- image -->

<!-- image -->

## PREREQUISITES

- Install Elektrobit tresos 27
- Download the LLCE and RTD release.
- Copy the plugins from LLCE and RTD release in tresos/plugins directory

<!-- image -->

## CAN2CAN TRESOS CONFIGURATIONS

1. Open EB tresos workspace, Go to File → Import
2. Select General → Existing Projects into Workspace and click Next.
3. Browse to the project and click on Finish.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## CAN2CAN TRESOS CONFIGURATION

4. In Project Explorer, right click on test\_llce(CORTEXM,S32GXXM7) and click on Load Configuration.
5. Double click on Can\_43\_LLCE to open CAN driver configurations and LLCE\_Af to open configuration of advance features.

<!-- image -->

<!-- image -->

<!-- image -->

## CAN2CAN TRESOS CONFIGURATION - CAN CONTROLLER CONFIGURATION

<!-- image -->

## CAN2CAN TRESOS CONFIGURATION - CAN HARDWARE OBJECT CONFIGURATION

<!-- image -->

<!-- image -->

## CAN2CAN TRESOS CONFIGURATION - CAN HARDWARE OBJECT CONFIGURATION

<!-- image -->

Can HW Filter mask

<!-- image -->

Reference to advance features

<!-- image -->

## CAN2CAN TRESOS CONFIGURATION - POLLING CLASSES

<!-- image -->

<!-- image -->

## CAN2CAN TRESOS CONFIGURATION - LLCE\_AF CONFIGURATION

<!-- image -->

## CAN2CAN TRESOS CONFIGURATION - LLCE\_AF CONFIGURATION

<!-- image -->

## CAN2CAN TRESOS CONFIGURATION - PROJECT GENERATION

After doing all the configurations, right click on project and click on Generate Project

<!-- image -->

<!-- image -->

## HOW TO BUILD SAMPLE APPLICATION

1. Open config.mk in '..\S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application' directory and make sure the paths to complier, plugin directory, llce bin and interface folder and tresos project are correct.
2. Select the toolchain(gcc or ghs) and the target board(S32G\_EVB or S32G\_RDB)
3. 3.
4. Open Cygwin or PowerShell and go to the path '..\S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application'
4. Run 'make target' (for can-can routing application, run 'make can\_routing'.
5. The generated elf 'can\_routing.elf' will be available in ./build folder

nxf42671@NXL45878/cygdrive/C/NXP/LLCE\_Software/S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0/S3 2G2XX\_LLCE\_GATEwAY4\_4\_1\_0\_0\_Sample\_App1ication make can\_routing

<!-- image -->

ZP

```
#Select the compiler (ghs/gcc -lowercase)and edit the path to one of them :MANDAroRY TOOLCHAIN ?=gCC #Location of GHS compiler (when building with GHS). Tested with v. 201914 GHS_1ocation = C:/ghs/comp_202014 Location of GCC compiler (when building with GCC). Tested with arm-none-eabi-gcc.exe (BLD = 1649) 9.2.0 20190812 (build.sh rev=gaf57174 s=F920) GCC_location=C:/gcc/gcc-9.2-arm32-eabi/bin #Select the target board (S32G_EVB/ S32G_RDB).Don't leave any empty space after the selection.:MANDATORY TARGET_BOARD ?= S32G_EVB #Edit the path to llce_bin (containing firmware binary as .c sources) and llce_interface :MANDAToRY LLCE_BIN_LoCATION = ../../1lce_bin/s32g2xx/bin/ghs/advanced LLCE_INTERFACE_LOCATION =../../1lce_interface Edit the path to tresos plugins (Mcal + Llce):MANDATORY PLUGINS_DIR = C:/EB/treSos27/plugins Path to the plugins and configuration files for the can2can routing with HSE authentication CAN2CAN_HSE_GENERATE_DIR =./sample_app_can_llce_af/tresos/Tresos_CAN2CAN_HSE_Project/output/generated # Path to the plugins and configuration files for the can2can routing CAN2CAN_GENERATE_DIR = ./sample_app_can_llce/tresos/Tresos_CAN2CAN_Project/output/generated Path to the plugins and configuration files for the simple loopback CAN_LB_GENERATE_DIR =./sample_app_can_1lce/tresos/Tresos_LoopBack_Project/output/generated # Path to the plugins and configuration files for the simple loopback Path to the configuration files for multihost and logging demos MULTIHosT_GENERATE_DIR1 = ./sample_app_can_llce/tresos/Tresos_Multihost_Project/Multihost_Cfgl/output/generated MULTIHosT_GENERATE_DIR2 =./sample_app_can_1lce/tresos/Tresos_Multihost_Project/Multihost_Cfg2/output/generated # Temporary folder to hold e.g. object files during compilation TMP_location = build ###Plugins version ### RTD 1.0.0 AR_PKG_RTD_NAME = TS_T40D11M10I0R0 #LLCE 1.0.0 AR PKG LLCE NAME = TS T40D11M10I0R0
```

## HOW TO RUN THE APPLICATION

1. Open TRACE32, go to File -&gt; Edit Script and select S32G\_app\_load.cmm script from tools/cmm\_scripts folder.
2. Edit the script for desired sample application and click Do.
3. The elf will run automatically and will output the number of frame sent and received.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->