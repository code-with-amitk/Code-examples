## Gnutella Message Types

- **1. Ping:** Message sent to discover peers on the network. A new peer sends a broadcast Ping message to announce its availability. The Ping message results in a
corresponding Pong message that contains information about the peer that received the Ping message.
- **2. Pong:** The Pong message is sent as a reply to the Ping message.
- **3. Query:** The Query message is used to search a data(eg: file). This message contains a search string. Each peer that receives the Query message checks the search
string against its local database of file names. The Query message is propagated in the P2P network until the hop count reaches its maximum value.
- **4.QueryHit:** This is reply to the Query message and contains information needed for downloading the file. The file transfer is first negotiated and then performed directly by the peers.
- **5. Push:** This message is a download request that is used by peers behind firewalls to trigger push-based file transfer.
