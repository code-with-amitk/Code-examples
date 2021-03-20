## 80386
- 132 pins
  - **Address Bus=32 bit** A2-A31. Can access 4G of memory. 2<sup>32</sup> = 4G
  - **Memory/Data Bus=32 bit** D0-D31
  - A12 = M/IO Differentiates between memory and IO cycles. 1=Select memory device,0=select IO device.
  - B10 = W/R Differentiates Read write cycles. 1=Write cycle, 0=read cycle.
  - A11 = D/C Data/Control Pin. Differentiates data cycle from machine cycle.
  - C10 = Lock. Locking CPU at time of use
  - INTR: Interrupt request by external circuitary. This is maskable.
  - RESET: 1 at this pin suspends current operation and restart execution from starting point.
  - NMI(Non maskable interrupt)

<img src=80386.png width=700 />
