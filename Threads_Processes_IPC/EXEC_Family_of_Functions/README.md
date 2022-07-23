**exec Family of function**
- [What](#what)
- [fork vs exec](#vs)
- **Types**
  - [execv](#v)
  - [execvp](#vp)
  - [execlp](#lp)

<a name=what></a>
### What is exec
- The exec family of functions replaces the current/running process with a new process.
- All functions executes a file [PCB](/Threads_Processes_IPC/Processes/Process_Table) of new process replaces old.
- There are 6 different execXX function calls. The differences between them is how the program is found, how the arguments are specified, and what are environment variables.
- **When exec() fails?** Exec can fail if the file name given does not exist ie not a valid executable file.

<a name=vs></a>
### Fork vs Exec
```c
        fork(starts new process) | exec(replaces original process)
---------------------------------|-----------------------------------
Control returns to parent process| Control never returns back until issues in exec() call itself
```

### Types
<a name=v></a>
#### int execv(const char `*path`, char `*const argv[]`)
v: Varaible number argument array `argv[]` is used to pass.
- wrt execvp, execv does not search the PATH. Instead, the full path to the new executable must be specified.
```c
#include <unistd.h> // execv()
#include <stdio.h>
int main() {
  char *const argv[] = {"/bin/ls", "-l", NULL};   //Full path is specified
  execv(argv[0], argv);
  printf("This line will not execute\n");
}
```

<a name=vp></a>
#### execvp(const char `*file`, char `*const argv[]`)
- v: Variable number of arguments passed in array `argv[]`
- p: name of the program to run will be taken from filename specified or program will be searhed using PATH variable.
```c
//Program-1
#include <stdio.h>
void main() {
    printf ("I am prog1");
}
# gcc prog1.c -o PROG1

//Program-2
#include <unistd.h>
#include <stdio.h>
void main(){
  char *args[] = {"./PROG1", NULL};
  execvp(args[0], args);
  printf("\nProg2 Last line");    //This line not executed bcoz as soon as the execvp() function is called, this program is replaced by PROG1
}
# gcc prog2.c -o PROG2
# ./PROG2
    I am prog1
```

<a name=lp></a>
#### execlp (const char `*file`, const char `*arg`, ...);
- l: variable-length argument list will be passed
- p: name of the program to run will be taken from filename specified or PATH variable is searched for program
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


|Suffix|Function|Description|POSIX|
|---|---|---|---|
|v `argv[]`|[int execv(const char `*path`, char `*const argv[]`)](execv)|wrt execvp, execv does not search the PATH. Instead, the full path to the new executable must be specified|Yes|
|p PATH|[execvp(const char `*file`, char `*const argv[]`)](execvp)|File can specified locally or it will searched in PATH variable|Yes|
|e env will be taken from caller's env, else env is taken from parent's env|int execvpe(const `char*` file, `char* const argv[]`, `char* const envp[]`)|`char* const envp[]`: allow the caller to specify the environment of the executed program via the argument envp|No|
|l variable-length argument list|int execl(path, arg,...`/* (char  *) NULL */`)||Yes|
||[int execlp(file, arg,...`/* (char  *) NULL */`)](execlp)|file:  file name associated with the file being executed|Yes|
|e Enviornment Variable|int execle(path, arg, `.../*, (char *) NULL, char * const envp[] */`)||Yes|
