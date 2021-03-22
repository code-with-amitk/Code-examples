## Create
#### A. int, string, double to String
- **1. Using stringstream**
```c++
#include<sstream>
int main(){
  stringstream ss;  int a=4;   string b="fail";   char c='e';
  ss<<a<<b<<c;
  cout<<ssc.str()<<endl;  //4faile
}
```

#### B. `vector<int>` from string
  - **1. Using stringstream**
```c++
vector<int> v;
string s = "Hello 444";
stringstream ss(s.substr(s.rfind(" ") + 1));      //ss=444
int a;
ss>>std::hex>>a;                                  //a=Hex of 444
v.push_back(a);
```

## Convert
#### A. char to int
```c++
  int a = static_cast<int>(char) - 48;
```
#### B. String to int
**1. istringstream**
```c++
  string a ="12";
  uint64_t val;
  istringstream(a) >> hex >> val;
  cout<<hex<<val;                     //12
```
**2. Stringstream**
```c++
  string str = "4", str1 = "5";
  int a;  
  stringstream ss (str);  
  ss >> a;
  cout << a << "\n";                  //4

  ss.clear(); ss.str(str1);           //Resuing stringstream
  ss >> a;
  cout << a << "\n";                  //5
```

||string|
|---|---|
|int(4 byte)|<ul><li>int stoi()</li></ul>|
|long(8 byte)|<ul><li>long stol()</li></ul>|
|long long(8 byte)|<ul><li>long long stoll()</li></ul>|
|float(4 byte)|<ul><li>float stof()</li></ul>|
|double(8 byte)|<ul><li>double stod()</li></ul>|
