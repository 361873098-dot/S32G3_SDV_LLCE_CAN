<!-- image -->

Future Proofing OTA Vehicle Updates &amp; Data Logging with S32G2 and the Sibros Deep Connectivity Platform

Preet Kang | VP of Firmware, Sibros

&gt;&gt;&gt;&gt;

1. OTA pitfalls
2. How NXP S32G2 helps bridge the connectivity gap
3. Sibros Connected Vehicle Platform on the S32G2

<!-- image -->

## Presentation Agenda

<!-- image -->

NXe

<!-- image -->

<!-- image -->

OTA Connectivity Pitfalls

<!-- image -->

## Why Hardware selection is important

- Vehicles are significantly different than those from 2000s, or 2010s
- Millions of more lines of code
- We can no longer ship vehicles of one model year, and never revisit its software
- Software changes (or bug fixes) result in costly vehicle recalls
- Software and Hardware architecture need to be considered first, rather than last
- Need to support full vehicle updates (not just infotainment)

<!-- image -->

<!-- image -->

<!-- image -->

## Connectivity Platform is the Key

- Comprehensive connectivity to the vehicle network is necessary
- Avoid non-standard CAN bus access
- Avoid throughput limited connectivity
- Beware of Engineering cost
- Overcome limitations of limited throughput
- Develop special software to access vehicle network

<!-- image -->

## Software Fragmentation

- Typical vehicle architecture involves an Infotainment, and a separate CAN Gateway
- Vehicle software is thus fragmented into different systems
- Separate software builds
- Different CPU architectures, different OS, compilers etc.
- Potentially multiple vendors working on the software that could be combined into fewer pieces running on unified hardware
- Potential security and safety loopholes

<!-- image -->

<!-- image -->

## Low cost platform?

- A "bare-metal" platform is inexpensive on the hardware cost, but expensive on the software side
- Things are seriously "bare metal"
- Limited RAM severely limits productivity
- Must develop or "port" specialized software with static RAM footprint (without heap memory)
- Non-standard connectivity
- Typically non-standard network API (no BSD sockets' API)
- Extra cost to maintain an "AT" command based connectivity (sw driver) with an external modem
- Non-standard platform
- Flash based storage typically with third-party file-system API
- Overall cost increases
- "Porting", development, validation, etc.

<!-- image -->

<!-- image -->

How S32G2 bridges the gap

<!-- image -->

## The S32G2

- Built on highest level of safety standards (ASIL-D)
- Application-class processor capable of running POSIX OS (such as Linux, or realtime QNX)
- Standard OS services
- POSIX Thread model
- BSD Socket API
- SocketCAN (standard CAN driver)
- Easy to write software
- Focus on "Application" or your goal vs.
- Bare-metal platform bring-up
- RTOS integration
- LTE modem bring-up
- TLS security integration

<!-- image -->

## S32G2 Connectivity Platform

- Consolidates the hardware
- CAN Gateway and Connected Gateway
- Easy to deploy Sibros Deep Logger
- Log anything and everything from the OS
- Log selected CAN frames directly to the Cloud
- Capable OTA update platform
- Direct access to each vehicle CAN bus
- Virtual memory support for system stability
- One process crash would not crash the whole system

<!-- image -->

<!-- image -->

<!-- image -->

## Thank you