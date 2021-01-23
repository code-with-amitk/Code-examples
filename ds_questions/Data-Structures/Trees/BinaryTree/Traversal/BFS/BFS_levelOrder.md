## [Level Order](https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/)
- Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
- Output is returned in 2-D vector.
```c++
        12
       /  \
      10  30
     /    / \
   14   25   40
             /
            50
O/P ->  12 
        10 30 
        14 25 40 
        50
```
## Logic(Using QUEUES)
1. Take a queue
2. Push root, null in queue. NULL is pushed to track levels.
3. while(queue.size() > 1)
```
  pop top;
  if (top == null)
    push null.
    push 1D vector to 2D vector
  else
    push top in 1D
    if(node has left)
        push on queue
    if(node has right)
        push on queue        
```

## Complexity
- Time:
- Space:
 
## Code
```c++
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
#include<vector>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

struct node *newNode(int item){
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

std::vector<std::vector<int> > bf_traversal(Node* pRoot){
  std::vector<std::vector<int>> vecNodes;
  if (pRoot == NULL)
    return vecNodes;

  std::vector<int> vecLevel;
  std::queue<Node*> qTree;
  Node* pNode;

  qTree.push(pRoot);
  qTree.push(NULL);

  while (qTree.size() > 1){
    pNode = qTree.front();
    qTree.pop();

    if (not pNode) {
      qTree.push(NULL);
      std::cout << std::endl;
      vecNodes.push_back(vecLevel);
      vecLevel.clear();
    }else {

      std::cout << pNode->data << " ";
      vecLevel.push_back(pNode->data);

      if(pNode->left)
        qTree.push(pNode->left);
      if(pNode->right)
        qTree.push(pNode->right);
    }
  }//while
  
  if (vecLevel.size())
    vecNodes.push_back(vecLevel);
    
  return vecNodes;
}

int main(){
    struct node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

  std::vector<std::vector<int> > vecNodes = bf_traversal(root);
  
  for(int i=0;i<vecNodes.size();++i){
    for(int j=0;j<vecNodes[i].size();++j){
      std::cout<<vecNodes[i][j];
    }
    std::cout<<"\n";
  }
  return 0;
}     
```
