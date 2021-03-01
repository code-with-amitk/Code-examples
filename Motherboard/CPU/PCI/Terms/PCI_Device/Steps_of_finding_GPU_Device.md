## Steps of finding GPU Device
- *1.* PCI Config Space is mapped from Physical to Virtual Memory from (Start_PCI_BusNo to End_PCI_BusNo) in MCFG Structure.
- *2.* Iterate all PCI Buses using for loop.
  - Skip Bus=0 (Since GPU Device is not expected at seg=0,bus=0)
```c++
  Read PCIConfig space in vector
  ++startBusNo;
  for (int i = startBusNo; i < EndBusNo; ++i) {
    readWord (offset=0, vendorId);               //Read 2 bytes
    readDWord (offset=0C, HeaderType);           //Read 4 bytes
    readWord (offset=0x62, DeviceStatus);
  }
```
