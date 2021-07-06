- [1. Functions](#fun)
  - [1.1 Function used as Object](#obj)
  - [1.2 Function passed as arguments to other function](#arg)
  - [1.3 Functions as Mutable Objects](#mut)
  - [1.4 Variable no of Arguments](#var)
- [2. Types of Functions](#types)
  - [2.1 Inner, function inside function](#func)
- [3. Function Arguments](#funarg)
  - [3.1 Arguments taking default value](#default)
  - [3.2 kwarg, keyword Arguments](#kwarg)
  - [3.3 Special Parameters](#special)
- [4. Built in methods](Builtin_Methods)
  - Dunder/Magic, `__ITER__()`, `__CONTAINS__`, `__REPR__()`, `__STR__()`, `__doc__`
- [5. Mostly used Functions](Mostly_Used_Functions)
  - split() & rsplit(), string.strip(`[char]`), type(), format(), range(), input(str)

<a name=fun></a>
## 1. Functions
<a name=obj></a>
### 1.1 Functions used as Object
- Means functions can be used as variable
```py
def fun():
    return "Hello"
test = fun
print(test())        #Hello
```
<a name=arg></a>
### 1.1 Function passed as argument to other function
```py
def f(a,b):
    return a+b
def f1(var):
    print("hello",var)
f1(f(1,2))              #Passing function f() as argument of f1() //hello 3
```
<a name=mut></a>
### 1.3 Function as Mutable Objects
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
### 1.4 Variable no of arguments
```py
def fun(*arg):
    for var in arg:
        print(var)
        return
fun ( 10, 20, 30 )
fun ( 1, 2 )
fun ( 'te', 90 )
```

<a name=types></a>
## 2. Types of Functions
<a name=inner></a>
### 2.1 Inner, function inside function
- Note that the order in which the inner functions are defined does not matter. 
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

<a name=funarg></a>
## 3. Function Arguments
<a name=default></a>
### 3.1 Arguments taking default value
```python
def fun1(a, c='Again'):            #c is default arguments
    if a == 1:
        print('Test1')
    elif a==11 and c=='Hello':
        print('Test3')
fun1(1)                 #Test1
```
<a name=kwarg></a>
### 3.2 kwarg, Keyword Arguments
- kwarg MUST follow positional arguments
<a name=special></a>
### 3.3 Special Parameters
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

