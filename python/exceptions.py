"""        exceptions.py

EXCEPTION? Errors detected during program execution.

HOW EXECUTION HAPPENS?
  TRY CLAUSE:
     - Statements in try block are executed, If no exception occurs, except block is skipped.
     - A try statement may have more than one except clause, to specify handlers for
       different exceptions,  At most one handler will be executed.
  EXCEPT CLAUSE:
     - If an exception occurs during execution of the try clause, the rest of the try block is skipped
     - if exception's type matches the exception named after the except keyword, that except clause is executed.
     UNHANDLED EXCEPTION:
         - If an exception occurs which does not match the exception named in
           the except clause, it is called unhandled exception and execution stops.
  ELSE CLAUSE(optional):
     - When this is present this must follow all except clauses.
     - Why used? if some code in except block generates error, then else will catch


RAISING EXCEPTION?
 - raise statement allows programmer to force a specified exception to occur.
 example:
   a. >> raise NameError('HiThere') #Argument in raise() is the exception to be raised  
       Traceback (most recent call last):
       File "<stdin>", line 1, in <module>
       NameError: HiThere   
   b. raise ValueError  # shorthand for 'raise ValueError()'


USER-DEFINED EXCEPTION?
- You can create your own exceptions by creating a new exception class.
- This should be derived from 'Exception' class.

try:
    ...
except:
    ...
except ZeroDivisionError as arg:    #arg is Exception argument
    ...
except (RuntimeError, TypeError, NameError):
    ...
else    #optional
    ...
finally #is executed under all circumstances
    ...

FINALLY:
 - This is executed under all circumstances
 - In real world applications, the finally clause is useful for releasing
   external resources (such as files or network connections), regardless
   of whether the use of the resource was successful.
 - The finally clause runs whether or not the try statement produces an exception
 - If a finally clause includes a return statement, the returned value will
   be the one from the finally clause’s return statement, not the value from
   the try clause’s return statement
"""

#1. ZeroDivisionError
try:
    print (1/0)
    print("Here")        #Will not be printed
except ZeroDivisionError:
    print("In exception")


#2. Multiple except statements
try:
    f = open ('a.txt')
    s = f.readline()
    i = int(s.strip())
except IOError:
    print("IOError")        #O/P=> IPERROR
except ValueError:
    print("ValueError")
except:
    print ("Generic exception")


#3. else clause
try:
    f = open('a.txt')
except OSError:
    print('cannot open')
else:
    print(arg, 'has', len(f.readlines()), 'lines')
    f.close()


#4. exception argument
def this_fails():
    x = 1/0
try:
    this_fails()
except ZeroDivisionError as err:
    print('run-time:', err)     #run-time: division by zero


#5. raise the exception
"""
try:
   raise NameError('HiThere')
except NameError:
   print('Hello!')
   raise    
"""
""" O/P:
Hello!
Traceback (most recent call last):
  File "exceptions.py", line 86, in <module>
    raise NameError('HiThere')
NameError: HiThere
"""


#6. User-defined Exceptions
class AmitCustomException(Exception):
    def __init__(self, a):
        self.a = a
    def __str__(self):
        run(repr(self.a))

try:
    raise(AmitCustomException(3*2))
except AmitCustomException as e:
    print('Amit Custom Exception',e.a)
""" O/P:
Amit Custom Exception 6
"""


#7. finally clause
#finally clause will execute as last task before try statement completes.
#The finally clause runs whether or not the try statement produces an exception
#If a finally clause includes a return statement, the returned value will be the one from the finally clause’s return statement, not the value from the try clause’s return statement
#try:
#    raise KeyboardInterrupt
#finally:
#    print('Being stronger')
"""
O/P:
Being stronger
Traceback (most recent call last):
  File "exceptions.py", line 125, in <module>
    raise KeyboardInterrupt
KeyboardInterrupt
"""

#If the try statement reaches a break, continue or return statement, the finally clause
#will execute just prior to the break, continue or return statement’s execution.
def test():
    try:
        return True
    finally:
        return False
test()              #False 
