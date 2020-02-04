/*
	3_stacks_using_1_array.cpp

Method-1: Divide array equally into 3 parts, note top of stacks and perform operations.


Method-2: Single ar[10] will hold 3 stacks and each stack can be of variable size.
- Note top of stacks using top[3]
- Maintain a parallel array of same size as original array prev_index[10] which will hold index of
  previous entry stack.

  | 2 | 11 | 15 | 4 | | | | | | |  arr[]
   s0   s1   s2   s0

  |-1 |-1 |-1 | 0 | | | | | | |  prev_index[]

  |3 |1 |2 |  top[3]	//3 stacks
   s0 s1 s2 

*/
#include<iostream>
using namespace std;

int ar[10];			//Actual stack
int top[3];			//Top of respective stacks
int curr=0;			//Current position of actual array
int prev_entry[10];		//maintains index of previous element in prev_entry

void push(int item, int sn){
	if(curr >= 10){
		cout<<"stack overflow\n";
		return;
	}

	prev_entry[curr]=top[sn];
	top[sn]=curr;
	ar[curr]=item;
	curr++;
}

void pop(int sn){
	cout<<top[sn];
}

int main(){

	for(int i=0;i<3;i++)
		top[i]=-1;
	for(int i=0;i<10;i++)
		prev_entry[i]=-1;

	push(2,0);	//push 1 on stackno=0.	stack0 stores multiples of 2
	push(11,1);	//push 50 on stackno=1	stack1 stores multiples of 11
	push(15,2);	//push 100 on stackno=2	stack2 stores multiples of 15
	push(4,0);	//push 4 on stack=0
	
//	for(int i=0;i<3;i++)
//		cout<<"top["<<i<<"]="<<top[i]<<"\n";
//	for(int i=0;i<10;i++)
//		cout<<"ar["<<i<<"]="<<ar[i]<<"\n";
//	pop(0);
}
