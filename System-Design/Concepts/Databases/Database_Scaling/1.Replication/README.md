**Replication**
- Types of Replication
  - [1. Master/Leader Slave/Follower](#ms)
  - [2. Master Master](#mm)
- [Synchronous, Asyncronous Replication](#sa)
- [Consistency problems in replication](#cp)


# Replication
Replication means keeping a copy of the **same data** on multiple machines. Each node that stores the copy is called Replica.

## Types of Replication
<a name=ms></a>
### 1.1 Master/Leader Slave/Follower
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
### 1.2 Master-Master
- All databases in master-master can RW with client.
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
Unlike semi-synchronous where leader waits for atleast 1 replica to respond, here leader does not wait for any,

<a name=cp></a>
### [Consistency Problem in Replication](/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)

