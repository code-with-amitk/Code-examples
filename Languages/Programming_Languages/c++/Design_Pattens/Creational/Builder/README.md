## Builder DP
- **What** Creating bigger object using smaller objects. Multiple products can be produced using same process.

### Entities present in Builder DP
- **a. Builder:** Abstract class declaring pure virtual functions
- **b. Concrete class1:** Class overriding builder class
- **c. Concrete-class2:** Another class overriding builder class
- **d. Director:** Class using concrete classes and returning a fancy/custom object.  

### UML DIagram  
```html  
                        Aggregation
    Builder class   -----------------------/\ Director
        /\                                 \/
         |
         |Inheritance
  -----------------
  |               |
 jetPlane     carrierPlane  
```

### [Code](Code)
