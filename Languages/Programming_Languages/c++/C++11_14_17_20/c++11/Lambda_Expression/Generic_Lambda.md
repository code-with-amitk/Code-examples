## Generic Lambda(C++14)
- Now lambda can be made Generic, for example auto can be used inside lambda. Earlier this use to give error.
```c++
  auto ptr = [](auto x, auto y){ return x+y; };
  string a = "Never", b = "GiveUp";
  
  cout << ptr(1,2) << endl;                            //3
  cout << ptr(a,b) << endl;                            //NeverGiveUp   
```
