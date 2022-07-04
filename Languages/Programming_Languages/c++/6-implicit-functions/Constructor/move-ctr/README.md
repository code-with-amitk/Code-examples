**Move Ctr**
- [Syntax](#s)
- Code
  - [User created Move ctr](#c1)
  - [Moving vector using std::move()](#c2)

## Move Ctr
- same named function of class A, Takes non-const R-value reference as parameter.
- Internally implemented as:
  - memmove() For union-type(https://en.cppreference.com/w/cpp/language/union)
  - For non-union type(eg: class,struct):  Does full member-wise move of the object's members.
```c    
  void* memmove( void* dest, const void* src, std::size_t count );
```    
- **WHEN MOVE CTR IS CALLED?** object is initialized (by direct-initialization or copy-initialization) from rvalue
- **WHEN MOVE CTR IS NEVER CALLED?** When the initializer is a prvalue. see copy elision.  
- **THINGS TO CONSIDER?**  After move original object can be empty, But c++ standards says this should not be relied upon.

<a name=s></a>
### Syntax
```cpp
- 1st parameter is T&& or const T&& or volatile T&& or const volatile T&&, 
- either there are no other parameters, or the rest of the parameters all have default values.
   
  class_name ( class_name && )
  class_name ( class_name && ) = default; 
  class_name ( class_name && ) = delete;
```

### Code
<a name=c1></a>
#### 1. User created Move ctr
```cpp
struct A{
        string a;
        A() : a("test"){}
        A(A& k):a(k.a){
          cout<<"move failed";
        }

        /*Why noexcept is required in move Constructor?
        noexcept will prevent exceptions when source object is left in unknown 
        state after move.
        Compiler will ignore move ctr, if exception happened and noexcept is preceded.
        */
        A(A &&k) noexcept: a(move(k.a)){}
};

int main(){
        A obj1 = A();                           //Called default ctr
        cout<<"obj1.a = "<<obj1.a<<"\n";        //obj1.a = test

        /*C++ provides a template function std::move(), which 
        tells compiler to move value from src to dst if its R-VALUE.
        You must be thinking, obj1 is lvalue then how this qualifies as r-value?
        std::move() just takes Reference and casts as rvalue reference.
        Internally,        move(obj1) = (A &&) v1;
        */        
        A obj2 = move(obj1);

        //quoted() just puts quotes around output
        cout<<"obj1.a = "<<quoted(obj1.a)<<"\n";        //obj1.a = ""
        cout<<"obj2.a = "<<quoted(obj2.a)<<"\n";        //obj2.a = "test"
}
```
<a name=c2></a>
#### 2. Moving vector using std::move()
```cpp
void disp(vector<string> &v){
    if(!v.size())
            cout<<"Empty";
  
    for (auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main() {

    vector<string> v1 = {"one", "two", "three"};

    /*You must be thinking, v1 is lvalue then how this qualifies as r-value?
    std::move() just takes Reference and casts as rvalue reference.
    move(v1) = (vector<string> &&) v1;
    
    Advantage of using move() here is it will sure shot create r value reference,
    once compiler sees its R value ref, It will sure shot call move ctr.
    */
    auto v2 = move(v1);
    disp(v1);
    disp(v2);
    return 0;
}
/*Output:
# ./a.out 
Empty
one two three
*/
```
