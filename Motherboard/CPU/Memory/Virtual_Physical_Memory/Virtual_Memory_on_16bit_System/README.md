### Virtual Memory on 16 bit System = 16 bit bus 
- **Address Bus?**
  - Can access 2<sup>16</sup> = 65535 = 64KB Memory. To address 65536 17 bits are needed.
  - On 16 bit system you can plug huge Hard disk but that will be no use, since in 1 go Only 2 bytes can be accessed.

- **[Example-1: Hard Disk=64KB, RAM=32KB]()**

### A1. Conversion of Virtual to Physical Address  (16 Bit system)
> Consider a 16 bit system having following.

||Virtual Memory/Hard Disk|Physical Memory/RAM|
|---|---|---|
|Size|64KB|32KB|
|Count|64k/4k = 16 Pages|32k/4k = 8 Frames|

- Page Size = 4KB = 4`*`1024 = 4096 Bytes. In Real systems Page sizes might be as large as 64KB.
![ImgURL](https://i.ibb.co/pbTrjFn/virtual-physical.png)

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

### A2. 16 bit system = Page-No(4 bits) + Offset(12 bits)
**32 bit system**:    Page-No(20 bits) + Offset(12 bits)    //anywhere offset is always 12 bit

- To access every bit of 64 kilibytes memory, we would need 16 bits. 2<sup>16</sup> = 65535 = 64KB
- 1 page=4KB=4096 bytes. 64x1024/4x1024 = 16 Pages. 64KB will have 16 pages.
- 2<sup>4</sup> = 16. With 4 bits we can access every 16 page.
- 2<sup>12</sup> = 4096. With 12 bits we can access every bit in page.
- **How Physical Address is converted to Virtual Address?**
  - Offset(12 bits) are copied as such. From Page-No(4 bit), frame number is constructed.
  
![ImgURL](https://i.ibb.co/86bzCf4/MMU-opearation.png)   
