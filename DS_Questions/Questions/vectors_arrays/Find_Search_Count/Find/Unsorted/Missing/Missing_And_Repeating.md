### [Problem](https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/)
- Continious, unsorted Array from `[1, n]`. Array will always start from 1. 
- Each integer appears exactly once except A which appears twice and B which is missing.
- Return A and B in linear runtime complexity & without using extra memory.
- A=Repeated, B=Missing
- **Examples**
```c++
Ex-1:
    {3,4,1,3,5}   //A=3, B=2. (Series from 1 to 5)
    
Ex-2:    
    {8,9,7,3,6,1,4,5,6}   //A=6, B=2  (series from 1 to 8)  
```

### Approach-1 (Sorting)
- But since array is const we cannot sort

### Approach-2 (Hash Map)
- But since question says not to use any other data structure, we cannot use

### Approach-3 //A<sup>2</sup> - B<sup>2</sup> = (A+B)(A-B)
> Input = {8,9,7,3,6,1,4,5,6}.  Repeated=A=6.    Missing=B=2
- *1.* A - B = CurrentSum - ActualSum
```c
    1+2+3+4+5+6+7+8+9 = 45  //ActualSum                     //n(n+1)/2
    1+6+3+4+5+6+7+8+9 = 49  //CurrentSum
    A-B = 49 - 45   //should be 4    
```
- *2.* A<sup>2</sup> - B<sup>2</sup> = CurrentSquare-ActualSquare
```c++
    1^2 + 2^2 + 3^2 + ... 9^2 = 285 //ActualSquare          //n(n+1)(2n+1)/6        
    1^2 + 6^2 + 3^2 + ... 9^2 = 317 //CurrentSquare
    6^2 - 2^2 = A^2 - B^2 = 32
```   
- *3.* A + B = (A<sup>2</sup> - B<sup>2</sup>)/(A - B)
```c++
  32/4       //should be 8    
```

### Complexity-Approach-3
- **Time:** O(n)
- **Space:** O(2)

### Code-Approach-3
```c++
#include<iostream>
#include<vector>

using vec = std::vector<int>;

vec find(vec& v){
  vec out;
  int A=0, B=0;   //A:Repeated, B:Missing
  long ActualSum = 0, CurrentSum = 0;
  long ActualSquare = 0, CurrentSquare = 0;
  int max=0;
  for (auto i:v) {
    CurrentSum += i;
    CurrentSquare += i*i;
    if (i>max)
      max = i;
  }

  ActualSum = max*(max+1)/2;    //1+2+3..n = n(n+1)/2
  ActualSquare = max*(max+1)*(2*max+1)/6;   //1^2+2^2+..n^2 = n(n+1)(2n+1)/6
  std::cout<<"CurrentSum: "<<CurrentSum<<"\n";
  std::cout<<"ActualSum: "<<ActualSum<<"\n";
  std::cout<<"CurrentSquare: "<<CurrentSquare<<"\n";
  std::cout<<"ActualSquare: "<<ActualSquare<<"\n";
  A = ((CurrentSum - ActualSum) + (CurrentSquare - ActualSquare)/(CurrentSum - ActualSum))/2;
  B = ((CurrentSquare - ActualSquare)/(CurrentSum - ActualSum)) - A;
  out.push_back(A);
  out.push_back(B);
  return out;
}

int main(){
  vec v = {8,9,7,3,6,1,4,5,6};
  vec out = find(v);
  for (auto i:out)
    std::cout<<i<<" ";
}
```
