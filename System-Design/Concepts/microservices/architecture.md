## Architecture
  - Components of microservices architecture:
    - **Micro architecture** comprises all decisions that can be made individually for each microservice.
    - **Macro architecture** consists of all decisions that can be made at a global level and apply to all microservices.
![ImgUrl](https://i.ibb.co/9vYXjLz/macro-micro.png)

## A. Design Types
### A1. Domain Driven Design(DDD)
  - **What** Each Micro-service serves a different domain.
  - **Bounded Context** Each domain model is valid only in a bounded context.
  - **Domain Events** For the communication between bounded contexts, we can use domain events.
