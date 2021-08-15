- [Cloud](#cloud)
  - [Types of cloud](#tyc)
- [Distributed System](#dis)
  - [Architecture of DS](#archds) 
  - [Types of DS](#tyd)

<a name=cloud></a>
## Cloud
Running programs on someone else's cluster of computers.
### Types of cloud
**1. Private**: used by specific orgnizations.
**2. Public:** Used by general public.
**3. Community:** Used by specific community
**4. Hybrid:** Composed of 2 or more different clouds.

<a name=dis></a>
## Distributed System
Collection of computing elements that appears to its users as a 1 system giving 1 system view ie end users does not notice that he is dealing with processes, data and control are dispersed across the nodes.
- All transactions in distributed systems Follow ACID(Atomic, Consistency, Isolated, Durable)
- **Components of DS**
  - *1. Middleware* It hides he differences in H/W and OS from each application.  
  - *2. Broker* All application commnicate with each other using broker. 

<img src=distributed-system-middleware-layer.PNG width=500/>

<a name=archds></a>
#### Architecture of Distributed Systems
- *1. Layered:* Components are organized in a layered fashion making upcall/downcall. Eg: TCP-IP Stack
- _2. Object Based/SOA:_ Each object/Node is connected using Procedure call mechanism. Client machine have proxy/stub application running which communicates with Server running on other machine.
- _3. Resource Centered/REST:_ Node/Resource is identified by single naming scheme. All services provide same interface. Stateless, no state maintained.
- _4. Event Based/Publisher Subscriber:_ Process1 publishes a notification describing the occurrence of an event. Process2 subscribed to kind of notification gets the message.

<img src=architecture-types-of-distributed-systems.png width=500/>

<a name=tyd></a>
#### Types of Distributed Systems
1. High Performance Distributed Computing
2. Cluster Computing: Simple computers connected on high-speed network, does parallel processing of task. Eg: Hadoop.
3. Grid Computing: Nodes can be anything. Databases, High end machines(super computers), normal processor, sensors, telescopes etc.
4. Cloud Computing: Customer upload tasks to a data center and charged on a per-resource basis. 3 types of services to customers.
```c
                                     | What
  -----------------------------------|--------
  A. IaaS(Infrastructure as Service) | Provide VM. Cloud provider will give access to OS of server/VM, user can install/remove/do anything on Server. Highest order of control.
  B. PaaS(Platform as Service)       | Provide Dashboard. upload button is provided you can upload your website.
  C. SaaS(Software as Service)       | Host S/W on cloud VM. SaaS is accessed using a thin client via a web browser.
     or On-Demand Service
  D. CaaS(Container as a Service)    |
  E. FaaS(Function as a Service)     |
  F. Managed Services
```  
