## Terms
- **Torrent Server/Coordinator Server/Web Server:** 
  - Clients uploads torrent files on Torrent server and torrent server places it on Web Server.
  - TS provides torrent file to requesting clients on HTTP.
  - Tracker has following information:
    - List of active clients/peers inside swarm.
    - Fragments each client/peer hold.
    - Upload/Download speed of peers.
- **Torrent File:** Contains information about file chunks and their hashes and IP Address of tracker server.
```c
# cat torrent_file
Creation Date: <>
Length: <>
IP_Address_of_Torrent: <>
Name of file: <>
  fragment-no   hash
    1           xxx
    3           yyy
```
- **Tracker** Stores
  - Fragments/pieces/chunks of files.
  - Status of peers/clients in swarm and pieces/fragments clients have with them.
- **Peer/Client:** (who wants file to be downloaded) should find tracker and downloaded torrent
- **Seeder:**
  - Peer that provide a complete file with all of its pieces.
  - This file contains information about the data, including the pieces and their hashes.
- **Leecher** All others clients in the swarm are known as leechers, who have some fragment of file but want more fragments.
- **Fragment size** Configurable default 256KB. Varies from  64 KB to 4 MB.
- **Block**  The unit of data transfer between two peers is that of a block, default 16 Kbyte.
- **Seed:** Peer that provides a file, maybe a portion of file.
- **Swarm:** Group of peers involved in downloading and sharing files.
- **Neighbour Set:** Neighbours in swarm.
