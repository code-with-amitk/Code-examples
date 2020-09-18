## Create
- **A. String from int, string, double**
  - **1. Using stringstream**
```c++
#include<sstream>
int main(){
  stringstream ss;  int a=4;   string b="fail";   char c='e';
  ss<<a<<b<<c;
  cout<<ssc.str()<<endl;  //4faile
}
```

- **B. `vector<int>` from stringstream**
```c++
vector<int> v;
string s = "Hello 444";
stringstream ss(s.substr(s.rfind(" ") + 1));      //ss=444
int a;
ss>>std::hex>>a;                                  //a=Hex of 444
v.push_back(a);
```
