## When fork can fail
- Fork can fail if there are:
  - *a.* No free slots left in the [process table](/Threads_Processes_IPC/Processes/Process_Table). 
  - *b.* and possibly if there is no memory or [swap space](/Operating_Systems/Linux/Daemons_Processes_Services/Systemd_PID1/Booting_up_With_systemd.md) left.
