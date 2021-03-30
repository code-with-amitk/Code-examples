## Terms

- **Flash Crowd:** Legitimate sudden burst in requests for a specific Web document or website. Eg: on New year wishes sent on facebook.
- **Free Riding:** Having selfish peers who do not contribute to the [swarm](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md) just wanted to take file from swarm.
  - *Solution* Node will only send packet to that whose is in his [Neighbour set(NS)](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md)
    - Example: Swarm=User-2...User-10. User-1 decides to connect user-2 for file. Now User-2 will only send file to user-1 when user-1 is in swarm downloaded from Tracker server. It means User-1 is also sending fragments.
- **Optimistic Unchoking:** Unselfishly provide block(s) to node(s) in Neighbour set
- **Tit for Tat Strategy:**  if the node-1 was cooperative, then node-2 is also cooperative. if node-1 is not cooperative then node-2 is also not.

