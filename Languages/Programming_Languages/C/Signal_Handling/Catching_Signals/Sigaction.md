## Logic of sigaction
- *1.* 

## Code
- This program will not terminate on Cntrl^C.
```c
#include <signal.h>
#include <iostream>

void SIGINT_Handler(int signalNumber){
  std::cout<<"Got Cntrl^C\n";
  return;
}

int main(){
  struct sigaction stAction;
  stAction.sa_flags = 0;
  sigemptyset (&stAction.sa_mask);
  
  //Adding Handler for SIGINT
  stAction.sa_handler = SIGINT_Handler;
  sigaction (SIGINT, &stAction, NULL);
  
  while(1);
}
```
