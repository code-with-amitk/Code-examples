## BAR5 = Memory Mapped Register Space 
- This is Where GPU Registers are present
```c
    BIOS						BAR5(d0a0_0000)
       ----Read BAR5 in uint32_t--->
       <---read(bn, dn, offset=0x24, &dword)---
 uint64 registerBaseAddress = d0a0_0000 & 0xffff_fff0;	      //0000_0000_d0a0_0000

    if (BAR5 & 0x04){       //Check if 64 bit
       //does not go inside
    }
```
