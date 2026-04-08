## LLCE LOW LATENCY CAN GATEWAY DEMO

APRIL 2021 VCNS SOLUTIONS &amp; APPLICATIONS

<!-- image -->

<!-- image -->

<!-- image -->

## AGENDA

Background

S32G2 LLCE Low Latency CAN Gateway DEMO

How this DEMO works

DEMO BOM

How to develop DEMO setup 1 for RDB2

How to develop DEMO setup 2/3 for RDB2

Setup Companion parts &amp; complete the system

Run the Demo

<!-- image -->

<!-- image -->

Background

<!-- image -->

## Flat to Hierarchical…

<!-- image -->

3 PUBLIC This demo shows low latency CAN gateway capability of S32G.

## S32G LLCE Low Latency CAN Gateway Demo

・ Demo setup 1

Low Latency CAN Gateway

<!-- image -->

To show the S32G's excellent low latency performance as a CAN gateway comparing conventional part. Excellent Low Latency performance

・ Demo setup 2 :

Low Latency CAN Gateway

Ethernet Video packets routing

+

<!-- image -->

To show the CAN2CAN low latency performance is not impacted by Video streaming Ethernet packet routing simultaneously. The CAN2CAN Low Latency performance is not impacted

・ Demo setup 3 :

Low Latency CAN Gateway

Ethernet 1Gbps routing

+

<!-- image -->

4 PUBLIC To show the CAN2CAN low latency performance is not impacted by 1Gbps high band-width Ethernet traffic routing simultaneously. The CAN2CAN Low Latency performance is not impacted

<!-- image -->

<!-- image -->

## S32G2 LLCE Low Latency CAN Gateway DEMO

<!-- image -->

## Demo Setup 1:

Low Latency CAN Gateway

<!-- image -->

## On the presentation PC, showing the logo transfer.

<!-- image -->

<!-- image -->

<!-- image -->

CANframe sende

NP

CANframe sende

NXO

Conventional

Gateway

CAN2CAN routing

S32G

CAN2CAN routing

UVAP

S32G274A

Session1-PulseView

Run

Session 1

Session1

Conventional Destination

Conventional Destination

S32GSource

S32G Destination

S32G Destination e2eSoft iVCam

Saleae Logic

+393200μs

10M samples8MHz

+393400μs

PUBLIC

口

+393600μs

9

YOU MIGHT SAY….

<!-- image -->

<!-- image -->

Yeah, understood S32G2's latency is shorter than conventional one.

But, not so much, right?

<!-- image -->

## Performance difference is much larger than it looks.

<!-- image -->

PUBLIC

Performance difference is much larger than it looks.

Conventional GW

SW routing

Source Ch.

Endofframe

Source Ch.

Bitmap frame

Destination Ch.

CAN:Fields

Destination Ch.

S32G

LLCE

routing

Source Ch.

Bitmap frame

Destination Ch.

Bitmap frame approx. 7us

approx. 200us

Latency

LLS

Bitmap frame

Ack frame

2 digits

Ack frame difference !

Ack frame

Latency

CR·IE

PUBLIC

time

+14800s

ID

CR...

IE

Ack frame time

1 2

## Why low latency ?

Conventional GW : CPU Core searches on RAM

<!-- image -->

Takes long latency depending on the hit index. Takes long latency depending on the hit index.

S32G/LLCE : RXLUT searches on F/F array ( RXLUT: RX LookUp Table accelerator )

<!-- image -->

<!-- image -->

## Demo setup 2:

Low Latency CAN Gateway

<!-- image -->

+

Ethernet Video packets routing

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

CANframe sender

NP

CANframe sende

NXO

Ethernet

Packet sende

?

Conventional

Gateway

CAN2CAN routing

S32G

CAN2CANrouting

UVAP

S32G274A

ETH2ETH routing e2eSoftiVCam

iv

192.168.2.20:8080/?action=strea

Notsecure

Settings

192.168.2.20:8080/?action=stream

PUBLIC

1 7

## Demo setup 3:

Low Latency CAN Gateway

<!-- image -->

+

Ethernet Video packets routing Ethernet 1Gbps routing

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

2 1

PUBLIC RX:eno1 1Gbps trafficrouting on

- S32G's CAN routing latency is much shorter than conventional Gateway.

## High Performance !

- Even massive Ethernet traffic routing will not affect on S32G's CAN routing performance.

## Deterministic !

<!-- image -->

<!-- image -->

## How this DEMO works.

<!-- image -->

Logic Analyzer

Windows10 PC (Demo presenting)

Bitmap senders (S32K EVB)

rendering view via WiFi

NP

4

NP

4

Bitmap Receivers (S32K EVB + Arduino LCD)

<!-- image -->

Conventional CAN Gateway (MPC5748G DEVKIT + DEVKIT COMM)

Mobile phone working as Wi-Fi camera

S32G-VNP-RDB2

<!-- image -->

## Demo setup 1 : Only CAN2CAN is done.

No activity. A53 clusters are not used.

S32G Real Time Drivers AUTOSAR ® 4.4 version 1.0.0 runs on M7 in order to configure LLCE and to start routing.

LLCE Demo app

RTD ASR4.4 1.0.0

M7 core

LLCE-FW

LLCE

Not used

PFE-FW

PFE

A53 clusters

S32K bitmap sender

<!-- image -->

S32K bitmap receiver

<!-- image -->

Any activity except CAN2CAN routing is not running.

CAN

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

Ubuntu PC 2 (192.168.0.20) 1000Base-T

<!-- image -->

<!-- image -->

## : ETH2ETH and CAN2CAN simultaneously. Demo setup 2&amp;3

Packet sender PC with WebCAM. Packet sender PC with iperf3.

<!-- image -->

View streamed video Measuring received traffic

## CAN2CAN Latency performance is not impacted by Ethernet packet routing.

<!-- image -->

<!-- image -->

<!-- image -->

COM8-TeraTermVT

FileEditSetupControlWindowHelp

口

X

e2eSoftiVCam

<!-- image -->

PUBLIC

3 0

<!-- image -->

## DEMO BOM

<!-- image -->

## HARDWARE BOM

<!-- image -->

<!-- image -->

S32G-VNP-RDB2  x1

S32K144EVB-Q100 x4

S32G  LLCE and AC power supply x2

<!-- image -->

- Arduino LCD shield x2 + Following LCDs are supported.

ILI9325, ILI9341, LGDP4535, ST7783, UC8230s

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

Female-to-Male / Female-to-Female Jumper cables for connection between parts

<!-- image -->

USB Logic Analyzer x1

DEVKIT-MPC5748G x1

DEVKIT-COMM x1

<!-- image -->

<!-- image -->

Linux PC x2, Windows PC x1

<!-- image -->

## SOFTWARE BOM

| Part                                                                               | Description                                                                                                                                     | Location                                                                                                                               | URL                                                                                                 |
|------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------|
| S32K CAN bitmap communication w/ LCD demo app MPC5748G DEVKIT CAN routing demo app | CAN bit map sender/receiver software project Conventional CAN gateway binary and project.                                                       | NXP Share                                                                                                                              | https://www.nxp .com/webapp/D ownload?colCo de=S32G-VNP- RDB2_LLCE- DEMO                            |
| PFE routing cli app binary                                                         | PFE application for Ethernet packet routing configuration                                                                                       | NXP Share                                                                                                                              | https://www.nxp .com/webapp/D ownload?colCo de=S32G-VNP- RDB2_LLCE- DEMO                            |
| The projects for RDB2                                                              | The out-of-the-box pre-built projects for RDB2 (For Demo setup1 and 2/3)                                                                        | NXP Share                                                                                                                              | https://www.nxp .com/webapp/D ownload?colCo de=S32G-VNP- RDB2_LLCE- DEMO                            |
| S32G274 Linux BSP27.0.0_PFE (binaries_auto_linux_bsp27.0_s32g 274_pfe.tgz)         | Linux BSP pre-built image.                                                                                                                      | Flexera: AutomotiveSW - S32G2 Reference Software > AutomotiveSW - S32G2 - Linux BSP > S32G274_LinuxBSP27.0.0                           | https://nxp.flexnetoperat ions.com/control/frse/do wnload?agree=Accept& element=12280077            |
| S32G LLCE standard SW Release 1.0.0 (S32G2XX_LLCE_GATEWAY_4.4_ 1.0.0_D2012.exe)    | Based on these software, you can replicate the demo project for RDB2. (Out-of-the-box complete project is contained in the above package on NXP | Flexera: AutomotiveSW - S32G2 Standard Software > AutomotiveSW - S32G2 - LLCE Driver + Firmware> S32G2XX_LLCE_1.0.0                    | https://nxp.flexnetoperat ions.com/control/frse/do wnload?element=12357 827                         |
| S32G2 Real Time Drivers4.4_1.0.0(SW32_RTD_4.4_ 1.0.0_D2012.exe)                    | Share)                                                                                                                                          | Flexera: AutomotiveSW - S32G2 Standard Software > AutomotiveSW - S32G2 - Real Time Drivers > S32G2 Real Time Drivers 4.4 version 1.0.0 | 3 3 PUBLIC https://nxp.flexnetoperat ions.com/control/frse/do wnload?agree=Accept& element=12359287 |

<!-- image -->

## SOFTWARE TOOLS

- -S32Design Studio version 3.4
- -S32 Design Studio 3.4 development packages for offline use, support for S32G2 family

(for creating SD card image)

- -S32DS for ARM 2018R1 (for building / programming S32K project)
- -GHS compiler (for building RDB2 project)
- -EB tresos Studio 2.6 (for configuration)
- -Cygwin (for building RDB2 project)
- -Sigrok Pulseview (GNU GPL Logic Analyzer software)
- -Win32DiskImager (Writing images to SD card)
- -TRACE32 (for flashing MPC5748G code on DEVKIT.)

<!-- image -->

<!-- image -->

## How to develop DEMO setup 1 for RDB2

<!-- image -->

## OVERVIEW OF THE FLOW

LLCE standard SW 1.0.0

Sample

FW binary app code

Modify tresos project

Eclipse/

plugins

EB tresos

Modify

Generated code make

RTD 4.4\_1.0.0

Eclipse/plugins elf

objcopy bin

S32DS3.4 IVT tool

Blob image

Win32DiskImager

PUBLIC

3 6

SD Card

## Preparation

<!-- image -->

PUBLIC

3 7

## Install the RTD 4.4 version 1.0.0

<!-- image -->

## I N S TALL  RTD\_4.4\_1.0.0

1. Go Flexera's Product Download page

## Automotive SW - S32G2 Standard Software

- &gt; Automotive SW - S32G2 - Real Time Drivers
- &gt; S32G2 Real Time Drivers 4.4 version 1.0.0
2. Download SW32\_RTD\_4.4\_1.0.0\_D2012.exe

<!-- image -->

<!-- image -->

## I N S TALL  RTD\_4.4\_1.0.0

3. Run downloaded exe file so that you can install the Real Time Drivers AUTOSAR 4.4 for S32G2.

<!-- image -->

<!-- image -->

## Once the install complete, Copy the installed RTD plugin files to the tresos plugin folder.

## 4. Copy the RTD plugin files in the installed eclipse\plugins to the EB-tresos's plugin folder.

<!-- image -->

<!-- image -->

## Install the LLCE Standard package 1.0.0

<!-- image -->

## I N S TALL  LLCE STANDARD PACKAGE 1.0.0

1. Go Flexera's Product Download page Automotive SW - S32G2 Standard Software
2. &gt; Automotive SW - S32G2 - LLCE Driver + Firmware &gt; S32G2XX\_LLCE\_1.0.0

<!-- image -->

<!-- image -->

## I N S TALL  LLCE STANDARD PACKAGE 1.0.0

3. Run downloaded .exe file so that you can install the LLCE Standard package including sample app.
4. Copy installed LLCE standard package 1.0.0

<!-- image -->

and rename (e.g., 'demo\_setup\_1') This will be the demo project folder.

<!-- image -->

## Once the install complete, Copy the installed plugin files to the tresos plugin folder.

<!-- image -->

<!-- image -->

## EB tresos Config

<!-- image -->

PUBLIC

4 6

## Import original tresos config from the installed LLCE SW

<!-- image -->

## Import the tresos config from the S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0

<!-- image -->

## Import the tresos config from the S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0

<!-- image -->

## Import the tresos config from the S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0

<!-- image -->

## Import the tresos config from the S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0

<!-- image -->

<!-- image -->

ZP

## Modify the tresos config.

1. CAN Controller configuration

<!-- image -->

## Load configuration

<!-- image -->

<!-- image -->

NP

## Configure baudrate for BCAN0.

<!-- image -->

5 4

<!-- image -->

NP

## Configure baudrate for BCAN0.

<!-- image -->

<!-- image -->

zP

## Configure baudrate for BCAN.

## Set following values for 500 kbps Arb. Rate)/2 Mbps Data Rate)

<!-- image -->

## Configure baudrate for BCAN1.

<!-- image -->

<!-- image -->

NP

## Configure baudrate for BCAN1.

<!-- image -->

<!-- image -->

NP

## Configure baudrate for BCAN1.

## Set following values for 500 kbps Arb. Rate)/2 Mbps Data Rate)

<!-- image -->

## Modify the tresos config.

## 2. Can Routing table configuration

<!-- image -->

## Configure Advanced feature

<!-- image -->

<!-- image -->

zP

## Configure Can2CanRoutingTable

<!-- image -->

<!-- image -->

zP

## Configure Can2CanRoutingTable\_0 for bitmap frame routing

<!-- image -->

## Configure Can2CanRoutingTable\_0 for bitmap frame routing

<!-- image -->

<!-- image -->

## Configure Can2CanRoutingTable\_1 for ack frame routing

<!-- image -->

<!-- image -->

## Configure Can2CanRoutingTable\_1 for ack frame routing

<!-- image -->

<!-- image -->

## Configure Can2CanRoutingTable\_1 for ack frame routing

<!-- image -->

<!-- image -->

NP

## Modify the tresos config.

3. Can HOH configuration

<!-- image -->

## Delete all Hardware object.

<!-- image -->

6 9

<!-- image -->

zP

## Create Dummy Hardware object entries.

<!-- image -->

<!-- image -->

## Create Dummy Hardware object entries.

<!-- image -->

ZP

## Create Dummy Hardware object entries.

<!-- image -->

## Create Dummy Hardware object entries.

<!-- image -->

8. Right click the row and click 'Duplicate element'. Repeat that until index 512. (Select multiple rows and duplicate for quick duplication.)

CanHardwareObject\_509*

&gt;

CanHardwareObject\_510*

CanHardwareObject\_511*

CanHardwareObject\_512*

Can Implementation Type*:FULL

FD padding value*:0

Can ID Message Type*:STANDARD

Can MBType*:RECEIVE

Can Object ID (MB Handll):0

Can Tx Ack send to Host*:true

Number of buffered Tx Confirmations*:16

Add MAC code to transmitted frames.*:false

B

Hardware Object Uses Polling*:false

Can Controller Reference*:/Can\_43\_LLCE/Can/CanConf

CanTriggerTransmitEnable*:false

Can MainFunction RW Period Reference*:/Can 43 LLCE

&gt;

Properties

Propertiesfor CanHandleType

Description

BASIC

BASIC

UBASIC

BASIC

BASIC

FULL

BASIC

Default

FULL

ErrorLog × ProblemsViewSearchd Results

Last 100 entries (up to 100) warnings, errors (filtered out: infos)

Message

Invalid XPath-expression for Attribute"EDITABLE" of node"/AUT

X\_Invalid XPath-

Basic-CAN) of a hardware object.

9. Configure column 'Can Implementation Type' of row 512 to 'FULL'

&gt;CanHwFilter*

&gt;CanGeneral

Configuration: Can\_43\_LLCE, Module: Can\_43\_LLCE\_TS\_T40D11M911R0, Project: MMLaunh\_training\_LLCE\_demo

Invalid XPath-expression for Attribute "EDITABLE" of node"/AUTOSAR/TOP-LEVEL-PACKAGES/Can\_43\_LLCE/ELEMENTS/Can/CanConfi!

Invalid XPath-expression for Atribute"EDITABLE" of node"/AUTOSAR/TOP-LEVEL-PACKAGES/Can\_43\_LLCE/ELEMENTS/Can/CanConfi

&gt;

Comments

CAN323\_Conf. Specifies the type(Full-CAN or

507

CanHardwareObject\_507

508 C CanHardwareObject\_508

510  CanHardwareObject\_510

509  CanHardwareObject\_509

511CanHardwareObject\_511

512CanHardwareObject\_512

STANDARD

STANDARD

Go

STANDARD

STANDARD

STANDARD

STANDARD

0 RECEIVE

0  RECEIVE

0 RECEIVE

0 RECEIVE

0

0  RECEIVE

RECEIVE

√□

口

VEL-PACKAGES/Can\_43\_LLCE/ELEMENTS/Can/CanConfig

口

口

口

PUBLIC

7 3

<!-- image -->

zP

## Create Dummy Hardware object entries.

<!-- image -->

10. Right click the row 512 and click 'Duplicate element'. Repeat that until index 1023. (Select multiple rows and duplicate for quick duplication.)

<!-- image -->

<!-- image -->

NP

## Create Dummy Hardware object entries.

<!-- image -->

## Create bitmap frame HOH.

<!-- image -->

<!-- image -->

## Conventional GW : CPU Core searches on RAM

S32G/LLCE : RXLUT searches on F/F array ( RXLUT: RX LookUp Table accelerator )

<!-- image -->

## Create bitmap frame HOH.

L

<!-- image -->

?

<!-- image -->

## Create bitmap frame HOH.

&gt;

<!-- image -->

## Create bitmap frame HOH.

<!-- image -->

## Create Ack frame HOH.

<!-- image -->

<!-- image -->

## Create Ack frame HOH.

<!-- image -->

## Create Ack frame HOH.

<!-- image -->

## Create Transmit HOH (BCAN0).

<!-- image -->

<!-- image -->

## Create Transmit HOH (BCAN0).

<!-- image -->

## Create Transmit HOH (BCAN1).

<!-- image -->

<!-- image -->

## Create Transmit HOH (BCAN1).

<!-- image -->

## Modify the tresos config.

## 4.Modify PLL &amp; DFS setting to enable LLCE full speed

<!-- image -->

## Open Clock configuration tab.

<!-- image -->

<!-- image -->

## Set CorePLL's loop divider value (i.e. MFD) and DFS's divider value (i.e. DFS1 MFI ).

<!-- image -->

<!-- image -->

NP

## Set CorePLL's loop divider value (i.e. MFD) and DFS's divider value (i.e. DFS1 MFI ).

NP

<!-- image -->

## Fix errors by re-calculation (PLL &amp; DFS)

<!-- image -->

## Fix errors by re-calculation (PCS)

<!-- image -->

<!-- image -->

NP

## Fix errors by re-calculation (PCS)

<!-- image -->

<!-- image -->

zP

## Fix errors by re-calculation (McuCgm0ClockMux0)

<!-- image -->

<!-- image -->

ZP

## Fix errors by re-calculation (McuCgm0ClockMux0)

<!-- image -->

PUBLIC

## Fix errors by re-calculation (McuClockReferencePoint)

<!-- image -->

<!-- image -->

ZP

## Fix errors by re-calculation (McuClockReferencePoint)

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

ZP

## Fix errors by re-calculation (McuClockReferencePoint)

<!-- image -->

<!-- image -->

zP

## Modify the tresos config.

5. Generate code

<!-- image -->

## Disable post-build variant.

1. Double click EcuC.

<!-- image -->

<!-- image -->

NP

## Generate Project.

<!-- image -->

<!-- image -->

zP

## Modify the LLCE sample app

1. Install tresos generated codes

<!-- image -->

## Copy the generated code folder into the demo project.

<!-- image -->

<!-- image -->

## Delete unnecessary files.

<!-- image -->

1 0 6

<!-- image -->

## Delete unnecessary files.

<!-- image -->

<!-- image -->

zP

## Modify app codes

<!-- image -->

PUBLIC

1 0 8

## MODIFY MAIN.C

Under your demo project, Edit

S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\sample\_app\_can\_llce\can\_mcal\_c an2can\src\main.c

This symbol is changed from

'&amp;Can\_43\_LLCE\_Config\_VS\_0' to '&amp;Can43\_LLCE\_Config'

```
12 void Can_Driver_Sample_Test (void) 13 14 volatile StatusType fail = E_OK; 15 Can_ErrorStateType ErrorState; 16 Std_ReturnType Can_retval = E_NoT_oK; 17 18 const Can_43_LLCE_ConfigType *Can_Cfgl = &Can_43_LLCE_Config: 19 20 Can_43_LLCE_Init(Can_Cfgl) : 21 22 /t Reset global flags and counters. 23 Can_CallBackSetUp() : 24 25 (void) can_retval; 26 27 can_retval = Can_43_LLCE_SetBaudrate(CoNTRoLLER0, 1): /* Index l corrresponds tc 28 Can_retval = Can_43_LLCE_SetControllerMode (CoNTROLLER0, CAN_CS_STARTED) : 29 can_retval = Can_43_LLCE_GetControllerErrorState(CoNTRoLLERo, fErrorState) : 30 31 Can_retval = Can_43_LLCE_SetBaudrate(CoNTRoLLERl, l) : /* Index 1 corrresponds t( 32 Can_retval = Can_43_LLCE_SetControllerMode(CoNTRoLLERl, CAN_CS_STARTED) : 33 Can_retval = Can_43_LLCE_GetControllerErrorState(CoNTRoLLERl, GErrorState): 34 35 36
```

<!-- image -->

1. In Can\_Driver\_Sample\_Test function, delete the lines which sending from host and receiving by the host. Keep the lines which initialize LLCE and BCAN0&amp;1.

Then, the function should be as this.

## MODIFY MAIN.C

## 2. Delete unused define lines.

<!-- image -->

<!-- image -->

## MODIFY CAN\_COMMON.H

Under your demo project, Edit

## S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\can\_common\include\can\_common.h

<!-- image -->

## MODIFY IO\_EXPAND.H

Since the onboard IO\_expander is different between RDB and RDB2, Address/port/register information to access the io-expander is changed.

Edit

S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\ioexpander\inclu de\IO\_expand.h

## Original

## Modified

<!-- image -->

## MODIFY IO\_EXPAND.H

## Original

## RDB's IO-Expander was TCA9539.

Modified RDB2's IO-Expander is PCAL6524.

<!-- image -->

<!-- image -->

## MODIFY IO\_EXPAND.C

```
Edit S32G2XX_LLCE_GATEWAY4_4_1_0_0_Sample_Application\platform_common\ioexpander\src\IO _expand.c
```

## Change the symbol name.

## Original

## Modified

```
[1]C:￥NXP¥...￥platform_common¥ioexpander￥src￥I0_expand.c [2]C:￥NXP¥...￥platform_common¥ioexpander¥src¥I0_expand.c 00007#include"10_expand.h 00007#include"10_expand.h 00008 00008 00009 00009 00010 00010 00011 void I0_expand_init(void) [ 00011 void I0_expand_init(void) { 00012 i2c_0_init(; 00012 i2c_0_init(； 00013 00013 00014 00014 00015 void 10_expand_write(TCA9539_DEVICE dev，TCA9539_REGISTER reg，uint8_t value) 00015 void I0_expand_write(PCAL6524_DEVICE dev，PCAL6524_REGISTER reg，uint8_t value)[ 00016 i2c_0_start_wait(TCA9539_DEVICE_ADDRESS + dev + I2C_WRITE); 00016 i2c_0_start_wait(PCAL6524_DEVICE_ADDRESS+ dev+I2C_WRITE); 00017 i2c_0_write(reg); 00017 i2c_0_write(reg); 00018 i2c_0_write(value); 00018 i2c_0_write(value); 00019 i2c_0_stop(); 00019 i2c_0_stop(）; 00020 00020 00021 00021
```

<!-- image -->

## MODIFY PLATFORM\_INIT.C

## Edit

S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\platform\_init\src\Pl atform\_Init.c

## Modify to align with new IO expander PCAL6524

## Modified

## Original

<!-- image -->

<!-- image -->

## MODIFY S32G\_I2C.C

```
Edit S32G2XX_LLCE_GATEWAY4_4_1_0_0_Sample_Application\platform_common\ioexpander\src\s3 2g_i2c.c
```

## Fix a typo in I2C ACK porality.

<!-- image -->

<!-- image -->

## Make

<!-- image -->

PUBLIC

1 1 7

## MODIFY CONFIG.MK

## Edit  S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\config.mk

<!-- image -->

<!-- image -->

## MAKE

Now ready to make. On the CYGWIN, run following commands.

$ make clean

$ make can\_routing

If no error, you can see the elf file 'can\_routing.elf' In S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\build

<!-- image -->

## OVERVIEW OF THE FLOW

LLCE standard SW 1.0.0

Sample

FW binary app code

Modify

Eclipse/

tresos project plugins

EB-tresos

Modify

Generated code make

RTD 4.4\_1.0.0

Eclipse/plugins elf

objcopy bin

S32DS3.4 IVT tool

Blob image

Win32DiskImager

PUBLIC

1 2 0

SD Card

## Create SD card for demo setup 1

<!-- image -->

PUBLIC

1 2 1

Convert elf to bin

<!-- image -->

## CONVERT CAN\_ROUTING.ELF TO BIN FILE.

## Elf to bin converter 'objcopy.exe' resides in the S32DS 3.4 installed directory.

<!-- image -->

<!-- image -->

## Run S32DS3.4 and open IVT tool.

<!-- image -->

## OPEN IVT TOOL ON S32DS3.4

Create a new project for S32G274A\_Rev2 on S32DS3.4. Then open IVT view.

If you can't reach below view, refer P14-P22 of 'S32G-VNP-RDB2 Software Enablement Guide V0.1.pdf '.

You can get the doc on Flexera (Automotive HW - S32G Reference Design Board 2 &gt; Automotive HW - S32G RDB2 - Documentation).

<!-- image -->

<!-- image -->

## ENABLE DCD AND APPLICATION BOOTLOADER

## Set DCD and Application bootloader ON. Set Others Reserved.

<!-- image -->

<!-- image -->

## Create DCD binary file for initializing SRAM.

<!-- image -->

## CREATE DCD BINARY FOR INITIALIZING SRAM

## At Menu bar, Click ConfigTools - DCD. Then, switched to DCD view.

<!-- image -->

<!-- image -->

## CREATE DCD BINARY FOR INITIALIZING SRAM.

<!-- image -->

<!-- image -->

## CREATE DCD BINARY FOR INITIALIZING SRAM.

<!-- image -->

<!-- image -->

## CREATE DCD BINARY FOR INITIALIZING SRAM.

<!-- image -->

<!-- image -->

## CREATE DCD BINARY FOR INITIALIZING SRAM.

<!-- image -->

<!-- image -->

## CREATE DCD BINARY FOR INITIALIZING SRAM.

<!-- image -->

<!-- image -->

## CREATE DCD BINARY FOR INITIALIZING SRAM.

<!-- image -->

<!-- image -->

NP

## CREATE DCD BINARY FOR INITIALIZING SRAM.

<!-- image -->

<!-- image -->

## LOAD CREATED DCD FILE

<!-- image -->

Load built binary as application boot code image. And create blob image.

<!-- image -->

## LOAD THE CONVERTED BIN FILE AS APPS BOOT CODE.

In the IVT view of S32DS 3.4, load the can\_routing.bin as an apps bootloader.

<!-- image -->

## AUTOMATIC ALIGN

<!-- image -->

## EXPORT BLOB IMAGE.

<!-- image -->

<!-- image -->

## Write the blob image on the SD card.

<!-- image -->

## WRITE THE EXPORTED IMAGE TO SD CARD

## Use Win32DiskImager to write image to SD CARD

<!-- image -->

PUBLIC

<!-- image -->

<!-- image -->

## How to develop DEMO setup 2/3 for RDB2

<!-- image -->

<!-- image -->

## Preparation

<!-- image -->

PUBLIC

1 4 5

## DOWNLOAD LINUX BSP27 AND CREATE BOOTABLE SD CARD

## Visit Flexera :

Automotive SW - S32G2 - LLCE Driver + Firmware &gt; Automotive SW - S32G2 - Linux BSP &gt; S32G274\_LinuxBSP27.0.0

<!-- image -->

<!-- image -->

## DOWNLOAD LINUX BSP27 AND CREATE BOOTABLE SD CARD

## Untar and unzip the downloaded file. Then, find directory 's32g274ardb2'

<!-- image -->

<!-- image -->

## Modify App codes based on demo setup 1

<!-- image -->

PUBLIC

1 4 8

## MODIFY MAIN.C

1. Copy demo setup 1 project folder and rename (e.g. 'demo\_setup\_2\_3')

## 2. Edit  S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\

<!-- image -->

<!-- image -->

## MODIFY LINKER FILE

Edit S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\build\_files\src\ghs\ sample\_app\_linker\_file.ld

## Original

## Modified

<!-- image -->

<!-- image -->

## MODIFY SYS\_INIT.C

## Edit  S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\clock\src\sys\_init.c

<!-- image -->

<!-- image -->

## MODIFY S32G\_I2C.H

## Edit  S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\ioexpander\include\s32g\_i2c.h Add following definition.

| #define I2C_IBCR_MSSL_MASK #define I2C_IBCR_MSSL_SHIFT #define I2C_IBCR_MSSL(x) #define I2C_IBCR_TXRX_MASK #define I2C_IBCR_TXRX_SHIFT #define I2C_IBCR_TXRX(x) #define I2C_IBSR_IBB_MASK #define I2C_IBSR_IBB_SHIFT #define I2C_IBSR_IBIF_MASK #define I2C_IBSR_IBIF_SHIFT #define I2C_IBSR_IBIF(x) #define I2C_IBSR_TCF_MASK #define I2C_IBSR_TCF_SHIFT #define I2C_IBSR_RXAK_MASK #define I2C_IBSR_RXAK_SHIFT   | (0x20U) (5U) (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_MSSL_SHIFT)) & I2C_IBCR_MSSL_MASK) (0x10U) (4U) (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_TXRX_SHIFT)) & I2C_IBCR_TXRX_MASK) (0x20U) (5U) (0x2U) (1U) (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBIF_SHIFT)) & I2C_IBSR_IBIF_MASK) (0x80U) (7U) (0x1U) (0U)   |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|

<!-- image -->

## MODIFY S32G\_I2C.C

```
Edit  S32G2XX_LLCE_GATEWAY4_4_1_0_0_Sample_Application\platform_common\ioexpander\src\ S32g_i2c.c Demo setup 1 Modified Use operator '.' instead of arrow operator. Use data type 'uint8_t' instead of 'uint8' I 1 00016 void i2c_0_init（void） 00016 void i2c_0_init(void) 00017 00017 00018 s32g_i2c_0_siul(); 00018 s32g_i2c_0_siul(); 00019 /xI2Cdisable*/ 00019 /*I2C disable */ 00020 I2C_0->IBCR = 0x80; 00020 I2C_0.IBCR.R = 0x80; 00021 /* SetI-Bus clock rate */ 00021 /*SetI-Bus clock rate*/ 00022 I2C_0->IBFD = 0x33; 00022 I2C_0.IBFD.R = 0x33; 00023 /* I2C enable, Disable interrupt */ 00023 /* I2C enable，Disable interrupt */ 00024 I2C_0->IBCR = 0x00; 00024 I2C_0.IBCR.R = 0x00; 00025 00025 00026 00026 00027 00027 00028 00028 00029 void s32g_i2c_0_siul(void) 00029 void s32g_i2c_0_siul(void) 00030 00030 00031 00031 00032 SIUL2_0->MSCR[31] = 0x383022; //0BE = 1， 0DE = 1， IBE = 1， SSS = 0x 00032 SIUL2_0.MSCR[31].R = 0x383022;//0BE = 1， 0DE = 1， IBE = 1， SSS = 0x 00033 SIUL2_0->IMCR[53] = 0x03; 00033 SIUL2_0.IMCR[53].R = 0x03; 00034 00034 00035 SIUL2_0->MSCR[32] = 0x383021; 00035 SIUL2_0.MSCR[32].R = 0x383021; 00036 SIUL2_0->IMCR[54] = 0x03: //SSS = 0x2; 00036 00037 00037 00038 00038 00039 00039
```

<!-- image -->

## MODIFY S32G\_I2C.C

Edit  S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\ioexpander\src\

S32g\_i2c.c

Use operator '.' instead of arrow operator. Use data type 'uint8\_t' instead of 'uint8'

## Demo setup 1

```
nnn 00040 /* Helper functions for hw access */ 00041stat ic inl ine void I2C_Set_ModuleModSelect (uint8 moduleType) 00042 uint8 regValue = (uint8) I2C_0->IBCR; 00043 regValue &= (uint8) ((I2C_IBCR_MSSL_MASK)); 00044 regValue=I2C_IBCR_MSSL(moduleType); 00045 I2C_0->IBCR = (uint8) regValue; 00046 00047 static inline void I2C_Set_ModuleTransmitMode(uint8 enable) [ 00048 uint8 regValue = (uint8) I2C_0->IBCR; 00049 regValue &= (uint8) ((12C_IBCR_TXRX_MASK)); 00050 regValue=I2C_IBCR_TXRX(enable); 00051 I2C_0->IBCR = (uint8) regValue; 00052 00053 00054 static inline uint8 I2C_Get_BusBusyEvent (void){ 00055 uint8 regValue = (uint8) I2C_0->IBSR; 00056 regValue=（regValue &I2C_IBSR_IBB_MASK)>>I2C_IBSR_IBB_SHIFT; 00057 return (uint8) regValue; 00058 00059 static inline uint8 I2C_Get_BusInterruptFlag(void) 00060 00061 uint8 regValue = (uint8) I2C_0->IBSR; 00062 regValue = (regValue & I2C_IBSR_IBIF_MASK) >> I2C_IBSR_IBIF_SHIFT; 00063 00064 return (uint8) regValue; 00065
```

## Modified

```
00040 /* Helper functions for hw access */ 00041stat ic inl ine void I2C_Set_ModuleModSelect (uint8_t moduleType) [ 00042 uint8_t regValue = I2C_0.IBCR.R ; 00043 regValue &= (uint8_t) (~(I2C_IBCR_MSSL_MASK)); 00044 regValue=I2C_IBCR_MSSL(moduleType); 00045 I2C_0. IBCR.R = (uint8_t) regValue; 00046 00047 stat ic inl ine void I2C_Set_ModuleTransmitMode(uint8_t enable) [ 00048 uint8_t regValue = I2C_0.IBCR.R ; 00049 regValue &= (uint8_t) (~(I2C_IBCR_TXRX MASK)); 00050 regValue=I2C_IBCR_TXRX(enab|e); 00051 I2C_0.IBCR.R = (uint8_t) regValue; 00052 00053 00054 static inline uint8_t I2C_Get_BusBusyEvent (void) [ 00055 uint8_t regValue = I2C_0.IBSR.R : 00056 regValue =(regValue &I2C_IBSR_IBB_MASK) >>I2C_IBSR_IBB_SHIFT; 00057 return (uint8_t) regValue; 00058 00059 stat ic inl ine uint8_t I2C_Get_BusInterruptFlag(void) 00060 00061 uint8_t regValue = I2C_0.IBSR.R ; 00062 regValue = (regValue & I2C_IBSR_IBIF_MASK) >> I2C_IBSR_IBIF_SHIFT; 00063 00064 return (uint8_t) regValue; 000651
```

<!-- image -->

## MODIFY S32G\_I2C.C

Edit  S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\ioexpander\src\

S32g\_i2c.c

Use operator '.' instead of arrow operator. Use data type 'uint8\_t' instead of 'uint8'

Use data type 'bool' instead of 'boolean'

## Demo setup 1

<!-- image -->

## Modified

<!-- image -->

<!-- image -->

## MODIFY S32G\_I2C.C

Edit  S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\ioexpander\src\ S32g\_i2c.c Use operator '.' instead of arrow operator.

## Demo setup 1

## Modified

```
00099 uint8_t i2c_0_start(uint8_t addr) 00100 00101 /* Enter transmit mode */ 00102 I2C_Set_ModuleTransmitMode(1); 00103 /* generates a START signal on the bus and selects the master mode */ 00104 I2C_Set_ModuleModSelect (1); 00105 00106 /* Check condition，as a START signal is detected， IBB is set */ 00107 whi le(!(12C_Get_BusBusyEvent())); 00108 00109 /* Transmit slave address, slave here = EEPROM */ 00110 I2C_0.IBDR.R = addr; 00111 00112 /* Check if byte transfer is complete */ 00113 whi le(!(I2C_Get_BusInterruptFlag())); 00114 00115 /* Clear the IBIF flag */ 00116 I2C_Clear_BusInterruptFlag(); 00117 00118 /* Check the falling edge of the 9th clock of a byte transfer(indicat: 00119 whi le(!(12C_Get_TCF())）; 00120 /x Check if the acknowledgment is received from the slave */ 00121 whi le(I2C_Get_ReceivedACK()); 00122 00123 00124 return 1; 00125 1
```

<!-- image -->

```
00099 uint8_t i2c_0_start(uint8_t addr) 00100 00101 /*Enter transmit mode */ 00102 I2C_Set_ModuleTransmitMode(1); 00103 /米 generates a START signal on the bus and selects the master mode *, 00104 I2C_Set_ModuleModSelect (1); 00105 00106 /* Check condition,as a START signal is detected，IBB is set */ 00107 whi le(!(I2C_Get_BusBusyEvent())); 00108 00109 /* Transmit slave address， slave here = EEPROM */ 00110 I2C_0->IBDR = addr; 00111 00112 /xCheck if byte transfer is complete */ 00113 whi le(!(I2C_Get_BusInterruptFlag())); 00114 00115 /* Clear the IBIF flag */ 00116 I2C_Clear_BusInterruptFlag(); 00117 00118 /* Check the falling edge of the 9th clock of a byte transfer(indica 00119 whi le(!（I2C_Get_TCF())); 00120 /* Check if the acknowledgment is received from the slave */ 00121 whi le(I2C_Get_ReceivedACK()); 00122 00123 00124 return 1; 00125 1
```

## MODIFY S32G\_I2C.C

```
Edit  S32G2XX_LLCE_GATEWAY4_4_1_0_0_Sample_Application\platform_common\ioexpander\src\ S32g_i2c.c Use operator '.' instead of arrow operator.
```

## Demo setup 1

```
00127/** 00128 @brief Send one byte to I2C device 00129 @param databyte to be transfered 00130 @retval 0 write successful 00131 @retval 1 write failed 00132 */ 00133 uint8_t i2c_0_write(uint8_t Port_value) 00134 00135 00136 I2C_0->IBDR = Port_value; 00137 delay(S32G_I2C_TEST_DELAY_COUNTER); 00138 /* Check if byte transfer is complete */ 00139 while(!(I2C_Get_BusInterruptFlag())); 00140 /*Clear the IBIF flag */ 00141 I2C_Clear_BusInterruptFlag(）; 00142 /* Check the falling edge of the 9th clock of a byte transfer(indica 00143 whi le（!(I2C_Get_TCF（))); 00144 /* Check if the acknowledgmentis received */ 00145 whi le(I2C_Get_ReceivedACK()); 00146 00147 return 0; 00148 1A
```

## Modified

```
00127** 00128 @brief Send one byte to I2C device 00129 @param databyte to be transfered 00130 @retval 0 write successful 00131 @retval 1 write failed 00132 */ 00133 uint8_t i2c_0_write(uint8_t Port_value) 00134 00135 00136 I2C_0.IBDR.R= Port_value; 00137 delay(S32G_I2C_TEST_DELAY_C0UNTER); 00138 /* Check if byte transfer is complete */ 00139 whi le(!(I2C_Get_BusInterruptFlag())); 00140 /* Clear theIBIF flag */ 00141 I2C_Clear_BusInterruptFlag(); 00142 /* Check the falling edge of the 9th clock of a byte transfer(indicat 00143 whi le(!(I2C_Get_TCF())); 00144 /* Check if the acknowledgmentis received */ 00145 whi le(I2C_Get_ReceivedACK()); 00146 00147 return 0; 00148 1A0
```

<!-- image -->

## MODIFY S32G\_I2C.C

Edit  S32G2XX\_LLCE\_GATEWAY4\_4\_1\_0\_0\_Sample\_Application\platform\_common\ioexpander\src\ S32g\_i2c.c Use operator '.' instead of arrow operator.

## Demo setup 1

```
00157 void i2c_0_start_wait(uint8_t addr) 00158 00159 I2C_Set_ModuleTransmitMode(1); 00160 deIay(S32G_I2C_TEST_DELAY_C0UNTER); 00161 /* generates a START signal on the bus and selects the master mode *, 00162 I2C_Set_ModuleModSelect(1); 00163 delay(S32G_I2C_TEST_DELAY_COUNTER); 00164 /* Check condition，as a START signal is detected，IBB is set */ 00165 whi le(!(I2C_Get_BusBusyEvent ())); 00166 00167 delay(S32G_I2C_TEST_DELAY_COUNTER); 00168 /*Write data tobe sent to slave */ 00169 I2C_0->IBDR = addr; 00170 00171 /* Check if byte transfer is complete */ 00172 while(!(I2C_Get_BusInterruptF|ag())); 00173 00174 /* Clear the IBIF flag */ 00175 I2C_Clear_BusInterruptFlag(); 00176 /* Check the falling edge of the 9th clock of a byte transfer(indica 00177 while(!(I2C_Get_TCF())); 00178 00179 /*Checkif the acknowledgmentis received from the slave */ 00180 whi le(I2C_Get_ReceivedACK()); 00181 nn182
```

## Modified

```
00157 void i2c_0_start_wait(uint8_t addr) 00158 00159 I2C_Set_ModuleTransmitMode(1); 00160 delay(S32G_I2C_TEST_DELAY_C0UNTER); 00161 /* generates a START signal on the bus and selects the master mode */ 00162 I2C_Set_ModuleModSelect (1); 00163 delay(S32G_I2C_TEST_DELAY_C0UNTER); 00164 /* Check condition，as a START signal is detected，IBB is set */ 00165 whi le(!(I2C_Get_BusBusyEvent ())); 00166 00167 delay(S32G_I2C_TEST_DELAY_C0UNTER); 00168 /*Write data to be sent to slave */ 00169 I2C_0. IBDR.R = addr; 00170 00171 /* Check if byte transfer is complete */ 00172 whi le(!(I2C_Get_BusInterruptFlag())); 00173 00174 /* Clear the IBIF flag */ 00175 I2C_Clear_BusInterruptFlag(); 00176 /* Check the falling edge of the 9th clock of a byte transfer(indicat 00177 whi le(!(I2C_Get_TCF())); 00178 00179 /*Checkif the acknowledgmentis received from the slave */ 00180 whi le(I2C_Get_ReceivedACK()); 00181 nn182
```

<!-- image -->

## Make

<!-- image -->

PUBLIC

1 5 9

## MODIFY MAKEFILE

<!-- image -->

<!-- image -->

## Bring up Linux integrating LLCE demo app

<!-- image -->

PUBLIC

1 6 1

## COPY THE BIN FILE &amp; PFE CLI APP TO THE LINUX BOOTABLE SD

1. In the windows command prompt, execute following to convert from elf to bin $ objcopy.exe -O binary can\_routing.elf can\_routing.bin
2. 2.Place the converted bin file and the downloaded PFE CLI app (i.e., pfe\_rte) on the Linux bootable SD card .

<!-- image -->

## SETUP FOR SDBOOT AND PC CONSOLE

## Connect host PC and J2 by USB cable.

## Set SW3,4,5,6,7,9,10 to the default position (as below)

<!-- image -->

## Config terminal soft on PC to 115200

bps .

<!-- image -->

<!-- image -->

<!-- image -->

## STOP AT U-BOOT

## 1. Insert the Linux bootable SD card to the RDB2 and power on.

```
U-Boot 2020.04+g6f1223272a (Nov 20 2020 - 09:30:35 +0000) CPU: NXP S32G274A rev. 2.1.0 Reset cause: Power-On Reset Model: NXP S32G27x Board:  NXP S32G274A-RDB DRAM:4GiB CA53 core 1 running. CA53 core 2 running. CA53 core 3 running. All (4) cores are_up. MMC: 'FSL_SDHC: 0 Loading Environment from MMC... OK Using external clock for PCIe0 Configuring PCIe0 as RootComplex(x2) Using external clock for PCIe1 Frequency 125Mhz configured for PCIe1 Configuring PCIe1 as SGMII(x2) [XPCS0 2.5G, XPCS1 0FF] PCIe0: Failed to get link up Pcie0: LINK_DBG_1: 0x00000000, LINK_DBG_2: 0x00000800 (expected 0x000000d1) DEBUG_R0: 0x00f4c600.DEBUG_R1: 0x08200000 PCI: Failed autoconfig bar 1c PCIe1: Not configuring PCIe, PHY not configured In: serial Out : serial Err: serial Net: EQ0S phy: rgmii @ 1 Warning: eth_eqos (eth0) using random MAC address_- aa:25:00:84:f9:a9 eth0: eth_eqos PFE: emac0: sgmii emacl: none emac2: rgmii eth1: eth_pfeng Hit any key to stop autoboot: 0
```

2. Stop booting process at the message 'Hit any key to stop autoboot'

<!-- image -->

## BRING UP U-BOOT AND KERNEL

## 1. Create batch variable for launching demo

- =&gt; setenv llcedemo "initsram 34500000 00100000;load mmc 0:1 0x34500000 can\_routing.bin;startm7 0x34500000;boot"

## 2.Saveenv

3. Boot the kernel and login with root.
4. Move 'pfe\_rte' app from the boot partition to the home directory (/home/root)
5. Edit'/etc/sysctl.conf' to add the following line :

```
# mkdir /media/rfs_tmp # mount /dev/mmcblk0p1/ /media/rfs_tmp # mv /media/rfs_tmp/pfe_rte ~ # rmdir /media/rfs_tmp
```

net.ipv4.ip\_forward=1

- 1 6. Enter sysctl command.

```
1 # sysctl -p
```

<!-- image -->

## Prepare companion PCs

<!-- image -->

PUBLIC

1 6 6

## FOR DEMO SETUP 1

<!-- image -->

Windows10 PC (Demo presenting)

- -Install sigrok pulse view.

( https://sigrok.org/wiki/Downloads )

- Plug in the USB logic analyzer
- Execute Zadig from start menu. And click Install Driver
- -Execute PulseView from start menu.
- Click here and select 'Demo device'
- -Then, click again and select 'Connect to Device'.
- -In the dialog, select fx2lafw and USB interface, Then, click 'Scan for devices using driver above'
- -You will see Salae Logic with 8 channels.
- -Click OK to finish setup.

<!-- image -->

<!-- image -->

<!-- image -->

## INSTALL Logic Analyzer

<!-- image -->

Windows10 PC (Demo presenting)

- -

## INSTALL Wi-Fi camera ap

- Install the Wi-Fi camera app E.g., iVcam

( https://www.e2esoft.com/ivcam/ )

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

1000Base-T

## Setup Ethernet adapter to receive packet from S32G

<!-- image -->

- -Run following command as an administrator.

# route add 192.168.2.0 mask 255.255.255.0 192.168.0.40 -p

PUBLIC

1 6 9

<!-- image -->

Windows10 PC (Demo presenting)

<!-- image -->

1000Base-T

## INSTALL video streaming app

- -Install mjpg-streamer

## $ sudo snap install mjpg-streamer

- -Install UVC driver to enable your web cam which is equipped in your PC.

## $ sudo modprobe uvcvideo

- -Enable mjpg-streamer with UVC camera
- $ sudo snap restart mjpg-streamer
- $ sudo snap connect mjpg-streamer:camera

PUBLIC

1 7 0

<!-- image -->

<!-- image -->

Windows10 PC (Demo presenting)

## INSTALL iperf3

$ sudo apt-get install iperf3

## INSTALL iperf3

<!-- image -->

Ubuntu PC 2 (192.168.0.20) 1000Base-T

$ sudo apt-get install iperf3

INSTALL speed meter app

$ sudo apt-get install speedometer

INSTALL telnet server

$ sudo apt install telnetd

$ sudo apt install inetutils-inetd

$ sudo /etc/init.d/inetutils-inetd start

<!-- image -->

PUBLIC

<!-- image -->

<!-- image -->

## Create 'iperf\_client\_step.sh' as below.

This is the batch file to create traffic increasing on steps

Windows10 PC (Demo presenting)

```
#!/bin/bash iperf3 -c 192.168.0.20 -u -p 15100 -B 192.168.2.20 --cport 10100 -1 1450 -t 3 -b 100H iperf3 -c 192.168.0.20 -u -p 15100 -B 192.168.2.20 --cport 10100 -1 1450 -t 3 -b 300H iperf3 -c 192.168.0.20 -u -p 15100 -B 192.168.2.20 HO09 9- 6 1- 05bT 1- 00T0T 1uod3-iperf3 -c 192.168.0.20 -u -p 15100 -B 192.168.2.20 HO08 9- 6 1- 05b1 1- 00101 1od2-iperf3 -c 192.168.0.20 -u -p 15100 -B 192.168.2.20 --cport 10100 -1 1450 -t 10000 -b 1000H
```

1000Base-T

<!-- image -->

Ubuntu PC 1 (192.168.2.20)

<!-- image -->

Ubuntu PC 2 (192.168.0.20) 1000Base-T

<!-- image -->

<!-- image -->

<!-- image -->

## Setup boards &amp; complete the system

<!-- image -->

## Setup companion boards

<!-- image -->

PUBLIC

1 7 4

## PREPARE BITMAP SENDER/RECEIVER NODES

<!-- image -->

<!-- image -->

Put Arduino LCD shield on the S32K144EVB

1. On S32DS for ARM 2018R1, import 'S32K144EVB\_S32DS2018R1\_CAN\_FD\_LCD\_Demo\_S32G' project .
2. Connect your PC to S32K144EVB via micro-USB cable.
3. Build the project and flash it into S32K144EVB via OpenSDA interface (choose OpenSDA as Interface option at Debugger configuration window)

## Repeat flashing the same binary to these 4 sets of S32K144EVB

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## On sender nodes (i.e., no LCD boards), configure Classic mode.

The sender/receiver project supports both Classic CAN and CANFD. You can choose it by potentiometer knob.

But note that current S32G project and DEVKIT project  supports only Classic CAN.

<!-- image -->

Turn this potentiometer knob to clockwise to choose classic-CAN frame. (Green LED indicates Classic-CAN mode. Blue LED indicates CANFD mode.)

<!-- image -->

## PREPARE SOFTWARE GATEWAY

<!-- image -->

## Put DEVKIT-COMM on the DEVKIT-MPC5748G

<!-- image -->

Download MPC5748G DEVKIT CAN routing demo app. And, flash the elf file (DEMO1\_2CH\_bitmap\_transferGW\Debug\DEMO1\_2C H\_bitmap\_transferGW.elf) via OpenSDA or debuggers (e.g., Lauterbach)

<!-- image -->

## Connection

<!-- image -->

PUBLIC

1 7 8

## DEMO SETUP 1 CONNECTION OVERVIEW

## CAN bus is working on 500 Kbps Classic CAN frame, Data Length =8 bytes

<!-- image -->

S32G-VNP-RDB2

<!-- image -->

## DEMO SETUP 1 WIRE CONNECTION DETAILS

GND

CANL

CANH

VBAT

GND

CANL

CANH

VBAT

S32G

+

S32G-VNP-RDB2

NP

(For Logic analyzer probing) CANRXD

58.740Ckbps]

NP

(For Logic analyzer probing) CANRXD

CAN

58.740Ckbps]

LLCE BCAN0

GND

LLCE\_CAN0\_CANH

LLCE\_CAN0\_CANL

GND

LLCE\_CAN1\_CANH

LLCE\_CAN1\_CANL

LLCE BCAN1

J6 Cable

(For Logic analyzer probing) CANRXD

VBAT

CANH

CANL

GND

GND

CANH

CANL

GND

CANL

12V Power supply

Conventional Software Gateway

R50TP41

T41018-

R16

241

0obR4

-R9

BRS

-R16

-R14

-R31TP10

BR29

SENDER

CANH

(For Logic analyzer probing)

VBAT

CANH

CANL

GND

mb

Bitmop

TP22

A27R2

CANRXD

PUBLIC

USB Power supply

12V Power supply

1 8 0

<!-- image -->

DEVKIT-CO

XN

RECEIVER→

## PIN MAP ( S E NDER/RECEIVER)

## For SWGW/RDB2

<!-- image -->

GND

CANH

CANL

Power supply

Transmission trigger Switch

VBAT

For another S32K board's power supply

RESET Switch

Dsition.

Set J

For Logic Analyzer probe

CAN\_RXD

CAN\_TXD

Turn this potentiometer knob to clockwise to choose classic-CAN frame. (Green LED indicates Classic-CAN mode. Blue LED indicates CANFD mode.)

PUBLIC

1 8 1

<!-- image -->

3

2

1

<!-- image -->

<!-- image -->

## DEMO SETUP 2/3  PC CONNECTION OVERVIEW

<!-- image -->

<!-- image -->

## How to Run the Demo

<!-- image -->

## Run Demo setup 1

<!-- image -->

PUBLIC

1 8 5

## DEMO SETUP 1

4

Windows10 PC (Demo presenting)

reparation: Turn on all companion nodes. Engage wifi camera tep1: Insert SD card for Demo setup 1

Step2: Turn on RDB2

Step3: Push transmission trigger SW for both sender node.

Step4: Capture CAN bus waveform with logic analyzer tep5: Check the result on LCD screen.

<!-- image -->

## Run Demo setup 2

<!-- image -->

PUBLIC

1 8 7

192.168.0.20 is assigned to Ethernet NIC.

3

Windows10 PC (Demo presenting)

1000Base-T

Ubuntu PC 1 (192.168.2.20)

WebCAM is shooting smartphone, which shows driving video.

1000Base-T

Pfe0: 192.168.0.40 Pfe2: 192.168.2.40

Preparation: Turn on all companion nodes.

Engage wifi camera

Turn on all PCs.

Run terminal soft on win10

(115200bps) for Linux console.

2

Step1: Insert the Linux SD card

Step2: Turn on RDB2

pfe2 Step3: Stop at U-boot and enter 'run llcedemo pfe0

1

<!-- image -->

Step4: On S32G console, login the kernel. And enter following command.

<!-- image -->

Windows10 PC (Demo presenting)

1000Base-T

<!-- image -->

Ubuntu PC 1 (192.168.2.20)

<!-- image -->

WebCAM is shooting smartphone, which shows driving video.

<!-- image -->

1000Base-T

192.168.0.20 is assigned to Ethernet NIC.

$ ifconfig pfe0 192.168.0.40

$ ifconfig pfe2 192.168.2.40

Step5: Make sure Ubuntu PC1 is configured to 192.168.2.20 and enter following command.

$ sudo route add -net 192.168.0.0/24 gateway 192.168.2.40

$ ping 192.168.2.40

$ ping 192.168.0.40

$ ping 192.168.0.20

<!-- image -->

Step6: If all ping are passed, enter following command.

$ mjpg-streamer -i "input\_uvc.so -f 30 -r 1280x720 -d /dev/video0" -o "output\_http.so -w /var/snap/mjpg-streamer/42/www"

Step7: open

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## Run Demo setup 3

<!-- image -->

PUBLIC

1 9 1

3

Windows10 PC (Demo presenting)

1000Base-T

Ubuntu PC 1 (192.168.2.20)

Ubuntu PC 2 (192.168.0.20) 1000Base-T

Pfe0: 192.168.0.40

Pfe2: 192.168.2.40

<!-- image -->

<!-- image -->

Windows10 PC (Demo presenting)

<!-- image -->

Ubuntu PC 2 (192.168.0.20)

1000Base-T

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->