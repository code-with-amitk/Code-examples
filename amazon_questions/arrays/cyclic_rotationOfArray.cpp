/*         cyclic_rotationOfArray.cpp

Rotation?
Means that each element is shifted right by one index, and the last element of the array is moved to the first place. 
For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7].

Task: Rotate array k times.
A = [3, 8, 9, 7, 6], K = 3
Answer: [9, 7, 6, 3, 8]

***************Logic:******************
a. If rotation_size(K) > size_of_array(N). Calculate actual_rotation(K) = rotation_size(K) % size_of_array(N)
b. Use vector's rotate() function to place Kth element from last at start of vector.
****************************************
*/

#include<iostream>
#include<algorithm>
#include<vector>

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
