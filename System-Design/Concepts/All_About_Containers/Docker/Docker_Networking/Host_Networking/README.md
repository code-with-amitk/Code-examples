## Host Networking
- **What?** [Container's](../../../Containers) network stack is same as host network stack. IP Address of container is same as host OS.
- **Use case?** Situtation where container needs to listen/read/write on large number of ports.
- [Advantages,Disadvantages](Advantages_Disadv_of_HostNetworking.md)

### Example
- *[1. Start ngnix Container which binds directly to port 80 on the Docker host](Examples)*
