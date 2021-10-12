**Visual Studio**
- [Shortcuts: call stack, threads](#s)
- **Debugging using VS**
  - [Remote Debugging](#r)
  - [Multithreaded Application](#m)

### Visual Studio
We can develop: Computer programs, Websites, Web apps, web services and mobile apps using VS.
<a name=s></a>
#### Shortcuts 
```c
Call stack  => Cntl + Alt + C
Threads     => Cntl + Alt + H
Parallel Stacks => Cntl + Shift + D
Processes   => Cntl + Alt + Z
```

## Debugging using Visual Studio
<a name=r></a>
### Remote debugging using VS
```c
1. Copy "Visual Studio Remote machine debugger" to remote machine and run `msvsmon.exe` locally.
  a. Copy c:/Program filesx(x86)/Microsoft Visual Studio 11.0/Common7/IDE/Remote Debugger/x64  to remote machine
  b. Run msvsmon.mon present at above path on local machine & Remote Machine Both
      |- Tool > Options >
        > Allow any user to debug
        > No Authentication. Maximum idle time: 0
        
2. Build exe in debug mode and place on remote machine
  Project_Property > Configuration > Active(Debug), Platform:Active(x64)
  copy test.exe to c:/amit/test.exe on remote machine

3. Configure remote debug in Visual Studio
  Project_Property > Debugging > Remote Windows Debugger
    |- Remote Command: C:/amit/test.exe               //Place test.exe in c:/amit on Remote machine
    |- Remote server name: Remote IP Address
    |- Remote Command Arguments:  -i
    |- Working Directory: C:/amit
    |- Connection:        Remote with no authentication

4. Press F5 on local system to start debugging.
```

<a name=m></a>
### Debugging Multithreaded Application using VS
```c
1. Goto Threads Window (Cntl + Alt + H)
Columns in thread window
  ID        : Thread identifier
  Category  : Category of threads either (UI, RPC handlers, or worker threads).
  Location  : Shows where the thread is running. We can expand this location to show the full call stack for the thread.
  Process Name: An advanced column (hidden by default) shows process to which each thread belongs.
  
2. Open Parallel stacks to see stacks of all threads. Cntl + shift + D  

3. Show Threads in Code. Click on Button in Visual Studio Bar. This will place marker in code where specific threads are.
```
