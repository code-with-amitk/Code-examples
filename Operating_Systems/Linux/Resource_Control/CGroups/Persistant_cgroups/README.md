## Creating Persistant cgroup
- *1.* Open and add [Resource Control parameter(s)]() to Unit file.
```c
# vim /etc/systemd/system/sshd.service
...
[Service]
CPUShares=1500
```
- *2.* Apply changes by reloading systemd configuration using [systemctl](/Operating_Systems/Linux/Administration/Commands) and restarting service.
```c
# systemctl daemon-reload
# systemctl restart httpd.service
```
