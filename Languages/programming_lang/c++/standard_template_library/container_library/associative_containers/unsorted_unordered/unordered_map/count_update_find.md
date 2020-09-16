## A. Count
### A1. No of occurences from Arrays
  - Create <key=value, value=count> from array. Where key=element_in_array, value=no_of_times_element_repeated_in_array
  - Array {4,3,1,1,3,3,2}
  
<key,value>
| 4,1 | 3,3 | 1,2 | 2,1 |

```c++
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

## B. Find
- **1. Key in unordered map<key,value>**
```c++
class Command{ ... };
class Command1 : public Command { ... };
class Command2 : public Command { ... };

unordered_map<string, Command *> um;

um["command1"] = new Command1();
um["command2"] = new Command2();

auto it = um.find ("Command1");

if (it != um.end()) {               //Found Key
  cout << it->second->fun();        //Call method of class
}
```

-  **2. Pair having smallest `key`**
  - Considering map in bullet-1, smallest key=1 and pair=<1,2>
```c++
  unordered_map<int,int>::iterator it;
  it = min_element(um.begin(), um.end());
  cout<<it->first<<" " <<it->second;          //1 2
```

- **3. Pair having smallest `value`**
  - Considering map in bullet-1, smallest value pair = `<4,1>`
```c++
  static bool comp(pair<int,int> i, pair<int, int> j)
    return i.second < j.second;

  unordered_map<int,int>::iterator it;
  it = min_element(um.begin(), um.end(),compare_func);
  cout<<it->first<<" " <<it->second;          //4 1
```
