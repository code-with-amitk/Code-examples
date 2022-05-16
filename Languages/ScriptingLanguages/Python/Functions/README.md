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
- [Decorator](#dec)
- [Lambda](#lam)
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

<a name=dec></a>
### Decorator
- Functions that add functionality to an existing function, without changing the structure of the existing function itself.
- They are represented the `@decorator_name` in Python and are called in a **bottom-up fashion**. 
- Example-1
```py
# decorator function to convert to lowercase
def lowercase_decorator(function):
   def wrapper():
       func = function()
       string_lowercase = func.lower()
       return string_lowercase
   return wrapper
   
# decorator function to split words
def splitter_decorator(function):
   def wrapper():
       func = function()
       string_split = func.split()
       return string_split
   return wrapper
   
@splitter_decorator # this is executed next
@lowercase_decorator # this is executed first
def hello():
   return 'Hello World'
   
# Driver Code
hello()                   # output => [ hello , world ]
```

- _Example-2:_
  - Decorators can accept arguments for functions can further modify those arguments before passing it to the function itself.
```py
# decorator function to capitalize names
def names_decorator(function):
   def wrapper(arg1, arg2):
       arg1 = arg1.capitalize()
       arg2 = arg2.capitalize()
       string_hello = function(arg1, arg2)
       return string_hello
   return wrapper
   
@names_decorator
def say_hello(name1, name2):
   return 'Hello ' + name1 + '! Hello ' + name2 + '!'
say_hello('sara', 'ansh')   # output => 'Hello Sara! Hello Ansh!'
```

<a name=lam></a>
## Lambda / Anonymous function
- Can accept any number of arguments, but can only have a single expression.
- **Use-case:** Require an anonymous function for a short time period. 
### Ways to use Lambda
#### 1. Assigning lambda functions to a variable
```py
mul = lambda a, b : a * b
print(mul(2, 5))    # output => 10
```
#### 2. Wrapping lambda functions inside another function
```py
def myWrapper(n):
 return lambda a : a * n
 
mulFive = myWrapper(5)
print(mulFive(2))    # output => 10
```
