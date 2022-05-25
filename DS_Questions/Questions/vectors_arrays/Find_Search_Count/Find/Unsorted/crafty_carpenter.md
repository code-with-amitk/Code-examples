Crafty Carpenter

### Crafty Carpenter
A carpenter is working on items at his workbench. The carpenter works on a lot of different items one after another, but unfortunately the bench only has space to hold one item at a time. So, once the carpenter completes work on a particular item, he stores it in a cabinet. Then, he either goes back to his bench to create another item, or he continues working on one of the existing, previously stored, items. He has a number of cabinets in his shop to store these items in.
It takes several iterations for the carpenter to finalize an item. When he continues work on a previously created item, he takes it out of the correct cabinet takes it back to the bench, works on them, and then stores it in a cabinet again. Then be takes out the next item, takes it back to the bench, etc, etc. He does.. many times a day.
It is very likely that the carpenter will be re-using an item be worked on recently. Because of this, be wants to store the most recently used items in the cabinet closest to the bench, and the least recently used items in the cabinet furthest away.
Each of these cabinets is limited in size, meaning: each cabinet can only store a limit. number of items. Each item is the same size (1), and identified with a 'numerical key (integer) for administrative purposes. When a cabinet is full, the item used least recently from that cabinet is moved to the next (further away) cabinet. If all cabinets are full, the oldest item is stored outside of the shop, where there is infinite amount of space.
Please help the carpenter optimize storage of these items as described above by modelling this process in code.

- Input
First line: specification of the sizes of the cabinets On order of nearest to furthest away) represented as an array of space-separated integers (e.g. “2 5 4 3”. Number of integers == number of cabinets (N).
Second line: number of lines (K) of input to follow.
Next K lines:
numerical key (integer) of the next item to be worked on by the carpenter
Input Value Ranges
```c
0 < cabinet size < 2^10
0 < N < 2^6
0 < K < 2^32
0 < numerical key < 2^32
Output The output of the your program should be one of the following:
```
An integer representing the cabinet the last item (as specified by the last line of input) was taken from, ranging from 1 (nearest) to N (furthest)
NEW if the item was newly created
OUTSIDE if the item was outside
INPUT_ERROR if the input was somehow incorrect
- Examples
```c
Input-1:
2 2 4
7
1
2
3
4
5
6
2 
Output-1: 3

Input-2:
2 4
5
83674
28736
398
109283
64832
Output-2:NEW

Input-3:
8
10
1
2
3
4
5
6
7
8
9
1
Output-3: OUTSIDE
```

### Code
```cpp
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int main() {
    list<uint32_t> l;
    string size_of_cabinets, temp_str;
    int no_of_inputs, all_cabinets_capacity;
    getline(cin, size_of_cabinets);
    stringstream ss(size_of_cabinets);
    vector<int> cabinet_sizes;
    while(getline(ss, temp_str, ' ')){              //Space tokenization
        int val;
        istringstream(temp_str) >> dec >> val;
        if (val <= 0 || val>=1024) {   //Cabinet cannot have 0 capacity
            cout << "INPUT_ERROR";
            return 0;
        }
        cabinet_sizes.push_back(val);
        all_cabinets_capacity += val;
    }

    unordered_set<uint32_t> outside;

    //key=value_in_bucket
    unordered_map<int, list<uint32_t>::iterator> umInCabinet;

    cin >> no_of_inputs;
    if (no_of_inputs <= 0) {
        cout << "INPUT_ERROR";
        return 0;
    }
    int i;
    for (i=0;i<no_of_inputs;++i){
        uint32_t item;
        cin >> item;
        if (i==no_of_inputs-1) {    //This is last item. Need to find its position

            // for (auto&i:l){
            //     cout << i << ", ";
            // }
            if (outside.find(item) != outside.end()) {
                cout << "OUTSIDE";
            } else if (umInCabinet.find(item) != umInCabinet.end()) {
                int cabinet_number = 1;
                int i=1, j=0;
                //Count Number of cabinets from front till item is found
                auto itr = l.cbegin();
                while (itr != l.cend()){
                    if (i++ == cabinet_sizes[j]){
                        j++;
                        cabinet_number++;
                        i=1;
                    }
                    if (*itr == item){
                        //cout << "cab:" << cabinet_number;
                        if (cabinet_sizes[j] == 1)
                            cabinet_number--;
                        cout << cabinet_number;
                    }
                    ++itr;
                }
            }
            else {
                cout << "NEW";
            }
        }
        else {

                //if item is present in Deque, Go to index delete and insert in front
                auto itr = umInCabinet.find(item);
                if (itr != umInCabinet.end()){
                    auto sec = itr->second;
                    l.erase(sec);
                    umInCabinet.erase(item);
                    l.emplace_front(item);
                    umInCabinet[item] = l.begin();
                }
                else        //if item is not present in list
                {
                    if (i < all_cabinets_capacity) {
                        //And list has space
                        //Simply insert at front.
                        l.emplace_front(item);
                        umInCabinet[item] = l.begin();
                    }
                    else
                    {
                        //item not present in list
                        //No space in list
                        //Remove last
                        int val = l.back();
                        outside.insert(val);
                        l.pop_back();
                        umInCabinet.erase(val);

                        l.emplace_front(item);
                        umInCabinet[item] = l.begin();
                    }
                }
        }
    }
    return 0;
}
```
