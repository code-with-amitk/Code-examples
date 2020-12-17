## Problem
- Find Max product of 3 elements.
A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).
```c
  ar = {-3,1,2,-2,5,6}

contains the following example triplets:
index
(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60    //Answer
```

## Code
```c
#include <iostream>
#include <algorithm>
#include <vector>

int solution(std::vector<int> &A){
        std::sort (A.begin(), A.end());
        std::sort (A.begin(), A.end());
        int tmp=0, max=0;
        unsigned int s = A.size() -2;

        for(unsigned int i=0; i<s; i++){
                tmp = A[i]*A[i+1]*A[i+2];

                if(tmp > max)
                        max = tmp;
        }
        return max;
}

int main(){
    std::vector<int> vect;
    vect.push_back(-3);
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(-2);
    vect.push_back(5);
    vect.push_back(6);
        std::cout<<solution(vect);
}
```
