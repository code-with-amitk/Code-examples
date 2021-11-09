- [Reconstruct Itinerary](#q)
- [Approach-1](#ap1)

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
map<key=airport, value=multiset<airport>>

|key=JFK, balanced_bst | key=ATL, balanced_bst | key=SFO, balanced_bst |
            |                        |                        |
           ATL                      JFK                      ATL
             \                        \
              SFO                     SFO
```
- _2._ Start from "JFK"

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
	map<string, multiset<string>> mTargets;
	vector<string> route;
public:
	void Visit(string airport) {

		//Check all airports which can be reached from this airport
		while (mTargets[airport].size()) {

			//Find 1st airport in multiset(which can be reached)
			auto it = mTargets[airport];
			string nextAirport = *it.begin();

			//Since we have visited this from present, delete
			mTargets[airport].erase(mTargets[airport].begin());

			//Visit next airport
			Visit(nextAirport);
		}

		//When there is no airport to visit, push present on route
		route.push_back(airport);
	}

    VectorString findItinerary(VectorVectorString& tickets) {
		//Create Edge List
		for (auto i : tickets) {
			mTargets[i[0]].insert(i[1]);
		}

		//Start from "JFK"
		Visit("JFK");
		return vector<string>(route.begin(), route.end());
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
