**Race Car**
- [Approach-1](#a1)

### [Race Car](https://leetcode.com/problems/race-car/)
- Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):
```c
Accelrate:
  position += speed
  speed *= 2
  
Reverse:
  if (speed>0)
    speed = -1 If your speed is positive then speed = -1
  else
    speed = 1
  position stays the same.
```
- Examples
```c
Example-1
Input: target = 3
Output: 2
Explanation: 
The shortest instruction sequence is "AA".
Your position goes from 0 --> 1 --> 3.

Example 2:
Input: target = 6
Output: 5
Explanation: 
The shortest instruction sequence is "AAARA".
Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.
```
- Given a target position target, return the length of the shortest sequence of instructions to get there.

<a name=a1></a>
### Approach-1, BFS
#### Logic
#### Code
```cpp
class Solution {
public:
  int racecar(int target) {
        
    queue<pair<int, int>> q;    //BFS
    q.push({0,1});
    unordered_set<string> visited;
	  visited.insert("0,1");

	  int level = 0;
        
    while (!q.empty()){
          int size=q.size();
          for (int i=0;i<size;i++){
              
               pair<int,int> top = q.front();   q.pop();
               long pos = top.first, vel = top.second, nextp, nextv;
			   
			        //base case
			        if (pos == target)
					      return level;
					
			        //Child A
			        nextp = pos+vel;	
			        nextv = vel*2;
              
             string str = to_string(nextp)+","+to_string(nextv);
              
		    	   if (!visited.count(str) && abs(target - nextp) < target) {
				    	visited.insert(str);
					    q.push({nextp, nextv});
				    }
              
			      //Child B
				    nextp = pos;
				    vel > 0?  nextv=-1 :  nextv=1;

            str = to_string(nextp)+","+to_string(nextv);
			      if (!visited.count(str) && abs(target - nextp) < target) {
    					visited.insert(str);
		    			q.push({nextp, nextv});
    				}
          }//for
		      level++;
       }
       return -1;
    }
};
```


