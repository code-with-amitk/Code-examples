- [Reconstruct Itinerary](#q)
- [Approach-1](#ap1)
  - [Logic](#l1)
  - [Complexity](#comp)
  - [Code](#c1)

<a name=q></a>
### Reconstruct Itinerary
- You are given a list of airline tickets where `tickets[i] = [fromi, toi]` represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
- All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
- For example, the itinerary `["JFK", "LGA"]` has a smaller lexical order than `["JFK", "LGB"]`.
- You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
```c
Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

  SFO   <-------     ATL
        ------->     /\ |
  /\                 |  |
   |                 |  |
  JFK ---------------|  |
      <------------------
```

<a name=ap1></a>
### Approach-1
<a name=l1></a>
#### Logic
- _1._ Create directed graph. Graph can have duplicate entries. Since person can travel same airport multiple times.
```
//map = multiset = Balanced BST(RBT)

map<key=airport, value=multiset<airport>>

             | key=JFK, value=ATL |
                    /  \        \
                   /    \        SFO
    |key=ATL,value=JFK|  |SFO,ATL|
	             \
                     SFO
```
- _2._ Start from airport="JFK", jump to connected airport(from value) and remove multiset. Pushback on vector while unwinding the stack.
```c
                                 visit(jfk) //1
                                   while(2)
                                     next = atl
                                       remove atl
                                         visit (atl)
                                  
		          visit(atl)  //2
			   while(2)
                            next=jfk
			     remove jfk
			     visit (jfk)                   |jfk,sfo|
			                                    /      \
                                                         |atl,sfo| |sfo,atl|
                       visit(jfk)  //3
		        while(1)
			 next=sfo
			 remove sfo
			 visit(sfo)                       |jfk|
                                                       /        \
						     |atl,sfo|  |sfo,atl|
                     visit(sfo)  //4
		      while(1)
		       next=atl
		       remove atl
		       visit(atl)                           |jfk|
		                                           /     \
						    |atl,sfo|    |sfo|
                   visit(atl)  //5
		    while(1)
		     next=sfo
		     remove sfo
		     visit(sfo)                         |jfk|
		                                       /    \
						      |atl|  |sfo|
                  visit(sfo)  //6
		   while(0)
		   route.push_back(sfo)
		   
		   route.push_back(atl)  //5
		   route.push_back(sfo)  //4
		   route.push_back(jfk)  //3
		   route.push_back(atl)  //2
		   route.push_back(jfk)  //1		   
```
- _3._ Reverse the vector to obtain route.

<a name=comp></a>
#### Complexity
```c
n : number of airports
m : number of airports connected to n
```
- **Time:** O(nm)
- **Space:** O(n+m)

<a name=c1></a>
#### Code
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using VectorString = vector<string>;
using VectorVectorString = vector<VectorString>;

class Solution {
	map<string, multiset<string>> mGraph;
	VectorString route;
public:
	void Visit(string airport) {

		//Check all airports which can be reached from this airport
		while (mGraph[airport].size()) {

			//Find 1st airport in multiset(which can be reached)
			auto it = mGraph[airport];
			string nextAirport = *it.begin();

			//Since we have visited this from present, delete
			mGraph[airport].erase(mGraph[airport].begin());

			//Visit next airport
			Visit(nextAirport);
		}

		//When there is no airport to visit, push present on route
		route.push_back(airport);
	}

    VectorString findItinerary(VectorVectorString& tickets) {
		//Create Edge List
		for (auto i : tickets) {
			mGraph[i[0]].emplace(i[1]);
		}

		//Start from "JFK"
		Visit("JFK");
		return VectorString(route.begin(), route.end());
    }
};

int main()
{
	VectorVectorString v = {
		{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}
	};
	Solution s;
	VectorString o = s.findItinerary(v);
	return 0;
}
```
