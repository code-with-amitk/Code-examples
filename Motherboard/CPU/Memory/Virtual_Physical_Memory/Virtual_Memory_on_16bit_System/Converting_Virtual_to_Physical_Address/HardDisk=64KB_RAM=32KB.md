## 16 bit system
- Virtual Memory/Hard Disk = 64KB. 64k/4k = 16 Pages  
- Physical Memory/RAM = 32 KB. 32k/4k = 8 Frames

> Page Size = 4KB = 4`*`1024 = 4096 Bytes. In Real systems Page sizes might be as large as 64KB.

<img src=https://i.ibb.co/pbTrjFn/virtual-physical.png width=300 />
                                                       
- **Ex1. MOV REG 0**
  - Program tries to access virtual address 0. Virtual address is sent to MMU for translation. 
```c
Code-Segment    
  MOV REG 0 ----> CPU
                   --Get Physical Address for 0--> MMU
                   <--Physical Address 8192-  Page-0 maps to Frame-2
//MMU has mapped all virtual addresses between 0-4095 onto physical addresses 8192-12287.                   
```                   
- **Ex2. MOV REG 8192**
```c
Code-Segment    
  MOV REG 8192 -> CPU
                   --Get Physical Address for 8192-->       MMU
                   <--Physical Add (24k=24x1024=24576)-- Page-3 maps to Frame-6
```
- **Ex3. MOV REG 20500**
  - 1stPage(0-4095), 2nd(4096-8191), 3rd(8192-12281), 4th(12282-16383), 5th(16384-20479), 6th(20480-24576)
  - 20500 falls 20 byte inside 6th Page.
```c
Code-Segment    
  MOV REG 20500 -> CPU
                    -Get Physical Address for 20500-->       MMU
                                                        Page-6 maps to Frame3
                    <--Physical Add 12302---- Frame-3-start:12282. PhysicalAdd=12282+20=12302
```
- **Ex4. MOV REG 24576** Request to reference a unmapped address(ie MMU does not have mapping).
  - [Page Fault](../../Terms.md)
  - [Page Eviction](../../Terms.md)
```c
Code-Segment
  MOV REG 24576 ---> CPU
                      --Return PhyAdd for 24576-> MMU
                      <---Not present--------------
                    trap() --Map 24576------------>
                                                      RAM(PM)                             Hard-Disk(VM)
                                                        --Frame=0 moved to VM-------------->
                                                        <-Page 24576 loaded in RAM(at address 0)--
                                            MMU(Updates Mapping)
                                            Page(12K not mapped)  
                                            Page-24K maps to Frame0
                      <---Virtual Address 0----
```
