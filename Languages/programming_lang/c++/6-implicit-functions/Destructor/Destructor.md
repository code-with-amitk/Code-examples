## Forcing compiler to generate destructor
- decl-specifier-seq(optional) ~ class_name () = default;

## User defined dtr
```c
struct A {
  int *p;
  A():p(new int){
    *p=2;
    cout<<"ctr\n";
  }
  ~A(){cout<<"dtr\n";}
};
int main(){
  {
    A obj;
  }
  cout<<"Out of scope\n";
}
/*O/P:
ctr
dtr
Out of scope
*/
```
