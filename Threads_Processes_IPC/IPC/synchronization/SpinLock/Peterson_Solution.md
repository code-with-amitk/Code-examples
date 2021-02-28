## Peterson Solution
- Before going into critical section each process or thread calls enter_region() function
- Before leaving critical_section they call leave_region

### Code
```c
#define FALSE 0
#define TRUE 1
#define N 2         /* number of processes */
int turn;           /* whose turn is it? */
int interested[N]; /* all values initially 0 (FALSE) */

void enter region(int process){   
  int other;                            /* number of the other process */
  other = 1 − process;                  /* the opposite of process */
  interested[process] = TRUE;           /* show that you are interested */
  turn = process;                       /* set flag */
  while (turn == process && interested[other] == TRUE) /* null statement */ ;
}

void leave region(int process){              /* process: who is leaving */
  interested[process] = FALSE;              /* indicate departure from critical region */
}

///////////Thread-1 or Process-1//////////////
while (TRUE) {
  while (shared_var != 0)
    critical_section();
    shared_var = 1;
    noncritical_section();
  }
}

//////////Thread-2 or Process-2/////////////////
while (TRUE) {
  while (shared_var != 1)
    critical_section();
    shared_var = 0;
    noncritical_section();
  }
}
```
