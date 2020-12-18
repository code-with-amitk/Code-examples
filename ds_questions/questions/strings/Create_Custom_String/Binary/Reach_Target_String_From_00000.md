### [Bulb Switcher 4](https://leetcode.com/problems/bulb-switcher-iv/)
- There are n bulbs(initially all off ie 0000). You need to reach target pattern by following rules:
  - *1.* You can turn any bulb on, All bulbs after that will change their state. Those who are on(1) will get switched off(0) and viceversa.
- Example
```c
Input: target = "10111"
Output: 3
Explanation: Initial configuration "00000".
flip from the third bulb:  "00000" -> "00111"
flip from the first bulb:  "00111" -> "11000"
flip from the second bulb:  "11000" -> "10111"
We need at least 3 flip operations to form target.
```

### Logic
- Traverse string
- On 1st `1` encountered increment count by 1.
- Then On every change of bit ie, (0 to 1) or (1 to 0)
  - increment the counter
  
### Code  
```c++
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
