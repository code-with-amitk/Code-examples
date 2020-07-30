# VIRTUAL AND PHYSICAL MEMORY
**Only Read Modern-Operating-System-Tanenbaum.pdf because internet is Garbage**

# A. VIRTUAL MEMORY
## What
- This is hard disk.
- **Concept** 
  - VM is bits and pieces of many programs in RAM/Physical memory at one time.
  - Each program has its own address space or virtual address space which is divided into fixed-size units called **pages**.
  - Units inside Physical Address space(RAM) are called **Frames**. Pages and frames are of *SAME SIZE*.
  - Pages are mapped to physical Memory(RAM), but not all pages have to be in physical memory to run the program.

## WHY VIRTUAL REQUIRED
- Now-a-days Complex programs require minimum `1 GB RAM`.
- Bigger programs need more RAM(>1 GB) and there are 10s of these on high end programs(Eg: in aircraft deisgning).
- So if 10 progmras are there each requiring `1 GB`, then system need to make `10 GB` available instantaneouly?

## Practical Example
- Consider a system having 
  - Physical/Memory or RAM = 32KB
  - Virtual Memory or Hard Disk = 64KB
    - To access 64KB = `64*1024`Bytes = 65536'th bit computer genereates 16 bit addresses. 65536 = 2<sup>16</sup>. These are VIRTUAL ADDRESSES.
  - Page Size = 4KB = `4*1024` = 4096 Bytes
    - In Real systems Page sizes might be as large as 64KB.
    - **How many PAGES**
      - Virtual Pages = 64KB/4KB = 16     //Means 16 pages on Hard Disk
      - Physical Pages = 32KB/4KB = 8     //8 frames on RAM

![ImgURL](https://i.ibb.co/rZ1K6S7/virtual-physical.png)

- Memory is d
