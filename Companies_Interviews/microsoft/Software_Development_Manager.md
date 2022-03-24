**Software Development Manager**
- **Coding**
  - [1. ListOfList](#lol)
  - [2. Sort list of cities by population / list of pairs](/DS_Questions/Questions/vectors_arrays/Pairs_Duplicates/Pairs/Unsorted/List_of_Cities_and_Population_sort.md)

## Software Development Manager
### Coding
<a name=lol></a>
#### 1. ListOfList
**Question:** Implement next(), hasNext() of `class ListIterator`.
```c
/**
 * // This is the interface that allows for creating list of lists.
 * // You should not implement it, or speculate about its implementation
 * class ListOfList {
 *   public:
 *     // Return true if this ListOfList holds a single integer, rather than a list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this ListOfList holds, if it holds a single integer
 *     // The result is undefined if this ListOfList holds a list
 *     int getInteger() const;
 *
 *     // Return the list that this ListOfList holds, if it holds a list
 *     // The result is undefined if this ListOfList holds a single integer
 *     const vector<ListOfList> &getList() const;
 * };
 */
 
class ListIterator {
public:
    ListIterator(vector<ListOfList> &listOfList) {
    }
    
    int next() {
    }
    
    bool hasNext() {
    }
};
Example (1)
Input: listOfList = [1,[4,[6]]]
Output: [1,4,6]

Example (2)
Input: [1, [2, 3, [4, 5, []], 6], 7]
Output: [1, 2, 3, 4, 5, 6, 7]
```
**My Answer:**
```c
class ListIterator {
    vector<ListOfList> ll;
    vector<ListOfList>::iterator it = ll.begin();
public:
    ListIterator(vector<ListOfList> &listOfList) {
        ll = listOfList;
    }
    
    int next() {
        if (hasNext()){
            for (auto i=it.begin(); i !=it.end(); ++i){
                //Check the single ll
                list<int>::iterator single& = *i;
                for (auto j=single.begin(); j!=single.end(); ++j){
                    return *j;
                }
            }
            //it = i;
        }
        return 0;
    }
    
    bool hasNext() {
        if it != ll.end()
            return true;
        return false
    }
};
```
