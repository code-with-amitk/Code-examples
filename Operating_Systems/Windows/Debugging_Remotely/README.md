## Remote Debugging using Windows
**Steps**
- *1.* Copy "Visual Studio Remote machine debugger" to remote machine.
```html
  Copy c:/Program filesx(x86)/Microsoft Visual Studio 11.0/Common7/IDE/Remote Debugger/x64  to remote machine
```
- *2.* Configure Remote Debugging
```html
  Project_Property > Debugging > Remote Windows Debugger
    |- Remote Command: c:/amit/test.exe               //Place test.exe in c:/amit on Remote machine
    |- 
```
- *3.* Build program in debug mode in Visual Studio.
