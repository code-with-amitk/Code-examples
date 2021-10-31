- [if()](#if)
- [for()](#for)
- [match](#m)
- [range()](#r)


### if statement
```py
if x < 0:
  x = 0
  print('Negative changed to zero')
elif x == 0:
  print('Zero')
else:                           //Optional
  print('More')
```

<a name=for></a>
### for statement
Iterates over the items of any sequence (a list or a string), in the order that they appear in the sequence
```py
... words = ['cat', 'window', 'defenestrate']               //Iterate over list
>>> for w in words:
...     print(w, len(w))

/////////////////Iterting from (0, n)////////
for x in range(0, n+1):
  print (x)
```

<a name=m></a>
### match statement = switch
```py
def http_error(status):
    match status:
        case 400:
            return "Bad request"
        case 404:
            return "Not found"
        case 418:
            return "I'm a teapot"
        case _:
            return "Something's wrong with the internet"
```

<a name=r></a>
### range()
iterate over a sequence of numbers
```py
>>> for i in range(5):
...     print(i)
```
