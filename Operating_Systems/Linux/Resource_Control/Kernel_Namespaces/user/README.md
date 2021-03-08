## User ID / user
- **What?**
  - It's possible to create user namespaces even without being actually privileged
  - user and group IDs of a process can be different inside and outside of the namespace
- **Usecase?** process can have a normal unprivileged user ID outside a user namespace while being fully privileged inside.

### Example
```c
  > id -u
1000
> unshare -U
> whoami
nobody
```
- *2.* `proc/$PID/{u,g}id_map` expose the mappings for user and group IDs for the PID. 
  - user ID 0 the namespace maps to a range starting at ID 1000. This applies only to the user with the ID 1000, since the defined length is 1.
```c
> cat /proc/$PID/uid_map
0 1000 1
  ```
