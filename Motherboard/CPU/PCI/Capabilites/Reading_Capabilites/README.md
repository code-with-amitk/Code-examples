## Reading Capabilites of Device
- *1.* Push all devices which are SRIOV capable on vector.
```c
class CPCI_EE_SRIOVCaps : CPCI_caps {
  uint16 caps_offset;
  uint16 caps_id;
  uint16 caps_next_ptr;
  uint16 caps_size;
};

1. Scan PCI devices
2. if pci device is has capability pointer set?
  - Push the device=segment,bus,dev,fun_no on vector<CPCI_EE_SRIOVCaps*> = | 0x21 | 0x89 | ... 
- 
```
