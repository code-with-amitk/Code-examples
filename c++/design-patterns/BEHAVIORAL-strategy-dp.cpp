/*              strategy-dp-duck-game.cpp

Strategy DP? This defines set of algorithms those can used by client/caller freely.

Principle used:
- Favour composition over inheritance.
  [We have used aggregation(ie pointer) because C++ does not allow creation of Abstract class object]

Situation/Task: Implement a Duck-game with these initial settings:
 duck-type      fly     swim    quack
 rubber          no      yes     no
 mallard         yes     no      no
 model           no      no      yes

- During the game, player can attach a rocket to duck and make it fly.
- Keep in mind these Design Principles:
 a. Favour composition over inheritance.
 b. Favour interface(ie PVF C++) class rather inheritance. 
*/
#include<iostream>
using namespace std;

class flyB{                     //INTERFACE
public: virtual void fly()=0;
};
class flyWithWings:public flyB{
public: void fly(){cout<<"I am Flying\n";}
};
class cannotFly:public flyB{
public: void fly(){cout<<"I cannot fly\n";}
};

class quackB{                   //INTERFACE=PVF
public: virtual void quack()=0;
};
class canQuack:public quackB{
public: void quack(){cout<<"Quacking\n";}
};
class muteQuack:public quackB{
public: void quack(){cout<<"Cannot quack\n";}
};

class swimB{                    //INTERACE
public: virtual void swim()=0;
};
class canSwim:public swimB{
public: void swim(){cout<<"I am Swimming\n";}
};
class cannotSwim:public swimB{
public: void swim(){cout<<"I Cannot swim\n";}
};

class duck{
public:
        flyB *f;
        quackB *q;
        swimB *s;
        virtual void create()=0;
};

class rubberDuck:public duck{
public:
        rubberDuck(){
                cout<<"Creating Rubber Duck\n";
                f = new cannotFly();
                q = new muteQuack();
                s = new canSwim();
        }
        void create(){
                this->f->fly();
                this->q->quack();
                this->s->swim();
        }
};

int main(){
        duck *p = new rubberDuck();
        p->create();
}
/*
Output:
# ./a.out
Creating Rubber Duck
I cannot fly
Cannot quack
I am Swimming
*/
