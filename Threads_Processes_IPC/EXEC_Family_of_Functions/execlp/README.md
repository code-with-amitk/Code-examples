## execlp (const char `*file`, const char `*arg`, ...);
- l: variable-length argument list will be passed
- p: name of the program to run will be taken from filename specified or PATH variable is searched for program

### Code
```c
#include <unistd.h> // execlp()

int main(void) {
  //Way-1
  //execlp("ls", "ls", "-l", NULL);
  
  //Way-2
  const char* args[] = {"ls", "-l", NULL};    //ls is searched in PATH and found at /usr/bin/ls
  execlp(args[0], args[0], args[1], NULL);
  
  printf("This line will not print\n");       //This line is not printed
}
```

