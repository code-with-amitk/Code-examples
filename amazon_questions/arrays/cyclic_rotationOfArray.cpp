#include<iostream>
#include <algorithm>
#include<vector>

/*
An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

    A = [0, 0, 0]
    K = 1
the function should return [0, 0, 0]

Given

    A = [1, 2, 3, 4]
    K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
 */

/* Logic:
        1. If rotation_size(K) > size_of_array(N). Calculate actual_rotation(K) = rotation_size(K) % size_of_array(N)
        2. Use vector's rotate() function to place Kth element from last at start of vector.

Return: Rotated Array
*/
std::vector<int> solution(std::vector<int> &A, int K) {
        int Asize=0;
        if(!A.empty())
                Asize = (int)A.size();
        else
                return A;
        if(K == Asize){
                std::cout<<"No rotation required\n";
        }else{
                K = K % Asize;
                int tmp;
                if(K>1){
                        tmp=Asize-K;
                        std::cout<<"tmp="<<tmp<<"\n";

                }else
                        tmp=K;
                std::cout<<"Rotations needed: "<<K<<" vector size:"<<Asize<<std::endl;
                std::rotate(A.begin(),A.begin()+tmp,A.end());
        }
        return A;
}

int main(){
    std::vector<int> vect;

//    vect = {3,8,9,7,6};  std::vector<int> t = solution(vect, 3);
//    vect = {0};    std::vector<int> t = solution(vect, 3);
//    vect = {2,3,4,5,6,7,1};    std::vector<int> t = solution(vect, 3);
//      vect = {5, -1000}; std::vector<int> t = solution(vect, 3);
//      vect={}; std::vector<int> t = solution(vect, 3);
        vect={6,0,0,-2,10,-4,4,11,12,13,14,15,16,17,18}; std::vector<int> t = solution(vect, 10);
        for (auto &it: vect)    std::cout<<" "<<it;
//    solution(vect, 5);
}
