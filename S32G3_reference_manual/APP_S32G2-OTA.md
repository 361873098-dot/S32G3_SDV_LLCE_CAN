## S32G2 OVER-THE-AIR (OTA) USE CASE

APRIL 2021

<!-- image -->

PUBLIC

<!-- image -->

## CURRENT SITUATION WITH NO OTA UPDATES

Premium cars have over  100m lines of code (Windows 10 has 50m)

60% of warranty costs are SW related

Firmware updates require car to be returned to garage

No guarantees that customer will return car for recall

Firmware updates time consuming for garages to carry out

Difficult to deliver new features to customers

<!-- image -->

## OTA UPDATES

Allows the vehicle to receive firmware updates wirelessly via Wi-Fi, cellular, radio, etc.

## Benefits for OEM:

- -Save OEMs money
- No recall required for software fix
- -Ability to immediately patch critical bug
- Increase safety and security level of the car
- -Allow addition of new features, post-purchase
- Support new consumer devices / protocols, real new functions e.g., Tesla autopilot

## OEM Demands:

- -Minimal effect on drivers (e.g., minimal/no vehicle down time during update)
- -No risk of failed update leaving car unusable
- -Security to prevent rogue updates/IP theft

<!-- image -->

## CURRENT STATE OF THE MARKET

<!-- image -->

- OTA updates available for IVI and TCU only
- All other nodes updated at dealership via OBD

<!-- image -->

## Key OTA Concepts

<!-- image -->

PUBLIC

4

## BACKGROUND: OVER THE AIR (OTA) UPDATE METHODS 1/2

In general, there are 2 methods for performing updates to a node

## In Place:

Update is performed on top of existing version

<!-- image -->

## Advantages:

- No need for additional flash

## Disadvantages:

- Requires vehicle downtime during update process
- Not possible to instantly 'roll-back' if an issue occurs

Note that bootloader is typically not updated via OTA.

<!-- image -->

<!-- image -->

## BACKGROUND: OVER THE AIR (OTA) UPDATE METHODS 2/2

## A/B:

Two versions of firmware exist in internal flash.

<!-- image -->

## Advantages:

- Update can be carried out whilst application is actively running from flash
- Always have original firmware to roll back to in case of issue
- Vehicle always available - guaranteed no vehicle downtime regardless of update errors

## Disadvantage:

- Requires 2x flash application storage
- Higher max current (run current in block A + erase/program current in block B)

Note that bootloader is typically not updated via OTA.

<!-- image -->

## BACKGROUND: UPDATE FIRMWARE FORMATS (1/2)

There are two formats in which the firmware can be delivered. Both formats can be used with A/B and In-Place update methods.

## Full Binary:

The binary of the application is sent to the end-node to be updated. This can be programmed as-is to the flash.

New Firmware

## Advantages:

- No requirement placed on previous firmware (e.g., can update from any previous version number and if previous firmware is corrupt)
- Minimal processing of received file - simply program into flash

## Disadvantage:

- Takes longer to transmit (500 Kbps CAN Network…)
- Requires larger storage space

<!-- image -->

## OTA Architecture

<!-- image -->

PUBLIC

8

## FULL VEHICLE FOTA UPDATE FLOW

<!-- image -->

<!-- image -->

## OEM CLOUD SERVER

- Vehicle Database
- Contains details of all vehicles by VIN / serial number
- Lists software currently on each vehicle
- Manages dependency between firmware versions on multiple nodes
- Software Database
- Contains all software, firmware, maps, etc.
- Generates diff files is required
- Real time monitoring and reporting
- Receives usage information and error codes from active vehicles
- Able to poll vehicles to update local database

<!-- image -->

<!-- image -->

## BACKEND CONNECTION (TCU)

## IP connectivity

- Establishes physical communication link and IP connections
- Handles multiple comms protocols (Wi-Fi, cellular, radio, V2X, etc.)

## Logical connectivity to cloud servers (services)

- → Depends on vehicle architecture. Logical connections can also be managed by gateway.
- Authenticates the vehicle and server
- Uses Secure Element as root of trust
- Establish secure connection between vehicle and OEMs server
- Handle loss of connection issues
- Hand off package to the OTA Manager

<!-- image -->

<!-- image -->

## OTA MANAGER (GATEWAY)

- Contains database of all ECUs
- Perform hashing and authentication on received image
- Unpack the received file and split for individual ECUs
- Stores updates until ready to install
- Can be used to create diffs
- Synchronise updates across multiple nodes
- Establish secure channel with end ECU
- Prompt IVI to display update details to driver (if required)
- Commence UDS diagnostic session with end node
- Success message is reported back to the cloud

<!-- image -->

<!-- image -->

## SOFTWARE: UDS

Unified Diagnostic Service - defines data link independent diagnostic services

- Underpins the OBD

| • Request diagnostic data from ECU                        | Ethernet      |
|-----------------------------------------------------------|---------------|
| • Request emissions data                                  | UDS           |
| • Clear/Reset trouble codes • Request vehicle info, etc.  | DOIP          |
| • Allows flashing of ECUs                                 | TCP           |
| End node requires minimal version                         | IP            |
| • Supports responses and reflashing only                  | CAN           |
| • Code size in the KBs • Already present in most end ECUs | UDS           |
|                                                           | CAN TP        |
| OTAManager - need to run stack in gateway • Size >10 MB   | CAN Interface |
| • Historically the stack ran on an off-board tester       | CAN Driver    |

.

<!-- image -->

## OTA MANAGER SCENARIOS 1

<!-- image -->

Telematics handles backend connection, gateway coordinates all updates.

## PROs:

- Physical isolation between gateway and TCUs large attack surface

## CONs:

- Large amount of data passing through the gateway
- IVI has high attack surface and is inside firewall

<!-- image -->

Telematics handles backend connection, gateway co-ordinates all updates except IVI.

## PROs:

- Physical isolation between gateway and TCU/IVIs large attack surface
- Off-loads large, bandwidth consuming IVI traffic from GW

## CONs:

- Removes layer of protection from IVI

<!-- image -->

## OTA MANAGER SCENARIOS 2

<!-- image -->

Telematics handles IP connection establishment. Gateway handles all logical connection management to OEM backend directly.

## PROs:

- Management of external connectivity related to NON-IVI ECUs behind firewall and treated separately

## CONs:

- Higher BOM

<!-- image -->

Telematics and gateway merged to single device, handles backend connection, and all updates.

## PROs:

- BOM cost reduction

## CONs:

- Security risk if TCU and GW functions are not properly isolated

<!-- image -->

## END NODE (OTA CLIENT)

- Verify/Authenticate image
- Decrypt image (optional)
- Use version number to confirm firmware is new
- Perform diff calculation (diff updates only)
- Erase flash block
- Program update
- Switch to new version and notify OTA Manager

## Software:

- Runs on the end node to be updated
- Performs actual the flashing operation
- Typically works along with bootloader
- Can be very small (&lt;2K)

<!-- image -->

<!-- image -->

## Security

<!-- image -->

PUBLIC

1 7

## OTA SECURITY

- -Protect the authenticity and integrity of firmware to prevent a hacker from running modified code
- -Encrypt the firmware to prevent a hacker from accessing code (IP) and data
- -Establish secure end-to-end communication between the vehicle and OEM servers to prevent man-in-the-middle attacks.
- -Ensure a secure, trusted location for the OTA Manager application

Should not overlook the fact that OTA Updates greatly increases security by allowing any exploits to be quickly patched

<!-- image -->

## SECURITY DURING UPDATE PROCESS

## Secure Element:

- Trust anchor
- Ensures secure authentication between vehicle and server
- Secure tamper proof storage of keys and certificates
- Used in ePassports and bank cards

<!-- image -->

<!-- image -->

## S32G2 Updates

<!-- image -->

PUBLIC

2 0

## OTA UPDATES

From the Boot Flow slides, we see that the NXP hardware and firmware controls the booting of the following:

- DCD Records
- HSE Firmware
- Customer Bootloader

The Customer bootloader then loads the customer application using a software defined method.

Therefore, there is a separate update method depending on what needs updating.

<!-- image -->

## EXTERNAL MEMORY CONTENTS

<!-- image -->

Version selected by Customer Bootloader

Version selected by IVT

Locked - not updatable

<!-- image -->

The IVT contains primary and backup addresses for each boot element. If no header is found at primary location, then backup address will be searched.

## Backup location can be:

- Exact copy of primary code
- New or older version of primary code
- Small recovery application
- Erased/Invalid

<!-- image -->

## UPDATING DCD / HSE FIRMWARE / CUSTOMER BOOT CODE

## A/B Method

- Create a backup of the current working version in the location of the IVT's backup pointer
- Erase the primary image including the bootheader. This means that a booting of that image will fail, and the device will auto boot from the backup image.
- Program the content of the primary pointer, except the boot header.
- Verify the new code and data.
- Finally, program the boot header at the primary pointer.
- Upon next boot, the BootROM will boot the new firmware.

## In Place Method

Erase primary image and program new image. Image will be unusable for duration of update.

Bootloader and HSE will not be updated regularly and will be relatively small - therefore, it may be acceptable to do an 'in-place' update in which case a backup version of the code would not be required.

<!-- image -->

## UPDATING CUSTOMER APPLICATION

The loading of the application will be covered by the customer's bootloader - the process is therefore customer defined.

One method is to have a table of boot vectors and version numbers in OTP flash. With the latest entry pointing to the latest image.

- The update flow:
- Erase old firmware block
- Program the new code image
- Verify the new code image
- Program new version number and location to OTP flash
- Upon next boot, the bootloader loads the new version

<!-- image -->

## Implementation Use Case

<!-- image -->

PUBLIC

2 5

<!-- image -->

Domain

## Implementation Use Cases

The following slides will highlight various different nodes within the vehicle and explore the options available to update them via OTA.

<!-- image -->

<!-- image -->

Domain

## Example ECU A

Flash:

2x internal flash available

Security:

Supports CMAC authentication

and AES-128 decryption

Connection to Gateway: FlexRay™

Vehicle Downtime: none

Security: high

## Steps:

1. Encrypted binary trickle downloaded and stored onto empty 'B' flash on ECU.
2. Firmware is decrypted and integrity checked as it is downloaded. Allows end2end security.
3. Once download complete, GW switches ECU to use new firmware from next boot.

<!-- image -->

<!-- image -->

Domain

## Example ECU B

Flash: Internal flash with external NAND flash for local storage of new binary

Security: Supports CMAC authentication and AES-128 decryption

Connection to Gateway:

CAN

Vehicle Downtime: long

Security: high

## Steps:

1. Encrypted binary downloaded and stored onto GW. Checks authentication and integrity.
2. GW sends to ECU as a background task - stored in external NAND.
3. Update triggered by GW carried out during vehicle downtime. Binary decrypted by ECU.

<!-- image -->

<!-- image -->

## Example ECU C

Flash:

Internal flash with 1 free block

Security:

No cryptographic security

Connection to Gateway:

CAN

Vehicle Downtime: long

Security: none

## Steps:

1. Encrypted diff file downloaded and stored onto GW NAND. Checks authentication and integrity.
2. During vehicle downtime, GW decrypts file and sends to ECUs RAM.
3. Update has to be sent over last step as plaintext (obfuscation algorithm can be used) ECU then execute update process reprogramming necessary blocks.

<!-- image -->

<!-- image -->