## Creating
- Create string from int, string, double

```
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){

  stringstream ssc;
  int a=4; 
  string b="fail"; 
  char c='e';
  
  ssc<<a<<b<<c;
  
  cout<<ssc.str()<<endl;
}  
  /*O/P:
  4faile */
```
