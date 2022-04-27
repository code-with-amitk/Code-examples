**ELB(Elastic Load Balancer)**
- [Scaling](#s)
- [Create ELB](#ce)

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

<a name=ce></a>
### Creating ELB
- _[1. Create 2 EC2 instances](/System-Design/Concepts/AWS/compute/EC2#l)_ Rename as InstanceA, InstanceB
- _2. Create Load Balancer:_
```c
Aws Dashboard > EC2 > Left Side Menu > Load Balancing > Load Balancers > Create LB
  Application Load Balancer > 
    Select 2 Availablity zones (us-east-1a, us-east-1b)
    Security Groups:                  default
    Create Target Groups(This is reference to servers which this ELB points to): 
      Choose target(We can route traffic to different things):                  Instances
      Target group-name:                                                        my-target-group
        Next
      Register Targets:                                                         select InstanceA, InstanceB
      Create
```
- _3. Check DNS Name of Load Balancer:_
```c
DNS Name: my-alb-804564689.us-east-1.elb.amazonaws.com
Listeners: Port=80. Target-group(Having EC2 instances)
```
