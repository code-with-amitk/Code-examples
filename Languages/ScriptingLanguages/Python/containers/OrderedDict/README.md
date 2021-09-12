**OrderedDict**
- [Example](#ex)

## OrderedDict
- OrderedDict is a dictionary subclass that remembers the order that keys were first inserted.
- **dict vs OrderedDict** OrderedDict preserves order in which keys are inserted. reguar dict does not track the insertion order.
 
<a name=ex></a>
#### Example
```py
from collections import OrderedDict 

d = {} 
d['a'] = 1
d['b'] = 2
d['c'] = 3
d['d'] = 4
  
for key, value in d.items(): 
    print(key, value)              #('a', 1) ('c', 3) ('b', 2) ('d', 4)   //See no order
  
od = OrderedDict() 
od['a'] = 1
od['b'] = 2
od['c'] = 3
od['d'] = 4
  
for key, value in od.items(): 
    print(key, value)             #('a', 1) ('b', 2) ('c', 3) ('d', 4)    //See order
```
