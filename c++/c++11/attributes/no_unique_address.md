## `[[no_unique_address]] C++20`
  - Can only be applied to `non-static` data member of class/struct.
  - Indicates that this data member need not have an seperate address from all other non-static data members of its class.
  - But its implementation/compiler dependent not guranteed.
    - For example: if member is `Empty type` compiler may optimize to occupy NO SPACE(same as in empty base).
```
struct inner {};
class A{
  int var;
  [[no_unique_address]] inner i1,i2;
public:
  void f(){
    cout<<"i1="<<addressof(i1)<<"\n";
    cout<<"i2="<<addressof(i2)<<"\n";
  }
};

int main(){
  A a;
  a.f();
}
```
    
