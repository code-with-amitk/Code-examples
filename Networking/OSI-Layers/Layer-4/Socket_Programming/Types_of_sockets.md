### Types of Sockets

- **Majorly:**

||Protocol|Features|Applications using TCP|
|---|---|---|---|
|Stream Socket, SOCK_STREAM|TCP|reliable, connection-oriented|Telnet, HTTP|
|Datagram, SOCK_DGRAM|UDP|unreliable, connection-less|multiplayer games, streaming audio, video conferencing, TFTP|
|SOCK_PACKET, SOCK_RAW|RAW|Send/receives packet on DL Layer|IP, Transport, Application Headers are placed by the Application only|

- **[Other Types](APIs_Structures/APIs/socket):** See Communication domain
