- [What is Chord](#what)
- [New node joining the chord](#new)
- [Node leaving chord](#leave)
- [Search key in chord](#search)

<a name=what></a>
## Chord = Consistent Hashing
- Each real node where `<key,value>` is stored maybe comprised of n virtual machines. Analysis will be for 1 of Virtual machine.
- Nodes are arranged in circular ring. Every node maintains the finger/routing table to reach nodes further away in the ring in clockwise direction.
```c
           | Node-1 | Node-2 | ...Node-n |
-----------|--------|--------|-----------|
keys range | 0-10   | 10-20  |  n-10..n  |

Nodes=n, keys=k
Every node holds = k/n keys
```

<img src=chord-dht.JPG width=500/>

<a name=new></a>
## New Node joining Chord
- When new node(x) joins the network, some keys assigned to x’s successor will be moved to x. 

<a name=leave></a>
## Node Leaving Chord
- When node leaves the network, all keys assigned to node are reassigned to its successor.
- Leaving node informs its successor & predecessor that it is leaving, allowing the system to reconfigure.

<a name=search></a>
### Search key in chord
- Complexity=logn. 
- Since nodes store keys in ascending order, using finger table binary jumps can be performed.
- Searching element on 1 node takes O(1) time.
