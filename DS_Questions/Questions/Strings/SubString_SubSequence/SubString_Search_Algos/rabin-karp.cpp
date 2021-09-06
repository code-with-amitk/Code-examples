/*	rabin-karp.cpp

https://amitkumar25nov.wordpress.com/rabin-karp-pattern-searching/	
https://www.quora.com/What-is-a-rolling-hash-and-when-is-it-useful

Pattern Searching Algorithm(PSA)? Algos searching a pattern inside given text.
Example:
 txt = "AEEFD";		//len=n
 pat = "EEF";		//len=m

Problem: Find indexes of pattern in txt.
Answer: pat[m] occurs in txt[] at indexes 1

Approach of rabin-karp?
 - Works on Sliding window.
 - Hash of pattern is compare with text window. size of text window = pattern size.
 - if hashes does not match, text window is slided by one to right.
 - New hash is not recalculated rather its calculated using:
 	oldhash + outgoing character + incoming character
 - if hashes of text window and pattern matches, compare each letter in string, Since hash collisions can happen.


***********Logic of RABIN-KARP-ALGORITHM(RKP)************
//ASCII TABLE A=65,B=66,C=67,D=68,E=69,F=70
Base-26 Number system: ONLY 26 CAPITAL LETTERS (A,B...Z)
BASE-52 Number system: (A..Z a..z)
BASE-62 Number system: (A..Z a..z 0..9)

Example:
 txt = "AEEFD";
 pat = "EEF";

a. AEEFD 
   EEF
b. AEEFD
    EEF
c. AEEFD
     EEF

Step-1: Calculate hash of pattern. 
	phash = hash(pat[]) = hash("EEF") = 69*26^0 + 69*26^1 + 70*26^2 = 49183
        	
Step-2: Window size = pattern size.
	Window is at index=0, "AEE"
	thash = hash("AEE") = 65*26^0 + 69*26^1 + 69*26^2 = 48503

	if (Hash(pat[]) == Hash("AEE")){
		No
	}

Step-3: Slide window by 1. Window is at index=1, "EEF"
	Calculate hash of "EEF".
	- Hash will not be recalcualted rather its calculated using oldhash,leavingCharacter('A') and incomingCharacter('F')

	Steps mentioned below(a,b,c) are carried in O(1) time:
	a. tempHash = oldhash - A = 48503 - 65 = 48438
	   We have just deducted character present at index[0] from oldhash.
	   Now its equivalent to:
	   	EF = 69*26^1 + 69*26^2
	b. tempHash = tempHash/base = (69*26^1 + 69*26^2)/26 = 69*26^0 + 69*26^1
	c. tempHash = 69*26^0 + 69*26^1 + 70*26^2	//70 is ascii of F
	hash(txt[1:4]) = hash("EEF") = 69*26^0 + 69*26^1 + 70*26^2 = 49183

        if (Hash(pat[]) == Hash("AEE")){
                Compare each alphabet of pat[] with txt[1:4]    //1:4 means 1,2,3
                        - if all alphabets match, note index
        }
	
Step-4: Repeat step-3
**********************************************************

**********************COMPLEXITY*****************************
n=txt size, m=pattern size
SPACE: VECTOR for storing indexes. Max=n. O(n)
TIME:  
	O(1) - hash is calculated
	Worst case : O(mn)
		- We are unlucky and getting every hash equal to pattern hash
		txt = "ABABABACAB"
		pat = "AC". hash(pat)=x
		index=0 hash(txt[0:2])=x
		We will do strcmp -> O(n)
		For every substring we need to compare with pattern.
		O(m) -> comparing each character of pattern
		O(n) -> Length of txt
		O(mn)
	Best Case: O(m+n)
		- Hash function gives accurate and unique hashes.
		- Comparing 1st character of txt with pat -> O(n)
		- whenever 1st character matches doing m strcmps -> O(m+n)
**********************************************************

*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<chrono>
using namespace std;
using namespace std::chrono;

#define BASE 26			//ONLY 26 CAPITAL LETTERS (A,B...Z)
//#define BASE 52		//26 small & 26 capital letters (A..Z a..z)
//#define BASE 62		//Includes digits (A..Z a..z 0..9)

int findhash(string str=NULL, int prevhash=0){
	int hash=0,i=0;
	int ssize = str.size();

	if(!prevhash){
	        while(i < ssize){
        	        hash += str[i]*pow(BASE,i);
        	        i++;
        	}
	}else{		//Calculating Rolling Hash
		hash = prevhash - str[0];
		hash /= BASE;
		hash += str[ssize-1]*pow(BASE,(ssize-2)); 
	}
	return hash;
}

vector<int> search(string txt, string pat)
{
	unsigned pathash=0,txthash=0;
	int psize = pat.size(),i;		//3
	int tsize = txt.size();		//5

	vector<int>index;

	pathash = findhash(pat);
//	cout<<"pathash="<<pathash<<endl;

	while(i <= tsize - psize){	//Going till (end - patsize)

		if(i==0)
			txthash = findhash(txt.substr(i,psize));
		else
			txthash = findhash(txt.substr(i-1,psize+1), txthash);

		if(txthash == pathash){
			if(!txt.substr(i,psize).compare(pat)){	//str1.compare(str2)
				index.push_back(i);
				i=i+psize-1;
			}
		}
		i++;
	}
	return index;

}

int main()
{
	string txt = "AEEFD";
	string pat = "EEF";
	vector<int> v;

	auto startTime = high_resolution_clock::now();

	v = search(txt, pat);
	cout<<"Pattern appears at indexes: ";
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

        auto stopTime = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stopTime - startTime);
        cout<<"Time taken="<<duration.count()<<" microsec\n";	
    	return 0;
}
