/*
A non-empty array A consisting of N integers is given. 
The array contains an odd number of elements, and each element of the array can be paired with another 
element that has the same value, except for one element that is left unpaired.

For example, in array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the elements at indexes 0 and 2 have value 9,
the elements at indexes 1 and 3 have value 3,
the elements at indexes 4 and 6 have value 9,
the element at index 5 has value 7 and is unpaired.
Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

For example, given array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

N is an odd integer within the range [1..1,000,000];
each element of array A is an integer within the range [1..1,000,000,000];
all but one of the values in A occur an even number of times.
 */

/* Logic:
  - Sort the vector.
  - compare 2 adjacent elements, if both are not same, return 1st element.
 */
#include<iostream>
#include <algorithm>
#include<vector>

int solution(std::vector <int> &A){
        std::sort(A.begin(), A.end());
        int tmp=0, tmp1=0, ret=0;
        for (std::vector<int>::iterator it=A.begin(); it!=A.end(); ++it){
                tmp = *it;
                tmp1 = *(++it);

                if(tmp != tmp1){
//                      std::cout<<"tmp: "<<tmp<<"\t"<<"tmp1: "<<tmp1<<"\n";
                        ret = tmp;
                        break;
                }
        }
        return tmp;
}

int main(){
    std::vector<int> vect;
    vect.push_back(9);
    vect.push_back(3);
    vect.push_back(9);
    vect.push_back(3);
    vect.push_back(9);
    vect.push_back(7);
    vect.push_back(9);
        std::cout<<solution(vect);
}
