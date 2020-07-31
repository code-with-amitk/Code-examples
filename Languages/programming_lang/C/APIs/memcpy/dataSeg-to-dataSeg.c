# Data Segment to Data Segment copy
- Filled strings lies in initlaized data segment
- strcpy would be better wrt memcpy here.

```
#include <stdio.h>
#include <string.h>

int main () {
   const char src[5] = "hello";
   char dest[6];

   memcpy(dest, src, strlen(src)+1);
   
   printf("dest = %s\n", dest);       //dest=hello
}
```
