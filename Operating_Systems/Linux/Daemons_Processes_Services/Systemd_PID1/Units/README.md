## Unit?
- **What?** This is systemd specific Object that perform/control particular task. systemd unit have Name,Type,unit-file(ini/configuration file).
- **Example:** consider systemd as a bus driver and the units such as gear, clutch, lever, brake, accelerator, etc. Bus driver uses controllers to drive/control bus, systemd uses units to control the system processes and services.
- [Commands to List all units, 1 type of units](/Operating_Systems/Linux/Administration/Commands/systemctl)

### Types of Units
|Type|Extension|Description|
|---|---|---|
|[Target](Target_Unit)|`*.target`|To define the various system states, the SysV uses numbers, known as run-levels, while the Systemd uses target-units|
|[Service](Services)|`*.service`|To start/stop/restart/reload a service daemon Eg Apache webserver.|
|[Socket](Sockets)|`*.service`|For IPC majorly|
|Device|`*.device`|For device-based activation such as a device driver.|
|Mount|`*mount`|Controls the file-system mount point.|
|Automount|`*.automount`|Controls on-demand mounting of file systems.|
|Swap|`.*swap`|Activates/deactivates swap partition.|
|Path|`*.path`|Monitors files/directories and activates/deactivates a service if the specified file or directory is accessed.|
|Timer|`*.timer`|Activates/deactivates specified service based on a timer or when the set time is elapsed.|
|Snapshot|`*.snapshot`|Saves the current state of all running units. This state can be used to restore the system later.|
|Slice|`*.slice`|Group of units that manages system resources such as CPU, and memory.|
|Scope|`*.scope`|Unit that organizes and manages foreign processes.|
|busname|`*.busname`|Controls DBus system.|
