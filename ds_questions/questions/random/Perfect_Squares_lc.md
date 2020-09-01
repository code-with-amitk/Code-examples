### [Perfect Squares](https://leetcode.com/problems/perfect-squares/)
- Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
- Example 1:
```c
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
```
- Example 2:
```c
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

### Logic
1. We need to create a array contaning count of perfact squares. Ex: Create array till number 5.
```c
  ar[0]=0
  ar[1]=1   //1 can be created using 1
  ar[2]=2   //2 = 1+1
  ar[3]=3   //3 = 1+1+1
  ar[4]=1   //4 = sq(2)
  ar[5]=2   //5 = 4+1
  
    | 0 | 1 | 2 | 3 | 1 | 2 |
index 0   1   2   3   4   5         //indexes denotes the actual elements

  Perfact square for 5 = 2
```  
2. How we calculate above array?
  - Take a square array for less than number.
  - Take dynamicProgramming array and inititialize all elements to infinity
```c
Squaure array for number=5 wuold be sq=[1,4]
vDP[0,inf,inf,inf,inf,inf]
```
3. Compare each element of vDP with each element of square array [1,4]
```
if(index-of-vDP(ie actual element) >= square-array-element)
  count = 
```      
### Code
```c++
class Solution {
public:
  int numSquares(int iNumber) {

    vector<int> vDP ( iNumber + 1, INT_MAX );
    vector<int> sq;

    vDP[0] = 0;

    for ( int i = 1; i*i <= iNumber; i++ )
      sq.push_back( i*i );

    for ( int i = 1; i <= iNumber; i++ ) {

      for( int j = 0; j < sq.size(); j ++) {

        if ( i >= sq[j] ) {
          vDP[i] = min( vDP[i], vDP[i - sq[j]] );
        }

      }
      vDP[i]++;
    }

    cout<<endl;
    for(auto i:vDP)
      cout<<i<<" ";
    cout<<endl;
    return vDP[iNumber];
  }
};

int main(){
  Solution s;
  cout<<s.numSquares(3);
}
```
