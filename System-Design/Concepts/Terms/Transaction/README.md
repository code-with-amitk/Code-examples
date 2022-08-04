**Transaction**
- [Why Transaction needed](#w)
- **Types**
  - [1. Database-internal distributed transactions](#t1)
  - [2. Heterogeneous distributed transactions](#t2)
- **Problems**
  - [Lost Updates](#l)
- **Serializability (to avoid Concurrency Problems)**
  - [1. Actual Serial Execution](#s1)
  - [2. Two Phase Locking / 2PL](#s2)
  - [3. Predicate Lock](#s3)
  - [4. Index range locks / next key lock](#s4)
- **Terms**
  - [Write Skew / Phantom](#ws)

# Transaction
```c
                                            |----|
Application ---data pkt----> |DB Manager|   | DB |
                                            |----|
```
> Not writing every single packet, But group of Reads/Writes together as logical unit.

- Application sends data packet to DbMgr. DB Manager will not write every packet to database but it groups several reads/writes together into a logical unit. This logical Unit is called TRANSACTION. 
- Transaction also means writing complete object to DB, if at half something fails aborting complete object.
- Note: Every application does not need transaction.
- All the reads and writes in a transaction are executed as one operation(either the entire transaction succeeds or it fails). If it fails, the application can safely retry.

### Types
<a name=t1></a>
#### 1. Database-internal distributed transactions
Some Databases support INTERNAL TRANSACTIONS among nodes of database. Eg: VoltDB and MySQL Cluster’s NDB.

<a name=t2></a>
#### 2. Heterogeneous Transactions
Databases from different vendors/technologies or Non-DB systems(Eg: Message brokers) communicate.

<a name=w></a>
### Why Transaction is needed?
- _1. Better Debugging:_ 
  - if Application is writing 20KB json document to DB. After 10KB node crashes, User will see partially updated values which is Wrong.
- _2. Safety Gurantees:_ By using transactions, Application can ignore certain error scenarios & concurrency issues, because the DB takes care of them.

## Problems
<a name=l></a>
### 1. Lost Updates / Read-Modify-Write Cycle / Later write clobbers the earlier write
- Transaction-1, Transaction-2 does read some value from the database, modifies it, and writes back the modified value.
- If two transactions do this concurrently, one of the modifications can be lost, because the second write does not include the first modification.
#### Solutions
- **a. Atomic Write Operations / Cursor Stability / Read Lock / MUTEX:**
  - Take RWlock on the object when it is read so that no other transaction can read it until the update has been.
  - This is serial execution of Read-Modify-Write cycle.
- **b. Automatically detecting lost updates:**
  - Execute Read-Modify-Write in parallel by 2 or more transactions.
  - if the transaction manager detects a lost update, abort the transaction and force it to retry its read-modify-write cycle
- **c. Compare and Set:**
  - Read a value from DB, if its not same as old value read(Do not write).

## Serializability
Means executing transactions one after other, serially. This is used to avoid concurrency problems.
<a name=s1></a>
### 1. Actual Serial Execution
- _a._ Execute only one transaction at a time, in serial order, on a single thread.
- _b._ OR Partition the data and execute different pieces on different CPU cores.

<a name=s2></a>
### 2. Two Phase Locking / 2PL
- Read/Write:
  - _Reading:_ No lock
  - _Writing(mutex):_ This blocks other Writers and Readers as well.
- _Disadv:_ Can be very slow at high percentiles.

<a name=s3></a>
### 3. Predicate Lock
For objects that do not yet exist in the database, but which might be added in the future. Taking lock earlier

<a name=s4></a>
### 4. Index range locks / next key lock
- Suppose a meeting room booking example has [reverse index](/System-Design/Concepts/Databases/Indexing/) on room number.
- Shared Lock is given to 3 transactions which want to book a room number, When 4th transaction comes it need to wait.


## Terms
<a name=ws></a>
### Write Skew / Phantom
- When 2 transactions update different objects after reading common object causing Race condition.
```c
Example:
There is a hospital where atleast 1 doctor is required to be on shift(always) in hospital.
Doctors can giveup their shifts if they are Sick, provided atleast 1 of their collegue stays in hospital.
- Alice & Bob are 2 doctors(on particular shift) feeling unwell and decide to request leave.
- Both click "Apply leave" button at same time.

Doctors
  Alice true
  Bob   true
  
    Alice                                     Bob
  select * from doctors                     select * from doctors
  where on_call=true and id=12              where on_call=true and id=12
  > currently oncall=2                      > currently oncall=2
  
  if(currently oncall>2)                    if(currently oncall>2)
  update doctors                            update doctors
  set on_call=false                         set on_call=false
  where name=Alice and id=12                where name=Bob and id=12

Doctors
  Alice false
  Bob   false
```
