[Problem](https://leetcode.com/problems/path-crossing/)

### Task
  - Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively.
  - You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
  - Return True if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return False otherwise
  
```
class Solution {
public:
    bool isPathCrossing(string p) {
      set<pair<int,int>> s;

      int size = p.size(), x=0, y=0;

      s.insert(make_pair(0,0));

      for(auto i:p){
        if(i == 'N')
          y++;
        if(i == 'E')
          x++;
        if(i == 'S')
          y--;
        if(i == 'W')
          x--;


        if(s.find({x,y}) != s.end()){ //entry found
          return true;
        }else{
          s.insert(make_pair(x,y));
        }
      }
      return false;        
    }
};

int main(){
  Solution s;
  string s1 = "NES";
  cout<<s.isPathCrossing(s1);
}
```
