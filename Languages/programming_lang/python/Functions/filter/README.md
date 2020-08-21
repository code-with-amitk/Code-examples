## filter()
- **What**
  - Pass a iterable(list, tuple etc) to function, if condition inside function is true for elements in list, function will return new list contianing elements.
    - Argument-1: Function. Which defines logic of filtering
    - Argument-2: Iterable elements passed to function
    - Return value: Iterable list which satifies the condition
- **Syntax**
  - filter(function, iterable)


### Example
- 1. Return iterable from filter function containing vowels only.
```python
def fun(var):
  l = ['a', 'e', 'i', 'o', 'u']
  if (var in l):
    return True
  else:
    return False

seq = ['h','e','l','o']

ret = filter(fun, seq)

for s in ret:
    print(s)          #e o
```
