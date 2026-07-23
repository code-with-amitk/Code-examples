**Java**
- [About](#a)
- [Classes: Calendar, Integer, NumberFormat, Object, java.lang.Math, Scanner](Classes)
- [Collections: HashMap, Hashset, List(ArrayList= vector(C++))](Collections)
- [Data types](Data_Types)
- [Exception Handling, finally](Exception_Handling)
- [Features](#f)
- **Input Output**
  - [1. Reading stdin & dump on stdout](#i1)
  - [2. Formatted Output](#fo)
- [Keywords: abstract, interface, final, implements, static](Keywords)
- [Memory Layout of Java Program](#ml)
- [Object Oriented: Class, Inheritance, extends](Object_Oriented)
- [Streams](Streams)
- [String: Tokenize, convert](String)


<a name=a></a>
## About
- By Sun micro systems(1995)
- **What?** Java is a language+collection of run-time-libraries.  Compiler javac(written in java). IDE's(Netbeans, Eclipse).
  - _J2EE?_ Platform for Enterprise Applications
  - _J2ME?_ Platform for Mobile Applications. 
  - _JDK(JAVA DEVELOPMENT KIT)_ SDK, for developing application and applets. This includes JRE, JavaDoc(documentation generator), javac(compiler), jar(archiver) etc. For development and running you need this.
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
- **Automatic Garbage Collection:**  Unlike C/C++ programmer need not to worry about freeing the memory. Garbage Collector runs periodically and frees all memory which is not longer needed.
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
## [Memory Layout of Java Program](https://code-with-amitk.github.io/Motherboard/Memory/Memory_layout_compared.html#java)

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

#### Functions
```java
            Function              |                 Meaning
----------------------------------|-----------------------------------------------------------------------
  getOrDefault(key, defaultValue) | Return value associated with key, if key not found return default value
```
