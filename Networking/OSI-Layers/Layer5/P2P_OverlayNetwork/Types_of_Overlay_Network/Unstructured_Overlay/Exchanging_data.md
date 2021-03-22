## Methods of Exchanging data
- **1. Central index**
  - When a node joins, it sends a list of locally available files to the index server. Also asks for some files.
  - Index server performs query on behalf of clients.
  - When some client has requested files, the peer that sent the query receives a list of the peers that have the actual data file available.
