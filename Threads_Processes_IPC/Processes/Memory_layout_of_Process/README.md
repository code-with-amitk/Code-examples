## Memory Layout of Process
```console
                   |                                                                                                                         |
                   |                                       <-------DATA SEGMENT (static, global) ---------------------->                     |
[Kernel] Process-2 | [STACK] shared_libraries [PTR-To-HEAP] {Uninitialized_BSS(Block Started by Symbol)} {Initialized DS} [TEXT/CODE SEGMENT]|
                   |  ----->                                                                             <--RW--><--RO-->              0x0000|
                   |                                                                                                                         |
```
1. **[Code Segment](Code_Segment)**
