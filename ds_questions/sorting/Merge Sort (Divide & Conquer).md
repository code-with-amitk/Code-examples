- ![#f03c15](https://via.placeholder.com/15/f03c15/000000?text=+) `#f03c15`

**In computer science, the mental representation for a problem is often closely related to its solution.**

## Merge Sort //Not inplace
### Complexity
  - **Time: O(nlogn)**
    - n: To divide the array, complete array needed to be traversed
    - logn: Array is divided in binary tree format.
  - **Space: O(n)** A auxillary subarrays are created and merged back to original array.
### Logic
  - Keep dividing input array into 2 halves recursively, until reach array of size=1
  - Merge back sorted subarrays in ascending order.  
### Code
```c++
#include<iostream>
#include<vector>
using vec1d = std::vector<int>;

void MergeSubArrays(vec1d& v, int left, int mid, int right) {

  //Create 2 sub arrays: left, right
  int leftArrSize=mid-left+1;
  int rightArrSize=right-mid;
  int leftArr[leftArrSize], rightArr[rightArrSize];

  //Fill 2 subarrays from Original array
  for(int i=0;i<leftArrSize;++i)
    leftArr[i] = v[left+i];
  for(int i=0;i<rightArrSize;++i)
    rightArr[i] = v[mid+1+i];

  int i,j,k;
  i=0, j=0, k=left;

  //Change elements of Original array
  while(i<leftArrSize and j<rightArrSize){
    if(leftArr[i] <= rightArr[j]){
      v[k] = leftArr[i];
      ++i;
    }else{
      v[k] = rightArr[j];
      ++j;
    }
    ++k;
  }

  //Merge Extra elements in left Subarray
  while (i<leftArrSize) {
    v[k] = leftArr[i];
    ++k; ++i;
  }

  //Merge Extra elements in right Subarray
  while (j<rightArrSize) {
    v[k] = rightArr[j];
    ++k; ++j;
  }
}

void MergeSort(vec1d& v, int left, int right){
  if (left>=right)
    return;

  int mid = (left+right)/2;
  MergeSort(v, left, mid);
  MergeSort(v, mid+1, right);
  MergeSubArrays(v, left, mid, right);
}

int main(){
  vec1d v = {10,5,4,2,7,6};
  MergeSort(v, 0, v.size()-1);
  for (const auto i:v)
    std::cout<<i<< " ";
}
```
