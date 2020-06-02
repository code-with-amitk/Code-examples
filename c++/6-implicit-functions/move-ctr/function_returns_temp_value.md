## Function call returns a Temporary Value in rax register
- Temporary value is R value
- Copying object using R-value calls move ctr.

### Example-1        
```
#include<iostream>
#include<vector>
using namespace std;

class A{
        int a;
public:
        A(int b):a(b)
        {
                cout<<"Default ctr\n";
        }
        A(A &k){
                cout<<"copy ctr\n";
                a = k.a;
        }
        A(A &&k) noexcept{
                a = move(k.a);
                cout<<"move ctr\n";
        }
};
A fun(A o)
{
        return o;
}

int main(){
    A obj2 = fun(A(1));
}
/*
Output:
# ./a.out 
Default ctr
move ctr
*/

/*ASSEMBLY
A::A(A&&):
        call    std::remove_reference<int&>::type&& std::move<int&>(int&)
        
fun(A):
        call    A::A(A&&)
        
main:
        call    A::A(int)                     //A(1)
        call    fun(A)                        //fun(A(1))
*/
```


### Example-2
```
#include<iostream>
#include<vector>
using namespace std;

class A{
        int a;
public:
        A(int b):a(b)
        {
                cout<<"Default ctr\n";
        }
        A(A &k){
                cout<<"copy ctr\n";
                a = k.a;
        }
        A(A &&k) noexcept{
                a = move(k.a);
                cout<<"move ctr\n";
        }
};

//Note (A o) calls copy ctr because Copying Object using L value
A fun(A o)      
{
        return o;
}
int main(){
        A obj1(1);

        //obj1 is created ie its L value
        A obj3 = fun(obj1);       //Equal to calls move ctr
}
/*
Output:
# ./a.out 
Default ctr
copy ctr
move ctr
*/

/*ASSEMBLY
A::A(A&&):
        call    std::remove_reference<int&>::type&& std::move<int&>(int&)
        
A::A(A&):
        call    basic_ostream<char, char_traits<char> >& operator<< <char_traits<char> >
                (basic_ostream<char, char_traits<char> >&, char const*)
        
fun(A):
        call    A::A(A&&)
        
main:
        call    A::A(int)                     //A obj1(1);
        call    A::A(A&)                      //fun(A o) = fun(obj1).Passing L-value and hence copy ctr called
        call    fun(A)        
        
```
