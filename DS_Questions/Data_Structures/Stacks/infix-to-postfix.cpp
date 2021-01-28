/*
        infix-to-postfix.cpp

        3 + 6        [3 Operand, + Operator]
Rules:
1. if received operand->Just display
2. if received operator 
        a. Push on stack, under these conditions:
           a1. if stack is empty.
           a2. if higherPrecedence operator is recieved wrt stackTop
           a3. if '('
           a4. Ignore every-rule, just push if top of stack='('.
        b. Pop the stack and display under conditions:
           b1. topStackPrecendence >= RecievedOperatorPrecendence. Pop all higher_or_equal precendence operators and push current operator on stack.
           b2. if ')' recieved, pop and display until '('

Input "a+b*(c^d-e)^(f+g*h)-i"
Output  "abcd^e-fgh*+^*+i-"

How output is achieved?
o/p -> a         b              c        d    ^     e    -              f       g        h   *+  ^*+  i    -
stack | |  |+| same  |*|  |(|  same |^| same |-|  same  |*|  |^|  |(| same |+| same |*| same |^| |-| same | |
                     |+|  |*|       |(|      |(|        |+|  |*|  |^|      |(|      |+|      |*|
                          |+|       |*|      |*|             |+|  |*|      |^|      |(|      |+|
                                    |+|      |+|                  |+|      |*|      |^|
                                                                           |+|      |*|
                                                                                    |+|

Rules 1    a1   1    a2   a3    1   a4  1    b1     1   b2                 a4       a2       b2  b1
*/

#include<iostream>
#include<stack>
using namespace std;

class test{
        string str;
        stack <char> s;
public:
        test(string a):str(a){
                cout<<str<<endl;
        }
        void infixToPostfix();
        int getPrecendence(char a){
                int val;
                if(a=='^') return 3;
                else if(a=='*' || a == '/') return 2;
                else if(a=='+' || a == '-') return 1;
                else return -1;
        }
};

void test::infixToPostfix(){
        int currPrec = -1;
        int stackTopPrec = -1;

        for(auto i=0;i<str.size();i++){
//              cout<<"str["<<i<<"]="<<str[i]<<"\n";

                if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){       //Opearand
                        cout<<str[i]<<" ";
                }else{                                                                          //Operator
                        if(str[i]!=')' || str[i]!='('){
                                currPrec = getPrecendence(str[i]);
                                if(s.empty()!=1) stackTopPrec = getPrecendence(s.top());
                        }

                        if(!s.size() || (stackTopPrec < currPrec) || str[i]=='(' || s.top()=='('){
//                              cout<<"Pushing "<<str[i]<<endl;
                                s.push(str[i]);
                        }

                        if(stackTopPrec >= currPrec && str[i] != '('){
                                while((getPrecendence(s.top()) >= currPrec) && s.empty()!=1 && s.top()!='('){
                                        char x = s.top();s.pop();
                                        cout<<x<<" ";
                                }
                                s.push(str[i]);
                        }

                        if(str[i]==')'){
                                while(s.top()!='('){
                                        char x = s.top();s.pop();
                                        if(x != '(' && x != ')')
                                                cout<<x<<" ";
                                }
//                              s.pop();
                        }
                }
        }

        while(s.empty()!=1){
                char x = s.top();s.pop();
                cout<<x<<" ";
        }
}

int main(){
        string s = "a+b*(c^d-e)^(f+g*h)-i";
        test t(s);
        t.infixToPostfix();
}
