## Serial Bus
- Data goes serially over the line.
- Clock signal is sent over clock_line(sd_c) by sender, all recievers start reading data over data line(sd_a). clock signal is again sent all recievers stop reading data.
- if some noise is there data will be corrupted.
```c
Example sending data(00001111) over the bus
Sent as digital signal
               ----------
              | 1 1 1 1 |
              |         |
  ---------------------------
    | 0 0 0 0 |
    |         |
    -----------

  ------|-------------|-------------|----- Data_line    (sd_a)
  -----||------------||------------||------- Clock_line (sd_c)
    sender/master  reciever1      reciever2
```
- **Problem-1: Slow Slave:** some slave is slow and cannot consume data at rate produced by master.
  - **Solution: Clock Streaching** Slave will pull the clock signal(sd_c) down when master tries to reset clock signal. Pulling down means setting. This way master will know slave is slow and master will slow down data sending over data line.
