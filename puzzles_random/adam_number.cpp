/*      adam_number.cpp

Adam Number? Number whose square is reverse of square of original number.
Eg: 12.
Number  Square
   12    144
   21    441
Since squares are reversed, Hence 12 is adam no.

Situation/Task: Given a number, Find whether adam number or not.

*****************Logic**********************
1. Find square of Orignal no
2. Find reverse of Original no
3. Find square of reverse and reverse it
4. if both square match. Adam number.

Complexity:
Space: 64*4 bytes
Time: O(n2)
        square=O(n2)
        reminder=O(n)
********************************************
*/
#include<iostream>
using namespace std;
typedef  int64_t INT64;

class A{
public:
        bool findAdam(INT64);
};

bool A::findAdam(INT64 a){
        INT64 sq, reminder, rev, revSQ, rev1=0;
        if(!a)
                return true;

        cout<<"Original No: "<<a<<endl;

        //Step-1: Find square of number
        sq = a*a;
        cout<<"Square of No: "<<sq<<endl;

        //Step-2: Reverse Orignal Number
        while (a != 0) {
                reminder = a % 10;
                rev = rev * 10 + reminder;
                a /= 10;
        }
        cout<<"Reverse of Original No: "<<rev<<endl;

        //Step-3: Square of reverse No
        revSQ = rev*rev;
        cout<<"Square of Rev No: "<<revSQ<<endl;

        //Step-4: Reverse of (Square of Rev No)
        while (revSQ != 0) {
                reminder = revSQ % 10;
                rev1 = rev1 * 10 + reminder;
                revSQ /= 10;
        }
        cout<<"Reverse of (Square of Rev No)"<<rev1<<endl<<endl;

        if(rev1 == sq)
                return true;
        else
                return false;

}

int main(){
        A o;
        int n=12;
        if(o.findAdam(n))
                cout<<n<<" is Adam number\n";
        else
                cout<<n<<" is Not adam number\n";
}
/*
# ./a.out 
Original No: 12
Square of No: 144
Reverse of Original No: 21
Square of Rev No: 441
Reverse of (Square of Rev No)144

12 is Adam number
 */
