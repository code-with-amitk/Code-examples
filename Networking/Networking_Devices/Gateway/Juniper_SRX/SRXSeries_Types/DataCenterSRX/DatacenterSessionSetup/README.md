## Data Center SRX Session Setup
- There are 2 NIC's containing seperate [NPU's](../NPU). NIC-1 for Ingress and NIC-2 for exgress traffic. 
- [CP](/SPC/SPU), [SPU](/SPC), [Wing Table](../NPU)
```console
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

## Flow
### 1. [TCP Session](/Networking/OSI-Layers/Layer-4/Protocols/TCP) Setup
```console
        [INGRESS-NPU]
--TCP SYN-->
      No wings present
      Send pkt to CP  --TCP SYN--> [CP]
                           Check Master session table
                           if pkt matches existing flow?
                           New session
                                    -----TCP SYN----------> [SPU]
                                                        Sets embryonic session lasting for 20 sec.
                                    <--embryonic Session Detail-
                                    
<--SYN+ACK--[Exgress-NPU]

--ACK----->forward
              ----ACK-------------->
                            Forward to correct SPU
                                    ----------ACK------------>
                                                      Session Complete
                                    <--Mark session complete--
                                                      Start session timer
           <--------Session completed------------------------
    Now when NPU gets
 a pkt, it creates entry
 in wing table 
```
### 2. [TCP Data transfer](/Networking/OSI-Layers/Layer-4/Protocols/TCP) begin
```console
        [INGRESS-NPU]
--Data Pkt-->
   Check wing table, forwards
   to appropriate SPU
             ----------Data Pkt------> [SPU]
                                Matches pkt in session table
                                Is it correct pkt in flow?
                                   Yes
                [Exgress-NPU]<-ACK--
               Matched with wing table
<--ACK-----------               
```
### 3. [TCP Tear Down](/Networking/OSI-Layers/Layer-4/Protocols/TCP) begin
```console

```
