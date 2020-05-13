/*	stack_constructors.cpp

WHAT? Container Adoptor providing LIFO. introduced in C++11

CONTAINER ADOPTORS(stack, queue, priority_queue)? 
 - These are not full container classes, but classes that provide interface relying on an object of one of the container classes (such as deque or list) to handle the elements.
 - Stacks are internally implemented using deque

CONSTRUCTORS:
  1. Default Ctr

  2. Copy Ctr
  	2a. Normal Copy ctr as shown below

	2b. Construct stack using Alloc as allocator:
	    template< class Alloc >
	    explicit stack( const Alloc& alloc );

	2c. Construct stack using srcObj & Alloc as allocator
	    template< class Alloc >
	    stack( const Container& srcObj, const Alloc& alloc );	

  3. Move Ctr
  	3a. Normal move ctr as shown below

	3b. Construct stack using movement from srcObj & Alloc as allocator
	    template< class Alloc >
	    stack( Container&& srObj, const Alloc& alloc );


ASSIGNMENT OPERATOR:	    
  4. Copy Assignment operator
  5. Move Assignment operator
  	Return value: (*this)
*/

#include<iostream>
#include<stack>
using namespace std;

int main(){

	/* 1. DEFAULT CTR: Does not take any arguments

	  stack() : stack(Container()) { }
	 */
	stack<int> s1;
	s1.push(5);
	cout<<s1.size()<<endl;		//1


	/* 2. COPY CTR: constructs new stack object using old object

	  explicit stack( const Container& srcObj );
	 */
	stack<int> s2(s1);		//1
	cout<<s2.size()<<endl;	


	/* 3. MOVE CTR: Moves contents from old to new
	  explicit stack( Container&& srcObj );	 
	 */
	stack<int> s3(move(s2));
	cout<<s3.size()<<endl;	


	/* 4. COPY ASSIGNMENT OPERATOR: Copies srcObj contents

	   stack& operator=( const stack& srcObj );
	 */
	stack<int> s4=s1;
	cout<<s4.size()<<endl;		//1


	/* 5. MOVE ASSIGNMENT OPERATOR: Moves contents of srcObj t0 dst.
	 
	   stack& operator=( stack&& srcObj );
	 */
	stack<int> s5 = move(s4);
	cout<<s4.size()<<endl;		//0
}
