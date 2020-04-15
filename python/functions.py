"""     functions.py
"""

"""
FUNCTIONS AS OBJECTS:
    Means functions can be used as variable
"""
def fun():
    return "Hello"
test = fun
print(test())        #Hello


"""
FUNCTIONS AS ARGUMENTS: 
    Function can be passed as arguments to other functions same as variables.
"""
def f(a,b):
    return a+b
def f1(var):
    print("hello",var)
f1(f(1,2))              #Passing function f() as argument of f1() //hello 3


"""
INNER FUNCTIONS:
    function inside function
    Below Output:   parent fun2 fun1
    Note that the order in which the inner functions are defined does not matter. Like with any other functions, the printing only happens when the inner functions are executed. Further fun1,fun2 are locally scoped to parent(): they only exist inside the parent() function as local variables.
"""
def parent():
    print("Parent")
    def fun1():
        print("fun1")
    def fun2():
        print("fun2")
    fun2()
    fun1()
parent()




"""
DEFAULT VALUE ARGUMENTS: Function having default arguments which takes values when function call does not contain argument.
"""
def fun1(a, b=4, c='Please try again!'):
    if a == 1:
        print('Test1')
    elif a==10 and b==2:
        print('Test2')
    elif a==11 and b==12 and c=='Hello':
        print('Test3')
fun1(1)                 #Test1
fun1(10,2)              #Test2
fun1(11,12,'Hello')     #Test3


"""
MUTABLE OBJECTS(list,dictionary etc)
 - Are shared between subsequent calls
"""
def fun2(a, L=[]):
    L.append(a)
    return L
print(fun2(1))     #[1]
print(fun2(2))     #[1,2]
print(fun2(3))     #[1,2,3]


"""
KEYWORD ARGUMENTS(kwarg): arguments having names
 - kwarg MUST follow positional arguments
"""
def fun3(a, state='init', action='start'):
    print(a,state,action)
fun3(1000)                  #1000 init start
fun3(a=5,action='new')      #5 init new
#fun3()                     #missing 1 required positional argument: 'a'
#fun3(b=10)                 #got an unexpected keyword argument 'b'
fun3(1,1)


"""
SPECIAL PARAMETERS
def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
      -----------    ----------     ----------
        |             |                  |
        |        Positional or keyword   |
        |                                - Keyword only
         -- Positional only
- By default, arguments may be passed to function either by position or by keyword.
- If / and * are not present in function definition, arguments may be passed to a function by position or by keyword.
- POSITION ONLY PARAMETER(/):
    Parameters cannot be passed by keyword
    Positional-only parameters are placed before / (forward-slash)
    Parameters after / may be positional-or-keyword or keyword-only

- KEYWORD ONLY PARAMETER(*):
    Place an * in the arguments list just before the first keyword-only parameter.
"""
def fun4(a):            #No restrictions, takes arguments using pos or keyword
    print('fun4',a)
fun4(1)                 #fun4 1     //Argument passed using position
fun4(a=2)               #fun4 2     //Argument passed using keyword

def fun5(a, /):
    print('fun5',a)
fun5(1)                 #fun5 1
#fun5(a=2)              #fun5 got an unexpected keyword argument 'arg'

def kwd_only_arg(*, arg):
    print(arg)
kwd_only_arg(3)         #kwd_only_arg() takes 0 positional arguments but 1 was given
kwd_only_arg(arg=3)     #3


"""
DUNDER/MAGIC METHODS/DOUBLE UNDERSCORE:
    Methods surrounded by __(double underscore).

EXAMPLES:
   __init__(Constructor)
   __del__(Destructor)
   __dict__(Class's namespace)
   __doc__(Class documentation)
   __name__(Class name) (print Employee.__name__  ==> Employee), Module name: Within a module, the module’s name (as a string) is available as the value of the global variable __name__.
   __module__: Module name in which class is defined
   __bases__: Contains base classes
   __ITER__(): returns an iterator for the given object. iter() calls __iter__() internally
   __CONTAINS__(): Called using in "containment check" operator
   __GETITEM__ : a[i] Python calls a.__getitem__(i)
"""
###__ITER__()
a = [4, 7, 0, 3]
it = iter(a)    #get iterator.
print(next(it))     #4
print(next(it))     #7

###__CONTAINS__
class A:
    v = 'test'
    def __contains__(self, m):
        if self.d:
            return True
obj = A()
if 'd' in obj:          #in operator calls __contains__
    print('True')

###__GETITEM__
object['sslVersionMin'] == ['TLS1.0']
True


"""
VARIABLE NO OF ARGUMENTS
"""
def fun(*arg):
    for var in arg:
        print var
        return
fun ( 10, 20, 30 )
fun ( 1, 2 )
fun ( 'te', 90 )


"""
STRING.STRIP([CHARS])
    Removes characters from both left and right based on the argument (a string specifying the set 
    of characters to be removed).
"""
def test(gpLink):
    ret = []
    if gpLink.strip() == "":
        print("gpLink is empty")
        return 4;
    return;
print "value=",test(" ")        #gpLink is empty=4


"""
TYPE()
     returns type of Object being passed
"""
print(type(3))                                #<class 'int'>
print(type(['foo', 'bar', 'baz']))       #<class 'list'>
print(type(1, 2, 3, 4, 5))                #<class 'tuple'>
class X:
    pass
print(type(X))                  


"""
FORMAT()
    Helps in positional and value formatting of string.    
    string.format()
"""
print ('The {} who says {}'.format('person','Hello')) #The person who says Hello.
print ('The {0} who says {1}'.format('person, 'Hello'))   #The person who says Hello
print ('The {1} who says {0}.'.format("person",'Hello')) #The Hello who says Person


"""
RANGE()
    produces continuous sequence
"""
print(list(range(5,8)))         #5,6,7
print(list(range(5,10,2)))      #5,7,9      #3rd argument tells interval of sequence
                                                                                                                         
