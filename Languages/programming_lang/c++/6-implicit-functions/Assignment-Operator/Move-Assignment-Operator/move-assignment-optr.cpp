/*	move-assignment-operator.cpp
WHAT?
   - Function having name operator= 
   - This moves the object not leaving 2 copies.

WHEN ITS CALLED?
   - when an object appears on the left-hand side of an assignment expression, where the right-hand side is an rvalue of same type.

COMPILER PROVIDES MOVE ASSIGNMENT OPERATOR WHEN?   
        1. there are no user-declared copy constructors;
        2. there are no user-declared move constructors;
        3. there are no user-declared copy assignment operators;
        4. there are no user-declared destructors;
   
PARAMETERS?
   - 1st parameter is T&& or const T&& or volatile T&& or const volatile T&&,
   - either there are no other parameters, or the rest of the parameters all have default values.

SYNTAX?
        class_name & class_name :: operator= ( class_name && )
        class_name & class_name :: operator= ( class_name && ) = default;
        class_name & class_name :: operator= ( class_name && ) = delete;

FORCING COMPLIER TO CREATE DEFAULT MOVE ASSIGNMENT OPERATOR
        class_name & class_name :: operator= ( class_name && ) = default;
*/

/********USER DEFINED MOVE ASSIGNMENT OPERATOR************/
struct A
{
        int a;
        A() : a(2){}    
        A& operator=(A&& k) {
                a = move(k.a);
                k.a=0;
                return *this;
        }
};
int main()
{
        A obj1, obj2;
        cout<<"obj1.a="<<obj1.a<<endl;
        obj2 = move(obj1);
        cout<<"obj1.a="<<obj1.a<<endl;
        cout<<"obj2.a="<<obj2.a<<endl;
}

