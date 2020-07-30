# VIRTUAL AND PHYSICAL MEMORY
**Only Read Modern-Operating-System-Tanenbaum.pdf because internet is Garbage**

# A. VIRTUAL MEMORY
## What
- This is hard disk.
- **Concept** 
  - VM is bits and pieces of many programs in RAM/Physical memory at one time.
  - Each program has its own address space or virtual address space which is divided into fixed-size units called **pages**.
  - Units inside Physical Address space(RAM) are called **page frames**.
  - Pages are mapped to physical Memory(RAM), but not all pages have to be in physical memory to run the program.

## WHY VIRTUAL REQUIRED
- Now-a-days Complex programs require minimum `1 GB RAM`.
- Bigger programs need more RAM(>1 GB) and there are 10s of these on high end programs(Eg: in aircraft deisgning).
- So if 10 progmras are there each requiring `1 GB`, then system need to make `10 GB` available instantaneouly?

## Practical Example
- Consider a system have (Physical/Memory or RAM = 32KB) & (Hard Disk or Virtual Memory = 64KB).
![ImgURL](https://i.ibb.co/3Mk2pk3/virtual-physical.png)

- Memory is d
