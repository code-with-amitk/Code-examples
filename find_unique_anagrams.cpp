/*	find_unique_anagrams.cpp

Anagram? This is a word or phrase formed by rearranging the letters of a different word or phrase

Question:
- Given vector<string> t = {"code", "doce", "test", "testing"}. 
- You need to return a vector only having 1st occurence of anagram. Example "code" and "doce" are anagrams.
- Return value should be {"code", "test", "testing"}

Logic:
- Traverse through elements in vector t
	- sort the element
	- search sorted_element in unordered_set	//O(1)
		if(element_not_found)	
			insert_element
			Note the index

- Create a new vector from noted_indexes and return
*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

vector<string> fun(vector<string> t1){

	unordered_set<string> us;

	vector<string> s, t=t1;
	vector<int> a;
	int pos = 0;

	for(auto i=t.begin(); i != t.end(); i++){
		pos++;

		sort((*i).begin(), (*i).end());

		if(us.find(*i) == us.end()){		
			us.insert((*i));
			a.push_back(pos);
		}
	}

	for(auto i=a.begin(); i != a.end(); i++){
//		cout<<"positions= "<<(*i);
		s.push_back(t1[(*i)-1]);
	}

	return s;
}

int main(){
	vector<string> t = {"code", "doce", "test", "testing"};
	vector<string> f = fun(t);

	for(auto i=f.begin(); i != f.end(); i++){
		cout<<*i<<" ";
	}
	return 0;
}
