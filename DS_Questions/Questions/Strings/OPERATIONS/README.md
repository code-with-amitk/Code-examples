- [Append](#ap)
- **Compare**
  - [compare()](#co1)
- **Create / Convert**
  - [A. int, double to string using stringstream](#ss1)
  - [B. String to `vector<int>` using stringstream](#ss2)
  - [C. String to int istringstream, stringstream](#ss3)
  - [D. Convert to lowercase](#con)
- [Erase](#er)
- [Find](#f)
- [insert](#in)
- [Replace](#rep)
- [size](#sz)
- [Substring](#sub)
- **Tokenize**
  - [stringstream](#ss)
  - [boost::tokenizer](#bt)
- [Traversal. Forward, Reverse](#tra)


<a name=ap></a>
## string& Append (const string& str);
```c++
  string s1="Ram ";
  string s2="Shyam";
  s1.append(s2);          //Ram Shyam
```

## Create
<a name=ss1></a>
#### A. int, double to string
```cpp
///Using stringstream
#include<sstream>
int main(){
  stringstream ss;  
  int a=4;   string b="fail";   char c='e';
  ss<<a<<b<<c;
  cout<<ssc.str()<<endl;  //4faile
}
```
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
<a name=ss3></a>
#### C. String to int
```c++
////1. istringstream////////
  string a ="12";
  uint64_t val;
  istringstream(a) >> dec >> val;
  cout<<hex<<val;                     //12
  
////2. Stringstream/////////
  string str = "4", str1 = "5";
  int a;  
  stringstream ss (str);  
  ss >> a;
  cout << a << "\n";                  //4

  ss.clear(); ss.str(str1);           //Resuing stringstream
  ss >> a;
  cout << a << "\n";                  //5
```
<a name=con></a>
#### D. String to lowercase
```c
  string sl = "Amit Kumar";
  
  transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
```

## Compare
<a name=co1></a>
#### A. int s1.compare(s2)
```cpp
  string s1 = "abc";
  string pat = "abe";
  
  if(!s1.compare(s2))
    cout<<"s1";          //s1
  else
    cout<<"s2";

compare returns:        
  0: if both strings are equal.
  value < 0 : if s1 is shorter than s2 or,first character that doesn't match is smaller than s2.
  value > 0 : if s1 is longer than str or,first character that doesn't match is greater
```

<a name=er></a>
## erase(starting_pos, length)
Erases portion of string, reducing its length
```cpp
  string s="Hunger for Success";
  
  s.erase(0, 7);                                      //Erase from index=0 to index=7
  cout<<s<<", size="<<s.size()<<endl;                 //for success, size=11
  
  s.erase(3, s.size()-1);                             //Erase from index=3 to end
  cout<<s<<", size="<<s.size()<<endl;                 //for, size=3
```

<a name=f></a>
## find()
Returns 0th index of character/substring if found, else string::npos
```cpp
  int index = -1;
  string str1 = "Failing Reveals your weaknesses!";
  if ((index = str1.find("your")) != string::npos)
    cout << index;
    
  O/P: 16
```

<a name=ins></a>
## insert(position, string)
Inserts additional characters into the string right before the character indicated by pos.
```cpp
  string s = "your ass out";
  s.insert(0, "work ");                 
  
  cout<<s<<endl;           //work your ass out
```

<a name=sz></a>
## Size Of String
#### str.length() & str.size()
```c
           | str.length()                       | str.size()
-----------|------------------------------------|-------------------
    What   | Returns no of characters in string | same
    Why    | inbuilt for string class           | To make consistent with other STL container
Complexity |      O(1)                          | O(1)
> Both are same anyone can be used.
```
**Code**
```c++
  string st = "LoveWork";
  cout<<st.size()<<endl;          //8
  cout<<st.length()<<endl;        //8
```


<a name=sub></a>
## str.substr(pos, length)
- pos: start position of the substring 
- len: number of characters in a substring
```c++
  std::string a = "Hello T11";
                 //012345678
  std::cout << a.substr(1, 2); //From pos=1, Len=2
  
//O/p: el
```

## Tokenize
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


