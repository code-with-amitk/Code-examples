**Inheritance**
- [What's inherited, what's not](#wi)
- [hiding variable](#hv)

## Inheritance
- [Meaning of Inheritance](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Inheritance/)
- [Types of Inheritance](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Inheritance/#ty).
  - **Java does not support Multiple inheritance**, ie Java class can have only 1 direct superclass.
- **extends keyword**
```java
class A{                             //A.java   
  public A(){
    S.o.p("A");
  }  
}
class B extends A{                  //B.java
  public B(){
    S.o.p("B");
  } 
}        
public static void main(String[] args) {
  B obj = new B();
}
O/P->    A B
```

<a name=wi></a>
### What's inherited, what's not
- **All base classes are inherited as public in Java** 
- What Member Variables, Methods Does a Subclass Inherit?
  - _Variables_
    - Inherited: public,protected,no access specifier in base
    - Not Inherited: private,derv class have member variable with same name as in base class.(Derv class is said to hide the base member variable)
  - _Methods?_
    - Inherited: public,protected methods. Methods declared with no scope
    - Not Inherited: same named methods(overriden), private methods.

<a name=hv></a>
### hiding base class variable
- if derv class have member variable with same name as in base class (Derv class is said to hide the base member variable)
- still derv can access base variable using `super.num`
```java
class A{                             //A.java   
  float num;
}
class B extends A{                  //B.java
  float num;
}
```
