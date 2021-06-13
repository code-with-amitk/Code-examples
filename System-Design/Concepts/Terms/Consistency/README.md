## Consistency / Accuracy
- With multiple copies of data maintained between master and replicas. Every read receives the most recent write or an error.
- **Consistency patterns:**

|Type|What|Use case|
|---|---|---|
|1.Weak consistency|After a write, reads may or may not see it. A best effort is done.|<ul><li>1.Web-client:Ok to see past 1-2 min data.</li></ul>|
|2.Eventual consistency|After a write, reads will eventually see it (typically within milliseconds)||
|3.Strong consistency|After a write, reads will see it. Data is replicated synchronously|<ul><li>1.Stock Exchanges or auctions</li></ul>|
