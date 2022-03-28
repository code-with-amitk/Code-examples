- [Cloud](#cloud)
  - [Types of cloud](#tyc)
- [Distributed System](#dis)
  - [Architecture of DS](#archds) 
  - [Types of DS](#tyd)

<a name=cloud></a>
## Cloud
Running programs on someone else's cluster of computers.
#### Types of cloud
- _1. Private_: used by specific orgnizations.
- _2. Public:_ Used by general public.
- _3. Community:_ Used by specific community
- _4. Hybrid:_ Composed of 2 or more different clouds.

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
- **1. High Performance Distributed Computing**
- **2. Cluster Computing:** Simple computers connected on high-speed network, does parallel processing of task. Eg: Hadoop.
  - _Advantages of cloud computing wrt onprem:_ Cheap(no upfront real estate cost), stop guessing capacity, increased speed, no maintaince of data centers, You can be near to your customer whereever he's in world.

- **3. Grid Computing:** Nodes can be anything. Databases, High end machines(super computers), normal processor, sensors, telescopes etc.
- **4. Cloud Computing**: Customer upload tasks to a data center and charged on a per-resource basis. 3 types of services to customers.
- **5. Edge Computing:** Computing done near to the data source. How does this help? If computation is done near data source it will be faster and has low latency.
- **6. HPC(High Performance Computing):** Process data and perform complex calculations at high speeds. HPC systems can perform quadrillions of calculations/sec. Eg: supercomputer. HPC has 3 main components: Compute, Network, Storage
```c
                                     |                    What                                                   |  Example
  -----------------------------------|---------------------------------------------------------------------------|-----------
  A. IaaS(Infrastructure as Service) | Provide VM. Cloud provider will give access to OS of server/VM,           | GCE(google compute Engine)
                                       user can install/remove/do anything on Server. Highest control.           |
                                       
  B. PaaS(Platform as Service)       | Provide Dashboard. upload button is provided you can upload your website. | GAE(Google App engine)
                                       Write your code, Cloud provider will take care of it                      |
                                       
  C. SaaS(Software as Service)       | Host S/W on cloud VM. SaaS is accessed using a thin client or by browser  | 
     or On-Demand Service            
     
  D. CaaS(Container as a Service)    | Creating kubernets clusters.                                              | GKE(Google Kubernets Engine)
  
  E. FaaS(Function as a Service)     | Writing application for IoT, mobilr backends.
     or Cloud Functions
     
  F. Managed Services
  
  G. Cluster as a Service            | Virtualize cluster for applications.
```
GCE(GCP)
