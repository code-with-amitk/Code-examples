## Virtualization
- **What?** 1 computer hosting multiple virtual machines, each VM running different operating systems.
- **Advantages?**
  - *1.* For companies(like Amazon or Microsoft), which runs 1000s of servers(all different OS), installing seperate machine for every Task would eat their Pocket.
  - *2. Easy Migrations:* Migrating OS/application to VM is much easier wrt OS
  - *3.* Software development:* if programmer wants to check his application works on Windows 10, centos, mac etc. Installing all OS on 1 is easy instead of all on different machines.
- **[History](History_of_Virtualization.md)** 
- **VMM(Virtual Machine Monitor)/Hypervisor?** Creates the illusion of multiple (virtual) machines on the same physical hardware. Types of VMMs:
  - *1. TYPE-1/NATIVE/BARE-METAL/ESXI:* Run directly on the host’s hardware. Eg: Citrix Xenserver, microsoft Hyper-V, VMWare ESX/ESXi.mid
  - *2. TYPE-2/HOSTED:* Run as a software layer on an operating system, like other computer programs. Eg: VMWare Work Station, VM-Ware Player, Virtual box, QEMU

<img src="hypervisor_vmm.png" width=500 />

- **Major Hypervisors?**
  - *1. XEN:* Open source Linux based type-1. 
  - *2. VMWARE ESXI:* 
  - *3. HYPER-V:* Hypervisor by Microsoft.
    - *3A. AZURE* Runs on customized version of Hyper V. Its hardened and stripped down.
  - *4. KVM:* Open source Linux based. Used in RHEV(Redhat Enterprise Virtualization).
