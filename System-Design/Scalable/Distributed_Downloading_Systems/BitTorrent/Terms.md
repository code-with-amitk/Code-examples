## Terms
- **Torrent Server/Coordinator Server/Web Server:** 
  - Centralized server having list of active nodes(client-IP addresses which are downloading a file) and fragment number which is already downloaded.
  - This is a Web server accepting HTTP or HTTPS GET requests and provides torrent files.
  - Tracker has following information:
    - List of active clients/peers inside swarm.
    - Fragments each client/peer hold.
    - Upload/Download speed of peers.
- **Tracker** Maintains status of a torrent (for example, the peers and information about the pieces they have).
- **Torrent File:** Contains 
  - Information about file chunks and their hashes
  - IP Address of tracker server.
```c
# cat torrent_file
  chunk-no  hash
    1       xxx
    3       yyy

IP_Address_of_Torrent 10.45.3.13
```
- **Peer/Client:** (who wants file to be downloaded) should find tracker and downloaded torrent
- **Seeder:**
  - Peer that provide a complete file with all of its pieces.
  - This file contains information about the data, including the pieces and their hashes.
- **Leecher** All others clients in the swarm are known as leechers, who have some fragment of file.
- **Fragment size** configurable default 256KB.
- **Block**  The unit of data transfer between two peers is that of a block, default 16 Kbyte.
- **Seed:** Peer that provides a file, maybe a portion of file.
- **Swarm:** Group of peers involved in downloading and sharing files.
- **Neighbour Set:** Neighbours in swarm.
