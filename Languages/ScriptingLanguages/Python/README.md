- [Class,Object: isinstance(),issubclass(), copy objects](Objects-and-Classes)
- [Concepts: GIL, Memory Management, PEP 8, Picking/Unpickling, Scope Resolution](#Concepts)
- [Containers: HashMap/Dictionary, dequeu=doubly linked list](containers)
- [Control Flow: if, for, range(), match statement](Control_Flow)
- Feature of Python
  - [Dynamically Typed](#st)
- [Functions: decorator, generator, filter(), format(), input(), join(), lambda, map(), range(), xrange(), reduce(), split() & rsplit(), strip(), type(), `__ITER__(), __CONTAINS__, __REPR__(), __STR__(), __doc__, __init__()`, call by value, call by reference](#Functions)
- [Keywords: self, yeild](Keywords)
- [Threading](/Threads_Processes_IPC/Threads/Code#p1)
- [Types: Arrays, Dictionary, vector=List, OrderedDict, Sets, Tuples](containers)
- [Input,Output: Taking input from keyboard](Input_Output)

## Python
Python is interpreted(executes statement line by line), general Purpose language. Other Interpreted languages: Ruby, R, PHP, JS.

## [Functions](https://code-with-amitk.github.io/Languages/Scripting/Python/)
- Call by Value, Call by Reference
- Function passed as Object, argument
- Variable number of arguments to Function
- Types of Functions
** kwargs
** decorator
** enumerate()
** lambda
** generator & yeild
  
### Features
#### 1. Python is dynamic typed language.
- Dynamic typed means type checking is done at run time.
- **What is Typed?** This means type checking.

|Typed Language|Example|
|---|---|
|1. Strongly|"1" + 2  results in type error|
|2. Weakly|"1" + 2  = "12". Eg: Javascript|

#### 2. virtualenv / virtual enviornment
* Virtual environment is like vm for python program each with their own independent set of Python packages installed in their site directories.
```py
C:\Users\amitk\source\repos\Python>pip3 install virtualenv
C:\Users\amitk\source\repos\Python>python3 -m venv venv_ml
C:\Users\amitk\source\repos\Python>venv_ml\Scripts\activate

(venv_ml) C:\Users\amitk\source\repos\Python>
(venv_ml) C:\Users\amitk\source\repos\Python>venv_ml\Scripts\deactivate.bat
C:\Users\amitk\source\repos\Python>
```
