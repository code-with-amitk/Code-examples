## Important Functions
- **1. rand()**
```c
int rand(void): returns a random number in the range of 0 to RAND_MAX.
RAND_MAX
        16 bit system:    2^15-1 = 32767
        32 bit system:    2^32-1 = 4294967295
        64 bit system:    2^64-1 = 18446744073709551615
```		
- **2. srand()**
```c
void srand(unsigned seed): sets seed. 
Seed: A integer used to Initialize random number generator. The "seed" is a starting point for the sequence and the guarantee is that if you set same seed
you will get the same sequence of numbers again and again.
NOTE: rand() requires seededing once ie at start of program, after that all invocations of rand() will take the seed.

seeding rand() with srand(time(0)). 
 - time_t time(time_t* arg): returns current time. seed(time(0)): time() returns a time_t value which vary everytime
```

### 1. Generating same seq everytime
- **Logic** Seed rand() by same number
- **Use case** 2 seperate programs want to generate same random number everytime.
- **Code**
```c
#include<iostream>
using namespace std;
int main(){
    srand(0); 				//Seeding with same number 0
  
    for(int i = 0; i<5; i++) 
        cout<<rand()%4<<"\t";
}
//Output:
//# ./a.out	3	2	1	3	1
//# ./a.out	3	2	1	3	1
//# ./a.out	3	2	1	3	1
```
### 2. Generating Different Sequence
- **Logic** rand() can be called without calling seed(), it will return random no everytime.
- **Usecase** Carom game or so where everytime its required to generate random number equals to points scored.
- **Code**
```c
#include<iostream>
using namespace std;
int main(){
    for(int i = 0; i<5; i++)
        cout<<rand()%4<<"\t";
}
//Output
//# ./a.out
//0	0	0	3	1
//3	2	1	3	3
```

### 3. Pseudo Random Number Generator (PRNG)
- **What** This is an algorithm that uses mathematical formulas to produce sequences of random numbers. 
```c	
num = (a*num + b) mod c
where,
num: Seqence of random numbers
a: multiplier
b: increment
c: modulus
```
- **Code**
```c
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
```
