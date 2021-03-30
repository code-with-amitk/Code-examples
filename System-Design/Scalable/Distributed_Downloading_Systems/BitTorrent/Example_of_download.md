### Example
> Let's suppose user-1, user-2, .. user-n wants to download a MovieX or VMware(.vmdk) file sized 3-4GB.

- *1.* [Seeder](Terms.md) provides a [torrent file](Terms.md) to a [torrent server](Terms.md).
- *2.* Torrent server uploads Torrent file to Web server for clients to search torrent file.
- *3.* Seeder uploads torrent file to [Tracker](Terms.md).
- *4.* Clients gets torrent file from Web-server using [HTTP GET](/Networking/OSI-Layers/Layer5/Protocols/HTTP/). Client gets Tracker server IP inside torrent file.
- *5.* After getting tracker IP, Client connects to Tracker server(over HTTP) and gets complete list of clients downloading files/fragments(ie Swarm).
- *6.* client-n downloads fragment-1, connect to client-m, provide fragment-1 & gets fragment-2.

<img src=Bittorrent_Architecture.jpg width=600 />

- **Phases of Downloading the file**
  - *1. Bootstrap phase* Node has just received its first fragment/block. Node has recieved block using [optimistic unchoking](/System-Design/Concepts/Terms)
  - *2. Trading Phase* Enough nodes can be paired to exchange data. This is longest and most efficient phase.
  - *3. Last download phase:* Node's NS potentially dropped to 0. Node dependents on newly arriving peers to get the last missing fragments/blocks.

