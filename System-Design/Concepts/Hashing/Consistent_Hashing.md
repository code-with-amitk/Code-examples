## DHT(Distrbuted Hashing)/DCT(Distributed Caching)
- **What**
  - Cache is distributed over cluster of servers.
- **Advantages**
  - Horizontal scaling is very easy.
  - Scaling down is easy.
  
## Consistent hashing/Consistent Hash Ring

- Hash value is generated from Hash function but to find exact slot mod is not performed. 
- Each entry in hash table is assigned predefined value, Once 
```
    cat->|Hash-fun|->2000        
    dog->|Hash-fun|->8392        
    rat->|hash-fun|->3000    
    mat->|hash-fun|->10500//Value is greater than key, move to 1st location & Store
    
//Search key greater than generated value and store at that index.

           ---------------sort of ring-------------------------------
            \/                                                       |
          | mat    | cat->rat  |           | dog      |         | 
key      1081     3098        5068        8000        9084    10000
```
