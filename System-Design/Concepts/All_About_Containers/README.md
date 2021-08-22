- Containers


<a name=con></a>
## Containers
- Isolated(Isolation is achieved using kernel namespace, [cgroups](/Operating_Systems/Linux/Resource_Control)) processes running on single host. Isolated from other processes.
- Only 1 Application can run inside container and all its dependent libraries. Each container has its own: Network interface, its own IP address, its own file system, All containers share the kernel of the host.
