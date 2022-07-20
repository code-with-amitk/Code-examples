**Transaction**

### Transaction
```c
                                            |----|
Application ---data pkt----> |DB Manager|   | DB |
                                            |----|
```
> Not writing every single packet, But group of Reads/Writes together as logical unit.
- Application sends data packet to DbMgr. DB Manager will not write every packet to database but it groups several reads/writes together into a logical unit. This logical Unit is called TRANSACTION. 
- Note: Every application does not need transaction.
- All the reads and writes in a transaction are executed as one operation(either the entire transaction succeeds or it fails). If it fails, the application can safely retry.
- **Why Transaction is needed?**
  - _1. Better Debugging:_ if DB Mgr dies in between, then Admin need not to worry about partial failure—i.e., the case where some operations succeed and some fail.
  - _2. Safety Gurantees:_ By using transactions, Application can ignore certain error scenarios & concurrency issues, because the DB takes care of them.
