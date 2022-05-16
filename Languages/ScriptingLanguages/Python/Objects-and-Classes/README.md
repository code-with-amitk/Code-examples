**Classes**
- [Constructor calling hierarchy](#cch)
- [issubclass()](#isc)
- [isinstance()](#in)

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

<a name=isc></a>
### issubclass()
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
### isinstance()
This checks if an object is an instance of a class.
```py
obj1 = Child()
obj2 = Parent()
print(isinstance(obj2, Child))    #False 
print(isinstance(obj2, Parent))   #True
```
