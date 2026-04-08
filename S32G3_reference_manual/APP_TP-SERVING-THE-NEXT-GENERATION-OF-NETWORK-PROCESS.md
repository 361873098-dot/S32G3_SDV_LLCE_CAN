<!-- image -->

## Why COQOS Hypervisor SDK and the S32G serve the next generation of Network Processors

## Agenda

1. Virtualization Example
2. VIRTIO Standard
3. COQOS Hypervisor for S32G
4. Virtualized Telematic System demo

<!-- image -->

|

## Virtualization Example

<!-- image -->

|

## Virtualization for vehicle?

<!-- image -->

- More and more functionality mainly built with software
- Safety and security relevant software
- Consolidation
- More functionality integrated into less Hardware
- Shorter software development cycles

<!-- image -->

|

## Virtualized Telematics Requirements

## Virtualized TCU, i.e. secure &amp; safe convergence of multiple features on a single HW

<!-- image -->

- Security: Separation between vehicle network and external network (cellular, Wi-fi, etc.)
- Safety: Separation of functions with different safety requirements
- Low latency &amp; propagation time for an efficient communication
- Low power consumption
- Scalability

<!-- image -->

|

## Virtualized Telematics: Security

- External networks create an attack surface that could be exploited from the outside
- Strong separation between vehicle and external network can be achieved:
- By separating the software in Virtual Machines (VM)
- And allowing the communication between VMs via minimal and supervised APIs

<!-- image -->

<!-- image -->

|

## Virtualized Telematics: Safety

- With the advent of V2X and the usage of data to support ADAS, safety certification may become mandatory
- COQOS Hypervsior enables safe separation of functions of different criticality

<!-- image -->

<!-- image -->

|

## VIRTIO Standard

<!-- image -->

|

## Enter VIRTIO

- Developed in 2008 &amp; managed by OASIS Open
- Supported by all clouds and enterprise hypervisors (VIRTIO 1.0 &amp; 1.1)
- A standardized interface for I/O between virtual machines and hypervisors
- Drivers widely available in major operating systems (Linux, Android, BSD, Windows, etc.)
- Work in progress for automotive domain, e.g. Audio, Sensors, GPU, CAN
- OpenSynergyis a member of OASIS Open driving the adoption of VIRTIO in automotive.

<!-- image -->

<!-- image -->

<!-- image -->

|

## VIRTIO Devices

## OASIS Consortium standardizes the VIRTIO interface

<!-- image -->

- Adds automotive specific device interfaces to standard
- Provides high quality drivers in upstream Linux kernel
- Prepares a virtual machine ecosystem that guarantees guest readiness
- AGL
- Android
- RTOS

•

...

<!-- image -->

|

## Future VIRTIO

- WLAN
- Bluetooth
- Controller Area Network (CAN)
- Camera
- Machine Learning

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

|

## How VIRTIO works

## Device Host (Server VM)

## Driver Guest (Client VM)

<!-- image -->

Device HW

SoC

- Bulk data transport via DMA -like memory model
- Buffer allocations handled by 'Driver' part (client)
- Direct R/W access to allocated buffers in the 'Device' part (server)
- Metadata transport via virt-queues (ring buffers, asynchronous pipeline)

## Open Source

Hypervisor Vendor

VIRTIO Support

VQ = virt-queue SG = Scatter Gather

<!-- image -->

|

## Getting a VIRTIO BSP for Linux

1. $&gt; git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
2. Add virtio support to your kernel configuration
3. Done!

```
+CONFIG_VIRTIO_MMIO=y +CONFIG_VIRTIO_NET=y +CONFIG_VIRTIO_BLK=y …
```

<!-- image -->

|

## Towards virtualization with hardware abstraction

## 1. The Good Old Days

- One service per hardware = no consolidation
- The hardware defines the software.

<!-- image -->

## 2. The Dawn of Virtualization

- Multiple services per hardware = consolidation
- The hardware defines the software.

<!-- image -->

## 3. Hardware Abstraction

- Multiple services per hardware = consolidation
- The software defines the hardware .

<!-- image -->

Base for Software Defined Architecture

<!-- image -->

|

## COQOS Hypervisor for S32G Present and Future

<!-- image -->

|

## COQOS Hypervisor SDK for S32G

<!-- image -->

A-Cores (NXP S32G)

M-Cores

<!-- image -->

- COQOS HV SDK implements a Software Defined Architecture
- Allows multiple Guests and communication channel running on the same HW.

<!-- image -->

|

## 'Next Gen COQOS' Multi SoC

<!-- image -->

<!-- image -->

|

## An Example with Remote GPU

<!-- image -->

<!-- image -->

|

## Virtualized Telematic System - demo

<!-- image -->

<!-- image -->

|

<!-- image -->

## Headquarters

## Berlin

OpenSynergy GmbH Rotherstraße 20 D-10245 Berlin Germany Phone

+49 30 / 6098 5400

## Further Locations

## Utah

OpenSynergy,  Inc. (USA)

765 East 340 South Suite 106 American Fork, Utah 84003

USA

## California

OpenSynergy,  Inc. (USA)

501 W. Broadway, Suite 832 San Diego, California 92101 USA Phone  +1 619 962 1725

E-Mail

i nfo@opensynergy.com

Web          www.opensynergy.com

OpenSynergy, COQOS Hypervisor SDK, Blue SDK, IrDA SDK, Voice SDK, Qonformat, and other OpenSynergy products and services mentioned herein as well as their respective logos are trademarks or registered trademarks of OpenSynergy GmbH in Germany and in other countries around the world. All other product and service names in this document are the trademarks of their respective companies. These materials are subject to change without notice. These materials are provided by OpenSynergy GmbH for informational purposes only, without representation or warranty of any kind and OpenSynergy GmbH shall not be liable for errors or omissions with respect to the materials. © OpenSynergy GmbH 2021

## Munich

OpenSynergy  GmbH

Starnberger Str. 22 D-82131 Gauting / Munich Germany Phone: + 49 89 / 2153 9073