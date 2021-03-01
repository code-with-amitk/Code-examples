## SRIOV / Single root I/O virtualization
- **What?** Bypassing the hypervisor’s involvement in the communication between the driver and the hardware/devices.
### SRIOV Device
  - There is only 1 Physical device, which appears as seperate device to all VMs(each having its own pvt copy).
  - Hardware Devices that support SR-IOV provide an independent memory space, interrupts and DMA streams to each virtual machine that uses it
  - Example: A SRIOV network interface, a virtual machine is able to handle its virtual network card just like a physical one. 
```html
 <---------------------VirtualMachine[user-space]------------------->
Application[open/read/write/close]  <>  Device-File  <> Device-Driver        Hardware-Device(Disk)
```

### Physical and Virtual Functions
- **Physical Function?** PFs are full PCIe functions ie access to complete PCIe space. This is not available to Guest OS.
- **Virtual Function?** VFs provide to virtual devices.
