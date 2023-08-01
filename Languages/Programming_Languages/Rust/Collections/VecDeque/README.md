**VecDeque**
- [c++(vector) vs rust(VecDeque)](#vs)
- [Internal Implementation](#in)
- [Functions](/Languages/Programming_Languages/c++/Standard_Template_Library/container_library/sequence_containers/Deque)

### Vector(C++) vs VecDeque
<a name=vs></a>
||vector(c++)|VecDeque|
|---|---|---|
|What|Dynamic Array, store elements contigiously in mem|same as vec, but elements can be added/removed at both ends|
|Search|O(1) Using index|O(n): At middle|
|Insert(Front, Middle)|O(n): At random position(Requires shifting of elements)|O(1)|
|Memory overhead|less|More(due to internal structure|

<a name=in></a>
#### Internal Implementation
- Implemented using RingBuffer
```rs
pub struct VecDeque<T> {
    tail: usize,
    head: usize,
    buf: RawVec<T>,
}
```
