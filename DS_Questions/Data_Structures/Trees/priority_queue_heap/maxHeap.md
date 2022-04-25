**Max Heap**
- [Logic](#l)
- Code
  - [Method-1](#c1)
  - [Method-2](#c2)
- [Complexity](#co)

### Max Heap
- Binary heap? Balanced complete Binary tree. Duplicates are allowed in heap. 
- Max-Heap? Root is always greatest. parent >= child
- How Heap is stored? Heap is stored using arrays. This provides advantage that space complexity is low since pointer is not stored as in trees.
- Question Build a Max-Heap from unsorted array {1, 13, 5, 17, 4, 6, 3, 10, 15, 8, 9}.
```c
Answer:
               17
              /   \
            15     13
           /  \   /  \
          9    6  5  10
         / \  / \
        4  8 15 1 
```
#### Logic to Build Max-Heap
_a._ Create Binary tree using level-order-traversal from Array
```c
        {1, 13, 5, 17, 4, 6, 3, 10, 15, 8, 9}
         0   1  2   3  4  5  6   7  8   9  10
  
              1
           /     \
          13      5
         /  \    /  \
        17   4  6    3
       / \  /\
      10 15 8 9

For any node a[i], leftChild = a[2*i + 1], rightChild = a[2*i + 2]
Example: i=2 a[i]=5  leftChild=a[2*2+1]=6. rightChild=arr[6]=3   
  
Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
         0  1  2  3  4  5   6   7  8  9   10
```
- _b._ Perform heapify operation on all non-leaf nodes starting from 1st non-leaf node to top of tree in reverse order.
  - heapify operation: Compare node,it's left & right child. Swap and place largest element at top.
  - Calculate all non-leaf nodes, on which heapify operation need to be performed!
  - Total nodes size=11, Non-leaf-nodes = sizeOfArray/2 - 1 = 11/2 - 1 = 4
  - We will heapify from last non-leaf node to 1st in reverse order.
  - Last non-leaf node, `arr[4]=4`.
  - Nodes to heapify=`[1, 13, 5, 17, 4]` in reverse order.
```c
              1
           /     \
          13      5
         /  \    /  \
        17   4  6    3
       / \  /\
      10 15 8 9

(Heapify 4) Swap 4 and 9.
              1
           /     \
          13      5
         /  \    /  \
        17   9  6    3
       / \  /\
      10 15 8 4
                
No need to heapify 17
(Heapify 5) Swap 5 and 6.

              1
           /     \
          13      6
         /  \    /  \
        17   9  5    3
       / \  /\
      10 15 8 4

(Heapify 13) Swap 13 and 17.
              1
           /     \
          17      6
         /  \    /  \
        13   9  5    3
       / \  /\
      10 15 8 4

(Again Heapify 15). Swap 13,15
              1
           /     \
          17      6
         /  \    /  \
        15   9  5    3
       / \  /\
      10 13 8 4
                
(Heapify 1) First Swap 1 and 17, Again swap 1,15. Again swap 13,1
              17
           /     \
          1      6
         /  \    /  \
        15   9  5    3
       / \  /\
      10 13 8 4
               
              17
           /     \
          15      6
         /  \    /  \
        1    9  5    3
       / \  /\
      10 13 8 4
               
              17
           /     \
          15      6
         /  \    /  \
        13   9  5    3
       / \   /\
      10  1  8 4

```
#### Code
<a name=c1></a>
**Method-1(Same as logic above)**
```c
a. Calculate number of nodes to be heapified.   size/2 - 1

b. Inplace heapify the array
  b1. In place array Heapify every node seperately.
        for(i=size/2-1; i>=0; i--)
                heapifyANode(a,size,indexOfNodeToHeapify);  //So, we call heapify function for every node seperately

  b2. How heapifyANode(a,size,indexOfNodeToHeapify) works?
    - if(leftChildIndex < sizeOfArray && a[leftChildIndex] > a[parentIndex])
        Just note that parent will be swapped with left
        IndexOfParent = IndexOfLeft
      
    - if(rightChildIndex < sizeOfArray && a[rightChildIndex] > a[parentIndex])
        IndexOfParent = IndexOfRight
  
      if(IndexOfParent != indexOfNodeToHeapify) //This means we need a swap & check that all nodes below it are heapified
        swap(a[indexOfNodeToHeapify], a[IndexOfParent])
        heapifyANode(a,size,IndexOfParent);   <<<<<<<<<<<<<<<<

- Now array is inplace heapified but yet Tree is not created

c. Create Tree level order by traversing the array

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

void method_1_heapifyANode(int a[], int size, int i){            //This function heapifies every node seperately

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

                //Now parent is either left or right child
                //  We will check new parent is not less than either of its children
                //
                // Terminating condition for this recursion:
                // - (leftChildIdx > size)              //means no left child
                // - (rightChildIdx > size)             //means no right child
                // - a[parentIdx] > a[rightChildIdx]    //means parent is bigger no swap
                // - a[parentIdx] > a[leftChildIdx]     //means parent is bigger no swap
                //
                heapifyANode(a, size, parentIdx);
    }
}


void method_1_heapifyArrayInPlace(int a[], int size){

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

NODE *method_1_createMaxHeapTree(int a[], int i, int size)
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
void show_max_heap(priority_queue <int> a)
{
        cout<<"Max Heap from priority_queue<>\n";
        while(a.empty() != 1)   //empty() return value 1 if container is empty
        {
                cout<<a.top()<<" ";
                a.pop();
        }
}
int main(){
        int a[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
        

        NODE *ptr;

        int noofelements = sizeof(a) / sizeof(a[0]);        //11

        method_1_heapifyArrayInPlace(a, noofelements);

        cout<<"Array is heapified in place\n";
        printInPlaceHeapifiedArray(a, noofelements);

        ptr = method_1_createMaxHeapTree(a,0,noofelements);
        cout<<"Created Max Heap tree from heapified array\n";
}
```
<a name=c2></a>
**Method-2: STL priority_queue**
```c
- Instead of implementing the things by yourself, use STL priority_queue
- priority_queue<int> is implemented as MAX_HEAP.

#include<iostream>
#include<queue>
using namespace std;
int main() {
        priority_queue <int> pq;
        for(int n: {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17})
                pq.push(n);
        show_max_heap(pq);
}
```

<a name=co></a>
#### Complexity
- **Time:** 
  - Heapify a single node takes O(Log N) time complexity where N is the total number of Nodes. 
  - Therefore, building the entire Heap will take N heapify operations and the total time complexity will be `O(N*logN)`.
