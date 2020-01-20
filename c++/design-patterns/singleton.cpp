/*
 	singleton.cpp	//Single Object

What? Only single instance/object of class can be created. And provides Global point of access to it.

How to Acheive?
1. Make default constructor pvt: 
	-Object should not be created from direct calls of constructor.

2. Make copy constructor pvt: CCtr is used to copy an exiting object to create new object.
        class test{    
            String *s; 
            test (test const &t1){    
	    	this->s = t1.s;
	    }
        };
        int main(){
            test t1;
            t2 obj(t);    //t2 is created as duplicate of t1. This should be avoided since we are using Singleton.
        }	
	
3. Make Assignment operator pvt: Assignment Operator is used if object is already existent,new object is given new value from other object.
        class test{
                test & operator =(const test &t){  cout<<"=";  }
        };
        int main(){
                test t1, t2;    //2 objects are created
                t2 = t1;    //Assignment Operator called. To Stop this call make Assignment Operator Pvt
        }

4. Take a static variable and save Object address in it and initialize to NULL.

5. Use Static Method to create Objects: because we need to deal with static variables inside.

6. Create objects using static variable only from main
*/

#include<iostream>
using namespace std;

class test{
private:	
        test(){}    				//1
        test(const test &){}    		//2
        test operator=(const test &);    	//3
        static test *obj;    			//4
public:
                static test *fun(){      	//5
                        if(obj == NULL)
                                obj = new test;
                        return obj;
                }
};

test *test::obj = NULL;    			//4

int main(){
	test *p1 = test::fun();    //Address: 0x6000227f0		//6
	cout<<"p1="<<p1<<"\n";
	test *p2 = test::fun();    //Address: 0x6000227f0
	cout<<"p2="<<p2<<"\n";
	return 0;
}
/*
Output:
# ./a.out
p1=0x2129e70
p2=0x2129e70
 */
