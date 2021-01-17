## Pair with specific sum
- Given an array of integers nums and an integer target, return true if exist else false.
```c++
Input: nums = [7,2,11,15], target = 13
Output: true
Output: Because nums[0] + nums[2] == 13
```

## 1. Approach-1   //Naive  O(n<sup>2</sup>)
- **Logic** Run 2 for loops. compare each element. Return index when elements are found.
- **Complexity** Time: O(n<sup>2</sup>).  Space: O(n)

## 2. Approach-2    //Sort+2 pointer  O(nlogn)
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

## 3. Approach-3  //Hash Table  //O(n)
- **Logic** Insert complete array into `unordered_set<int>`. Traverse array again, find (target - element) in array
- **Complexity** Space: O(n), Time: O(n)
- **Code**
```c++
int main(){
  std::vector<int> v = {7,2,11,15}; int target = 13;
  std::unordered_set<int> us;

  for (auto i:v)
    us.insert(i);

  for(auto i:v){
    if (us.find(target-i) != us.end()){
      std::cout<<"Found";
      break;
    }
  }
}
```

#### Logic-2(Sort)
  1. Sort the array.          std::sort()=>O(nlogn)
  2. Take two index variables
     - Initialize first to the leftmost index: l=0
     - Initialize second  the rightmost index:  r=ar_size-1
  3. while l < r                                        =>O(n)
     - if (A[l] + A[r] == sum)  then return 1
     - else if( A[l] + A[r] <  sum )  then l++
     - else r--
