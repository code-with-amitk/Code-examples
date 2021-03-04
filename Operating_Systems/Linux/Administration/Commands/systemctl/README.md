## systemctl
- [systemd](/Operating_Systems/Linux/Daemons_Processes_Services/Systemd_PID1) utility that is responsible for Controlling the systemd system and service manager.

### Examples
- Listing units commands
```c
# systemctl -t help                             //List all available units of systemd

//////////SERVICE UNIT///////////
# systemctl --all list-units | grep .service    //lists all available units in the type service.
  abrt-ccpp.service
  abrt-ops.service
  abrt-vmcore.service
# systemctl start | is-active | reload | list-dependencies sshd.service       //View status/reaload/list-dependencies of service
# systemctl list-dependencies <unit>                            //Prints tree of units those must be started if this unit is started.
# systemctl    mask/unmask     network        //Masking service



///////////SOCKET UNIT///////////////
#systemctl list-unit-files | grep .socket       //status of socket units
```
