- **Classes**
  - [Calendar](#cal)
  - [Integer](#int)
  - [NumberFormat](#nf)
  - [Object](#o)
  - [java.lang.Math](#math)
  - [Scanner](#s)

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

<a name=o></a>
### Object class
- Object class sits at the top of the class hierarchy tree. Every class in the Java system is a descendent (direct or indirect) of the Object class.
- **Benefits:** Object class provides couple of methods, which every class can use example
  - compare oneself to another object
  - convert to a string
  - to wait on a condition variable, to notify other objects that a condition variable has changed, and to return the object's class
  - Methods provided by Object class
```java
getClass(): Returns information about object. Its name, its superclass, and the names of the interfaces that it implements.
equals(): 2 objects are equal or not
toString(): Returns string representation of object.
  System.out.println(Thread.currentThread().toString());
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
