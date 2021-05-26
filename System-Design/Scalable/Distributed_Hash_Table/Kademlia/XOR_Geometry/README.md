 ## XOR Geometry
- The XOR distance between a node and itself is zero.
- XOR is symmetric, and the distance from A to B and from B to A are equal.
- XOR satisfies the triangle inequality property.
```console
 Distance between 3 nodes (x,y,z).  d(x, y) + d(y, z) ≥ d(x, z)
 
 d(x, z) = d(x, y) ⊕ d(y, z)  //⊕ is XOR
```
