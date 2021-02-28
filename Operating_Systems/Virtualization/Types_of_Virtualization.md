## Types of Virtualization
### 1. Full Virtualization
- Achieved using VMM. Whenever VM(userland) want to go in kernel space, VM traps VMM, which in turn traps kernel.
  - Note: TRAP instruction is used by user-space process to move to kernel space.
- Whole responsibilty of executing system call or in kernel space lies with VMM.

### 2. Para Virualization
- VMs has responsility to execute/help in running system calls or inside kernel space. Unlike full virtualization.
- This model provides **HYPERCALLS.** With hypercalls guests/VMs does kernel specific tasks(Eg: updating page tables) in cooperation with the hypervisor, making overall system can be simpler and faster
