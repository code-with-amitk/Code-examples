- Replication
  - [1. Master/Leader Slave](#ms)
  - [1. Master Master](#mm)
  - [1. Consistency problems in replication](#cp)


# Replication
Replication means keeping a copy of the **same data** on multiple machines. Each node that stores the copy is called Replica.

## Types of Replication
<a name=ms></a>
### 1.1 Master/Leader Slave
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

<a name=cp></a>
### [1.3 Consistency Problem in Replication](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)

