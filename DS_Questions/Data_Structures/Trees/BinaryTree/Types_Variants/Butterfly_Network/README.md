## Butterfly Network
- **What?** This is a technique to link multiple computers into a high-speed network. Butterfly contains a binary tree with root in the first level.
- **Formula?**
  - n = 2<sup>d</sup>   //n:Processors/Computers, d:depth
  - s = n(logn+1)       //s:switches
- Example:
  - d=3. n=8. s=8x4=32

<img src=Butterfly_Network.jpg width=400 />

- **Advatanges?**
  - Butterfly networks have lower diameter than other topologies like a linear array, ring and 2-D mesh hence message sent from 1 processor to destination will reach in a lower number of network hops.
  - Butterfly networks have higher bisection bandwidth than other topologies. This implies that in butterfly network, a higher number of links need to be broken in order to prevent global communication.

