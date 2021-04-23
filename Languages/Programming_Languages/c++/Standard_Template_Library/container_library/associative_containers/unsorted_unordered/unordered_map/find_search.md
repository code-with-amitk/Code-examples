### 1. Find/Search
- **1. Key in unordered map<key,value>**
```c++
class Command{ ... };
class Command1 : public Command { ... };
class Command2 : public Command { ... };

unordered_map<string, Command *> um;

um["command1"] = new Command1();                  //Created unorderd_map
um["command2"] = new Command2();

auto it = um.find ("Command1");                   //Finding Key

if (it != um.end()) {                            //Found Key
  cout << it->second->fun();                     //Call method of class
}
```
-  **2. Pair having smallest `key`**
```c++
  unordered_map<int,int>::iterator it;
  it = min_element(um.begin(), um.end());
  cout<<it->first<<" " <<it->second;          //1 2
```

- **3. Pair having smallest `value`**
```c++
  static bool comp(pair<int,int> i, pair<int, int> j)
    return i.second < j.second;

  unordered_map<int,int>::iterator it;
  it = min_element(um.begin(), um.end(),compare_func);
  cout<<it->first<<" " <<it->second;          //4 1
```

### 2. Count Number of occurences from of value inside array
- Let's suppose an array `{4,3,1,1,3,3,2}` is present we need to create a map
```c++
key ->            4 3 1 2
NoOfOccurences -> 1 3 2 1

  vector<int>& arr = {4,3,1,1,3,3,2};
  unordered_map<int,int> um;           //<key=element, value=count>
  
Method-1:                     //USE THIS
  for(auto i:arr)
    um[i] = um[i] + 1;
  
Method-2:  
  unordered_map<int,int>::iterator it;
  for(auto i:arr){
    it = um.find(i);
    if(it != um.end())
      ++it->second;
    else
      um.insert(make_pair(i,1));
  }
```
