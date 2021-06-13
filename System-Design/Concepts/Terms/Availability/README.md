## AVAILABILITY
- Every request receives a response, without guarantee that it contains the most recent version of information. 

### Availability patterns
- **a. Fail-over**
  - _a1. Active-Passive/Master-Slave:_ Only active DB handles clients. If active DB goes down passive will take IP address of active and resume. Both talk to each other with heartbeat messages.
  - _a2. Active-Active/Master-Master:_ Both databases handles traffic. 
- **b. Using [Replication](..)**
