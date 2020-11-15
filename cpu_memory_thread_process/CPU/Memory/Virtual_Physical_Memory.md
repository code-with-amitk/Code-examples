```diff
- Only Read Modern-Operating-System-Tanenbaum.pdf because internet is Garbage
```
## Virtual Memory & Physical Memory

[MyYouTube Video For Understanding](https://www.youtube.com/watch?v=OjGycsu0I1M)

||Virtual Memory = Hard Disk|Physical Memory = RAM|
|---|---|---|
|What|This is Hard Disk|This is RAM|
|Size|Always Bigger|Smaller from HD|
|Contains|**Pages** inside Virtual Table|**Frames** inside Page Table. Pages & Frames are of same size.|
|Memory Allocation|Contigous|Contigous|

- **Why VM needed?** Now-a-days programs are RAM hungry. every other program(eg: adobe photoshop, microsoft teams) need more RAM. if 10 such processes want to run simultaneously then 10GB RAM is needed which is not available. VM is illusion to program that it has complete access to RAM.
- **Paging** Process of dividing Hard-Disk to equal-sized blocks is called paging.
- **MMU(Memory Management unit)** Takes Virtual address(of Virtual Memory) as Input provides Physical Address(of RAM) as output ie translate virtual to physical address.

## A. Conversion of Virtual to Physical Address
> Consider a system having following.

||Virtual Memory/Hard Disk|Physical Memory/RAM|
|---|---|---|
|Size|64KB|32KB|
|Count|64k/4k = 16 Pages|32k/4k = 8 Frames|

- Page Size = 4KB = 4`*`1024 = 4096 Bytes. In Real systems Page sizes might be as large as 64KB.
![ImgURL](https://i.ibb.co/GCFwbL0/virtual-physical.png)

- **Ex1. MOV REG 0**
  - Program tries to access virtual address 0. Virtual address is sent to MMU for translation. 
```c++
Code-Segment    
  MOV REG 0 ----> CPU
                   --Get Physical Address for 0--> MMU
                   <--Physical Address 8192-  Page-0 maps to Frame-2
//MMU has mapped all virtual addresses between 0-4095 onto physical addresses 8192-12287.                   
```                   
- **Ex2. MOV REG 8192**
```c++
Code-Segment    
  MOV REG 8192 -> CPU
                   --Get Physical Address for 8192-->       MMU
                   <--Physical Add (24k=24x1024=24576)-- Page-3 maps to Frame-6
```
- **Ex3. MOV REG 20500**
  - 1stPage(0-4095), 2nd(4096-8191), 3rd(8192-12281), 4th(12282-16383), 5th(16384-20479), 6th(20480-24576)
  - 20500 falls 20 byte inside 6th Page.
```c++
Code-Segment    
  MOV REG 20500 -> CPU
                    -Get Physical Address for 20500-->       MMU
                                                        Page-6 maps to Frame3
                    <--Physical Add 12302---- Frame-3-start:12282. PhysicalAdd=12282+20=12302
```
- **Ex4. MOV REG 24576** Request to reference a unmapped address(ie MMU does not have mapping).
  - **Page Fault**? CPU issues trap() system call. OS picks a LRU Frame(from Physical Memory/RAM) and moves/writes back to the Hard-Disk/Virtual-Memory. Then copies Page into RAM. MMU updates mapping.
  - **Page Eviction:** Movement of pages in/out of RAM is done by SWAPPER.
```c++
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

## B. Fragment/Page No(4 bits) + Offset(12 bits) 
- For 64k Virtual Memory. MMU uses 16 bit scheme.
- Virtual Page(4 bit) 
  - 2<sup>4</sup> = 16. With 4 bits we can access 16 pages.
  - Page no is used as index into Page Table, outputting the Physical Page no.
  - This is always high order bits.
  - However 3 or 5 bits can also be taken for the page. Different splits imply different page sizes.
- OFFSET(12 bit)
  - 2<sup>12</sup> = 4096. With 12 bits we can access all 4096 bits inside a page.
  - These are always low order bits.
![ImgURL](https://i.ibb.co/86bzCf4/MMU-opearation.png)   

### VPN(Virtual Page Number)
- This is content of virtual-table.
- This is used as an index into the page table to find the mapping for that virtual page.
- And then from Page-Table, Page-Frame is found.
- VPN + offset creates actual Physical Address. See Below example.

| **Present/Absent bit ->** | 1 | 1 | 1 | 0 | ... |
| --- | --- | --- | --- | --- | --- |
| **VPN ->** | 0010 = 2 | 0001 = 1 | 0110 = 6 | 0000 |  |
| **Index ->** | 0 | 1 | 2 | ... | 15 |

### Accessing the pages/CONVERSION OF VIRTUAL to PHYSICAL Addresses
#### Mov REG 8196
- Access address=8196. This is virtual address. Binary=0010000000000100. PageNo=0010, Offset=000000000100
- virtual_table`[page_no]` = virtual_table`[0010]` = virtual_table`[2]` = 110 = 6
  - Access 6th page frame.
- Physical-Address = `0110``000000000100` = `output_of_virtual_table_entry=VPN``offset_copied_as_it_is` = 0110000000000100
- If the Present/absent bit is 0, a trap to the OS is caused.
