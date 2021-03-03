## Booting up with systemd
- See booting up with init. Things are same till init process, here systemd
```c
 Power On > systemd process > Reads default.target(This is symlink to graphical.target) > 
 Reads /etc/system-d/system/multi-user.target (Sets env for multi-user support. Starts firewall services) >
 Reads basic.target (Starts graohical manager service) >
 Reads sysinit.target (Mounts system mounts, swap spaces, devices. Kernel additional options etc.) >
  Reads local-fs.target (Handles low level services. Performs actions on /etc/fstab, /etc/inittab)
```
- **Troubleshooting booting process?**
```c
//Built-in command to examine boot process. You can find out the units which are facing errors 
during boot up and can further trace and correct boot component issues.
  # systemd-analyze    

//shows the time spent in kernel,  and normal user space
  # systemd-analyze time
        Startup finished in 1440ms (kernel) + 3444ms (userspace)

//Prints a list of all running units, sorted  by the time taken by then to initialize, in this way you can have idea of 
  which services are taking long time to start during boot up.          
  $ systemd-analyze blame        
    2001ms mysqld.service
    234ms httpd.service
    191ms vmms.service

//Shows if there are any syntax errors in the system units. Systemd-analyze plot can be used to write down whole startup process to a SVG formate file.
# systemd-analyze plot > boot.svg        
```  
