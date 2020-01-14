/*
What is Binary heap? Balanced complete Binary tree. Duplicates are allowed in heap. 
Max-Heap?
Root is always greatest. Condition: parent >= child    //This condition is for all nodes except Root-node.

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

2. Heapify every node seperately.
        for(i=size/2-1; i>=0; i--)
                heapifyANode(a[i]);          //So, we call heapify function for every node seperately

3. How heapifyANode() works?


4. Traverse from index 4 to 0 in reverse order, heapify each element. 
        (heapify means: Compare node,it's left & right child. Swap and place largest element at top.)

***********************************
TIME COMPLEXITY:
Heapify a single node takes O(Log N) time complexity where N is the total number of Nodes. 
Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).
*/
#include<iostream>
using namespace std;

void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

//This function heapifies every node seperately
void heapifyANode(int a[], int size, int i){

    int parentIndex = i;
    int leftChildIndex = 2*i + 1;             //left-child = 2*i + 1
    int rightChildIndex = 2*i + 2;            //right-child = 2*i + 2

    // If left child is larger than root
    if (leftChildIndex < size && arr[leftChildIndex] > arr[parentIndex])
        parentIndex = leftChildIndex;

    // If right child is larger than largest so far
    if (rightChildIndex < size && arr[rightChildIndex] > arr[parentIndex])
        parentIndex = rightChildIndex;

    // If largest is not root
    if (parentIndex != i) {             //We found parent is smaller than either left or right node
        swap(arr[i], arr[parentIndex]); //Swap largest element and parentIndex

        // Recursively heapify the affected sub-tree
        heapifyANode(arr, size, parentIndex);
    }
}

void buildHeap(int a[], int size){

    int startIndex = (size / 2) - 1;         //(11/2)-1 = 4. 1st node to heapify

    for (int i = startIndex; i >= 0; i--) {  //Perform heapify operation from 1st nonleaf to root node, in reverse order
        heapify(a, size, i);               //heapify arr[4], arr[3], arr[2], arr[1] and arr[0]
    }
}

int main(){
        int a[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

        int noofelements = sizeof(a) / sizeof(a[0]);        //11

        buildHeap(a, noofelements);
        printHeap(a, noofelements);

        return 0;
}

# g++ maxHeap.cpp
# ./a.out 
Array representation of Heap is:
17 15 13 9 6 5 10 4 8 3 1 
