## Pair with specific sum
- Given an array of integers nums and an integer target, return true if exist else false.
```c++
Input: nums = [7,2,11,15], target = 13
Output: true
Output: Because nums[0] + nums[2] == 13
```

### 1. Approach-1   //Naive  O(n<sup>2</sup>)
- **Logic** Run 2 for loops. compare each element. Return index when elements are found.
- **Complexity** Time: O(n<sup>2</sup>).  Space: O(n)

### 2. Approach-2    //Sort+2 pointer  O(nlogn)
- **Logic** Sort array. Take left and right pointer. 
```c
  if (v[left]+v[right]>target)
    --right
  else
    ++left
```
- **Complexity** O(nlogn)+O(n)
- **Code**
```c++
int main(){   //2,5,7,11,13,14,15
  std::vector<int> v = {5,7,2,14,13,11,15}; int target = 13;
  sort(v.begin(), v.end());

  int left=0, right=v.size()-1;
  while(left<right) {
    int temp = v[left]+v[right];
    if (temp == target){
      std::cout<<"Found";
      break;
    }
    else if (temp > target)
      --right;
    else
      ++left;
  }
}  
```

### 3. Approach-3  //Hash Table  //O(n)
- **Logic** 
  - *1.* Traverse array, if difference (target-element) is not present in unordered_set. Insert element in unordered_set
  - *2.* else we found the pair
- **Complexity** Space: O(n), Time: O(n)
- **Code**
```c++
#include<iostream>
#include<vector>
#include<unordered_set>
using vec = std::vector<int>;
using vec2d = std::vector<std::vector<int>>;

vec2d fun(vec& v, int target){
  vec2d out;
  std::unordered_set<int> us;

  for (auto i:v){

    auto it = us.find(target-i);

    if (it == us.end())   //Element not found
      us.insert(i);
    else{                   //Element found
      vec a;
      a.push_back(target-i); a.push_back(i);
      out.push_back(a);
    }
  }
  return out;
}

int main(){   //2,5,7,11,13,14,15
  vec v = {2,5,7,11,14,15,6}; int target = 13;
  vec2d out = fun(v, target);
  for(auto i:out)
    std::cout<<i[0]<<","<<i[1]<<"\n";
}
```
