**Java**
- [About](#a)
- [Features](#f)
- [Memory Layout of Java Program](#ml)
- [Data types](Data_Types)
- **Keywords**
  - [Extends = inheritance](#ex)
  - [final](#fi)
  - [Implements](#im)
  - [static](#st)
- **Input Output**
  - [1. Reading stdin & dump on stdout](#i1)
  - [2. Formatted Output](#fo)
- **Classes**
  - [ArrayList](#al)
  - [Calendar](#cal)
  - [Integer](#int)
  - [List`<>`](#li)
  - [NumberFormat](#nf)
  - [HashMap](#hm)
  - [java.lang.Math](#math)
  - [Scanner](#s)


<a name=a></a>
## About
- By Sun micro systems(1995)
- **What?** Java is a language+collection of run-time-libraries.  Compiler javac(written in java). IDE's(Netbeans, Eclipse).
  - _J2EE?_ Platform for Enterprise Applications    J2ME?Platform for Mobile Applications. 
  - _JDK(JAVA DEVELOPMENT KIT)_ SDK, for developing application and applets. This includes JRE,  JavaDoc(documentation generator), javac(compiler), jar(archiver) etc. For development and running you need this.
  - _JRE(JAVA RUNTIME ENV)_: Includes JVM+library classes. If you only want to run Java applications you would need JRE.
  - _JVM(JAVA VIRTUAL MACHINE)/INTERPRETER_: JVM executes the java program line-by-line. JVM becomes an instance of JRE at runtime of a Java program.
- **CATEGORIES**     a. core-java    b. Advanced-java    c. J2EE(without completing core, advanced java, You will not understand J2EE)
- **RUNTIME PLATFORMS:**    
  a. J2SE(Java 2 Standard Edition): Includes libraries for JDBC(Java DB Connectivity), JNDI(Java Naming Directory Interface), RMI(Remote Method Invocation), AWT , Swing
  b. J2EE(Java 2 Enterprise Edition):  Includes Java Mail,  JAXB (Java API for XML Binding), Servlets, JSF (Java Server Faces), JMS (Java Messaging Service), EJB (Enterprise Java Beans).
  c. J2ME(Java 2 Micro Edition): APIs for handheld devices.

<a name=f></a>
## Features of Java
- **Architecture Neutral:** Compiler generates bytecode which has nothing to do with computer architecture.
- **Automatic Garbage Collection:** 
  - Unlike C/C++ programmer need not to worry about freeing the memory. Garbage Collector runs periodically and frees all memory which is not longer needed.
```java
public class main{
	public static void main(String[] args) {
    {
		  A obj = new A();
    }
    //Object goes out of scope, Memory automatically deleted. While this does not happen in C++.
	}
}
```
  - _How Garbage Collector works?_
    - Garbage collector is a mark sweep garbage collector that scans dynamic memory(Heap) for objects, marking those that are referenced/used.
    - After all possible paths to objects are investigated, those objects that are not marked (that is, not referenced) are known to be garbage and are collected.
  - _How to make GC Run explicitly?_
    - Java program can ask the garbage collector to run at any time by calling System.gc.
- **Distributed:** We can create distributed application in Java using RMI, EJB.
- **Object Oriented**
- **Platform Independent:** 
  - Java produces [byte code](/Languages/Programming_Languages/CompilationSteps_C_Java.md), Unlike C and C++ which produces platform specific machine code. This byte code is distributed over the web and interpreted by virtual Machine (JVM) on whichever platform it is being run. ie byte-code can be generated on MAC & run on linux/Windows.
  - Elimination of platform specific constructs
- **Portable:** bytecode can be carried to any platform, no implementation depend features.
- **Robust:** Code is made robust as Java introduces, Memory management & mishandled exceptions.
- **Safe:** 
  - _a._ Java always runs on [JRE](/Languages/Programming_Languages/CompilationSteps_C_Java.md) which has almost 0 interaction with OS hence secure.
  - _b._ No pointers(hence no SEG faults)    
  - _c._ Runtime exception handling is better wrt c++/c.
  - _d._ typecasting is meaningful and logical. int can be casted to short but not bool.
- **Multi-threaded:** 1 program can have multiple threads running and improving performance of program.
- **Speed:** Memory is allocated on Eden space and its not guaranteed that it will be allocated contiguously. Non-contiguous memory is slower wrt to contiguous.        //Java is slow wrt C,C++


<a name=ml></a>
## Memory Layout of Java Program
Since program runs inside JVM, we will also see How JVM looks on memory.
```java
                                 |---   Stack   Area      -----|  |----    PC(program counter Registers ---|
    [ Method Area ] [ Heap area] <--Thread-1----><-Thread-2---->  <Register-Thread-1><Register-Thread-2> [Native-Method-Stack]
                                  Stack-Frames LVA,OS,FD 
```

- _Method Area_ Heap memory created by JVM at startup and all threads share this. JVM stores following information here: FQDN of a type (ex: String), Type's modifiers, Type's direct superclass name, Structured list of the fully qualified names of super interfaces.
- _Heap Area:_ This is created on JVM startup. Only 1 heap exists for each running JVM process. By default, the maximum heap size is set to 64 MB.
  - What is stored on Heap area:    a. Instance of objects allocated using new keyword.     b. Arrays
- Understanding Heap Area
```java
    <---------------------        Young Space            ------------------->    <---------  Old Space   --------->
    | Eden Space | S0(Survivor-0) | S1(Survivor-1) | Keep Area |
    Minor GC                                                                        Major GC 
```                                        
- _Nursery/Young Space/Young Generation_
  - Nursery is divided into - Eden space, 2 survivor spaces.
  - Eden space: Stores newly created objects.
  - Survivor Spaces: When Eden becomes full, Minor garbage collector(Minor GC) is run and objects present from long are moved to Survivor spaces, ensuring 1 survivor space is always empty. Objects that survived many cycles of GC, are moved to old generation memory space.
  - Keep Area: Contains the most recently allocated objects in the nursery and is not garbage collected until the next young generation. 
- Old Space/Old Generation
  - Garbage collection is performed in Old generation memory when it’s full called Major GC and usually takes longer time

- _Stack Area🇦🇬 This is created when Thread is created. Stack memory is allocated per thread. It contains references to heap objects. 
  - Stack-Frame: This is a data structure that contains the thread's data. Only one frame (the frame for executing method) is active at any point in a given thread of control. This frame is called the current frame. Contains:
    - Local Variable Array (LVA), Operand Stack (OS), and Frame Data (FD). 
- PC-Registers: Each thread has a Program Counter (PC) register associated with it. PC register stores the return address or a native pointer. It also contains the address of the JVM instructions currently being executed.
- Native Method Stack/C stack: This stack is for native code written in a language other than Java



## Keywords
<a name=ex></a>
### Extends = Inheritance
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

<a name=fi></a>
### Final
- Before an object is freed by [GC, the garbage collector]() calls object's final() method. Object can free all resources itself in final(). This process is called finalization.
- During finalization object can: free system resources(eg: files,sockets) or drop references to other objects
- finalize method is a member of the Object class and class must override finalize method to perform any finalization.

<a name=im></a>
### Implements
```c
```

<a name=st></a>
### Static
Types of static
```c
1. static class variable
2. static class method
3. static class
```
Properties
```c
1. All objects share same static variable
```
Code
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

## Input Output
<a name=i1></a>
#### 1. Reading stdin & dump on stdout
[scanner class](#s)
```java
import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int i = scan.nextInt();                   //Read int
        double d = scan.nextDouble();             //Read double
        scan.nextLine();                          //Scanner.nextInt() or Scanner.nextDouble() does not read the newline character
                                                  //in input created by hitting "Enter" hence Scanner.nextLine returns after reading that newline
        String s = scan.nextLine();
        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
    }
}
```
<a name=fo></a>
#### 2. Formatted output
- `%n` is newline
```java
float a = 4.2f;
System.out.printf("%.4f", a);         //4.2000                      //Printing upto 4 precisions

float n = 2324435.3f;
System.out.printf("%20.4f n=",n);     //n =         2324435.2500    //number is formatted from right margin & occupies width of 20 characters

String s="java";
int a = 20;
System.out.printf("%-15s%03d%n", s, a);   //java           20
```

## Classes
<a name=al></a>
### Arraylist = vector(C++)
- AL are not synchronized(ie If multiple threads access AL, synchronization needed to be provided externally). vectors are synchronized
```java
Iterable <--extends-- Collection <--extends-- List  <--implements-- AbstractList <--extends-- ArrayList

List<Integer> al = new ArrayList<Integer>();
```

<a name=cal></a>
### Calendar
This is abstract class that provides methods for converting date b/w DD/MM/YYYY to other formats.
```c
Calendar obj = new Calendar();
void obj.set(year, month, day);      //Sets the calender to YEAR, MONTH, and DAY_OF_MONTH.
int get(Calendar.DAY_OF_WEEK);       //Returns the day of the given calendar field in int
```

<a name=int></a>
### Integer class
**Why?** Converting int to string, string to int. Methods:
```c
String s = Integer.toString(int i);       //Converts int to string
```

<a name=li></a>
### `List<>`
- List is interface which is implemented by some concreate classes: AbstractList, AbstractSequentialList, ArrayList, AttributeList, CopyOnWriteArrayList, LinkedList, RoleList, RoleUnresolvedList, Stack, Vector
- Since List`<>` is a interface, we cannot create object of List class.

<a name=nf></a>
### NumberFormat
This class provides methods for converting numbers into different locales(US, India, Italy, etc).
```c
double d = 123456.789
Indian representation: 1,23,456.789
US representation:     123,456.789
Italy representation:  123.456,789

double input = 12324.134;
NumberFormat us = NumberFormat.getCurrencyInstance(Locale.US);
NumberFormat in = NumberFormat.getCurrencyInstance(new Locale("en", "IN"));
NumberFormat ch = NumberFormat.getCurrencyInstance(Locale.CHINA);
NumberFormat fr = NumberFormat.getCurrencyInstance(Locale.FRANCE);
                
System.out.println(us.format(input));                       // $12,324.13
System.out.println(in.format(input));                       // Rs.12,324.13
System.out.println(ch.format(input));                       // ￥12,324.13
System.out.println(fr.format(input));                       // 12 324,13 €
```

<a name=hm></a>
### HashMap `<key,value>`
- Writing on Key that is already existant Overrides the old entry. No ordering is maintained.
```
map <--implements-- AbstractMap <--extends-- HashMap
```
#### Code
```java
HashMap<Integer,String> hm = new HashMap <Integer,String>();
hm.add(100,"Ravi");
hm.add(200,"Hari");
hm.add(300,"Mani");

for (Map.Entry temp:hm.entrySet())
  S.o.p(temp.getValue());
```
#### Functions
```java
            Function              |                 Meaning
----------------------------------|-----------------------------------------------------------------------
  getOrDefault(key, defaultValue) | Return value associated with key, if key not found return default value
```

<a name=s></a>
### Scanner
Scanner class is used to get user input, and it is found in the java.util package. Available methods in scanner class
```java
Scanner scan = new Scanner(System.in);
scan.nextLine():   Read string from stdin
scan.nextInt():    Read int from stdin
scan.nextDouble(): Read double from stdin

while(scan.hasNext()){   //Returns true if this scanner has another token in its input. This method may block while waiting for input to scan.
}
```
<a name=math></a>
### java.lang.Math
```java
Contained methods:
  Math.pow(a,b)
```
