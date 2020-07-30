# VIRTUAL AND PHYSICAL MEMORY
**Only Read <div class="text-purple">Modern-Operating-System-Tanenbaum.pdf</div> because internet is Garbage**

# A. VIRTUAL MEMORY
## 1. What
- This is hard disk.
- **Concept** 
  - VM is bits and pieces of many programs in RAM/Physical memory at one time.
  - Each program has its own address space or virtual address space which is divided into fixed-size units called **PAGES** and Process of dividing Hard-Disk to equal-sized blocks is called **PAGING**.
  - Units inside Physical Address space(RAM) are called **FRAMES**. Pages and frames are of *SAME SIZE*.
  - Pages are mapped to physical Memory(RAM), but not all pages have to be in physical memory to run the program.
  - Tranlation from Virtual to Physical Address is done by **MMU**.

## 2. WHY VIRTUAL REQUIRED
- Now-a-days Complex programs require minimum `1 GB RAM`.
- Bigger programs need more RAM(>1 GB) and there are 10s of these on high end programs(Eg: in aircraft deisgning).
- So if 10 progmras are there each requiring `1 GB`, then system need to make `10 GB` available instantaneouly?

## 3a. Example
- Consider a system having 
  - Physical/Memory or RAM = 32KB
  - Virtual Memory or Hard Disk = 64KB
    - To access 64KB = 64`*`1024Bytes = 65536'th bit computer genereates 16 bit addresses. 65536 = 2<sup>16</sup>. These are VIRTUAL ADDRESSES.
  - Page Size = 4KB = 4`*`1024 = 4096 Bytes. In Real systems Page sizes might be as large as 64KB.
    - **How many PAGES**
      - Virtual Pages = 64KB/4KB = 16         //Means 16 pages on Hard Disk
      - Physical Pages = 32KB/4KB = 8         //8 frames on RAM
    - Every page begins on a multiple of 4096 and ends 4095, so 4K-8K really means 4096-8191 and 8K to 12K means 8192-12287.      
![ImgURL](https://i.ibb.co/rZ1K6S7/virtual-physical.png)

### 3b. Accessing the pages/CONVERSION OF VIRTUAL to PHYSICAL Addresses
> Never try accessing Virtual address directly. Its not real address and will result in corruption.
#### 1. `MOV REG 0`
- Program tries to access address 0. 0 is the virtual address. Virtual address is sent to MMU for translation.
- 0 falls on 1st page (0-4k) which according to its mapping is page frame 2(8192-122870). MMU sends 8192 onto Bus
- Please note, Bus does not know anything about addresses, whichever address is placed on it carries
#### 2. `MOV REG 8192` = `MOV REG 8k`
- Page(8192) maps to page-frame-6(24k = 24`*`1024 = 24576)
- `MOV REG 8192` becomes `MOV REG 24576`
#### 3. Acesss virtual address `20500`
- On Virtual-table 20500 falls on 5th page(20k = 20`*`1024 = 20480). 
- But 20500 is not start of page but it falls 20 inside. 20500 = 20480 + 20. Here 20 is **OFFSET**.
- To access Physical address, offset is added = (12k + 20) = 12`*`1024 +20 = 12288 + 20 = 12308. 
- Address 12308 is placed on Bus.
#### 4. `MOV REG 32780` = `MOV REG 32k+12` 
- **Request to reference a unmapped address**.
- Now, MMU finds page in unmmaped, CPU **TRAPS the OS**. This is called **PAGE FAULT**.
  - **Page Fault**? OS picks a least-used page frame and writes its contents back to the disk, then copies page into page frame changes mapping, and restarts the trapped instruction. This is called **Page Eviction**. Movement of pages in/out of RAM is done by **SWAPPER**.
    - Example Let OS decides to evict Page number=0. 
      - Page=0 is mapped to frame=2, ie at physical address 8192.
      - Virtual Page 8 = 32k is loaded into physical memory 8192.
      - Changes done in MMU.  a. Make entry of virtual-page=0(as unmapped)  b. Place 1 at frame=2 at Virtual-Page-8's entry.

