- [maxHeap](#max)
- [minHeap](#min)

<a name=min></a>
### minHeap
```rs
use std::collections::BinaryHeap;
use std::cmp::Reverse;

fn main() {
    // Create an empty min-heap
    // wrap the elements in the Reverse struct. This is because by default, BinaryHeap in Rust implements a max-heap
    let mut min_heap: BinaryHeap<Reverse<i32>> = BinaryHeap::new();

    // Insert elements into the heap
    // The Reverse wrapper is used to reverse the comparison order, so the smallest elements will be at the top of the heap.
    min_heap.push(Reverse(5));
    min_heap.push(Reverse(2));
    min_heap.push(Reverse(10));
    min_heap.push(Reverse(1));

    // Pop the minimum element from the heap
    while let Some(Reverse(min)) = min_heap.pop() {
        println!("Popped element: {}", min);
    }
}

```
