## S32G2 PERIPHERALS

APRIL 2021

<!-- image -->

<!-- image -->

## PERIPHERAL OVERVIEW - NETWORKING

## FlexCAN with FD:

Quantity: 4

- Independent from LLCE

## Enhancements over previous generation:

- Rx FIFO is now independent of the MBs
- Depth of up to 20 messages
- Rx FIFO now available be used in FD mode
- 128 MBs
- Additional 64-byte MBs added
- Filtering improved
- Filter on range
- 32-bit Time Stamping option added
- Increased flexibility with bit timing

<!-- image -->

CAN

## FlexRay:

Quantity: 1

- In addition to FlexRay in LLCE
- Both modules identical
- Supports 2 channels
- Supports 256 MBs
- Does not support time stamping

## USB:

Quantity: 1

- USB 2.0 with OTG support
- ULPI interface to external phy.
- Supports:
- -High-Speed (480 Mbps)
- -Full Speed (12 Mbps)
- -Low-Speed (1.5 Mbps)

<!-- image -->

<!-- image -->

TM

<!-- image -->

## PERIPHERAL OVERVIEW - SERIAL COMMUNICATION

## DSPI:

Quantity: 6

- Separate from LPSPI modules in LLCE
- Available on mix of 3.3V and 1.8V pads
- DMA Support
- FIFO Depth: 5
- Supports 5 CS (5 as Master, 1 as Slave)
- Supports master and slave

## I2C:

Quantity: 5

- One required for PMIC
- Available on mix of 3.3V and 1.8V pads
- DMA Support

## LINFlex:

Quantity: 3

- Separate from LIN modules in LLCE
- Supports LIN slave mode
- Can also be used in UART mode

<!-- image -->

<!-- image -->

<!-- image -->

## PERIPHERAL OVERVIEW - OTHERS

## SAR ADC:

## Quantity: 2

- Supports 6 channels each
- Available on 1.8V pads only
- 12-bit resolution (approx. 8-bit accuracy)
- DMA support

## Others:

- Semaphore (x1 module, 16 semaphores)
- CRC (x1)

## Timers:

- PIT (x2 - total of 13x 32-bit timers)
- SWT (x7 - one per core)
- STM (x8)
- FlexTimer (2x6ch - DMA support)

<!-- image -->

<!-- image -->