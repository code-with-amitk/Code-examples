**Number of Steps to Reduce a Number in Binary Representation to One**
- [Approach-1, Convert to decimal](#a1)
- [Approach-2, Comprehend string as binary only](#a2)
  - [Logic](#l)
  - [Code](#c)
  - [Complexity](#co)

### [Number of Steps to Reduce a Number in Binary Representation to One](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one)
- Number "s" is given in binary representation. Return the number of steps to reduce it to 1 under the following rules:
 - If the current number is even, you have to divide it by 2.
 - If the current number is odd, you have to add 1 to it.
- Example
```c++
Input: s = "1101"
Output: 6
Goal: make the string s=="1".
```


<a name=a1></a>
### Approach-1, Convert to decimal
#### Logic
- Convert String "1101" to decimal.
- Then perform operations and count steps.
```c
 1101 => 13
 
 Operation  
 13+1 = 14
 14/2 = 7
 7+1  = 8
 8/2  = 4
 4/2  = 2
 2/2  = 1    //Steps=6
```
#### Problem with above approach
In case of very big number 500 bits, 2<sup>500</sup> we cannot store it in unsigned long long = 16 bytes = 128 bit

<a name=a2></a>
### Approach-2, Comprehend string as binary only
<a name=l></a>
#### Logic
- _1._ Check last bit of number. Perform operation on last bit.
```c
 last-bit      Operation
  1 (odd no)   Add 1
               {1+1 = 0(at position),1(carry)}. Assign 0 to last bit and search for 0 before last bit.
               If 0 is found, change that to 1 and all the characters after that change to 0.
               If 0 is not found, insert 1 at beginning of the string and make all other bits as 0.
               
  0 (even no)  remove last bit

Example: number=1110
Step   Last-bit    resulting-no
 1       0 (even)     111
 2       1 (odd)      1000
 3       0 (even)     100
 4       0 (even)     10
 5       0 (even)     1
```

<a name=c></a>
### Code
```c++
#include<iostream>
#include<string>
#include<cmath>
#include<chrono>
using namespace std::chrono;
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0, i;

        while (s != "1"){

            if(s == "0")
                return ++steps;

            //Last Bit=0, Even Number. 1110
            if(s[s.size() - 1] == '0') {
                s.erase(s.size() - 1, 1);
                steps++;
            }else{

                //Last Bit=1. Odd Number. 111
                //Step-1: Place 0 at last. 110
                s[s.size() - 1] = '0';

                //Step-2: Traverse from last-1 to 1st bit
                //Find place of 1st 0 in number
                for(i = s.size() - 2; i >= 0; i--)
                    if(s[i] == '0')
                        break;

                //On 1st 0, place 1
                if(i > 0){
                    s[i] = '1';
                    //Make all zeros after this 1
                    for(i = i+1;i < s.size(); i++){
                        s[i] = '0';
                    }
                    steps++;
                }else{
                    //if no 0 is found inbetween
                    //Insert 1 at start ie index=0 and make all others=0
                    s.insert(0, "1");
                    for(int i = 1; i < s.size(); i++){
                        s[i] = '0';
                    }
                    steps++;
                }
            }
        }
        return steps;
    }
};
int main(){
  Solution obj;
//  string str = "1101";
//  string str = "10";
  string str = "1";
  auto startTime = high_resolution_clock::now();
  cout<<obj.numSteps(str)<<endl;
  auto stopTime = high_resolution_clock::now();
  auto diff = duration_cast<microseconds>(stopTime - startTime);
  cout<<"Time taken = "<<diff.count()<<" millisec"<<endl;         
  }
  ```
