## Socket Unit
- Socket units have a .socket extension and represent inter-process communication (IPC) sockets that systemd should monitor. 
```c
# systemctl list-units --type=socket --all                   //List all socket units, active and inactive
```
