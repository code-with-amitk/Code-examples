## Exec Family of function?
- **What?**
  - Replaces current running process with a new process. PCB of new process replaces old.

### Types
- **int execvp (file, args)**
  - file is Executable name which need to started in my place.    (github: execvp.c)
- **int execv(path, argv[])**    
  - path: should point to the path of the file being executed
- **int execlp(file, arg,.../* (char  *) NULL */):**    
  - file:  file name associated with the file being executed
- **int execl(path, arg,.../* (char  *) NULL */)**
- **int execvpe(file, argv[],char *const envp[]):**    
  - char* const envp[]: allow the caller to specify the environment of the executed program via the argument envp. 
- **int execle(path, arg, .../*, (char *) NULL, char * const envp[] */)**
