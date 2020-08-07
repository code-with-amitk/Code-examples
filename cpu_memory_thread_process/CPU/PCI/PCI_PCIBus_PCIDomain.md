## A. PCI(Peripheral Component Interconnect)
- **What**
  - This is a standard that describes how to connect the peripheral components of a system together in a structured and controlled way.
  
## B. PCI-Bridges
- These are used to connect more than 1 PCI bus to the system. Bridges joins the PCI buses.
 - Overall layout of a PCI system is a tree where each bus is connected to an upper-layer bus, up to bus 0 at the root of the tree.

## C. PCI Domain
- Earlier there were 32 devices connected to 1 PCI bus. But this was not sufficient for many large systems. 
- PCI specifications allowed creation of PCI domains. Each domain can have upto 
- 1 PCI Domain can have:
	- 256 Buses
	- 32 PCI devices/Bus
	- 8 functions/Device
	- Config Space Register/function
 		- 256(PCI), 4096(PCIe)
- Each device(Eg: CD-ROM drive) can be a multifunction board with a maximum of eight functions. Each function is identified by 2-byte address, or key.
```
	|<--    pci-domain-1    --->|<--    pci-domain-2    -->|<--    pci-domain-n    --->|
	 upto 256 pci buses
	 1 bus=32 devices
	 1 device=8 functions
```
