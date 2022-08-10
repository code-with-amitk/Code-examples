**BlockChain**
- [Benefits / Why to learn Blockchain](#w)
- [Terms](#t)
- [Features](#f)

## Blockchain
- This is append-only, immutable distributed ledger that is updateable only via consensus/agreement among peers. There is no single authority of this ledger.
- This is [Peer to Peer](/Networking/OSI-Layers/Layer-7/P2P_OverlayNetwork/) network running over TCP. Same as HTTP,FTP over TCP

<a name=w></a>
### Why to learn blockchain
- Enhanced security. Your data is sensitive and crucial, and blockchain can significantly change how your critical information is viewed. ...
- Greater transparency. ...
- Instant traceability. ...
- Increased efficiency and speed. ...
- Automation.

<a name=t></a>
## Terms
### Block
This is a Node(singly linked list). This is a transactions bundled together.
```c
struct block {
  struct block_header* bh;
  struct block* prev_block;   //This is Hash pointer(not normal pointer)
  long timestamp;
  long nonce;
  long transaction_counter
  struct transactions* t;
  struct other_attribute* oa;
}
```

#### Genesis Block
1st block in blockchain. This is hardcoded at time when blockchain started.

### Smart Contracts
These are the programs that run on blockchain having business logic.

### Features
#### Distributed consensus
#### Transaction verification
Only valid transactions are included in blockchain. When a node publishes a transactions its verified based on a predetermined set of rules, then its included.
