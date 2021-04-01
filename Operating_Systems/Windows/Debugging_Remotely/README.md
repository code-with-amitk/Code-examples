## Remote Debugging using Visual Studio
**Steps**
- *1.* Copy "Visual Studio Remote machine debugger" to remote machine and run `msvsmon.exe` locally.
```c
  a. Copy c:/Program filesx(x86)/Microsoft Visual Studio 11.0/Common7/IDE/Remote Debugger/x64  to remote machine
  b. Run msvsmon.mon present at above path on local machine & Remote Machine Both
      |- Tool > Options >
        > Allow any user to debug
        > No Authentication. Maximum idle time: 0
```
- *2.* Build exe in debug mode and place on remote machine
```c
  Project_Property > Configuration > Active(Debug), Platform:Active(x64)
  copy test.exe to c:/amit/test.exe on remote machine
```
- *3.* Configure remote debug in Visual Studio
```c
  Project_Property > Debugging > Remote Windows Debugger
    |- Remote Command: C:/amit/test.exe               //Place test.exe in c:/amit on Remote machine
    |- Remote server name: Remote IP Address
    |- Remote Command Arguments:  -i
    |- Working Directory: C:/amit
    |- Connection:        Remote with no authentication
```
- *4.* Press F5 on local system to start debugging.
