## Resource Control / Resource Management
- **What?** Resource(CPU, Network, Memory(RAM, Hard disk) given in controlled manner to processes.

### Methods of Resource Control
3. CGROUPS(CONTROL GROUPS)
WHAT? Group of 1 or more processes whose CPU, memory, disk I/O and network's usage can monitored and controlled. Eg: cgroup1 has 4 processes(p1,p2,p3,p4), cgroup2 has 2 processes(p5,p6). We can limit cgroup1 to use Max 20% of RAM and cgroup2 to use max 60%. if p1 uses 21% of RAM, it will be killed by OOM(Out of Memory) killer.
WHY? To restrict cpu,memory,I/O,network usage of a process or group of processes.
