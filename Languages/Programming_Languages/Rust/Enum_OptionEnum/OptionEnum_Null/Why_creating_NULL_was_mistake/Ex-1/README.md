## NULL References when derefrenced will cause crash
- **C/C++ crashing code**
```c++
int fun(struct A*& p){              //Funtion taking NULL reference
  if (p == nullptr)
    cout<<"Got Null ptr reference\n";
  cout << p->a;
}

int main(){
  struct A* p = nullptr;
  fun(p);
}

$ ./a.out
Got Null ptr reference
Segmentation Fault
```
- **How Rust avoid it?**
  - _1._ Whichever variable can have NULL or other value, Rust asks to declare it as [Option`<T>`]()
  - _2._ Rust does not allow creating structure object without initializing its members.
    - It can be initialized with Some or None. This is how rust avoids NULL crashes.
```rust
fn fun(obj:&A){
    println!("a:{:#?}",obj.a);
}
struct A{
    a:Option<i32>,              //1
}
fn main() {
    let obj = A{
        a:None                  //2
    };
    fun(&obj);
}
```
