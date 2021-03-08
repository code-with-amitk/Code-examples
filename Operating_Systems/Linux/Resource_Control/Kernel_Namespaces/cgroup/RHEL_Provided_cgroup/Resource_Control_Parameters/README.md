## Resource Control Parameters
- These are parameters to manage CPU, memory consumption, block IO to be provided inside Systemd's service unit files.
- These parameters communicate with [cgroup controllers](../CGroup_Controllers), that have to be enabled in the kernel. 

### Managing CPU
- **1. CPUShares:** Linked to [cpu cgroup controller](../CGroup_Controllers).
  - Every service receives the same amount of CPU time, regardless of how many processes it contains this is changed using `CPUShares=value`.
```c
[Service]
CPUShare=value

value(default)=1024   //By increasing value, we can assign more CPU time this unit.
```
- **2. CPUQuota:** Assign the specified CPU time quota to the processes executed. Values higher than 100% indicate that more than one CPU is used.
```c
[Service]
CPUQuota=20%
```

### Managing Memory
- **1. MemoryLimit:** limit on maximum memory usage of the processes executed in the cgroup.
```c
[Service]
MemoryLimit=1G
```

### Managing Block IO
- **1. BlockIOWeight:**
```c
BlockIOWeight=value

//Default=1000.     //Choose between 10 to 1000
```

### Managing other system resources
- **1. DeviceAllow:** Controls access to specific device nodes. 
```c
[Service]
DeviceAloow=/dev/test,r/w/m
```
