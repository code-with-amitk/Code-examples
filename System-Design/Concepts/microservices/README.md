## MICROSERVICES
- **What** 
  - Bigger project is broken into independent modules/processes(called microservice) running on independent VM or Docker container.
- **Size** 
  - Size of microservices can vary from 100 LOC to keeping complete team busy.
- **CD** 
  - Each microservice has its own continuous delivery pipeline, this provides continous delivery.
  - CI/CD pipeline contains smaller number of tests as microservices code is small.
- **Stateless** 
  - Should be, because if new MS boots in to serve existing request, it should not care about states.
- **Categorization of MS** Microservices can be developed into 2 domains
  1. Domain-level: Writing 1 MS for a particular domain.
  2. Technical-Level: Number of microservices based on technicalities of project.
- **Advantages** 
  1. Independent deployble modules. All teams can work independently of each other. Teams can make their own technology decisions.
  2. Microservice can be brought into production at its own.
  3. developers can employ a completely new technology stack.
  4. Complete microservice can be re-engineered or replaced easily, without affecting other microservices.
- **Disadvantages**
  1. Increased Operation effort: MS system have many more units wrt deployment monolith hence requires larger operations efforts
  2. High communication time: MS communicate over network, hence will take more time wrt file based communication.
  3. Testing all microservices together is not good idea: If 1 MS fails, it blocks tests of all other microservices.
  
  ## Microservices vs Deployment Monolith
  
  | | Microservices | Deployment Monolith |
  | --- | --- | --- |
  | What | definition above | Opposite to microservices, in DM all modules are tightly coupled. |
  | CI/CD pipeline | Small(as smaller code to be tested) | Huge |
  | time taken by CI/CD | small | Huge |
  | Machine required to build CI/CD | small | high end machine |
  | Deployment | poses a smaller risk(since less functionality is changed) | Complete system is deployed as new |
  | Automate deployment | MS can only function if deployment is automated(since deployments are large) | |
  | Robust | More than DM. Memory leak in MS will crash MS only | Crash whole system & hard to debug |
  | Communication medium | via network | files etc |
  | Scaling | Particular MS might be scaled. All times Whole system scaling is not required | whole system is scaled |
  | Stateless | yes | no |
  | Security | More, since all MS are isolated from each other | |
  | Performance | Accurate & Easy to measure | |
  | Fast delivery to market | Yes | no |
  
  
