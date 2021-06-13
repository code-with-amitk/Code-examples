## CONSISTENCY(Accurate)
- With multiple copies of data maintained between master and replicas. Every read receives the most recent write or an error.
- **Consistency patterns**
  - _a. Weak consistency:_ After a write, reads may or may not see it. A best effort approach is taken. Eg: Web-client: Ok to see past 1-2 min data
  - _b. Eventual consistency:_ After a write, reads will eventually see it (typically within milliseconds). 
  - _c. Strong consistency:_ After a write, reads will see it. Data is replicated synchronously. Eg: Stock Exchanges or auctions
