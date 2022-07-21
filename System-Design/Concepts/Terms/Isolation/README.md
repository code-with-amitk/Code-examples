**Isolation**
- Achieving Isolation
  - [1. Read Committed](#rc)

## Isolation
Concurrently executing [transactions](/System-Design/Concepts/Terms/Transaction) are isolated from each other ie they cannot step on each other.

## Achieving Isolation
<a name=rc></a>
### 1. Read Committed
It ensures No Dirty Reads, No Dirty writes
#### No Dirty Read
When reading from DB, we will only see data that has been committed ie not reading a broken transaction.
#### No Dirty Writes
When writing to DB, we will only overwrite data that has been committed, ie not writing on broken transaction.
