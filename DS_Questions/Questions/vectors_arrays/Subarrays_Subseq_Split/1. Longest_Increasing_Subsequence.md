### [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
- From array return longest increasing subsequence.
- A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
- Example
```
 input: [0,3,1,6,2,2,7]   //[3,6,2,7] is Subsequence but not increasing

input: [10,9,2,5,3,7,101,18]
Output: 4              //Longest increasing subsequence [2,3,7,101]

Input: nums = [0,1,0,3,2,3]
Output: 4             //LIS [0,1,2,3]
```
### [Self youtube video](https://youtu.be/mqbCl4kyDmQ)

### Logic(Dynamic Programming)
1. Create a Array `dp` containing longest subsequnce till particular element. Initialize array by 1.
```c++
vecArr:    10    9   2   5   3   7   101   18

dp:         1    1   1   1   1   1    1     1
Final dp:   1    1   1   2   2   3    4     4  //This we will calculate
```
2. Take 2 pointers i and j. i will point to element whose lis need to be calculated and j will start from index=0
```c++
vecArr:    10    9   2   5   3   7   101   18
            j    i
```
3. if element[i]>element[j] and dp[i]<=dp[j]. Increment dp[i] by 1 more than dp[j]
  - This means till element 2 there was LIS of length 1, But since 5 > 2. LIS at 5 can be 1 more than LIS at 2.
```c++
vecArr:    10    9   2   5   3   7   101   18
            1    1   1   2
```

### Code
```c++
int lis(std::vector<int> vecArr) {
  int iSize = vecArr.size(), iMax = 1;
  
  std::vector<int> dp(iSize, 1);        //A

  for (int i = 1; i < iSize; ++i){
    for (int j = 0; j < i; ++j){

      if (vecArr[i] > vecArr[j] and dp[i] <= dp[j]){
        dp[i] = dp[j] + 1;
        if(dp[i] > iMax)
          iMax = dp[i];
      }
    }
  }

  std::cout << "Dynamic Program Array:\n";
  for (int i=0;i<iSize;++i)
    std::cout << dp[i] << " ";
  std::cout<<"\n";
  
  return iMax;
}

int main() {
  std::vector<int> v = {10,9,2,5,3,7,101,18};
  std::cout << "Length = ";
  std::cout<<lis(v);
  return 0;
}
/*
# ./a.out
Dynamic Program Array:
1 1 1 2 2 3 4 4
Length = 4
*/
```
