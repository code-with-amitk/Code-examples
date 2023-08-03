- Sort
  - [Lexiographical](#lex)
- [Substring](#sub)
- **Tokenize**
  - One Delimiter
    - [stringstream](#ss)
    - [boost::tokenizer](#bt)
  - Multiple Delimiters
    - [strtok](#strt)
- [Traversal. Forward, Reverse](#tra)

||C++|Rust|Python|
|---|---|---|---|
|Append|s1.append(s2)|||
|Compare|s1.compare(s2)|||
|Convert|<ul><li>**Lowercase** `transform(sl.begin(), sl.end(), sl.begin(), ::tolower)`</li> <br> <li>**int,double to str** `int a=4; stringstream ss; ss<<a; cout<<ss.str()`</li> <br> <li>**string to int** `string str="ab"; int i; istringstream(str)>>i;`</li> <br> <li>**string to int** `string str="ab"; int i; stringstream(str)>>i;`</li> </ul>|||
|Erase|<ul><li>**substring** `s.erase(3, s.size()-1)`</li> <br> </ul>|||
|Find|<ul><li>**substring** `(index = s1.find(s2)) != string::npos)`</li> <br> </ul>|||
|Size|<ul><li>**str.length()** Inbuilt in str class</li> <br> <li>**str.size()** To make consistent with other STL container</li></ul>|||
|substr|str.substr(pos=0, length=n)|||


<a name=ss2></a>
#### B. String to `vector<int>`
```c++
///Using stringstream
vector<int> v;
string s = "Hello 444";
stringstream ss(s.substr(s.rfind(" ") + 1));      //ss=444
int a;
ss>>std::hex>>a;                                  //a=Hex of 444
v.push_back(a);
```

### Sort
<a name=lex></a>
#### [Lexiographical](/DS_Questions/Questions/Strings/Lexicographical)
```c
int main() {
    string s = "I love CS3233 Competitive \
Programming. i also love kk zz aza za \
AlGoRiThM";
    string delimiters = "- .";
    vector<string> o = tokenize(s,delimiters);    //Defined in strtok (/DS_Questions/Questions/Strings/OPERATIONS#strt)
    sort(o.begin(), o.end());
    for (auto i:o) {
        cout << i << " ";
    }
}
# ./a.out
algorithm also aza competitive cs3233 i i kk love love programming za zz
```

## Tokenize
### Delimiter=1
<a name=ss></a>
#### stringstream
*1. Read input from keyboard. Tokenize for " ", create string*
```cpp
#include<sstream>
int main(){
  string s = "never give up";
  //OR
  //getline(cin, s);                  //Read from stdin. getline() is part of header<string> and reads space seperated input string.
  string temp_str;
  stringstream ss(s);                             //Fed string to ss constructor
  while(getline(ss, temp_str, ' ')){              //Space tokenization
    cout<<temp_str<<" ";
    temp_str=temp_str+" ";
    cout<<endl;
  }
  
  /*O/P:
  never
  give
  up */
```
<a name=bt></a>
#### boost::tokenizer
```cpp
Code-examples/Languages/programming_lang/c++/boost/Libraries/Tokenizer/Examples/1.string-from-stdin.md
```

<a name=rep></a>
## string.replace(position, length, string-to-replace-with)
Replace a character in string with some other character
```c
//REPLACE: replace "." with "[.]"

  string s = "1.1.1.1";
  for(auto i=0;i<s.size();i++){
    if(s[i]=='.'){
      s.replace(i,1,"[.]");
        i=i+3;
    }
  }
  
  cout<<s<<endl;                                        //1[.]1[.]1[.]1
```

### Delimiters=2 or more
<a name=strt></a>
#### strtok
```cpp
char *strtok(char *str, const char *delim)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string convert_char_to_string(char* token){
    string temp = token;
    if (temp.size())
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    return temp;
}
vector<string> tokenize(string s, string delimiters){
   char *str = (char*)input.c_str();        //Convert string to char*
   const char *delim = delimiters.c_str();  //Convert string to const char*

   char *token;
   vector<string> out;                        //Store tokens
   token = strtok(str, delim);
   out.push_back(convert_char_to_string(token));     //Convert char* to string
   while( token != NULL ) {
      token = strtok(NULL, delim);
      if (token)
        out.push_back(convert_char_to_string(token));
   }
   return out;
}
int main() {
    string s = "I love CS3233 Competitive Programming. i also love AlGoRiThM";
    string delimiters = "- .";                      //Tokenize on - . " "
    vector<string> o = tokenize(s, delimiters);
    for (auto& i: o)
      cout << i << " ";
}
```

<a name=tra></a>
## Traversal
```cpp
#include<sstream>
int main(){

  string str = "Fail early fail often";
  
  for (auto i=str.begin(); i!=str.end(); i++)       //Forward iterator
    cout<<*i;
  
  for (auto i=str.rbegin(); i!=str.rend(); i++)    //Reverse iterator     
    cout<<*i;
}

/*O/P:
Fail early fail often
netfo liaf ylrae liaF */
```


