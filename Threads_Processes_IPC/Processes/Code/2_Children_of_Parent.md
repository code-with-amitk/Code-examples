## Creating 2 Children of parent
- To create 2 children we need to call fork inside parent.
```c
#include <unistd.h>
#include <stdio.h>
#include <error.h>

void error(char* cString) {
  perror(cString);
  printf("%d", errno);
  exit(0);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string>
#include <iostream>
extern int errno;

void error(std::string cString) {
  //perror(cString);
  printf("%d", errno);
  exit(0);
}

int main() {
    pid_t child_a, child_b;

    child_a = fork();

    if (child_a == 0) {
        /* Child A code */
        sleep(1);
        std::cout << "Child1:" << getpid() << "\n";
    } else {
        child_b = fork();
        std::cout << "Parent:" << getpid() << "\n";

        if (child_b == 0) {
            /* Child B code */
            std::cout << "Child2:" << getpid() << "\n";
        } else {
            /* Parent Code */
            std::cout << "Parent:" << getpid() << "\n";
        }
    }
}

$ a.out
Child1: 1234
Parent: 780
Child2: 1235
Parent: 780
```
