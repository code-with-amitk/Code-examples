Object Oriented

### class
#### Creating
```java
$ mkdir test; cd test
$ vim Emp.java
public class Emp {
  public Emp (String name, int age, int sal, String pos) {    //Constructor
    this.name = name;
    this.age = age;
    this.sal = sal;
    this.position = pos;
    minWage = 750;
    maxWage = 2000;
  }
  public void printName() {                           //Methods
    System.out.println(name + " " + name);
  }
  public int getSal() {
    return sal;
  }
  private String name;                              //Attributes
  private int age;
  private int sal;
  private String position;
  final int maxWage;
  final int minWage;
}

$ vim Employee.java
public class Employee {
    public static void main(String[] args) {
        Emp e = new Emp("amit", 21, 10, "t11");       //Creating Object. See with new
        int sal = e.getSal();
        System.out.println("sal="+sal);
    }
}

$ javac *.java
$ java Employee
sal=10
```

