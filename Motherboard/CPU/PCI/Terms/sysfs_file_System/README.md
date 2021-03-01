## SYSFS File System
- sysfs file system is automatically mounted at /sys by kernel contains information of PCI devices on system.
```
# ls -ltr /sys/devices/pci0000\:00\                     //PCI devices in domain 0000
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:0.0    
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:07.0
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:07.1
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:08.0
```    
