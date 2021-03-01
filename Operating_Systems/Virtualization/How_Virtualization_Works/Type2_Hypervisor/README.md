## How Type2 Hypervisor works?
- See [Type1 Hypervisor](/Operating_Systems/Virtualization/How_Virtualization_Works/Type1_Hypervisor) working 1st to understand this.
- **Problem?** Since Type-2 Hypervisor itself is not in kernel space, if some user want to install some [ISR](/Operating_Systems/Linux/Kernel/Interrupts) or signal handler how he can do?
  - *Solution?* Most modern type 2 hypervisors therefore have a kernel module operating in ring 0 that allows them to manipulate the hardware with privileged instructions.
