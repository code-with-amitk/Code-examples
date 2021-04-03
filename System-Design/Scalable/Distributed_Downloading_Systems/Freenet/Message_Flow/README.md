## Architecture
- **1. Files are identified using keys**
  - Upon receiving a request for an unknown key, node forwards the request to another node that has keys closer to the requested key.
  - A node will most likely download files with similar keys
- **Routing?** Each node only knows the its immediate neighbors.

### Message Flow
> Node enters into Freenet network using [Bootstraping](/System-Design/Concepts/Terms).
- *1.* node A sends a request(Contains KEY of file) for a certain file.
- *2.* B does not have the file request is sent to C.
- *3.* Node C does not know any other nodes and responds to B that the request has failed.
- *4.* B contacts E.
- *5.* E sends request to F. F does not know any other nodes and responds with a failure.
- *11.* E to contact D, which has the requested file. The ENCRYPTED file is then sent back to Avia E and B.
> At each step the validity of the file is checked by intermediate nodes, and they may cache the file.

<img src=freenet_message_flow.JPG width=500 />
