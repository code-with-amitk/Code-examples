## Anti Pattern
- Bad software designs. These are opposites to Design Patterns & undesirable. 

### Examples of anti patterns
- **1. GOD OBJECT:** An object which does lot of things on its own, instead OO programming says separate task into small objects.
```c
BAD PRACTICE
class GodObject {
    function PerformInitialization() {}
    function ReadFromFile() {}
    function WriteToFile() {}
    function DisplayToScreen() {}
    function PerformCalculation() {}
    function ValidateInput() {}
}
Good Practice
class FileInputOutput {
    function ReadFromFile() {}
    function WriteToFile() {}
}
class UserInputOutput {
    function DisplayToScreen() {}
    function ValidateInput() {}
}
class Logic {
    function PerformInitialization() {}
    function PerformCalculation() {} 
}
```

- **2. TELESCOPIC CONSTRUCTOR:**  Class has N number of constructors, each taking different number of arguments & doing the job
```c
 public class FoodTelescopingDemo {
    public FoodTelescopingDemo(int id, String name) {
      this(id, name, 0, 0, 0, "default description");  
    } //Constructor1
    public FoodTelescopingDemo(int id, String name, int calories) { 
      this(id, name, calories, 0, 0, "default description"); 
    } //Constructor2
    ...
    public FoodTelescopingDemo(int id, String name, int calories, int servingSize, int fat, String description) {
  //Constructor5, Builds Object
}
```
