## [Pan cake sorting](https://www.pramp.com/challenge/3QnxW6xoPLTNl5jX5LM1)
- **What is Pancake sorting?** This sorting works on only 1 function ie flip or reverse(arr, position). ie reverse the array from begin to position.
- **How pancake sorting works?** arr = [1, 5, 4, 3, 2]
  - *1.* Find larget number in array and reverse from index=0, to index_Of_LargestElement
```c++
  index_Of_LargestElement = 1
  v = flip (arr, index_Of_LargestElement)
  v = [5, 1, 4, 3, 2]
```
  - *2.* Reverse array from index=0 to end. Now largest element gets at end, fix this position.
```c++
  v = flip(arr, 4)
  v = [2, 3, 4, 1, 5]
                   /\
                   Fixed
```
 - *3.* Repeat steps 1 and 2 for sub array `[0, 3]`
```c++
  index_Of_LargestElement in [2, 3, 4, 1] = 2    //Since 5 is fixed
  v = flip (arr, index_Of_LargestElement=2)
    //v = [4, 3, 2, 1, 5]
    
  v = flip (arr, 3)                 //Reverse/flip [4, 3, 2, 1] leaving fixed element=5.
    //v = [1, 2, 3, 4, 5]  
                    /\ /\
                  fixed fixed
-> Now 2 elements are fixed repeat this process for rest of elements.                  
```

### Input, Output
```c++
input:  arr = [1, 5, 4, 3, 2]
output: [1, 2, 3, 4, 5]
```

## Code
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using vi = std::vector<int>;

vi& flip(vi& arr, int k){
  std::reverse(arr.begin(),arr.begin()+k+1);    //reverse[first,last).  Reverses from first to last(excluding last)
  return arr;
}

vi pancakeSort( const vi& arr ) {
  vi v = arr;
  int i = v.size();

  while (i >= 0){
    int maxIndex = std::max_element(v.begin(), v.begin()+i) - v.begin();  //Find index of Max element in array
    flip(v, maxIndex);
    flip(v, i-1);
    --i;
  }
  
  return v;
}

int main() {
  vi arr = {1, 5, 4, 3, 2};
  vi v = pancakeSort(arr);
  for (auto i:v)
    std::cout << i << " ";
}
# ./a.out
1 2 3 4 5
```
