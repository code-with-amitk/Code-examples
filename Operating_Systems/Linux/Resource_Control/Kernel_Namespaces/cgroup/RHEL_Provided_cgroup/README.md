## RHEL Provided cgroup
- RHEL provides cgroups using systemd, ie [Units of systemd](/Operating_Systems/Linux/Daemons_Processes_Services/Systemd_PID1) are placed inside cgroups.
- RHEL provides some tools/commands(called [cgroup Controllers](CGroup_Controllers)) which can be used to create cgroups.

### Types of cgroups?
  - **1. Transient/Temporary:** 
    - Changes made will be lost after reboot.
    - [Creating transient cgroup using systemd-run command](/Operating_Systems/Linux/Administration/Commands/systemd-run). 
  - **2. Persistant/Permanent:**
    - Changes are permanent and not lost after reboot.
    - [Creating persistant cgroup using unit files](Persistant_cgroups)
