/*	fold_expression.cpp
https://en.cppreference.com/w/cpp/language/fold

FOLD? means reducing or compressing

FOLD EXPRESSION?
 - Reduces (folds) a parameter pack over a binary operator.
 - Provides way to apply binary operation to the elements of a parameter pack.

SYNTAX:
1. Unary left fold: pack-variable on right
  (... operator pack-variable)

2. Unary right fold: Pack-variable on left
  (pack-variable operator ...)

3. Binary right fold: Pack-variable on left
  (pack-variable operator ... operator initial-value)

4. Binary left fold: pack-variable on right
   (initial-value operator ... operator pack-variable)

pack-variable: unexpanded parameter pack expression

operator: any of the following 32 binary operators: + - * / % ^ & | = < > 
<< >> += -= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*. 
In a binary fold, both ops must be the same.

initial-value: an expression that does not contain an unexpanded parameter
pack and does not contain an operator with precedence lower than cast at
the top level (formally, a cast-expression)
*/


#include<iostream>
using namespace std;

/*1. UNARY LEFT FOLD
     ( ... + a) becomes ((((1+2)+3)+4)+5)
     (... op ai) becomes (((a1 op a2) op ...) op an)
     - Where, N is number of elements in pack expansion.
     - Applying binary operator(+) and expands folds/parameter pack
*/
template<typename ... T>
auto sum(T ... a){
	return ( ... + a);
}

template<typename... T>
auto mult(T... a) { 
	return (... * a); 
}


/*2. UNARY RIGHT FOLD
     (a % ... ) becomes (49%(10%4))
     (a op ...) becomes (a1 op (... op (an-1 op an)))
     - Applying binary operator(%) and expands folds/parameter pack
*/
template<typename... T>
auto mod(T ... a){
	return (a % ... );
}


/*3. Binary right fold
     ((a + ...) * 10) becomes ((1+(2+(3)))*10)
     (a op ... op initial-value) becomes (a1 op (... op (an−1 op (an op initial-value))))

What this function does?
 - Add all values in parameter pack and multiply with last.
*/
template<typename... T>
auto addAndMult(T ... a) {
	return((a + ...) * 10);		
	//lower precedence operator should be grouped in () with parameter pack
}


/*4. Binary left fold: Pack-variable on right
     10 * (... / a)) becomes ((((10 * 100)/2)/5)/10)
     (initial-value op ... op ai) becomes ((((initial-value op a1) op a2) op ...) op an)

What this function does?
 -  and multiply with last.
*/
template<typename... T>
auto multiplyDivide(T ... a) {
        return(10 * (... / a));
}

int main(){
	cout<<sum(1,2,5,6)<<endl;	//Output:14
	cout<<mult(1,2,5,6)<<endl;	//Output:60
	cout<<mod(49,10,4)<<endl;	//Output:1
	cout<<addAndMult(1,2,3,10)<<endl;	//Output:160
	cout<<multiplyDivide(100,2,5,10)<<endl;	//Output:10
}
