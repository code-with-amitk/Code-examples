## Advantages
- *1. Better Resistance to [Flash Crowd](/System-Design/Concepts/Terms/) than standard web server:* Because peers assist each other in downloading files.
- *2. Integrity check using SHA-1:* Peers check integrity of file before download using SHA1.
- *3. Uses [Biased Neighbour Selection](/System-Design/Concepts/Terms)* for reducing network traffic.

## Disadvantages
- *1.* Bittorrent is Oblivious(not aware) about underlying protocols(underlay) hence cannot take advantage of it.
