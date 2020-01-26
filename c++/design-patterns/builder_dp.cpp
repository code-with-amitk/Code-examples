/*
                builder_dp.cpp

Builder DP: Creating bigger object using smaller objects. Multiple products can be produced using same process.

Entities present in Builder DP:
a. Builder: Abstract class declaring pure virtual functions
b. Concrete class1: Class overriding builder class
c. Concrete-class2: Another class overriding builder class
d. Director: Class using concrete classes and returning a fancy object.

Simply director takes concrete class pointers and build object.
Director here creates object having horsepower of JetPlane and weight of carrierPlane.

*/

#include<iostream>
#include <string>
using namespace std;

class aeroplane {
public:
        float weight;
        int horsePower;
};

class Builder {
 public:
        virtual void setWeight() = 0;
        virtual void setHorsePower() = 0;
        virtual void disp() = 0;
};

class jetPlane : public Builder {
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

class carrierPlane : public Builder {
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

class Director {
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
