/*
What is Binary heap? Balanced complete Binary tree. Duplicates are allowed in heap. 
Min-Heap? Root is always smallest. Condition: parent =< child

How Heap is stored?
- Heap is stored using arrays. This provides advantage that space complexity is low since pointer is not stored as in trees.

Question Build a Max-Heap from array {17, 15, 8, 9, 10, 13, 6, 4, 5, 3, 1}
Answer 
               1
              /   \
            3      6
           /  \   /  \
          4   10  13  8
         / \  / \
        9  5 15 17
        
Basic Logic to Build Min-Heap:
a. Create Binary tree using level-order-traversal from Array
b. Perform heapify operation on all non-leaf nodes starting from 1st non-leaf node to top of tree in reverse order.
        heapify operation: Compare node,it's left & right child. Swap and place smallest element at top.
-> Code logic is given below.

Example:        
Array = {17, 15, 8, 9, 10, 13, 6, 4, 5, 3, 1}
          0   1  2  3   4   5  6  7  8  9  10

Step-1: Create Complete Binary Tree from Array using level-order/bfs method.
        For any node a[i], leftChild = a[2*i + 1], rightChild = a[2*i + 2]
        Example: i=3 a[i]=9  leftChild=a[2*3+1]=4. rightChild=arr[8]=5
                
                 17
              /     \
           15        8
         /    \     /  \
        9     10   13   6
       / \    / \
      4   5  3   1
      
Step-2: Calculate all non-leaf nodes, on which heapify operation need to be performed!
        Total nodes size=11, Non-leaf-nodes = sizeOfArray/2 - 1 = 11/2 - 1 = 4
        We will heapify from last non-leaf node to 1st in reverse order.
        Last non-leaf node, arr[4]=10.
        Nodes to heapify=[1, 3, 5, 4, 6] in reverse order.
        
Step-3: (Heapify 10) Swap 10 and 1. Compare 10,3,1. Place smallest element at top
                 17
              /     \
           15        8
         /    \     /  \
        9      1   13   6
       / \    / \
      4   5  3   10
Step-4: (Heapify 9) Swap 4 and 9.
                 17
              /     \
           15        8
         /    \     /  \
        4      1   13   6
       / \    / \
      9   5  3   10
Step-5: (Heapify 8) Swap 8 and 6.
                 17
              /     \
           15        6
         /    \     /  \
        9      1   13   8
       / \    / \
      4   5  3   10
Step-6: (Heapify 15) First Swap 15 and 1, again swap 3 and 15.
                 17
              /     \
            1        8
         /    \     /  \
        9      3   13   6
       / \    / \
      4   5  15   10
Step-7: (Heapify 17) First Swap 1 and 17, again swap 3 and 17, finally swap 17 and 15.
                 1
              /     \
            3        8
         /    \     /  \
        9      15   13   6
       / \    / \
      4   5  17   10


************Code Logic*************
1. Calculate number of nodes to be heapified.   size/2 - 1

2. Inplace heapify the array
  2a. In place array Heapify every node seperately.
        for(i=size/2-1; i>=0; i--)
                heapifyANode(a,size,indexOfNodeToHeapify);  //So, we call heapify function for every node seperately
                
  2b. How heapifyANode(a,size,indexOfNodeToHeapify) works?
    - if(leftChildIndex < sizeOfArray && a[leftChildIndex] < a[parentIndex])
        Just note that parent will be swapped with left
        IndexOfParent = IndexOfLeft
      
    - if(rightChildIndex < sizeOfArray && a[rightChildIndex] < a[parentIndex])
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

        if((leftChildIdx < size) && (a[parentIdx] > a[leftChildIdx]))
        {
                parentIdx = leftChildIdx;                       //a
        }
        if((rightChildIdx < size) && (a[parentIdx] > a[rightChildIdx]))
        {
                parentIdx = rightChildIdx;                      //b
        }

        if (parentIdx != i) {           //This means any of above two(a or b) holds true. otherwise parentIdx was i
                swap(a[i], a[parentIdx]);

                /*Now parent is either left or right child
                 * We will check new parent is not greater than either of its children
                 *
                 * Terminating condition for this recursion:
                 * - (leftChildIdx > size)              //means no left child
                 * - (rightChildIdx > size)             //means no right child
                 * - a[parentIdx] < a[rightChildIdx]    //means parent is smaller no swap
                 * - a[parentIdx] < a[leftChildIdx]     //means parent is smaller no swap
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

NODE *createMinHeapTree(int a[], int i, int size)
{
        NODE *ptr;

        if(i<size)
                ptr = newNode(a[i]);

        if(2*i+1 < size)
                ptr->left = createMinHeapTree (a,2*i+1,size);

        if(2*i+2 < size)
                ptr->right = createMinHeapTree (a,2*i+2,size);

        return ptr;
}

int main(){
        int a[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
        NODE *ptr;

        int noofelements = sizeof(a) / sizeof(a[0]);        //11

        heapifyArrayInPlace(a, noofelements);

        cout<<"Array is heapified in place\n";
        printInPlaceHeapifiedArray(a, noofelements);

        ptr = createMinHeapTree(a,0,noofelements);
        cout<<"Created Min Heap tree from heapified array\n";

}

/*
# g++ minHeap.cpp
# ./a.out 
Array is heapified in place
1 3 6 4 10 13 8 9 5 15 17 
Created Min Heap tree from heapified array
*/
