## Traversal
- Forward, Reverse

```
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){

  string str = "Fail early fail often";
  
  for (auto i=str.begin(); i!=str.end(); i++)       //Forward iterator
    cout<<*i;
  cout<<endl;
  
  for (auto i=str.rbegin(); i!=str.rend(); i++)    //Reverse iterator     
    cout<<*i;
  cout<<endl;
}

/*O/P:
Fail early fail often
netfo liaf ylrae liaF */
```
