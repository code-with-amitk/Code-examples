## Pass by Reference(&) RW
- **What?** Means passing outside variables into lambda. Variables passed can be modified inside lambda.
- **1. Passing 1 outside variable inside lambda**
  - This variable can be changed inside lambda.
```c++
  int i = 1;
  auto p = [ &i ] (int a, int b)  ->  int { i = 5;  return a + b + i; };
  cout << p(2,3) << endl;            //10
```

- **2. Passing all outside variables to lambda**
```c++
  int i = 1, j = 2;
  auto p = [ & ] (int a, int b)  ->  int { return a + b + i + j; };
  cout << p(3,4);    //10
```
