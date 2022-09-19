**Insertion Sort**
- [Logic](#l)
- [Pseudo Code](#pc)
- [Code](#c)
- [Complexity](#co)

### [Self Video](https://youtu.be/EAxqcbpGs_w)

### Insertion Sort(From Cormen book. CRLS) (Placing Card at correct position in hand)
<a name=l></a>
#### Logic
- _1._ Compare each value to value on its left. if (value_on_left > value) swap. Repeat till index=0

<a name=pc></a>
#### Pseudo Code
<img src=images/insertion_sort.JPG width=500/>

```c
for j=1 in to A.size()
  //A[j]      //Card to be placed at correct position
  
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
        int k = j;
        while (i>=0 && v[i]>v[k]){
            //Swap the values
            v[i] = v[i]^v[j];
            v[k] = v[k]^v[i];
            v[i] = v[i]^v[k];
            
            if(i)
                i = i-1;
            k--;
        }
    }
    for (auto&i:v)
        cout << i << ",";
}
```
<a name=co></a>
#### Complexity
- **Time:** O(n<sup>2</sup>)
