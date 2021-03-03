## Units
- These are Processes/Resources/Services running in background that are managed by systemd. These are defined in unit files.

### Types of Units
- **a. [Service unit](Services)** Service units have a `*.service` extension and represent system services.

- **b. [Socket Unit](Sockets):** Socket units have a `*.socket` extension and represent inter-process communication (IPC) sockets that systemd should monitor. 

- **c. `*.path`:** Delay the activation of a service until a specific file system change occurs.
 
- **d. [Target Unit](Target_Unit):** Units with `*.target` extension.
