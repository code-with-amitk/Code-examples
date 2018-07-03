Operator Overloading/Operator Adhoc Polymorphism?
- Different behavior of operators in different context. Example:
	x=6, y=4; x+y=10        x="hey", y="man"; x+y="hey man";

Commonly Overloaded Operators:
	=    +      -      *        /           +=         -=       *=         /=      ==      !=        >>        <<

Operators which cannot be overloaded:
	.(member access)     *(pointer to member)       ?:(Ternary)     sizeof     ::(scope resolution)    typeid

Why sizeof cannot be overloaded?
	 sizeof is compile time operator. ie compiler places value in place of sizeof() at compile time

Can any person Define his own Operators? NO. Language have not defined.

Syntax of overloading an Operator:
	return_type Keyword-operator  Operator-to-overload (arguments)
	const test 	operator  		* 	   (test obj1)
