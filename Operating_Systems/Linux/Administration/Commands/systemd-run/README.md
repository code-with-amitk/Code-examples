## systemd-run
- **What?** systemd-run may be used to create and start a transient systemd [`*.service` or `*.scope` unit](/Operating_Systems/Linux/Daemons_Processes_Services/Systemd_PID1) and run the specified COMMAND in it.

### Steps
- *1.* Create [Transient cgroup](/Operating_Systems/Linux/Resource_Control/Kernel_Namespaces/cgroup/RHEL_Provided_cgroup)
```c
//Create a new group called group1. Run top command inside that group. Name of command=amit_top.service
# sudo systemd-run --unit=amit_top --slice=group1 top -b
```
- *2.* Set amount of resource cgroup can use.
```c
//systemctl set-property --runtime    name          property=value
# systemctl set-property --runtime amit_top.service CPUShares=600 MemoryLimit=500M
```
- *3.* View information about control group.
```c
# systemd-cgls              //Entire cgroup hierarchy
├─system
│ ├─1 /usr/lib/systemd/systemd --switched-root --system --deserialize 20  
├─ group1.slice
|   ├─ amit_top.service
        ├─ 3714 /bin/top -b
....

# systemd-cgtop                         //View Resource,CPU,IO consumed by cgroup
Path                             Tasks   %CPU    Memory    Input/s   Output/s
/                                 260     3.4     658.9M      -         -
/group1.slice/amit_top.service      1      -        -         -         -
...
```
