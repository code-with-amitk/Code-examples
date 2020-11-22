## Problem
- Implement compression using the counts of repeated characters. Assume string only contains Upper and lower case letters(a-z).
- Examples:
```c++
 aabcccccaaa --becomes--> a2b1c5a3
```

## Logic
- start from index=0
- Find index duplicates using
  - lower_bound(ForwardIterator first, ForwardIterator last, const T& val); //returns index of 1st occurence
  - upper_bound(ForwardIterator first, ForwardIterator last, const T& val); //returns index of last+1
  - calculate diff.
- Create output string character+count
```

## Complexity:
- O(mlogn)

## Code
```c++
#include<iostream>
#include<algorithm>
using namespace std;

void comp(string s){
        int size = s.size(), i=0,diff;
//        cout<<"size="<<size<<"\n";

        if(!size){
                cout<<"null string";
                return;
        }

        string::iterator low,up;
        string compressed;

        while(i<size){                                  //O(m). m is number of unique elements.
//                cout<<"element:"<<s[i]<<"\n";

                low = lower_bound(s.begin(),s.end(),s[i]);      //O(logn)
//                cout<<"low:"<<low-s.begin()<<"\n";

                up = upper_bound(s.begin(),s.end(),s[i]);       //O(logn)
//                cout<<"up:"<<up-s.begin()<<"\n";

                diff = up-low;

//                cout<<"diff:"<<diff<<"\n";
                compressed.shrink_to_fit();
                compressed = compressed+ char(s[i]);
                compressed = compressed + to_string(diff);

                i = up-s.begin();
        }

        if(compressed.size()<s.size())
                cout<<"\n"<<compressed<<"\n";
        else
                cout<<"\n"<<s;
}

int main(){
        string s = {'A','A','a','a','b','b','b','c','c','c','c','c'};   //A2a2c3c5
                  //0    1   2   3   4   5   6   7   8   9
//      string s = {};  
        comp(s);
}
/*
Output:
A2a2b3c5
*/
```
