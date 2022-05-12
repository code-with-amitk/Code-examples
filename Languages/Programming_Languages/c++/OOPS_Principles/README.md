## OOPS Principles
### 1. SOLID
- *a. Single Responsibility:* Every module/class should have one responsibility and should work on single part of functionality provided by software. Microservices are build around this.
- *b. Open-Closed:* Software entities(classes/modules) should be open for extension but closed for modification.
  - Extension: Existing classes can be extended/coupled with any new behavior.
  - Modifications: Coders have spent day & night for making code bug free & fast. We cannot get code changes in existing now.
- *c. Liskov Substitution:* function using base class object can use derv class object in place of base class object, without causing any issues/problems.
- *d. Interface Segregation:* Split the Bigger/Large Interfaces into smaller once, so that client should should only know about interfaces that interests him.
- *d. Dependency Inversion:* Decoupling software modules. High-level modules should not depend on low-level modules. Both should depend on abstractions(ie interfaces).

### Other Principles
- *a. DRY(Donot repeat yourself):* If you have a block of code in more than two places, consider making it a separate method
- *b.  Favour composition over inheritance*
- *c. ODR(One Definition Rule):*    A compiled source code(also called compilation unit/translation unit) will have only 1 definition but can have multiple declarations.
- *d. Separation of concerns:* Dividing code into distinct sections so that each section addresses separate concern. Concern here means problems that code is going to address  

### RAII(Resource Acquisition is Initialization) OR SBRM(Scope Bound Resource Management):
- Resource(Anything that exists in limited supply eg: socket, files, disk, mutex, Heap, threads etc) lifetime should be bounded to object lifetime. Means when object's lifetime ends, resources are also freed in reverse order of allocation.
- resource would be available to any function that accesses the object. 
- How this is achieved? Acquire resources in constructor, release in destructor or smart pointer.
