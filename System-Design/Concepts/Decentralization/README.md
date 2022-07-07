**Decentralization**
- [Methods of decentralization](#m)
- [Advantages of decentralization](#a)
- Comparison
  - [Replication vs Decentralization](#v1)
  - [Centralized vs Decentralized](#v2)
- 

## Decentralized
<a name=v1></a>
### Replication vs Decentralization
- [Replication](Replication) and Decentralized as different.
||Replication|Decentralized|
|---|---|---|
|What|Ensures mutliple copies of data are created on masters or slaves|Same|
|Availabilty|Client talks to master to get data. Client can also talk to slaves(but not mandatory)|Client can talk to any node(many different leaders) and will get data, Control is decentralized|
|Examples|MongoDB is centralized|Cassandra is decentralized|

<a name=v2></a>
### Centralized vs Decentralized
#### Centralized
Though data is stored on multiple nodes using replication, but still control is with single central authority
#### Decentralized
Control is not with any single node. Example in a college every department has its own database and that authority is solely incharge of it.

<a name=m></a>
### Methods of decentralization
Suppose you want to send money to your friend in US, what are different options you have?
- _1._ Go to bank(centralized authority) & send money. if money transfer charges are increased you have to pay
- _2._ No central authority: 
#### Disintermediation
Send this money directly without bank using blockchain technology. Get address of your friend on the blockchain.
#### Through competition
Many banks/authorities compete and provide best rates for sending money

<a name=a></a>
### Advantages of decentralization
- **Adv:**
  - No central authority(Availabilty)
  - reduced costs, competition(hence better technology)
- **Disadv:**
  - Storage of pvt keys data on seperate nodes(what if node is malicious, Security)?
  - Nodes talk to each other(without central authority), if riot happens and we donot want nodes to talk to each other(Security).
  - Node storing data suddenly goes out of network(Availabilty)
