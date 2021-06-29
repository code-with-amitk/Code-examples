- [1. What is Shell](#what)
- [2. Types of Shells](#types)
- [3. How shell works](#how)
- [4. Working Code](#work)
  - [4.1 C++ Shell](#cpp)
  - [4.2 C Code](#cc)

<a name=what></a>
## 1. Shell
- Computer program which exposes OS services to User or programs.

<img src=shell.PNG width=400/>

<a name=types></a>
## 2. Types of shells
- **a. Bash shell:** Comes with .bash_profile.
  - `~/.bash_profile?` Executed for shell Logins. 
    - Shell Login? When you are at remote machine, Login via ssh(type username/password) Before 1st time Command prompt arrives, bash_profile is executed
- **b. ksh/bourne shell(Default):** comes with .profile file.   
- **c. kcsh shell:** comes with .login file
  - `~/.bashrc?` Executed for non-shell logins.
    - Non-Shell login? You have already logged onto machine, now you open a new terminal window using xterm, vnc, KDE bashrc is executed.

<a name=how></a>
## 3. How shell works
- Program puts arguments on register, Switches context from user to kernel mode using [TRAP instruction](https://sites.google.com/site/amitinterviewpreparation/c-1/memory-management/virtual-memory)
- When user types a command line, the shell extracts the first word from it. Assumes this as program. Finds, forks a child.Child runs the program. shell waits on waitpid().
- **Example Code:**
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

<a name=work></a>
## 4. Working code

<a name=cpp></a>
### 4.1 C++ Shell
- *1.* Display prompt
- *2.* Take command from keyboard into string
- *3.* Tokenize command and place into `vector<string>`
- *4.* Execute Command
  - *a.* Create array of `char*` containing command and its arguments, since [execXXX()](/Threads_Processes_IPC/EXEC_Family_of_Functions) takes `char*` array.
  - *b.* [fork()](/Threads_Processes_IPC/Processes/Process_Creation) a child, run execvp replacing child process's [PCB](/Threads_Processes_IPC/Processes/Process_Table) with command to be executed.
  - *c.* Wait in parent on [waitpid()](https://linux.die.net/man/2/waitpid) for child.
```c++
#include<iostream>
#include<string>
#include<unistd.h>    //fork()
#include<sys/wait.h>
#include<boost/tokenizer.hpp>
#include<boost/algorithm/string.hpp>

using tokenizer = boost::tokenizer <boost::char_separator<char>>;
boost::char_separator<char> sep(" ");
using VectorString = vector<string>;

bool process (VectorString& vecInput) {                   //4
  int status;
  
  char *arr[vecInput.size() + 1];
  for (auto i=0; i<vecInput.size(); ++i)
    arr[i] = const_cast<char*>(vecInput[i].c_str());
  arr[vecInput.size()] = NULL;
  
  if (fork() == 0)    //Child                            //a
    execvp (arr[0], arr);
  else                                                  //b
    waitpid (-1, &status, 0);
    
  return true;    
}

int main(){
  string strInput;
  VectorString vec;
  while (1) {
    cout << "> ";                               //1
    getline (cin, strInput);                    //2
    boost::algorithm::trim (strInput);
    if (strInput == "q") {
      cout << "Bye!!\n";
      exit (0);
    }
    tokenizer tok(strInput, sep);               //3
    for (const auto& t:tok) 
      vec.push_back(t);

    process (vec);              
    vec.clear();
  }
}

# g++ shell.cpp
# ./a.out
> ls -l
```

<a name=cc></a>
### [4.2 C Code](https://github.com/brenns10/lsh/tree/407938170e8b40d231781576e05282a41634848c)
