### [Count ways to reach the n’th stair](https://www.geeksforgeeks.org/count-ways-reach-nth-stair/)
- There are n stairs, a person standing at the bottom wants to reach the top. 
- The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.
![ImgURL](https://media.geeksforgeeks.org/wp-content/uploads/nth-stair.png)
```c
Example-1:
steps = 2
ways:2 [1,1] [2]

Example-2:
steps = 3
ways:3. [1,1,1] [1,2] [2,1] 

Example-3:
Steps = 4
Ways: 5. 1111, 211, 221, 212, 122
```

### Approach-1  //Recursion   (2<sup>n</sup>)
### Logic-1
```c
			  	4
			 /	   \
			3	    	2
	  /  \	     \
	 2    1    	  1
	  \
	   1
```
- *1.* On nth stair person can reach from n-1 or n-2 stair. fun(n) = fun(n-1) + fun(n-2)
- *2.* To count number of ways till nth stair start from (n+1)th stair.
### Complexity-1
  - **Space:** O(1)
  - **Time:** [Recursion=O(2<sup>n</sup>)](/DS_Questions/README.md)
### Code-1
```c++
int Ways(int a){
  if (a<=1)
    return a;

  return Ways(a-1)+Ways(a-2);
}

int DistinctWays(int& a){
  return Ways(a+1);
}

int main(){
  int a=4;
  std::cout<<DistinctWays(a);
}
```

### Approach-2  //Dynamic Programming   //O(n)
- *1.* See above, This is repeative subproblems question.  2-1
- *2.* Take a array sized n, Each element stores ways to reach nth stair.
  - *2a.* Ways to reach stair 1 is 1.
  - *2b.* Build the array using `v[i] = v[i] + v[i-j]`. Where j can be 1 or 2. At stair i person can reach from i or i-2th stair
### Complexity
  - **Space:** O(n)
  - **Time:** O(n*2)
### Code-2
```c++
#include<iostream>
#include<vector>
using vec1d = std::vector<int>;

int Ways(int a){
  vec1d v(a,0);                     //Dynamic Prgoramming array
  
  v[0]=v[1]=1;                      //2a
  
  for(int i=2;i<a;++i){
    for(int j=1; j<=2 && j<=i; ++j)
      v[i] += v[i-j];               //2b
  }
  return v[a-1];
}

int DistinctWays(int& a){
  return Ways(a+1);
}

int main(){
  int a=3;
  std::cout<<DistinctWays(a);
}
```
