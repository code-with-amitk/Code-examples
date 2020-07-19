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

## D. How it works
- All multicast users have recieved Certificates from Root-CA.
### Nodes in Architecture
#### 1. Initiator
- This is the Node starting multicast session. Does following tasks:
  - Set security attributes for that particular session (e.g: classification levels of traffic, algorithms to be used, key lengths, etc.)
  - Creates group access control list(ACL) called initial multicast group participant list.
#### 2. Root/Server
- Node which controls the multicast group, this is elected by Initiator.
- Root's responsibilities:
  - Perform the addition and deletion of group participants
  - Perform user access control against the security attributes of session
  - Distribute **traffic encryption key(called multicast group NET KEY)**.
#### 3. List Controller
- After initialization, LC is the node with authority to addition/delete future group participants

