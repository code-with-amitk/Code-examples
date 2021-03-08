## [Kernel Namespaces](https://medium.com/@saschagrunert/demystifying-containers-part-i-kernel-space-2c53d6979504)
- **What?** Group of processes given isolated instance of resource.
- **9 Namespaces?** mnt, pid, net, ipc, uts, user and cgroup, time, syslog
```c
> ls -Gg /proc/self/ns/
total 0
lrwxrwxrwx 1 0 Feb  6 18:32 cgroup -> 'cgroup:[4026531835]'
lrwxrwxrwx 1 0 Feb  6 18:32 ipc -> 'ipc:[4026531839]'
lrwxrwxrwx 1 0 Feb  6 18:32 mnt -> 'mnt:[4026531840]'
lrwxrwxrwx 1 0 Feb  6 18:32 net -> 'net:[4026532008]'
lrwxrwxrwx 1 0 Feb  6 18:32 pid -> 'pid:[4026531836]'
lrwxrwxrwx 1 0 Feb  6 18:32 pid_for_children -> 'pid:[4026531836]'
lrwxrwxrwx 1 0 Feb  6 18:32 user -> 'user:[4026531837]'
lrwxrwxrwx 1 0 Feb  6 18:32 uts -> 'uts:[4026531838]'
```
- **APIs used in implementing namespace?** 
  - [clone()](/Threads_Processes_IPC/Processes)
  - unshare(): Process can disassociate parts of the execution context which are currently being shared with others.
  - setns(): Reassociates the calling thread with the provided namespace file descriptor. This function can be used to join an existing namespace.
