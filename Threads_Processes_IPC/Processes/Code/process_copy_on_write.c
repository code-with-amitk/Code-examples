/*      process_copy_on_write.c
COW(Copy On Write): 
- CS, DS, SS, HS all are shared between parent & child Initially. If any one of them Modifies, New page is created & modified data is copied    
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Code-1: Parent & child process executing same code
void main(){
    fork();
    printf("Hello");
}
Output
    Hello    //Child
    Hello    //Parent
Why? CS for parent and child are same
*/


/*Code-2: COW*/
int dsVar = 10;    //DS variable
void main(){
        int stackVar=10;        //stack variable
        int *heapVar  = malloc(sizeof(int));
        *heapVar=10;    //Heap variable

        if(fork() == 0){    //Child
                stackVar = *heapVar = dsVar = 20;        //Child CS Changed
                printf("%d %d  %d\n", stackVar, *heapVar, dsVar);   // =>    20 20 20
        }else{    //Parent
                printf("%d %d  %d\n", stackVar, *heapVar, dsVar);   // =>    10 10 10
        }
}
/*
Output:
10 10  10
20 20  20
*/
