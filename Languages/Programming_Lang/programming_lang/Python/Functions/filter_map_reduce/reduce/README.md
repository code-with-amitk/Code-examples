## reduce()
- **What**
  - Apply condition to iterable passed as input to function and reduce the list to single value
  - Its not builtin but present inside *module functools*.
- **Syntax**
  - reduce(function, sequence`[, initial]`)
  
### Examples
#### 1. Function reduce() to add all values
```python
from functools import reduce

def add(x, y):
    return x + y

list = [2, 4, 7, 3]
print(reduce(add, list))                #16
```
