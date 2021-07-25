- [rand()](#rand)
  - [rand() considered harmful](#harm)
- [srand()](#srand)
- [Generate same seq everytime](#gens)
- [Generating Different Sequence](#gend)
- [Pseudo Random Number Generator (PRNG)](#prng)


<a name=rand></a>
## int rand(void)
- returns a random number in the range of 0 to RAND_MAX.
```c
RAND_MAX
  16 bit system:    2^15-1 = 32767
  32 bit system:    2^32-1 = 4294967295
  64 bit system:    2^64-1 = 18446744073709551615
```		

<a name=harm></a>
### [rand() considered harmful](https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful)
- Instead use C++ provided random generator
```cpp
#include<random>
default_random_engine seed;
return vec[uniform_int_distribution<> (0, 100)(seed)];     //Generate random b/w 0 to 100
```

<a name=srand></a>
## void srand(uint seed)
- sets the seed. Seed is and int used to initialize random number generator. The "seed" is a starting point for the sequence and the guarantee is that if you set same seed
you will get the same sequence of numbers again and again.

<a name=gens></a>
## Generate same seq everytime
- Seed rand() by same number
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
<a name=gend></a>
## Generating Different Sequence
- rand() can be called without calling seed(), it will return random no everytime.
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

<a name=prng></a>
## Pseudo Random Number Generator (PRNG)
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
