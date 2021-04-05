## Key based Routing
- Every file is identified by unique key.
- Every node builds its routing table based on keys advertised by its neighbours.
- Nodes try to use [Path Folding / Location Swapping](/System-Design/Concepts/Terms) to find shortest route.
- On request of file. Corresponding key is searched on nodes which advertises keys near to requested file.
  - Because its assumed that nodes caches a range of nearby keys.
