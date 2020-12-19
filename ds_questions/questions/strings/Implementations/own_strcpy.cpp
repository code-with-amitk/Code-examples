/*
Problem: Writing our own strcpy function. taking 2 arguments should copy src to dst.

char *strcpy(char *dst, char *src)                      //C++ library provided strcpy()
- copies src to dst including terminating NULL character.
- To avoid overflows, the size of the array pointed by destination shall be long enough to contain the source
- if overflow happens its upto programmer.

*************Logic*****************
- pass src,dst strings, collect in ptr
- in while loop copy src to dst
- return dst
***********************************
*/

#include<iostream>
using namespace std;

                //test      "hello sandy"
char *mystrcpy(char *dst, char *src){
        int i=0;

        while(src[i] != '\0'){
                dst[i] = src[i];
                i++;
        }
        return dst;
}

int main(){
        char a[15]="test";
        char b[15]="hello sandy";
                //dst,src
        cout<<mystrcpy (a, b)<<"\n";
        cout<<a;
}
/*
Ouput:
hello sandy
hello sandy
*/
