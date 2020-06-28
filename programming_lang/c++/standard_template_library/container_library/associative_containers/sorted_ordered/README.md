## SORTED/ORDERED
  - **What** Ordered container always stores unique values in sorted order.
  - **Ordered/Sorted?** All elements are in order(ascending/descending)
  - Some operations does not make sense Eg: push_back(), push_front()
  - Sorting is done using Compare() function.
  - **COMPLEXITY** insert, remove, search: O(logn)
    - Implemented internally as RB Trees.
  - Every container is defined as template class. class provides templated contructors/functions.
