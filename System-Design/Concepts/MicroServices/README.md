**Microservices**
- [What](#what)
- [Advantages/Disadvantages](#adv)
- [Microservices vs Deployment Monolith](#vs)
- [Migrating from Depolyment Monolith to microserves](#mig)
  - [Migration Patterns](#pat)
- [Architecture](#ar)
- **Design Types**
  - Domain Driven Design(DDD)
    - [1. CUSTOMER/SUPPLIER PATTERN](#cust)
    - [2. CONFORMIST PATTERN](#con)
    - [3. ANTI-CORRUPTION LAYER/ACL PATTERN](#an)
    - [4. SEPERATE WAYS PATTERN](#sep)
    - [5. SHARED KERNEL PATTERN](#sh)
    - [6. OPEN HOST SERVICE PATTERN](#open)


### What?
- Bigger project is broken into independent modules/processes(called microservice) running on independent VM or Docker container. Size of microservices can vary from 100 LOC to 10k.
- Microservices are stateless because new MS boots in to serve existing request, it should not care about states.

<a name=adv></a>
### Advantages/Disadvantages
#### Advantages
  - *1. Independent deployble modules:* All teams can work independently of each other. Teams can make their own technology decisions.
  - *2.* Microservice can be brought into production at its own.
  - *3. Adopting New Technology:* Developers can employ a completely new technology stack (without affecting the others).
  - *4. Easy replacement:* Complete microservice can be re-engineered or replaced easily, without affecting other microservices.
  - *5. Resilience:*  If 1 microservice of a system fails, failure will not cascade to rest of the system. Rest of system can carry on working.
  - *6. Scaling:* In monolithic system we have to scale everything together not with microservices.

#### Disadvantages
  - *1.* Increased Operation effort: MS system have many more units wrt deployment monolith hence requires larger operations efforts
  - *2.* High communication time: MS communicate over network, hence will take more time wrt file based communication.
  - *3.* Testing all microservices together is not good idea: If 1 MS fails, it blocks tests of all other microservices.

<a name=vs></a>
### Microservices vs Deployment Monolith
  
  | | Microservices | Deployment Monolith |
  | --- | --- | --- |
  | What | definition above | Opposite to microservices, in DM all modules are tightly coupled. |
  | CI/CD pipeline | Small(as smaller code to be tested) | Huge |
  | time taken by CI/CD | small | Huge |
  | Machine required to build CI/CD | small | high end machine |
  | Deployment | poses a smaller risk(since less functionality is changed) | Complete system is deployed as new |
  | Automate deployment | MS can only function if deployment is automated(since deployments are large) | |
  | Robust | More than DM. Memory leak in MS will crash MS only | Crash whole system & hard to debug |
  | Communication medium | network/async | sync/files(sync communication leads issues when hosts are unavailable) |
  | Scaling | Particular MS might be scaled. All times Whole system scaling is not required | whole system is scaled |
  | Stateless | yes | no |
  | Security | More, since all MS are isolated from each other | |
  | Performance | Accurate & Easy to measure | |
  | Fast delivery to market | Yes | no |
  | Database | Each should have its own DB or atleast its own DB schema. CI/CD is not possible in common DB| |
  | Complexity | Small code, easy to understand | Huge code, tough to correlate |
  
<a name=mig></a>  
### Migrating from Depolyment Monolith to microserves
#### Reasons for Migrations
  - **Outdated technology** Microservices would be developed a fresh using new technology without using old monolith code.
  - All other reasons incresed security, robustness, speed of development etc.
  - Increase development speed.
 
<a name=pat></a> 
#### Migration Patterns
_1._ Strangler pattern
     - When a change would have to be made to the legacy system, a new microservice must be created first. The change is then implemented in this microservice instead.
     - microservices increasingly strangle the legacy system until nothing is left of the legacy system.
     - The full migration to microservices can take a very long time.
_2._ Migration based on layers
     - Migration happens based on layers. Example:
       - UI can be migrated first.
     - the remaining layers would have to be migrated into the same microservice afterward
_3._ Copy/Change Approach
     - microservices system is developed as exact replica of DM, while old code is still not removed.
  
<a name=ar></a>
### Architecture
Components of microservices architecture:
- **Micro architecture** comprises all decisions that can be made individually for each microservice.
- **Macro architecture** consists of all decisions that can be made at a global level and apply to all microservices.

<img src=macro-micro.png width=500/>

Table shows the typical micro and macro architecture decisions:

| Micro or Macro | Micro | Macro |
| --- | --- | --- |
| Programming Language | Continuous Delivery Pipeline	| Communication Protocol |
| Database | Authorization |	Authentication |
| Look and Feel |	Tests of the Microservice in Isolation	| Integration tests |
| Documentation | |

  
## Design Types
### Domain Driven Design(DDD)
Each Micro-service serves a different domain.
- *Bounded Context* Each domain model is valid only in a bounded context.
- *Domain Events* For the communication between bounded contexts, we can use domain events.
- *Upstream* Upstream team can influence the success of the downstream team, downstream means team lying more near to customer. Example: In amazon order processing. payment team is downstream, order processing is upstream.
- *Downstream:* downstream team cannot influence the success of the upstream team

DDD describes in several patterns how exactly communication takes place.

<a name=cust></a>
#### 1. CUSTOMER/SUPPLIER PATTERN
There is 1 supplier(upstream) and 1 customer/consumer(downstream). Example: if upstream/supplier(order-process) does not provide correct data downstream/customer(Payment). Transaction cannot be processed. So consumer can provide his requirements to supplier.

<a name=con></a>
#### 2. CONFORMIST PATTERN
A `bounded context` simply uses a `domain model` from `another bounded context`. Example: Processing online order
- `Dataware house team` takes information from `order process team`.
-  `Dataware house team` cannot demand more information from other bounded context. It has to work with information from other bounded contexts

<a name=an></a>
#### 3. ANTI-CORRUPTION LAYER/ACL PATTERN
`Bounded context` does not directly use the domain model/information of the other bounded context. It contains a `layer for decoupling` its own domain model from the model of the bounded context

<a name=sep></a>
#### 4. SEPERATE WAYS PATTERN
The bounded contexts are `not related` at the software level. Example: Ecommerce website
- There is a micro service for payment. Let's suppose a new MS/bounded context is added (ie Purchasing). Purchasing would be separate from the remaining system

<a name=sh></a>
#### 5. SHARED KERNEL PATTERN    
Describes a common core that is shared by multiple bounded contexts. `It is an anti-pattern` for microservices systems. But because DDD can also be applied to deployment monoliths, there are still scenarios in which a shared kernel is used.

<a name=open></a>
#### 6. OPEN HOST SERVICE PATTERN
The `bounded context-1` offers a generic interface with several services. Other bounded contexts can implement their own integration with `bounded context-1`, its their choice.
  - `Published language` is a domain model accessible by all bounded contexts.
  - *Example* This pattern is frequently found at public APIs on the Internet. 

#### How to select a pattern?
Pattern should be choosen based on 
    1. Domain  
    2. communication relationships between the teams  
    3. Structures.
