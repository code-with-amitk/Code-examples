**Replication**
- Types of Replication
  - [1. Master/Slave or Leader/Follower](#ms)
  - [2. Master/Master or Active/Active or Leader/Leader](#mm)
- [Synchronous, Asyncronous Replication](#sa)
- Problems in Replication
  - [1. Master Node dies. Failover](#p1)
  - [2. Slave Node outrages, Dying slaves](#p2)
  - [2. Consistency problems](/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/)
- Implementation of Replication Log
  - [1. Statement-based replication](#i1)
  - [2. Write-ahead log (WAL) shipping](#i2)
  - [3. Logical (row-based) log replication](#i3)
  - [4. Trigger based replication](#i4)


# Replication
Replication means keeping a copy of the **same data** on multiple machines. Each node that stores the copy is called Replica.

## Types of Replication
<a name=ms></a>
### 1. Master/Slave or Leader/Follower
- 1 node is designated as Leader/master. Client does RW operations with master, and only Read on any of slave. If master goes down slaves serve as RO DB. Slaves can also replicate among themselves.
- **How it works**?
  - Master stores session in it'd DB 1st then master writes(or slave reads) data to replicas/slaves(as replication log or change stream).
  - Each slave takes the log from master and updates its local copy of the database in the same order as they were processed on the leader.
- **Disadv:**    
  - _a._ Logic is required to promote slave to master    
  - _b._ If high number of slaves, more write operations can lead to replication lag.
```c
//Write only to Master
                                       |-Write--> RO-SlaveReplica-DB-1
  client  ----Write----->  MasterDB ---|                           
                           /\          |-Write--> RO-SlaveReplica-DB-2
                           |                      /\
  client  ----Read---------|-----------------------|
//Read to Master or Replica(any)
```
<img src=master_slave.PNG width=600/>

<a name=mm></a>
### 2. Master/Master or Active/Active or Leader/Leader
- There are 2 or more leader nodes
- As in [Master-Slave](#ms) replication, Client Writes to master and read from any slave
  - Same concept applies here, Client can write to any 1 of leader. Other leaders will act as slave and read all data from present leader.
#### Usecases of Master/Master configuration
- _1. Multi datacenter operation:_ 
  - if we have slaves placed in different datacenters to tolerate failover. 1 leader in each datacenter. 
  - Between datacenters leader/leader replication happens. While within datacenter leader/follower replication takes place.
- _2. Clients with offline operation:_
  - Suppose we have google drive laptop. if user is offline and writes the data(its saved to disk) and when he comes online sent to other servers.
  - This laptop(having google drive) can be thought as Leader which sends data to other leaders, failover recovery is high in this case.
- **Disadv:** 
  - _a._ Load balancer maybe required in front to configure client where to send the requests.    
  - _b._ conflicts becomes more and more as more write nodes comes into picture.
```c
  client-1  <----RW------->    MasterDB
                                  |RW
  client-2  <----RW-------->  masterReplica-DB-1
```

<a name=sa></a>
### Synchronous, Asynchronous Replication
#### Semi-Synchronous Configuration
- Leader does not wait for ACK from all Followers/slaves for sending ACK to user. When Master recieves ACK from any 1 slave(called Synchronous replica) it sends ACK to user.
- Now if Synchronous replica goes down, master creates some other replica as Synchronous from where response is recieved.
- So its a Gurantee that user has atleast 2 copies of up-to-date data. 1 master & 2nd with Synchronous replica.
  - _Why master does not wait for ACK from all replicas?_
    - if master has 10 slaves and 1 slave is not in sync(maybe due to slow network, hardware failure etc), then we cannot wait for slave's problem to get corrected and then send response to user.

<a name=sync_async.PNG width=400 />

#### ASynchronous configuration
Leader does not wait for any replica to ACK.

## Problems in Replication
<a name=p1></a>
### 1. Master/Leader Node Fails(power failure, network outrage, crash etc)
#### Solution-1: Failover
- A slave need to be promoted to master(new leader).
- All clients should connect to new Leader, all slaves should receive updates from new leader.
- Failover can be manual(By Adminstrator) or Automatic.
- **Automatic Failover steps**
  - _1. Leader Election:_ 
    - All replica nodes choose a replica as a leader(who has most up-to-date DB). [Gettting nodes to agree on 1 leader=Consensus Problem] OR
    - A controller node(previously appointed) can also choose a leader
  - _2. Replicas configured to use new leader:_ All replicas will send requests to new leader.
  - _3. Old leader need to recognize new leader:(SPLIT BRAIN PROBLEM)_
    - Now if old master comes up & thinks himself as master, while nodes has made him stepped down then this can be problamatic(both old and new leaders will accept writes and lead to out of sync cluster).
    - _Solution:_ if 2 leaders are found, 1 leader can be shut down.

<a name=p2></a>
### 3. Slave nodes dies(hardware crash, kernel update)
#### Solution-1. Recover from Replication log on Local Disk
- Each follower keeps log of data change from Leader. After node boots up, it can use this to build DB state.
- Follower can connect to leader and request all updates after last entry in replication log.


## Implementation of Replication Log
Follower/Replica/Slave stays in-sync with master, even recovers from failure using Replication log.
<a name=i1></a>
### 1. Statement-based replication
- leader logs every Insert/Update/Delete statement that it executes and sends that statement log to its followers.
- Each follower parses and executes that SQL statement as if it had been received from a client
- **Problems,Solutions:**
  - _Problems-1._ SQL statements having some timebased/random functions time()/rand() will generate different outputs on Replicas.
    - Solution: leader can replace any non-deterministic function calls with a fixed value.
```c
  Leader --update/del--|--> DB
                       |--> replication_log_file
                                |
                                |----> Slave-1
                                |----> Slave-2
                       
```

<a name=i2></a>
### 2. Write-ahead log (WAL) shipping
- Provides [Atomicity, Durability](/System-Design/Concepts/)
- Write to Log file 1st before writing to DB. Every opeartion Insert/Delete/Update is written to log then DB.
- _Benefit of WAL:_ Suppose node crashes while writing, so when it recovers it can check Log file and actual Disk content so see what's completed and not.

<a name=i3></a>
### 3. Logical (row-based) log replication
- Master creates a log(called physical log) when it update/delete/insert entry in DB. But a different log(called logical log) is sent to Follower as replication log.
- Advantage: 
  - _1._ it segregates master and follower's logs.
  - _2._ A logical log format is easier for external applications to parse(Eg: data analytics, warehouse)
- Logical log will contain all writes to DB.

<a name=i4></a>
### 4. Trigger based replication
- Replication logic is moved to application layer. 
- Data changes are made available to Application by reading replication log, now application can move this data to other DB or to analytics engine.
- Involvement of Application into replication induces some bugs.
