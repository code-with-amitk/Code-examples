## Host Networking
- **What?** [Container's](../../../Containers) network stack is same as host network stack. IP Address of container is same as host OS.
- **Use case?** Situtation where container needs to listen/read/write on large number of ports.
- **Disadvantages?**
  - *1.* Host networking driver only work on linux not on Windows and MAC. 
