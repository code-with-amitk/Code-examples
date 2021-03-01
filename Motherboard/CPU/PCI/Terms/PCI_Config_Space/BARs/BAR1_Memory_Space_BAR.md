## 1. Memory Space BAR
```c
|16byte Aligned Base Address(28 bits)|Prefechable(1 bit)|Type(2 bit)|0(1 bit)|   //LSB: Always 0
Type:
  |-0: 32bit decoder.	//Means This PCI device can access addresses from 0-4GB. 2^32 = 4GB. BIOS will mmap this device's Memory(after header) to MMIO_LOW.
  |-2: 64bit decoder.	//This PCI device can access addresses from 0-16ExaBytes. BIOS can allocate space from MMIO_LOW or MMIO_HIGH. In this case next BAR is ganged together.
  |-1: Not used
Prefechable: Base address region does not have read side effects
```
