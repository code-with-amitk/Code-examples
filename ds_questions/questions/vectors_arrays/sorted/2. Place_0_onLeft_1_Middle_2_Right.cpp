## Problem= sort_an_array_0_1_2
- Sort the array containing 0,1,2. All 0s on left, 1s in middle, 2s right
- Example
```c
 input = 0 2 1 2 0
 output = 0 0 1 2 2       //After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
```

### Code
```c
#include<iostream>
#include<vector>
using namespace std;

int main(){
        int num_of_test_cases, elements_in_array, zeros=0, ones=0, twos=0, array_element;
        int i,j,k,l, temp=0;

        cin>>num_of_test_cases;
        for(i=0;i<num_of_test_cases;i++){
                cin>>elements_in_array;
                for(j=0;j<elements_in_array;j++){
                        cin>>array_element;
                        if(array_element == 0)
                                zeros++;
                        if(array_element == 1)
                                ones++;
                        if(array_element == 2)
                                twos++;
                }
//              cout<<"\n";
//              cout<<"0 = "<<zeros<<" 1="<<ones<<" 2="<<twos<<"\n";
                while(temp<zeros){
                        cout<<"0 ";
                        temp++;
                }
                temp=0;
                while(temp<ones){
                        cout<<"1 ";
                        temp++;
                }
                temp=0;
                while(temp<twos){
                        cout<<"2 ";
                        temp++;
                }
                zeros = ones = twos = temp = 0;
                cout<<"\n";
        }
        return 0;
}
```
