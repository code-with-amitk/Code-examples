## chroot
- Every process/command in Linux has root directory. chroot changes the root directory for currently running processes as well as its child processes.
- **jailed Directory?** A process/command that runs in such a modified environment cannot access files outside the root directory. This modified environment is known as “chroot jail” or “jailed directory”.
- **Use cases?** To create a test environment, To recover the system or password, To reinstall the bootloader.
- [Creating new root directory](Creating_chroot_jail.md)
