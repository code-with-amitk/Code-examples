## Units
- These are Processes/Resources/Services running in background that are managed by systemd. These are defined in unit files.

### Types of Units
- **a. `*.service:`** Service units have a .service extension and represent system services.
```c
# systemctl list-units --type=service                        //List all service units installed 
# systemctl list-units --type=socket --all                   //List all socket units, active and inactive
# systemctl start | is-active | reload | list-dependencies sshd.service       //View status/reaload/list-dependencies of service
```    
- **b. `*.socket`:** Socket units have a .socket extension and represent inter-process communication (IPC) sockets that systemd should monitor. 
- **c. `*.path`:** Delay the activation of a service until a specific file system change occurs.
- **d. `*.target`:** 
  - To define the various system states, the SysV uses numbers, known as run-levels, while the Systemd uses keywords, known as target-units. Eg: Graphical, Multiuser, Rescue, Emergency    //See runlevel on Linux page

### Commands
- **Dependent services:** A Service may be dependent on 0 or more services, stopping/restarting 1 may require start/stop others also
```c
# systemctl    list-dependencies    <unit>    //Prints tree of units those must be started if this unit is started.
```
- **Masking Services:** A system may have conflicting services installed. Eg: iptables, firewalld. Masking service means if service is started by mistake nothing will happen.
```c
    # systemctl    mask/unmask     network    
        ln -s '/dev/null' '/etc/systemd/system/network.service'     
    # systemctl    mask/unmask    iptables
```    
- **List services**
```c
# systemctl    list-units        //To see all units(Processes/Resources/Services) present on system
        UNIT                                                  LOAD   ACTIVE     SUB       DESCRIPTION
        proc-sys-fs-binfmt_misc.automount     loaded     active         running   Arbitrary Executable File For
        sys-devices-pci0000:00-0000:00:02.0-drm-card0-card0\x2deDP\x2d1-intel_backlight.device loaded active plugged   /sys/devices/pci0000:00/0000:
        .................................... 
# systemctl    list-units | grep .service        //If only want to see services on system
# systemctl    list-units    --type=socket    //List All socket units
# systemctl    --failed            //All failed units
```
