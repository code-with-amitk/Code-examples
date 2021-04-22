### Time Complexity

||Bubble|Modified Bubble|Selection|Insertion|Merge|Quick|Heap|[Intro Sort. Used by sort() STL](Hybrid_Sorting_Algo)|
|---|---|---|---|---|---|---|---|---|
|Best|O(n<sup>2</sup>)|O(n)| O(n<sup>2</sup>)| O(n)| O(n)|O(n)|O(nlogn)|O(nlogn)
|Worst|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(nlogn)|O(n<sup>2</sup>)//When arr is sorted|O(nlogn)|O(nlogn)|
|Avg|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n<sup>2</sup>)| O(nlogn)|O(nlogn)|O(nlogn)|O(nlogn)|

### Space Complexity

||Bubble|Modified Bubble|Selection|Insertion|Merge|Quick[Best]|Heap|
|---|---|---|---|---|---|---|---|
||O(1)|O(1)|O(1)|O(1)|O(n)|O(1)|O(1)|

- O(1): space complexity constant ie No extra space needed

Worst-Case-Quick-Sort: We can use randomized version of quick sort which produces O(nlogn) in almost all cases with very high probability.
