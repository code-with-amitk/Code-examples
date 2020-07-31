
# PREDICATE CLASS
- A class that implements functor `bool object()` that returns boolean value(true or false).
- Predicate is used with algorithms that takes container, predicate function(as input) and returns boolen result.


## TYPES OF PREDICATES
| Type | Unary | Binary |
| --- | --- | --- |
| What | Unary functor returning bool | Binary functor returning bool |

## Predicate Examples
| Predicate | What|
| --- | --- |
| all_of(), any_of(), none_of | <ul><li>Take an array of elements, predicate as an input</li></ul> <ul><li>Call predicate on individual input elements</li></ul> <ul><li>return true if for all/any/none elements, predicate returns true</li></ul> |
| find_if() | <ul><li>Take sequence of elements, predicate as input</li></ul <ul><li>Return first element in the sequence, for which predicate returns value equal to true</li></ul |
