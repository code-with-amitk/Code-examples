/*
Logic(unordered_set):
        - Create a circular LL.
        - Create a unordered_set<int>
                //unordered_set is implemented using Hash-Table
                //Why unordered_map<kkey,value> is not taken? Because key,value pair is required.
          1. Traverse Linked list.
          2. Place Linked List address pointer into unordered_set.      s.insert(ptr)
          3. before placing element into unordered LL check element exist or not?
   Complexity:
        Space: n
        Time: O(n). Finding hash and placing assumed in O(1).
 */
#include<iostream>
#include<unordered_set>
typedef struct node {
    int data;
    struct node* next;
}NODE;

NODE* newNode(int key)
{
    NODE* temp = new NODE();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int detectLoop_unordered_set(NODE *ptr){
        std::unordered_set<NODE *> s;
        while(ptr != NULL){
                if(s.find(ptr) != s.end())
                        return true;
                s.insert(ptr);
                ptr=ptr->next;
        }
}

int main()
{
        //      1 -> 2 -> 3 -> 4 -> 5
        //     /\                   |
        //      |                   |
        //       -------------------
        NODE* head = newNode(1);
        head->next = newNode(2);
        head->next->next = newNode(3);
        head->next->next->next = newNode(4);
        head->next->next->next->next = newNode(5);

        //Create Loop
        head->next->next->next->next->next = head;
        std::cout<<"created LL"<<std::endl;

        if(detectLoop_unordered_set(head))
                std::cout<<"Loop found";
        else
                std::cout<<"Loop not found"<std::endl;
        return 0;
}

//#g++ detect-loop.c --std=c++11
//Loop found
