**Transaction**

### Transaction
```c
                                            |----|
Application ---data pkt----> |DB Manager|   | DB |
                                            |----|
```
- Application sends data packet database manager. DB manager will not write every packet to database. DB Mgr will group several reads and writes together into a logical unit. This logical Unit is called TRANSACTION.
- All the reads and writes in a transaction are executed as one operation(either the entire transaction succeeds or it fails). If it fails, the application can safely retry.
- **Why Transaction is needed?**
  - _1. Better Debugging:_ if DB Mgr dies in between, then Admin need not to worry about partial failure—i.e., the case where some operations succeed and some fail (for
whatever reason).
