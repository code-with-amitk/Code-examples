/*
Basic Logic to Build Max-Heap:
a. Create Binary tree using level-order-traversal from Array
b. Perform heapify operation on all non-leaf nodes starting from 1st non-leaf node to top of tree in reverse order.
        heapify operation: Compare node,it's left & right child. Swap and place largest element at top.
-> Code logic is given below.

Example:        
Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
         0  1  2  3  4  5   6   7  8  9   10

Step-1: Create Complete Binary Tree from Array using level-order/bfs method.
        left-child = 2*i + 1
        right-child = 2*i + 2
        For node 4, index=3.    left-child-index=2*3+1=7. left=child=arr[7]=9   right-child-index=2*3+2=8. right-child=arr[8]=8
                
                 1
              /     \
            3         5
         /    \     /  \
        4      6   13  10
       / \    / \
      9   8  15 17

Step-2: Total nodes = 11 = N
        Nodes to heapify = All non-leaf nodes = N/2 - 1 = 11/2 - 1 = 4
        We need to heapify from index(4) in reverse order.
        Last non-leaf node = arr[4] = 6
        To build the heap, heapify only the nodes:
        [1, 3, 5, 4, 6] in reverse order.

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


Code Logic:
1. We will rearrange elements within the array itself so that if tree is created using level-order-traversal. it comes out as maxHeap.
2. Take array having 11 elements. { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };.
        -> We know if we want to build level-order-traversed tree 
                left-child = 2*i + 1
                right-child = 2*i + 2
3. Find index of 1st non-leaf node.     (N/2)-1         (11/2)-1=4
4. Traverse from index 4 to 0 in reverse order, heapify each element. 
        (heapify means: Compare node,it's left & right child. Swap and place largest element at top.)
*/
#include<iostream>
using namespace std;

// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapify(int arr[], int noOfElements, int i){

    int parentIndex = i;
    int leftChildIndex = 2 * i + 1;             //left-child = 2*i + 1
    int rightChildIndex = 2 * i + 2;    //right-child = 2*i + 2

    // If left child is larger than root
    if (leftChildIndex < noOfElements && arr[leftChildIndex] > arr[parentIndex])
        parentIndex = leftChildIndex;

    // If right child is larger than largest so far
    if (rightChildIndex < noOfElements && arr[rightChildIndex] > arr[parentIndex])
        parentIndex = rightChildIndex;

    // If largest is not root
    if (parentIndex != i) {             //We found parent is smaller than either left or right node
        swap(arr[i], arr[parentIndex]); //Swap largest element and parentIndex

        // Recursively heapify the affected sub-tree
        heapify(arr, noOfElements, parentIndex);
    }
}

void buildHeap(int arr[], int noOfElements){

    int indexOf1stNonLeafNode = (noOfElements / 2) - 1;         //(11/2)-1 = 4. ie arr[4]=6

    for (int i = indexOf1stNonLeafNode; i >= 0; i--) {          //Perform heapify operation from 1st nonleaf to root node, in reverse order
        heapify(arr, noOfElements, i);                  //heapify arr[4], arr[3], arr[2], arr[1] and arr[0]
    }
}

int main(){
        int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

        int noofelements = sizeof(arr) / sizeof(arr[0]);        //11

        buildHeap(arr, noofelements);
        printHeap(arr, noofelements);

        return 0;
}

# g++ maxHeap.cpp
# ./a.out 
Array representation of Heap is:
17 15 13 9 6 5 10 4 8 3 1 
