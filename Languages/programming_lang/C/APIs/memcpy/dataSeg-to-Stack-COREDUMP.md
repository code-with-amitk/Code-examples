## Data Segment to Stack

```
#include <stdio.h>
#include <string.h>

int main () {
   const char src[5] = "hello";
   char *dst;

   memcpy(dst, src, strlen(src)+1);
   printf("dest = %s\n", dst);             <<<<<CORE DUMP

   return(0);
}
```
