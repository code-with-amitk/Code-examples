**Sort list of cities / list of pairs**
- Approach=Sorting using comparator
  - [Logic](#l)
  - [Code](#c)

### Arrange Cities in proper order by Population
- Sort list of cities in right order
- Give list of tuples. 
- Tuple represents (population_of_present_city, Number of cities on its left whose population >= this city's population)
- Examples:
```c
Example-1
        a          b        c         d         e
Input: [8000,1], [5000,3], [8000,0], [6000,2], [6000,0]
    city          a       b     c     d       e
    population:   8000    5000  8000  6000   6000
    //There should be:
      1 cities to left of city=a, whose population >= 8000.
      3 cities to left of city=b, whose population >= 5000
      0 city to left of city=c, whose population >= 8000
      2 city to left of city=d, whose population >= 6000      
      0 cities to left of city=e, whose population >= 6000

Output: [6000,0] [8000,0] [6000, 2] [5000, 3] [8000, 1]

Example-2
        a         b       c         d
Input: [800,0], [700,0], [300,1], [600,2]
  0 cities to left of city=a whose population >= 800
  0 cities to left of city=b whose population >= 700
  1 city to left of city=c whose population   >= 300
  2 cities to left of city=d whose population >= 600

Output: [700,0][300,1][800,0][600,2]
```

### Approach=Sorting using comparator
<a name=l></a>
#### Logic
- _1._ Sort in decending order by population
```c
input = [8000,1], [5000,3], [8000,0], [6000,2], [6000,0]

1a. sorted in desc order by population:
        [8000,1] [8000,0] [6000,2] [6000,0] [5000,3]
        
1b. if population is same, sort by second element
        [8000,0] [8000,1] [6000,0] [6000,2] [5000,3]
```
- _2._ Arrange tuples as per indexes obtained in step-1b
```c
    [8000,0] [8000,1] [6000,0] [6000,2] [5000,3]
    
    Index of:
      [6000,0] should be 0.   [6000,0] [8000,0] [8000,1] [6000,2] [5000,3]
      [6000,2] should be 2.   [6000,0] [8000,0] [6000,2] [8000,1] [5000,3]
      [5000,3] should be 3.   [6000,0] [8000,0] [6000,2] [5000,3] [8000,1]
      
Ans: [6000,0] [8000,0] [6000,2] [5000,3] [8000,1]
```
<a name=c></a>
#### Code
**CPP**
```c
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
using mpair = pair<int,int>;

bool comparator(pair<int,int> p1, pair<int,int> p2){
    if(p1.first == p2.first)
      return p1.second < p2.second;

    return p1.first > p2.first;
}

//i = {8000,1}, {5000,3}, {8000,0}, {6000,2}, {6000,0}
vector<mpair> fun(vector<mpair> input) {
    vector<mpair> o;

    sort(input.begin(), input.end(), comparator);

    //After sort
    //i = {8000,0}, {8000,1}, {6000,0}, {6000,2}, {5000,3}

    for (int i=0; i<input.size(); ++i)
        o.insert(o.begin()+input[i].second, input[i]);

    return o;
}

int main(){
    vector<pair<int,int>> i = {{8000,1}, {5000,3}, {8000,0}, {6000,2}, {6000,0}};
    vector<mpair> o = fun(i);
    for (auto j:o){
        cout << j.first <<"," << j.second;
        cout <<"\n";
    }
}
# ./a.out
6000,0
8000,0
6000,2
5000,3
8000,1
```
