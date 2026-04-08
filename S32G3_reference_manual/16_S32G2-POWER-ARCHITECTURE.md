## S32G2 POWER ARCHITECTURE

APRIL 2021

<!-- image -->

<!-- image -->

## EXAMPLE SYSTEM BOM (HIGH)

<!-- image -->

## Required Supplies:

- S32G-H: 0.8V core voltage, (max ~4W)
- 3.3V/1.8V GPIO
- 1.8V analog logic
- External DRAM:
- LPDDR4 - 1.1V, 1.8V
- DDR3L - 1.35V
- External NOR Flash: 1.8V (opt. 3.3V)
- External NAND Flash: (3.3V or/and 1.8V)
- Ethernet: 3.3V or 1.8V
- PCIe: 1.8V and 0.8V

## VR5510 PMIC for S32G2

- S32G2 Specific supply rails
- Controllable in 6.25 mV steps
- High Voltage Input (Battery, 45-65V DC)
- Low Q current operation in Standby Mode (~40 uA)
- Precision Voltage Monitors on S32G supplies with low voltage detection
- Power Up/Down Sequencing
- Programmable Switching Frequency
- I 2 C communication interface
- Watchdog timer for Run and Low Power Modes
- Over Current &amp; Short Circuit Protection

<!-- image -->

## POWER MODES

<!-- image -->

## S32G2 HARDWARE POWER OPTIONS

<!-- image -->

S32G2 has two power options - either full device is powered or only the standby domain is powered. The PMIC has two separate 0.8V regulators in order to support this:

- Standby domain (requires 0.8V and 3.3V) includes:
- 32K SRAM
- Timer
- Slow IRC (clock)
- 3.3V Wakeup Pads
- RUN Domain contains everything else!
- All cores
- LLCE, PFE
- Memories
- Peripheral
- Etc.
- All context is lost when a domain is powered down

Wakeup sources can be internal e.g.,

- RTC

Or external

- Pin transition on any of 23 pins (e.g., CAN bus activity)

<!-- image -->

## PMIC

<!-- image -->

PUBLIC

4

## VR5510 HV PMIC

## Differentiating Points

- Low Power Mode (40 uA in Key-Off (Standby) mode)
- Directly connected to Battery up to 60 V
- Proven and Robust solution co-developed with MCU. BSP and reference designs provided
- Scalable supply and safety (Fit up to ASIL-B &amp; D )
- Minimize EMC with Spread spectrum, frequency tuning, frequency synchronization and multi-phase operation

## Product Features

- Vin 2.7 V to 60 V
- Vpre: Synchronous Buck, 333 kHz to 2.5 MHz, ext. MOS
- Buck 1 &amp; 2 (Single or Dual-Phase), 3.6A Peak each,
- Buck 3, 3.6A Peak,
- BOOST 4.5 V to 6 V, up to 800 mA, int. MOS
- High Voltage LDO (&lt;15 µA)
- LDO1, configurable 1.1 V to 5 V, up to 400 mA
- LDO2, configurable 1.5 V to 5 V, up to 400 mA (with load switch mode)
- LDO3, configurable 1.5 V to 5 V, up to 400 mA (with load switch mode)
- -40°C to 125°C Operating Ambient Temperature (150°C Tj)
- Safety scalable : QM, ASIL-B, and ASIL-D
- Package : 8x8 mm 56-LD QFN-EP

## Applications

- Gateway
- Infotainment / Cluster / Driver Awareness
- Telematics
- V2X

<!-- image -->

## VR5510 Functional Block Diagram

## HVBUCK

(3.3V TO 5.3V, Ext. MOS, 60mA gate drive current capability)

LDO1

(1.1V to 5V, 400mA)

LDO2

(1.5V to 5V, 400mA)

OTP 1

Power Management

(Flexible Configuration)

BOOST

4.5V to 6V, 800mA)

LDO3

(1.5V to 5V, 400mA)

Low IQ LDO

(0.8V, 1.8V or 3.3V, 10mA)

Voltage Supervisor (up to 7)

Latent Failure checker (ABIST, LBIST)

OTP 2

Fail Safe Engine

BUCK1 (Master/Slave)

(0.4V to 1.8V, 3.6A peak)

BUCK2 (Master/Slave)

(0.4V to 1.8V, 3.6A Peak)

BUCK3 (Independent)

(1V to 4.1V, 3.6A Peak)

## Clock management

External Clock Sync. Spread Spectrum Manual Frequency tuning

## Windowed Watchdog

(Simple &amp; Challenger)

MCU HW Failure monitoring (FCCU, SMU, WDI … )

Safety Outputs

(PGOOD, RSTb, FS0b)

<!-- image -->

Logic &amp; Control I2C, MCU interface Regulator Control Wake inputs

## ISOLATION

Safety Logic &amp; Control Fit for ASIL D I2C Independent Safety Monitoring Unit

## EXAMPLE -COMMON USE CASE NORMAL MODE

## Normal Mode

- ❑ Power Up sequence
- ❑ First: HV Buck (3.3 V)
- ❑ Second: Boost (5 V) : Allowing CAN, Flash and Ethernet supply
- ❑ Others LVBUCK and LDO according OTP configuration
- ❑ VDD Core STDBY supplied by HVLDO connected to LV Buck 1 and 2 (0.8 V) (Purple line)
- ❑ VDD 3P3 supplied from LDO3 in SWITCH mode

<!-- image -->

Power Rail used in this mode

Power Rail not used in this mode

<!-- image -->

## EXAMPLE - COMMON USE CASE STANDBY MODE

## Stand By Mode

- ❑ Standard configuration will switch off : BOOST, LV BUCK and LDO (Orange dotted line)
- ❑ VPRE 3.3 V and HVLDO are still present (Green line)
- ❑ HVLDO connection
- ❑ To LV buck1/2 for normal mode
- ❑ To VPRE for Stdby mode
- ❑ OTP configuration will switch automatically HVLDO from switch mode in normal mode to LDO mode in STDBY mode
- ❑ Load Switch should be connected to VBST if user would like to disable the Ethernet bus in stdby mode (if not needed, it could be connected to HV Buck 3.3 V)
- ❑ Wake up by CAN is available as 3.3 V still present

<!-- image -->

Power Rail used in this mode

<!-- image -->

<!-- image -->

## EXAMPLE - COMMON USE CASE STANDBY MODE WITH DDR REFRESH

## Stand By Mode with DDR Refresh

- ❑ Configuration via I2C allows to keep ON Buck 3 and LDO2 (in this case) in STDBY mode to keep DDR Refresh (Blue line)

<!-- image -->

## PMIC TO S32G2 INTERFACE

<!-- image -->

- WDOG available on PMIC in run and standby mode
- Supply voltages monitored by PMIC
- Standby Entry: I2C message then Standby Mode pin transition
- NXP will deliver reference Software driver

<!-- image -->

## I N T E R FA C E   S I G N A L   D E S C R I P T I O N S

| PMIC Signal           | S32G2 Signal              | Polarity                 | Description                                                                                                                            |
|-----------------------|---------------------------|--------------------------|----------------------------------------------------------------------------------------------------------------------------------------|
| STBY (Input)          | PMIC_STBY_MODE_B (Output) | Active Low               | Asserted by S32G2 when run power domains can be removed. De-asserted when run power domains are required.                              |
| STBY_PGOOD (Output)   | PMIC_VDD_OK (Input)       | Active High              | Asserted (set high) by PMIC when run power domains are turned on. De-asserted (set low) by PMIC when run power domains are turned off. |
| PGOOD (Output)        | POR_B (Input)             | Active High (Open Drain) | Remains de-asserted until PMICs BIST has completed, and all supplies are ready. Is de-asserted on an LVD or HVD event.                 |
| RSTB (bi-directional) | RESET_B (bi-directional)  | Active Low (Open Drain)  | Follows PGOOD signal.                                                                                                                  |
| BUCK1/2-FB (inputs)   | PMIC_SENSE (output)       | Analog                   | 0.8 V Digital supply sense point output to PMIC for low and high voltage detection.                                                    |

<!-- image -->

## Low Power

<!-- image -->

PUBLIC

1 1

## WAKEUP SOURCES

|   WKEUP[n] | Primary Wakeup Function   |
|------------|---------------------------|
|          0 | LLCE_CAN0_RX              |
|          1 | LLCE_CAN1_RX              |
|          2 | LLCE_CAN2_RX              |
|          3 | LLCE_CAN3_RX              |
|          4 | LLCE_CAN4_RX              |
|          5 | LLCE_CAN5_RX              |
|          6 | LLCE_CAN6_RX              |
|          7 | LLCE_CAN7_RX              |
|          8 | LLCE_CAN8_RX              |
|          9 | LLCE_CAN9_RX              |
|         10 | LLCE_CAN10_RX             |
|         11 | LLCE_CAN11_RX             |
|         12 | LLCE_CAN12_RX             |
|         13 | LLCE_CAN13_RX             |
|         14 | LLCE_CAN14_RX             |
|         15 | LLCE_CAN15_RX             |

|   WKEUP[n] | Primary Wakeup Function   |
|------------|---------------------------|
|         16 | LLCE_LIN0_RX              |
|         17 | LLCE_LIN1_RX              |
|         18 | LLCE_LIN2_RX              |
|         19 | LLCE_LIN3_RX              |
|         20 | LLCE_FR_RX_A              |
|         21 | LLCE_FR_RX_B              |
|         22 | LLCE_LPSPI0_RX            |
|         23 | RTC                       |

## Internal Pulls

- Each wakeup pin has an internal pull up or pull-down resistor which can optionally be enabled whilst the device is in standby
- Value ~10K
- Note that this will increase standby current - all standby specs assume that pulls are disabled and external resistors are used.

<!-- image -->

## S32G2 has 24 wakeup sources.

- 23 of these are external pins including comms interfaces
- Any comms pin can also be used as GPIO
- 1 is for the internally generated RTC interrupt

## BOOT FLOW (BOOTROM)

<!-- image -->

The BootROM will be able to detect a standby exit versus a reset event.

- Each wakeup event will have a selectable boot type, either full or lowpower.
- This is implemented via a new register (wakeup type) with a bit for each wakeup source.
- The bootROM checks the wakeup source in the WKUP module and then checks the corresponding bit in the wakeup type register and proceeds with the boot based on its value.

<!-- image -->

## WAKEUP COMPARISON

## Full Boot Wakeup

- No need to load fuses as these are retained in standby logic.
- Not necessary to run BIST.
- Full, secure boot is carried out as per IVT in external flash.
- HSE Firmware is loaded and HSE is enabled.
- Customer Application looks at reset status registers to find if the boot was triggered by a wakeup.
- If so, it evaluates the wakeup source and can access any retained data or code in Standby RAM.

## Low-power Boot Wakeup

- No need to load fuses as these are retained in standby logic.
- Not necessary to run BIST.
- Boot from IVT in Standby RAM.
- DCD records stored in standby RAM (if required).
- No HSE firmware loaded.
- IVT will point to application code in standby RAM.
- Begin executing code from standby RAM.
- Code will execute and then either return to standby or trigger a software reset in order to have a full boot.

<!-- image -->

## WAKEUP USE CASES

## There are 2 typical use cases:

1. API Timer wakeup boots to RAM every 1second to feed watchdog in PMIC and then return to standby mode.
2. Async wakeup from a pin - in this case we should check wakeup register which will state whether to boot to RAM or Flash:
- a) If we boot to RAM then the code can then decide if it can deal with the situation and return to standby, or if it needs a full boot (e.g., if we need to copy and execute the Flash image).
- b) If we boot to flash, then full secure boot is carried out and customer code reads the wakeup registers to deal with the wakeup event.

<!-- image -->

## DRAM SELF REFRESH IN STANDBY

S32G2 also provides the option to support an external DRAM in selfrefresh mode during standby.

Use case: Greatly reduce wakeup time when exiting to POSIX OS as skip the need to copy full image from flash to DRAM.

Power: Requires 1.1 V supply to S32G2 during standby to power required pads. Current draw is minimal

The DRAM chip itself requires 1.1 V and 1.8 V.

<!-- image -->

<!-- image -->

## S32G2 HARDWARE POWER SAVING OPTIONS

<!-- image -->

## Powered Down:

- Everything powered off.
- Power: Zero
- Context: Lost

## RUN:

- Everything powered and running.
- Power: Highest
- Context: Retained

## STOP:

- Everything powered, select cores/module clock gated.
- Power: Medium to high
- Context: Retained

## STANDBY:

- Vast majority of device powered down.
- Power: Minimal (uA range)
- Context: Majority lost

<!-- image -->

## DRAM Self-Refresh

<!-- image -->

PUBLIC

1 8

## DRAM HARDWARE POWER SAVING OPTIONS

<!-- image -->

For most intents and purposes, the DRAM can be considered separately from S32G2

## Powered Down:

- Everything powered off.
- Power: Zero
- Content: Lost

## Full powered mode:

- Everything powered and running.
- Power: highest
- Content: Retained

## Self-refresh:

- Vast majority of device powered down.
- Power: Minimal (single digit mA range)
- Content: Retained

DRAM could be put into self-refresh when S32G2 is in STOP, STANDBY or Powered Down mode.

<!-- image -->

## Other Features

<!-- image -->

PUBLIC

2 0

## THERMAL MONITORING UNIT (TMU)

- Three sensors on device which monitor temperature at separate locations on device
- Thermal diode for production test temperature reference
- Brought out on TMU\_ANODE / CATHODE pins
- When (programmable) threshold is reached:
- Trigger Interrupt
- Send fault to FCCU
- Security Tamper Event Accuracy:

| Symbol   | Text                     |   Min | Typ   | Max   | Unit   | Condition            | Footnote   | Spec Number   |
|----------|--------------------------|-------|-------|-------|--------|----------------------|------------|---------------|
| TERR     | Temperatur esensor error |    -8 |       | 8     | C      | TRANGE = -40Cto85C   |            |               |
| TERR     | Temperatur esensor error |     5 |       | 5     | C      | TRANGE = 85Cto120C   |            |               |
| TERR     | Temperatur esensor error |     3 |       |       | C      | TRANGE = 120Cto 125C | 2          |               |

<!-- image -->

<!-- image -->

## DYNAMIC FREQUENCY SCALING

- DFS is not supported in the hardware sense
- However, it is possible for software to alter the clock speeds whilst the core continues to execute
- Using A53 core as an example:

<!-- image -->

Progressive Clock Frequency Switching - used to ramp clock changes to prevent current spikes. Can be used whilst A53 is executing

<!-- image -->

## DFS USE CASE

A53 is complete asynchronous with rest of platform so clock can be altered with minimal impact.

## By default:

- CORE\_PLL = 2 GHz
- PHI1\_CLK = 1 GHz - this is A53 clock source
- DFS2\_CLK = OFF

If software wishes to reduce frequency, then:

- Configure DFS2\_CLK to desired frequency (e.g., 800 MHz)
- Once locked, setup PCFS to control ramp (if required)
- Use MC\_CGM\_1 mux to change source from PHI1\_CLK to DFS2\_CLK

If further reduction required:

- Cannot change DFS2\_CLK on fly
- Change PHI1\_CLK to /3 giving 667 MHz
- Use MC\_CGM\_1 mux to change source from DFS2 \_CLK to PHI1\_CLK

<!-- image -->

<!-- image -->

## COLLATERAL

- S32G2 Hardware Design Guide
- AN12952 - S32G2 Power Saving Techniques
- Reference Design Board (RDB) Schematics
- VR5510 Design Guidelines

<!-- image -->

<!-- image -->