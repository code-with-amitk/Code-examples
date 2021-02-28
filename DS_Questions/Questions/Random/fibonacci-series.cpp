/*	fibonacci-series.cpp

Fibonacci-series? Series of numbers in which each number is the sum of 2 preceding numbers. Eg: 1, 1, 2, 3, 5, 8
*/


/*	Method-1: recursive_solution.cpp
                         f(5)
			 ret f(4)+f(3)
               f(4)                		f(3)
	       ret f(3)+f(2)

        f(3)      	f(2)         		f(2)    f(1)
	ret f(2)+f(1)

  f(2)   		f(1)  f(1) f(0) f(1) f(0)
  ret f(1)+f(0)

f(1) ret 1

f(0) ret 1

=> f(3),f(2) all needs to be recalculated
*/
#include<iostream>
using namespace std;
#ifdef RECURSION
int f(int n){
	if (n <= 1)
		return n;
	return f(n-1) + f(n-2);
}

int main(){
	cout<<f(5);
}
#endif


/*	Method-2: Memoization-Dynamic-Programming

Logic:
|-1|-1|-1|-1|-1|-1|-1|
lookup

Return lookup entry instead of calculating again!
*/
#ifdef Memoization_Dynamic_Programming
int lookup[10];

int f(int n){
	if(lookup[n] == -1){
		if(n<=1)
			lookup[n]=n;
		else
			lookup[n]=f(n-1)+f(n-2);
	}
	return lookup[n];
}

int main(){
	for(int i=0;i<10;i++)
		lookup[i]=-1;
	cout<<f(5);
}
#endif


/*	tabulation-dynamic-programming
- builds a table in bottom up fashion and returns the last entry from table.	
*/

int fib(int n)
{
  int f[n+1];
  int i;
  f[0] = 0;   f[1] = 1;
  for (i = 2; i <= n; i++)
      f[i] = f[i-1] + f[i-2];

  return f[n];
}

int main ()
{
  int n = 9;
  printf("Fibonacci number is %d ", fib(n));
  return 0;
}


