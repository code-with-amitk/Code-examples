## systemctl
- [systemd](/Operating_Systems/Linux/Daemons_Processes_Services/Systemd_PID1) utility that is responsible for Controlling the systemd system and service manager.

### Examples
- Listing units commands
```c
# systemctl -t help                             //List all available units of systemd
# systemctl --all list-units | grep .service    //lists all available units in the type service.
abrt-ccpp.service
abrt-ops.service
abrt-vmcore.service
```
