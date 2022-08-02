**Consensus**
- [Atomic Commit](#ac)
- **Atomic Commit Problem**
  - [Solution-1. 2 Phase Commit](#2pc)


# Consensus
Several nodes to agree on something. Situations where consensus is needed:
- _1. Leader Election:_ In a database with single-leader replication, all nodes need to agree on which node is the leader
- _[2. Atomic commit](#ac)_ 

<a name=ac></a>
## Atomic Commit
- **What?**
  - In system where a transaction writing/commits spans over several nodes/partitions, problem is that a transaction may fail on some nodes but succeed on others.
  - Consensus need to be maintained that either they all abort/roll back (if anything goes wrong) or they all commit (if nothing goes wrong) else data becomes inconsistent.

## Atomic Commit Problem
Some nodes commit the transaction but others abort it, the nodes become inconsistent with each other and so as data.

<a name=2pc></a>
### Solution-1 (2 Phase Commit)
- 2PC ensures that either all nodes commit or all nodes abort.
- A transaction commit must be IRREVOCABLE: ie once node decides to commit, then there is no turning back. Reason: Once data has been committed, it becomes visible to other transactions, and thus other clients may start relying on that data; this principle forms the basis of read committed isolation.
- **NOTE:** 2PC and 2PL(2 Phase lock) are different. 2PC provides atomic commit in a distributed database, whereas 2PL provides serializable isolation.

#### How 2PC is achieved (A Definite Promise)
  - _1. Coordinator/Transaction Manager:_ This is a new component comes in that does not normally appear in single-node transactions. Eg: Narayana, JOTM, BTM, or MSDTC.
```c
1. Application sends write request.
2. Coordinator sends Prepare message asking nodes whether they can commit or not?
3. When Node recieves prepare, it makes sure that it can commit to Disk at any cost.
  - if Node crashes After sending Yes. Then after recovery it has to commit the transaction.
4. Node sends response to Coordinator
  if (all respond yes)
    Phase-2: Sends Message. Nodes Commit
  else  //if any one says no
    Phase-2: Send Abort Message

                                                           <============ Distributed Database ========>
  Application(RW Data)      Coordinator(Zookeeper)         Node-1            Node-2              Node-n
            ----- connect ------> 
                            Generate transactionID=12
                                    [Globally Unique]
            <-- transactionID=12 --
            -- write(hello), id=12 --> 
                              
                            <<<<<<<<< PHASE-1 of 2PC Start >>>>>>>>>>>>>>>>>>>>>
                              -- Prepare, transactionId=12 -->
                              <--------- yes -----------------
                              
                              --------------Prepare, transactionId=12 --------->
                              <----------------- no ----------------------------
                              
                              -------------------Prepare, transactionId=12 ------------------------->
                              <------------------------------------ yes -----------------------------
                              <<<<<<<<< PHASE-1 of 2PC End >>>>>>>>>>>>>>>>>>>>>
                              
                              <<<<<<<<< PHASE-2 of 2PC Start >>>>>>>>>>>>>>>>>>>>>
                              ------------ abort --------------->
                              ------------------------- abort ----------------->
                              -------------------------------------- abort --------------------------->
                              <<<<<<<<< PHASE-2 of 2PC End >>>>>>>>>>>>>>>>>>>>>
```
