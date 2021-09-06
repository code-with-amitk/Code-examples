/*	naive_algorithm.cpp

CASES WHERE NAIVE DOES NOT WORK WELL:
A. Many matching characters followed by a mismatching character. 
   txt[] = "AAAAAAAAAAAAAAAAAB"
   pat[] = "AAAAB"

Complexity = O(mn)	
*/
#include<iostream>
#include<string>
#include<vector>
#include <cstring>
#include<chrono>
using namespace std;
using namespace std::chrono;

vector<int> fun(string str, string pat){
	vector<int> index;

	int ssize = str.size();		//5
	int psize = pat.size();		//3
	int i=0,j=0,k=0;

	while(i < ssize){
		if(str[i]==pat[j]){
			k = i;
			while(str[k]==pat[j] && j<psize){
				if( j == psize -1 ){
//					cout<<"ss found index="<<i<<endl;
					index.push_back(i);
				}
				k++;j++;
			}
			j=0;
		}
		i++;
	}

	return index;
}

int main(){
	string txt = "EEFAABBCCDDEEFFGGEEFAABBCCDDEEFFGGEEFAABBCCDDEEFFGGEEFAABBCCDDEEFFGGEEFAABBCCDDEEFFGGEE";
//	string txt = "EEFAABBCCDDEEFGG";

//	string txt = "AEEFD";
//	string pat = "EEF";
	string pat = "EEFAABBCCDDEEFFGG";
	vector<int> v;

	auto startTime = high_resolution_clock::now();

	v = fun(txt,pat);

	cout<<"Substring found at indexes = ";
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	auto stopTime = high_resolution_clock::now();
    	auto duration = duration_cast<microseconds>(stopTime - startTime);	
	cout<<"Time taken="<<duration.count()<<" microsec\n"; 
}
/*
 *OPTIMIZED CODE RUNS FASTER THAN UNOPTIMIZED CODE
 # g++ navie-algorithm.cpp -O2 -Wall -Wextra -Wpedantic
 # ./a.out
Substring found at indexes = 0 11
Time taken=15 microsec
*/
