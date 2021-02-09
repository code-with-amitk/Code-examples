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
