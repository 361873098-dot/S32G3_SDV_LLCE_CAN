## S32G2 ETHERNET DEMO ON RDB2

APRIL 2021 VCNS APPLICATIONS AND SOLUTIONS

<!-- image -->

<!-- image -->

<!-- image -->

## S32G-VNP-RDB2

<!-- image -->

## S32G-VNP-RDB2 BLOCK DIAGRAM

<!-- image -->

<!-- image -->

## S32G-VNP-RDB2 BOARD OVERVIEW

## Overview

The S32G-VNP-RDB2 is a compact, highly-optimized and integrated reference design board featuring the S32G Vehicle Network Processor. With its high-performance computing capacity and rich input/output(I/O), this board can provide reference for a variety of typical automotive applications, such as central gateway, domain controller, FOTA, secure key management, smart antenna and highperformance central compute nodes. It offers high levels of compute, real-time network performance, multi-Gigabit packet acceleration and security for new automotive applications.

.

## Technical Highlights:

- Supports service-oriented gateway, vehicle compute and domain controller applications
- Dedicated processing engine for networking and security
- Multiple network interfaces - features 18 CAN/CAN FD and 12 Ethernet ports
- Supports low power mode and multiple wake-up sources
- ISO 26262 support by using safety components

<!-- image -->

<!-- image -->

<!-- image -->

## Packet Forwarding Engine (PFE) Overview

<!-- image -->

## ETHERNET PROCESSING HIERARCHY

Deep Packet Inspection (e.g., IDPS)

Monitor payload of packets to detect unusual patterns

## Flow Switching

208-byte header firewall (e.g., L2/3/4, DOIP, SOME/IP) NAT Translation IPsec Offload

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
3. Modem-ADAS: May have valid paths, but want to monitor payload to detect if data is in 'unusual' state (i.e., rule-based check, or machine learning check)
- -CPU flexibility &amp; high performance required

<!-- image -->

## S32G ETHERNET IP ROUTING ENGINE

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

## IPv4 / IPv6 router

Host application can change operation mode of a physical interface to IP Router and specify routing rules into routing table using FCI API.

## Example:

- Fast-path routing between PFE\_MAC1 and PFE\_MAC2 and slow-path routing within host CPU
- Once configured, the routing points  and  forward traffic received via PFE\_MAC1 or PFE\_MAC2, which matches a routing table entry, to desired destination interface(s) (PFE\_MAC2 or PFE\_MAC1) while the rest of traffic is sent to default interface (CPU0) where the host software can perform custom, slow-path routing

<!-- image -->

<!-- image -->

## S32G Networking Stack

- PFE Firmware
- Ethernet Driver
- FCI (Fast Control Interface)
- Endpoint
- Library

<!-- image -->

<!-- image -->

## S32G Networking Stack: FCI - Fast Control Interface

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

<!-- image -->

<!-- image -->

## PFE Fast Path Demo

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## FCI Overview

<!-- image -->

## FCI - Fast Control Interface

- Available from 2 sources
- Included in the Automotive SW - S32G2 - PFE Driver + Firmware package (0.9.2 not yet available)
- Can be extracted from Linux BSP in yocto
- ▪
- bitbake -e libfci | grep '^S='
- Change to directory pointed to by result of grep to get the following files:
- FCI\_API Reference manual
- doc/FCI\_API\_Reference.pdf
- Required header files
- sw/xfci/libfci/public/   fpp\_ext.h,fpp.h &amp; libfci.h · sw/common/public/pfe\_cfg.h
- FCI library
- sw/xfci/libfci/build/release/libfci.a

```
bitbake libfci
```

<!-- image -->

## FCI - Fast Control Interface

- Refer to the BSP User manual for recommended version of gcc
- Currently the Linaro GCC 9.2.0 toolchain
- Application compilation needs to include header files
- Application linking needs to include libfci.a file

<!-- image -->

<!-- image -->

## FCI - Fast Control Interface

- Typical application flow:
- User calls fci\_open() to get the FCI\_CLIENT instance
- User calls fci\_cmd() to send a command with arguments to the endpoint.
- Endpoint receives the command and performs requested actions.
- Endpoint generates response and sends it back to the client.
- Client receives the response and informs the caller.
- User calls fci\_close() to finalise the FCI\_CLIENT instance.
- fci\_write() and fci\_query() can also be used
- fci\_write() only returns status
- fci\_query() returns status and response data

<!-- image -->

## FCI - Fast Control Interface

- L3 router configuration
- Generate list of next hop addresses for each PFE\_MAC used to route packets
- FPP\_CMD\_IP\_ROUTE + FPP\_ACTION\_REGISTER
- Generate conntracks as required
- FPP\_CMD\_IPV4\_CONNTRACK + FPP\_ACTION\_REGISTER
- FPP\_CMD\_IPV6\_CONNTRACK + FPP\_ACTION\_REGISTER
- Set physical interfaces to FPP\_IF\_OP\_ROUTER mode
- FPP\_CMD\_PHY\_IF + FPP\_ACTION\_UPDATE.
- Enable physical interfaces by setting FPP\_IF\_ENABLED flag
- FPP\_CMD\_PHY\_IF + FPP\_ACTION\_UPDATE
- Modify / delete conntracks
- FPP\_CMD\_IPV4\_CONNTRACK \_ FPP\_ACTION UPDATE or FPP\_ACTION\_DEREGISTER

```
fciStatus = fci_cmd(client, FPP_CMD_IP_ROUTE, (unsigned short *)&fciRouteCmd, sizeof(fciRouteCmd), (unsigned short *)&fciRouteResp, &fciRouteRespLen);
```

<!-- image -->

<!-- image -->