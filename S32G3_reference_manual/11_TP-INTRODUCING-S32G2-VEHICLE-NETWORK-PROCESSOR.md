## VEHICLE NETWORK PROCESSOR

## S32G2 GENERAL OVERVIEW

APRIL 2021 VCNS SOLUTIONS &amp; APPLICATIONS

<!-- image -->

<!-- image -->

<!-- image -->

## OBJECTIVE

- Introduction to Vehicle Networks
- S32G2 Vehicle Network Processor
- S32G2 Software Overview
- S32G2 Tools Overview
- NXP S32G2 Boards Overview

<!-- image -->

<!-- image -->

## Introduction to Vehicle Networks

<!-- image -->

## GATEWAY RISE AND EVOLUTION

<!-- image -->

- No or limited connectivity
- No or limited security
- Basic routing
- Limited bandwidth / scalability (kilobit / Megabit interfaces)
- Up to ASIL B with fail safe

## Connectivity

## Security

## Processing

## Networking

Functional Safety

- High-speed wireless interfaces
- High security, isolation, public key crypto, contextual firewall, intrusion detection
- Advanced routing, vehicle OTA, analytics, ECU consolidation, services
- High-bandwidth, scalable architectures (Gigabit interfaces)
- Up to ASIL D with fail operational

<!-- image -->

## CAN CENTRAL GATEWAY ARCHITECTURE

- Legacy Automotive Networks
- Typically 3-8 CAN networks
- Typically 1-2 FlexRay networks
- Increased bandwidth
- But small compared to consumer / networking world
- Proprietary protocols for higher bandwidth (e.g., MOST)
- Physical Isolation
- Functional domains
- Safety / Non-safety
- Gateway role
- Firewall internal traffic
- Protocol translation

<!-- image -->

<!-- image -->

<!-- image -->

## HYBRID ETHERNET ARCHITECTURE

- Legacy + Ethernet Networks
- CAN, FlexRay and Ethernet
- High-bandwidth Data
- 100 Mbit → 1 Gbit Ethernet
- ADAS and Infotainment drive higher data rates
- Improved ECU program time in factory
- Gateway role
- Firewall internal and external
- Efficient protocol translation
- ECU consolidation
- New apps and services

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## CENTRAL COMPUTE ARCHITECTURE

- Central Compute + I/O Gateways
- No functional domains
- Strategy for vehicle fully owned by Central Compute
- I/O Gateways connect Edge Nodes to Central Compute
- Distributed processing
- Optimize network utilization
- Benefits:
- Network architecture optimised to vehicle topology

## 'Edge Nodes' e.g., Radar ECU, Powertrain ECU

<!-- image -->

- Less wires (less weight, power, cost)

High Speed Ethernet Network (Mesh/Ring)

Optimised to vehicle topology for Reduced Wiring

<!-- image -->

## KEY GATEWAY USE CASES

## · Protocol Translation

- Protocol-to-Protocol
- Data-to-Information

## · Network Security

- High-performance Contextual Firewall
- Intrusion Detection and Prevention (CAN and Ethernet)
- Secure Messages
- Network Key Management
- OTA Updates Management
- Remote upgrades (recalls/security…)
- Diagnostics / Prognostic Health Management
- Remote monitoring and condition-based maintenance
- Apps Processing
- ECU consolidation
- Analytics (edge and cloud)
- Centralized functions (vehicle identity, power strategy…)
- Agile deployment of future functionality

<!-- image -->

<!-- image -->

## S32G2 Vehicle Network Processor

<!-- image -->

## COMMON CHASSIS: COMMON HW AND SW PLATFORM

<!-- image -->

Arm, Cortex are trademarks or registered trademarks of Arm Limited (or its subsidiaries) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved.

## Customer Benefits

- Leverage SW tools and development investment across functional domains
- Focus on differentiation rather than enabling silicon

## One Common Architecture Base

- Fixed set of Cores and Interconnect
- Consistent Safety Concept and Security
- Identical Base Peripheral Set
- Consistent Boot and Debug

## Application-specific Support

- Cortex-A/R/M Processors
- Accelerators
- Analog Subsystems
- Peripherals and Memory Interfaces

<!-- image -->

## S32G274A: ASIL D VEHICLE NETWORK PROCESSOR

<!-- image -->

## Specifications:

- Cores: Three Arm® Cortex®-M7 cores @ 400MHz (core lockstep for ASIL D) Four Arm® Cortex®-A53 cores @ 1GHz MHz (cluster lockstep for ASIL D)
- Memory: 8 MB SRAM with ECC, external flash (NOR, eMMC/SDXC NAND)
- Temp Range: Ta = -40 to 105  C (Tj=125° C)
- Power Supplies: 0.8 V, 1.1/1.2V, 1.8 V, 3.3 V , companion PMIC (NXP VR5510)
- Packaging: 19x19 mm, .8 mm pitch, 525 FC-PBGA (23x23 balls, corner ball depopulated)

## Key Features:

- Hybrid SoC: Low-latency MCU + High-bandwidth MPU for real time (AUTOSAR) and rich OS (Linux/QNX/Integrity)
- PCIe interfaces : Gen3 PCIe expansion to performance SoCs
- Network Accelerators: PFE (Ethernet) + LLCE (CAN, FR, LIN, SPI)
- Functional Safety: Developed to ISO 26262 with target ASIL B/D
- Security: HSE with AES, RSA, ECC, RNG, and hash acceleration, XRDC, Lifecycle
- OS Support: AUTOSAR®, Linux®, QNX, Green Hills INTEGRITY (planned)

<!-- image -->

## S32G274A: ASIL D VEHICLE NETWORK PROCESSOR

<!-- image -->

## MEMORY OVERVIEW

<!-- image -->

- SRAM
- -8 MB on S32G274A/S32G254A/S32G234M
- -6 MB on S32G233A
- Standby SRAM
- -32 KB size, separate from the system SRAM
- -Powered by the STANDBY power domain
- -Supports ECC protection
- DDR
- -Support for LPDDR4, DDR3L
- QuadSPI
- -Supports external NOR flash with SDR/DDR modes (ref. RM for details)
- Ultra-Secured Digital Host Controller (uSDHC)
- -SD Host Controller Standard Specification version 2.0/3.0
- -MMC System Specification version 4.2/4.3/4.4/4.41/4.5/5.0/5.1
- -SD Memory Card Specification version 3.0 (ref. RM for details)

Note: S32G2 has no internal flash

<!-- image -->

## LOW LATENCY COMMUNICATIONS ENGINE (LLCE)

## LLCE features

- -4x Arm® Cortex® M0+ cores
- Each with dedicated instruction/data RAM
- 16x CAN (CAN 2.0 and CAN-FD)
- -4x LIN
- -1x FlexRay
- -4x SPI
- -Global time base
- -Shared memory 2x 160 kB
- -FIFOs to manage pointers for message buffers
- -Comms HW accelerators (RX-LUT, TX-LUT)
- -Watchdogs, CRC, Core2core, Semaphore

## LLCE connectivity

- -Host cores (M7 and A53)
- -Ethernet
- -HSE (Security)

LLCE is the communication engine, a combination of cores, memory, hardware acceleration IP blocks and firmware to provide acceleration for standard automotive communication interfaces.

<!-- image -->

<!-- image -->

## LLCE - LOW LATENCY COMMUNICATION ENGINE

Fully programmable engine with firmware supporting:

- Offload of host CPU for all communication interface related tasks
- -Reduced interrupt load on the host core
- -Advanced software filtering
- Direct data transfer to/from HSE for security related tasks
- Flexible control and data interface exposed to the Host cores
- Efficient support of security over network protocols and global time synchronisation
- Hardware acceleration for filtering and prioritization of messages

Integrated into AUTOSAR® Communication stack via AUTOSAR MCAL drivers (CAN, FlexRay™, LIN)

<!-- image -->

<!-- image -->

## STANDARD LLCE SOFTWARE FEATURES

## ❖ CAN LOOPBACK

- Simple sending and receiving frames from one channel to the other connected through wire.

## ❖ LIN LOOPBACK

- Creates a master-slave communication between 2 nodes.

## ❖ CAN Multihost

- Deliver received frames to multiple hosts
- ❖ CAN to CAN routing
- Receive a frame from a BCAN and send it to one or multiple configured BCAN
- Receive a frame from a BCAN, change the ID and send it to one or multiple configured BCAN.
- Convert a received standard CAN frame to CAN FD frame
- Convert a CAN FD frame to CAN frame if payload length is less than 8 bytes.

## ❖ CAN to Ethernet routing

- Packing selected CAN frames into an IEEE ® 1722 AVTP protocol and sending over PFE on the Ethernet network

## ❖

- Ethernet to CAN routing
- Sending an IEEE1722 compliant frame to the specified RGMII port.
- Valid CAN frames contained in the Ethernet frame will be unpacked and sent to the respective channels.

<!-- image -->

## PACKET FORWARDING ENGINE (PFE)- ARCHITECTURE

PFE offloads the processing of Ethernet packets from the host cores, yielding higher performance and lower power than pure software processing can achieve

- Architecture based on Processing Engines (PEs) supported by pure HW components
- PEs are dedicated cores running firmware code from fast internal instruction memory
- 3 x EMAC - Ethernet MAC
- -Checksum verification/generation (L2 CRC, IPv4, TCP, UDP and ICMP, MAC address filter, VLAN filter, 1588 timestamping
- HIF - Host Interface
- -4 x HIF do full data copy, 1 x HIF with no copy
- Can offload security flows via HSE
- QoS (Queues, Tail Drop, Schedulers, Shapers)

<!-- image -->

<!-- image -->

## PACKET FORWARDING ENGINE (PFE) - FAST VS SLOW PATH

## Fast Path

- -Accelerate majority of routed packets, with minimal CPU load

## Example:

1. Application uses FCI to configure a routing table (SRC/DST IP, SRC/DST port, protocol) in HW
2. Frame is received on an ingress port
3. PFE engines search routing table for match
4. In case of a match, frame is modified and fast-forwarded to the destination interface
5. In case of no match, frame is sent to host

## Slow Path

- -Involves Host CPU
- -Control Path &amp; Complex Packet Processing (e.g., DPI)

<!-- image -->

<!-- image -->

## PACKET FORWARDING ENGINE (PFE) FEATURES

- Datapath Endpoint
- -Traffic distribution from/to host system with HW pre-classification of RX packets.
- Multi-instance Datapath Endpoint
- -Ability to run multiple driver instances within separate environments (CPUs/VMs) sharing the PFE-provided connectivity.
- IPv4/IPv6 Router
- -L3/L4 traffic router within fast-path domain (TCP/UDP).
- IPv4/IPv6 Multicast Router
- -L3/L4 traffic router with multicast support (TCP/UDP).
- VLAN Aware Switch
- -Ethernet switch within fast-path domain.
- Flexible Router
- -Fast-path traffic router allowing an arbitrary combination of packet properties including packet payload values to be used to make routing decisions.
- Ingress QoS Management API
- -Configuration of ingress traffic prioritization and congestion prevention. Access to statistics.
- Egress QoS Management API
- -Configuration of egress traffic aggregation and prioritization.
- IPsec Offload
- -Transparent ESP Tunnel mode with HSE assistance.
- IDPS integration
- Traffic/Runtime Statistics
- MDIO support
- IEEE1588 Timestamping with API
- Runtime Errors Reporting:
- -Firmware State Monitoring
- -HW Watchdogs Monitoring
- -Bus Parity Errors Monitoring
- -Error Interrupts Monitoring
- -Safety Events Reporting and Handling
- Firmware plugins in form of third-party libraries
- HIF Programmer's Guide
- FCI Reference Manual

<!-- image -->

## HARDWARE SECURITY ENGINE (HSE)

The Hardware Security Engine (HSE\_H) subsystem implements the security functions for the device. It provides cryptographic services to host CPUs and the network accelerators. It establishes the root of trust on the device during the boot process.

## HSE Features:

Physically-isolated Security Domain

- Exclusive system resources
- Connects to the host via a dedicated interface

Executes relevant security functions having stringent security and/or authenticity requirements

Isolates security-sensitive information (e.g., secret keys) from the application

Offloads the application from processing cryptographic operations

Provides acceleration for cryptographic operations with dedicated coprocessors

Latest Symmetric &amp; Asymmetric (PK) protocols accelerated in hardware

## Reference Documentation:

HSE Firmware Reference Manual - Contains architecture details of security firmware

HSE Service Interface Reference Manual - Security firmware API reference

<!-- image -->

<!-- image -->

## I N T E GRATING NXP'S HSE IN STANDARD SECURITY STACK

<!-- image -->

<!-- image -->

## PERIPHERALS OVERVIEW*

## USB x 1

- -2.0 with OTG support, ULPI interface to external PHY.

## FlexCAN (with FD) x 4

- -From Common Chassis, completely independent from LLCE

## FlexRay x 1

- -2 Channels, from Common Chassis, completely independent from LLCE

## LINFlex x 3

- -Supports LIN Slave mode &amp; UART mode, from Common Chassis, completely independent from LLCE

## I2C x 5

- -1 required for PMIC

## SAR ADC x 2

- -Support 6 channels each

## Timers

- PIT x 2, SWT x 7 (one per core), STM x 8 (one per core + 1) , FlexTimer Module (2 instances, 6 channels each)

## DSPI x 6

*Refer S32G2 RM for details

<!-- image -->

## S32G2 FAMILY - VARIANTS

- Package (all variants): 525 FC-BGA 19x19 mm, 0.8mm pitch
- The following table compares the features of these S32G2 family variants.

|                          | S32G234M         | S32G233A         | S32G254A         | S32G274A         |
|--------------------------|------------------|------------------|------------------|------------------|
| MCU Cores                | 3                | 1                | 3                | 3                |
| MPUCores                 | -                | 2                | 2                | 4                |
| SystemRAM                | 8 MB/ -          | 6 MB/ -          | 8 MB/ -          | 8 MB/ -          |
| PCIe                     | 1x2 Lane PCIe2.0 | 2x2 Lane PCIe3.0 | 2x2 Lane PCIe3.0 | 2x2 Lane PCIe3.0 |
| USB2.0 OTG               | -                | 1                | 1                | 1                |
| Security                 | HSE              | HSE              | HSE              | HSE              |
| Ethernet* (PFE + std)    | 3 + 1            | 3 + 1            | 3 + 1            | 3 + 1            |
| CAN* (LLCE + std)        | 16 + 4           | 16 + 4           | 16 + 4           | 16 + 4           |
| LIN* (LLCE + std)        | 4 + 3            | 4 + 3            | 4 + 3            | 4 + 3            |
| FlexRay ™ * (LLCE + std) | 1 + 1            | 1 + 1            | 1 + 1            | 1 + 1            |
| SPI* (LLCE + std)        | 4 + 6            | 4 + 6            | 4 + 6            | 4 + 6            |
| PFE / LLCE accelerator   | available        | available        | available        | available        |

<!-- image -->

## NXP MPC5748G → S32G KEY HIGHLIGHTS

| MPC5748G                                                              | S32G274A                                                                                           |
|-----------------------------------------------------------------------|----------------------------------------------------------------------------------------------------|
| Microcontroller                                                       | Microcontroller + Microprocessor                                                                   |
| Three processor cores: (2) PowerPC z4 @160 MHz (1) PowerPC z2 @80 MHz | Seven processor cores: (3) Arm® Cortex®-M7 lockstep @400 MHz (4) Arm Cortex-A53 (2 lockstep) @1GHz |
| 700 DMIPS processing                                                  | 15,900 DMIPS processing (>16x Calypso) (including 3900 real-time - 5.6x Calypso)                   |
| No communications acceleration                                        | CAN/LIN/FR/SPI Comms Acceleration Ethernet Packet Acceleration                                     |
| 768 KB SRAM, 6 MB embedded flash MMC, SD                              | 8 MB SRAM, no embedded flash, MMC, SD, QSPI, DDR3L/LPDDR4 support                                  |
| (2) 10/100 Ethernet                                                   | (3) 1G Ethernet, (1) 2.5G                                                                          |
| (8) CAN FD / (18) LIN                                                 | (20) CAN FD / (7) LIN                                                                              |
| USB 2.0                                                               | USB 2.0, (2) Gen3 PCIe                                                                             |
| HSM Security (100 DMIPS)                                              | HSE Security (1300 DMIPS) + Physical Protection                                                    |
| ASIL B functional safety - fail safe                                  | ASIL D functional safety - fail operational                                                        |

Arm, Cortex are trademarks or registered trademarks of Arm Limited (or its subsidiaries) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved.

<!-- image -->

<!-- image -->

## S32G2 Software Support

<!-- image -->

## S32G2 SOFTWARE AND FIRMWARE

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## S32G2 Tools Overview

<!-- image -->

## S32 Design Studio is a software development environment One integrated environment with tools and software

- GCC and premium industry compilers for all ARM cores
- NXP S32 Debugger and third-party debugger support
- S32 Configuration Tools:
- Pins, Clocks, DDR, DCD, IVT, Peripheral, SW Config
- New Project Wizard
- Flash tool
- Platform software SDKs

<!-- image -->

<!-- image -->

## S32DS: COMPONENTS - S32 CONFIGURATION TOOL

## Pins Tool

<!-- image -->

## IVT Composer Tool

<!-- image -->

## Clock Configuration

<!-- image -->

<!-- image -->

## FreeRTOS Config

<!-- image -->

## Peripheral Config

<!-- image -->

<!-- image -->

## S32DS: COMPONENTS - FLASH TOOL

S32 Flash Tool is a solution designed for programming binary files (software images) to an external flash device.

S32 Flash Tool supports SD, eMMC via uSDHC interfaces and external flash devices supported on the target via QSPI peripheral.

<!-- image -->

<!-- image -->

<!-- image -->

- DDR Tool provides board and component specific DDR PHY and Controller initialization.
- Generated code can be used within the boot loaders to prepare software to use DDR.

<!-- image -->

<!-- image -->

- S32 Debugger &amp; S32 Debug Probe
- Interface through probe USB directly or Ethernet across a network
- Full Multi-core Debug supported
- Interface to target through JTAG connector
- Support standard debug features

<!-- image -->

Flash programming through JTAG included in debugger

Debug from RAM or Flash

Accelerator Core Support

C Source Code/Assembly Debug

General Core Register Views

Specialized Register View

Standard GNU Debug Views

Breakpoints, Expressions, Memory, Disassembly

Supports all programmable cores on S32 devices: A53/R52/M4/M7/M0+ Arm cores

## www.nxp.com/S32DebugProbe

<!-- image -->

## TOOLS SUMMARY

## Integrated Development Environment - S32 Design Studio V3.x

<!-- image -->

## S32 Debugger/ Trace &amp; Profiling Tools

Support rev 1 and rev 2 Silicon New Project wizard supports selection of silicon revision S32 Debugger support 3200MT/s for LPDDR4 for rev 2 Secure Application Debug Support Secure boot support by S32 Flash Tool Support Real Time Drivers for rev 2

## S32 Configuration Tools

<!-- image -->

<!-- image -->

DDR configuration/QSPI configuration DDR Firmware config/download DCD/IVT/Clocks/Pins/Peripherals Support for RTD software

<!-- image -->

<!-- image -->

<!-- image -->

Standard Debug Capabilities Scripting and Logging Multicore debug/Flash through JTAG USB/Ethernet Probe Connection (Remote/Local) Secure Application Debug Support Trace and Profiling on A53 Cores

## S32 Flash Tool

<!-- image -->

GUI/Command line Flash QSPI/SD/eMMC support UART/CAN/Ethernet

Program IVT/DCD/Self-test/HSE/Application Boot

<!-- image -->

## Code Generation Tools

<!-- image -->

Compilers, Assemblers, Linkers NXP GCC-v6.3 &amp; v9.2

<!-- image -->

## NXP S32G2 Boards Overview

<!-- image -->

## S32G: VEHICLE NETWORK PROCESSING REFERENCE DESIGN BOARD (RDB2)

<!-- image -->

S32G274AVehicleNetworkProcessor SJA1110A 10-portAutoEthernetSwitch

VR5510

PowerManagementIC

PF5600

PowerManagementIC

PF5300

PowerManagementIC

PF5020

PowerManagementIC

NX5P3363USBPowerSwitch

CBTL02043ADifferential2:1Switch

Note: Data is for S32G-VNP-RDB2 Rev C

TJA1043High-speedCANTransceiver

TJA1153SecureCANTransceiver(STINGER)

TJA14635MbpsCANTransceiver（FALCON)

TJA1021LINTransceiver

TJA1124QuadLINMasterTransceiver

TJA1081FlexRayNodeTransceiver

NTS0102Dual-supplyTranslatingTransceiver

https://nxp.com/S32G-VNP-RDB2

https://nxp.com/S32G-VNP-GLDBOX

Name:

S32GVehicleNetworkProcessingReferenceDesignBoard2

PartNumber:

S32G-VNP-RDB2/S32G-VNP-GLDBOX(w/enclosure)

MainFunction:

- -A-sample-likedesignfordevelopment/demos/evaluation

- -GatewayandDomainControllerApplications

- -Central computerw/PCle tootherSoC(s)

- -Service-orientedArchitecture(SoA)

- -FOTA/Firewalldemo

- -Functionsafetyand low-powerdesign

Price:

Availability:

<!-- image -->

<!-- image -->

ZP

<!-- image -->

<!-- image -->