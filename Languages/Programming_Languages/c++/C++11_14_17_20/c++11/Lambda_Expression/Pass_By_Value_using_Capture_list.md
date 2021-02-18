## PASS BY VALUE `[ = ]`
- **What?** Means passing outside variables into lambda using capture list. Pass by value variable are RO, cannot be modified lambda.

### Examples
- **1. Passing 1 outside variable to lambda**
```c++
  int i = 1;
  auto p =  [ i ]  (int a, int b)  ->  int {  return a + b + i;   };
  cout << p(2,3) << endl;            //6
```  

- **2. Passing all outside variables to lambda**
```c++
  int i = 1, j = 2;
  auto p =  [ = ]  (int a, int b)  ->  int {  return a + b + i + j;   };
  cout << p(3,4) << endl;            //10
```  

- **3. Outside Variable cannot be modified in lambda**
```c++
  int i = 1;
  auto p =  [ = ]  (int a, int b) -> int { i = 6;  return a + b + i;   };   //Compilation error: assignment of read-only variable ‘i’
  cout << p4(2,3) << endl;
```  
