- **Why Flow, Congestion Control?**
  - Network devices operate at different data rates because of various factors like CPU and available bandwidth.
  - It may happen a sending device to send data at a much faster rate than the receiver can handle. 

|| FLOW CONTROL(receiver side) | CONGESTION CONTROL(sending side) |
|---|---|---|
|Why|Prevents a slow receiver from being overwhelmed by a fast sender| Prevents network/wire from being overwhelmed |
|How|Asking sender to send data slowly|Asking transport layer to place data slowly on n/w|
|Layers handling| Data link layer, Transport layer|network and transport layer|
|Methods| Stop-n-wait, Sliding Windows |Provisioning, Traffic-aware routing, and Admission control, Nagle Algorithm|
