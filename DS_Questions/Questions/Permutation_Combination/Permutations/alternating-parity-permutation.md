## Problem
- Parity of number? Only 2 parities are there. Odd, even
- Input = n `1 <= n <= 11`
- Output: 2-D array of alternating parities
  - Generate a sequence where parities are alternating.
  - ie no 2 odd parities or 2 even parities shuold be colocated.
  
### Example-1
- Input no = 2
```
n = 2   
Ouput=  {1,2}, {2,1}
```

### Example-2
- Input no = 3
```
n = 3
All Permutations:
{1,2,3}      //ok
{1,3,2}      //Reject: Odd parities(1,3) are adjacent
{2,1,3}      //ok
{2,3,1}       //Reject: Odd parities(3,1) are adjacent

Output= {1,2,3} {3,2,1}
```

# Example-3
- Input no = 4
```
n = 4
Valid Permutations:
1 2 3 4
1 4 3 2
2 1 4 3
2 3 4 1
3 2 1 4
3 4 1 2
4 1 2 3
4 3 2 1
```

## Logic
- Generate a vector from incoming no. Eg: n=4. Generate vector{1,2,3,4}
- Create a 2-D vector to store permutations.
- Find the possible permutations in while loop using `next_permutation()`
  - push 1st permutation as it is `{1,2,3,4}`
  - On every other permutation check neither even or odd numbers are adjacent to each other, if they are. Reject the permutation.
  
## Code
```
vector<vector<int>> f(int n){
  vector<vector<int>> v;
  int firstPass = 1, pass=0;

  //create a vector
  vector<int> a;
  for(int i=1;i<=n;i++)
    a.push_back(i);

  do{
    if(firstPass){
      v.push_back(a);
      firstPass=0;
    }else{
      //Traverse Permutation & Check no adjaecent nos are even or odd
      
      for(int i=0;i<n-1;i++){
        if((a[i]%2 == 0 && a[i+1]%2 == 0) || (a[i]%2==1 && a[i+1]%2==1)){
          pass=1;
          break;
        }
      }
      if(!pass)
        v.push_back(a);
    }
    pass=0;
  }while(next_permutation(a.begin(), a.end()));
  return v;
}
```
