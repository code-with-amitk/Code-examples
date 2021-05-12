## Data Center SRX Session Setup
- There are 2 NIC's containing seperate [NPU's](../NPU). NIC-1 for Ingress and NIC-2 for exgress traffic.

```c
    ------------Data Ceter SRX-------
    |  Ingress                       |
    | ----------             ----    |
--> | NIC | NPU |           | CP |   |
    | ----------             ----    |
    |                                |
    |  Exgress                       |
    | ----------             -----   |
<-- | NIC | NPU |           | SPU |  |
    | -----------            -----   |
     ---------------------------------
```
