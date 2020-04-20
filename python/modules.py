"""     modules.py

MODULE? file containing python functions, class, variables etc. 
    # vim mult_sum.py           #Module named mult_sum is defined.
        def mult1(a,b):
            print('Mult:',a*b)
        def sum1(a,b):
            print('Sum:',a+b)    

1. IMPORTING A MODULE? means including the module to use its functionality.
METHODS OF IMPORTING?
  1A. Importing complete module
  2B. Importing 1 function from module

2. MODULE NAME? 
   module’s name (as a string) is available as the value of the global variable __name__.  

3. MODULES AS SCRIPTS?  Means passing command line arguments to module
   This code needed to be added at end of module:
   if __name__ == "__main__":
    import sys
    fib(int(sys.argv[1]))

4. DIR(): Gives which names are defined by module.

5. MODULE EXAMPLES:
    A. SYS: provides access to some variables maintained by interpreter and to functions that interact with the interpreter.
    B. BUILTIN: provides access to all ‘built-in’ identifiers of Python
"""


############1. IMPORTING THE MODULE################
##1A. IMPORTING COMPLETE MODULE
import mult_sum as a
#OR from mult_sum import *
a.mult1(1,2)                        #2
a.sum1(4,5)                         #9


##1B. IMPORTING SINGLE FUNCTION
from mult_sum import mult1
mult1(2,3)                          #6
###################################################


##2. MODULE NAME
print(a.__name__)                   #mult_sum


##3. MODULE AS SCRIPT
"""
    # vim mult_sum.py
        def mult1(a,b):
            print('Mult:',a*b)
        def sum1(a,b):
            print('Sum:',a+b)    
        if __name__ == "__main__":
            import sys
            mult1(int(sys.argv[1]),int(sys.argv[2]))

    # python3.6 mult_sum.py 2 3         #6
"""


##4. dir() function
print(dir(a))       #['__builtins__', '__cached__', '__doc__', '__file__', '__loader__', '__name__', 
'__package__', '__spec__', 'mult1', 'sum1']


##5. MODULE EXAMPLES
#5A. sys module
import sys
print(sys.path)     #['/root/amit-code/python', '/usr/lib64/python36.zip', '/usr/lib64/python3.6', 
'/usr/lib64/python3.6/lib-dynload', '/root/.local/lib/python3.6/site-packages', '/usr/local/lib64/python3.6/site-packages', 
'/usr/local/lib/python3.6/site-packages', '/usr/local/lib/python3.6/site-packages/memory_profiler-0.57.0-py3.6.egg', 
'/usr/lib64/python3.6/site-packages', '/usr/lib/python3.6/site-packages']

#5B. builtins module
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
