**1405. Longest Happy String**
- [Approach-1. Priority Queue. O(n)](#a1)
  - Code
    - [CPP](#c)

### [1405. Longest Happy String](https://leetcode.com/problems/longest-happy-string/description/)
- A string s is called happy if it satisfies the following conditions:
  - s only contains the letters 'a', 'b', and 'c'.
  - s does not contain any of "aaa", "bbb", or "ccc" as a substring.
  - s contains at most a occurrences of the letter 'a'.
  - s contains at most b occurrences of the letter 'b'.
  - s contains at most c occurrences of the letter 'c'.
- Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
- A substring is a contiguous sequence of characters within a string.
- Example 1:
```c
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
```

<a name=a1></a>
### Approach-1, Priority Queue. O(n)
#### Logic
- _1._ Create max heap of elements.
```c
    7,c
   /  \
  1,a  1,b  
```
- _2._ Remove top 2 elements and insert into output.
```c
out = cca
    5,c
   /
  1,b
```
- _3._ `if removed element's size > 0` again insert into queue
#### Code
<a name=c></a>
**CPP**
```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        string out = "";
        /*
            7,a
            / \
           2,b 1,c 
        */
        while (pq.size() >= 2) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();

            /* Insert 2 elements from max element in queue
               out = aa
            */
            if (top1.first >= 2){
                out += top1.second;
                out += top1.second;
                top1.first -= 2;
            }
            else {
                out += top1.second;
                top1.first -= 1;
            }

            /* For 2nd max element, Only insert 2 elements 
                if top2 now became max, ie after removal of top1
                But top1=5, top2=2. Still top1 is max, insert only 1 element
                out = aab
            */
            if (top2.first >= 2 && top2.first >= top1.first){
                out += top2.second;
                out += top2.second;
                top2.first -= 2;
            }
            else {
                out += top2.second;
                top2.first -= 1;
            }
            if (top1.first)
                pq.push(top1);
            if (top2.first)
                pq.push(top2);
        }//while

        if (pq.empty())
            return out;

        if (pq.top().first >= 2) {
            out += pq.top().second;
            out += pq.top().second;
        }
        else{
            out += pq.top().second;
        }
        return out;
    }
};
```
