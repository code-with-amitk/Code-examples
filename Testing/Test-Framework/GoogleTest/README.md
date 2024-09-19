- [What is GoogleTest / gtest](#what)
- [Installation](#install)
  - [1. Ubuntu](#ubuntu)
  - [1. CentOS/Fedora/RedHat](#centos)
- [Using gtest](#using)
  - [1. Testcases for class](#class)

<a name=what></a>
## [GoogleTest / gtest](https://github.com/google/googletest)
- This is unit testing library for the C++ programming language.

<a name=install></a>
## Install

<a name=ubuntu></a>
#### 1. Ubuntu
```c
# sudo apt-get install libgtest-dev               //1. Install gtest source files
# sudo apt-get install cmake

# cd /usr/src/gtest                               //2. Go to directory where source is installed and make it
# sudo cmake CMakeLists.txt; sudo make

# sudo cp *.a /usr/lib                            //3. copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
```
<a name=centos></a>
#### 2. CentOS/Fedora/RedHat
```c++
# yum install gtest -y
```

<a name=using></a>
## Using Googletest

<a name=class></a>
#### 1. Testcases for class
```c++
class A{                              //test.cpp
public:
  int fun(int a, int b) {
    return a/b;
  }
};

# vim main.cpp
#include "test.cpp"
#include <gtest/gtest.h>

TEST(DivideTest, TestCase1) {
  Solution obj;
         //(Expected_Output, function call)
  ASSERT_EQ(5, obj.fun(100,2));                         //Function returning int

  vector<int> input       = {5,10,-5};
  vector<int> ExpectedOut = {5,10};
  vector<int> ActualOut   = obj.asteroidCollision(v);   //Function taking vector and returning vector
  for (int i=0; i < ExpecedtOut.size(); ++i){
    EXPECT_EQ (ActualOut[i], ExpectedOut[i]);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

# vim CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
project(runTests)

# Enable testing with GoogleTest
enable_testing()

# Find gtest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Find and link threading library
find_package(Threads REQUIRED)

# Add the test executable
add_executable(runTests main.cpp)

# Link libraries (GTest and Threads)
target_link_libraries(runTests ${GTEST_LIBRARIES} Threads::Threads)
```
- **Compile and Run tests**
```c++
# cmake CMakeLists.txt
# make
# ./runtests
```c++
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from DivideTest
[ RUN      ] DivideTest.TestCase1
[       OK ] DivideTest.TestCase1 (0 ms)
[----------] 1 test from DivideTest (4 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (24 ms total)
[  PASSED  ] 1 test.
```
