- [Deque](#d)
- [Functions: C++, Python, Rust](#fun)

<a name=d></a>
## Deque (Double Ended Queue) / Deck
- Remember these are not Doubly LL, which are `list<>` container in C++
- **Allocation** Does not gurantee contigous allocations.
- **Accessing elements** Elements can be accessed directly through random access iterators.

<a name=fun></a>
### Functions C++, Python, Rust
|| C++ |Python | Rust |
|---|---|---|---|
| Declaration | `deque<int> dq` | self.dq = deque() | `let mut dq:VecDeque<i32> = VecDeque::new();` |
| push at end | dq.push_back(x) | self.dq.append(x) | dq.push_back(x) |
| Front, Back element | dq.front(), dq.back() | `self.dq[0],self.dq[-1]` | dq.front(),dq.back() |
| Pop front, back | dq.pop_front(), dq.pop_back() | self.dq.pop(), self.dq.popleft() | dq.pop_front(), dq.pop_back() |
| Check empty | !dq.empty() | bool(self.dq) | !dq.is_empty() |
| size | dq.size() | len(self.dq) | dq.len() |
