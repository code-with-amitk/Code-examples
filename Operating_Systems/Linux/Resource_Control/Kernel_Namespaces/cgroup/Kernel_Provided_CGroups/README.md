## Kernel Provided Cgroups
- **What?** 
  - Working directly on cgroups provided by kernel, unlike RHEL which provides a wrapper called systemd to work on cgroups.

### Example
- **1. Create a new cgroup**
  - By default, the kernel exposes cgroups in /sys/fs/cgroup. To create a new cgroup, create a directory there. We get default values.
```c
$ sudo mkdir /sys/fs/cgroup/memory/amit
$ ls /sys/fs/cgroup/memory/amit
cgroup.clone_children
cgroup.event_control
cgroup.procs
memory.failcnt
memory.force_empty
memory.kmem.failcnt
memory.kmem.limit_in_bytes
memory.kmem.max_usage_in_bytes
memory.kmem.slabinfo
memory.kmem.tcp.failcnt
memory.kmem.tcp.limit_in_bytes
memory.kmem.tcp.max_usage_in_bytes
memory.kmem.tcp.usage_in_bytes
memory.kmem.usage_in_bytes
memory.limit_in_bytes
memory.max_usage_in_bytes
memory.move_charge_at_immigrate
memory.numa_stat
memory.oom_control
memory.pressure_level
memory.soft_limit_in_bytes
memory.stat
memory.swappiness
memory.usage_in_bytes
memory.use_hierarchy
notify_on_release
tasks
```
- **2. set the memory limits for cgroup=amit**
  -  We are also turning off swap to make our example implementation work.
```c
> sudo su
# echo 100000000 > /sys/fs/cgroup/memory/amit/memory.limit_in_bytes
# echo 0 > /sys/fs/cgroup/memory/amit/memory.swappiness
```
- **3. Assign a process to a cgroup**
  - Just write the corresponding PID to the cgroup.procs file:
```c
# echo $$ > /sys/fs/cgroup/memory/demo/cgroup.procs
```
- **4. Run sample application to consume more than the allowed 100 megabytes of memory**
```rust
//Rust Application
pub fn main() {
    let mut vec = vec![];
    loop {
        vec.extend_from_slice(&[1u8; 10_000_000]);
        println!("{}0 MB", vec.len() / 10_000_000);
    }
}
```
- **5. Run the process and see process got killed because of memory constraints**
```c
# rustc memory.rs
# ./memory
10 MB
20 MB
30 MB
40 MB
50 MB
60 MB
70 MB
80 MB
90 MB
Killed
```
