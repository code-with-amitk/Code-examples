- [abstract vs interface](#ai)
- [abstract](#ab)
- [interface](#inf)
- [final](#fi)
- [Implements](#im)
- [Package](#p)
- [static](#st)

## Keywords
<a name=ai></a>
### abstract vs interface
||abstract=Virtual Function|interface=Pure Virtual Function|
|---|---|---|
|What|Provides 0-100% programming interface|Provides 100% programming interface|
|Method can have body|yes|no (will not compile)|
|Implemented using keyword|extends|implements|
|Multiple Inheritance|not supported|supported|
|Variables|final, non-final, static and non-static|static and final|

<a name=ab></a>
### abstract
This provides complete programming interface.
#### abstract class
This class cannot be instantiated. Subclass must override abstract methods in superclass, or the subclass itself must be abstract.
```java
$ Number.java
abstract class Number{
}

$ Inte.java
class Inte extends Number{
    public static void main(String[] args) {
        System.out.println("Hi");
    }
}

$ javac *.java
```

#### abstract method
Can/Cannot have a body.
```java
$ Number.java
abstract class Number{
  abstract void fun() {
    int a;
  }
}

$ Inte.java
class Inte extends Number {
 void fun() {
 . . .
 }
}
```

<a name=inf></a>
### interface = PVF
- interface can only provide template, function cannot have body.
- All functions are abstract.
```java
$ test.java
public interface test {
    public void fun();			//Methods in Interface cannot have body. Complilation error
}

$ main1.java
public class main1 implements test{	//implement interface
    public void fun() {			//Interface function should be overridden
        System.out.println("test");
    }
    public static void main(String[] args){
        System.out.println("main");
    }
}
```

<a name=f></a>
### Final
- **final Method:**
  - Before an object is freed by [GC, the garbage collector](#f) calls object's final() method. Object can free all resources itself in final(). This process is called finalization.
  - During finalization object can: free system resources(eg: files,sockets) or drop references to other objects
  - finalize method is a member of the Object class and class must override finalize method to perform any finalization.
  - final method cannot be overridden in derived class
```java
class ChessAlgorithm {
  final void fun() {          //This cannot be overridden in derv class
  }
}
 .
```
- **final class:** final class cannot be inherited. But why someone want to make class=final. 2 reasons(Security, Design decision)
```java
final class A {		//This will not be inherited
 . . .
}
```

<a name=p></a>
### Package
- Package is groups of related classes and interfaces bundles together for specific purpose.
- To create package: `package` keyword is used.
- To use package: `import` keyword is used.
```java
$ A.java
package pack;                         //Package keyword creates a package named pack. Class A gets avilable in pack
public class A {
  public void msg() {
    System.out.println("Hello");
  }
}

$ B.java
import pack.*;                        //Above created package would be used
public class B{
  public static void main(String args[]){
   A obj = new A();
   obj.msg();
  }
}

$ javac *.java
```

<a name=st></a>
### Static
- _Types of static:_
  - _1._ static class variable
  - _2._ static class method
  - _3._ static class
```
- _Properties_
  - _1._ All objects share same static variable
- static base class methods cannot be overridden in derv class.
- Code
```java
public class Solution {
  static Scanner scan = new Scanner(System.in);
  static int B = scan.nextInt();
  static int H = scan.nextInt();
  static boolean flag = true;
  static{
    try{
        if(B <= 0 || H <= 0){
            flag = false;
            throw new Exception("Breadth and height must be positive");
        }
    }catch(Exception e){
        System.out.println(e);
    }
  }
}
```
