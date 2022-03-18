/*	frequencey of maximum Value
 
 >>>>>>>>>>>>>>>>Only 2 test cases passed<<<<<<<<<<<<<<<<<<<<<
 
 Input array n={5,4,5,3,2} is given
 Index Array q={1,2,3,4,5} is given

 Create a 3rd array using following rule:
 - count maximum elements in input array from q[i] to end
Example:
 q[0]=1 From index=1 to end in input array, maximum element(5) happens 2 times
 q[1]=2 From index=2 to end in input array, maximum element(5) happens 1 time
 q[2]=3 From index=3 to end in input array, maximum element(5) happens 1 time
 q[3]=4 From index=4 to end in input array, maximum element(3) happens 1 time
 q[4]=5 From index=5 to end in input array, maximum element(2) happens 1 time
 Output array {2,1,1,1,1}
*/
#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void f(vector<int> n,vector<int> q){

	int d,s;
	vector<int> p;

	for(int i=0;i<q.size(); i++){
		d = *max_element(n.begin()+i,n.end());
		s = count(n.begin()+i, n.end(), d);
		p.push_back(s);	
	}
	
	for(int i=0;i<p.size(); i++){
		cout<<p[i]<<" ";
	}
}
int main(){
	vector<int> n={5,4,5,3,2};
	vector<int> q={1,2,3,4,5};

	f(n,q);
}
