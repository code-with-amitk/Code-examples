**Analyze User Website Visit Pattern**
- [Approach-1, HashMap, O(n<sup>3</sup>)](#a1)

### [Self Video](https://youtu.be/tO0GCoq2YqQ)

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
Note: Time stamps for 1 user cannot be always ascending, but output should be in ascending timestamps hence map<>
	joe		4	home
	joe		1	about
	joe		3	career
	Valid series: {about home career}
 
 user   map<timestamp,website>
|joe, <<1,home>, <2,about>, <3,carrer>> | james, <........> | mary, <........> |
```
- _2._ Create a string by combining 3 website names for 1 user. `unordered_map <3Websites, count>`
```cpp
Note: If 1 user visites more than once same 3 websites, only 1 should be taken in output. hence unordered_set<>
	joe		1	home
	joe		2	about
	joe		3	career
	joe		4	career
	
	visted website: {home about career}	//123 
					{home about career} //124.
	But we need to consider only once.	1
 
home$about$carrer  2  //joe, mary
home$cart#home     1  //james
home$cart#maps     1
home$maps#home     1
```
- _3._ Find max value from unordered_map in step2.
  - if 2 or more values are same find lexiographically smaller string
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
      //1. Create hashmap of websites visited by users
      // Note: timestamps are not always in ascending order for 1 user
      //  Hence we need to take map to keep timestamps in ascending order
      //  vector<timestamp, website> will not work
      std::unordered_map<String, std::map<int, String>> umUserWebsite;
      for (int i=0; i<username.size(); ++i) {
	       auto it = umUserWebsite.find(username[i]);
	       if (it == umUserWebsite.end()) {
            map<int, String> m;
            m[timestamp[i]] = website[i];
		          umUserWebsite[username[i]] = m;
        }
        else 
            it->second[timestamp[i]] = website[i];
      }

        std::unordered_map<String, int> um;

        //2. Create map of <key=website=home$about$career, value=count>
        /*  home$about#career

            | home$about#career, 2 | home$cart#maps, 1 | home$maps#cart,1 |
        */
       std::unordered_map <String, int> umWebsiteCount;
       std::map<String, int> mapWebsitesCount;
       for (auto&i : umUserWebsite) {
         auto username = i.first;
         map<int, String> mCountWebsite = i.second;
         std::unordered_set<String> ts;
         for (auto i=mCountWebsite.begin(); i!=mCountWebsite.end(); ++i) {    //1st iterator point to 1st entry
           for (auto j=next(i); j!=mCountWebsite.end(); ++j) {  //2nd iterator point to 2nd entry
    		       for (auto k=next(j); k!=mCountWebsite.end(); ++k) {  //3rd iterator point to 3rd entry
	                String var;
    	    		      var += i->second + "$";
                 var += j->second + "$";
                 var += k->second;
                    
                //3. Insert unique created String to set.
                //if user visits same pattern twice, we only need to take once
                //a$b$c(t=1), a$b$c(t=2)
                //Take only 1 a$b$c
                ts.insert(var);
	    	      }//for(i)
	         }//for(j)
	        }//for(k)
        
        //Insert created string
        for (auto&l:ts)
            mapWebsitesCount[l]++;
      }//for(auto&i : umUserWebsite)
        
    //4. Find Largest count or lexicographically smallest(in case of equal count)
    int count = INT_MIN;
    String strOutput;
    for (auto&i : mapWebsitesCount) {
	     String strWebsites = i.first;
	     int iCount = i.second;
	     if (iCount > count) {
    		  count = iCount;
	    	  strOutput = strWebsites;
	     } else if (count == iCount) {	
    		  // We found equal counted Website string
	    	  if (String(strOutput) > String(strWebsites)) 
		    	   strOutput = strWebsites;
      }
    }

      //5. Remove website separators that we inserted (ie $) and return output
      vecS vecOutput;
      String strFinal;
      for (char &i : strOutput) {
	        if (i != '$'){
            strFinal += i;
         } else {
    	      vecOutput.push_back(strFinal);
           strFinal.clear();
         }
      }
      vecOutput.push_back(strFinal);
      return vecOutput;       
    }
};
```
