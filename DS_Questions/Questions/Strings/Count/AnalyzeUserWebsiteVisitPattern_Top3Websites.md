**Analyze User Website Visit Pattern**
- [Approach-1, HashMap, O(n<sup>3</sup>)](#a1)

### [Analyze User Website Visit Pattern / Top 3 visited websites](https://leetcode.com/problems/analyze-user-website-visit-pattern/)
- Users visit websites at particular timestamps.
- Find top 3 visited websites in increasing seq of time, ie if website is visited earlier we should list earlier.
```c
Input:
username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"]
timestamp = [1,2,3,4,5,6,7,8,9,10]
website = ["home","about","career","home","cart","maps","home","home","about","career"]
//user=joe visited website=home at timestamp=1
//user=joe visited website=about at timestamp=2

Output: ["home","about","career"]
Explanation: The tuples in this example are:
["joe","home",1],["joe","about",2],["joe","career",3],["james","home",4],["james","cart",5],["james","maps",6],["james","home",7],["mary","home",8],["mary","about",9], and ["mary","career",10].
The pattern ("home", "about", "career") has score 2 (joe and mary).
The pattern ("home", "cart", "maps") has score 1 (james).
The pattern ("home", "cart", "home") has score 1 (james).
The pattern ("home", "maps", "home") has score 1 (james).
The pattern ("cart", "maps", "home") has score 1 (james).
The pattern ("home", "home", "home") has score 0 (no user visited home 3 times).
```

<a name=a1></a>
### Approach-1, HashMap
#### Logic
- _1._ Create `unordered_map< username, map<timestamp, website>>`. This will create a ordered list of websites which user visited.
```cpp
 user   map<timestamp,website>
|joe, <<1,home>, <2,about>, <3,carrer>> | james, <........> | mary, <........> |
```
- _2._ Now instead of creating tuple, Create a string by combining 3 website names. `unordered_map <3Websites, count>`
```cpp
  | home$about#carrer, 2 | home$cart#home, 1 | home$cart#maps, 1 | home$maps#home, 1 | cart$maps#home, 1 | 
```
- _3._ Find max value from unordered_map in step2. if 2 or more values are same find lexiographically smaller string
- _4._ Break the string into vector and return

#### Complexity
- **Time:** O(n<sup>3</sup>). n: Number of user
  - O(n): Creation of `unordered_map<string, map>`
  - O(n<sup>3</sup>): creation of `unordered_map<string,int>`
- **Space** O(nm). n: Number of user, m: websites visited by user
  - O(nm): Creation of `unordered_map<string, map>`
  - O(m): Creation of `unordered_map<string, map>`

#### Code
```cpp
using vecS = std::vector<std::string>;
using vecI = std::vector<int>;
using String = std::string;
using mapIS = std::map<int, String>;
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
       vecS out;

        //Create a hashMap of maps
        /*                                     |8,home|9,about|10,career|
                 |1,home|2,about|3,career|     /\
                 /\                            |
            |joe, | | james,  | | mary, -------  |
                             \/
                             |4,home|5,cart|6,maps|7,home|
        */
        std::unordered_map<String, mapIS> m;
        for (auto i=0; i<username.size(); ++i)
            m[username[i]][timestamp[i]] = website[i];

        std::unordered_map<String, int> um;

        //Create unordered_map<String, count> of 3 websites
        /*  home$about#career

            | home$about#career, 2 | home$cart#maps, 1 | home$maps#cart,1 |
        */
        for (auto u : m) {
            std::unordered_set<String> ts;
            for (auto it = begin(u.second); it != end(u.second); ++it)
              for (auto it1 = next(it); it1 != end(u.second); ++it1)
                for (auto it2 = next(it1); it2 != end(u.second); ++it2)
                  ts.insert(it->second + "$" + it1->second + "#" + it2->second);
                for (auto s : ts) ++um[s];
        }
        
        //Find Lexiographically smallest string having max number
        //of occurences
        int cnt = 0;
        String s;
        for (auto&i:um) {
            int val = i.second; String str = i.first;
            if (cnt < val) {
                s = str;
                cnt = val;
            } else if (cnt == val) {
                //Store lexiographically smaller String
                if (String(str) < String(s))
                    s = str;
            }
        }

        //Create vector from String found above
        String s1;
        for (int i=0;i<s.size();++i) {
            if (s[i]=='$' || s[i]=='#') {
                out.push_back(s1);
                s1.clear();
                continue;
            }
            s1 += s[i];
        }
        out.push_back(s1);
        return out;        
    }
};
```
