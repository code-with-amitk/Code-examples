/*	move-constructor.cpp
WHAT? 
  - same named function of class A
  - Takes non-const R-value reference as parameter
  - Internally implemented as:
    - For union-type(https://en.cppreference.com/w/cpp/language/union) as std::memmove()
        void* memmove( void* dest, const void* src, std::size_t count );
    - For non-union type(eg: class,struct) 
        Does full member-wise move of the object's members.

WHEN MOVE CTR IS CALLED?
  - object is initialized (by direct-initialization or copy-initialization) from rvalue

WHEN MOVE CTR IS NEVER CALLED?
 - When the initializer is a prvalue. see copy elision.  

THINGS TO CONSIDER?
 - After move original object can be empty, But c++ standards says this should not be relied upon.
 - 

PARAMETERS?   
   - 1st parameter is T&& or const T&& or volatile T&& or const volatile T&&, 
   - either there are no other parameters, or the rest of the parameters all have default values.

SYNTAX?
        class_name ( class_name && )
        class_name ( class_name && ) = default; 
        class_name ( class_name && ) = delete;

FORCING COMPLIER TO CREATE DEFAULT ASSIGNMENT OPERATOR
        class_name ( class_name && ) = default;

*/

//COMPLIER PROVIDED MOVE CTR


/*************USER CREATED MOVE CTR*****************/
struct A{
        string a;
        A() : a("test"){}
        A(A& k):a(k.a){cout<<"move failed";}
        A(A &&k) noexcept: a(move(k.a)){}
};

int main(){
        A obj1 = A();                           //Called default ctr
        cout<<"obj1.a = "<<obj1.a<<"\n";        //obj1.a = test

        A obj2 = move(obj1);

        cout<<"obj1.a = "<<quoted(obj1.a)<<"\n";        //obj1.a = ""
        cout<<"obj2.a = "<<quoted(obj2.a)<<"\n";        //obj2.a = "test"
}
//quoted() just puts quotes around output

