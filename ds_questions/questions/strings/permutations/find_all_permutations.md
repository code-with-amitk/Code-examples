## Question
- Find all permutations of given string. 
  
### Example
- Input = abc  
```
Output:
a b c
a c b
b a c
b c a
c a b
c b a
```  

### Logic
- [youtube](https://www.youtube.com/watch?v=GuTPwotSdYw)
```
A B C
0 1 2
                       ABC
         ------------------------------
         |              |             |
         |A-A           |A-B          |A-C
         |              |             |
        ABC            BAC           CBA                //Swap all indexes with index=0. (index0 swapped-with index1) & (index0 swapped-with index2)
         |              |             |
       ------       --------      ---------
       |    |       |      |      |       |
    B-B| B-C|    A-A|   C-A|   B-B|    B-A|     
      ABC  ACB     BAC    BCA    CBA     CAB            //Keeping index=0 fixed, Swap index=1 with rest of indexes in array

Time Complexity: O(n*n!), where n is number of elements in string     
```

### Method-1 next_permutation()
```
#include<algorithm>

vector<vector<char>> f(vector<char> s){
  vector<vector<char>> v;
  do{
    v.push_back(s);
  }while(next_permutation(s.begin(), s.end()));
  return v;
}

int main(){
  vector<char> a = {'a','b','c'};
  vector<vector<char>> s = f(a);
}
```

### Method-2
```
//This function works on above logic, But unfortunately its complex to understand And better to cram.
void perm(string a, int l, int r){
    if (l == r)
        cout<<a<<endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            perm(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}

int main(){
        string t = "abc";
        perm(t, 0, t.size()-1);
}
```
