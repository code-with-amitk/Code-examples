### Anagram? 
- This is a word or phrase formed by rearranging the letters of a different word or phrase
### Problem
- From array of strings, delete all anagrams, only keep 1st occurence.
```c
Input = {"code", "doce", "test", "testing"}. 		//code, doce are anagrams
Output = {"code", "test", "testing"}			//deleted subsequent anagrams
```

### Logic:
1. Sort strings
```c
  {"cdeo", "cdeo", "estt", "eginstt"}
```
2. Insert element into unordered_set (if does not exist)
	- search sorted_element in unordered_set	//O(1)
		if(element_not_found)	
			insert_element
			Note the index

3. Create a new vector from noted_indexes and return


### Code
```c
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
```
