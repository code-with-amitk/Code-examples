**Shell**
- **Types of Shells**
  - [Bash](#bash)
  - [Ksh](#ksh)
  - [Kcsh](#kcsh)
- [How shell works](#how)
- **Code**
  - [1. C++: Execute commands, Redirection](#cpp)
  - [2. C](#cc)

## Shell
Computer program which exposes OS services to User or programs.

<img src=shell.PNG width=400/>

## Types of shells
<a name=bash></a>
- **a. Bash shell:** Comes with .bash_profile.
  - `~/.bash_profile?` Executed for shell Logins. 
    - Shell Login? When you are at remote machine, Login via ssh(type username/password) Before 1st time Command prompt arrives, bash_profile is executed
<a name=ksh></a>
- **b. ksh/bourne shell(Default):** comes with .profile file.   
<a name=kch></a>
- **c. kcsh shell:** comes with .login file
  - `~/.bashrc?` Executed for non-shell logins.
    - Non-Shell login? You have already logged onto machine, now you open a new terminal window using xterm, vnc, KDE bashrc is executed.

<a name=how></a>
## How shell works
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

## Code
<a name=cpp></a>
### 1. C++ Shell
- This code can: Execute commands, redirect output to a file.
> [execXXX()](/Threads_Processes_IPC/EXEC_Family_of_Functions), [fork()](/Threads_Processes_IPC/Processes/Process_Creation),  [PCB](/Threads_Processes_IPC/Processes/Process_Table), [waitpid()](https://linux.die.net/man/2/waitpid)
- **Steps**
  - _1._ Display shell prompt
  - _2._ Read command from keyboard into string and trim leading, trailing spaces.
  - _3._ if input command is "q" exit.
  - _4._ Tokenize the command and place into `vector<string>` with sepeartor space " ".
  - _5._ if input contains ">" jump to Redirect() function to process [redirection command]().
    - _5a._ Create file into which output needed to be redirected
    - _5b._ [dup2()](/Operating_Systems/Linux/Kernel/System_Calls) stdout as newly created file descriptor. so STDOUT,new file both point to new file.
    - _5c._ Remove file name, `>` from input string and pass string to execute function.
  - _6._ if input does not contain ">", excute the command.
    - _6a._ Create array of `char*` containing command and its arguments
    - _6b._ execute the command in child process and wait in parent
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

void Execute (VectorString& vecInput) {                         //6              
  int status;
  
  char *arr[vecInput.size() + 1];                               //6a
  for (auto i=0; i<vecInput.size(); ++i)
    arr[i] = const_cast<char*>(vecInput[i].c_str());
  arr[vecInput.size()] = NULL;

  if (fork() == 0)    //Child                                    //6b
    execvp (arr[0], arr);
  else                                          
    waitpid (-1, &status, 0);
}

//ls -ltr > a.txt
//Implements redirect using dup2
void Redirect (VectorString& vecStr) {
  int saved_stdout = dup(1);                              //Saving stdout for restoring after getting work done
  
  //Considering last as file name
  int oldfd = creat (vecStr[vecStr.size() - 1].c_str(), 0644);    //5a
  dup2 (oldfd, STDOUT_FILENO);                                    //5b
  vecStr.pop_back();      //Remove filename                       //5c
  vecStr.pop_back();      //Remove redirection symbol >
  Execute (vecStr);
  
  dup2(1, saved_stdout);                                  //Work completed, restore stdout back.
  close (oldfd);
}

//ls -ltr | grep a.out
//Implements Pipe |
void Pipe (VectorString& vecStr) {
  VectorString::iterator itr;
  VectorString temp;
  for (itr = vecStr.begin(); itr != vecStr.end(); itr++) {
    if (*itr == "||")
      Execute (temp);
    temp.push_back (*itr);
  }
}

int main() {
  string strInput;
  VectorString vecStr;
  
  while (1) {
    cout << "> ";                               //1
    getline (cin, strInput);                    //2
    boost::algorithm::trim (strInput);
    if (strInput == "q") {                      //3
      cout << "Bye!!\n";
      exit (0);
    }
    
    tokenizer tok(strInput, sep);               //4
    for (const auto& t:tok) 
      vecStr.push_back(t);

    if (count(vecStr.begin(), vecStr.end(), ">"))   //5
      Redirect(vecStr);
    else if (count.vecStr.begin(), vecStr.end(), "|")
      Pipe (vecStr);
    else                                          //6
      Execute (vecStr);

    vec.clear();
  }
}

# g++ shell.cpp
# ./a.out
> ls -l
```

<a name=cc></a>
### [2. C Code](https://github.com/brenns10/lsh/tree/407938170e8b40d231781576e05282a41634848c)
