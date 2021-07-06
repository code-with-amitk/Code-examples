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
- [4. Builtin Methods](#buitin)
  - [4.1 Dunder, Magic](#dunder)
  - [4.2 `__ITER__()`](#iter)
  - [4.3 `__CONTAINS__`](#contains)
  - [4.4 `__REPR__()`](#repr)
  - [4.5 `__STR__()`](#str)
  - [4.6 `__doc__`](#doc)
- [5. Mostly used Functions](#muf)
  - [5.1 split() & rsplit()](#split_r)
    - [5.1.1 split() example](#split)
    - [5.1.2 rsplit() example](#rsplit)
  - [5.2 string.strip(`[char]`)](#strip)
  - [5.3 type()](#type)
  - [5.4 format()](#format)
  - [5.5 range()](#range)
  - [5.6 input(str)](#input)

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

<a name=builtin></a>
## 4. Builtin Methods in Python
<a name=dunder></a>
### 4.1 Dunder, Magic / Double underscore
- Methods surrounded by (double underscore).
```python
EXAMPLES:
   __bases__: Contains base classes
   __del__(Destructor)
   __dict__(Class's namespace)
   __doc__(Class documentation)   
   __init__(Constructor)
   __name__(Class name) (print Employee.__name__  ==> Employee), Module name: Within a module, the module’s name 
   (as a string) is available as the value of the global variable __name__.
   __module__: Module name in which class is defined
```
<a name=iter></a>
### 4.2 `__ITER__()`
- returns an iterator for the given object. iter() calls `__iter__()` internally
```
a = [4, 7, 0, 3]
it = iter(a)    #get iterator.
print(next(it))     #4
print(next(it))     #7
```
<a name=contains></a>
### 4.3 `__CONTAINS__`
- Called using in "containment check" operator
```
class A:
    d = 'test'
    def __contains__(self, m):
        if self.d:
            return True
obj = A()
if 'd' in obj:          #in operator calls __contains__
    print('True')
```    
<a name=repr></a>
### 4.4 `__REPR__()`
- Returns a printable representation of the given object. takes 1 parameter ie object, whose printable representation has to be returned
```
class D:
    pass
p = D()
print("repr",p)     #repr <__main__.D object at 0x7f283adce278>
```
<a name=str></a>
### 4.5 `__STR__()`
- Initially we had the Person class with nothing implemented. Created object of class and printed out the same. 
- It shows class reference.Defined __str__ method, See object reference it displayed the string which was returned from the __str__ method.
- __STR__:if we override/define  __str__() inside the class we can print the text when object is tried to be printed using print()
```
class B:
    pass
p = B()
print(p)            #<__main__.B object at 0x7fbe0b090198>
class C:
    def __str__(self):
        return 'Class C'
p = C()
print(p)            #Class C
```
<a name=doc></a>
### 4.6 `__doc__`
- A docstring is a string literal that occurs as the first statement in a module/function/class or method definition.
- Docstring becomes the __doc__ special attribute of that object. All modules should normally have docstrings, and all functions and classes exported by a module should also have docstrings. Public methods (including the __init__ constructor) should also have docstrings.
```
print(abs.__doc__)      #Return the absolute value of the argument.
```

<a name=muf></a>
## 5. Mostly used Functions
<a name=split_r></a>
### 5.1 Split() & rsplit
- **split:** splits into tokens from start to end
- **rsplit()** plits into tokens from end to start
```py
list[] = str.split(seperator = None, maxsplit = -1)
list[] = str.rsplit(seperator = None, maxsplit = -1)

- seperator: if separator is not provide WHITESPACE is taken as separator
- maxsplit:
    - If maxsplit is provided, at most maxsplit splits are done
    - If maxsplit is not provided or -1, there is no limit on the number of splits 
Return: A list of strings.
```
<a name=split></a>
#### 5.1.1 split example
```
word = 'Amit, will, achieve'
li = word.split(', ')
print(li)                    #['Amit', 'will', 'achieve']   //1

l2 = word.split(', ',1)      #['Amit', 'will, achieve']     //2
print(l2)
```
<a name=rsplit></a>
#### 5.1.2 rsplit example
```
word = 'Amit, will, achieve'
li = word.rsplit(', ')
print(li)                    #['Amit', 'will', 'achieve']   //Same as 1

l2 = word.rsplit(', ',1)      #['Amit, will', 'achieve']    //Different from 2
print(l2)
```
<a name=strip></a>
### 5.2 string.strip(`[char]`)
- Removes characters from both left and right based on the argument (a string specifying the set of characters to be removed)
```py
def test(gpLink):
    ret = []
    if gpLink.strip() == "":
        print("gpLink is empty")
        return 4;
    return;
print("value=",test(" "))        #gpLink is empty=4
```
<a name=type></a>
### 5.3 type()
- returns type of Object being passed  
```py
print(type(3))                                #<class 'int'>
print(type(['foo', 'bar', 'baz']))       #<class 'list'>
#print(type(1, 2, 3))                #<class 'tuple'>
class X:
    pass
print(type(X))
```  
<a name=format></a>
### 5.4 format()
- Helps in positional and value formatting of string. string.format()
```python
print ('The {} who says {}'.format('person','Hello')) #The person who says Hello.
print ('The {0} who says {1}'.format('person', 'Hello'))   #The person who says Hello
print ('The {1} who says {0}.'.format("person",'Hello')) #The Hello who says Person
```
<a name=range></a>
### 5.5 range()
- produces continuous sequence
```python
print(list(range(5,8)))         #5,6,7
print(list(range(5,10,2)))      #5,7,9      #3rd argument tells interval of sequence
```
<a name=input></a>
### 5.6 input(str)
- The input() function allows user input until new line is pressed.
- *raw_input()* This was older function replaced by input()
- **Returns** string
```
r = float(input('Enter radius'))
print('Area=' + 3.14*r**2)                                     //** is Exponetial. ie x^y
```
