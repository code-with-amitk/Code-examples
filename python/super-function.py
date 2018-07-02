class base (obj):
	def __init__(self):
	print ("Base")

class derv (base):
	def __init__(self):
	base.__init__(self)
