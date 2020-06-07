/*
	random_number_generator.cpp

int rand(void): returns a random number in the range of 0 to RAND_MAX.
RAND_MAX
        16 bit system:    2^15-1 = 32767
        32 bit system:    2^32-1 = 4294967295
        64 bit system:    2^64-1 = 18446744073709551615

void srand(unsigned seed): sets seed. 
Seed: A integer used to Initialize random number generator.
The "seed" is a starting point for the sequence and the guarantee is that if you set same seed you will get the same sequence of numbers again and again.
NOTE: rand() requires seededing once ie at start of program, after that all invocations of rand() will take the seed.
*/


/*	PROGRAM-1: GENERATING SAME SEQUENCE EVERYTIME

- if we seed rand() by same number, it will create the same sequence again and again every time program runs.
	If srand() is not called, the rand() seed is set as if srand(1).
[Usecase] 
  - if 2 seperate programs want to generate same random number they should seed rand() with same random number.
  - Everytime they run exactly same sequence would be generated.
*/
#ifdef Generating_Same_Sequence_EveryTime
#include<iostream>
using namespace std;
int main(){
    srand(0); 		//Seeding with same number 0
  
    for(int i = 0; i<5; i++) 
        cout<<rand()%4<<"\t";
}
//Output:
//# ./a.out	3	2	1	3	1
//# ./a.out	3	2	1	3	1
//# ./a.out	3	2	1	3	1
#endif


/*        PROGRAM-2: GENERATING DIFFERENT SEQUENCE

seeding rand() with srand(time(0))
time_t time(time_t* arg): returns current time.
seed(time(0)): time() returns a time_t value which vary everytime

[Usecase] 
- Carom game or so where everytime its required to generate random number equals to points scored.
*/
#ifdef GENERATING_DIFFERENT_SEQUENCE
#include<iostream>
using namespace std;
int main(){
    srand(time(0));           //Seeding with time(0), which returns different time everytime

    for(int i = 0; i<5; i++)
        cout<<rand()%4<<"\t";
}
//Output
//# ./a.out
//0	0	0	3	1
//3	2	1	3	3
#endif



/*	PROGRAM-3: Creating random number generator.
 *
Pseudo Random Number Generator (PRNG): is an algorithm that uses mathematical formulas to produce sequences of random numbers.

num = (a*num + b) mod c

where,
num: Seqence of random numbers
a: multiplier
b: increment
c: modulus
*/
#ifdef CREATING_RANDOM_NUMBER_GENERATOR
#include<iostream>
using namespace std;

int main(){
	int seed = 2;
	int a = 3;
	int b = 10;
	int c = 5;
	int num = seed;

	for(int i=0;i<5;i++){
		num = (a*num + b) % c;
		cout<<num<<"\t";
	}
}
//Output:
//./a.out
//1	3	4	2	1
#endif
