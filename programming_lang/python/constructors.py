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
