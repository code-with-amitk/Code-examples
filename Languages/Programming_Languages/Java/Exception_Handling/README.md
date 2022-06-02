**Exception Handling**
- Examples
  - [1. Catching Divide by 0](#e1)


## Exception Handling
- [What is Exception](/Languages/Programming_Languages/c++/ExceptionHandling)
- In Java, when exception occurs a EXCEPTION OBJECT is created and handed over to runtime. All exceptions in Java are subclasses of **java.lang.Throwable**
- **java.lang.Exception, java.lang.Error** are major subclasses of java.lang.Throwable
```java
        java.lang.Throwable
    /                       \
java.lang.Exception     java.lang.Error
```
- [try,catch,throw](/Languages/Programming_Languages/c%2B%2B/ExceptionHandling#t)

<a name=e1></a>
#### Example-1. Catching Divide by 0
- Only Usage of **throw is bit different in Java**(wrt C++). 
  - After function parameter list Possible exceptions are added Comma Seperated.
  - Java uses throws, c++ uses throw
```java
///////////Program causing crash/////////////
$ test.java
public class test {
    public static void main(String[] args){
        test t = new test(0);
    }
    test (int a) {
      int s = 1/a;
    }
}
$ javac test.java
$ java test
Exception in thread "main" java.lang.ArithmeticException: / by zero
        at test.<init>(test.java:8)
        at test.main(test.java:3)
        
///////////Catching Exception no Crash/////////////
$ test.java
public class test {
    public static void main(String[] args){
        try {
            test t = new test(0);
        } catch (ArithmeticException e){
            System.out.println(e);
        }

    }

    test (int a) throws ArithmeticException{    //Also note its throws not throw
        int s = 1/a;
    }
}
$ javac test.java
$ java test
java.lang.ArithmeticException: / by zero
```
