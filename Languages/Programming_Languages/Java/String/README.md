**String**
- [Tokenize](#tok)
- [Convert: String to int](#con)

## String
- java.lang.String class implements Serializable, Comparable and CharSequence interfaces.

<a name=tok></a>
### Tokenize
java.util.StringTokenizer class allows you to break a String into tokens.
```java
import java.util.StringTokenizer;  
public class Simple {  
  public static void main(String args[]) {  
  
    /// Tokenize on whitespace
    StringTokenizer st = new StringTokenizer("hello how are you"," ");
    while (st.hasMoreTokens()) {  
      System.out.println(st.nextToken());  
    } 
  }
}
```

<a name=con></a>
### Convert
#### String to int
```java
public class StringToIntExample1{  
  public static void main(String args[]){  
    String s="200";  
    
    /// Convert String into int
    int i=Integer.parseInt(s);
  }
}
```
