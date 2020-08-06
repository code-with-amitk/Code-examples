## Builder DP
- **What** Creating bigger object using smaller objects. Multiple products can be produced using same process.

### Entities present in Builder DP
- **a. Builder:** Abstract class declaring pure virtual functions
- **b. Concrete class1:** Class overriding builder class
- **c. Concrete-class2:** Another class overriding builder class
- **d. Director:** Class using concrete classes and returning a fancy/custom object.  

### UML DIagram  
```  
                        Aggregation
    Builder class   -----------------------/\ Director
        /\                                 \/
         |
         |Inheritance
  -----------------
  |               |
 jetPlane     carrierPlane  
```

### Code
```
#include<iostream>
#include <string>
using namespace std;

class aeroplane {                        
public:
        float weight;
        int horsePower;
};

class Builder {                          //BUIDER. Base Class
 public:
        virtual void setWeight() = 0;
        virtual void setHorsePower() = 0;
        virtual void disp() = 0;
};

class jetPlane : public Builder {                 //Derv-class-1
        aeroplane a;
public:
        void setHorsePower(){
                a.horsePower = 10000;
        }
        void setWeight(){
                a.weight = 1000;
        }
        void disp(){
                cout<<"Jet Plane\n";
        }
};

class carrierPlane : public Builder {           //Derv-class-2
        aeroplane a;
public:
        void setHorsePower() {
                a.horsePower = 5040;
        }
        void setWeight() {
                a.weight = 5000;
        }
        void disp(){
                cout<<"Carrier Plane\n";
        }
};

class Director {                                //Director
public:
        void fun(jetPlane *a, carrierPlane *b) {
            a->setHorsePower();
            b->setWeight();
            cout<<"This is Customized plane\n";
        }
};

int main(){
    Director director;

    /* 
     * Derived class objects can be collected in Builder class pointer using
     * Dynamic Polymorphism.
     */
    jetPlane *jp = new jetPlane();
    carrierPlane *cp = new carrierPlane();
    director.fun (jp, cp);

    return 0;
}
```
