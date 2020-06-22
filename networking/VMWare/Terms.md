## Terms
### A. HYPERVISOR/VMM(virtual machine monitor) 
  - **What?**
    - A process that creates and runs virtual machines (VMs). This is combination of software+Firmware+Hardware.
    - A hypervisor allows one host computer to support multiple guest VMs by virtually sharing its resources, like memory and processing.
  - **Types of Hypervisors?**
    1. ***Type-1/Bare-metal/Native/ESXI***: Run directly on the host’s hardware. Eg: Citrix Xenserver, microsoft Hyper-V, VMWare ESX/ESXi.mid
    2. ***Type-2/Hosted***: Run as a software layer on an operating system, like other computer programs. Eg: VMWare Work Station, VM-Ware Player, Virtual box, QEMU.

![ImgUrl](https://i.ibb.co/R7Y4vtX/hypervisor.png)
