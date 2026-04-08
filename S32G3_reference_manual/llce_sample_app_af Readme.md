Sample App Readme

This is about llce\_sample\_app\_af  read me file

This sample application uses the the driver interface to demonstrate in a simply way the functionality of LLCE Firmware, AUTOSAR CAN driver and AUTOSAR LIN driver.

This resumes in sending multiple CAN frames in loopback from one channel to another over the external bus or throw internal routing. Also, 2 different hosts can manange Llce simultaneously.

The application can be built using GNU Makefile version &gt;= 4.2.1 (check make --version), using make command with specific targets itemized below.

## Prerequisites

* SW32\_RTD\_4.4\_4.0.0\_D2210.exe

* S32G\_LLCE\_1\_0\_5\_D2210.exe

## Description

## Environment

1. Every CAN demo sends and receives frames in loopback. Every 2 controllers in pairs (eg. 0-1, 2-3) are directly connected on the EVB in order to check sending and receiving frames in the same time. Every demo has an EB Tresos project which contains configurations for filters, internal routing filters and destination channels, chosen host interface and logging filters.
2. Multiple baudrate configurations for this sample application are available and can be referenced in EB Tresos, in each CanController configuration. Default baudrate chosen in every demo has index 1 in tresos and corresponds to a baudrate of 500 Kbps in Nominal Phase and 2 Mbps in FD Phase. The others configs are (index 0: 250Kbps, 500 Kbps) and (index 2: 1Mbps, 4Mbps). When configuring another baudrates, be aware of Tresos warnings.
3. A solution for loading the firmware and enabling the ECC RAM is provided in platform\_common/firmware\_loading folder, by raw bytes from host memory to LLCE internal memory and enable LLCE cores in order to start running.
4. The Can driver does the timeout detection (seconds) for non-blocking functions using the Os APIs OsIf\_GetCounter and OsIf\_GetElapsed.
5. Clock tree initialization and Llce partition activation are done using RTD MCU driver.
6. For demos involving multicore usage, if you want to further develop the sections in linker files, be careful to keep split the sections memory areas between cores, like int\_sram, int\_sram\_no\_cacheable, int\_sram\_stack, int\_shared\_ram.
7. The LIN demo uses hardware channels 2 and 3, which are connected through an wire on the development board. In order to use the hardware channels 0 and 1, a dedicated hardware switch must be configured.
8. Every demo has an associated EB Tresos project. All of them are created for the S32G2 target, except for a single one which is found under tresos/s32g3 path.

## CAN Loopback demo

- This demo does simple sending and receiving frames from one channel to the other connected through wire.
- It involves all the 16 CAN channels.
- It can be built using: make can\_loopback
<!-- image -->

The Host is sending messages to every controller. Since all BCANs are in LoopBack, the message will be received by the Controller that is paired to the Controller which sent the message.
In the example above, the Host is sending a can message with id 0 to Controller0. Controller1 will receive this message because of the wired loopback, and will forward the message to the host.

## LIN Loopback demo

- This demo creates a master-slave communication between 2 nodes.
- It can be built using: make lin\_loopback

## CAN2CAN demo

- This demo does internal simple routing, routing with changing frame from Can to CanFD, routing with changing frame from CanFD to Can, routing with Can Id remapping.
- It can be built using: **make can\_routing**
<!-- image -->

In this test, the Host is sending frames to Controller1 which is wired in loopback with Controller0.
Controller0 has assigned advanced features, which can apply to the frames it receives based on the message ID of the frame.

Examples:

- Messages received by Controller0 with ID 888, will be forwarded to Controller1 with the ID of the message changed to 999
- Messages received by Controller0 with ID 15 will simply be forwarded to Controller15
- Messages received by Controller0 with ID 321 will be transformed from CAN-FD to CAN and forwarded to Controller15
- Messages received by Controller0 with ID 123 will be transformed to CAN-FD and forwarded to Controller15
- Messages with ID 1 have the routing option OFF

## MULTIHOST demo

- The configuration specifies 8 controllers assigned to host1 and other 8 assigned to host2.
- They are sending frames simultaneous through LLCE. The demo generates 2 elf files, corresponding to every host, which takes half of the SRAM each one for the code area.
- It can be built using: **make can\_multihost**

### Using Wired Loopback inside the same Host (First part)

<!-- image -->

In the first part, the Host is sending frames using Controller1.
Controller1 is in **wired Loopback** with Controller0, so the frames will be received by Controller0 and fed back to the Host.

### Using wired LoopBacks (Second part)

<!-- image -->

In the second part, Host1 sends frames to Host2 by using internal routing feature and external loopbacks (wired loopbacks).

The frames will be sent from Host1 to controller 5, which is in **Wired Loopback** with Controller4.
Then, using the advanced feature Can2CanRouting Controller4 will forward the frames to Controller11. Then, the frames will be routed to controller 9 (using the **Wired Loopback** ) and received by controller 10 which will send them to Host2.

### Using LoopBack mode (Third part of the test)

<!-- image -->

In this test, Host1 is using Controller7 to send a frame to Host2.

Controller7 is set to **LoopBack Mode** (so it will receive the frame that it just sent), and also **Self Reception** is enabled, so it can receive the frames that it actually sent (see picture below).

<!-- image -->

Using the advanced feature Can2CanRouting , Controller7 forwards the message to Controller12, which is also set in **LoopBack Mode** and **Self Reception** mode, so Controller12 will actually receive the frame and forward it to Host2.

## Building the application

1. Edit the paths in config.mk. Note that you can select the platform.
2. make using the following options: can\_loopback, can\_routing, can\_multihost, lin\_loopback

Note: make can be executed in multithreaded mode, e.g.: make -j8 can\_loopback.

## Running the application

1. Open the corresponding cmm script (for either S32G2 or S32G3) from tools/cmm\_scripts in Trace32.
2. Edit the script by selecting one of the described options (default is CAN\_LOOPBACK)
3. Run the script.

The lines containing \_DEBUG\_MODE will open the app in debug mode, meaning that the user has to go through step-by-step.

The lines NOT containing \_DEBUG\_MODE will automatically run until the end of the test.