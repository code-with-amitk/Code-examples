## map()
- **What**
  - Perform operation on input iterable(list,tuple etc) create map object(result of applying logic defined inside function) is passed to map function annd return.
    - Argument-1: function : It is a function to which map passes each element of given iterable.
    - Argument-2: iter : It is a iterable which is to be mapped.
- **Syntax**
  - map(function, iterator)
  
### Examples
#### 1. Double values in list using map()
```python
def fun(n):
    return n + n

num = (1, 2, 3, 4)
res = map(fun, num)

print((res))              //<map object at 0x7f379salsk>
print(list(res))          //(2,4,6,8)
```
