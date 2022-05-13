**Classes**
- [Constructor calling hierarchy](#cch)

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
