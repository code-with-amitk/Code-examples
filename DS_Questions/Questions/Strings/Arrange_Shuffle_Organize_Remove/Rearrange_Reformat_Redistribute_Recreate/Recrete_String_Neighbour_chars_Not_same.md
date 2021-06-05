## [Reorganize String](https://leetcode.com/problems/reorganize-string/)
- Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
- If possible, output any possible result.  If not possible, return the empty string.
- Examples:
```
Input: S = "aab"
Output: "aba"

Input: S = "aaab"
Output: ""
```

### [Self Video for Understanding](https://youtu.be/kE7q5LL8j-0)

## Logic (Hash and priority_queue/maxHeap)
> s = "aaaaaccbbb"
1. Count number of elements using hash table`unordered_map<key=char,value=count>`. This contains unique keys.

| a,5 | c,2 | b,3 |
|---|---|---|

2. From hash table create `priority queue<key=count, value=char>`.

```
  5,a
  / \
2,c 3,b
```

3. Perform following operation on Priority queue.

|5,a|3,b|2,c|
|---|---|---|

  - pop Topmost element p1 = (5,a) and 2nd top most p2 = (3,b)
  
|2,c|
|---|
  
  - Create output string using 2nd elements of p1 and p2. 
```  
string = ab
```
  - Decrement 1st element of p1,p2.   p1=(4,a)  p2(2,b)
  - If p1.first>0 push Again on queue
  - If p2.first>0 push Again on queue

|4,a|2,c|2,b|
|---|---|---|

  - Repeat proces till queue is not empty
  
## Complexity
- Creating Hash Table = O(n)
- Creating priority Queue using Hash table
  -  Since heap is balanced BT, nodes are inserted using level order traversal. Insertion=O(1) but balance=O(log26). Since only 26 unique elements are present.
- Remove top1, top2 = O(1)  
- Re-Insert = O(log26).
  - If all elements are unique reinsertion will not happen only pop top will happen O(1).
  - if half elements are same as other half. Eg: aaaaabbbbb. Then n/2 insertions will happen. 
- **Complexity** 
  - **Time:**
```diff
 O(n) + n/2*O(log26) = O(n)
```
  
## Code  
```c++
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> um;
        priority_queue<pair<int, char>> pq;
        string output = "";

        for (auto i : s)
            um[i]++;

        for (auto &i : um)
            pq.push({i.second, i.first});

        while (pq.size() > 1) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();

            output += top1.second;
            output += top2.second;

            if (--top1.first > 0){
                pq.push(top1);
            }
            if (--top2.first > 0){
                pq.push(top2);
            }
        }

        if (pq.size()) {
            if (pq.top().first == 1)
                output += pq.top().second;
            else
                return "";
        }
        return output;
    }
};
int main(){
  string s = "aaaaaccbbb";
  Solution o;
  cout<<o.reorganizeString(s);
}

# ./a.out
abacabacba
```
