## Memory Layout of Process
```console
                   |                                                                                                |
                   |                           <------DATA SEGMENT (static, global) ----------->                    |
[Kernel] Process-2 | [STACK] shared_libraries {PTR-To-HEAP} {Uninitialized_BSS} {Initialized DS} [TEXT/CODE SEGMENT]|
                   |  ----->                                BlockStartedBySymbol <-RW--><--RO-->              0x0000|
                   |                                                                                                |
```
1. **[Code / Text Segment](Code_Segment)**
2. **[Data Segment](Data_Segment):** Also contains Pointer to heap
3. 
