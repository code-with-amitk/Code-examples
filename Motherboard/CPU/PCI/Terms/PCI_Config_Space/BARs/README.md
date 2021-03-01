## BAR(Base Address Register)
- **What?**
  - Each PCI Device will have some control registers, which will be mapped to Physical memory by device driver to access them.
  - BARs contains base address of those control registers.
  - Device can have upto six 32bit BARs. Two 32bit BARs can be combined to create 64Bit BAR.
- **6 BAR Registers**

|BAR No|offset|Purpose|
|---|---|---|
|0|0x10|<ul><li>Frame Buffer/Video Memory 64Bit</li></ul><ul><li><BAR0 on left 32 bits><BAR1 on right 32 Bits> = APERBASE </li></ul><ul><li>if we want to read beyond memory mapped by Frame Buffer. Place offset on MMINDEX_Register(0x00) and read data from MMINDEX_Register(0x04)</li></ul>|
|1|0x14|Combined with BAR0 makes frame buffer|
|2|0x18|Doorbell or REG_BASE_LO. When we write something on register, we write and set Doorbell. GPU reads it|
|3|0x1C|Doorbell or REG_BASE_HI|
|4|0x20|IO Base|
|5|0x24|<ul><li>Memory Mapped Register Space or Register Base Address or GPU Register Access = REGBASE</li></ul><ul><li>if we want to read beyond memory mapped by BAR5. Place offset on RSMU_Index_Register(0x50) and read data from RSMU_Data_Register(0x54)</li></ul>|
