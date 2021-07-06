- [1. Builtin Methods](#buitin)
  - [1.1 Dunder, Magic](#dunder)
  - [1.2 `__ITER__()`](#iter)
  - [1.3 `__CONTAINS__`](#contains)
  - [1.4 `__REPR__()`](#repr)
  - [1.5 `__STR__()`](#str)
  - [1.6 `__doc__`](#doc)

<a name=builtin></a>
## 1. Builtin Methods in Python
<a name=dunder></a>
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
<a name=iter></a>
### 1.2 `__ITER__()`
- returns an iterator for the given object. iter() calls `__iter__()` internally
```
a = [4, 7, 0, 3]
it = iter(a)    #get iterator.
print(next(it))     #4
print(next(it))     #7
```
<a name=contains></a>
### 1.3 `__CONTAINS__`
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
### 1.4 `__REPR__()`
- Returns a printable representation of the given object. takes 1 parameter ie object, whose printable representation has to be returned
```
class D:
    pass
p = D()
print("repr",p)     #repr <__main__.D object at 0x7f283adce278>
```
<a name=str></a>
### 1.5 `__STR__()`
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
### 1.6 `__doc__`
- A docstring is a string literal that occurs as the first statement in a module/function/class or method definition.
- Docstring becomes the __doc__ special attribute of that object. All modules should normally have docstrings, and all functions and classes exported by a module should also have docstrings. Public methods (including the __init__ constructor) should also have docstrings.
```
print(abs.__doc__)      #Return the absolute value of the argument.
```
