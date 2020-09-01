## Function Templates
- Template is compiler abstraction.
- Compiler creates the specialization for each type at compile time. Means Seperate specializations(overloaded functions) for:
  - long int, short int, int, double, string
- Specialization
  - Benefits: Makes code type-safe.    
  - Drawbacks: increases sizeof object file
```c++
//At compile time, compiler creates 2 overloaded versions of maxof function.
//maxof(int a, int b){ }
//maxof(const char*, const char*){  }
   
template <class T>
T maxof(T a, T b) {
  return (a>b)?a:b;
}

int main() {
 cout << maxof(4,5) <<endl;                 //Calls as maxof<int> (4,5)
 //cout << maxof(5,7.8) <<endl;             //error: no matching function for call to ‘maximum(int, double)’
 cout << maxof("hellome","hello") <<endl;   //hellome.  calls as maxof<const char*>("hellome", "hello")
}
```
