## [Problem](https://leetcode.com/problems/coin-change-2/)
- You are given coins of different denominations and a total amount of money. Find number of combinations that make up that amount. There is infinite number of each kind of coin.
- Examples
```c
Example-1
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Example-2
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
```

### You need to watch [Self-Youtube-Video](https://youtu.be/7pRO5Zuiijo) [Video-2](https://youtu.be/C8bmCYohJkw) for explanation, because its pretty complex.

### Code
```c++
//n=value to be made
//c=denominations of coins
long getWays(int n, vector<long> c){
  if(!n)
    return 1;
  if(n && !c.size())
    return 0;
    
  sort(c.begin(), c.end());

  int denominations = c.size();

  long ways[denominations][n+1];
  ways[0][0] = 1;

  for(int i=0;i<n+1;i++){ 
    if(i%c[0] == 0)
      ways[0][i] = 1;
    else
      ways[0][i] = 0;
  }
  
  //Making 1st col as 1
  for(int i=0;i<denominations;i++)
    ways[i][0] = 1;

  for(int i=1;i<denominations;i++){
    for(int j=1;j<n+1;j++){
      if(j < c[i]){
        ways[i][j] = ways[i-1][j];
      }else{
        ways[i][j] = ways[i-1][j] + ways[i][j - c[i]];
      }
    }
  }

  /*for(int i=0;i<denominations;i++){
    for(int j=0;j<n+1;j++){
      cout<<ways[i][j]<<" ";
    }
    cout<<"\n";
  }*/

  return ways[denominations-1][n];
}

int main(){
  int n = 4;
  vector<long> v = {1,2,3};
  cout<<getWays(n,v);             //4
}
```
