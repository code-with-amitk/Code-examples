- [Pre-requisites before starting troubleshooting](#pre)
- [DEBUGGING HUNG LINUX BOX](#hung)

<a name=pre></a>
### Pre-requisites before starting troubleshooting
1. Any recent changes made to the system(software patch, hardware replacements, driver updates, firmware updates, new software install, configuration changes)
2. Is it a VM or standalone? What's OS, kernel version?
```c
   # hostnamectl    //Centos
    static hostname: bngvm9019
    Chassis:    vm                                        <<<<<<<VIRTUAL MACHINE (can be desktop)
    OS:    CentOS Linux 7
    Kernel:    Linux 3.10.0-1160.6.1el7    <<<<<<<
    Architecture:    x86_64
```
3. OS version
```
   # cat /etc/*-release
    CentOS Linux release 7.9.2009 (core) 
```
4. Number of users logged in
```c
   # who
    amit pts/0 2021-01-02 10:13 (ip-address)
```
5. Connected PCI devices    `# lspci`
6. Connected usb devices    `# lsusb`

<a name=hung></a>
### DEBUGGING HUNG LINUX BOX
1. Is server pingable, How load is changing over time?
2. Configure kdump for next occurrence and test it.
3. System logs(if available).
```c
  System
    /var/log/bootlog : Boot logs
    /var/log/dmesg: Initializing all services, network etc
    /var/log/messages: System logs from systemd, yum, kernel
    /var/log/yum.log: What's newly installed/removed/updated on system.
  Security
    CentOS:/var/log/secure, Ubuntu:/var/log/auth.log: Eg Authentication using ssh, Commands issued using sudo, information from authentication module.
```
4. Which process(PID) is causing the load/slowness?
5. Configure sysrq
```c
/etc/sysctl.conf 
    kernel.sysrq = 1                    // physical console access extra abilities,
    kernel.panic_on_oops = 1 (Best Practice)        //Controls the kernel's behavior when an oops or BUG is encountered. 0: continue operation, 1: panic immediately.
# sysctl -p
```

