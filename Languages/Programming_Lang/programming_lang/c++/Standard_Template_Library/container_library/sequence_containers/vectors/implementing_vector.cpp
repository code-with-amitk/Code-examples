/*      implementing_vector.cpp

You have been asked to implement a vector data structure, which allows 2 operations:
add element
search element - checks whether element is present in the vector

*************C Program Logic***************
- Take **p to array of char*. Each char* will point to allocated element in vector
- vector resizes/realloc() itself after every 3 insertions
*******************************************
*/

#ifdef PureC
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
char **p;
int size=0;
int resize=3;

void allocate_and_copy(char *t){
        p[size] = malloc(strlen(t)+1);
        strcpy(p[size],t);
        size++;
}

void search(char *t){                   //O(n). Basically binary_search is for sorted containers
        int i=0,set=0;
        char **m=p;
        while(i<size){
                if(!strcmp(m[i],t)){
                        printf("String %s found in vector\n",t);
                        set=1;
                        break;
                }
                i++;
        }
        if(!set)
                printf("String %s is not found\n");

}

void insert(char *t){
        if(!strlen(t)){
                printf("NULL string cannot be inserted in vector\n");
                return;
        }
        if(p==NULL){
                p = malloc(resize*sizeof(char *));
                allocate_and_copy(t);
                printf("copied [%s] to vector, sizeof vector[%d]\n",t,size);
                return;
        }

        //Search until free space
        if(size < resize){
                allocate_and_copy(t);
                printf("copied [%s] to vector, sizeof vector[%d]\n",t,size);
        }else{
                //Time to resize the vector.    realloc
                resize=resize+3;
                p = realloc(p,resize*sizeof(char *));
                allocate_and_copy(t);
                printf("copied [%s] to vector, sizeof vector[%d]\n",t,size);
        }
}

void destructor(){
        int i=0;
        char **m=p;
        while(i<size){
                free(p[i++]);
        }
        free(p);
        printf("vector deallocated\n");
}

int main(){
        insert("test");
        insert("test1");
        insert("test2");
        insert("test3");
        search("test2");
        destructor();
}
/*
# gcc implementing_vector.c 
# ./a.out 
copied [test] to vector, sizeof vector[1]
copied [test1] to vector, sizeof vector[2]
copied [test2] to vector, sizeof vector[3]
copied [test3] to vector, sizeof vector[4]
String test2 found in vector
vector deallocated
*/
#endif
