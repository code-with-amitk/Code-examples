## [Problem](https://www.pramp.com/challenge/VKdqbrq6B1S5XAyGAOn4)
- You are given an array of characters arr that consists of sequences of characters separated by space characters. Each space-delimited sequence of characters defines a word.
- Implement a function reverseWords that reverses the order of the words in the array in the most efficient manner.
- Explain your solution and analyze its time and space complexities.
- Example:
```c++
input:  arr = {'a','m','i','t',' ','k','u','m','a','r'};
output: {'k','u','m','a','r',' ','a','m','i','t'};
```

## Logic
1. Reverse the complete string. Using reverse() function or stack
```c++
'r','a','m','u','k',' ','t','i','m','a'
```
2. Reverse Each word using 2 pointers.
```c++
'r','a','m','u','k',' ','t','i','m','a'
/\              /\
i               j
```

## Complexity
- **Time** 2O(n). Reverse whole string=O(n) + Reverse each word=O(n)
- **Space** O(n). Taking extra vector

## Code
```c++
vector<char> reverseWords( const vector<char>& v1 ) {
  std::vector<char> v = v1;
  std::reverse(v.begin(), v.end());

  int i=0, j=-1, k=0;

  for (auto itr:v) {
    if (itr == ' '){
      while (i <= j){
        std::swap(v[i],v[j]);
        ++i; --j;
      }
      j = k+1;
      i = k+2;
    }else{
      ++j;
      k = j;
    }
  }
  if(j>i){
      while (i <= j){
        std::swap(v[i],v[j]);
        ++i; --j;
      }
  }
  return v;
}
```
