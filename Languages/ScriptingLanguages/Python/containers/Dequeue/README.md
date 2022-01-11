**Deque**
- [Initialize](#in)
- [Append](#ap)
- [Remove 1st, last](#r)

### Deque //double ended queue.

<a name=in></a>
### Initialize
```py
out = collections.deque()
```

<a name=ap></a>
### Append
```py
from collections import deque

dq = deque(["amit", "vivek", "anil"])
dq.append("harry")
print(dq)               #deque(['amit', 'vivek', 'anil', 'harry'])
```
<a name=r></a>
### Remove
```py
print(dq.popleft())         #amit
print(dq.popleft())         #vivek
print(dq)                   #deque(['anil', 'harry'])
```
