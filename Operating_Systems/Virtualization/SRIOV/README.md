## SRIOV / Single root I/O virtualization
- **What?** Bypassing the hypervisor’s involvement in the communication between the driver and the hardware/devices.
- **Normal Device?**
```html
 VirtualMachine[user-space]                                  Hypervisor/kernel_space
Application[open/read/write/close]  <>  Device-File  <>        Device-Driver        Hardware-Device(Disk)
```
- **SRIOV Enabled Device**
  - The device appears as multiple separate devices and each can be configured by separate virtual machines.
  - Hardware Devices that support SR-IOV provide an independent memory space, interrupts and DMA streams to each virtual machine that uses it
```html
 <---------------------VirtualMachine[user-space]------------------->
Application[open/read/write/close]  <>  Device-File  <> Device-Driver        Hardware-Device(Disk)
```
