## Airbiquity

Automotive OTA Software Updates and Data Management - Airbiquity OTAmatic ® on the NXP S32G Processor -

Brian Carlson: Director of Global Products and Solutions Marketing, NXP Keefe Leung: Vice President of Product Management, Airbiquity

November 30, 2020

2

NXP CONFIDENTIAL AND PROPRIETARY

## NXP Automotive Processing

<!-- image -->

<!-- image -->

<!-- image -->

## Vehicle Functional Domains

Service-oriented Gateway is central to the vehicle and has secure connectivity to the cloud

- Ideal for vehicle-wide data access
- Ideal for vehicle-wide OTA updates

<!-- image -->

## NXP S32 Family of Automotive Processors

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

| Performance                                     | Arm                                              | Safe                                       | Secure                                                                                                    | OTA                                                                                   | SW Reuse                                                      |
|-------------------------------------------------|--------------------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|---------------------------------------------------------------|
| Optimized for domain control Real-time Scalable | Arm top to bottom Arm Cortex-A, -R, and -M cores | ASIL D Process certified to ISO 26262:2018 | Powerful hardware security engine (HSE) Firmware upgradable public key encryption No side channel attacks | Across most nodes Scalable encrypted external NVM Wide memory range, read while write | Massive software Re-use within and across application domains |

<!-- image -->

<!-- image -->

<!-- image -->

Fully Scalable, Safe Automotive Compute Platform

<!-- image -->

## S32G is a New Type of Automotive Processor: Vehicle Network Processor

## PROCESSING

Lockstep Microcontrollers Cluster Lockstep Microprocessors Automotive Networks Acceleration

Ethernet Packet Acceleration

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

<!-- image -->

## 20+ Year Leader in Cloud-Based Connected Car Service Delivery

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## Company Summary

<!-- image -->

## Vehicle-Wide OTA Software and Data Management

<!-- image -->

Foundation for ADAS, V2X, and Autonomous

<!-- image -->

## OTA Vehicle Lifecycle Value Creation

<!-- image -->

<!-- image -->

## Problem: Efficiently Managing Increasingly Complex OTA Landscapes

Solution: OTA Orchestration and Automation in the Cloud

<!-- image -->

<!-- image -->

## Over-the-Air Orchestration

<!-- image -->

End-to-End Security

<!-- image -->

Policy-Driven Dependency Rollback, and Recovery

Standards-Based Certification, Authentication, and Encryption

<!-- image -->

Best Telematics Product or Service

<!-- image -->

## End-to-End Platform for Realizing OTA as a Service

## Airbiquity OTAmatic Software and Data Management Features

Data Management Framework

Dynamic Data Collection and Upgradeable Analytics

<!-- image -->

Bandwidth and Storage Management

Intelligent Network Selection, Data Caching, and Transfer

<!-- image -->

Campaign Management

<!-- image -->

Vehicle Configuration

Vehicle Configuration Definition and Regulatory Compliance

<!-- image -->

Campaign Creation, Approvals, Reporting, and Administration

<!-- image -->

- ¤ Orchestration and automation of multi-ECU OTA software updates and data management
- ¤ Highly refined policy and event driven campaign creation, approval, reporting, and administration
- ¤ Industry leading vehicle, device, network, platform, and back office integration expertise
- ¤ Solution deployment flexibility: Public cloud or on-premise hosting

Consumer Interaction and Privacy

<!-- image -->

Customized Notifications, Prompts, and Consent

<!-- image -->

<!-- image -->

## Solution Architecture and Integration

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## Pre-Installation Management

- ¤ Allows OEM to specify pre-conditions associated with a software update (e.g., battery level)
- ¤ In-vehicle software ensures pre-conditions defined for an update are met before installing the update
- ¤ Runs OEM provided scripts to perform pre-installation operations

## Vehicle Configuration, Regulatory, and Installation Management

- ¤ Enables OEM to define vehicle ECU configurations and manage and report UNECE WP.29 type approvals and RXSWINs
- ¤ Transfers and installs updates according to the vehicle configurations and priorities specified by the OEM
- ¤ Installation does not require network connectivity

## Fault / Error Detection and Prevention

- ¤ Pre-condition check for battery level, vehicle state, etc. to limit failures due to power loss or user interruption
- ¤ Resume interrupted downloads
- ¤ Start updating only after verification of the downloaded package to limit connectivity or verification failures
- ¤ Post-installation diagnostics check ensures successful update

## Recovery and Rollback

- ¤ Configurable installation retries based on OEM selected policy settings
- ¤ Store ECU rollback software in persistent memory or utilize dual-bank 'A / B' memory if available
- ¤ Rollback to previous installed version to ensure vehicle is in working condition
- ¤ Revert to safe / reduced functionality vehicle state for installation failures

## Post-Installation Verification

- ¤ Runs OEM provided diagnostic scripts to ensure update was successful
- ¤ Update OEM provided scripts to update or restore ECUs with any configuration files required after the update

## Software Update Orchestration

<!-- image -->

## Dynamic data strategy and management approach:

- ¤ Continually modify data collection - and optimize expenses - based on realtime business requirements
- ¤ Edge Analytics: In-vehicle data processing
- Ø Real-time feedback to users
- Ø Reduce connectivity costs: Only upload worthy data that is processed
- Ø Security and Privacy: Data can be anonymized before uploaded to cloud
- Ø Enable partner ecosystem growth
- ¤ OTAmatic ® enables OEMs to deploy Edge Analytics Modules from partners which are built using the OTAmatic DM SDK
- ¤ OTAmatic DM SDK includes everything required to create, test, and debug Analytic Modules - both on developer machines and actual target devices

<!-- image -->

<!-- image -->

## Data Management Framework - Technical Summary

<!-- image -->

<!-- image -->

<!-- image -->

## Uptane: An Open Security Framework for Automotive

- ¤ Open specification for securing OTA software updates for automotive electronics
- Ø Confidentiality, Integrity, Authenticity, Availability
- ¤ Foundational and ongoing involvement of notable government, academic, and research organizations:
- ¤ Strong design and feedback process participation by OEMs and Tier 1 suppliers across North America, Europe and Asia
- ¤ Based on The Update Framework (TUF) which has been well-vetted by both academia and the automotive industry
- ¤ Multiple open-source projects have based their software update security on TUF:
- ¤ Released through IEEE Industry Standards and Technology Organization (IEEE-ISTO) on July 31, 2019

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

- ¤ Addresses all security needs of an OTA update system
- Ø Thwart and mitigate attacks to the system
- Ø Survive server compromise with minimum possible damage
- Ø Minimize damage of a single key being exposed
- Ø Be able to revoke keys, maintaining trust
- ¤ Purpose built for an automotive multi-ECU environment
- Ø Primary and Secondary ECUs
- ¤ Compromise resilience
- Ø Offline and Online Keys
- Ø Different roles for specific tasks
- ¤ Deployment flexibility
- Ø Delegation of code signing
- Ø Designed with automotive supply chain in mind
- ¤ Comprehensively addresses threats
- Ø Eavesdrop, drop-request, slow retrieval, freeze, partial bundle installation, rollback, endless data, mix-and-match, and arbitrary software attacks

Automotive Grade

<!-- image -->

<!-- image -->

Compromise Resilient

<!-- image -->

<!-- image -->

<!-- image -->

## Airbiquity-NXP OTA Solution Demonstrator

## Vehicle-Wide OTA Update Solution

- ¤ Powerful NXP automotive-grade production-ready hardware platform
- Ø S32G: Ideal for connected gateway applications
- Ø i.MX8: Advanced multimedia applications
- Ø S32K: General purpose automotive applications
- Ø S32S: Ideal for electrification and domain controller applications
- ¤ Comprehensive Airbiquity OTA software and data management
- Ø Supports full update capabilities of OTAmatic solution
- Ø Update or add VM operating systems and applications
- Ø Differential updates for secondary ECUs
- Ø Full UDS flash updates for legacy ECUs, sensors, and actuators
- Ø Dependency management for physical and virtual ECUs
- Ø Flexibility to perform updates while the vehicle is in motion
- Dual-bank / read-while-write (RWW) memory
- ¤ Robust Uptane-based end-to-end security
- Ø Full Uptane implementation including all specified components
- Ø Hardware Security Engine (HSE) for secure key management, authentication, and cryptography
- Ø Accelerators for both symmetric and asymmetric keys

## Airbiquity

Thank you!