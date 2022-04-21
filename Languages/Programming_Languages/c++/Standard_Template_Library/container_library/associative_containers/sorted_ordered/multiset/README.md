**multiset**
- Create/Store
  - [Desending](#c1)
  - [Ascending](#c2)


### Create
<a name=c1></a>
#### Desending
```cpp
#include<set>
int main(){
    multiset<int, greater<int>> ms;
    ms.insert(3);
    ms.insert(3);
    ms.insert(1);
    ms.insert(5);
    ms.insert(4);

    for (auto &i:ms)
        cout << i << " ";             //5 4 3 3 1
}
```
<a name=c2></a>
#### Ascending
```cpp
int main(){
    multiset<int> ms;
    ms.insert(3);
    ms.insert(3);
    ms.insert(1);
    ms.insert(5);
    ms.insert(4);

    for (auto &i:ms)
        cout << i << " ";           //1 3 3 4 5
}
```
