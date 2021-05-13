## execXX Family of function?
- All executes a file.
- Replaces current running process with a new process. [PCB](/Threads_Processes_IPC/Processes/Process_Table) of new process replaces old.
- There are 6 different execXX function calls. The differences between them is how the program is found, how the arguments are specified, and what are environment variables.
- **When exec() fails?** Exec can fail if the file name given does not exist ie not a valid executable file.
- **Fork vs Exec**

||fork(starts new process)|exec(replaces original process)|
|---|---|---|
|Control|Control returns to parent process|Control never returns back until issues in exec() call itself|

### Types

|Suffix|Function|Description|POSIX|
|---|---|---|---|
|v `argv[]`|[int execv(const char `*path`, char `*const argv[]`)](execv)|wrt execvp, execv does not search the PATH. Instead, the full path to the new executable must be specified|Yes|
|p PATH|[execvp(const char `*file`, char `*const argv[]`)](execvp)|File can specified locally or it will searched in PATH variable|Yes|
|e env will be taken from caller's env, else env is taken from parent's env|int execvpe(const `char*` file, `char* const argv[]`, `char* const envp[]`)|`char* const envp[]`: allow the caller to specify the environment of the executed program via the argument envp|No|
|l variable-length argument list|int execl(path, arg,...`/* (char  *) NULL */`)|Yes|
||[int execlp(file, arg,...`/* (char  *) NULL */`)](execlp)|file:  file name associated with the file being executed|Yes|
|e Enviornment Variable|int execle(path, arg, `.../*, (char *) NULL, char * const envp[] */`)||Yes|
