## Dijkstra Algo(DYKE-struh)
- Let Source node: 0
```c
    ----> [0] --1-- [1] --2-- [2]
          \                   /4        
           \------ [3] -----/                  

if (distance(src) + cost(src,dst) < distance(dst))
  distance(dst) = distance(src) + cost(src,dst)
```
