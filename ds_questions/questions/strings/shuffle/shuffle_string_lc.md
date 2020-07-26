## [Problem](https://leetcode.com/contest/weekly-contest-199/problems/shuffle-string/)

### Example
```
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
```
### Code
```
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string restoreString(string s, vector<int>& v) {
      int size = v.size();

      if(!size)
        return {};

      char ret[size+1];

      for(auto i:v){
        ret[v[i]] = s[i];
      }
      ret[size]='\0';

      for(auto i:v){
        cout<<ret[i]<<" ";
      }

      return ret;
    }
};

int main(){
  string s = "codeleet";
  vector<int> v = {4,5,6,7,0,2,1,3};
  Solution o;
  string t = o.restoreString(s, v);
  cout<<t;
}
```
