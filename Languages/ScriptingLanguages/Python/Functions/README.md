- Function
  - [1. Used as Object](#o)
  - [2. Passed as arguments](#arg)
  - [3. As Mutable Objects](#mut)
- [Variable no of Arguments](#var)
- **Types of Functions**
  - [Inner, function inside function](#func)
- **Function Arguments**
  - [Arguments taking default value](#default)
  - [kwarg, keyword Arguments](#kwarg)
  - [Special Parameters](#special)
- [Built in methods: Dunder/Magic, `__ITER__(), __CONTAINS__, __REPR__(), __STR__(), __doc__, __init__`](Builtin_Methods)
- [Mostly used Functions: split() & rsplit(), string.strip(`[char]`), type(), format(), range(), input(str)](Mostly_Used_Functions)
- [filter(), map(), reduce()](filter_map_reduce)

<a name=o></a>
### Function used as Object
Means functions can be used as variable
```py
def fun():
    return "Hello"
test = fun
print(test())        #Hello
```
<a name=arg></a>
### Function passed as argument to other function
```py
def f(a,b):
    return a+b
def f1(var):
    print("hello",var)
f1(f(1,2))              #Passing function f() as argument of f1() //hello 3
```
<a name=mut></a>
### Function as Mutable Objects
- MUTABLE OBJECTS(list,dictionary etc): Are shared between subsequent calls
```py
def fun2(a, L=[]):
    L.append(a)
    return L
print(fun2(1))     #[1]
print(fun2(2))     #[1,2]
print(fun2(3))     #[1,2,3]
```
<a name=var></a>
### Variable no of arguments
```py
def fun(*arg):
    for var in arg:
        print(var)
        return
fun ( 10, 20, 30 )
fun ( 1, 2 )
fun ( 'te', 90 )
```

## Types of Functions
<a name=inner></a>
### Inner, function inside function
Note that the order in which the inner functions are defined does not matter. 
```py
def parent():
    print("Parent")
    def fun1():
        print("fun1")
    def fun2():
        print("fun2")
    fun2()
    fun1()
parent()        #O/P: parent fun2 fun1
```

## Function Arguments
<a name=default></a>
### Arguments taking default value
```py
def fun1(a, c='Again'):            #c is default arguments
    if a == 1:
        print('Test1')
    elif a==11 and c=='Hello':
        print('Test3')
fun1(1)                 #Test1
```
<a name=kwarg></a>
### kwarg, Keyword Arguments
kwarg MUST follow positional arguments
<a name=special></a>
### Special Parameters
```py
def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
      -----------    ----------     ----------
        |             |                  |
        |        Positional or keyword   |
        |                                - Keyword only
         -- Positional only
  - By default, arguments may be passed to function either by position or by keyword.
  - If / and * are not present in function definition, arguments may be passed to a function by position or by keyword.
  - POSITION ONLY PARAMETER(/):
    Parameters cannot be passed by keyword
    Positional-only parameters are placed before / (forward-slash)
    Parameters after / may be positional-or-keyword or keyword-only

  - KEYWORD ONLY PARAMETER(*):
    Place an * in the arguments list just before the first keyword-only parameter.

def fun4(a):            #No restrictions, takes arguments using pos or keyword
    print('fun4',a)
fun4(1)                 #fun4 1     //Argument passed using position
fun4(a=2)               #fun4 2     //Argument passed using keyword

#def fun5(a, /):
#    print('fun5',a)
#fun5(1)                 #fun5 1
#fun5(a=2)              #fun5 got an unexpected keyword argument 'arg'

def kwd_only_arg(*, arg):
    print(arg)
#kwd_only_arg(3)         #kwd_only_arg() takes 0 positional arguments but 1 was given
kwd_only_arg(arg=3)     #3
```

