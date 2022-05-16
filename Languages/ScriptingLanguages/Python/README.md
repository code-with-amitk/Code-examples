- [What](#w)
- [Concepts: Picking, Unpickling](#Concepts)
- Feature of Python
  - [Dynamically Typed](#st)
- [Memory Management](#mm)
- [PEP](#pep)
- [Scope Resolution](#sr)
- [Class,Object: isinstance(),issubclass(), copy objects](Objects-and-Classes)
- [Types in Python: Arrays, Dictionary, List, OrderedDict, Sets, Tuples](containers)
- [Control Flow: if, for, range(), match statement](Control_Flow)
- [Functions: decorator, filter(), format(), input(), lambda, map(), range(), xrange(), reduce(), split() & rsplit(), strip(), type(), `__ITER__(), __CONTAINS__, __REPR__(), __STR__(), __doc__, __init__()`](#Functions)
- [Input,Output: Taking input from keyboard](Input_Output)
- [Keywords: self, yeild](Keywords)

<a name=w></a>
### Python
Python is interpreted(executes statement line by line), general Purpose language. Other Interpreted languages: Ruby, R, PHP, JS.

### Features
#### 1. Python is dynamic typed language. 
- Dynamic typed means type checking is done at run time.
- **What is Typed?** This means type checking.

|Typed Language|Example|
|---|---|
|1. Strongly|"1" + 2  results in type error|
|2. Weakly|"1" + 2  = "12". Eg: Javascript|

<a name=mm></a>
### Memory Management
- Memory management in Python is done by Python Memory Manager. The memory allocated in private heap space.
- All objects are stored in private heap & inaccessible to programmer.
- Python has an in-built garbage collection to recycle the unused memory for the private heap space.

<a name=pep></a>
### PEP 8 (Python Enhancement Proposal)
- PEP is an official document providing information about new feature coming in python.

<a name=sr></a>
### Scope Resolution
- Python modules namely 'math' and 'cmath' have a lot of functions that are common to both of them - log10(), acos(), exp() etc. To resolve this ambiguity, it is necessary to prefix them with their respective module, like math.exp() and cmath.exp().
