- **Monotonic Stack**
  - [Increasing subseqeunce](#i1)
  - [Decreasing subseqeunce](#i1)

## Monotonic Stack
- This contains increasing subsequence or decreasing subsequence(BUT NOT LONGEST/SMALLEST) and done in O(nm) time.
  - n:Number of input elements, m:
- We create stack from input array.
```c
Input array = {2, 3, 7, 11, 5, 17, 19}
Monotonic Increasing Stack
|19|
|17|
|5 |
|3 |
|2 |
```

<a name=i1></a>
### Increasing subseqeunce
#### Logic
- _1._ if stack is empty, insert element.
- _2._ if 
  - (ele > stack.top())
    - insert element
  - else
    - remove all greater elements
```c
arr = {2, 3, 7, 11, 5, 17, 19}
  arr_ele   stack
    2       |2|
    3       |3|     //3>2
            |2|
    7       |7|     //7>3
            |3|
            |2|
    11      |11|     //11>7
            |7|
            |3|
            |2|
    5       |11|     //element(5) < top(11). pop
            |7|
            |3|
            |2|
            
            |7|     //element(5) < top(7). pop
            |3|
            |2|
            
            |3|     //element(5) > top(3). push
            |2|

            |5|
            |3|
            |2|

    17      |17|     //17 > 5. Push
            |5|
            |3|
            |2|

    19      |19|     //19 > 17. Push
            |17|
            |5|
            |3|
            |2|
```
- _3._ Our stack contains increasing subsequence.
```c
{2, 3, 7, 11, 5, 17, 19}
Longest Increasing subsequence: {2,3,7,11,17,19}
Monotonic stack contains:       2,3,5,17,19
```

#### Code
```cpp
int main() {
    vector<int> arr = {2,3,7,11,5,17,19};

    stack<int> st;
    for (int i=0;i<arr.size();++i){
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        st.push(arr[i]);
    }
    while(!st.empty()){
        cout << st.top() <<" ";   st.pop();
    }
    cout <<"\n";
}
```

<a name=i2></a>
#### Decreasing subseqeunce
