## System Memory
> Let's consider 4 TB space. Bits required to address = 40. 2<sup>40</sup> = 1x10<sup>12</sup>

## Sections of Memory
### Low Memory {0 - 1MB}
- This is carry over from old DOS days, hence we can still boot to DOS if needed.
- **What things are present here**
  - 1. System BIOS: Present on upper 128 k byte
  - 2. Interrupt vector table
  - 3. BIOS data area
  - 4. SMM Area
  - 5. Expansion ROM area
### SMM-TSeg  {8-32MB}
- System Management RAM.
### MMIO-Low {between 1-4G}
- These are not mapped to memory, this means access to this area will not go to physical memory.
- We have assumed MMIO-Low from 2G(but it can from 1G also).
