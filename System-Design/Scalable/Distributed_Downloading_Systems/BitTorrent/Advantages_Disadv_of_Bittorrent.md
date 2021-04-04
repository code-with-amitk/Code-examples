## Advantages
- *1. Better Resistance to [Flash Crowd](/System-Design/Concepts/Terms/) than standard web server:* Because peers assist each other in downloading files.
- *2. Integrity check using [SHA-3](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security):* Peers check integrity of file before download using SHA3.
- *3. Uses [Biased Neighbour Selection](/System-Design/Concepts/Terms)* for reducing network traffic.

## Disadvantages
- *1.* Bittorrent is Oblivious(not aware) about underlying protocols(underlay) hence cannot take advantage of it.
- *2.* As size of Bittorrent increases, more peers gets added, Malicious peers may also get added(since there is no check on mailicous peers). These malicious peers may generate DDOS attack.
- *[3. Free Riding](/System-Design/Concepts/Terms)*
- *4.* Peer can provide Fragment based on number of fragments recieved. This will lead to chocking at some point.
  - *Solution:* Good fair treatment for peers having balaced send/recv ratio.
