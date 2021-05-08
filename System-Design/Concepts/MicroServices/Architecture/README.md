## Architecture
  - Components of microservices architecture:
    - **Micro architecture** comprises all decisions that can be made individually for each microservice.
    - **Macro architecture** consists of all decisions that can be made at a global level and apply to all microservices.
![ImgUrl](https://i.ibb.co/9vYXjLz/macro-micro.png)

  - Table shows the typical micro and macro architecture decisions:

| Micro or Macro | Micro | Macro |
| --- | --- | --- |
| Programming Language | Continuous Delivery Pipeline	| Communication Protocol |
| Database | Authorization |	Authentication |
| Look and Feel |	Tests of the Microservice in Isolation	| Integration tests |
| Documentation | |

## Design Types
### A. Domain Driven Design(DDD)
  - **What** Each Micro-service serves a different domain.
  - **Terms**
    - ***Bounded Context*** Each domain model is valid only in a bounded context.
    - ***Domain Events*** For the communication between bounded contexts, we can use domain events.
    - ***Upstream***  
      - upstream team can influence the success of the downstream team
      - downstream means team lying more near to customer.
      - Example: In amazon order processing. payment team is downstream, order processing is upstream.
    - ***Downstream*** 
      - downstream team cannot influence the success of the upstream team
![ImgUrl](https://i.ibb.co/DQghn4G/updown.png)      
  
#### B. Microservices Patterns   
  - DDD describes in several patterns how exactly communication takes place.

##### B1. CUSTOMER/SUPPLIER PATTERN
  - There is 1 supplier(upstream) and 1 customer/consumer(downstream).
  - Example: if upstream/supplier(order-process) does not provide correct data downstream/customer(Payment). Transaction cannot be processed.
    - So consumer can provide his requirements to supplier.
![ImgUrl](https://i.ibb.co/87HYv44/suppconsumer.png)

#### B2. CONFORMIST PATTERN
  - A `bounded context` simply uses a `domain model` from `another bounded context`.
  - Example: Processing online order
    - `Dataware house team` takes information from `order process team`.
    -  `Dataware house team` cannot demand more information from other bounded context. It has to work with information from other bounded contexts
    
#### B3. ANTI-CORRUPTION LAYER/ACL PATTERN
  - `Bounded context` does not directly use the domain model/information of the other bounded context.
  - It contains a `layer for decoupling` its own domain model from the model of the bounded context
![ImgUrl](https://i.ibb.co/GcVL7Cc/acl.png)

#### B4. SEPERATE WAYS PATTERN
  - the bounded contexts are `not related` at the software level.
  - Example: Ecommerce website
    - There is a micro service for payment
    - Let's suppose a new MS/bounded context is added (ie Purchasing).
    - Purchasing would be separate from the remaining system
![ImgUrl](https://i.ibb.co/C0sJLwB/seperateways.png)    
    
#### B5. SHARED KERNEL PATTERN    
  - Describes a common core that is shared by multiple bounded contexts. 
  - `It is an anti-pattern` for microservices systems. But because DDD can also be applied to deployment monoliths, there are still scenarios in which a shared kernel is used.
![ImgUrl](https://i.ibb.co/j86VGdH/sharedkernel.png)

#### B6. OPEN HOST SERVICE PATTERN
  - The `bounded context-1` offers a generic interface with several services.
  - Other bounded contexts can implement their own integration with `bounded context-1`, its their choice.
  - `Published language` is a domain model accessible by all bounded contexts.
  - ***Example*** This pattern is frequently found at public APIs on the Internet. 
  
#### How to select a pattern?
  - Pattern should be choosen based on 
    1. Domain  
    2. communication relationships between the teams  
    3. Structures.

