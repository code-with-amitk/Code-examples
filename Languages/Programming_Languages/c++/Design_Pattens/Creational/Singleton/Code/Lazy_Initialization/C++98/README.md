## C++98 Code

```c++
class A{
        A(){}
        A(A &){}
        void operator = (const A&){}
        static A *ptr;
public:
        static A *fun(){
                if(ptr == NULL)
                        ptr = new A();
                return ptr;
        }
};
A *A::ptr = nullptr;
int main(){
//      A obj1;         //Error:error: ‘A::A()’ is private within this context
        A *p1 = A::fun();			//4
        cout<<p1<<endl;

        A *p2 = A::fun();
        cout<<p2<<endl;
}
# ./a.out
0x1ec5e70
```
