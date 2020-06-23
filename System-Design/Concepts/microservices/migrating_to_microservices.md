## Migrating from Depolyment Monolith to microserves

### Reasons for Migrations
  - **Outdated technology** Microservices would be developed a fresh using new technology without using old monolith code.
  - All other reasons incresed security, robustness, speed of development etc.
  - Increase development speed.
  
### Migration Patterns  
  1. Strangler pattern
     - When a change would have to be made to the legacy system, a new microservice must be created first. The change is then implemented in this microservice instead.
     - microservices increasingly strangle the legacy system until nothing is left of the legacy system.
     - The full migration to microservices can take a very long time.
  2. Migration based on layers
     - Migration happens based on layers. Example:
       - UI can be migrated first.
     - the remaining layers would have to be migrated into the same microservice afterward
  3. Copy/Change Approach
     - microservices system is developed as exact replica of DM, while old code is still not removed.
