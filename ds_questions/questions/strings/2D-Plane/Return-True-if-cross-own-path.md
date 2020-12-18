### [Path Crossing lc](https://leetcode.com/problems/path-crossing/)
- string represents 1 movement in North,East,West,South directions. Retrun "true" if you crossed your own path else false
- Example
```c
      N
    W   E
      S

  input = "NES"         //From (0,0). Move 1 unit North, 1 unit east, 1 1 unit south.
  Output: false 
```

### Logic

### Code
```c++
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
