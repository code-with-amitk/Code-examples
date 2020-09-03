### Problem
- Implement variadic function template that adds all arguments passed to it.

#### Code (How it works internally)
- Everything is resolved at compile time.
- **Parameter Pack**
  - Vals is template parameter pack
  - vals is function parameter pack
- Varidic templates are written as recursive code, generic case which recurses and base case.
- 
```c++
template < typename T >
T add ( T v ) {
  return v;
}

template < typename T, typename... Vals >
T add ( T first, Vals... vals ) {
  cout << __PRETTY_FUNCTION__ << "\n";                      //Verbose output
  return first + adder ( vals... );
}

int main() {
  cout<<add(1, 2, 3, 4, 5);     //15
  
  std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
  cout<<adder(s1, s2, s3, s4);                          //xaabbyy
}

////////////////At compile time compiler changes as follows/////////////////
adder<int> (v=5){                           //fun-5
  return 5
}
adder<int, int> (first=4){                    //fun-4 //4,5
  4 + fun-5
}
adder<int, int, int> (first=3){              //fun-3  //3,4,5
  3 + fun-4
}
adder<int, int, int, int> (first=2){         //fun-2  //2,3,4,5
  2 + fun-3
}
adder<int, int, int, int, int> (first=1){    //1,2,3,4,5
  1 + fun-2
}

```
