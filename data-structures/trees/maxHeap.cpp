/*
What is Binary heap? Balanced complete Binary tree. Duplicates are allowed in heap. 
Max-Heap?
Root is always greatest. Condition: parent >= child    //This condition is for all nodes except Root-node.

How Heap is stored?
- Heap is stored using arrays. This provides advantage that space complexity is low since pointer is not stored as in trees.

Question Build a Max-Heap from array {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
Answer 
               17
              /   \
            15     13
           /  \   /  \
          9    6  5  10
         / \  / \
        4  8 15 1 


Basic Logic to Build Max-Heap:
a. Create Binary tree using level-order-traversal from Array
b. Perform heapify operation on all non-leaf nodes starting from 1st non-leaf node to top of tree in reverse order.
        heapify operation: Compare node,it's left & right child. Swap and place largest element at top.
-> Code logic is given below.

Example:        
Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
         0  1  2  3  4  5   6   7  8  9   10

Step-1: Create Complete Binary Tree from Array using level-order/bfs method.
        For any node a[i], leftChild = a[2*i + 1], rightChild = a[2*i + 2]
        Example: i=3 a[i]=4  leftChild=a[2*3+1]=9. rightChild=arr[8]=8
                
                 1
              /     \
            3         5
         /    \     /  \
        4      6   13  10
       / \    / \
      9   8  15 17

Step-2: Calculate all non-leaf nodes, on which heapify operation need to be performed!
        Total nodes size=11, Non-leaf-nodes = sizeOfArray/2 - 1 = 11/2 - 1 = 4
        We will heapify from last non-leaf node to 1st in reverse order.
        Last non-leaf node, arr[4]=6.
        Nodes to heapify=[1, 3, 5, 4, 6] in reverse order.

Step-3: (Heapify 6) Swap 6 and 17. Compare 17,15,6. Place largest element at top
                 1
              /     \
            3         5
         /    \      /  \
        4      17   13  10
       / \    /  \
      9   8  15   6

Step-4: (Heapify 4) Swap 4 and 9.
                 1
              /     \
            3         5
         /    \      /  \
        9      17   13  10
       / \    /  \
      4   8  15   6

Step-5: (Heapify 5) Swap 13 and 5.
                 1
              /     \
            3         13
         /    \      /  \
        9      17   5   10
       / \    /  \
      4   8  15   6

Step-6: (Heapify 3) First Swap 3 and 17, again swap 3 and 15.
                 1
              /     \
            17         13
          /    \      /  \
         9      15   5   10
        / \    /  \
       4   8  3   6      

Step-7: (Heapify 1) First Swap 1 and 17, again swap 1 and 15, finally swap 1 and 6.
                 17
              /      \
            15         13
          /    \      /  \
         9      6    5   10
        / \    /  \
       4   8  3    1


************Code Logic*************
1. Calculate number of nodes to be heapified.   size/2 - 1

2. Inplace heapify the array
  2a. In place array Heapify every node seperately.
        for(i=size/2-1; i>=0; i--)
                heapifyANode(a,size,indexOfNodeToHeapify);  //So, we call heapify function for every node seperately

  2b. How heapifyANode(a,size,indexOfNodeToHeapify) works?
    - if(leftChildIndex < sizeOfArray && a[leftChildIndex] > a[parentIndex])
        Just note that parent will be swapped with left
        IndexOfParent = IndexOfLeft
      
    - if(rightChildIndex < sizeOfArray && a[rightChildIndex] > a[parentIndex])
        IndexOfParent = IndexOfRight
  
      if(IndexOfParent != indexOfNodeToHeapify) //This means we need a swap & check that all nodes below it are heapified
        swap(a[indexOfNodeToHeapify], a[IndexOfParent])
        heapifyANode(a,size,IndexOfParent);   <<<<<<<<<<<<<<<<

====Now array is inplace heapified but yet Tree is not created====

3. Create Tree level order by traversing the array
      


***********************************
TIME COMPLEXITY:
Heapify a single node takes O(Log N) time complexity where N is the total number of Nodes. 
Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).
*/
#include<iostream>
using namespace std;

typedef struct node
{
        int val;
        struct node *left, *right;
}NODE;

void printInPlaceHeapifiedArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapifyANode(int a[], int size, int i){            //This function heapifies every node seperately

        int parentIdx = i;
        int leftChildIdx = 2*i+1;
        int rightChildIdx = 2*i+2;

        if((leftChildIdx < size) && (a[parentIdx] < a[leftChildIdx]))
        {
                parentIdx = leftChildIdx;                       //a
        }
        if((rightChildIdx < size) && (a[parentIdx] < a[rightChildIdx]))
        {
                parentIdx = rightChildIdx;                      //b
        }

        if (parentIdx != i) {           //This means any of above two(a or b) holds true. otherwise parentIdx was i
                swap(a[i], a[parentIdx]);

                /*Now parent is either left or right child
                 * We will check new parent is not less than either of its children
                 *
                 * Terminating condition for this recursion:
                 * - (leftChildIdx > size)              //means no left child
                 * - (rightChildIdx > size)             //means no right child
                 * - a[parentIdx] > a[rightChildIdx]    //means parent is bigger no swap
                 * - a[parentIdx] > a[leftChildIdx]     //means parent is bigger no swap
                 */
                heapifyANode(a, size, parentIdx);
    }
}


void heapifyArrayInPlace(int a[], int size){

    int startIndex = (size / 2) - 1;         //(11/2)-1 = 4. 1st node to heapify

    for (int i = startIndex; i >= 0; i--) {  //Perform heapify operation from 1st nonleaf to root node, in reverse order
        heapifyANode(a, size, i);               //heapify arr[4], arr[3], arr[2], arr[1] and arr[0]
    }
}

NODE *newNode(int i)
{
        NODE *ptr = new NODE();
        ptr->val = i;
        ptr->left = ptr->right = NULL;
        return ptr;
}

NODE *createMaxHeapTree(int a[], int i, int size)
{
        NODE *ptr;

        if(i<size)
                ptr = newNode(a[i]);

        if(2*i+1 < size)
                ptr->left = createMaxHeapTree (a,2*i+1,size);

        if(2*i+2 < size)
                ptr->right = createMaxHeapTree (a,2*i+2,size);

        return ptr;
}

int main(){
        int a[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
        NODE *ptr;

        int noofelements = sizeof(a) / sizeof(a[0]);        //11

        heapifyArrayInPlace(a, noofelements);

        cout<<"Array is heapified in place\n";
        printInPlaceHeapifiedArray(a, noofelements);

        ptr = createMaxHeapTree(a,0,noofelements);
        cout<<"Created Max Heap tree from heapified array\n";

}

/*
# g++ maxHeap.cpp
# # ./a.out 
Array is heapified in place
17 15 13 9 6 5 10 4 8 3 1 
Created Max Heap tree from heapified array
*/
