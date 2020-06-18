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
  Supplier  --->    Consumer
  (Upstream)      (Downstream)
  
  
