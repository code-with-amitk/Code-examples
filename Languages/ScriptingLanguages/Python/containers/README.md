## Comparison
Mutable=changable

|| List(not linkedlist)=vector(c++) | Tuple |Dictionary{} / MAP(STL) |      SET{}    | DEQUE
|---|---|---|---|---|---|
|Defined inside  |  `[]`          | With or without `()` |           {}            |         {}    |       |
|What| 1-D/2-D/n-D vector, which can store int,float,char anything| Immutable lists | {key,value} pair. Unique Keys | No duplicates | Double ended queue|
|Mutable/Changable|y|n|
|Comprehension   |      y         |            n         |       y                 |       y        | |
|Hetrogeneous    |       Y        |            Y|

<a name=st></a>
### Sequence Types
For storage of collection of objects. Can store different data types.

|Type|Represented by|Difference|
|---|---|---|
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

