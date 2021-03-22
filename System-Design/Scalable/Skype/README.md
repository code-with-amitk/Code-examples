# Skype

## 5. HLD
- Nodes would be distributed across internet.
- **[Broker](/System-Design/Concepts/Distributed_Systems/Architecture)** will part of middleware, all applications will communicate using broker.
- Nodes would be classified as **[Strong,Weak](/System-Design/Concepts/Hashing)**
- In addition, skype network will also have Skype Super nodes.
```c
  Skype-node-1(weak)        Skype-node-3(weak)        Skype-node-n(strong)USER-a
           |                    |                               |
           |--------------------|-------------------------------|
                                                                |
                                                                |
          USER-b-Skype-node-m(Strong)  ----------------- Skype-Super-Node
                                                                |
                              Skype-node-2(weak)----------------|

```

### Skype Super Nodes
  - These are centralized login servers. Every node weak or strong will communicate with super node.
  - address default super peers is hard-coded in the Skype software.
  - **Host Cache** 
    - Each weak peer has a local list of addresses of reachable super peers in its cache. it can have upto 100 addresses.
    -  To search for a specific user, a weak peer contacts its super peer, which will return a number of other peers to ask.
  - Weak peer has to establish a TCP connection with a super peer.
  - Nodes behind firewall will connect to super peers.
  
