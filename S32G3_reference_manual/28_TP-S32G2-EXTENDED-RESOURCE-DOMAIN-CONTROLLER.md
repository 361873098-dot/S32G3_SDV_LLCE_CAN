## S32G2 XRDC

E X TENDED R ESOURCE D OMAIN C ONTROLLER

APRIL 2021

<!-- image -->

PUBLIC

NXP, THE NXP LOGO AND NXP SECURE CONNECTIONS FOR A SMARTER WORLD ARE TRADEMARKS OF NXP B.V. ALL OTHER PRODUCT OR SERVICE NAMES ARE THE PROPERTY OF THEIR RESPECTIVE OWNERS. © 2021 NXP B.V.

<!-- image -->

## EXTENDED RESOURCE DOMAIN CONTROLLER (XRDC) SUMMARY

- Extended Resource Domain Controller manages access control, system memory protection and peripheral isolation.
- It allows software to assign chip resources (cores, non-core bus masters, memory regions and slave peripherals) to domains .
- These domains have a defined access control policy for each privilege level . This is based on Arm's Supervisor and User levels, with additional secure and nonsecure states.
- Applications co-exist on same silicon with static firewall between them.
- Support for Arm ® TrustZone scheme.
- Example use cases:
- Isolating real time and non-real time application elements
- Isolate safety critical and non-safety critical code
- Isolate cores running third party untrusted from cores running trusted code base

<!-- image -->

<!-- image -->

## S32G2 SECURE RESOURCE ISOLATION USING XDRC

<!-- image -->

- XRDC manages access control from bus masters to system memory and peripherals
- XRDC can be used to create logically isolated secure memory(and peripherals)
- Bus Masters attach to a 'Domain'
- M7 masters can have multiple domains (task assigned)
- Bus Slaves support region descriptors / access control, based on domain of access(TZ aligned)

<!-- image -->

## XRDC COMPONENTS

## MDAC: Master Domain Assignment Controller

- Assigns a domain identifier (DID) attribute to every bus transaction. Does this based on:
- Master ID (fixed value per bus master)
- Process ID (discussed later…)
- Can optionally alter the secure/priv bits

## MRC: Memory Region Controller

- Enforces memory region access policies based on:
- Domain ID
- Privilege/User state of transaction
- Secure/Non Secure state of transaction

## PAC: Peripheral Access Controller

- Enforces peripheral access control policies based on:
- Domain ID
- Privilege/User state of transaction
- Secure/Non Secure state of transaction

## XRDC Manager

- Register interface to programming model

control

<!-- image -->

<!-- image -->

## XRDC SIMPLE REPRESENTATION

- Bus Master (e.g. M7 core): Makes a bus transaction e.g., a read access. This transaction will contain the address along with 'sideband signals' including:
- Master ID number (fixed value assigned to each bus master)
- Secure/non-secure bit: denotes if the master was in a secure or non-secure state when the transaction occurred
- 0=secure, 1=non-secure
- Priv/user mode: denotes if the master made the transaction whilst in user or privilege mode
- 0=user, 1=priv

## · MDAC

- Assigns a domain ID to the transaction based on master ID and process ID. The master ID sideband is removed at this point.
- MRC/PAC : transaction then passes through MRC/PAC depending on whether it is addressed to memory or peripherals respectively.
- The MRC/PAC decides if the access is valid by looking at the address and the secure/non-secure and user/priv bit.

<!-- image -->

Key point: Secure and Priv sidebands are not used by the MDAC but they affect the permissions at the MRC/PAC.

(MDAC can alter the secure/priv bits under certain conditions discussed later)

<!-- image -->

## XRDC PARAMETERS

S32G2 has 2 instances of the XRDC.

- -XRDC0 is for the main subsystem
- -XRDC1 is for the Accelerator subsystem

Accesses flow between the instances - so a PFE access will be assigned a domain by an XRDC1 MDAC and this domain number will be evaluated at an XRDC0 slave the same as if the transaction had come from XRDC0 based MDAC.

| Parameter                                  |   XRDC0 Value |   XRDC1 Value | Total                             |
|--------------------------------------------|---------------|---------------|-----------------------------------|
| Master Domain Assignment Controller (MDAC) |            19 |             8 | 27                                |
| Memory Region Controller (MRC)             |            14 |             6 | 20                                |
| Peripheral Access Controller (PAC)         |             4 |             1 | 5                                 |
| Domains                                    |             8 |             8 | 8 (shared across both instances)  |
| Semaphores (in SEMA42 module)              |            16 |            16 | 16 (shared across both instances) |

Note that the XRDC is disabled by default and is configured and enabled by boot code.

<!-- image -->

## Master Domain Assignment Controller (MDAC)

<!-- image -->

PUBLIC

6

## MDAC (MASTER DOMAIN ASSIGNMENT CONTROLLER)

- Generates a domain ID for every master transaction
- -Multiple masters can exist in a single domain
- -Cores have 8 MDACFG each - can therefore be assigned to up to 8 domains based on Process ID
- -If there is no match at the MDAC then access is given a DID of 0 .
- -Non cores have single MDACFG
- Always assigned to same domain (unless DID\_in is used like DMA in virtual environment)
- Assigned domain could theoretically be updated at run time.
- Notes:
- -some master have a secure/nonsecure output, others are hard wired
- -A53 has one MDAC per cluster
- -M7 cores have 2 MDACs per core (for AHB and AXI ports)

## XRDC0

| Submodule instance   | Configuration   |   Numberof MDA_Wx_y_DFMTz registers | Busmaster         | Non-secureinput1   |
|----------------------|-----------------|-------------------------------------|-------------------|--------------------|
| XRDC_MDACO           | Processor       |                                   8 | Cortex-A53C0      | Inputfrommaster    |
| XRDC_MDAC1           | Processor       |                                   8 | Cortex-A53 C1     | Input from master  |
| XRDC_MDAC2           | Nonprocessor    |                                   1 | Debug ETR         | Input from master  |
| XRDC_MDAC3           | Nonprocessor    |                                   1 | GIC-500           | Input from master  |
| XRDC_MDAC4           | Nonprocessor    |                                   1 | Reserved          | 1                  |
| XRDC_MDAC6           | Nonprocessor    |                                   1 | eDMA_0            | 1                  |
| XRDC_MDAC7           | Nonprocessor    |                                   1 | eDMA_1            | 1                  |
| XRDC_MDAC8           | Processor       |                                   8 | M7_0 AXI          | Input from master  |
| XRDC_MDAC9           | Processor       |                                   8 | M7_1 AXI          | Inputfrommaster    |
| XRDC_MDAC10          | Processor       |                                   8 | M7_2 AXI          | Input from master  |
| XRDC_MDAC11          | Nonprocessor    |                                   1 | HSE               | Inputfrommaster    |
| XRDC_MDAC12          | Nonprocessor    |                                   1 | GMAC_0 (Ethermet) | Input from master  |
| XRDC_MDAC15          | Nonprocessor    |                                   1 | FlexRay           | 1                  |
| XRDC_MDAC16          | Processor       |                                   8 | M7_0 AHB          | 0                  |
| XRDC_MDAC17          | Processor       |                                   8 | M7_1 AHB          | 0                  |
| XRDC_MDAC18          | Processor       |                                   8 | M7_2 AHB          | 0                  |
| XRDC_MDAC19          | Nonprocessor    |                                   1 | LLCE              | 1                  |
| XRDC_MDAC20          | Nonprocessor    |                                   1 | uSDHC             | Input frommaster   |
| XRDC_MDAC21          | Nonprocessor    |                                   1 | Debug trace       | Inputfrommaster    |

MDAC5: PCIe\_0 (missing from this table) MDAC8-10: Non-secure input tied to 0

## XRDC1

| Submodule Instance   | Conflguratlon   |   Number ot MDA_Wx_y_DFMTz reglsters | Bus master   | Non-secure Input   |
|----------------------|-----------------|--------------------------------------|--------------|--------------------|
| XRDC_MDACO           | Nonprocessor    |                                    1 | PCle_1       | Input from master  |
| XRDC_MDAC1           | Nonprocessor    |                                    1 | PFE_HIFO     | 1                  |
| XRDC_MDAC2           | Nonprocessor    |                                    1 | PFE_HIF1     | 1                  |
| XRDC_MDAC3           | Nonprocessor    |                                    1 | PFE_HIF2     | 1                  |
| XRDC_MDAC4           | Nonprocessor    |                                    1 | PFE_HIF3     | 1                  |
| XRDC_MDAC5           | Nonprocessor    |                                    1 | PFE_DDR      | 1                  |
| XRDC_MDAC6           | Nonprocessor    |                                    1 | PFE_UTIL     | 1                  |
| XRDC_MDAC7           | Nonprocessor    |                                    1 | USB          | 1                  |

<!-- image -->

## PROCESS IDENTIFIER (PIDN) REGISTERS

- Each core master has a PID register - the holds a 6 bit value which represents the process currently running.
- This register needs to be updated by software (e.g. by scheduler of hypervisor) upon a task switch in the core)

PID[5]

PID[5] can override core inputs and select secure/non secure state when the PID is in 'three-state mode' (TSM is enabled on a PID by PID basis)

## PID[4:0]

PID[4-0] used to group tasks into different domains (masking is available to allow multiple processes to share a domain)

- The MRC and PAC are not aware of PID - it is only used by MDAC
- The PIDn register must be written in secure/priv mode and can be locked to individual masters

00b-Registercanbewrittenbyanysecure privilegedwrite.

01b-Registercanbewrittenbyanysecure privilegedwrite.

10b-Register canonlybewrittenbyasecure privileged write frombus master m.

11b -Register is locked (read-only) until thenextreset.

Note: PID register cannot be used on A53 cores

<!-- image -->

## MDAC FOR M7 CORES

<!-- image -->

- Cores in lockstep share the same ports so MDAC configuration applies to both cores.
- Note that the AXI and AHB ports have separate MDACs which need to be configured individually.
- For most use cases same configuration would be used for each.
- SW must update both PID registers on a task switch.
- M7 core does not support TrustZone so core has no of concept of secure/non-secure mode. All accesses are treated as secure unless software uses PID[5] bit to override.
- Priv bit comes from core's priv/non\_priv status and cannot be altered by MDAC.
- Core MDACs also have a DID\_in value of 0 but this has no valid use.

<!-- image -->

## MDAC FOR A53 CORES

<!-- image -->

## Recommendation:

Each A53 core has an MMU, use this to isolate memory and peripheral accesses rather than XRDC.

- Both cores in A53 cluster share same AXI port.
- Both cores have same Master ID. Process ID register is shared between both cores so is of limited use.
- A53 supports TrustZone so the secure\_in signal will reflect the state of the core which made the access.
- Priv bit comes from core's status which is reflected in the AXPROT[0] signal. Please consult the core documentation for more details.

<!-- image -->

| Table7-10Cortex-A53MPCoremodeandARPROTandAWPROTvalues   | Table7-10Cortex-A53MPCoremodeandARPROTandAWPROTvalues                                                                                                   | Table7-10Cortex-A53MPCoremodeandARPROTandAWPROTvalues   |
|---------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| Processorexceptionlevel                                 | Typeof access                                                                                                                                           | ValueofARPROT[O]                                        |
| EL0,EL1,EL2,EL3                                         | Cacheable read access                                                                                                                                   | Privileged access                                       |
| EL0                                                     | Device, or normal Non-cacheable read access                                                                                                             | Unprivileged access                                     |
| EL1, EL2, EL3                                           |                                                                                                                                                         | Privileged access                                       |
| EL0,EL1, EL2, EL3                                       | Cacheable write access                                                                                                                                  | Privileged access                                       |
| EL0                                                     | Device, nGnRnE, nGnRE, and nGRE write                                                                                                                   | Unprivileged access                                     |
| EL1,EL2,EL3                                             |                                                                                                                                                         | Privileged access                                       |
| EL0                                                     | Nomal Non-cacheable or Device GRE write, except for STREX, STREXB, STREXHSTREXD,STXR,STXRB,STXRH,STXP,STLXR,STLXRB,STLXRH and STLXP to shareable memory | Privileged access                                       |
| EL0                                                     | Normal Non-cacheable write for STREX,STREXB,STREXH,STREXD,STXR STXRB, STXRH, STXP, STLXR, STLXRB, STLXRH and STLXP to shareable memory                  | Unprivileged access                                     |
| EL1,EL2,EL3                                             | Normal Non-cacheable write                                                                                                                              | Privileged access                                       |
| EL0, EL1, EL2, EL3                                      | TLB page walk                                                                                                                                           | Privileged access                                       |

<!-- image -->

## MDAC FOR A53 CORES - CORE DIFFERENTIATION

<!-- image -->

## Summary:

For accesses to peripheral space, XRDC can identify a core within a cluster e.g., a DMA can inherit a permission from a core rather than just a cluster

- A53 MDACs have a special DID-in port. This can be used to tell which core owns the transaction:
- 0b10 - core 0
- 0b11 - core 1

These bits are concatenated with the domain ID in the register:

•

DID[3:0] = user defined[3:2] + DID\_in[1:0]

- Example output:
- Core differentiation feature is only available for specific accesses:
- accesses to non-reorderable device memory (e.g., peripherals)
- store exclusives,
- barrier operations
- Accesses to normal memory or reorderable device memory cannot be precisely identified

|   [o:c]ala | Description   |
|------------|---------------|
|          2 | cluster0, cp0 |
|          3 | cluster0, cp1 |
|          6 | cluster1, cp0 |
|          7 | cluster1, cp1 |

<!-- image -->

## A53 HW ISOLATION OVERVIEW

- The table below shows which HW isolation mechanism is used for accesses from a specific master to a slave.
- This also shows the granularity available.
- DMA Peripherals are IP blocks which can make memory mapped accesses (e.g., eDMA, HSE, PFE, etc.)

<!-- image -->

*If memory region is configured as strongly ordered, then XRDC could be used at core level.

<!-- image -->

## MDAC FOR NON-CORE MASTERS

<!-- image -->

- Non-core masters have no concept of PID so this signal is not used
- Secure and priv input signals can either come from the master or will be fixed in hardware (e.g., for FlexRay™, all accesses are fixed to non-secure).
- Non-core MDACs can alter the secure and priv signals using the SA and PA bits:

Oob - Force the bus atlribute for this master to secure.

01b -Force the bus attribute for this master to nonsecure.

10b - Use the bus master's secure/nonsecure altribute directly.

11b - Use the bus master's secure/nonsecure altribute directly.

- Domain ID input signal set to 0 except for the case of the eDMA - see next slide for details.

<!-- image -->

## MDAC FOR NON-CORE MASTERS - EDMA

<!-- image -->

The DMA can mimic the domain of the requestor which setup the job it is carrying out. This means that the DMA can only access the same locations as the requestor which set it up

- When a task writes to the DMAs 'Transfer Control Descriptor' (TCD) to setup a job, the domain of the requestor is logged in hardware.
- When that TCD is triggered, all accesses from the DMA use Domain ID from the TCD. This prevents an unsecure requestor from requesting the DMA copy data from a secure location into a non-secure space which it can access.
- It does this by using the did\_in value and bypassing and domain assignment within the MDAC. This option is enabled using the DIDB bit:

<!-- image -->

<!-- image -->

## Memory Region Controller (MRC) and Peripheral Access Controller (PAC)

<!-- image -->

PUBLIC

1 5

## MRC / PAC

- Each slave port has either an MRC or a PAC depending on whether it is a memory or a peripheral
- The MRC/PAC evaluates the access and decides whether to grant access based on:
- Domain ID, Priv bit and Secure bit of the transaction
- Access to the configuration registers needs to be from a master in Secure/Priv mode. PACs:

Granularity: Permissions can be set on a per peripheral basis

- PAC to peripheral Mapping can be found from memory map spreadsheet as shown below

## XRDC0 PACs:

| Module name   | Slavesprotected    |
|---------------|--------------------|
| XRDC_PACO     | Peripheral group 0 |
| XRDC_PAC1     | Peripheral group 1 |
| XRDC_PAC2     | Peripheral group 2 |
| XRDC_PAC3     | Peripheral group3  |

## XRDC1 PACs:

| Module name   | Slavesp protected   |
|---------------|---------------------|
| XRDC_PACO     | Peripheralg group 0 |

## Memory Map:

<!-- image -->

| Peripheral description     | Size (KB)   | Start address (hex)   | End address (hex)   | XRDC PDAC slot   |
|----------------------------|-------------|-----------------------|---------------------|------------------|
| Peripheral group 1         |             |                       |                     |                  |
| SWT 0                      | 4           | 40100000              | 40100FFF            | 128              |
| reserved (padding for 16K) | 12          | 40101000              | 40103FFF            |                  |
| SWT 1                      | 4           | 40104000              | 40104FFF            | 129              |
| reserved (padding for 16K) | 12          | 40105000              | 40107FFF            |                  |
| SWT 2                      | 4           | 40108000              | 40108FFF            | 130              |
| reseved (padding for 16K)  | 12          | 40109000              | 4010BFFF            |                  |
| SWT 3                      | 4           | 4010C000              | 4010CFFF            | 157              |

<!-- image -->

## MRC

## MRCs:

- Each MRC has a specific number of region descriptors - these are used to setup memory regions with individual permission settings Each descriptor consists of:
- Start Address
- End Address
- Access permissions per domain
- Granularity: 32 bytes
- Note: DRAM1 is not present on S32G so this should be ignored
- Note: as SRAM accesses are interleaved, the MRC config must be replicated across (2 and 3 - covering 0x34000000 - 0x343FFFFF) and (4 and 5 - covering 0x34400000 - 0x347FFFFF). The result is that there are 32 regions across the whole SRAM.
- If transaction address is not covered by an MRC descriptor, then the access is rejected.
- For 'mirrored' address spaces an MRC must be configured for each address range e.g.,

| Startaddress (hex)   | Endaddress (hex)   |   Size (KB) | 40-bit Master Description   |
|----------------------|--------------------|-------------|-----------------------------|
| 00XO 0055 0000       | 00X0 53FF FFFF     |       16384 | PCle                        |
| 0x58 0000 0000       | 0x5F FFFF FFFF     |          32 | PCle_0 (0 - 16MB mirrored)  |

## XRDC0 MRCs:

| Submoduleinstance   |   Number of region descriptors | Slaves protected,module(port number)                                                                 |
|---------------------|--------------------------------|------------------------------------------------------------------------------------------------------|
| XRDC_MRCO           |                             16 | DRAMO_COHERENT(O), DRAM0_M7_EDMA(1), DRAMO_GENERAL(2)                                                |
| XRDC_MRC1           |                             16 | DRAM1_COHERENT(O), DRAM1_M7_EDMA(1), DRAM1_GENERAL(2)                                                |
| XRDC_MRC2           |                             16 | SRAM_1(0), SRAM_2(1), SRAM_3(2), SRAM_0(3)                                                           |
| XRDC_MRC3           |                             16 | SRAM_5(0), SRAM_4(1), SRAM_6(2), SRAM_7(3)                                                           |
| XRDC_MRC4           |                             16 | SRAM_9(0), SRAM_8(1), SRAM_11(2), SRAM_10(3)                                                         |
| XRDC_MRC5           |                             16 | SRAM_12(0), SRAM_13(1), SRAM_14(2), SRAM_15(3)                                                       |
| XRDC_MRC6           |                             16 | Ncoreregisters(1) and coherent accessesofPCle_O,GMAC_O,and othermasterswithaccesstothisslave port(0) |
| XRDC_MRC7           |                             16 | S_FLASH(O)(External)                                                                                 |
| XRDC_MRC8           |                             16 | S_LLCE(0)                                                                                            |
| XRDC_MRC9           |                             16 | S_GIC-500(0)                                                                                         |
| XRDC_MRC10          |                             16 | S_PCle(0)                                                                                            |
| XRDC_MRC11          |                             12 | M7_TCM(0)                                                                                            |
| XRDC_MRC12          |                              4 | FlexNoC_0 registers(0)                                                                               |
| XRDC_MRC13          |                             16 | S_DBG_APB(O)                                                                                         |

## XRDC1 MRCs:

| Submoduleinstance   | Numberofdescriptors   | Slavesprotected,module(port number)   |
|---------------------|-----------------------|---------------------------------------|
| XRDC_MRCO           | 4                     | STDBY_SRAM                            |
| XRDCMRC1            | 4                     | LLCE                                  |
| XRDC_MRC2           | 16                    | Concerto                              |
| XRDC_MRC3           | 4                     | PCle_1                                |
| XRDC_MRC4           | 4                     | PFE                                   |
| XRDC_MRC5           |                       | Service_Regs                          |

<!-- image -->

## SRAM MRC

In order to maximise multi-host bandwidth, accesses to the SRAM blocks are interleaved in hardware. This impacts the MRCs as follows:

- MRC2/3, SRAM{0-7} work together to support the interleaved SRAM scheme and are mapped to the lower 4 MB address range 0x34000000 - 0x343FFFFF.
- MRC4/5, SRAM{8-15} work together to support the interleaved SRAM scheme and are mapped to the upper 4 MB address range 0x34400000 - 0x347FFFFF.
- As such, MRC 2 and 3 should be programmed identically. As should MRC 4 and 5.
- Granularity: Due to the interleaving mechanism, the granularity of the SRAM regions is multiple of 256-bytes.

<!-- image -->

## PERMISSION SETTING (MRC AND PAC)

- Access rights are configured the same way for MRC and PAC:
- -Each MRC/PAC descriptor has 8 fields to set the permission for each of the 8 domains
- -Access rights for each domain is set using a 3-bit value as shown in Valid Permission Table
- -E.g., For a memory region descriptor has the following settings:
- Domain 0 Permissions = 000
- Domain 1 Permissions = 011
- Etc…

| ACCESS DETAILS   | ACCESS DETAILS   | ACCESS DETAILS   | ACCESS DETAILS    | ALLOWED     |
|------------------|------------------|------------------|-------------------|-------------|
| Access Domain    | Priv State       | Secure State     | Access Type (r/w) | OR BLOCKED? |
| 0                | Any              | Any              | Any               | Blocked     |
| 1                | Any              | Secure           | R                 | Allowed     |
| 1                | Any              | Unsecure         | R                 | Blocked     |

A transaction is aborted, and details are captured in the error handling registers if:

- No address hits
- If single hit which results in a permission violation
- If multiple hit which ALL result in permission violation

## Valid Permissions:

|        | AllowableAccesses   | AllowableAccesses   | AllowableAccesses   | AllowableAccesses   |
|--------|---------------------|---------------------|---------------------|---------------------|
| Policy | Secure Priv         | Secure User         | Nonsecure Priv      | Nonsecure User      |
| 111    | W                   | W                   | r,w                 | r， W                |
| 110    | r W                 | W                   | r, W                | none                |
| 101    | W                   | W                   |                     |                     |
| 100    | P M                 | M                   | r                   | none                |
| 011    | W                   | W                   | none                | none                |
| 010    | r W                 | none                | none                | none                |
| 001    |                     |                     | none                | none                |
| 000    | none                | none                | none                | none                |

<!-- image -->

## XRDC ACCESS PERMISSIONS

<!-- image -->

| Asset                  | Secure and Privileged Write Required?   | Can be locked to a specific master ID?   | Only Accessible by same domain?   | Can be locked to protect from further writes?   |
|------------------------|-----------------------------------------|------------------------------------------|-----------------------------------|-------------------------------------------------|
| MDAC Registers         |                                         |                                          |                                   |                                                 |
| PID Registers          |                                         |                                          |                                   |                                                 |
| MRC Registers          |                                         |                                          |                                   |                                                 |
| PAC Registers          |                                         |                                          |                                   |                                                 |
| Domain Error Registers |                                         |                                          |                                   |                                                 |

<!-- image -->

## DRAM ADDRESS SPACE

- The DRAM appears at a different address on the M7 mem map compared to other masters:
- The MRC for the DRAM sees the master address (i.e., an access to the first location of DRAM will appear as 0x6000\_0000 if access is from M7 and as 0x8000\_0000 if access is from A53)
- -Therefore, care must be taken when setting up descriptors to take into account this difference
- -Recall that descriptors have a start/end address and then access permissions per domain
- -Also note that no descriptor = no access

| Start address (hex)   | End address (hex)   | 32-bit Master Description Size (KB) (except M7)   | M7 Description           |
|-----------------------|---------------------|---------------------------------------------------|--------------------------|
| 0x0060000000          | 0x00_7FFF_FFFF      | 524288                                            | DDR_0 (0 - 512M bytes)   |
| 0x0080000000          | 0x00 9FFF FFFF      | 524288DDR_0 (0-512M bytes)                        | DDR_0 (512M -1G bytes)   |
| 0x00 A0000000         | OxO0 BFFF FFFF      | 524288DDR_0 (512M - 1G bytes)                     | DDR_0 (1G to 1.5G bytes) |
| 0x00 C000 0000        | OxO0 DFFF FFFF      | 524288 DDR_0 (1G to 1.5G bytes)                   | DDR_0 (1.5G - 2G bytes)  |
| 0x00E0000000          | OxO0 FFFF FFFF      | 524288DDR_0 (1.5G -2G bytes)                      | M7 PPB + Systems space   |

<!-- image -->

<!-- image -->

5 region descriptors required (vs 4 for unified map)

<!-- image -->

<!-- image -->

2 region descriptors required (vs 2 for unified map)

<!-- image -->

<!-- image -->

5 region descriptors required (vs 4 for unified map)

<!-- image -->

## EXAMPLE DRAM MRC DESCRIPTORS -2 X   S M A L L   S H A R E D   R E G I O N ,   R E S T   D E D I C AT E D   T O   A 5 3

<!-- image -->

6 region descriptors required (vs 4 for unified map)

<!-- image -->

## SEMAPHORE INTEGRATION

- Each MRC and PAC descriptor can also be assigned a semaphore (from the separate SEMA42 module) to control write accesses to that memory region/peripheral
- Whether a semaphore is required along with which semaphore to use is set on a descriptor-bydescriptor basis
- There are a total of 16 semaphores to be shared across the chip
- If semaphore is enabled, then it is checked prior to the access evaluation decision
- E.g.:
- The domain which owns the semaphore has write access - other domains are unable to write but can read
- If semaphore is not owned by any domain, then all writes are enabled
- This allows for dynamic control of access rights

<!-- image -->

## Error Handling

<!-- image -->

PUBLIC

2 7

## ERROR REACTION

- XRDC has no interrupts of its own.
- An illegal access will trigger an exception on the source core.
- The exception will depend on the access type.

Example:

Cortex M7: could trigger BusFault (vector 5)

Cortex A53: could trigger DATA\_ABORT (vector 4)

BusFault

A BusFault is an exception that occurs because of a memory related fault for an instruction or data memory transaction. This might be from an error detected on a bus in the memory system.

Non-core master: triggers a 'Bus Error' - it is down to the individual master how it reacts to this. E.g., eDMA has its own error logging facility and can optionally trigger an error interrupt.

Therefore, it is not possible for a 'monitoring core' to be notified of another master causing an exception .

<!-- image -->

## ERROR CAPTURING

- Upon a violation, address and attribute information is captured in the Domain Error Registers (DER)
- DERRLOCn - points to which PACs and MRCs have triggered errors. One per domain so n=0 to 7

There are then an array of 4 words entries which separately cover the MRCs and PDACs. m 0 to 14 are MRCs, 15 to 19 are the PACs

- DERRm\_W0 - gives access address that generated access violation
- DERRm\_W1 - Gives attributes of error e.g., Which MRC detected error, What kind of access violation, which domain?
- DERRm\_W2 - unused
- DERRm\_W3 - Used to Re-arm error capture register once exception is complete. W0 and W1 are cleared.

## Usage:

- -Only the domain, which case the error can read the registers.
- -Error registers can only be accessed whilst in secure, privileged mode
- Read HWCFG1 to find the DomainID (n) which caused the error, then go direct to that DERRm register Note that the errors are stored by domain. The master ID is not logged.

<!-- image -->

## Software Enablement

<!-- image -->

PUBLIC

3 0

## SOFTWARE ENABLEMENT

- RTD XRDC driver available now
- -Supports graphical configuration through the EB tresos tool

<!-- image -->

<!-- image -->

<!-- image -->