## Advantages
  - *1.* Independent deployble modules. All teams can work independently of each other. Teams can make their own technology decisions.
  - *2.* Microservice can be brought into production at its own.
  - *3.* developers can employ a completely new technology stack.
  - *4.* Complete microservice can be re-engineered or replaced easily, without affecting other microservices.

## Disadvantages
  - *1.* Increased Operation effort: MS system have many more units wrt deployment monolith hence requires larger operations efforts
  - *2.* High communication time: MS communicate over network, hence will take more time wrt file based communication.
  - *3.* Testing all microservices together is not good idea: If 1 MS fails, it blocks tests of all other microservices.
