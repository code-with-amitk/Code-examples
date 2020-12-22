### [Problem](https://www.geeksforgeeks.org/split-array-two-equal-sum-subarrays/#:~:text=Given%20an%20array%20of%20integers,Print%20the%20two%20subarrays.)
- Given an array of integers greater than zero, find if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays is the same. Print the two subarrays.
- Examples
```c++
Input : Arr[] = { 1 , 2 , 3 , 4 , 5 , 5  }
Output :  { 1 2 3 4 } 
          { 5 , 5 }

Input : Arr[] = { 4, 1, 2, 3 }
Output : {4 1}
         {2 3}

Input : Arr[] = { 4, 3, 2, 1}
Output : Not Possible
```
### Logic
- 2 pointer approach
## Code
```c++
bool fun(std::vector<int>& a) {
  int i=0, j = a.size() - 1;
  int leftSum = a[i], rightSum = a[j];

  while(i<j){

    if (leftSum < rightSum)
      leftSum += a[++i];
    else
      rightSum += a[--j];

    if(j-i==1)
      break;
  }
  return leftSum == rightSum ? true : false;
}
```
