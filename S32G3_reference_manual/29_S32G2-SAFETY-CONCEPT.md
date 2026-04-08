## S32G2 SAFETY CONCEPT

APRIL 2021

<!-- image -->

PUBLIC

<!-- image -->

<!-- image -->

## AGENDA

- Introduction
- System Solution
- Safety and Availability Concept
- Boot
- Cores
- Safety and Security
- Contacts and Support

<!-- image -->

## Introduction

<!-- image -->

PUBLIC

2

## AUTOMOTIVE GLOBAL MEGATRENDS DRIVING THE NEED FOR NEXT GENERATION SILICON CAPABILITIES

Autonomy

<!-- image -->

Electrification

<!-- image -->

Target: Zero Accidents Safe and Secure Mobility

Connectivity

<!-- image -->

<!-- image -->

## EVOLVING VEHICLE ARCHITECTURE

S32G2 targets gateway and domain controller applications

<!-- image -->

<!-- image -->

<!-- image -->

## EVOLVING VEHICLE ARCHITECTURE

S32G2 targets gateway and domain controller applications

<!-- image -->

<!-- image -->

SENSE

THINK

ACT

## ELEMENTS OF A SAFE SYSTEM

<!-- image -->

<!-- image -->

<!-- image -->

SOTIF: Safety of the intended functionality

<!-- image -->

## WHAT IS FUNCTIONAL SAFETY?

Functional safety is the absence of unreasonable risk due to hazards caused by malfunctioning behavior of electrical or electronic systems

Demonstrate freedom from negligence in case of product liability

<!-- image -->

<!-- image -->

## SAFE DEVELOPMENT PROCESS EVOLUTION

<!-- image -->

<!-- image -->

## FUNCTIONAL SAFETY MARKET TRENDS

<!-- image -->

## Safety Concept

- The target applications can be characterized as requiring
- High performance
- High level of safety integrity (ASIL B to ASIL D)
- High level of availability
- Fault detection and reaction
- ASIL B to ASIL D, safe state transition controlled by independent HW
- Fault recovery
- Enable application fault reactions (localize, recover, restart)
- Degraded mode
- Enable application safe stating (localize, safe state)

<!-- image -->

## TOP LEVEL SAFETY TARGETS FOR S32G2

<!-- image -->

)   │

Comprehensive safety collateral

<!-- image -->

## I S O   2 6 2 6 2 : 2 0 1 8   E D I T I O N   2

- -BCaM7 Release 3.3 updated to ISO 26262: 2018
- -S32G2 will be completed compliant to the new standard

<!-- image -->

<!-- image -->

<!-- image -->

## S32G2 KEY DIFFERENTIATORS FOR SAFETY

## · Highest performance ASIL D in the industry

- S32G2 scales from 3.9 - 8.5 KDMIPS of ASIL D performance making it the processor of choice for autonomous central compute safety processing.

## · Scalability in ASIL B &amp; D Processing

- Ability to run A53 performance cores in decoupled mode (4 cores) for 9.2 KDMIPS ASIL B performance or in lockstep for 4.6 KDMIPS. Plus, potential for safety by SW prototype solution which aims to deliver 9.2 KDMIPS ASIL D performance (not yet production ready).

## · Ideal for Gateway and Safety Domain Controller applications

- The combination of connectivity (Ethernet, PCIe, CAN) and ASIL B / ASIL D safety integrity makes S32G2 the ideal solution for Autonomous system domain controller executing vehicle plans

## · System Solution

- Faster time to market for customers when using S32G2, VR5510 PMIC and SAF Safety SW all developed ISO 26262 compliant ASIL D

## · Development process compliant with ISO 26262:2018

- NXP BCaM development process is already certified since September 2019 for HW and SW with ISO 26262:2018

<!-- image -->

## System Solution

<!-- image -->

PUBLIC

1 3

## SYSTEM SAFETY SOLUTION

## Standard Safety

- Concept across

16FFC

- System Solution
- SW Safety Library
- MCU
- SBC
- Application interface to safety concept through SW Safety Library

<!-- image -->

<!-- image -->

## S32G2 Safety HW &amp; SW

## SYSTEM SAFETY SOLUTION

## • VR5510

- -Independent Safety Monitoring Unit (iSMU) - ASIL B to ASIL D system solution
- -Voltage monitoring with individual UV/OV thresholds and filtering time configuration
- -Integrated windowed WD - Simple or Challenger
- -MCU HW failure monitoring (FCCU)
- -End to End communication protection (8 bits CRC) with M7-0 safety core
- -Analog and Logical BIST
- -Safety Output to transition system in safe state with short to high detection
- -Safety measures to manage transient failures (bit flips)
- -Safety reaction to faults fully configurable

## · S32G2

- -High level of safety integrity (ASIL B to ASIL D)
- -Safe state transition controlled by independent HW - FCCU
- -Master Safety Core to safe boot, self tests and fault handling
- -Fault Injection HW to support safety mechanisms tests
- -MBIST / LBIST to detect permanent faults (start-up tests or fault localization during fault recovery)
- -Delayed Lockstep Cores or Safety by Software to reach ASIL D
- -Independent watchdog per core
- -Safe Interconnect fabric and memory region protection
- -ECC protected memories

<!-- image -->

<!-- image -->

## S32G2 SOFTWARE ENABLEMENT BY QUALITY PROCESS

<!-- image -->

RTOS

<!-- image -->

## SAFETY SOFTWARE (SAF)

- Safe Boot SW to check the MCU fault status during Boot and determine how to start (Normal mode, Degraded mode, no start possible, retry with a reset) and configure the MCU for safety function execution.
- Check the checker SW to test safety mechanisms typically using fault injection tests. These are nondestructive tests (no reset required to continue).
- Memory Fault Reporting SW to manage the fault reporting from on chip memories.
- Fault Handler SW to manage the reaction from each fault signaled to the FCCU.
- MBIST Manager SW to manage the execution and result analysis of MBIST.
- LBIST Manager SW to manage the execution and result analysis of LBIST.
- Fault Recovery SW to manage the overall recovery flow from the point the fault is indicated to the decision whether to continue in Normal mod or a Degraded mode.
- Safety by Software SW to monitor the execution of performance cores in conjunction with the Safety by SW hardware IP and achieve the maximum level of performance and safety.
- Structural Core Self-Test SW to test performance cores during run time.  (Provided separately from SAF.)

<!-- image -->

## S32G274A HARDWARE SAFETY FEATURES

## Decoupled or Lockstep A53 Cores and INTC ECC on Memories

<!-- image -->

Redundant use of IO Application Checks

<!-- image -->

## SAFETY HARDWARE

- Independent Fault handling in HW (FCCU and RGM) to manage the reaction to all faults detected by on chip safety mechanisms and move the system to a safe state.
- Master Safety Core to manage all the safety SW including safe boot, check the checker tests, fault handling, MBIST/LBIST manager, fault recover and safety by SW firmware.
- Fault Injection HW to support check the checker tests to detect failures in safety mechanisms.
- MBIST to detect permanent failures in SRAM either during start-up or from application SW or as part of fault recovery flow to localize faults.
- LBIST to detect permanent failures in digital logic either during start-up or from application SW or as part of fault recovery flow to localize faults.
- HW Delayed Lockstep Cores to detect failures in general purpose cores.
- Safety by Software HW to support the Safety by SW performance core monitoring and achieve the maximum level of performance and safety.
- Watchdog HW per core to support watchdog function for each core.
- HW Delayed Lockstep Interrupt Controllers to detect failures in interrupt controllers.
- HW Delayed Lockstep DMAs to detect failures in DMA engines.
- Safe Interconnect to detect data, address and control failures in the interconnect fabric.
- Memory Region Protection HW to protect the address space from incorrect accesses and to safeguard the separation of safety related and non-safety related SW execution.
- SRAM ECC to detect failures in SRAM memories.
- Flash ECC to detect failures in Flash memories.
- DRAM ECC to detect failures in DRAM memories.
- Power supply monitors to detect failures in safety related power supplies.
- Clock monitors to detect failures in safety related clocks.
- External SBC to monitor the MCU, detect failures in the power supply and manage the safe state of the system in conjunction with the MCU fault detection mechanisms.

<!-- image -->

## TOP LEVEL SAFETY REQUIREMENTS FOR S32X PLATFORM

- The MCU itself is developed as a SEooC to provide the MCU functionalities with appropriate assumed safety integrity ASIL D
- Fault Tolerant Time Interval
- -FTTI MCU = 100 ms or 10 ms (Gateway: 100 ms, Safety Controller: 10 ms)
- Multiple Point Fault Detection Interval
- -MPFDIMCU= Defined by application
- To detect multiple-point faults in the most critical MCU safety mechanisms , software-initiated fault injection tests can be periodically triggered within the FTTI.

- SPFM: 99% (transient and permanent)

- LFM: 90% (permanent faults)

- PMHF: 10-9 h-1 (10% of the system target for ASIL D (&lt;10-8 h-1))

PMHF: Probabilistic Metric for Random Hardware Failures

<!-- image -->

## I S O  26262  - LATENT FAULT METRIC (LFM)

- The requirements from ISO 26262-5 for Latent Fault Metric are shown in table 5
- Latent Faults exist in two areas of the MCU
1. Safety Mechanisms and their fault reporting path to safe state the system -&gt; Covered by SW Initiated Fault Injection Tests
2. In areas of the chip where faults are transparently corrected, with no indication to the application -&gt; Not applicable for MCU (e.g., SRAM ECC corrections are counted in ERM or IP allowing SW to be notified)

|                     | ASILB   | ASIL C   | ASIL D   |
|---------------------|---------|----------|----------|
| Latent-fault metric | ≥60 %   | ≥80 %    | 290 %    |

<!-- image -->

<!-- image -->

## Safety &amp; Availability Concept

<!-- image -->

PUBLIC

2 2

## S32X SAFETY AND AVAILABILITY CONCEPT

<!-- image -->

<!-- image -->

## SAFETY FRAMEWORK ENABLES CUSTOMER TO FOCUS ON APPLICATION

<!-- image -->

<!-- image -->

## S32X SAF FLOW

<!-- image -->

<!-- image -->

## FAULT REACTIONS - FCCU AND RESETS

- When a fault is routed to the FCCU there are 3 reactions possible to bring the MCU to a safe state :
- -R1 : Alarm interrupt with FCCU timer, if timer expires interrupt and error out asserted (local recovery)
- -R2 : Interrupt and error out asserted (global recovery)
- -R3 : No interrupt, error out asserted and reset (no recovery configured)
- If a fault is Not Safety Related, the FCCU could be configured to the following reactions:
- Fault is disabled, no FCCU reaction
- Interrupt Benefit:

Users can customize FCCU reactions for their respective needs.

<!-- image -->

<!-- image -->

## FUNCTIONAL REGIONS AND DEGRADED MODE

- Safety concept enables fault localization and recovery to degraded mode
- E.g., if permanent fault identified in Sys region, S32G2 cannot boot
- E.g., if permanent fault identified in M7 1, S32G2 can still boot and execute - application disables M7 1
- E.g., if permanent fault identified in A53 1, S32G2 can still boot and execute - application disables A53 1

| Region Description              | Application Functional Permanent Fault   | Recovery                        | DegradedMode   |
|---------------------------------|------------------------------------------|---------------------------------|----------------|
| Modules required to boot        | No                                       | -                               | SYS No         |
| M7cluster 0(Master Safety Core) | No                                       | -                               | CPU0 No        |
| M7cluster 1                     | Yes                                      | Disable M7cluster 1             | CPU1 No        |
| M7cluster 2                     | Yes                                      | Disable M7cluster 2             | CPU2 No        |
| A53cluster 0                    | Yes                                      | Disable A53cluster 0            | CPU3 Yes       |
| A53cluster 1                    | Yes                                      | Disable A53cluster 1            | CPU4 Yes       |
| A53GIC &Concerto                | Yes                                      | Disable A53cluster0&1           | INT Yes        |
| CommonPeripherals               | Yes                                      | Disable CommonPeripherals       | PER No         |
| Device Specific Modules         | Yes                                      | Disable Device Specific Modules | DSM No         |

<!-- image -->

## Boot

<!-- image -->

PUBLIC

2 8

## SAFETY OBJECTIVES DURING BOOT

- When the S32G2 boots, the following actions are taken for safety
- Run MBIST and LBIST
- Integrity check of code before execution
- Test Safety Mechanisms
- Configure device for safety execution (FCCU, safety mechanisms)
- Check complete device safety configuration (STCU, RGM, FCCU, safety mechanisms, module config)
- Exiting boot and ready to execute a safety function the S32G2 SW de-asserts the FCCU outputs and starts to refresh the PMIC watchdog to bring system out of safe state

<!-- image -->

## STANDBY OVERVIEW

- Assumed that Standby is Not Safety Related as used only when vehicle ignition key is removed (i.e. car not driving)
- During Standby majority of S32G2 and PMIC functions are powered down , including fail safe outputs Design is to minimize standby power consumption
- When coming out of Standby the safe boot safety checks executed on S32G2 and PMIC establish the safety context again before executing a safety function
- To enter Standby , S32G2 and PMIC specific sequence and handshake is required, thus ensuring that Standby can only be entered intentionally
- Standby RAM &amp; Fuse configuration on S32G2 is protected with ECC , plus application CRC .
- Suspend to RAM can be used during Standby

<!-- image -->

## Cores

<!-- image -->

PUBLIC

3 1

## S32 - SAFETY ALTERNATIVES FOR MAIN CORES

## HW lock step

<!-- image -->

- Delayed Lock-step
- Fully transparent to SW
- Safe compute platform, enables safety for 'black box' SW
- targets ASIL D
- Fallback to degraded mode in case of a permanent fault

## Performance option

<!-- image -->

- NXP structural core self-test (SCST)
- Executed @runtime on each CPU
- High diagnostic coverage with low performance impact
- Application comparison can be implemented to detect transient faults.
- Targets ASIL B @ full DMIPS (with minimal SW overhead)

## Safety-by-SW

<!-- image -->

- Enable customers to achieve ASIL D with high performance by application monitoring.
- Detects loss of integrity and data error caused by SW and HW faults
- Time Monitored Comparator ( TMC )
- -detects data error (and timing errors)
- -requires a monitoring function
- Timed Multi-Watchdog Processor ( TMWDP )
- operational logical flow errors
- logical timing errors
- -behavioral models as timed state machines

<!-- image -->

<!-- image -->

## STRUCTURAL CORE SELF-TEST (SCST) DEVELOPMENT PROCESS

The RTL-code of the core together with Arm Architecture Manual is examined in detail by NXP. An expert individually analyses the core sub-modules, defines the test patterns, and analytically estimates DC.

<!-- image -->

<!-- image -->

## SBSW FROM HIGH LEVEL

## Safety Monitor may detect fault effects caused by

- HW faults
- SW faults

Common cause faults in the backbone detected by HW mechanisms

## Detected fault effects:

- Lost of Integrity
- Data Error

## Reaction based on fault error type and scope. Scopes:

- Task
- Task group
- OS
- Core
- Microcontroller

<!-- image -->

<!-- image -->

## RECOMMENDED SAFETY CONCEPT A53 ASIL B

- Start-up
- HW: Run MBIST (99% DC stuck-at) and LBIST (90% DC stuck-at) on A53 domain
- SW: Test A53 safety mechanisms using NXP SAF SW
- SW: Check A53 boot configuration for safety using NXP SAF SW

## • Runtime

- HW: ECC / Parity protection on SRAM Cache memories, with SRAM implementation ensures only single bit transient faults (&gt;99% DC)
- HW: GIC Interrupt controller running in lockstep and ECC protected SRAM (99% DC)
- SW: Implement a watchdog using temporal (time-window) and logical monitoring of program sequence
- SW: Each FTTI run NXP A53 Structural Core Self-Test software (permanent faults) (Target 90% DC stuck-at)
- SW: For subset of critical computation, application software reciprocal comparison across cluster 0 and 1 to check plausibility of SW execution (transient faults) (Target 90% DC)

## · External Mechanisms

- The A53 is integrated into an ASIL D compute platform on S32G where the clock, power, buses, MPU, system RAM and DRAM are all architected for ASIL D. This additionally strengthens the overall A53 correct SW execution safety concept.

<!-- image -->

## RECOMMENDED SAFETY CONCEPT A53 ASIL D

## · Start-up

- HW: Run MBIST (99% DC stuck-at) &amp; LBIST (90% DC stuck-at) on A53 domain (optional as all logic is in lockstep)
- SW: Test A53 safety mechanisms using NXP SAF SW
- SW: Check A53 boot configuration for safety using NXP SAF SW

## • Runtime

- HW: Delayed lockstep across cluster 0 and 1 (&gt;99% DC)
- HW: ECC / Parity protection on SRAM Cache memories, with SRAM implementation ensures only single bit transient faults. (&gt;99% DC)
- HW: GIC Interrupt controller running in lockstep and ECC protected SRAM (99% DC)
- SW: Implement a watchdog using temporal (time-window) and logical monitoring of program sequence

## · External Mechanisms

- The A53 is integrated into an ASIL D compute platform on S32G where the clock, power, buses, MPU, system RAM and DRAM are all architected for ASIL D. This additionally strengthens the overall A53 correct SW execution safety concept.

<!-- image -->

## Contacts and Support

<!-- image -->

PUBLIC

3 7

## NXP SAFEASSURE PROGRAM

To support customer to build their safety system, the following deliverables are provided as standard for all ISO 26262 developed products.

## Confidential Information available under NDA

- Safety Manual
- FMEDA
- Safety Assessment Report
- PPAP

## Additional Enablement for S32G2

- S32 Safety Software Framework (SAF)
- VR5510 PMIC

<!-- image -->

<!-- image -->

<!-- image -->

## SAFEASSURE COMMUNITY CUSTOMER SUPPORT FOR FUNCTIONAL SAFETY

<!-- image -->

## SafeAssure Community

Public Space for knowledge distribution and industry-wide news

<!-- image -->

## SafeAssure NDA

Private NDA space for customer to access safety documentation here

<!-- image -->

Community users find answers to their questions and safety documentation requests

## Support

Safety Expert Group composed of Safety Managers and Architects, Field and Application Engineers

<!-- image -->

<!-- image -->