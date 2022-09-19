**Insertion Sort**
- [Logic](#l)
- [Pseudo Code](#pc)
- [Code](#c)
- [Complexity](#co)

### Insertion Sort (Placing Card at correct position in hand)
<a name=l></a>
#### Logic
- _1._ Compare each value to value on its left. if (value_on_left > value) swap. Repeat till index=0

<a name=pc></a>
#### Pseudo Code
```c
for j=1 in to A.size()
  key = A[j]
  
  // Insert A[j] into the sorted seqeuence
  i = j-1
  while i>0 and A[i]>A[j]
    swap A[i], A[j]
    i = i-1
    j = j-1
```
<a name=c></a>
#### Code
```c
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v = {5,2,4,6,1,3};
    for (int j=1;j<v.size();++j) {

        int i = j-1;
        while (i>=0 && v[i]>v[j]){
            //Swap the values
            v[i] = v[i]^v[j];
            v[j] = v[j]^v[i];
            v[i] = v[i]^v[j];
            
            if(i)
                i = i-1;
            j--;
        }
    }
    for (auto&i:v)
        cout << i << ",";
}
```
<a name=co></a>
#### Complexity
- **Time:** O(n<sup>2</sup>)
