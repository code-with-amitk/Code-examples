#include<iostream>

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

void printReverse(NODE *ptr){
        if(ptr->next)
                printReverse(ptr->next);
        std::cout<<ptr->data<<"\t";
}

int main()
{
        //1->2->3->4->5
        NODE* head = newNode(1);
        head->next = newNode(2);
        head->next->next = newNode(3);
        head->next->next->next = newNode(4);
        head->next->next->next->next = newNode(5);
        std::cout<<"created LL"<<std::endl;

        printReverse(head);
        return 0;
}
