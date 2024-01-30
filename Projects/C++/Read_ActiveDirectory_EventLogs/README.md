:toc:
:toclevels: 5

== Objective
* Read event logs from channel="Security" any 1 of following paths:
```c
"Event/System"
"Event/System[EventId=4624 or EventId=4634]"    //4624=logon, 4634=logout
```
