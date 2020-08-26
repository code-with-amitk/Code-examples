## Problem
- There is array[4] of unsigned long long(8 byte).
- Copy this array to char array and traverse using char *

## Code
```c
int main(){
  int noOfEntries = 4;
  unsigned long long ar[] = {10,20,30,40};              
  
  int size = sizeof(unsigned long long);          //8
  
  unsigned char *ptr = new unsigned char[noOfEntries*size +1];
  
  memcpy(ptr, arr, noOfEntries*size);
  
  unsigned long long test;
  
  for(unsinged int i=0; i<noOfEntries; i+=8){
    test = *((unsigned long long *)(ptr + i));            //Convert to long ptr 1st then to long int
    cout<<test;
  }
}

# g++ file.cpp -g
# ./a.out
10 20 30 40
-> Debug using gdb if you issues
```
