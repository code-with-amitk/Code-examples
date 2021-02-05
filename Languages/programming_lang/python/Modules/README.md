## Module?
- **What** File containing python functions, class, variables etc. Examples
  - *sys* Access system variables, functions maintained by interpreter.
  - *builtin* Built-in identifiers of Python

### Using modules
- **Step-1 Define a module**
- **Step-2 Import the module:** means including the module to use its functionality. There are 2 methods of importing a module.
  - {Method-1} Import complete Module
  - {Method-2} Import 1 function from Module
```python
###########   1. Defined module(Multiply_Sum)  ##########
# vim Multiply_Sum.py           
def Multiply(a,b):
  print('Multiplies:', a*b)
def Sum(a,b):
  print('Sum:', a+b)  

########## 2. Import module  ###########
#### 2A. Import complete module ####
# vim test.py
import Multiply_Sum as MS
#OR from Multiply_Sum import *
MS.Multiply(1,2)                    #2
MS.SUM(4,5)                         #9
print(MS.__name__)                   #Print the module name: Multiply_Sum


## 2B. Import 1 function from module
# vim test2.py
from Multiply_Sum import Multiply
Multiply(2,3)                         #6
```

## MODULES AS SCRIPTS?
- Means passing command line arguments to module. This code needed to be added at end of module:
```
    # vim mult_sum.py
        def mult1(a,b):
            print('Mult:',a*b)
        def sum1(a,b):
            print('Sum:',a+b)    
        if __name__ == "__main__":
            import sys
            mult1(int(sys.argv[1]),int(sys.argv[2]))

    # python3.6 mult_sum.py 2 3         #6
```


## dir() function
```
print(dir(a))       #['__builtins__', '__cached__', '__doc__', '__file__', '__loader__', '__name__', 
'__package__', '__spec__', 'mult1', 'sum1']
```


## MODULE EXAMPLES
### A. sys module
```
import sys
print(sys.path)     #['/root/amit-code/python', '/usr/lib64/python36.zip', '/usr/lib64/python3.6', 
'/usr/lib64/python3.6/lib-dynload', '/root/.local/lib/python3.6/site-packages', '/usr/local/lib64/python3.6/site-packages', 
'/usr/local/lib/python3.6/site-packages', '/usr/local/lib/python3.6/site-packages/memory_profiler-0.57.0-py3.6.egg', 
'/usr/lib64/python3.6/site-packages', '/usr/lib/python3.6/site-packages']
```

### B. builtins module
```
import builtins
print(dir(builtins)) #['ArithmeticError', 'AssertionError', 'AttributeError', 'BaseException', 'BlockingIOError', 
'BrokenPipeError', 'BufferError', 'BytesWarning', 'ChildProcessError', 'ConnectionAbortedError', 'ConnectionError', 
'ConnectionRefusedError', 'ConnectionResetError', 'DeprecationWarning', 'EOFError', 'Ellipsis', 'EnvironmentError', 
'Exception', 'False', 'FileExistsError', 'FileNotFoundError', 'FloatingPointError', 'FutureWarning', 'GeneratorExit', 
'IOError', 'ImportError', 'ImportWarning', 'IndentationError', 'IndexError', 'InterruptedError', 'IsADirectoryError', 
'KeyError', 'KeyboardInterrupt', 'LookupError', 'MemoryError', 'ModuleNotFoundError', 'NameError', 'None', 
'NotADirectoryError', 'NotImplemented', 'NotImplementedError', 'OSError', 'OverflowError', 'PendingDeprecationWarning', '
PermissionError', 'ProcessLookupError', 'RecursionError', 'ReferenceError', 'ResourceWarning', 'RuntimeError', 
'RuntimeWarning', 'StopAsyncIteration', 'StopIteration', 'SyntaxError', 'SyntaxWarning', 'SystemError', 'SystemExit', 
'TabError', 'TimeoutError', 'True', 'TypeError', 'UnboundLocalError', 'UnicodeDecodeError', 'UnicodeEncodeError', 
'UnicodeError', 'UnicodeTranslateError', 'UnicodeWarning', 'UserWarning', 'ValueError', 'Warning', 'ZeroDivisionError', 
'__build_class__', '__debug__', '__doc__', '__import__', '__loader__', '__name__', '__package__', '__spec__', 'abs', 
'all', 'any', 'ascii', 'bin', 'bool', 'bytearray', 'bytes', 'callable', 'chr', 'classmethod', 'compile', 'complex', 
'copyright', 'credits', 'delattr', 'dict', 'dir', 'divmod', 'enumerate', 'eval', 'exec', 'exit', 'filter', 'float', 
'format', 'frozenset', 'getattr', 'globals', 'hasattr', 'hash', 'help', 'hex', 'id', 'input', 'int', 'isinstance', 
'issubclass', 'iter', 'len', 'license', 'list', 'locals', 'map', 'max', 'memoryview', 'min', 'next', 'object', 'oct', 
'open', 'ord', 'pow', 'print', 'property', 'quit', 'range', 'repr', 'reversed', 'round', 'set', 'setattr', 'slice', 
'sorted', 'staticmethod', 'str', 'sum', 'super', 'tuple', 'type', 'vars', 'zip']
```
