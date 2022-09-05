- [SOLID Principles](#sp)
- [Other Principles](#op)
- [Head 1st Design Principles](#hf)

<a name=sp></a>
### SOLID Principles
#### a. Single Responsibility 
Every module/class should have one responsibility and should work on single part of functionality provided by software. Microservices are build around this.
#### b. Open-Closed
- Software entities(classes/modules) should be open for extension but closed for modification.
  - Extension: Existing classes can be extended/coupled with any new behavior.
  - Modifications: Coders have spent day & night for making code bug free & fast. We cannot get code changes in existing now.
- **How Achieved?** By creating a abstract class and every derived class has its own custom implementation.
  - Example: Calculate area of any shape.
    - Initially we have only Rectangle. We can include circle, Triagle, polygon etc later on and add new code, without touching abstract class code.
```cpp
class Shape {   //Pure Virtual class. Abstract class
public:
        virtual double Area() = 0;
};
class Rectangle : public Shape {
        int width, height;
public:
        Rectangle(int w, int h):width(w), height(h){}
        double Area(){
                return width*height;
        }
};
class Circle : public Shape {
        int radius;
public:
        Circle(int r):radius(r){}
        double Area(){
                return radius*radius*3.14;
        }
};
int main(){
        Rectangle r(4,5);
        cout << r.Area() << "\n";
        Circle c(3);
        cout << c.Area();
}
```
#### c. Liskov Substitution
Derv class object can be used in place of base class object without any issues.
#### d. Interface Segregation (Interaface in C++ = Base class having pvf)
Split the Bigger Interfaces into smaller once. Also program to interface.
#### e. Dependency Inversion
Decoupling modules. High-level modules should not depend on low-level modules. Both should depend on abstractions(ie interfaces).

<a name=op></a>
### Other Principles
- *a. DRY(Donot repeat yourself):* If you have a block of code in more than two places, consider making it a separate method
- *c. ODR(One Definition Rule):*    A compiled source code(also called compilation unit/translation unit) will have only 1 definition but can have multiple declarations.
- *d. Separation of concerns:* Dividing code into distinct sections so that each section addresses separate concern. Concern here means problems that code is going to address  

<a name=hf></a>
### Head 1st Design Patterns Principles
#### 1. Identify the aspects of application that vary and separate them from what stays the same.
#### 2. Program to an interface, not an implementation.
#### 3. Favour composition over inheritance

### RAII(Resource Acquisition is Initialization) OR SBRM(Scope Bound Resource Management):
- Resource(Anything that exists in limited supply eg: socket, files, disk, mutex, Heap, threads etc) lifetime should be bounded to object lifetime. Means when object's lifetime ends, resources are also freed in reverse order of allocation.
- resource would be available to any function that accesses the object. 
- How this is achieved? Acquire resources in constructor, release in destructor or smart pointer.
