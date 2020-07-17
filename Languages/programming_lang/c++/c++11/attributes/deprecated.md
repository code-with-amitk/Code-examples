## `[[deprecated]]C++14  [[deprecated("reason")]](C++14)`
  - The use of the name or entity declared with this attribute is allowed, but discouraged for some reason.
```
[[deprecated("Use addTemplated(int,int) instead")]]
int add(int a, int b){return a+b;}
int main(){
        cout<<add(1,2);
}
# g++ test.cpp                //Gets complied but with warning
    : warning: ‘int add(int, int)’ is deprecated: Use addTemplated(int,int) instead [-Wdeprecated-declarations]
```
