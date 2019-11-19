/*
 Logic: Remember ASCII Chart.
        48 - 57 == 0-9
        65 - 90 == A-Z
        97 - 122 == a-z
        10 == \n
 */
#include<stdio.h>
void main(){
        char ar[] = "abc44651a$$";
        int i=0, num=0, alp=0, size;
        size = sizeof(ar);
        printf("Array = [%s]\n", ar);
        for (i=0;i<size;i++){
                if(48<=ar[i]&& ar[i]<=57){ num++;}
                if(97<=ar[i]&& ar[i]<=122){ alp++;}
        }
        printf("Numbers in Array = %d\n",num);
        printf("Alphabets in Array = %d\n",alp);
}
