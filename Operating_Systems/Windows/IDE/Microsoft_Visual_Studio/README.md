**Visual Studio**
- [Shortcuts: call stack, threads](#s)
- **Debugging using VS**
  - [Remote Debugging](#r)
  - [Multithreaded Application](#m)
- [Code in VS build on Windows, WSL both](#c)

### Visual Studio
We can develop: Computer programs, Websites, Web apps, web services and mobile apps using VS.
<a name=s></a>
#### Shortcuts 
```c
Call stack  => Cntl + Alt + C
Threads     => Cntl + Alt + H. 		Debug > Windows > Threads
Parallel Stacks => Cntl + Shift + D. 	Debug > Windows > Parallel Stacks
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
  
2. Open Parallel stacks to see stacks of all threads. Cntl + shift + D  . Debug > Windows > Parallel Stacks

3. Show Threads in Code. Click on Button in Visual Studio Bar. This will place marker in code where specific threads are.
```

<a name=c></a>
## Code in VS build on Windows, WSL both
We will create CMake project which will build on Windows, Linux(WSL) both.
- _A._ [Target WSL from Visual Studio](https://devblogs.microsoft.com/cppblog/targeting-windows-subsystem-for-linux-from-visual-studio/)
```c
1. On WSL
 1a. Install gdbserver
wsl$ sudo apt install -y build-essential
wsl$ sudo apt install -y gdbserver        //For remote debugging

 1b. Install and configure ssh 
wsl$ sudo apt install -y openssh-server
wsl$ vim /etc/ssh/sshd_config
PasswordAuthentication yes
$ sudo ssh-keygen -A
$ sudo service ssh start

2. Install & configure Visual Studio
- Install Linux development with c++
- Now you can connect to WSL from Visual Studio. Tools > Options > Cross Platform > Connection Manager.
  Click add and enter “localhost” for the hostname and your WSL user/password.
```

- _B._ [Create a CMake Linux project in Visual Studio](https://docs.microsoft.com/en-us/cpp/linux/cmake-linux-project?view=msvc-160)
```c
1. Create a new Linux CMake project
2. Add a Linux configuration
  From the main toolbar, open the Configuration dropdown and choose Manage Configurations.
    chose: Linux-GCC-Debug or Linux-GCC-Release.
  Refresh Intellisense it will copy files on WSL at location:
    /home/amit/.vs/
```

- _C._ Build on Linux from Visual Studio it will print "Linux". Build on windows from VS it will print "Windows".
```cpp
using namespace std;
int main()
{
	cout << "Hello CMake." << endl;
#if defined(WIN32)
	cout << "Windows";
#else
	cout << "Linux";
#endif
	return 0;
}
```

- _D._ if stuck see this [Microsoft Article](https://docs.microsoft.com/en-us/cpp/linux/cmake-linux-project?view=msvc-160).
