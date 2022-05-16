**Classes**
- [Constructor calling hierarchy](#cch)
- Functions
  - [issubclass()](#isc)
  - [isinstance()](#in)
- [Copy of Object](#co)

## Classes
```py
class test:
  def B():
    return 1;
  def A():
    return self.B();    //A() calling B()
```

<a name=cch></a>
### Constructor calling hierarchy
```py
class Base1(object):
	def __init__(self):
		print("Base1")

class Base2(object):
	def __init__(self):
		print("Base2")

# Derv class from Base1, Base2
class Derv(Base2,Base1):
	def __init__(self):	#Ctr Derv
		print("Derv")

obj = Derv()	#Output = Derv. Unlike C++ Ctr calling hierarchy
```

### Functions
<a name=isc></a>
#### issubclass()
This method checks if a class is a child of another class
```py
class Parent(object):
   pass   
 
class Child(Parent):
   pass   
 
print(issubclass(Child, Parent))    #True
print(issubclass(Parent, Child))    #False
```

<a name=in></a>
#### isinstance()
This checks if an object is an instance of a class.
```py
obj1 = Child()
obj2 = Parent()
print(isinstance(obj2, Child))    #False 
print(isinstance(obj2, Parent))   #True
```

<a name=co></a>
### Copy of Object
- Assignment statement(= operator) does not copy objects. Instead, it creates a binding between the existing object and the target variable name. 
- Copy is created using copy module.
- **Shallow Copy:** 
  - Copied object created has an exact copy of the values in the original object.
  - If either of the values is a reference to other objects, just the reference addresses for the same are copied.
- **Deep Copy:** Copies all values recursively from source to target object, i.e. it even duplicates the objects referenced by the source object.
```py
from copy import copy, deepcopy
list_1 = [1, 2, [3, 5], 4]

list_2 = copy(list_1)                  ## shallow copy
list_2[3] = 7
list_2[2].append(6)
list_2    # output => [1, 2, [3, 5, 6], 7]
list_1    # output => [1, 2, [3, 5, 6], 4]

list_3 = deepcopy(list_1)             ## deep copy
list_3[3] = 8
list_3[2].append(7)
list_3    # output => [1, 2, [3, 5, 6, 7], 8]
list_1    # output => [1, 2, [3, 5, 6], 4]
```
