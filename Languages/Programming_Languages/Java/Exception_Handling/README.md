**Exception Handling**
- Examples
  - [1. Catching Divide by 0](#e1)
- [Throwing User defined class](#tu)


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

### Examples
<a name=e1></a>
#### Example-1. Catching Divide by 0  
**Program causing crash**
```java
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
```
**1a. Catching exception Using throws:** After function parameter list Possible exceptions are added Comma Seperated.
```java 
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

    test (int a) throws ArithmeticException{    //throws not throw. When function can throw any from list of exceptions.
        int s = 1/a;
    }
}
$ javac test.java
$ java test
java.lang.ArithmeticException: / by zero
```
**1b. Catching exception Using throw**. [Same as C++](/Languages/Programming_Languages/c%2B%2B/ExceptionHandling#e1)
```java
public class test {
    public static void main(String[] args){
        try {
            test t = new test(0);
        } catch (ArithmeticException e){
            System.out.println(e);
        }

    }
    test (int a) {
        if (a <=0)
            throw new ArithmeticException("Divide by 0");
        int s = 1/a;
    }
}
```

<a name=tu></a>
### Throwing User defined class
- We can create our own class(which extends Exception class) and this can be thrown.
- **Usage:** User defined class can have attributes which can be used.
```java
$ custom_except.java
class custom_except extends Exception {              //1. Create class extending Exception
    custom_except(){}
}

$ A.java
public class A{
    public static void main(String[] args) {
        try {                                        //3. Provide try, catch
            A obj = new A(0);
        }
        catch (custom_except e){                    //4. catch custom exception class
            System.out.println("custom Exception");
        }
    }
    A(int a) throws custom_except {                 //2. Function should throws custom class
        if (a<=0)
            throw new custom_except();
    }
}
$ javac *.java
$ java A
custom Exception
```
