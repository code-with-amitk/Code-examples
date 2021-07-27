- [Max Area 2](#ques)
- Approach-1, Sort
  - [Logic](#logic1)
  - [Complexity](#comp1)
  - Code
    - [C++](#cpp1)

<a name=ques></a>
## [Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)
- You are given a rectangular cake of size height x width and two arrays of integers horizontalCuts and verticalCuts where:
  - `horizontalCuts[i]` is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
  - `verticalCuts[j]` is the distance from the left of the rectangular cake to the jth vertical cut.
- Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 10<sup>9</sup> + 7.
- Examples
```c
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts.
After you cut the cake, the green piece of cake has the maximum area.
```
<img src=leetcode_max_area_2.png width=200/>

## Approach-1, Sort
<a name=logic1></a>
### Logic
- _1._ sort horizontal_cuts and vertical_cuts arrays.
- _2._ Find maximum horizontal cut, by calculating the difference of adjacent horizontal cuts.
```c
total height=5, cuts at=1,2,4
         0 <---> 1 <---> 2 <---> 4 <---> 5
hori cuts    1      1       2       1               //Max horizontal cut=2
```
- _3._ Find maximum vetical cut, by calculating the difference of adjacent vertical cuts.
```c
total height=4, cuts at=1,3
         0 <---> 1 <---> 3 <---> 4
vert cuts    1       2       1                       //Max vertical cut=2
```
- _4._ Max area = max_hori_cut `*` max_vert_cut

<a name=comp1></a>
### Complexity
- **Time:** O(nlogn) + O(mlogm)
  - n=horizontal cuts. sort:O(nlogn), Traverse all cuts:O(n)
  - m=vertical cuts. sort:O(mlogm), Traverse all cuts:O(m)
- **Space:** O(1)
### Code
<a name=cpp1></a>
```cpp
//max_height.cpp
using vecI = vector<int>;
class Solution {
public:
  int maxArea(int h, int w, vecI& horizontal_cuts, vecI& vertical_cuts) {
    sort(horizontal_cuts.begin(), horizontal_cuts.end());                     //1
    sort(vertical_cuts.begin(), vertical_cuts.end());

    long max_hori_cut = max(horizontal_cuts[0], numeric_limits<int>::min());      //2

    for (int i=0;i<horizontal_cuts.size()-1; ++i)
      max_hori_cut = max(long(horizontal_cuts[i+1]-horizontal_cuts[i]), max_hori_cut);  //2
    max_hori_cut = max(long(h-horizontal_cuts.back()), max_hori_cut);

    long max_vert_cut = max(vertical_cuts[0], numeric_limits<int>::min());

    for (int i=0;i<vertical_cuts.size()-1; ++i)
      max_vert_cut = max(long(vertical_cuts[i+1]-vertical_cuts[i]), max_vert_cut);
    max_vert_cut = max(long(w-vertical_cuts.back()), max_vert_cut);

    return max_hori_cut%1000000007 * max_vert_cut%1000000007;
  }
};

#include"max_height.cpp"
#include <gtest/gtest.h>

TEST(Collision, case1) {
  using vecI = vector<int>;
  Solution s;
         //(Expected_Output, function call)
  int h=5, w=4;
  vecI hc = {1,2,4}, vc={1,3};
  EXPECT_EQ(4, s.maxArea(h,w,hc,vc));

  h=5,w=4;
  hc = {3,1}, vc={1};
  EXPECT_EQ(6, s.maxArea(h,w,hc,vc));

  h=5,w=4;
  hc = {3}, vc={3};
  EXPECT_EQ(9, s.maxArea(h,w,hc,vc));

  h=1000000000, w=1000000000;
  hc={2}, vc={2};
  EXPECT_EQ(81, s.maxArea(h,w,hc,vc));
}

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

$ cmake .
$ make
$ ./runtests
```
