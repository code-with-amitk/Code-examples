## 3. (IO Base Address = BAR1 or BAR4 & 0000_fffe)
```c
    Program						BAR1(000a_0000)
    uint16_t wread
       ----Read BAR1 in uint16_t--->
       <---read(bn, dn, offset, &word)---
     if (word == 0)                                     BAR4(0000_3001)
       ----Read BAR4 in uint16_t--->
       <---read(bn, dn, offset, &word)---
     uint32_t ioBase = wread & 0000_fffe = 0000_3000
    }
```
