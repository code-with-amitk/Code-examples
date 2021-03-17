## [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- Given a collection of intervals, merge all overlapping intervals.
- Examples
```c
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]		//Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]		//Intervals [1,4] and [4,5] are considered overlapping.
```

### Logic
- *1.* Take a second vector(b) which will be created from a.
- *2.* Start from 2 starting nodes
```c
	node0. a1 = node0[0], b1 = node0[1]
	node1. a2 = node1[0], b2 = node1[1]
```  
- *3.* if(a2(2) <= b1(10))				{1,10}{2,3}	//These will be merged
```c
	- Nodes will be merged.
	b1 = 10
```  
- *4.* Move to next node. node2. a2 = 18, b2 = 19
```c
	a2(18) !<= b1(10)
	b = {a1(1), b1(10)}
	a1 = 18
	b1 = 19
```
  
### Code
```c++
//{2,3},{4,5},{6,7},{8,9},{1,10}
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& a) {
    if(a.size()<2)
      return a;

    vector<vector<int>> b;
    vector<int> node0, nextNode;

    sort(a.begin(), a.end(),
         [](const vector<int> &x,const vector<int> &y){ //Donot compare all elements just 1st
            return x[0]<y[0];
          }
      );
    //{1,10},{2,3},{4,5},{6,7},{8,9}

     node0 = a[0];        //{1,10}
     int index = 1;
     int a1 = node0[0];   //1
     int b1 = node0[1];   //10
     int a2, b2;

    while(index < a.size()) {
//      nextNode = a[index++];    //{2,3}
      nextNode = a[index];    //{2,3}
      a2 = nextNode[0];         //2
      b2 = nextNode[1];         //3
      if(a2 <= b1)
        b1 = max(b1,b2);
      else{
        b.push_back({a1,b1});
        a1 = a2;
        b1 = b2;
      }
      index++;
    }
    b.push_back({a1,b1});
    return b;
  }
};   
int main(){
  vector<vector<int>> a = {{2,3},{4,5},{6,7},{8,9},{1,10}};
  Solution s;
  vector<vector<int>> b;
  b = s.merge(a);
  for(int i=0;i<b.size();i++)
    for(int j=0;j<2;j++)
    cout<<a[i][j]<<" ";
}
```
