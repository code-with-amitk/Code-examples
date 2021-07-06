- [1. filter()](#filter)
  - [1.1 Ex: Return iterable from filter function containing vowels only](#vowel)
- [2. map()](#map)
  - [2.1 Ex:Double values in list using map()](#mapex)
- [3. reduce()](#reduce)
  - [3.1 Ex:Function reduce() to add all values](#reduceex)

<a name=filter></a>
## 1. filter()
- Pass a iterable(list, tuple etc) to function, if condition inside function is true for elements in list, function will return new list contianing elements.
```py
filter(function, iterable)

Arguments:
Function: Which defines logic of filtering
Iterable: elements passed to function

Return value: Iterable list which satifies the condition
```
<a name=vowel></a>
#### 1.1 Return iterable from filter function containing vowels only.
```py
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

<a name=map></a>
## 2. map()
- Perform operation on input iterable(list,tuple etc) create map object(result of applying logic defined inside function) is passed to map function annd return.
```py
map(function, iterator)
function : It is a function to which map passes each element of given iterable.
iter : It is a iterable which is to be mapped.
```
<a name=mapex></a>
#### 2.1 Ex:Double values in list using map()
```py
def fun(n):
    return n + n

num = (1, 2, 3, 4)
res = map(fun, num)

print((res))              //<map object at 0x7f379salsk>
print(list(res))          //(2,4,6,8)
```

<a name=reduce></a>
## 3. reduce()  
- Apply condition to iterable passed as input to function and reduce the list to single value
- Its not builtin but present inside module functools.
```py
  reduce(function, sequence`[, initial]`)
```
<a name=reduceex></a>
#### 3.1 Example: Function reduce() to add all values
```py
from functools import reduce

def add(x, y):
    return x + y

list = [2, 4, 7, 3]
print(reduce(add, list))                #16
```

## Comparison

||filter()|map()|reduce()|
|---|---|---|---|
|1st argument|Function-name or function object|same|same|
|2nd argument|iterable(container which can be iterated eg(list,tuple))|same|same|
|Return|true or false|complete iterable|Single value|
|What|returns true for items satisfying the condition in function|Returns complete modified list|Reduces the list to single value and return|
