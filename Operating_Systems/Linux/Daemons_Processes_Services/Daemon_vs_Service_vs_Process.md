## DAEMON?
- Process running in background to perform system tasks. 

## SERVICE? 
- 1 or more daemon/processes combined together for servicing the user. Eg: File server, Apache/httpd service(shows 5-6 processes in ps), sshd, systemd
```c
    # ps -aux|grep systemd
                   PID%cpu%mem    vsz        rss      tty  state    start-time    command
        root        1    0.0    0.0    193844    5808     ?    Ss    2020    1:11    /usr/lib/systemd/systemd --switched-root --system
        root    632    0.0    0.0    390601    5782     ?    Ss    2020    1:11    /usr/lib/systemd/systemd-journald                            //Event Logging with journald
        root    669    0.0    0.0    112121    1212     ?    Ss    2020    1:11    /usr/lib/systemd/systemd-udevd
        root    904    0.0    0.0    129492    8589     ?    Ss    2020    1:11    /usr/lib/systemd/systemd-logind
```        

## PROCESS? 
- 1 or more threads of execution together. Converting process to service(See systemd section below)?
