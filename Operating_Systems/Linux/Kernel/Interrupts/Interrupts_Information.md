## /proc/interrupts
- Only interrupts corresponding to installed handlers are shown.
  - if no [handler/ISR] for interrupt is defined, CPU cannot handle the interrupt, also that is not listed in /proc/interrupts.
- Col-2: how many interrupts have been delivered to each CPU-0
- Col-4: Interrupt controller/handler that handles the interrupt 
```c
# cat /proc/interrupts
interrupt_number	CPU0 	  CPU1
 0:             4848108    34 		IO-APIC-edge timer
 2:                 0      0 		XT-PIC cascade
 8:                 3      1 		IO-APIC-edge rtc
 10:              4335     1 		IO-APIC-level aic7xxx
 11:              8903     0 		IO-APIC-level uhci_hcd
 12:                49     1 		IO-APIC-edge i8042
NMI:                 0     0
LOC:            4848187   4848186
ERR:                0
MIS:                0
```

## /proc/stat
- Contains information about total interrupts recieved on System and no of interrupts on each line
  - 99990109: Total interrupts received on system
  - 5154006: Interrupts recieved on line 0
  - 4096: Interrupts recieved on line 4
```c
# cat /proc/stat
intr 99990109 5154006 2 0 2 4907 0 2 68 4 0 4406 9291 50 0 0
```
