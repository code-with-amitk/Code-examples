**Naive, Brute Force**
- [Cases where Naive perform worst](#c)
- [Complexity](#co)
- [Code](#c1)

<a name=c></a>
### Cases where Naive perform worst
Many matching characters followed by a mismatching character. 
```c
   txt[] = "AAAAAAAAAAAAAAAAAB"
   pat[] = "AAAAB"
```

<a name=co></a>
### Complexity
O(mn)

<a name=c1></a>
### Code
```cpp
using vec = vector<int>;

vec fun(string haystack, string needle){
  vec index;

  int hsize = haystack.size();
  int nsize = needle.size();
  int i=0,j=0,k=0;

  while (i < hsize) {
    if (haystack[i] == needle[j]) {
      k = i;
      while (haystack[k] == needle[j] && j < nsize){
        if( j == psize -1 )
          index.push_back(i);
        k++;
        j++;
      }
      j=0;
   }//if
   i++;
  }
  return index;
}

int main(){
  string haystack = "testmanmanm";
  string needle = "man";

  vector<int> v = fun(haystack, needle);
  cout<<"Substring found at indexes = ";
  for(auto i:v)
    cout<<i<<" ";
}

 # g++ navie-algorithm.cpp -O2 -Wall -Wextra -Wpedantic
 # ./a.out
Substring found at indexes = 0 11
```
