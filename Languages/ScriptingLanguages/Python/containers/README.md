
- [Built-in: int,float,complex,bool](#b)
- [Sequence Type: list, tuple, Range, str](#st)
- [Mapping Type: Dictionary](#mt)
- [Set Type: Dictionary](#st)

## Types in Python
<a name=b></a>
### Built in Types
- Python doesn't require data types to be defined explicitly during variable declarations
- Python provides type() and isinstance() functions to check the type of these variables.
- **Categories:**
  - _1. None:_ same as NULL
  - _2. Numeric Types:_ int, float, complex(stores complex numbers a+ib), bool, decimals.

<a name=st></a>
### Sequence Container
For storage of collection of objects. Can store different data types.

|Type|Represented by|Difference|Comprehension|
|---|---|---|---|
|1. List(not linked list)| `[]` | Mutable=Changable. This is same as vector in c++ |y|
|2. Tuple| () | Immutable |n|
|3. Range Object| immutable | Sequence of numbers generated during execution |
|4. str | Immutable | Sequence to store textual data. |

<a name=mt></a>
### Mapping Container `<key, value=object>`
- These are Mutable. Key cannot be mutable. Hence these cannot be used as key(set, list)
- Example: Dictionary
- Dictionary Comprehension: y

<a name=st></a>
### Set Container
|Type|Represented by|Mut/Immutable|Description|Comprehension|
|---|---|---|---|---|
|1. set| {} | Mutable, supports add(),remove()|No Duplicates|y|
|2. frozen_set| | Immutable | |
