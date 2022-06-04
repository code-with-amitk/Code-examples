## RW to/from File
```java
import java.io.*;
public class File {
    public static void main(String args[]) {
        try {
            FileInputStream in = new FileInputStream("in.txt");
            FileOutputStream out = new FileOutputStream("out.txt");

            int c;
            while ((c=in.read()) != -1) {
                out.write(c);
            }
            in.close();
            out.close();
         }
        catch (FileNotFoundException e) {
            System.err.println("File: " + e);
        }
        catch (IOException e) {
            System.err.println("File: " + e);
        }
    }
}
$ cat in.txt
Dharya the test code

$ javac File.java
$ java File
$ cat out.txt
Dharya the test code
```
