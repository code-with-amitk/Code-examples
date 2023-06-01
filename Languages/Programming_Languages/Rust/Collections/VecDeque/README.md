**VecDeque**

### vec(vector in c++) vs VecDeque
||vec|VecDeque|
|---|---|---|
|What|Dynamic Array, store elements contigiously in mem|same as vec, but elements can be added/removed at both ends|
|Search|O(1) Using index|O(n): At middle|
|Insert(Front, Middle)|O(n): At random position(Requires shifting of elements)|O(1)|
|Memory overhead|less|More(due to internal structure|

#### How vecDeque is implemented
- Implemented using RingBuffer
```rs
pub struct VecDeque<T> {
    tail: usize,
    head: usize,
    buf: RawVec<T>,
}
```
