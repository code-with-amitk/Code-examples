**Consensus**
- 


### Consensus
Several nodes to agree on something. Situations where consensus is needed:
- _1. Leader Election:_ In a database with single-leader replication, all nodes need to agree on which node is the leader
- _2. Atomic commit:_ 
  - In system where transaction writing/commits spans over several nodes/partitions, problem is that a transaction may fail on some nodes but succeed on others.
  - To maintain transaction atomicity all nodes need to agree on the outcome of transaction: either they all abort/roll back (if anything goes wrong) or they all commit (if nothing goes wrong). This instance of consensus is known as the atomic commit problem.
