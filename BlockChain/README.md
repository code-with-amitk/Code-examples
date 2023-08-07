**BlockChain**
- [Benefits / Why to learn Blockchain](#w)
- [Limitations of Blockchain](#limi)
- [Terms](#t)
- [Features](#f)

## Blockchain
- This is append-only, immutable distributed ledger that is updateable only via consensus/agreement among peers. There is no single authority of this ledger.
- This is [Peer to Peer](/Networking/OSI-Layers/Layer-7/P2P_OverlayNetwork/) network running over TCP. Same as HTTP,FTP over TCP

<a name=w></a>
### Why to learn blockchain
- **Decentralization:** no need for a trusted third party or intermediary to validate transactions; instead a consensus mechanism is used to agree on the validity of transactions.
- **Transparency and trust:** As blockchains are shared and everyone can see what is on the blockchain, this allows the system to be transparent and as a result trust is established.
- **Immutable:** Once the data has been written to the blockchain, it is extremely difficult to change it back.
- **High availability:** As the system is based on thousands of nodes in a peerto-peer network, and the data is replicated and updated on each and every node.
- **Highly Secure:** All transactions on a blockchain are cryptographically secured and provide integrity.
- **Cost saving:** As no third party is required in the blockchain model.

<a name=lim></a>
### Limitations of Blockchain
- Scalability
- Adaptability
- Regulation
- Relatively immature technology
- Privacy

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
