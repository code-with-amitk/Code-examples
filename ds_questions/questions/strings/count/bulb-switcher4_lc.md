## [On LeetCode](https://leetcode.com/problems/bulb-switcher-iv/)

- Read Question completely on Leet-code only.
## Logic
- Traverse string
- On 1st `1` encountered increment count by 1.
- Then On every change of bit ie, (0 to 1) or (1 to 0)
  - increment the counter
```
class Solution {
public:
    int minFlips(string s) {
      int count = 0, fOne=0;
      char curr = '0';

      for(int i=0;i<s.size();i++){

        if(s[i]=='1' && fOne == 0){   //1st 1
          count++;
          fOne++;
          curr = '1';
        }

        if(s[i] != curr){
          count++;
          curr = (curr == '1') ? '0' : '1';
        }

      }
      return count;        
    }
};
int main(){
  //string s = "101";   //3 ok
  //string s = "001011101"; //5 ok
  //string s = "000000000000";  //0 ok
  string s = "10111";
  Solution o;
  cout<<o.minFlips(s);
}
```
