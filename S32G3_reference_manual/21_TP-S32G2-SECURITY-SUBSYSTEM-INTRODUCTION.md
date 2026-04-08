## S32G2 SECURITY SUBSYSTEM INTRODUCTION

MARCH 2021 AP, Vehicle Control &amp; Networking Solutions

<!-- image -->

<!-- image -->

<!-- image -->

## AGENDA

- Concepts of security subsystem
- Security Architecture
- Hardware Security Module (HSE)
- Security services
- Platform security

<!-- image -->

<!-- image -->

<!-- image -->

## Concepts of security subsystem

<!-- image -->

## DID YOU KNOW?

<!-- image -->

Vehicle cyber incidents In 2019

<!-- image -->

Vehicles recalled in the largest incident to date

<!-- image -->

## WHY HACKING?

Valuable data attracts hackers

Car-generated data may become a 750 B$ market by 2030

<!-- image -->

## WHY IS IT POSSIBLE?

## High system complexity

implies high vulnerability

Up to 150 ECUs per car, up to 200 M lines of software code

<!-- image -->

## WHY NOW?

Wireless interfaces enable scalable attacks

250 M connected vehicles on the road in 2020

<!-- image -->

<!-- image -->

## CAN WE TRUST MODERN CARS?

<!-- image -->

<!-- image -->

## CAN WE TRUST MODERN CARS?

<!-- image -->

<!-- image -->

## CAN WE TRUST MODERN CARS?

<!-- image -->

<!-- image -->

## CAN WE TRUST MODERN CARS?

<!-- image -->

<!-- image -->

## CAN WE TRUST MODERN CARS?

<!-- image -->

<!-- image -->

## CAN WE TRUST MODERN CARS?

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

YES WE CAN!

…AS LONG AS SECURITY IS AN INTEGRAL PART OF THE DESIGN

<!-- image -->

## HOLISTIC APPROACH - SOLUTIONS AND ORGANIZATION MULTIPLE LAYERS OF PROTECTION

<!-- image -->

|                         | PREVENT ACCESS                                    | DETECT ATTACKS                                    | REDUCE IMPACT                                     | FIX VULNERABILITIES                               |                                                   |
|-------------------------|---------------------------------------------------|---------------------------------------------------|---------------------------------------------------|---------------------------------------------------|---------------------------------------------------|
| SECURE INTERFACES       | M2M Authentication and Firewalling                | Secure Ranging (e.g., FiRa)                       |                                                   |                                                   |                                                   |
| SECURE DOMAIN ISOLATION | Firewalling (context-aware message filtering)     | Network Intrusion Detection Systems (NIDS)        | Separated Functional Domains                      | Secure Updates                                    |                                                   |
| SECURE NETWORKS         | Secure Messaging                                  | Network Intrusion Detection Systems (NIDS)        | Message Filtering and Rate Limitation             |                                                   |                                                   |
| SECURE PROCESSING       | Code / Data Authentication (@ start-up)           | Code / Data Authentication (@ run-time)           | Resource Control (virtualization)                 |                                                   |                                                   |
| SECURE ENGINEERING      | SDLC incl. Security Reviews and Testing,…         | Threat Monitoring, Intelligence Sharing,…         | Incident Management / Response                    | Incident Management / Response                    |                                                   |
| SECURE ENGINEERING      | Security-Aware Organization, Policies, Governance | Security-Aware Organization, Policies, Governance | Security-Aware Organization, Policies, Governance | Security-Aware Organization, Policies, Governance | Security-Aware Organization, Policies, Governance |

<!-- image -->

## SECURITY MEASURES

<!-- image -->

## LOCAL ATTACKS

## ECU (IC)

DISCRETE AND INTEGRATED SECURITY SOLUTIONS

<!-- image -->

## LOCAL INTERFACES

## REMOTE ATTACKS

## REMOTE INTERFACES

## CORE SECURITY PRINCIPLES

SECURE EXTERNAL INTERFACES

<!-- image -->

SECURE FOUNDATIONS

SECURE DOMAIN ISOLATION

<!-- image -->

<!-- image -->

SECURE INTERNAL COMMUNICATION

<!-- image -->

SECURITY SERVICES

<!-- image -->

SECURE SOFTWARE EXECUTION

<!-- image -->

<!-- image -->

## NXP'S AUTOMOTIVE SECURITY SOLUTIONS

<!-- image -->

## AUTOMOTIVE ICS WITH ON-CHIP SECURITY SUBSYSTEMS

INFOTAINMENT AND IN-VEHICLE EXPERIENCE

CONNECTIVITY

ADAS AND HIGHLY AUTOMATED DRIVING

VEHICLE NETWORKING

POWERTRAIN AND VEHICLE DYNAMICS

BODY AND COMFORT

<!-- image -->

<!-- image -->

<!-- image -->

i.MX8

Layerscape

S32x

Security Controller (SECO)

High performance Media content protection

Security Controller (SEC)

HSE (HSM)

High performance Versatile feature set

<!-- image -->

CSE

Ease-of-use

Cost-optimized

## SECURITY COMPANIONS

<!-- image -->

Security Controller (SE)

Tamper-resistant secure system ideal for M2M authentication (e.g., V2X)

## FUNCTION-SPECIFIC SECURE ICS

<!-- image -->

Secure in-vehicle networking (IVN) Network level filtering of CAN/Ethernet frames

<!-- image -->

<!-- image -->

<!-- image -->

(Smart) Car Access solutions Precise ranging with Ultra-Wideband (UWB)

WiFi and DSRC (V2X)

With ultra-fast WPA2/3 and ECDSA security

Broadcast radio (AM/FM/Digital) Platform security incl. secure boot

<!-- image -->

## MEGATREND: ON-CHIP SECURE SUBSYSTEM

<!-- image -->

<!-- image -->

SECURITY CONFIGURATIONS

## SECURITY SUBSYSTEM

- A security subsystem is a dedicated subsystem within an IC (i.e., microcontroller or SoC).
- In the automotive market, they are often referenced as the secure hardware extension (SHE) module or the hardware security module (HSM).
- Objectives
- Provide security services to the application, and support securing application code and data in transit and at rest
- Provide platform security and protect platform integrity as well as the confidentiality and availability of critical assets where needed; these functions includes controlling the application environment in various ways (e.g., secure boot) and enforcing security policies
- Protect cryptographic keys from software attacks by moving the control over critical assets (in particular, cryptographic keys) from the application domain into a separate domain

<!-- image -->

<!-- image -->

## Security Architecture

<!-- image -->

## AUTOMOTIVE SECURITY SPECIFICATIONS

The SHE specification set the foundation, introducing the concept of a configurable (automotive) security subsystem

EVITA's HSM specification extended this concept into a programmable subsystem, in three flavors (Full, Medium, and Light), addressing a broader range of use cases

Nowadays, OEMs are creating their own technical specifications, including select aspects of SHE, EVITA, and FIPS 140-2

<!-- image -->

<!-- image -->

## SECURITY REQUIREMENTS - TODAY'S LANDSCAPE

<!-- image -->

| SHE *                                                                                                                                                   | 2008                                                                                                                                           | EVITA (Light / Medium / Full) 2010                                                                                                                                                                                                  | More recent needs Now / Future   |
|---------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------|
| • Configurable, fixed function                                                                                                                          | • Programmable (except EVITA Light)                                                                                                            | • Acceleration close to the interfaces (CAN and ETH MAC/PHYs) • Support for Flash-less technologies                                                                                                                                 | ARCHITECTURE                     |
| • Secure boot • Memory update protocol • AES-128 (ECB, CBC) • CMAC, AES-MP • TRNG, PRNG • Key derivation (fixed algorithm) • 10+4 keys, key-usage flags | Same as SHE, plus: • AES-PRNG • monotonic counters (16x, 64-bit) Plus, for EVITA Medium and Full: • WHIRLPOOL, HMAC-SHA1, ECDH and ECDSA(P256) | • Further crypto algorithms (e.g., RSA, SHA3, Curve25519, …) • Rollback protection • Key negotiation protocols • Communication protocol offloading (e.g., TLS, IPsec, MACsec, …) • Context separation / multi-application scenarios | FUNCTIONALITY                    |
| OTHER                                                                                                                                                   |                                                                                                                                                | • Increased attack resistance (e.g., SCA, Fault Injection, …)                                                                                                                                                                       |                                  |
| CSE family (since 2010) HSM family (since 2015) Covered by:                                                                                             |                                                                                                                                                |                                                                                                                                                                                                                                     |                                  |

<!-- image -->

## APPLICATION DOMAIN AND SECURITY SUBSYSTEM DOMAIN

## APPLICATION DOMAIN

Complex Subsystems Multiple Processing Elements Multiple Interfaces

## SECURE DOMAIN

Resistance to Local Attacks Root of Trust Acceleration of Security Primitives

Logical view of security subsystem domain and application domain

<!-- image -->

<!-- image -->

<!-- image -->

HSE

<!-- image -->

## HSE SIMPLIFIED BLOCK DIAGRAM

<!-- image -->

<!-- image -->

## HSE INTERFACE WITH HOSTS: MESSAGING UNIT (MU)

<!-- image -->

<!-- image -->

## HSE FIRMWARE RELEASE

- Package content
- HSE Firmware: encrypted binary
- The Pink image
- HSE Firmware interface files
- hse\_interface.h
- HSE Service API RM

<!-- image -->

<!-- image -->

| Key types (max key size)          | AES(256 bits) RSA(2048 bits) ECC(256 bits) HMAC(512 bits) DH(2048 bits)   | AES(256 bits) RSA(4096 bits) ECC(521 bits) HMAC(1152 bits) DH(4096 bits)   |
|-----------------------------------|---------------------------------------------------------------------------|----------------------------------------------------------------------------|
| Number of keys                    | RAM keys: 20 NVM keys: 12(asym) + 40(sym)                                 | RAM keys: user configurable NVM keys: user configurable                    |
| Number of memory regions verified | 4                                                                         | 32                                                                         |
| Protocol offloading               | NA                                                                        | IPSec                                                                      |

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## Security services

<!-- image -->

## ON-CHIP SECURE SUBSYSTEM: HSE SERVICE EXAMPLES

## KEY MANAGEMENT

Key file management

Key import

Key export

Key generation

Key derivation

Key exchange

AES key up to 256 bits RSA key up to 4096 bits

* Please see HSE firmware release note for detail information

<!-- image -->

## CRYPTO OPERATIONS

AES

<!-- image -->

Encryption &amp; decryption

CMAC / HMAC Generation &amp; verification

Hashing (SHA2 and SHA3)

RSA / ECC signature Generation &amp; verification

RSA OAEP / ECIES Encryption &amp; decryption

Random generation TRNG &amp; PRNG

All operations hardware accelerated

## PLATFORM SECURITY

Strict secure boot

Verify-then-start

Parallel secure boot Verify-and-start

On-demand verification

Secure boot control in app.

Configurable sanctions E.g., key usage restrictions

Secure boot optimized for latency

<!-- image -->

<!-- image -->

## S32 SECURITY SUBSYSTEM: NATIVE SECURITY SERVICES

## Cryptographic functions

- -Encryption / decryption
- -MAC generation / verification
- -Hashing
- -Signature generation / verification

## Memory checks

- -Memory verification at start-up (secure boot)
- -Memory verification at run-time

## Administration

- -System initialization &amp; configuration
- -Functional tests
- -Security policy manager
- -Service updates &amp; extension

## Key management

- -Key import &amp; export
- -Key generation
- -Key derivation
- -Key exchange

## Monotonic counters

- -Incrementing and reading volatile &amp; non-volatile counters

## Secure network protocols

- -SSL / TLS offload
- -IPsec offload

## Random number generation

- -Pseudo-random numbers based on true random seed

## Secure time base

- -Secure tick to host

<!-- image -->

<!-- image -->

## Platform security

<!-- image -->

## SYSTEM SECURITY POLICIES

- A security subsystem must be able to monitor, validate and control the application and its environment to enforce relevant security policies.
- Sanctions
- Hardware-enforced isolation and access control
- The system security policy is usually comprised of multiple configuration options that affect peripherals, subsystems or an entire IC.
- Debug access protection
- Secure boot
- System memories access control
- Firmware protection
- Access control to security services

<!-- image -->

## SECURE BOOT

- Perform the verification of authenticity and integrity of an application before let it go
- System bring-up (Boot ROM)
- Boot stages
- Root-of-trust for secure boot
- Sequential boot vs. parallel boot
- Confidentiality protection

<!-- image -->

<!-- image -->

## RUNTIME INTEGRITY PROTECTION

- Runtime memory protection
- To verify the integrity of application code and data at runtime
- Integrity checks are initiated periodically or triggered through events
- The service may be utilized to protect code and data from unauthorized modification
- Makes sense for memories whose contents remain unchanged throughout longer periods of time. Examples: operating system code, interrupt vector tables, interrupt handlers or monitoring software

<!-- image -->

## SYSTEM LIFECYCLE

- Lifecycles in automotive products

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->