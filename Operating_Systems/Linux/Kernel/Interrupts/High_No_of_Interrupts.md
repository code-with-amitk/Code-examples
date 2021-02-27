## High Number of Interrupts
- Interrupts are a normal way for H/W(device) and CPU to communicate. Interrupts should not take too much of CPU(should be < 5%).
- High CPU usage by System Interrupts means there is issue in hardware driver(ISR) or hardware itself.
- Solutions? 
  - *1.* Check whether you're using recent Driver. 
  - *2.* Disable/remove each indivisual driver and check CPU status to find culprit device.
  - *3.* (if disabling driver did not helped). Check for malfunctioning hardware and try installing it new.
  - *4.* Check disabling all sound effect, check how many interrupts generated now?
  - *5.* Update BIOS, restart.
