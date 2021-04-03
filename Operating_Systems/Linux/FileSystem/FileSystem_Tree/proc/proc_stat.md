## /proc/stat
- Contains information about total interrupts recieved on System and no of interrupts on each line
  - 99990109: Total interrupts received on system
  - 5154006: Interrupts recieved on line 0
  - 4096: Interrupts recieved on line 4
```c
# cat /proc/stat
intr 99990109 5154006 2 0 2 4907 0 2 68 4 0 4406 9291 50 0 0
```
