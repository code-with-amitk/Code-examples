## Systemd
- (In fedora, RHEL, CentOS) This is Replacement of init process. Parent of all other processes. System and Service manager.
- **Advantages of systemd over init?**
  - *1.* systemd can start multiple services parallely(while init cannot) which reduces boot time of a system.
  - *2.* Ability to remove unneccessary services.
  - *3.* systemd itself takes less booting time wrt init.
- **[Units in systemd](Units)**
