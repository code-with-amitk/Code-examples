**Online Test**


### Online Test
- Task: Implement the assign() member function of this data structure `interval_map<>`. `interval_map<K, V>` is implemented on top of std::map.
- `interval_map<K,V> m_map` is a data structure that associates keys of type K with values of type V. Intervals of consecutive keys are associated with the same value. 
- Each key-value-pair (k,v) in `interval_map<K,V> m_map` means that the value v is associated with all keys from k (including) to the next key (excluding) in m_map.
- For example
```c
    Key     Value
    10      x0
    11      x1
    12      x2
    20      x20

10,11,12 are consecutive keys.

Q1: What is meaning of intevals of consecutive keys?
Does this mean (10 to 12)
Q2: Intervals of consecutive keys are associated with same value?
Does this mean (10,11,12) all have same value xy. And map becomes
    Key     Value
    10      xy
    11      xy
    12      xy
    20      x20
```
- The member `interval_map<K,V>::m_valBegin` holds the value that is associated with all keys less than the first key in m_map.
```
Example: Let m_map be an instance of `interval_map<int,char> m_map` where
    m_map.m_valBegin==a,
    M.m_map=={ (1,b), (3,a) },

Then M represents the mapping
    key     Value
    -2      a
    -1      a
    0       a
    1       b       //Why not a?. Interval of consecutive keys is still 1
    2       b
    3       a       //Why again a
    4       a
    5       a    
```
- The representation in the std::map must be canonical, that is, consecutive map entries must not contain the same value: ..., (3,'A'), (5,'A'), ... is not allowed. 
    - But in above example you given its allowed.
- Likewise, the first entry in m_map must not contain the same value as m_valBegin. Initially, the whole range of K is associated with a given initial value, passed to the constructor of the interval_map<K,V> data structure.
- Key type K
  - copyable and assignable, is less-than comparable via operator<, and
  - does not implement any other operations, in particular no equality comparison or arithmetic operators.
- Value type V
  - copyable and assignable, is equality-comparable via operator==, and
  - does not implement any other operations.
