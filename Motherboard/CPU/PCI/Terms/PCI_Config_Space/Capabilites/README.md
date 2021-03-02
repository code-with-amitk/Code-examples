## Capabilities
- **What?** Some PCI Devices may have extra capablities (Eg: GPU device may have [SRIOV](/Operating_Systems/Virtualization/SRIOV) support) while others(Eg: Host bridge) may not have.
- **Capabilities Pointer / offset = 0x34**
  - Every device is represented as a [function](/Motherboard/CPU/PCI/Terms/PCI_Device). This is offset into this Device's configuration space pointing to a linked list of capabilities implemented by the device.
  - Used if bit 4 of the status register (Capabilities List bit) is set to 1.
- **[Reading Capabilities](Reading_Capabilites)**
