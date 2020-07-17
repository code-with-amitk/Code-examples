"""     deque.py

What? This is double ended queue.
Methods:
    append(): Adds item at end
    popleft(): Removes element from top
"""

from collections import deque

dq = deque(["amit", "vivek", "anil"])
dq.append("harry")
dq.append("matt")
print(dq)               #deque(['amit', 'vivek', 'anil', 'harry', 'matt'])
print(dq.popleft())         #amit
print(dq.popleft())         #vivek
print(dq)                   #deque(['anil', 'harry', 'matt'])

