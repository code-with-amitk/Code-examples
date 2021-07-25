- [Insert Delete GetRandom O(1)](#ques)
- Approach unordered_set+vector
  - [Logic](#logic)
  - [Complexity](#comp)
  - Code
    - [C++](#cpp)
    - [Rust](#rust)

## [RandomizedSet](https://leetcode.com/problems/insert-delete-getrandom-o1/)
- Implement the RandomizedSet class:
  - RandomizedSet() Initializes the RandomizedSet object.
  - bool insert(int val): Inserts val into the set if not present. Returns true if the item was not present, false otherwise.
  - bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
  - int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

## Approach unordered_set+vector
<a name=logic></a>
### Logic
- insert(): can be carried in O(1)
- getRandom(): 
  - _Problem_: getRandom() cannot be carried in O(1) in hashset or hashmap, because we need to know what elements are present in hash before we can get random and that will take O(n)
  - _Solution:_
    - Use vector to store indexes of elements present in unordered_map
    - Unordered_map<key=element, value=index_inside_vector_storing_the_element>
    - Using this we can do getRandom() in vector in O(1) time
```c
4,9,1,5
  unordered_map 
    key=element              5      4     1      9
    ----------------------|------|-----|------|----
    value=index_in_vector    3      0     2     1
  
vector <int>
    element   4    9    1    5
    --------|---|----|----|-----|
    index     0    1    2    3
```
- remove(ele): Eg: remove(9)
  - _1._ Search `<key,value>` in map. Found `<key=9,val=1>`
  - _2._ Goto index=val=1 in vector.
    - _2a._ copy last element to present element and pop_back in vector.
    - _2b._ Remove element from unordered_map and Update mapping.
```c
After copy, vector:
    element   4    5    1    5
    --------|---|----|----|-----|
    index     0    1    2    3

After pop_back, vector:                   //2a
    element   4    5    1  
    --------|---|----|----|
    index     0    1    2  

Update, unoredered_map:
    key=element              5      4     1     //2b
    ----------------------|------|-----|------|
    value=index_in_vector    1      0     2    
```
<a name=comp></a>
#### Complexity
- **Time:** Insert,Delete,getRandom: O(1)
- **Space:** O(2n)

#### Code
<a name=cpp></a>
```cpp
//RandomizedSet.cpp
class RandomizedSet {
public:
    RandomizedSet():seed((random_device())()) {}

    bool insert(int val) {
      if (um.find(val) != um.end())
        return false;

      vec.emplace_back(val);
      um[val] = vec.size()-1;
      return true;
    }

    bool remove(int val) {
      if (!um.count(val))       //if val not present return false
        return false;

      vec[um[val]] = vec.back();
      um[vec.back()] = um[val];
      vec.pop_back();
      um.erase(val);
      return true;
    }

    int getRandom() {
  //rand() is considered harmful
  //https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
  //    return vec[rand()%vec.size()];
  
      return vec[uniform_int_distribution<>(0, vec.size()-1)(seed)];
    }
private:
                //element, index
  unordered_map<int, int> um;
  vector<int> vec;
  default_random_engine seed;
};

//main.cpp
#include"RandomizedSet.cpp"
#include <gtest/gtest.h>
TEST(Random, case1) {
  {
             //(Expected_Output, function call)
    RandomizedSet obj;
    EXPECT_EQ(true, obj.insert(1));
    EXPECT_EQ(false, obj.remove(2));
    EXPECT_EQ(true, obj.insert(2));
    EXPECT_EQ(1, obj.getRandom());
    EXPECT_EQ(true, obj.remove(1));
    EXPECT_EQ(false, obj.insert(2));
    EXPECT_EQ(2, obj.getRandom());
    EXPECT_EQ(2, obj.getRandom());
  }
};  
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//CMakeLists.txt
cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
```
