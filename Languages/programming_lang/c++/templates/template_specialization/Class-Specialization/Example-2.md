## [Hacker-rank-problem](https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem)
- Read enumeration values for two different types as input. then prints out the corresponding enumeration names. Write a class template that can provide the names of the enumeration values for both types. If the enumeration value is not valid, then print unknown
- Example
```c++
Input:
2
1 0
3 3

Output:
green apple
unknown unknown
```

```c++
string aFruit[4]={"apple","orange","pear","unknown"};
string aColor[4]={"red","green","orange","unknown"};

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <>
struct A<Color>{
  static string name (int a){
    if(a>3 || a<0)
      return aColor[3];
    else
      return aColor[a];
  }
};

template <>
struct A<Fruit>{
  static string name (int a){
    if(a>3)
      return aFruit[3];
    else
      return aFruit[a];
  }
};

int main(){
  cout << A<Color>::name(index1) << " ";
  cout << A<Fruit>::name(index2) << "\n";  
}
```
