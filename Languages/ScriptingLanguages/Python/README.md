- [What](#w)
- Feature of Python
  - [Dynamically Typed](#st)
- [PEP](#pep)
- Types in Python
  - [Built-in: int,float,complex,bool](#b)
  - [Sequence Type: list, tuple, Range, str](#st)
  - [Mapping Type: Dictionary](#mt)
  - [Set Type: Dictionary](#st)
- [Containers: Dictionary,List, OrderedDict, Sets, Tuples](containers)
- [Control Flow: if, for, range(), match statement](Control_Flow)
- [Functions](#fun)
- [Input,Output: Taking input from keyboard](Input_Output)
- [Keywords: yeild](Keywords)

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

<a name=pep></a>
### PEP 8 (Python Enhancement Proposal)
- PEP is an official document providing information about new feature coming in python.

## Types in Python
<a name=b></a>
### Built in Types
- Python doesn't require data types to be defined explicitly during variable declarations
- Python provides type() and isinstance() functions to check the type of these variables.
- **Categories:**
  - _1. None:_ same as NULL
  - _2. Numeric Types:_ int, float, complex(stores complex numbers a+ib), bool, decimals.

<a name=st></a>
### Sequence Types
For storage of collection of objects. Can store different data types.

|Type|Represented by|Difference|
|---|---|
|1. List| `[]` | Mutable=Changable |
|2. Tuple| () | Immutable |
|3. Range Object| immutable | Sequence of numbers generated during execution |
|4. str | Immutable | Sequence to store textual data. |

<a name=mt></a>
### Mapping Types `<key, value=object>`
- These are Mutable. Key cannot be mutable. Hence these cannot be used as key(set, list)
- Example: Dictionary

<a name=st></a>
### Set Type
|Type|Represented by||
|---|---|---|
|1. set| {} | Mutable, supports add(),remove()|
|2. frozen_set| | Immutable |
