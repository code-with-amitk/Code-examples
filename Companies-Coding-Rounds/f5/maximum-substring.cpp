/* Lexicographical Maximum substring of string

https://www.geeksforgeeks.org/lexicographical-maximum-substring-string/

Example: 
Input = "banana"
substrings = [b,ba,ban,bana,banan,banana,a,an,ana,anan,anana,n,na,nan,nana,ana,na,a]
Lexigraphical ordered=[a,ana,anan,anana,b,ba,ban,bana,banan,banana,n,na,nan,nana]
Output: nana


***************Logic*****************
- max(const T& a, const T& b): Returns the greater of the given values.
- Note max substring, iterate through string and update
*************************************
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string LexicographicalMaxString(string str) 
{ 
	string mx = "";
    	for (int i = 0; i < str.length(); i++)
        	mx = max(mx, str.substr(i));

    	return mx;
} 

int main(){
	string s = "banana";
	cout<<LexicographicalMaxString(s);
}
