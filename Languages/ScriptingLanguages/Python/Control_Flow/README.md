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
```py
words = ['cat', 'window', 'defenestrate']               //Iterate over list
for w in words:
  print(w, len(w))

for i in range(0, 4):                       //Iterate over range
  print (i)           #0,1,2,3

str = "abc"
for i in reversed(str):                   //Reverse Print
  print (i)                               //cba
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
