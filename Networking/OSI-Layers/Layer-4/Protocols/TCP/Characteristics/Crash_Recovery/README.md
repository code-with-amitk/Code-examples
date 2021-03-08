## Crash Recovery
- TCP provides seqno of each segment. Reciever need to send ACK of seqno.
- Let TCP Server crashes in mid-way of communication.
  - Server recovers and broadcasts TPDU to all its clients.
  - Clients will send the last seqno which was never unacknowledged and server knows which segment to send again to which client.

### TPDU(TCP Protocol data Unit)
- PDU is a single unit of information transmitted among peer entities of a computer network. A PDU is composed of protocol-specific control information and user data.
