# What is super()?
# Definition
	# Official-definition: super() method returns a proxy object that delegates method calls to a parent or sibling class of type
	# my-definition: Using super() we can call methods from Base class. This base class has to be 1st in Inheritance hierarchy. 
	# Note: With super() you can call only 1st Base class's function not all.
# Calling format
	# super(derv_class, self).function_name	//Python2
	# super().function_name			//Python3

class Base1(object):
	def __init__(self):
		print("Base1")
	def disp(self):
		print("Base1 disp")

class Base2(object):
	def __init__(self):
		print("Base2")
	def disp(self):
		print("Base1 disp")


# Derv class from Base1, Base2
class Derv(Base1,Base2):
	def __init__(self):	#Ctr Derv
		super(Derv,self).__init__()	#Call Base1.__init__()
#		Base1.__init__(self)		#You can call
		print("Derv")
		super(Derv,self).disp()


obj = Derv()	
#Output:
# Base1
# Derv
# Base1 disp 
