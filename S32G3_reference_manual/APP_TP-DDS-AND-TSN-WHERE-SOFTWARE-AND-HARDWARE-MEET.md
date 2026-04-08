## DDS AND TSN:

WHERE SOFTWARE AND HARDWARE MEET FOR DEPENDABLE COMMUNICATION USING RTI CONNEXT© DRIVE AND THE NXP S32G PROCESSOR

Lulu Chan - Senior System Architecture Engineer (NXP) Emilio Guijarro - Senior Automotive Applications Engineer (RTI)

J U N E   2 0 2 1

<!-- image -->

rti

<!-- image -->

## MAKING VISION ZERO A REALITY

Zero Road Accidents 94% of accidents from human error AUTONOMY

<!-- image -->

ELECTRIFICATION Zero Emissions Increasing global

<!-- image -->

regulations

<!-- image -->

CONNECTIVITY Zero Time Wasted Intelligent transport systems, new opportunities for infotainment

<!-- image -->

## AUTOMOTIVE TRENDS INCREASE VEHICLE COMPLEXITY

<!-- image -->

<!-- image -->

<!-- image -->

## I N CREASED COMPLEXITY CHALLENGES THE VEHICLE ARCHITECT

Increasing in-vehicle connectivity

Increasing interdependencies

## Architecting challenges

- Manage complexity
- Keep communication
- Deterministic
- Prioritized
- Reliable

<!-- image -->

<!-- image -->

## Who is RTI?

## RTI makes the #1 software framework for autonomy

- 1700+ designs, real-world programs across industries
- 750+ research programs
- ~$50M+ annual revenue with 25%+ CAGR

## HQ in Silicon Valley

- Offices in Colorado, Spain, Singapore
- Employees worldwide

<!-- image -->

## 200+ RTI autonomous vehicle programs

- 50+ commercial systems
- -10+ Passenger vehicles
- -10+ EV startups
- -5+ Software platforms
- -8+ Trucks, mining vehicles, forklifts
- -2 Flying taxi services
- -2 Hyperloop &amp; other
- -2+ Autonomous ships
- -2+ Underwater robots
- 100+ defense systems (land, sea, air)
- 75+ research programs (companies, universities, etc.)

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## Introduction to Data Distribution Service (DDS ™️ )

<!-- image -->

## The DDS standard

- DDS is a data-oriented connectivity framework, standards-based and battle-tested in many industries
- Standardized by the OMG: world's largest software standards organization
- -UML, DDS, CORBA, etc.
- Open and cross-vendor
- -Open, freely accessible
- -12+ implementations

<!-- image -->

<!-- image -->

## The DDS standard

<!-- image -->

## · Connectivity middleware

- -Data centricity
- -Decentralization
- -Low latency
- -Reliability
- -Scalability
- Built for business , mission and safety-critical applications

<!-- image -->

## From this…

<!-- image -->

<!-- image -->

## Why DDS ?

<!-- image -->

## I N CREASED COMPLEXITY CHALLENGES THE VEHICLE ARCHITECT

Increasing in-vehicle connectivity

Increasing interdependencies

## Architecting challenges

- Manage complexity
- Keep communication
- Deterministic
- Prioritized
- Reliable

<!-- image -->

<!-- image -->

<!-- image -->

## Introduction to TSN

<!-- image -->

## I E E E   T I M E - S E N S I T I V E   N E T W O R K I N G   S TAN D A R D S

## T ime S ensitive N etworking (TSN)

- Active IEEE 802.1 Task Group
- Improvement of performance

## TSN Profiles

- IEC/IEEE 60802 Industrial Automation
- P802.1DG Automotive In-Vehicle

<!-- image -->

<!-- image -->

## I E E E   8 0 2 . 1 Q :   AL L O W   C O E X I S T E N C E   O F   D I F F E R E N T   T R AF F I C   T Y P E S

- Allows different traffic types to be assigned different priorities
- Outgoing messages are placed in the queue corresponding to their priority
- Priorities allow network components to handle important messages with urgency
- VLANs ensure frames only go where they are allowed to go (virtual wires)

<!-- image -->

<!-- image -->

## I E E E   8 0 2 . 1 Q a v :   AV O I D   T R AF F I C   B U R S T S   T H AT   C AN   C AU S E   N E T W OR K   C ON GE S T I O N

- Credit-based shapers keep track of the amount of queue data transmitted
- A non-negative credit is required to transmit
- Increases while waiting
- Decreases while transmitting
- Reset when empty and credit is positive
- They cap the bandwidth that a queue can transmit in hardware
- This allows the use of optimized software stacks that usually generate traffic bursts

<!-- image -->

<!-- image -->

## I E E E   8 0 2 . 1 C B :   F R AM E   R E P L I C AT I O N   AN D   E L I M I N AT I O N TO INCREASE NETWORK RELIABILITY

- Provides seamless data redundancy
- Frames are replicated and an R-tag is added that includes a sequence number
- Each frame copy follows its own path
- Disjoint from the path of the other frame (where possible)
- Duplicates are eliminated at merge points
- Bridges and/or end stations may replicate and eliminate

<!-- image -->

<!-- image -->

## I E E E   8 0 2 . 1 C B :   F R AM E   R E P L I C AT I O N   AN D   E L I M I N AT I O N TO INCREASE NETWORK RELIABILITY

- An example where end stations replicate and eliminate
- Protects more of the path

<!-- image -->

<!-- image -->

## I E E E   T I M E - S E N S I T I V E   N E T W O R K I N G   S TAN D A R D S

## T ime S ensitive N etworking (TSN)

- Active IEEE 802.1 Task Group
- Improvement of performance

## TSN Profiles

- IEC/IEEE 60802 Industrial Automation
- P802.1DG Automotive In-Vehicle

<!-- image -->

<!-- image -->

## DDS and TSN Standardization

<!-- image -->

<!-- image -->

## DDS and TSN

## · DDS

- -Distributed, data-centric, peer-to-peer architecture
- -Standard APIs and wire protocol
- -Comprehensive set of QoS policies to fine tune communication and resource limits
- -Extensible type system for data modeling
- -Data-centric and transport-based security

## · TSN

- -Ethernet-based: COTS, interoperable and highbandwidth
- -High-availability through redundancy and traffic management
- -Deterministic, low-latency delivery
- -Sub-microsecond time synchronization

<!-- image -->

Based onIndustrial Internet ConsortiumloTConnectivityStack

<!-- image -->

## Towards a standard DDS &amp; TSN integration

- RTI is working on a DDS-TSN standard at the OMG
- -Filed an RFP in September 2018
- -Leading a submission with the collaboration of other vendors
- TSN vendors are invited to join to provide support and validation

<!-- image -->

<!-- image -->

## What's in the standard?

- Platform-independent extensions of the DDS Application Configuration model (DDS-XML) supporting
- -Deployment configuration
- -TSN configuration
- -CUC and CNC interactions
- Platform-independent extension of the DDSI-RTPS wire protocol
- Platform-specific extensions of the DDS-RTPS wire protocol for
- -UDP/IP
- -Ethernet
- -TSN

<!-- image -->

## DDS and TSN in Automotive

<!-- image -->

## DDS + TSN design methodology

- Top-down
- -From high-level DDS systems down to TSN networks
- Practical
- -Considers common DDS, OS and TSN constraints
- Automotive-oriented
- -Domain vocabulary

<!-- image -->

<!-- image -->

## Identifying domains

- Powertrain
- Body
- Chassis
- Infotainment
- Connectivity
- ADAS
- …

<!-- image -->

## The process at a glance

Identify domains

<!-- image -->

Model DDS system rti

## Modeling the DDS system

- Use standard DDS meta-model (DDS-XML) to design
- -DDS Domains (using results from previous step)
- -DDS Domain Participants
- And their entities: publishers, subscribers, topics, DW's, DR's
- -DDS QoS policies
- -Deployment nodes
- And the domain participant(s) each hosts
- -TSN Talkers and Listeners
- Referencing DW's and DR's respectively
- Assign TSN-related policies

<!-- image -->

## Modeling the DDS system

<!-- image -->

## Modeling the DDS system

<!-- image -->

<!-- image -->

## The process at a glance

Identify domains

<!-- image -->

Model DDS system

Derive stream graph

<!-- image -->

## Building the stream graph

1. Derive a graph of TSN Streams from the system design
2. -From DataReader and DataWriter pairs linked by Topic
3. -Assign VLAN IDs from applicable Domain
4. -Assign source/destination MACs from Deployment Nodes
5. -Assign TSN constraints from TSN Talker and Listeners in the design

## 2. Cluster and schedule streams

- -Set PCP values
- -Set transmission windows

<!-- image -->

## The process at a glance

Identify domains

<!-- image -->

Derive OS, DDS and TSN configuration

Model DDS system

<!-- image -->

Derive stream graph

<!-- image -->

## Deriving deployment configuration

- From the scheduled Stream Graph
- -At OS level, configure NICs matching Domains defined in step 1
- -At DDS level, update QoS policies for DataReaders and DataWriters (e.g., TRANSPORT\_PRIORITY, LATENCY\_BUDGET, etc.)
- -At TSN level, update TSN policies for bridges and end stations using standard (CUC, CNC) or vendor-specific protocols
- In run-time, DDS Samples flow through time-sensitive network streams as initially devised in the DDS System Model

<!-- image -->

<!-- image -->

Demo video

<!-- image -->

## DEMO SETUP - AUTONOMOUS VALET PARKING (AVP) APPLICATION

<!-- image -->

<!-- image -->

AUTOWARE.AUTO

<!-- image -->

## DEMO SETUP - AUTONOMOUS VALET PARKING (AVP) APPLICATION

<!-- image -->

<!-- image -->

AUTOWARE.AUTO

<!-- image -->

## DEMO SETUP - HARDWARE AND SOFTWARE

automated driving simulator workstation

<!-- image -->

Autonomous Valet Parking RTI Connext® DDS LS2084

high-performance computer drive-by-wire (simulator) interface camera service for telematics RTI Connext® DDS S32G, SJA1110

gateway

Time-Sensitive Networking SJA1110s network

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

DEMO VIDEO

## DDS-TSN demo of deterministic and reliable communication

<!-- image -->

<!-- image -->

PUBLIC

4 5

## Colophon

rti

## Summary

- DDS enables design, implementation and deployment of scalable, reliable and performant distributed communications
- TSN ensures determinism and reliability at the link layer of Ethernet networks
- DDS and TSN complement each other, becoming the right foundation next-generation automotive architectures

<!-- image -->

## Stay Connected

<!-- image -->

<!-- image -->

<!-- image -->

rti.com Free trial of Connext DDS

@rti\_software

@rti\_software

<!-- image -->

<!-- image -->

<!-- image -->

rtisoftware connextpodcast

rti.com/blog

<!-- image -->

## Try a full version of Connext DDS for 30 days

TRY CONNEXT AT RTI.COM/DOWNLOADS

Includes resources to get you up and running fast

<!-- image -->

<!-- image -->

<!-- image -->

SHOWROOM.NXP.COM

PUBLIC

5 0