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
  | Communication medium | network/async | sync/files(sync communication leads issues when hosts are unavailable) |
  | Scaling | Particular MS might be scaled. All times Whole system scaling is not required | whole system is scaled |
  | Stateless | yes | no |
  | Security | More, since all MS are isolated from each other | |
  | Performance | Accurate & Easy to measure | |
  | Fast delivery to market | Yes | no |
  | Database | Each should have its own DB or atleast its own DB schema. CI/CD is not possible in common DB| |
  | Complexity | Small code, easy to understand | Huge code, tough to correlate |
