## String from int, string, double
### 1. stringstream
- `>>` is input stream object.
```
#include<sstream>
int main(){
  stringstream ss;  int a=4;   string b="fail";   char c='e';
  ss<<a<<b<<c;
  cout<<ssc.str()<<endl;  //4faile
}
```

## Creating vector from stringstream
- `<<` is output stream object.
```
vector<int> v;
string s = "Hello 444";
stringstream ss(s.substr(s.rfind(" ") + 1));      //ss=444
int a;
ss>>std::hex>>a;                                  //a=Hex of 444
v.push_back(a);
```
