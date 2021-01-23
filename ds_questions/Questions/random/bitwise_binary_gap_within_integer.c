/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example,
- Number 9 has binary representation 1001 and contains a binary gap of length 2. 
- Number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.
- Number 20 has binary representation 10100 and contains one binary gap of length 1.
- Number 15 has binary representation 1111 and has no binary gaps. 
- Number 32 has binary representation 100000 and has no binary gaps.

Write a function:
class Solution { public int solution(int N); }

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
 */

/*Logic:
 - (&) the Number with 1 get binary value at position
 On Encounter of 1st 1:
        - Start counting gap till 2nd 1
 On Encounter of 2nd 1:
        - set variable high to value of gap.
        - reset gap variable.
 */
#include <stdio.h>
void main(){
        printf("sizeof(int)=%d\n",sizeof(int));
        int a = solution(1041);
        printf("binary gap=%d\n",a);
}

//Function returns longest Binary gap
int solution(int N){
        int i,gap=-1,start_count=0,high=0,first_1=0,second_1=0;
        for(i=0;i<sizeof(int)*8;i++){
                if(N&1){        //Found 1
                        if(first_1==1){
                                //This is second 1. Need to stop counting. Reset.
                                second_1 = 1;
                        }
                        first_1 = 1;
                }
                if(first_1){
                        gap = gap+1;
                        //printf("gap=%d, second_1=%d",gap,second_1);
                }
                if(second_1){
                        if(gap>high){
                                high=gap-1;
                        //      printf(", high=%d\n",high);
                        }
                        gap=0;
                        second_1=0;
                }
                N=N>>1;
        }
        return high;
}
