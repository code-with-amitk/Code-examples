# Multicast Encryption OR Secure Multicast
## A. What
- This is securing the multicast traffic.
- Each host in multicast group should communicate securely with every other host using a **multicast group net key**. 
- securely **rekeying** the users of the multicast group when necessary.

## B. How its different from normal key management
- Users can be added and removed securely and efficiently, both individually and in bulk.
- Users who have been dropped should not be able to read any subsequent traffic.

## C. Real world examples
- **Distributed gaming** 1000 participants, very rapidly dropping/joining at high bandwidth.
- Video Confrencing

## D. Nodes in Architecture
### 1. Initiator
- This is the Node starting multicast session. Does following tasks:
  - Set security attributes for that particular session (e.g: classification levels of traffic, algorithms to be used, key lengths, etc.)
  - Creates group access control list(ACL) called initial multicast group participant list.
### 2. Root/Server
- Node which controls the multicast group, this is elected by Initiator.
- Root's responsibilities:
  - Perform the addition and deletion of group participants
  - Perform user access control against the security attributes of session
  - Distribute **traffic encryption key(called multicast group NET KEY)**.
### 3. List Controller
- After initialization, LC is the node with authority to addition/delete future group participants
### 4. Group Participants
- Every participant in the multicast session

## D. How it works
### HIERARCHICAL TREE APPROACH
![ImgURL](https://i.ibb.co/5KnYcWg/preplaced-keys.png)
- All nodes will set at leaves.
- Here, Key-I will be encrypted using Key-M and so on.
- For the example a user at depth d=4 would hold five keys.
- A common Net Key for  the multicast group which is separately encrypted.
### 1. 1st time key exchange
- All multicast users have recieved Certificates from Root-CA.
- DH is used for negotiation of keys. This is called **PRE-PLACED-KEYS** for user.
- This pairwise key exchange and Net Key distribution continues for all  N users of the multicast group.
- Root will maintain KEK(Key Encryption Keys) per user. Which is used for encrypting keys sends to each user.
- 
### 2. User leaving group
- Group participant leaves multicast group all other participants should be rekeyed new Net Key.
- Root sends a new Net key encrypted with each individual's KEK to all remaining participants.
