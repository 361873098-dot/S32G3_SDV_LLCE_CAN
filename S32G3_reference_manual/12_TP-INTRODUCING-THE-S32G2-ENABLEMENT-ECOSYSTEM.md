## S32G2 Development Environment

APRIL 2021 VCNS APPLICATIONS AND SOLUTIONS

<!-- image -->

EXTERNAL USE

<!-- image -->

<!-- image -->

## Agenda

- Introduction
- S32G2 SW Development Tools
- S32 Design Studio
- Tool Overview
- S32DS Components
- -Configuration Tools
- -S32 Debugger + S32 Debug Probe
- Yocto for Linux BSP
- 3 rd Partner Compilers and Tools
- Lauterbach
- Green Hills
- iSystem
- HW Platforms
- RDB2 / GoldBox

<!-- image -->

## INTRODUCTION

<!-- image -->

EXTERNAL USE

2

## I N T RODUCTION

- S32G2 is a high-performance vehicle network processor
- NXP offers SW and HW support to build and setup development environment including
- Integrated environment with tools and software to ease SW development
- Quality production software releases
- Reference Design Board  2 and GoldBox for HW reference and SW development
- Support for 3 rd partner compilers and tools

<!-- image -->

<!-- image -->

## S32G2 Software Development Tools

<!-- image -->

EXTERNAL USE

4

## S32DS OVERVIEW

- The S32 Design Studio IDE is a collection of tools and software to enable automotive users to quickly and easily develop their applications.
- Features:
- Ease application development with software as part of the Integrated Development Environment:
- S32G Real Time Drivers (RTD) for easy S32G Platform development
- NXP GNU toolchain for bare-metal and Linux® ARM® targets
- Multicore debugging support, Semi hosting support
- S32 Debug Probe support provided with S32 Debugger and S32 Trace
- Arm and accelerator cores supported
- Support for Lauterbach TRACE32 debugging
- S32DS Extensions and Updates tool
- S32 Configuration Tool framework - DDR Tool, IVT Tool, etc.
- Support for kernel aware debugging for FreeRTOS
- Linux application project creation and remote debugging

<!-- image -->

## S32DS EXTENSIONS AND UPDATES

Special tool to install, update and learn packages

- Communicates with the product's website
- Access to new products and features
- Reduce DS download size
- Display actual information about packages
- Pop-up notification about updates
- User can download the latest product updates manually

<!-- image -->

<!-- image -->

## S32DS EXTENSIONS AND UPDATES

To add new patches/updates which are manually downloaded from Flexera:

- Window -&gt; Preferences -&gt; S32DS Extensions and Updates
- Add -&gt; add the archive.
- Apply -&gt; OK

A pop-up will show that new modules are available to be installed. Click it OR go to the extensions and updates window manually. And install the package.

<!-- image -->

<!-- image -->

## S32DS INSTALLING REAL TIME DRIVERS (RTD)

1. Download latest RTD package release from Flexera.
2. Open S32DS.
3. Help -&gt; Install New Software…
4. Add -&gt; Archive -&gt; SW32G2\_RTD\_4.4\_0.9.0\_CD01\_DS\_updatesite\_D 2009.zip
5. Uncheck Group items by category.
6. Select All -&gt; Finish

It takes a few minutes to install the RTD and once the installation is complete the S32DS will re-start.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## S32DS: PROJECT EXPLORER - NEW PROJECT

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## S32DS: IDE

Project Explorer Window

<!-- image -->

Problems, Tasks, Console, Properties tabs window

To add more tabs, go to Windows -&gt; Show View and select the new view

Configuration tools pane

<!-- image -->

## S32DS COMPONENTS: CONFIGURATION TOOLS

<!-- image -->

## Available tools:

1. Pins Tool
2. Clocks Tool
3. Peripherals Tool
4. DCD Tool
5. IVT Tool
6. QuadSPI Tool
7. DDR Tool
8. Flash Tool

<!-- image -->

## S32DS COMPONENTS: CONFIGURATION TOOLS

<!-- image -->

<!-- image -->

## S32DS COMPONENTS: CONFIGURATION TOOLS

## Pins Tool

<!-- image -->

## IVT Tool

<!-- image -->

## DCD Tool

<!-- image -->

## Flash Tool

<!-- image -->

## Clocks Tool

<!-- image -->

## QuadSPI Tool

<!-- image -->

## Peripherals Tool

<!-- image -->

## DDR Tool

<!-- image -->

<!-- image -->

## PINS TOOL

- The Pins Tool is used for pin routing configuration, validation and code generation.
- It provides pin settings for signal muxing, electrical properties, and run-time configurations.
- Selections can easily be captured using the graphical package view or searchable or sortable spreadsheet view.

<!-- image -->

<!-- image -->

## PINS TOOL

<!-- image -->

Quick configuration of pins from:

1. Peripherals view
2. Pins view
3. Package view
4. Resource view Other features:
5. Properties for each pin, Validation of pins selection, Support and help for managing conflicts
6. Registers modified information (6)
7. Configuration C-Code Generation
8. Power Groups Highlight

<!-- image -->

## PINS TOOL: C-CODE GENERATION

<!-- image -->

1. For c-code generation, click the Update Code icon.
2. The Update files window shows the files getting modified and the status corresponding to each file.

In case the status column shows error, remove the error first and then update code.

3. Click OK for code generation.

The user can individually generate code for every tool output OR can also configure every tool for desired settings to generate all the code at once.

<!-- image -->

## DCD TOOL

- The DCD Tool is used to generate the Device Configuration Data image.
- DCD is the configuration information contained in the DCD Image, that the Boot ROM interprets to configure various peripherals on the device.

<!-- image -->

<!-- image -->

## DCD TOOL

<!-- image -->

<!-- image -->

- DCD Tool Supports following 3 commands: ×
- 1.WRITE - writes a memory area 2.NOP - introduces a wait
- 3.CHECK -checks a memory area
4. The user can select the command from the drop-down menu
5. DCD Tool generates a binary which incorporates all the settings done.
6. The user can export this image using the Export button on the top right corner. This image can be further imported in the DCD section in IVT tool while creating the blob image.

<!-- image -->

## CLOCKS TOOL

- The Clocks Tool allows the user to easily configure the initialization of the system clocks, including core, system, bus and peripheral clocks, and then generate C-code.
- Visual inspection of the configured clock paths is available using the graphical clock tree.
- The S32 Config Tools Clocks Tool validates clock settings and provides calculations of the resulting clock frequencies.

<!-- image -->

<!-- image -->

## CLOCKS TOOL

<!-- image -->

Quick configuration of clocks can be done from:

1. Clock diagram view

Clock summary table

2. Sources
3. Outputs

Support and help for managing conflicts and highlighting constraints - (4)

Register modified information - (5)

- Configuration C-Code Generation - (6)

Peripheral clock view, to enable/ disable IP clock, select the source, set the dividers and provide the frequency value - (7)

<!-- image -->

## CLOCKS TOOL: C-CODE GENERATION

<!-- image -->

1. For c-code generation, click the Update Code icon.
2. The Update Files window shows the files getting modified and the status corresponding to each file.

In case the status column shows error, remove the error first and then update code.

3. Click OK for code generation.

The user can individually generate code for every tool output OR can also configure every tool for desired settings to generate all the code at once.

<!-- image -->

## PERIPHERALS TOOL

- Peripherals Tool provides a user-friendly interface for quick configuration of IP with code generation on top of RTD SDK. The settings are instantly checked for conflicts or constraint violations.

<!-- image -->

<!-- image -->

## PERIPHERAL TOOL

<!-- image -->

+

1. Select the peripherals to configure by clicking on the check box.
2. Apply desired configurations.
3. Configuration CCode Generation.
4. Register modified information.

<!-- image -->

## I V T  TOOL

- The IVT tool helps create the IVT image which is the first image that BootROM reads from the boot device.

<!-- image -->

<!-- image -->

## I V T  TOOL

<!-- image -->

<!-- image -->

## FLASH TOOL

S32 Flash Tool supports programming user's image to flash memory. User has 2 options to access the Flash tool:

1. From IDE in the IVT Tool Window
2. S32 Flash tool GUI inside \_\_\S32DS\tools\S32FlashTool\GUI\s32ft.exe

<!-- image -->

<!-- image -->

<!-- image -->

## FLASH TOOL

Step 1: Put the device in serial boot mode.

Step 2: Select the communication device and parameters. The example here uses transfer over serial UART interface.

Step 3: Select the Target as S32G2xxx.

Step 4: Select the flash device in the algorithm, the tool provides write to different QSPI Flash devices, SD and eMMC.

Step 5: Tick the Secure boot checkbox if the user plans to do a secure boot.

Step 6: Power on the board.

Step 7: Initialize the hardware

- Click 'Upload target and algorithm to hardware…'

Step 8: Different Flash operations may now be used to erase/read/write to the flash device.

The progress bar comes in the Execution Window.

In case of any error, make sure the RCON and BMOD settings are correctly done for serial boot mode and that the device is connected successfully over the communication medium.

<!-- image -->

<!-- image -->

## QUADSPI TOOL

- The QuadSPI Tool is used to generate the reconfiguration parameters image for QuadSPI boot.
- The reconfiguration parameters are the configuration parameters provided as a pointer in the IVT image that the BootROM interprets to re-configure QuadSPI at the required speed, pads and other configurations.

<!-- image -->

<!-- image -->

## QUADSPI TOOL

<!-- image -->

A Problems α

<!-- image -->

<!-- image -->

1. QuadSPI configuration settings for selecting the Flash port connection, DLL modes and IPCR enable.
2. QuadSPI flash clock frequency set.
3. QuadSPI register configuration window.
4. Command sequence add window
5. 4.1. To add sequence, click add, and provide the required instruction, pin and operand.
5. Flash write data window.
7. 5.1. Flash write data configuration window.

<!-- image -->

## DDR TOOL

- DDR Tool helps with DDR PHY and Controller initialization.

<!-- image -->

<!-- image -->

## DDR TOOL

<!-- image -->

type filter text

1. Memory configuration window
2. Different Validation scenarios
3. Validation tests selection and configuration and results
4. Validation tests logs and summary
5. Serial/Ethernet connection setup for validation test. Tool can be connected via serial connection/ debug probe (ethernet)
6. Configuration C-Code Generation.

<!-- image -->

## DDR TOOL

<!-- image -->

1. Select connection
2. Select operation to be performed
3. Configure the operation and view the results
4. Run the test
5. View/export generated files

<!-- image -->

## S32DS COMPONENTS: CONFIGURATION TOOLS

<!-- image -->

<!-- image -->

## S32DS COMPONENTS: S32 DEBUGGER AND S32 DEBUG PROBE

## All standard debug features included

- Interface through probe USB directly or Ethernet across a network
- Full Multicore Debug supported
- Interface to target through JTAG connector
- Flash programming through JTAG included in debugger
- Debug from RAM or Flash
- Accelerator Core Support
- C Source Code/Assembly Debug
- General Core Register Views
- Specialized Register View
- Standard GNU Debug Views
- Breakpoints, Expressions, Memory, Disassembly
- Supports all programmable cores on S32G:
- A53/M7/M0+ Arm® cores

<!-- image -->

<!-- image -->

## S32DS COMPONENTS: S32 DEBUGGER AND S32 DEBUG PROBE

<!-- image -->

<!-- image -->

1. Click the drop-down button in front of debug icon and select Debug Configurations.
2. Select the Debug\_RAM option corresponding to your project.
3. On the Main tab, verify the following settings:
- Project: The path of the application project.
- Application: The path of the executable (ELF)built from the application project.
- Build Configuration: The build configuration for debugging from RAM. If you activate the Enable autobuild option, this build configuration will be used to rebuild the application before each debug session.
4. Check the Debug probe connection along with other settings in the Debugger tab.
5. On the Startup tab, specify the place in code where the first breakpoint will be set ( main by default).
6. Click Apply and then Debug.

<!-- image -->

## S32DS COMPONENTS: S32 DEBUGGER AND S32 DEBUG PROBE

<!-- image -->

1. Source code view for debug
6. Peripheral registers window

<!-- image -->

- The Linux BSP is a collection of source code that can be used to create U-Boot boot loader, Linux kernel image and a root filesystem for the supported boards.
- Linux BSP for S32G is built and tested using the gcc 9.2.0 for Arm ® 64 cross-compiler included in the Yocto 3.0 "Zeus" distribution.
- The Yocto component is responsible for providing a way of building all BSP components and tools necessary to create the binary images that run on the target supported hardware.
- Refer the Linux BSP User Manual provided with every BSP release for more details.

<!-- image -->

## Third Partner Compilers and Tools

<!-- image -->

EXTERNAL USE

3 8

## LAUTERBACH GMBH - TRACE 32 DEBUGGER FOR S32G

<!-- image -->

| Product Key Features and Benefits                                                                                                                                                                              | Targeted Applications/Verticals                                                                                         |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
| • ASM/HLL/C++ Debugger • SMP and AMP Debugging • CACHE and MMU Support • FLASH Programming • Powerful Script Language • API for Automated Testing • On-Chip Trace Support • Support for many operating systems | • Software Debug and Test • Software Verification • Hardware Bring-up • Hardware Test • Production Programming and Test |
| Product Enablement                                                                                                                                                                                             | Product Imagery                                                                                                         |
| Product page: https://www.lauterbach.com/bdmarm.html Evaluation Software: https://www.lauterbach.com/download.html                                                                                             |                                                                                                                         |

https://www.lauterbach.com https://www.nxp.com/webapp/connect/displayPartnerProfile.sp?partnerId=1%2BS%2B7694

<!-- image -->

## Order Information

| Orderable Part Number   | Detail                                    |
|-------------------------|-------------------------------------------|
| LA-3500                 | PowerDebug USB3                           |
| LA-3743                 | Debugger for Cortex-A/R (ARMv8 32/64-bit) |
| LA-7844X                | Debug Cortex-M (ARMv6/7/8 32-bit) Ext.    |
| LA-7970X                | Trace License forARM (Debug Cable)        |

## NXP Product Associations

NXP Product Family

## S32G274A

<!-- image -->

## LAUTERBACH GMBH - TRACE 32 DEBUGGER AND TRACE FOR S32G

| Product Key Features and Benefits                                                                                                                                                                               | Targeted Applications/Verticals                                                                                                                                   |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| • ASM/HLL/C++ Debugger • SMP and AMP Debugging • CACHE and MMU Support • FLASH Programming • Powerful Script Language • API for Automated Testing • Off-Chip Trace Support • Support for many operating systems | • Software Debug and Test • Software Verification • Hardware Bring-up • Hardware Test • Run-time Measurement and Profiling • Code Coverage for DO330 and ISO26262 |

## Product Enablement

## Product page:

https://www.lauterbach.com/bdmarm.html

## Evaluation Software:

https://www.lauterbach.com/download.html https://www.lauterbach.com

https://www.nxp.com/webapp/connect/displayPartnerProfile.sp?partnerId=1%2BS%2B7694

## Product Imagery

<!-- image -->

<!-- image -->

## Order Information

| Orderable Part Number   | Detail                                    |
|-------------------------|-------------------------------------------|
| LA-3505                 | PowerDebug PRO                            |
| LA-3743                 | Debugger for Cortex-A/R (ARMv8 32/64-bit) |
| LA-7844X                | Debug Cortex-M (ARMv6/7/8 32-bit) Ext.    |
| LA-3520 + LA-3521       | Power Trace Serial + Cable Set            |

## NXP Product Associations

NXP Product Family

## S32G274A

<!-- image -->

## GREEN HILLS SOFTWARE - MULTI INTEGRATED DEVELOPMENT ENVIRONMENT

## Product Key Features and Benefits

- Certified for automotive, industrial, medical safety (ASIL D, SIL 3)
- Optimizing 32/64-bit C/C++ compilers for all Arm, PowerPC and ColdFire cores
- Multicore, multithread source level debugger executes forward and reverse in code
- OS-Awareness for OSEK/AUTOSAR® and Linux®
- MISRA C Adherence Checker
- Run-time Errors &amp; Memory Leak Detection
- Instruction Set Simulator
- Static Code Coverage, Performance Profiler
- Flash programming
- Python API for external programs
- Source Code Editor
- Project Builder and makefile interfaces

Product Enablement https://www.ghs.com/video/index.html

https://www.ghs.com/products/MULTI\_IDE.html https://www.ghs.com/products/rtos/integrity.html

https://www.nxp.com/webapp/connect/displayPartnerProfile.sp?partnerId=1%2B40B%2B16&amp;tid=vanG REENHILLS

## Targeted Applications/Verticals

All embedded C/C++/Ada/Assembly applications including:

- Automotive
- IoT
- Industrial
- Medical
- Military and aerospace
- Networking
- Storage
- UAVs

Product Imagery

<!-- image -->

<!-- image -->

## Pricing

Pricing is not public but available to customers through Green Hills Sales teams.

## NXP Product Associations

NXP Product Family

Kinetis V, K, W, E, L, M, or EA Series MCUs

LPC5500, LPC54000, LPC51U68, LPC800, or LPC1100 Series MCUs i.MX RT1064, RT1060, RT1050, RT1020, RT600 Series Crossover Processors

i.MX 8, 7, 6 Series Applications Processors

S32G , S32R, S32V (Cortex-A), S32S (Cortex-R)

LX2xxx, LS2xxx, LS1xxx (Cortex-A)

<!-- image -->

## GREEN HILLS SOFTWARE - GREEN HILLS PROBE V4

## Product Key Features and Benefits

- 4GB of high-speed trace memory with 40 Gbits/second of aggregate bandwidth
- Multiuser, multicore, high-speed JTAG and Trace debugging and board bring-up
- Connects to the board via Ethernet or USB
- Supports desktop Windows &amp; Linux® host operating systems
- High speed serial or parallel
- Software and hardware breakpoints
- Firmware is field upgradeable

## Product Enablement

https://www.ghs.com/products/probe.html https://www.ghs.com/partners/NXP\_partner.html

https://www.nxp.com/webapp/connect/displayPartnerProfile.sp?partnerId=1%2B40B%2B16&amp;tid=vanG REENHILLS

## Targeted Applications/Verticals

- Automotive
- IoT
- Medical
- Industrial
- Military and aerospace
- Storage
- Any application running on NXP processor

## Product Imagery

<!-- image -->

## Pricing

Pricing is not public but available to customers through Green Hills Sales teams.

## NXP Product Associations

## NXP Product Family

Kinetis V, K, W, E, L, M, or EA Series MCUs

LS 1xxx, LS2xxx families i.MX RT Series Crossover Processors

i.MX 8, 7, 6 Series Applications Processors

ColdFire, S32G

<!-- image -->

<!-- image -->

## I S YSTEM HARDWARE - BLUEBOX IC5700

## Product Key Features and Benefits

- Generic Hardware Platform
- PC Interface USB 3.0, ETH
- Trace Support Nexus, ETM, HSSTP
- Trace Buffer Size 1 GB
- Trace Bandwidth up to 250MHz in parallel mode, up to 5Gbps in serial mode

## Product Enablement

https://www.youtube.com/watch?v=Pl\_xQp10erM

https://www.isystem.com/products/hardware.html https://www.isystem.com/support/online-help.html

https://www.isystem.com/products/hardware/onchip-analyzers/ic5700.html https:/www.isystem.com https://www.nxp.com/webapp/connect/displayPart nerProfile.sp?partnerId=1-2DE8-12

## Targeted Applications/Verticals

- Automotive
- Others

## Product Imagery

<!-- image -->

## Pricing

| Orderable Part Number   | Pricing   |
|-------------------------|-----------|

## NXP Product Associations

## NXP Product Family

## PowerArchitecture

Arm/Cortex

<!-- image -->

<!-- image -->

<!-- image -->

## I S YSTEM SOFTWARE - WINIDEA

## Product Key Features and Benefits

- Windows debug environment
- Supports all basic debug capabilities Breakpoints, memory view, watch windows, real-time watch, RTOS task view
- Includes advanced debug support Trace, Profiling, Code Coverage, Multicore, AUTOSAR® Profiling, …
- Microsoft Visual Studio Look&amp;Feel

## Product Enablement

https://www.youtube.com/watch?v=Pl\_xQp10erM

https://www.isystem.com/products/software.html https://www.isystem.com/support/online-help.html

https://www.isystem.com/products/software/winid ea.html https://www.isystem.com/products/software/winid ea-open.html

https:/www.isystem.com https://www.nxp.com/webapp/connect/displayPart nerProfile.sp?partnerId=1-2DE8-12

## Targeted Applications/Verticals

- Automotive
- Others

## Product Imagery

<!-- image -->

## Pricing

| Orderable Part Number   | Pricing   |
|-------------------------|-----------|

## NXP Product Associations

NXP Product Family

PowerArchitecture

Arm/Cortex

<!-- image -->

<!-- image -->

<!-- image -->

## Hardware Platforms

<!-- image -->

EXTERNAL USE

4 5

## S32G-VNP-RDB2 AND S32G-VNP-GLDBOX

The S32G-VNP-RDB2 and S32G-VNP-GLDBOX (GoldBox) are compact, highly-optimized and integrated reference design platforms featuring the S32G Vehicle Network Processor. The GoldBox has the RDB2 inside its enclosure.

With its high-performance computing capacity and rich input/output(I/O), this board can provide reference for a variety of typical automotive applications, such as serviceoriented gateway, vehicle central compute nodes, domain controller, safety controller, black-box, smart antenna and FOTA. They can be directly used by carmakers, suppliers and software ecosystem partners to accelerate development for shorter time-to-market.

<!-- image -->

S32G-VNP-RDB2

S32G-VNP-RDB2 Landing Page: https://nxp.com/S32G-VNP-RDB2

S32G-VNP-GLDBOX Landing Page: https://nxp.com/S32G-VNP-GLDBOX

<!-- image -->

S32G-VNP-GLDBOX

<!-- image -->

## S32G-VNP-RDB2 / S32G-VNP-GLDBOX BOARD OVERVIEW

- Part Number:
- S32G-VNP-RDB2
- S32G-VNP-GLDBOX (RDB2 w/enclosure)
- Main Functions:
- A-sample-like design for development/demos/evaluation
- Gateway and Domain Controller Applications
- Central computer w/PCIe to other SoC(s)
- Service-oriented Architecture (SoA)
- Supports low power mode and multiple wake-up sources
- Strengthens safety design on power supply part

<!-- image -->

<!-- image -->

## S32G-VNP-RDB2 / S32G-VNP-GLDBOX : BLOCK DIAGRAM

<!-- image -->

<!-- image -->

<!-- image -->