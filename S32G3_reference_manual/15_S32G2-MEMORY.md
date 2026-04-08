## S32G2 MEMORIES

APRIL 2021

<!-- image -->

PUBLIC

NXP, THE NXP LOGO AND NXP SECURE CONNECTIONS FOR A SMARTER WORLD ARE TRADEMARKS OF NXP B.V. ALL OTHER PRODUCT OR SERVICE NAMES ARE THE PROPERTY OF THEIR RESPECTIVE OWNERS. © 2021 NXP B.V.

<!-- image -->

## MEMORY OVERVIEW

Unlike the previous generation gateway family, the S32G2 has no internal flash

<!-- image -->

<!-- image -->

## MEMORY ARCHITECTURE

<!-- image -->

<!-- image -->

OTA

A-B

SWAP

- Load / Execute
- NVM: Ext. NOR Flash
- Execute: System RAM
- High performance execution path
- CPU to System RAM
- Security built into architecture
- -External = Encrypted + Signed
- -On-the-fly Decrypt + Authenticate
- Built into ext. flash I/F
- Fast secure boot
- Secure RAM and Secure OTP on-chip
- Full OTA support
- -A-B Swap, Overwrite method
- -Non-intrusive firmware updates
- -Customer only pays for OTA memory they require

<!-- image -->

## I N T E R N A L   M E M O R I E S :   S R A M

- Size: 8 MB - made up of 16 x 512KB Blocks
- Each block has independent RAM controller with 128-bit data bus
- Implements ECC on contents (initialized by hardware as triggered by BootROM)
- Uses an Interleaved architecture
- Interleaved on a 64byte boundary
- Transaction splitting and reordering taken care of by FlexNOC - entirely transparent to user

## Advantages of this approach:

- Accesses are shared across all 16 ports - lessening the amount of bottlenecks on single ports
- No need for customer to manually partition code between RAM controllers to optimize for multi master accesses

<!-- image -->

<!-- image -->

## I N T E R N A L   M E M O R I E S :   S TA N D B Y   R A M ,   B O O T R O M

## Standby RAM

- Separate 32 KB block - not part of main SRAM array.
- Clocked at 400 MHz
- 39 bits wide: 32-bit + 7-bit ECC
- Remains powered during standby mode and retains content through functional reset.

## BootROM

- ROM contains NXP boot code
- Executed by HSE core upon boot
- -Not executed at any other time
- Reads fuses/boot pins and configures external memory
- Securely copies software to RAM and begins execution
- Approximately 128 KB

<!-- image -->

## EXTERNAL MEMORY INTERFACES: DRAM

- Memory map contains up to 4 GB
- Upper 2 GB restricted to A53, PCIe and CAAM
- Supports LPDDR4, DDR3L
- Supports x16 and x32-bit DRAM Modules
- DDR3L @ DDR-1600 (800 MHz): x16
- LPDDR4 @ DDR-3200 x16 and x32
- Support for 2x CS
- Supports self-refresh mode in standby
- 3 ports:
- 2x 128-bit wide optimized for BW over latency
- 1x 64-bit optimized for latency critical traffic (M7/DMA)
- Supports burst length of 16 for LPDDR4
- ASIL D

<!-- image -->

## EXTERNAL MEMORY INTERFACES: DRAM

## • Supports Inline ECC:

<!-- image -->

<!-- image -->

## DRAM CONTROLLER: INLINE ECC (WRITE)

- DRAM address space will be split into 8 regions for each DRAM channel
- Each region can separately enable inline ECC
- The 8 th region is used for ECC storage and becomes unavailable for application
- Write example to ECC region - 8 data bursts will fill one additional ECC burst
- Read access to ECC enabled region

<!-- image -->

## DRAM CONTROLLER: INLINE ECC (READ)

<!-- image -->

<!-- image -->

## EXTERNAL MEMORY INTERFACES: QUADSPI

- Memory Mapped (512 MBytes)
- Single QSPI module supports A and B interface (dual flash).
- All AHB accesses to flash devices are directly memory mapped to the chip system memory.
- Flexible sequence engine to support various flash vendor devices.
- Single, dual, quad and octal modes of operation
- There is no set standard for QuadSPI protocol. S32G2 supports:
- Cypress HyperFlash
- Macronix Octa Flash
- Micron Octal Flash

|           | QSPI_A             | QSPI_B                                        |
|-----------|--------------------|-----------------------------------------------|
| I/O       | 1.8V (dedicated)   | 1.8V or 3.3V (shared with SDHC)               |
| Max Speed | 200 MHz (400 MB/s) | 1.8V: 133 MHz (266MB/s) 3.3V: 66 MHz (66MB/s) |

<!-- image -->

## EXTERNAL MEMORY INTERFACES: QUADSPI

<!-- image -->

Figure 43.OCTA Read Mode Sequence (DTR-OPI Mode)

| Cypress HyperFlash   |
|----------------------|

<!-- image -->

## EXTERNAL MEMORY INTERFACES: SDHC

- Supports SD and eMMC
- No support for raw NAND
- eMMC has higher max bandwidth
- SD high speeds requires the supply voltage to begin at 3.3V and then switch to 1.8V.
- SD likely to be used for development only - eMMC is main use case.
- Supports latest HS400 and Enhanced HS400
- Supports 1-bit / 4-bit SD and SDIO modes, 1-bit / 4-bit / 8-bit MMC modes

| Name           | Data Rate   | I/O Voltage   | CLK Freq   | Max Data Rate   |
|----------------|-------------|---------------|------------|-----------------|
| Legacy         | SDR         | 3.3V / 1.8V   | 26 MHz     | 26 MB/s         |
| High Speed SDR | SDR         | 3.3V / 1.8V   | 52 MHz     | 52 MB/s         |
| High Speed DDR | DDR         | 3.3V / 1.8V   | 52 MHz     | 104 MB/s        |
| HS200          | SDR         | 1.8V          | 200 MHz    | 200 MB/s        |
| HS400          | DDR         | 1.8V          | 200 MHz    | 400 MB/s        |

<!-- image -->

## USE CASES: QUADSPI VS EMMC

| Feature                      | QuadSPI   | eMMC     |
|------------------------------|-----------|----------|
| Cost                         | Medium    | Cheaper  |
| Standby Current (CS Release) | 55 uA     | 150 uA   |
| Deep power down              | 2 uA      | 110 uA   |
| Deep power down exit time    | 30 uS     | 6.5 mS   |
| Power up time                | <300 uS   | 1001 mS! |
| Compatible with OTC?         | Yes       | No       |

Customers with external DRAM will typically use eMMC and copy full application at boot.

If A53/DRAM not required, then QuadSPI is preferred due to memory mapping.

<!-- image -->

## USE CASES

<!-- image -->

<!-- image -->

<!-- image -->