**Find All subsequences**
- [Approach-1, 2 pointers, 3 loops. O(n<sup>3</sup>)](#a1)

### Find All subsequences
Print all subsequence of given string
```c
input = {1,2,3}
output = 
{1}
{1,2}
{1,2,3}

{2} 
{2,3}

{3}
```

<a name=a1></a>
### Approach-1, 2 pointers, 3 loops. O(n<sup>3</sup>)
#### Logic
- _1._ Take pointer a to start and move b.
 ```c
 1   2   3   4   5
 a   b
```
- _2._ Wherever is the position of print values between a and b.
```c
 1   2   3   4   5
 a   b                //{1,2}
 a       b            //{1,2,3}
 a           b        //{1,2,3,4}
 a               b    //{1,2,3,4,5}
```
- _3._ When a is moved to next element bring b back to element+1 where a is pointing to.
```c
 1   2   3   4   5
     a   b                //{2,3}
     a       b            //{2,3,4}
     a           b        //{2,3,4,5}
```
#### Code
```cpp
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    int b = 0;
    for (int i=0; i<a.size(); ++i) {
        b=i;
        while (b <= a.size()) {
            for (int j=i; j<b; ++j) {
                cout << a[j] << " ";
            }
            b++;
            cout << "\n";
        }
    }
}
```
#### Complexity
- **Time:** O(n<sup>3</sup>)
- **Space:** O(1)
