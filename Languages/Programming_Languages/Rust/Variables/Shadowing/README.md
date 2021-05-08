## Shadowing a Variable
- **What?** Shadowing means Again declaring the variable with same name and new variable shadows the previous variable, even new type can be assigned.
```rust
fn main() {
    let x = 5;
    let x = x + 1;                  //Shadowing x. Is it possible in C/C++? No
    let x = x * 2;
    println!("The value of x is: {}", x);   //Output:12
    
    let spaces = "   ";           //Type:string
    let spaces = spaces.len();    //Type:Len
}

//C++
int main(){
  int a = 5;
  int a = a+1;    //Compliation Error, redeclaration
}
```
- **Why?**
  - *1.* We need not to declare new variable(of new type), we can use old variable. As seen above in `spaces`. if this was not the case we have to use something as:
```rust
  let spaces_str = "    ";
  let spaces_num = spaces_str.len();
```
