## Architecture
  - Components of microservices architecture:
    - **Micro architecture** comprises all decisions that can be made individually for each microservice.
    - **Macro architecture** consists of all decisions that can be made at a global level and apply to all microservices.
![ImgUrl](https://i.ibb.co/9vYXjLz/macro-micro.png)

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
