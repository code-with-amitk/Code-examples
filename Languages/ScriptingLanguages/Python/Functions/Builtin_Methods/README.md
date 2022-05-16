Builtin Methods
- _1._ Dunder, Magic
  - [a. `__contains__`](#con)
  - [b. `__doc__`](#doc)
  - [c. `__init__`](#in)
  - [d. `__iter__()`](#iter)
  - [e. `__repr__()`](#repr)
  - [f. `__str__()`](#str)


## 1. Builtin Methods in Python
### 1.1 Dunder, Magic / Double underscore
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

<a name=con></a>
### a. `__contains__`
Called using in "containment check" operator
```py
class A:
    d = 'test'
    def __contains__(self, m):
        if self.d:
            return True
obj = A()
if 'd' in obj:          #in operator calls __contains__
    print('True')
```   

<a name=doc></a>
#### b. `__doc__`
- A docstring is a string literal that occurs as the first statement in a module/function/class or method definition.
- Docstring becomes the __doc__ special attribute of that object. All modules should normally have docstrings, and all functions and classes exported by a module should also have docstrings. Public methods (including the __init__ constructor) should also have docstrings.
```py
print(abs.__doc__)      #Return the absolute value of the argument.
```

<a name=in></a>
#### c. init
- This is a contructor method in Python and is automatically called to allocate memory when a new object/instance is created. 
- All classes have a `__init__` method associated with them.
```py
class Student:
   def __init__(self, fname, lname, age, section):
       self.firstname = fname
       self.lastname = lname
       self.age = age
       self.section = section

stu1 = Student("Sara", "Ansh", 22, "A2")    # creating a new object
```

<a name=iter></a>
#### d. `__iter__()`
Returns an iterator for the given object. iter() calls `__iter__()` internally
```py
a = [4, 7, 0, 3]
it = iter(a)    #get iterator.
print(next(it))     #4
print(next(it))     #7
```
<a name=repr></a>
#### e. `__repr__()`
Returns a printable representation of the given object. takes 1 parameter ie object, whose printable representation has to be returned
```py
class D:
    pass
p = D()
print("repr",p)     #repr <__main__.D object at 0x7f283adce278>
```
<a name=str></a>
#### e. `__str__()`
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
