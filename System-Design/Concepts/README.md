- **Cloud**
  - [Types of cloud](#t)
- [Distributed System](#d)
  - [Architecture of DS](#a) 
  - [Types of DS](#ty)
    - [1. High Performance Distributed Computing](#hpdc)
    - [2. Cluster Computing](#clc)
    - [3. Grid Computing](#gc)
    - **[4. Cloud Computing](#cc)**
      - [Advantages of cloud computing wrt onprem](#adv)
      - [Types of Cloud Computing](#tc)
      - [Deployment Models of Cloud Computing](#dm)
    - [5. Edge Computing](#ec)
    - [6. HPC(High Performance Computing)](#hpc)

## Cloud
Running programs on someone else's cluster of computers, ie not running program locally.
<a name=t></a>
### Types of Cloud
- **1. Private:** used by specific orgnizations.
- **2. Public:** Used by general public.
- **3. Community:** Used by specific community
- **4. Hybrid:** Composed of 2 or more different clouds.

<a name=d></a>
# Distributed System
- Collection of computing elements that appears to its users as a 1 system giving 1 system view ie end users does not notice that he is dealing with processes, data and control are dispersed across the nodes.
- All transactions in distributed systems Follow ACID(Atomic, Consistency, Isolated, Durable)
## Components of DS
- *1. Middleware* It hides he differences in H/W and OS from each application.  
- *2. Broker* All application commnicate with each other using broker. 

<img src=distributed-system-middleware-layer.PNG width=500/>

<a name=a></a>
## Architecture of Distributed Systems
- *1. Layered:* Components are organized in a layered fashion making upcall/downcall. Eg: TCP-IP Stack
- _2. Object Based/SOA:_ Each object/Node is connected using Procedure call mechanism. Client machine have proxy/stub application running which communicates with Server running on other machine.
- _3. Resource Centered/REST:_ Node/Resource is identified by single naming scheme. All services provide same interface. Stateless, no state maintained.
- _4. Event Based/Publisher Subscriber:_ Process1 publishes a notification describing the occurrence of an event. Process2 subscribed to kind of notification gets the message.

<img src=architecture-types-of-distributed-systems.png width=500/>

<a name=ty></a>
## Types of Distributed Systems
<a name=hpdc></a>
### 1. High Performance Distributed Computing
<a name=clc></a>
### 2. Cluster Computing 
Simple computers connected on high-speed network, does parallel processing of task. Eg: Hadoop.
<a name=gc></a>
### 3. Grid Computing 
Nodes can be anything. Databases, High end machines(super computers), normal processor, sensors, telescopes etc.
<a name=cc></a>
### 4. Cloud Computing
Customer upload tasks to a data center and charged on a per-resource basis.
<a name=adv></a>
#### Advantages of cloud computing wrt onprem
- _1. Pay on demand/usage:_ No upfront payment
- _2. Cheap:_ You are sharing with lots of customers on cloud
- _3. Stop Guessing:_ No need to guess the infra capacity, just pay whatever used
- _4. Increase speed:_ Get resources by few clicks, instead of waiting for weeks.
- _5. No money spent on running/maintaining datacenters:_ no need to hire admins to maintain datancenters.
- _6. Go global in minutes:_ You can be near to your customer whereever he's in world.

<a name=tc></a>
#### Types of cloud computing
||SaaS(Software as Service) for CUSTOMERS|PaaS(Platform as Service) for DEVELOPERS|IaaS(Infrastructure as Service) for ADMINS|
|---|---|---|---|
|What|Host S/W on cloud VM. SaaS is accessed using a thin client or by browser|Provide Dashboard. upload button is provided you can upload your website. Write your code, Cloud provider will take care of it|Provide VM. Cloud provider will give access to OS of server/VM, user can install/remove/do anything on Server. Highest control|
|Examples|Gmail, Salesforce, Office 365|GAE(Google App engine), Heroku, AWS(Elastic Bean stawk)|AWS, GCP, Azure|

```c
                                     |                    What                                                   |  Example
  -----------------------------------|---------------------------------------------------------------------------|-----------
  D. CaaS(Container as a Service)    | Creating kubernets clusters.                                              | GKE(Google Kubernets Engine)
  
  E. FaaS(Function as a Service)     | Writing application for IoT, mobilr backends.
     or Cloud Functions
     
  F. Managed Services
  
  G. Cluster as a Service            | Virtualize cluster for applications.
```

<a name=dm></a>
#### Deployment Models of Cloud Computing
- **1. Cloud:** Eg: Dropbox
- **2. On-Prem** Eg: Hospitals, Govt Offices, Insurance companies
- **3. Hybrid:** Combination of cloud & on-prem


<a name=ec></a>
### 5. Edge Computing 
Computing done near to the data source. How does this help? If computation is done near data source it will be faster and has low latency.
<a name=hpc></a>
### 6. HPC(High Performance Computing)
Process data and perform complex calculations at high speeds. HPC systems can perform quadrillions of calculations/sec. Eg: supercomputer. HPC has 3 main components: Compute, Network, Storage
