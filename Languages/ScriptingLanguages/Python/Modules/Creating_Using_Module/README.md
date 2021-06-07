## Creating & Using Modules
- _1. Define a module_
- _2. Import the module:_ means including the module to use its functionality. There are 2 methods of importing a module.
  - _2A._ Import complete Module
  - _2B._ Import 1 function from Module
```python
# vim Multiply_Sum.py                 #1. Defined module(Multiply_Sum)
def Multiply(a,b):
  print('Multiplies:', a*b)
def Sum(a,b):
  print('Sum:', a+b)  
  
########## 2. Import module  ####
# vim test.py                               # 2A. Import complete module
import Multiply_Sum as MS
#OR from Multiply_Sum import *
MS.Multiply(1,2)                    #2
MS.SUM(4,5)                         #9
print(MS.__name__)                   #Print the module name: Multiply_Sum

# vim test2.py                              # 2B. Import 1 function from module
from Multiply_Sum import Multiply
Multiply(2,3)                         #6
```
