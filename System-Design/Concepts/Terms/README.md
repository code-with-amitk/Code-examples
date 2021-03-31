## Terms

- **Antisnubbing:** snub means ignoring someone or something. Time to time, a BitTorrent peer becomes choked/blocked by all peers from which it was receiving fragments because of poor download/upload capacity or absesnce of required fragments. 
  - *Solution:* Finds a better peer than any of the current ones.
- **Bandwidth Throttling:** Intentional slowing or speeding of an internet service by an Internet service provider (ISP). 
  - *Advantages?* To reduce bandwidth congestion, To reduce a user's usage of bandwidth.
- **End Game / End Mode:** To download all end fragments, Bittorrent client sends requests to all of its peers. As soon client gets the ending fragment it sends cancel to peers.
- **Flash Crowd:** Legitimate sudden burst in requests for a specific Web document or website. Eg: on New year wishes sent on facebook.
- **Free Riding:** Having selfish peers who do not contribute to the [swarm](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md) just wanted to take file from swarm.
  - *Solution* Node will only send packet to that whose is in his [Neighbour set(NS)](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md)
    - Example: Swarm=User-2...User-10. User-1 decides to connect user-2 for file. Now User-2 will only send file to user-1 when user-1 is in swarm downloaded from Tracker server. It means User-1 is also sending fragments.
- **Local Rarest First for Piece Selection**
  - Nodes independently maintains a list of the fragments which are least number of copies amongst [swarm](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md). Whenever a new client joins in, he is given this list and he starts downloading the rarest fragment.
- **Optimistic Unchoking:** Unselfishly provide block(s) to node(s) in Neighbour set.
  - Node uses a part of its available bandwidth for sending data to random peers, so that neighbours donot fall in tit for tat problem.
- **Tit for Tat Strategy:**  if the node-1 was cooperative, then node-2 is also cooperative. if node-1 is not cooperative then node-2 is also not.

