## S32G2 IPCF Hands On

APRIL 2021 VCNS APPLICATIONS AND SOLUTIONS

<!-- image -->

EXTERNAL USE

<!-- image -->

<!-- image -->

## Agenda

- Introduction
- Underlying HW
- IPCF Architecture
- IPCF Shared Memory Driver
- IPCF Use-Cases
- Hands On

<!-- image -->

## INTRODUCTION

<!-- image -->

EXTERNAL USE

2

## I N T RODUCTION

- Inter-Platform Communication Framework (IPCF) is a subsystem which enables applications, running on multiple homogenous or heterogenous processing cores, located on the same chip or different chips, running on different operating systems (AUTOSAR ® OS, Linux ® , FreeRTOS, etc.), to communicate over various transport interfaces (Shared Memory, etc.).
- Designed for closely distributed embedded systems with low-latency and tiny-footprint.
- Exposes a Zero-copy API for maximum performance, minimum overhead and low CPU load.
- IPCF SW release for S32G2 performs communication over Shared Memory.

<!-- image -->

<!-- image -->

## Underlying HW

<!-- image -->

EXTERNAL USE

4

## UNDERLYING HW

- Message-signaled interrupts (MSIs) are interrupts that are indirectly broadcast to a target core by writing configuration bits in MSCM.
- S32G274A has 3 MSIs for core-to-core interrupts and all the application cores can access these.

<!-- image -->

<!-- image -->

## MSCM - INTER-CORE INTERRUPTS EXAMPLE

- A53\_0 transmit notification is interrupt INT0 and receive notification is INT1

<!-- image -->

<!-- image -->

## IPCF Architecture

<!-- image -->

EXTERNAL USE

7

## I P C F  S YSTEM ARCHITECTURE

IPCF driver contains the following layers:

- Shared memory generic implementation that is HW and OS agnostic
- Queue component implementation used in IPCF driver
- HW abstraction component: abstraction over various HW IP modules (MSCM, INTC …)
- OS abstraction component: OS agnostic API for common OS services

<!-- image -->

<!-- image -->

## IPCF Shared memory driver

<!-- image -->

EXTERNAL USE

9

## I P C F  S HARED MEMORY DRIVER ARCHITECTURE

<!-- image -->

- Zero-Copy architecture
- Performance
- High throughput
- Low CPU load
- Efficient core utilization
- Freedom from interference
- Memory protection
- Different ASIL partitions

<!-- image -->

<!-- image -->

## MANAGED CHANNEL DATA FLOW A53 → M7

The diagram shows data flow from OS1 app to OS2 app, and it is symmetric in the other direction

<!-- image -->

<!-- image -->

## UNMANAGED CHANNEL DATA FLOW A53 → M7

- -Similar to POSIX ShM
- -Each App owns half of the channel memory
- -Apps responsible for memory management and sync
- -Can be used for streaming use-cases
- -It is symmetric in the other direction

<!-- image -->

<!-- image -->

## IPCF Use Cases

<!-- image -->

EXTERNAL USE

1 3

## I P C F USE CASES

- On Multiple homogenous or heterogenous processing cores
- On Multiple homogenous or heterogenous processing cores with multiple instances.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

Note: The MSIs are limited to 3. The below use case is applicable with polling feature which is scheduled to be added in the next IPCF SW release.

<!-- image -->

## I P C F USE CASES

- Use case in Linux

<!-- image -->

<!-- image -->

<!-- image -->

## IPCF Hands-On

<!-- image -->

EXTERNAL USE

1 6

## GETTING THE IPCF SW

- Linux ®
- o IPCF module is built with Yocto from NXP Auto Linux BSP, but can also be built manually, if needed.
- AUTOSAR ®
- o On Flexera, Automotive SW - S32G2 Standard Software → Automotive SW - S32G2 - Inter-Platform Communication Framework
- o Open the latest SW release package, currently latest SW version - D2012
- o Download the installer IPCF\_1.1.0\_D2012.exe
- o As a prerequisite, the S32XX\_AUTOSAR\_OS\_4\_3\_106\_CODEDROP5\_0\_8\_0 for S32G274A would also be required.
- FreeRTOS / Bare-metal
- o On Flexera, Automotive SW - S32G2 Standard Software → Automotive SW - S32G2 - Inter-Platform Communication Framework
- o Open the latest SW release package, currently latest SW version - D2012
- o Download the installer PCF\_1.1.0\_D2012\_updatesite.zip. This is added as module in the S32DS 3.3.
- o For adding FreeRTOS support, install the FreeRTOS version available on Flexera: S32G2 Reference Software → S32G2 - FreeRTOS for Cortex-M7 → S32G2 FreeRTOS 10.3.1 version 0.9.0 → SW32G2\_FreeRTOS\_10\_3\_1\_UOS\_0\_9\_0\_DS\_updatesite\_D2012.zip

<!-- image -->

## RUNNING THE IPCF SW

1. Flash the SD card with the Auto Linux BSP image.
2. Copy the stripped binary (IPCF\_Example\_S32G274.bin) created for CM7 core to the FAT partition on SD-card.
3. Establish a serial connection with the S32G274A board and power it on.
4. Hit any key to stop in the U-Boot console.
5. Disable Data Cache from U-Boot. dcache off
6. Zero-set SRAM shared memory used by both sample apps. initsram 0x34100000 0x700000
7. Load the binary in SRAM to the address specified in the linker file.

fatload mmc 0:1 0x34300000 /IPCF\_Example\_S32G274.bin

8. Start the M7\_0 core. (The argument is the address of the Interrupt Vector defined in the Linker file) startm7 0x34501000
9. Boot Linux. boot
10. Login with root and run Linux sample application. insmod /lib/modules/`uname -r`/extra/ipc-shm-dev.ko insmod /lib/modules/`uname -r`/extra/ipc-shm-sample.ko echo 10 &gt; /sys/kernel/ipc-shm-sample/ping

## Expected Output

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->