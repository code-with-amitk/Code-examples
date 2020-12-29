## Problem
- Given a unsorted array where every number occur even number of times except one number, find the odd occurring number.
```c
arr[] = {1, 1, 4, 9, 6, 8, 6, 4, 8 }
Answer: 9
```

### Approach-1(Sort, Binary Search)
1. Sort:        O(nlogn)
2. Binary search: O(logn)
3. Complexity: O(n+1(logn))

### Approach-2(XOR Operator)
- Complexity: O(n)

### Approach-3(Hash-table)
- if element is not present in HT insert.
- if element is present erase
- At last only odd occurance element remains.
- Complexity:O(n)

### Code
```c++
#include <iostream>
#include <unordered_set>
using namespace std;

int main(void)
{
    int num = 0, n;
    unordered_set<int> s;

    int a[] = {1, 1, 4, 9, 6, 8, 6, 4, 8 };
    int n = sizeof(a) / sizeof(a[0]);

/*  Using XOR Operator: O(n)
    for (int i = 0; i < n; i++)
        num ^= a[i];
        
    cout<<num;
*/        

    //Using Hash Table: O(n)
    for(int i=0;i<n;i++){
        if(s.find(a[i]) != s.end()){
            s.erase(a[i]);
        }else{
            s.insert(a[i]);
        }
    }
    
    for(auto i=s.begin();i!=s.end();i++)
        cout<<*i;
}
/*
Output:
9
*/
```
