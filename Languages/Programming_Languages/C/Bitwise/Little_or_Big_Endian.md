## Little or Big Endian
```c
164:        1        0        1        0        0        1        0        0
          MSB(2^7)=1                                                   LSB(2^0)=0
```
- **Little Endian/Network byte order:** 
  - MSB At Higher Address, LSB at Lower Address. 164 is stored as (1 0 1 0 0 1 0 0). Eg: Intel x86, x86_64 
- **Big Endian/host byte order:** 
  - LSB at higher address. 164 stored as (0 0 1 0 0 1 0 1). Eg: IBM z/Architecture processors

## Code
- *1.* Store number=1 in memory. `0000000 0000000 0000000 00000100`
- *2.* Take char* to number.
- *3* Print 1st byte using char ptr, if char*=1, Little else Big.
```c
#include<iostream>

int main(){
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)
       printf("Little endian");
   else
       printf("Big endian");
   return 0;
}
```
