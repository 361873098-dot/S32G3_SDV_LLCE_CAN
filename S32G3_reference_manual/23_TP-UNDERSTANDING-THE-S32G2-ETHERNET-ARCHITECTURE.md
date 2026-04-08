## S32G2 ETHERNET ARCHITECTURE

APRIL 2021 VCNS APPLICATIONS AND SOLUTIONS

<!-- image -->

<!-- image -->

<!-- image -->

## Ethernet IP evolution

<!-- image -->

## BANDWIDTH AND SECURITY TRANSFORM VEHICLE NETWORKS

<!-- image -->

## PAST VEHICLE NETWORKS

- Dominated by classic CAN
- Limited bandwidth / scalability
- No security
- Need for gateway

## FUTURE VEHICLE NETWORKS

- Reduced ECUs and wiring complexity
- Evolving Ethernet (10-100-1000 Mbps+)
- Trusted OEM connectivity
- Service-Oriented architectures
- Higher security beyond EVITA Full
- Context-aware security
- ASIL B → ASIL D functional safety

<!-- image -->

## ADDRESSING VEHICLE NETWORK TRENDS

- ECU consolidation
- Managing multiple high-speed networks
- Ethernet connectivity (Gigabit Ethernet)
- Applications processing for new services
- Connected car and secure OTA updates
- Higher levels of security and safety

## CAN CENTRAL GATEWAY ARCHITECTURE

- Legacy automotive networks
- Typically 3-8 CAN networks
- Typically 1-2 FlexRay™ networks
- Increased bandwidth
- But, small compared to consumer / networking world
- Proprietary protocols for higher bandwidth (e.g., MOST)
- Physical isolation
- Functional domains
- Safety / Non-safety
- Gateway role
- Firewall internal traffic
- Protocol translation

<!-- image -->

<!-- image -->

<!-- image -->

## HYBRID ETHERNET ARCHITECTURE

- Legacy + Ethernet networks
- CAN, FlexRay™ &amp; Ethernet
- High-bandwidth data
- 100 Mbit → 1 Gbit Ethernet
- ADAS and infotainment drive higher data rates
- Improved ECU program time in factory
- Gateway role
- Firewall internal &amp; external
- Efficient protocol translation
- ECU consolidation
- New apps &amp; services

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## ZONAL/CENTRAL COMPUTE ARCHITECTURE

- Central compute + I/O gateways
- No functional domains
- Strategy for vehicle fully owned by central compute
- I/O gateways connect Edge nodes to central compute
- Distributed processing
- Optimize network utilization
- Benefits:
- Network architecture optimised to vehicle topology
- Less wires (less weight, power, cost)

## 'Edge Nodes' e.g., Radar ECU, Powertrain ECU

<!-- image -->

High speed Ethernet network (Mesh/Ring)

Optimised to vehicle topology for reduced wiring

<!-- image -->

<!-- image -->

## Packet Forwarding Engine (PFE) Overview

<!-- image -->

## ETHERNET PACKET FORWARDING ENGINE (PFE)

## Ethernet bandwidth is growing

- 5G Cellular, more ADAS data, more ECUs to program
- Secure Gateway will firewall and route traffic
- Customer concerns: Higher performance needed and lack of Ethernet expertise. Value a SW-enabled, tested, efficient solution
- PFE: Packet Accelerator leveraged from NXP Layerscape products
- Fully offloads Ethernet routing from host CPU

<!-- image -->

## Value Propositions

- Proven solution (in NXP Digital Networking)
- Offloads host processor
- 33% power dissipation of CPU-based alternative

<!-- image -->

## ETHERNET PROCESSING HIERARCHY

Deep Packet Inspection (e.g., IDPS)

Monitor payload of packets to detect unusual patterns

## Flow Switching

208-byte header firewall (e.g., L2/3/4, DOIP, SOME/IP) NAT Translation IPSec Offload

L2/L3 Switching Support for ports at line-rate

<!-- image -->

- Classic networking hierarchy
- Multiple layers to handle different traffic types
- Typ. depends on security requirements
- Example flows:
1. Modem-to-IVI: Both domains 'untrusted', may allow direct connection with minimal firewalling (not impacting vehicle operation)
- -L2/3 Switch could support L2/3 switching
- -May need NAT translation, supported by PFE
2. IVI-to-ADAS: Filter traffic based on specific SOME/IP service ID, may want to support authentication of traffic using IPSEC
- -SOME/IP filter &amp; IPSec offload in PFE
3. Modem-ADAS: May have valid paths, but want to monitor payload to detect if data is in 'unusual' state (i.e., rule based check, or machine learning check)
- -CPU flexibility &amp; high performance required

<!-- image -->

## S32G2 ETHERNET MUXING

- S32G2 supports 4x Ethernet MACs
- 3X integrated with Packet Forwarding Engine (PFE)
- 1X as standalone Ethernet Controller (GMAC)
- S32G2 525FC-BGA supports:
- All 4 MACs can be used in parallel
- Max of 3X RGMII/RMII/MII* interfaces (mux options available for all MACs)
- Max of 4X SGMII interfaces (PFE\_MAC0/1/2, GMAC)

<!-- image -->

## Each RGMII additionally supports RMII &amp; MII (*MII requires additional mux signals in LLCE)

<!-- image -->

*Refer to S32G2 Reference Manual for latest IOMUX summary

<!-- image -->

- PHY interface speed options
- SGMII: 1 Gbps and 100 Mbps
- PFE\_MAC0 also supports 2.5 Gbps
- RGMII: 100 Mbps and 1 Gbps
- MII/RMII: 10 and 100 Mbps

## PFE ARCHITECTURE

<!-- image -->

<!-- image -->

<!-- image -->

## PFE features

<!-- image -->

## S32G2 ETHERNET IP ROUTING ENGINE

- Aim: Accelerate majority of routed packets, with minimal CPU load
- Fast Path / Slow Path concept
- Traffic heavily utilises Fast Path
- Slow Path
- Host CPU
- Control Path &amp; Complex Packet Processing (e.g., DPI)
- Fast Path
- Hardware acceleration
- Heavily pipelined to maximise packet throughput

<!-- image -->

<!-- image -->

## PFE OVERVIEW

- PFE is networking accelerator executing NXP firmware
- Access to host memory space and interaction with host CPUs ( IRQs )
- Access to security services provided by HSE
- Available to LLCE for bus bridging

<!-- image -->

<!-- image -->

## PFE INTERFACES

- Total of 7 available data interfaces
- -4x host
- Independent data interfaces to host CPUs
- Register isolation via XRDC
- Coherency support (A53)
- -3x PFE\_MAC
- Data interface to external world
- SGMII: 1 Gbps, 100 Mbps, PFE\_MAC0 also 2.5 Gbps
- RGMII: 100 Mbps + 1 Gbps
- MII/RMII: 10 Mbps + 100 Mbps
- Ability to classify, modify, prioritize, and distribute ( not only Ethernet ) traffic across all interfaces without host CPU intervention.

<!-- image -->

<!-- image -->

## I N GRESS QOS MANAGEMENT

## Ingress QoS

- Congestion avoidance and malicious flows termination
- Ingress traffic prioritization
- Can be used to offload some IDPS-triggered actions (drops, rate limitation, …)
- Credit-based shaper
- Allows limiting ingress data/packet rate per PFE interface

## · WRED

- Ability to prioritize ingress traffic using table of rules . In case of PFE congestion the WRED starts dropping less significant traffic with probability increasing as the congestion level gets more severe.

## Accept only Reserved frames

Accept all Managed and Reserved frames Drop Unmanaged at high probability

Accept all Managed and Reserved frames Drop Unmanaged at medium probability

Accept all Managed and Reserved frames Drop Unmanaged at low probability

Accept all frames

<!-- image -->

## EGRESS SCHEDULING/SHAPING

- Traffic management unit is passed packets after classification/modification
- It computes next packet to be transmitted
- Each Ethernet port has:
- 8 queues
- Schedulers: PQ, WRR, RR
- Credit based shapers
- Flexible configuration of shapers/schedulers by host software
- Shaping at queue or port level
- Supports multicast of traffic

<!-- image -->

## PFE FOR IDPS

- PFE offers support to aid DoS attack prevention
- capable of recognizing several upper layer protocol fields and taking additional actions in order to support prevention of DoS attacks
- actions for the packet filters can be:
- Discard the packet
- Forward the packet normally
- Send the packet to the host CPU for processing
- Send the packet to the host CPU and also forward it normally
- PFE firmware extensions are also possible to add additional monitors including counter based violations, e.g., detect &gt;100 SYN messages per second
- For more details on PFE firmware extension requests please contact your NXP representative

<!-- image -->

<!-- image -->

## PFE flow

<!-- image -->

## STANDARD APPROACH (SLOW-PATH)

1. Traffic is received
2. Traffic is sent to host CPU for processing
3. Host runs some classification algorithm and decides that given flow shall be forwarded to another node
4. Traffic is modified and sent back to the Ethernet controller to be forwarded
5. Traffic is forwarded

<!-- image -->

<!-- image -->

## ACCELERATED APPROACH (FAST-PATH)

1. Traffic is received
2. PFE runs local classification algorithm and decides what to do with given flow
3. Known traffic is processed and forwarded directly via target interface without host CPU intervention

<!-- image -->

<!-- image -->

<!-- image -->

## Example Use Cases

<!-- image -->

## I P V 4   /   I P V 6   R O U T E R

Host application can change operation mode of a physical interface to IP Router and specify routing rules into routing table using FCI API.

## Example:

- Fast-path routing between PFE\_MAC1 and PFE\_MAC2 and slow-path routing within host CPU
- Once configured, the routing points  and  forward traffic received via PFE\_MAC1 or PFE\_MAC2, which matches a routing table entry, to desired destination interface(s) (PFE\_MAC2 or PFE\_MAC1) while the rest of traffic is sent to default interface (CPU0) where the host software can perform custom, slow-path routing

<!-- image -->

<!-- image -->

## DATAPATH ENDPOINT

- Three hosts can access PFE\_MACs via respective logical interface (pfe0-2)
- CPU1 is running Master driver while CPU0 and CPU2 are running Slave drivers
-  ,  , and  are configurable routing points where PFE decides which interface the traffic received from PFE\_MACn shall be forwarded to
-  ,  ,  are configurable routing points to dispatch traffic received via HIF to respective PFE\_MAC

<!-- image -->

<!-- image -->

## VLAN-aware L2 Bridge

- Ethernet switch
- Interfaces can be assigned to a bridge domain using VLAN
- Traffic is being routed using MAC addresses
- MAC addresses can be learned or statically assigned

## Example:

- 2 bridge domains A and B
- A: CPU0, CPU1, CPUm, PFE\_MAC0, PFE\_MAC1
- B: CPUm, PFE\_MAC2, CPUn
- Traffic in domain A is never visible to domain B but CPUm can act as a cross-domain router and forward traffic between domains (if security rules allow that…)

<!-- image -->

<!-- image -->

<!-- image -->

## PFE software stack

<!-- image -->

## S32G2 NETWORKING STACK

- PFE Firmware
- Ethernet Driver
- FCI (Fast Control Interface)
- Endpoint
- Library

<!-- image -->

<!-- image -->

## S32G2 NETWORKING STACK : FIRMWARE

- Runs on processing engines within the PFE
- Implements soft PFE features
- Main FW for packet classification, routing, modification, and distribution
- Auxiliary FW for IPsec offload and other utility tasks
- Delivered in form of binary files
- Firmware is under full control of NXP and can be modified via software services

<!-- image -->

<!-- image -->

## S32G2 NETWORKING STACK : ETHERNET DRIVER

- Provides data-path functionality, connection with networking stack, and exposes logical interfaces to the host system:
- -Generic low-level PFE platform driver
- HW bring-up, firmware upload
- Monitoring and management
- HIF driver
- -OS-specific part to support portability
- Connection to networking stack
- OS Abstraction Layer
- OS-specific features
- Supports master-slave multi-instance deployment over multiple different CPUs/VMs

<!-- image -->

<!-- image -->

## S32G2 NETWORKING STACK : FCI - FAST CONTROL INTERFACE

- FCI together with LibFCI provides control interface between the HW/FW and user's applications
- IOCTL-like API provided by FCI library
- Allows top-level applications to configure the PFE as well as receive events in opposite direction
- Examples:
- -Assign interfaces to L2 bridge domain, manage static entries, manage VLANs, control learning
- -Manage and monitor L3 routing table entries
- -Configure traffic-to-HIF distribution
- -Configure physical/logical interface properties
- -Configure classification algorithms
- -Configure ingress/egress QoS
- -Get statistics

- …

- Detailed description of FCI API with usage examples can be found within the FCI API Reference document delivered within driver release packages

<!-- image -->

<!-- image -->

## EXAMPLE: FAST PATH IN ACTION

<!-- image -->

| MATCH Criteria (Src IP Addr/Port, Dest IP Addr/Port, Protocol)   |   Route ID |
|------------------------------------------------------------------|------------|
| SADDR: 192.168.1.56, DPORT: 80                                   |        999 |

<!-- image -->

<!-- image -->

## Ethernet security

<!-- image -->

## AUTHENTICATION / ENCRYPTION OVER ETHERNET

<!-- image -->

- Several possibilities for security over Ethernet
- External traffic
- -e.g. to Internet/OEM
- -Internet stds: TLS, IPsec VPN
- Internal traffic
- -Required: Auth + Integrity
- -Optional: Encryption
- -No industry consensus on which layer to protect
- -Balance cost vs protection
- PFE supports IPsec offload to reduce host core utilization
- -Interfaces directly to HSE
- -PFE can pre-filter other secure protocol streams to a specific HIF channel to be handled by a specific host core

<!-- image -->

## PFE IPsec offload

## Example: IPsec ESP tunnel between two interfaces

- PFE\_MAC0 is 'non-secure' and PFE\_MAC1 'secure' interface
- -NonSecure-to-Secure Port: Traffic received via PFE\_MAC0 is classified by routing point  and sent to HSE for encapsulation/encryption if is liable to IPsec processing. Then it is forwarded via PFE\_MAC1 as IPsec traffic. Rest of packets are sent to host for normal processing.
- -Secure-to-NonSecure Port: In opposite direction the routing point  selects traffic liable to IPsec processing and sends it to HSE for decryption/decapsulation. Plain packets are then forwarded via PFE\_MAC0.

<!-- image -->

<!-- image -->

<!-- image -->

GMAC

<!-- image -->

## STANDARD APPROACH (SLOW-PATH)

1. Traffic is received
2. Traffic is sent to host CPU for processing
3. Host runs some classification algorithm and decides that given flow shall be forwarded to another node
4. Traffic is modified and sent back to the Ethernet controller to be forwarded
5. Traffic is forwarded

<!-- image -->

<!-- image -->

## PFE ARCHITECTURE VS GMAC ETHERNET CONTROLLER

<!-- image -->

- -802.1Qbv (Time Aware Scheduling)

<!-- image -->

## GMAC FEATURES

- MII / RMII / RGMII and SGMII interface support
- TSN (AVB) Support
- 802.1Qbu (Pre-Emption) &amp; 802.1Qbv (Time Aware Scheduling)
- IEEE ® 1588 / 802.1AS-Rev
- Hardware assist for:
- -L3/4 Checksum offload
- Rx filtering
- Layer 2 and VLAN
- Layer 3 (IPv4 / IPv6) and layer 4 (TCP / UDP)
- Programmable lookup table for flexible parsing
- Independent Tx and Rx DMA engines

<!-- image -->

<!-- image -->