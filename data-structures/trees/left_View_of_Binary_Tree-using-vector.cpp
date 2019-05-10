#include<iostream>
#include<vector>
/*
Problem: 
 - Given a Binary Tree, print Left view of it.
 - Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
 - The task is to complete the function leftView(), which accepts root of the tree as argument.
 - Left view of following tree is 1 2 4 8

          1
       /     \
     2        3
   /   \    /    \
  4     5   6    7
   \
     8

Input:
2               <<Number of test cases
2               <<Number of edges in binary tree
1 2 R 1 3 L     <<Number of edges+1 number of nodes data        1 2 R,   1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R         =Interpret as=>  10 20 L,  10 30 R,   20 40 L,  20 60 R
|- This creates tree as:
                10
              /    \
            20     30
           / \
          40 60

Output:         //Print nodes in left view of Binary Tree
1 3
10 20 40
*/
typedef struct node{
        int val;
        int leftIdx;
        int rightIdx;
}NODE;

int main(){
        std::vector<NODE> vec;
        NODE temp;
        std::vector<NODE>::iterator it;

        int num_of_test_cases, i, j, num_of_edges;
        int ele1, ele2;
        std::string left_or_right;

        std::cin>>num_of_test_cases;
        //std::cout<<"num_of_test_cases="<<num_of_test_cases<<std::endl;
        for(i=0;i<num_of_test_cases;i++){
                std::cin>>num_of_edges;
                //std::cout<<"num_of_edges="<<num_of_edges<<std::endl;

                for(j=0;j<num_of_edges;j++){
                        std::cin>>ele1;
                        //std::cout<<"ele1="<<ele1<<std::endl;

                        if(j==0){
                                temp = {ele1, -1, -1};
                                vec.push_back(temp);
                        }
                        std::cin>>ele2;
                        //std::cout<<"ele2="<<ele2<<std::endl;
                        std::cin>>left_or_right;
                        //std::cout<<"left_or_right="<<left_or_right<<std::endl;

                        //found = find(root, ele1);
                        //std::cout<<"vec.size()="<<vec.size()<<std::endl;
                        for(int k=0;k<vec.size();k++){
                                if(vec[k].val == ele1){
                                        if(left_or_right == "L"){
                                                //std::cout<<"Inside L"<<std::endl;
                                                vec[k].leftIdx = vec.size();
                                                temp = {ele2, -1, -1};
                                                vec.push_back(temp);
                                        }else{
                                                //std::cout<<"Inside R"<<std::endl;
                                                vec[k].rightIdx = vec.size();
                                                temp = {ele2, -1, -1};
                                                vec.push_back(temp);
                                        }
                                }
                        }
                }
                //std::cout<<"Created tree"<<std::endl;

                //std::cout<<"Finding left view"<<std::endl;
                int l=0;
                std::cout<<std::endl<<vec[l].val<<" ";
                while(vec[l].leftIdx != -1){
                        l = vec[l].leftIdx;
                        std::cout<<vec[l].val<<" ";
                }
                vec.clear();
        }
        return 0;
}

/*Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
*/

/*Ouput
1 3
10 20 40 
*/
