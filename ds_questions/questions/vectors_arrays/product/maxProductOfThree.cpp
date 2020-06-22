/*
A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A, returns the value of the maximal product of any triplet.

For example, given array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].
 */
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
