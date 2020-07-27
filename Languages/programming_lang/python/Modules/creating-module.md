## MODULE?
- **What** file containing python functions, class, variables etc.
- **Module name** Module’s name (as a string) is available as the value of the global variable __name__. 
- **Module examples**
  - **SYS:** provides access to some variables maintained by interpreter and to functions that interact with the interpreter.
  - **BUILTIN:** provides access to all ‘built-in’ identifiers of Python

## DEFINING A MODULE
```
# vim mult_sum.py           #Module named mult_sum is defined.
def mult1(a,b):
  print('Mult:',a*b)
def sum1(a,b):
  print('Sum:',a+b)    

```

## IMPORTING A MODULE? 
- **What** means including the module to use its functionality.
- There are 2 methods of importing a module.

#### 1A. Importing complete module
```
import mult_sum as a
#OR from mult_sum import *
a.mult1(1,2)                        #2
a.sum1(4,5)                         #9
print(a.__name__)                   #Print the module name: mult_sum
```

#### 1B. Importing 1 function from module
```
from mult_sum import mult1
mult1(2,3)                          #6
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
