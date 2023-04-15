**Max difference between two elements, larger appears after smaller / Best Time to Buy and Sell Stock**
- [Approach-1, Naive](#a1)
- [Approach-2, Sliding Window. O(1)](#a2)


### [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- Array of `prices[i]` is given shows the price of a given stock on the ith day.
- You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
- Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0
- Examples
```c
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

<a name=a1></a>
### 1. Approach1 //Naive O(n<sup>2</sup>)
#### Logic
Find difference of every element with other element using 2 for loops.
#### Code
```c
  int maxProfit(std::vector<int>& prices) {
    int maxDiff = 0;
    for (int i=0; i<prices.size();  ++i){
      for (int j=i; j<prices.size();  ++j){
        int var = prices[j] - prices[i];
        if (var>maxDiff)
          maxDiff = var;
      }
    }
    return maxDiff;
  }
};
```

<a name=a2></a>
### 2. Approach-2. Sliding Window   //Time:O(n), Space:O(1)
#### Logic
  - *1.* maxDiff = 0;   minElement = INT_MAX
  - *2.* Iterate thru the elements.
```c  
    if (element < minElement)               //if smaller element is found update minElement
        minElement = element
    if (element - minElement > maxDiff)     //if difference is greater than stored
        maxDiff = element - minElement;
```
#### Code
```cpp
  int maxProfit(vector<int>& prices) {        
    int minElement = INT_MAX;
    int maxDiff = 0;
        
    for (int i=0; i<prices.size();  ++i){
      if (prices[i] < minElement)
        minElement = prices[i];
        
      if (prices[i] - minElement > maxDiff)
        maxDiff = prices[i] - minElement;
    }
    return maxDiff;
  }
```
