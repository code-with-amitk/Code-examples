## 1. LISTS AS STACK(LIFO):
- list can be very easily used as a stack
- Implementation
  - Consider list's end as top.
  - push element at top of stack:    
    - list.append(x) Appends element at end
 - pop element:
    list.pop() removes element from end
```
stack = [1,2,3]
stack.append(4)     #[1,2,3,4]
stack.append(5)     #[1,2,3,4,5]
print(stack.pop())         #5   //Remaning List[1,2,3,4]
print(stack.pop())         #4   //Remaning List[1,2,3]
```

## 2. LISTS AS QUEUES(FIFO)
- lists are not efficient as queues
- Why lists not good queues?
  - **Push=Slow:** Inserts or pops from the beginning of a list is slow, because all of the other elements have to be shifted by one.
  - **Pop=Fast:** appends and pops from the end of list are fast
