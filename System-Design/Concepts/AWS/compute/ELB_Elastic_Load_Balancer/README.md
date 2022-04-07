**ELB(Elastic Load Balancer)**
- [Scaling](#s)

## ELB
- Node/Machine which automatically distributes incoming application traffic across multiple resources, such as Amazon EC2 instances.
- _Analogy:_ You can think of ELB as a person standing on Gate of BurgerKing who sends who sends customer to free counters.
<a name=s></a>
### Scaling
- **Adding of new App-Server:** Whenever a new App-server is spawned(on increase of load) on EC2 instance, It will notify ELB to send traffic to it.
- **Load Increases:** Whenever load increases on ELB, ELB autoscales itself.
```c
//All App-servers are same, ie same instance of application is running.

  ----\    /----- (App-server on EC2)
  ---- ELB ------ (App-server on EC2)
  ----/    \----- (App-server on EC2)
        /\
        |------  New-App-Server //Will advertise to ELB
```
