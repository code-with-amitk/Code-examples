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
- All transactions in distributed systems Follow [ACID](/System-Design/Concepts/Terms/README.md#acid)
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
- _1._ **Trade upfront expense for variable expense:** if you are setting up an Datacenter, upfront expenses include physical servers & other resources.
  - With AWS no need to purchase Datacenter Hardware, Pay for on demand/usage. No upfront payment
- _2._ **Stop spending money to run & maintain data centers:**
  - Donot spend time on datacenter's research(if you are not datacenter company).
  - Focus on your application, make application better than your competitors. Delight your customer with new innovations.
- _3._ **Stop guessing capacity:** if we are building our own datacenter we need to guess how much would be the cost(Eg: for 10M users for 3 years) & purchased HW accordingly.
    - _Overestimation:_ And then turns out we have only 1M users.
    - _Underestimation:_ if we got 100M users, we need to scale our infra it may take 2-3 months(loss of business).
  - At AWS we don’t need to predict users, autoscale up/down. Amazon EC2 instances will spun up/down within 5 min as users increases.
- _4._ **Benefit from massive economies of scale:** Lower pay-as-you-go prices.
  - AWS is building Huge datacenters around the globe and buys hardware at cheaper costs.
  - AWS is expert in setting datacenters for max productivity & least cost.
  - While if we setup our own datacenter we might buy H/W at higher prices & setup might not be correct costing high.
- _5._ **Increase speed and agility:** Suppose a new multithreaded code developer wrote and he wants to test it High-end intel Xeon processor need to be purchased might take 2-3 months(if code is not good) whole cost is wasted.
  - With AWS, Get high end EC2 instance in few clicks check your code and delete instance.
- _6._ **Go global in minutes:** Suppose you have your datacenters in US, now got new customer base in Germany. You need to setup DC in germany or customers see high latency.
  - If you setup datacenter at your own it can take months to years but with AWS it takes minutes.

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
- **2. On-Prem/Private Cloud:** Eg: Hospitals, Govt Offices, Insurance companies
- **3. Hybrid:** Combination of cloud & on-prem


<a name=ec></a>
### 5. Edge Computing 
Computing done near to the data source. How does this help? If computation is done near data source it will be faster and has low latency.
<a name=hpc></a>
### 6. HPC(High Performance Computing)
Process data and perform complex calculations at high speeds. HPC systems can perform quadrillions of calculations/sec. Eg: supercomputer. HPC has 3 main components: Compute, Network, Storage
