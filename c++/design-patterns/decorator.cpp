/*      decorator.cpp
 
 STARTBUZZ COFFEE SHOP:
 In addition to coffee, you can add condiments like soy, mocha, chocolate etc.
 Costs would be separate for them.

 */
#include<iostream>
#include<string>
using namespace std;

class Beverage{
        string desc="Unknown Beverage";
public:
        virtual string getDesc(){ return desc; }
        virtual double cost()=0;        //PVF should be overridden inside derv class
};

class DarkRoast:public Beverage{
        string desc="DarkRoast";
public:
        string getDesc(){ return desc; }
        double cost(){return 1.99;}
};

class Espresso:public Beverage{
        string desc="Espresso";
public:
        string getDesc(){ return desc; }
        double cost(){return 1.99;}
};

class HouseBlend:public Beverage{
        string desc="HouseBlend";
public:
        double cost(){return .89;}
};

class CondimentDecorator:public Beverage{
public:
        virtual double cost()=0;
};

class Whip:public CondimentDecorator{
        Beverage *b;
public:
        Whip(Beverage *be) {
                this->b = be;
        }
        string getDesc() {
                return b->getDesc() + ", Whip";
        }
        double cost() {
                return .20 + b->cost();
        }
};

class Mocha:public CondimentDecorator{
        Beverage *b;
public:
        Mocha(Beverage *be) {
                this->b = be;
        }
        string getDesc() {
                return b->getDesc() + ", Mocha";
        }
        double cost() {
                return .40 + b->cost();
        }
};

int main(){
        Beverage *esp = new Espresso();
        cout<<esp->getDesc() << " $"<< esp->cost()<<"\n";

        Beverage *darkR = new DarkRoast();
        Beverage *mocha1 = new Mocha(darkR);
        cout << mocha1->getDesc() <<" $"<<mocha1->cost()<<"\n";
}
/*
# ./a.out 
Espresso $1.99
DarkRoast, Mocha $2.39
*/
