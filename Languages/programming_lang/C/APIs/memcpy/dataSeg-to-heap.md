## Data segment to heap

```c
#include <stdio.h>
#include <string.h>

int main () {
   const char src[5] = "hello";
   char *dst = malloc(sizeof(char) * 6);

   memcpy(dst, src, strlen(src)+1);
   printf("dest = %s\n", dst);            //dst

   return(0);
}
```
