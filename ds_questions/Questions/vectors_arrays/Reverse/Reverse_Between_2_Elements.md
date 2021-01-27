### Problem
- You receive a vector/ array and 2 numbers, eg 2 and 5. Between those 2 positions in the vector (2 and 5) you have to reverse the order of the elements.
- Example
```c
input = {1,2,9,8,7,6,5}
output = {1,2,6,7,8,9,5}
```

## 1. Approach-1    //Naive
- **Logic:**
  - *1.* Start from left(index=0), Find index of element=2.
  - *2.* Again Start from left(index=0), Find index of element=5.
  - *3.* Move to indexes of 2,5 reverse in place.
- **Complexity**
  - **Time:** O(n)
    - 1st traversal finding index of 2. O(n)
    - 2nd traversal finding index of 5. O(n)
    - Reversing in place. O(n)

## 2. Approach-2    //Optimized. 2 pointer Approach
- **Logic:**
  - *1.* In 1 pass find positions of 2 and 5.
  - *2.* Take 2 pointers, left=index of 2. right=index of 5.
  - *3.* Reverse inplace using left,right.
- **Complexity**
  - **Time:** O(n)
    - In 1 pass find indexes of 2,5.  O(n)
    - Reversing in place using 2 Pointers. O(n)
- **Code**
  - *1.* Without using Inbuilt Functions
```c++
int main(){
  std::vector<int> v = {1,2,11,10,9,8,7,6,5};
  int start = -1, end = -1;

  //Find positions of 2, 5
  for (int i=0;i<v.size(); ++i){
    if(v.at(i)==2)
      start == -1 ? start = i : bTwoEntries = true;
    if(v.at(i)==5)
      end == -1 ? end = i : bTwoEntries = true;
      
    if(bTwoEntries){  //Edge case
      std::cout<<"Duplicate Entries of 2 or 5";
      break;
    }
  }

  //Edge case
  if (not bTwoEntries and start == -1 or end == -1){
    std::cout<<"Cannot find 2 or 5\n";
    return 0;
  }

  while (start < end){
    //std::swap(v.at(++start),v.at(--end));
    //OR
    ++start; --end;
    v.at(start) = v.at(start) + v.at(end);  //a = a+b
    v.at(end) = v.at(start) - v.at(end);    //b = a-b
    v.at(start) = v.at(start) - v.at(end);  //a = a-b
  }

  for (auto i:v)
    std::cout<<i<<" ";
}
```
  - *2.* Using inbuilt functions
```c++
int main(){
  std::vector<int> v = {1,2,11,10,9,8,7,6,5};
  itr it1 = std::find(v.begin(), v.end(), 2);   //Find position of 2
  std::vector<int>::iterator it2 = std::find(v.begin(), v.end(), 5);   //Find position of 5
  std::reverse(it1+1, it2);                   
}
```

### Complexity
- 3O(n)
