## How Shell works?
- When user types a command line, the shell extracts the first word from it. Assumes this as program. Finds, forks a child.Child runs the program. shell waits on waitpid().
- **Example:**
```c
main() {
  while (1) {                              
    cout << "#";
    getline (str, cin);              //str =>     cp  test1 test2
    int pid = fork();   
    if ( pid == 0)        //child
      execve (cp, params, 0);        //Replaces child with "cp" program. Once cp finishes it exists, never returns to child.
    else
      waitpid (-1, &status, 0)
  }
}
```
- **[Complete Code](Code)**
