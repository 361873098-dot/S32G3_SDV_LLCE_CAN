## TRANSITIONING TO A SAFE AND SECURE ZONAL ARCHITECTURE

S32G Vehicle Network Processor as the Foundation

<!-- image -->

## Automotive E/E Architecture Evolution Paths: Logical and Physical

<!-- image -->

<!-- image -->

## Potential Automotive OEM Architecture Migration Paths → Logical + Physical

<!-- image -->

<!-- image -->

## OVERVIEW

- We're tasked with transitioning legacy to Zonal E/E Architecture
- GuardKnox will assume the role of OEM engineering
- We'll have a workshop with suppliers
- NXP and Green Hills Software

<!-- image -->

BGUARDKNOX

## APPROACH

- WHY … ?
- WHAT … ?
- WHERE … ?
- HOW … ?
- WHEN … ?

<!-- image -->

<!-- image -->

<!-- image -->

BGUARDKNOX

## SCALABILITY WALL

- Too many ECUs
- Too much wiring
- Limited network configurations
- Coupled functionality

## PROBLEMS &amp; CHALLENGES

## INDUSTRY LANDSCAPE

- New propulsion
- New consumer
- New compatitors
- Upcoming regulation

THE AUTOMOTIVE INDUSTRY IS IN THE MIDST OF A PARADIGM SHIFT

<!-- image -->

## ETHERNET BACKBONE -TOPOLOGY OPTIONS

<!-- image -->

STAR TOPOLOGY-LOGICALLAYOUT

## ZONAL ARCHITECTURE DEVICE CLASSES

<!-- image -->

9

9

Proprietary and Confidential   l   www.guardknox.com www.guardknox.com

<!-- image -->

## GOALS

01

## END UP WITH A ZONAL ARCHITECTURE

<!-- image -->

<!-- image -->

- 02 REDUCE COSTS AS FAST AS POSSIBLE
- 03 BACKWARD AND FORWARD COMPATIBLE

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

BGUARDKNOX

## WHICH DEVICE?

## VEHICLE SERVER -ECU REDUCTION

VS.

- Transition to server(s)
- Network agnostic
- Agnostic to physical layout
- Cost reduction for any car
- Scales up / down
- Major impact on cost (engineering)

## MEETS OUR GOALS

## ZONAL GATEWAY -WIRING REDUCTION

- Introduce new gateway(s)
- Changes to backbone
- Depended on physical layout
- Cost reduction for wiring burdened car
- Unclear scaling
- Some impact on cost (material and labour)

## WE ' LL KEEP THAT  IN MIND

<!-- image -->

## OBJECTIVES

## CONSOLIDATED PLATFORM

## DE-FRAGMENT ECO-SYSTEM

## FUTURE PROOF

13

13

Proprietary and Confidential   l   www.guardknox.com www.guardknox.com

- Function = software package
- Stop ordering individual ECUs
- Runtime environments and versions
- Shorten development, certification and integration times
- Single design fits many use cases
- Incremental functionality development

<!-- image -->

## COMMUNALITY

- Powertrain = uC + Interfaces
- Cockpit = uP + uC + Interfaces + GPU
- Connectivity = uP + Interfaces + Wireless
- Body = uP + uC + Interfaces
- Autonomy / ADAS = uP + uC + Interfaces + Vision / GPU
- Battery = uC + Interfaces + PLC / Wireless
- Gateway = uP + uC + Interfaces
- Legacy = uP / uC + Interfaces + ASICs

## SERVER = uP + uC + Interfaces

<!-- image -->

<!-- image -->

BGUARDKNOX

## CONSTRAINTS

- Replace an existing ECU
- Biggest network outreach
- Place to scale

' CENTRAL ' EXISTING ECU → SERVER PLATFORM

<!-- image -->

## GATEWAY ARCHITECTURE

## BLOCK DIAGRAM

<!-- image -->

NETWORK TOPOLOGY (STAR-ISH)

<!-- image -->

<!-- image -->

## GATEWAY TO ZONAL

<!-- image -->

<!-- image -->

## DOMAIN CONTROLLER ARCHITECTURE

BLOCK DIAGRAM

<!-- image -->

NETWORK TOPOLOGY (TREE-ISH)

<!-- image -->

## DOMAIN TO ZONAL

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

BGUARDKNOX

## VEHICLE SERVER 'TEMPLATE'

- Consolidated
- Single SoC
- Software modules
- Mixed criticality
- Safety
- Security
- Scalable
- Clustering
- Device family
- Runtime environments
- Secure (inclusive safety)
- Defense in depth
- Logical / physical isolation

<!-- image -->

<!-- image -->

## REQUIREMENTS

<!-- image -->

<!-- image -->

<!-- image -->

BGUARDKNOX

## S32G is a New Type of Automotive Processor: Vehicle Network Processor

## PROCESSING

Lockstep Microcontrollers Cluster Lockstep Microprocessors Automotive Networks Acceleration Ethernet Packet Acceleration

## SAFETY &amp; SECURITY

ASIL D Functional Safety Support Advanced Hardware Security Engine

<!-- image -->

<!-- image -->

<!-- image -->

## NETWORKING

20 x CAN/CAN FD Interfaces LIN and FlexRay™ Interfaces 4 x Gigabit Ethernet Interfaces PCI Express Gen 3 Interfaces

## APPLICATIONS

Service-oriented Gateway Domain Controller ADAS/AD Safety Controller

Vehicle Compute / Zonal Gateways

<!-- image -->

## S32G Processor Supports Vehicle Architecture Transformation

<!-- image -->

UNFIT TO FUTURE MOBILITY SECURITY AND SCALABILITY ISSUES LEGACY APPROACH |  FLAT

•

· Low bandwidth, one MCU per application

ENABLING SCALABLE GROWTH, CONSOLIDATION AND NEW FEATURES LIKE AUTONOMOUS VEHICLE LOGICAL RESTRUCTURE  |  DOMAINS

· High bandwidth network · Gateway key to communication between domains Domain Controllers for local networking and ECU consolidation

REDUCING WIRING COMPLEXING AND ENABLING THE USER-DEFINED CAR PHYSICAL RESTRUCTURE  |  ZONES

Domains virtualized by SW - enabling high flexibility · Easy enable/disable or update functions

<!-- image -->

•

•

## S32G274A: ASIL D Vehicle Network Processor

## MCUs for realtime processing

## MPUs for apps and services

<!-- image -->

System Peripherals and Interfaces including 2x2 PCI 3.0

## On-the-Fly Secure External Flash Memory

## Functional Safety Design

Embedded Hardware Security with PKI Support

Automotive Networks (CAN/LIN/FlexRay) Hardware Acceleration

Automotive Gigabit Ethernet Hardware Acceleration

<!-- image -->

## S32G Scalable Family Applications*

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## Advanced Service-oriented Gateway, Connected Gateway, AD Domain Controller

Maximum processing performance for services, domain control and communications stacks  Maximum ASIL D performance

## Basic Service-oriented Gateway, Domain Controller

Maximum real-time performance  Application processing for services and domain control

## Ethernet Gateway, Management Controller

Application processing for management and control  Some real-time processing for automotive networking

## Low/Mid-range Gateway, Zonal I/O Controller, Safety Controller

Maximum real-time performance for automotive networking and safety control  No applications processing

*These applications are only for guidance and can vary based on customer requirements.

<!-- image -->

## NXP S32G Reference Design Board Accelerates Development

<!-- image -->

## Carmakers

Proof of concept Benchmarking Vehicle data insights New services deployment

<!-- image -->

## Application Developers

Innovation platform Software development Test and validation Demo showcase

<!-- image -->

## Cloud &amp; Service Providers

Symbiotic compute Over-the-Air (OTA) updates Machine learning deployment Edge service deployment

Accelerating Transformation Across the Automotive Ecosystem

3.62

<!-- image -->

## Mixed-Criticality as an Enabler

- ❑ The main driver is the application landscape
- Domain controllers &amp; vehicle computers
- ADAS/AD Applications
- Gateways
- Modular software deployment
- 'App -store' like software distribution
- ❑ Heterogeneous computing platforms to the rescue
- Require vast middleware packages
- Enable rich connectivity functions
- ❑ Mixed criticality on a single platform is the key

<!-- image -->

<!-- image -->

## Freedom-From-Interference

- ❑ A failure in an element is caused by a fault
- ❑ Faults can have diverse root causes
- Hardware faults -bit flips, erratas, etc.
- Software faults -bugs
- Malicious attacks
- ❑ FFI prevents failures from propagating (cascading)
- Relevant for the safety functions of an ECU
- ❑ FFI is critical for separating mixed-criticality systems
- Prevents failures to cascade from ' lower ' ASIL to ' higher ' ASIL
- Prevents failures to cascade within the same ASIL domain

<!-- image -->

<!-- image -->

## Mixed-Criticality in Action

- ❑ A pre-certified secure microkernel
- Minimal codebase, low footprint, efficient hardware resource usage
- Trusted secure base for separation
- ❑ Least privilege model provides ' containerization '
- Additionally enhanced by virtualization capabilities

<!-- image -->

## Green Hills Software INTEGRITY RTOS

NXP S32G

PacketForwardingEngine

Core 1

Coren

<!-- image -->

Peripherals

## SOFTWARE STACK LAYOUT

- App domain
- Quad A53
- Split/lock
- RTOS
- Hypervisor
- RT domain
- Triple M7
- Lockstep
- RTOS
- Bare metal
- Accelerators
- Network
- Security

<!-- image -->

<!-- image -->

## HARDWARE ENFORCED ISOLATION

- App domain → MMU

- RT domain → MPU

- Interconnect → XRDC

<!-- image -->

<!-- image -->

## CONSOLIDATION: USE CASE

- Runtime
- AUTOSAR Classic
- AUTOSAR Adaptive
- Linux
- Bare metal
- Vendors
- AUTOSAR Classic
- ECU suppliers
- Criticalities
- ASIL-D
- ASIL-B
- QM
- Unspecified

AUTOSAR Classic A (ASIL-D)

Legacy ECUs

AUTOSAR Classic A (ASIL-B)

Linux + AUTOSAR Adaptive (QM)

AUTOSAR Classic B (ASIL-B)

Bare metal (?)

<!-- image -->

## USE CASE IMPLEMENTATION A

- App domain
- Quad A53
- Split/lock
- RTOS
- Hypervisor
- RT domain
- Triple M7
- Lockstep
- RTOS
- Bare metal
- Accelerators
- Network
- Security

<!-- image -->

<!-- image -->

## USE CASE IMPLEMENTATION B

- App domain
- Dual A53
- Split/lock
- RTOS
- Hypervisor
- RT domain
- Single M7
- Lockstep
- RTOS
- Accelerators
- Network
- Security

<!-- image -->

<!-- image -->

## ZONAL GATEWAY

- Re-use gateway + server design
- Optimize case by case

<!-- image -->

<!-- image -->

## UNIFORMITY

- Maximize software re-use
- MCAL / BSP
- Applications
- Guest OS / middleware / eco-system
- Hardware scaling up / down
- Pin compatibility
- Vendor roadmap
- Product / chip family and variants
- Interchangeable parts
- May not need to maintain old ECUs
- May not need to stock up parts for over a decade
- Used car factory options ' retrofitting '
- Vendor complementary peripherals
- Design optimized PMIC, Ethernet switches, transceivers …

<!-- image -->

## CHALLENGES AND PITFALLS

- Cost reduction
- Across entire E/E
- Vehicle lifecycle
- Not a traditional supplier engagement
- Requires expertise - no general solution
- Can ' t spec-out ' make me have zonal '
- DMIPS performance rating
- Accelerators and offloaders are left out
- Today mostly a compiler optimizer benchmark

<!-- image -->

<!-- image -->

BGUARDKNOX

41

## BGUARDKNOX ZONALE/EARCHITECTUREDEMORACKSET-UP

<!-- image -->

<!-- image -->

<!-- image -->

SOFTWARE

<!-- image -->

Proprietary and Confidential   l   www.guardknox.com

## PARTNER MAPPING

<!-- image -->

<!-- image -->

SOFTWARE

KNOX

<!-- image -->

## THANK YOU

Idan Nadav Idan@guardknox.com http://www.guardknox.com

Nikola Velinov Nvelinov@ghs.com http://www.ghs.com

Brian Carlson Brian.Carlson@nxp.com http://www.nxp.com

<!-- image -->