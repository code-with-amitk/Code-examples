## Units
- systemd uses units to manage different types of objects. 

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
