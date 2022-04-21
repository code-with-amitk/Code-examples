- [Complexities](#c)
- [Stable/Unstable Sort](#su)

<a name=c></a>
### Complexities

|Algorithms|Time Complexity | Space Compelxity |
|---|---|---|
| Bubble/Selection/Insertion Sort |O(n<sup>2</sup>)| O(1) |
| Merge/Heap/Quick(Best) Sort | O(nlogn) | Merge:O(n), Other: O(1) |
| Counting/Radix/Bucket Sort | O(n) | |

- O(1): space complexity constant ie No extra space needed
- Worst-Case-Quick-Sort: We can use randomized version of quick sort which produces O(nlogn) in almost all cases with very high probability.

<a name=su></a>
### Stable/Unstable 
- Stability of algorithm is judged mainly on this form of input `<key, value>` (Eg: people names as keys and their details as values), and we wish to sort these objects by keys. - - Algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted
  - **Stable:** Bubble, insertion, merge, count    
  - **Unstable:** quick, heap

