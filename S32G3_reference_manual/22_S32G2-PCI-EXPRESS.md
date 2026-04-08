## S32G2 VEHICLE NETWORK PROCESSOR PCI EXPRESS

APRIL 2021

<!-- image -->

<!-- image -->

## OBJECTIVE

- PCIe Overview
- S32G2 PCIe Features
- S32G2 PCIe Use Cases

<!-- image -->

## PCIe Overview

<!-- image -->

PUBLIC

2

## PCIE PROTOCOL OVERVIEW

- High speed serial transmission protocol
- Packet based
- Serial differential interface
- Each lane has 4 signals: TxP, TxN and RxP, RxN
- Scalable width (# of lanes): x1, x2, x4, x8, x12, x16, x32
- Root Complex (Host) and End Point (Device) modes

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## PCIE PROTOCOL OVERVIEW

- PCIe transactions are defined as a series of one or more packet transmissions required to complete an information transfer between a requester and a completer. Communication involves the transmission and reception of packets called Transaction Layer packets (TLPs).
- PCIe transactions are divided in 4 categories:

| Address Space   | Transaction Type         | Purpose                                                                                          |
|-----------------|--------------------------|--------------------------------------------------------------------------------------------------|
| Memory          | R/W                      | Transfer data to or from a location in the system memory map                                     |
| IO              | R/W                      | Transfer data to or from a location in the system IO map                                         |
| Configuration   | R/W                      | Transfer data to or from a location in the configuration space of a PCI-compatible device        |
| Message         | Baseline/Vendor Specific | General in-band messaging and event reporting (without consuming memory or IO address resources) |

<!-- image -->

## PCIE PROTOCOL OVERVIEW

- Throughput is for a single direction (i.e., PCIe 3.0 x1 can carry 8 GT/s in each direction simultaneously).
- Most components are backwards compatible so if you plug a x4 card into a x2 lane slot it will work, just slowly. Also, a gen 3.0 card will work in a gen 2.0 slot.

## PCI Express link performance[39][40]

| Version   | Line code   | Transfer rate[i[i]   | Throughputli[ij]   | Throughputli[ij]   | Throughputli[ij]   | Throughputli[ij]   | Throughputli[ij]   |
|-----------|-------------|----------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
| Version   | Line code   | Transfer rate[i[i]   | x1                 | x2                 | x4                 | x8                 | x16                |
| 1.0       | 8b/10b      | 2.5 GT/s             | 250 MB/s           | 500 MB/s           | 1.0 GB/s           | 2.0 GB/s           | 4.0 GB/s           |
| 2.0       | 8b/10b      | 5.0 GT/s             | 500 MB/s           | 1.0 GB/s           | 2.0 GB/s           | 4.0 GB/s           | 8.0 GB/s           |
| 3.0       | 128b/130b   | 8.0 GT/s             | 984.6 MB/s         | 1969.2 MB/s        | 3938.5 MB/s        | 7.877 GB/s         | 15.754 GB/s        |
| 4.0       | 128b/130b   | 16.0 GT/s            | 1969.2 MB/s        | 3938.5 MB/s        | 7.877 GB/s         | 15.754 GB/s        | 31.508 GB/s        |
| 5.0       | 128b/130b   | 32.0 GT/s[iv]        | 3938.5 MB/s        | 7.877 GB/s         | 15.754 GB/s        | 31.508 GB/s        | 63.015 GB/s        |

## Note

Transfer rate refers to the encoded serial bit rate; 2.5 GT/s means 2.5 Gbps serial data rate.

Throughput refers to the pre-coded data rate prior to 8b/10b or 128b/130b coding.

So, transfer rate of 2.5 GT/s means 2.5 Gbit/s serial bit rate corresponding to a throughput of 2.0 Gbit/s or 250 MByte/s.

<!-- image -->

## PCIE TOPOLOGY EXAMPLE

- Root complex - connects CPU/memory to the PCIe fabric. Generates transaction requests on behalf of CPU.
- End point - I/O devices or a bridge from PCI-Express to another bus.
- Switch - connects root complex to end point or end point to end point.

<!-- image -->

<!-- image -->

## LAYERED ARCHITECTURE

- Transaction layer: Processes read/write requests from software
- Data link layer: Data integrity, error detection and management
- Physical layer: Parallel-to-serial and serial-to-parallel conversion (SERDES), PLL and impedance matching circuitry and interface initialization and maintenance
- PCIe management data is contained in the Data Link Layer Packet(DLLP) and payload data is contained in a Transaction Layer Packet (TLP)

<!-- image -->

<!-- image -->

<!-- image -->

## S32G2 PCIe features

<!-- image -->

PUBLIC

8

## S32G2 PCIE FEATURES

S32G2 family variants contains two PCIe communication interfaces with integrated PHY (except S32G234M with one)

- Each controller can be root complex (RC) or endpoint (EP)
- PCI Express 3.0 specification
- backwards compatible with PCIe 2.1 (5 Gbps) and PCIe 1.1 (2.5 Gbps)
- S32G234M Gen 2 only
- 2 lane configuration for up to 8 Gbps per lane. 16 Gbps total. (1.97G Bytes/sec net bandwidth after 128/130 bit encoding/decoding)
- Integrated PHY includes transmitter, receiver, PLL, digital core and ESD
- Payload size of max. 256 Bytes per packet
- Internal DMA support to off-load CPU
- Supports common clock mode with an external reference clock generation for Gen3 and as option an internal reference clock generation for speeds up to Gen2
- Each PHY lane can be optionally used for SGMII mode of the Ethernet module
- As the S32G2 does not have SMMU, PCIe SRIOV is not supported
- Each instance of PCIe has 32GBytes of address window on the memory map

<!-- image -->

## SERDES LANE CONFIGURATION OPTIONS

S32G2 has 2x SERDES instances.

Each SERDES can support below PCIe modes.

<!-- image -->

<!-- image -->

## S32G2 PCIe Use Cases

<!-- image -->

PUBLIC

1 1

## USE CASE SCENARIOS

## Allows for:

- Expand compute performance via external SoC, e.g., Layerscape
- Additional functionality, e.g., ADAS with graphics processor
- Additional storage support, e.g., add SSD to dump data
- Telematics Connectivity

<!-- image -->

## EXAMPLE USE CASE 1: PERFORMANCE EXPANSION

<!-- image -->

<!-- image -->

- Performance Expand (PCIe connect 2nd MPU)
- Re-use GW architecture

<!-- image -->

## EXAMPLE USE CASE 2: ADDITIONAL FUNCTIONALITY

- S32G2 in ADAS domain
- S32G2 used for safety, routing between GPU and ADAS and general compute

<!-- image -->

<!-- image -->

## EXAMPLE USE CASE 3: ADDITIONAL STORAGE

- S32G2 in Safety Controller
- Acts like a black box and can dump large amounts of data

<!-- image -->

<!-- image -->

## EXAMPLE USE CASE 4: TELEMATICS CONNECTIVITY

- Connectivity over WiFi / Cellular Network
- S32G2 used for safety, routing between GPU and ADAS and general compute

<!-- image -->

<!-- image -->

<!-- image -->