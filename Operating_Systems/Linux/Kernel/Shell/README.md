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
    if ( pid == 0) {       //Child
     //Replaces child with "cp" program. 
     //Once cp finishes it exists, never returns to child.
      execve (cp, params, 0);       
    } else {              //Parent
      waitpid (-1, &status, 0)
    }
  }
}
```

## Code
<a name=cpp></a>
### 1. C++ Shell
- This code can: Execute commands, redirect output to a file, run pipe `|` command.
> [execXXX()](/Threads_Processes_IPC/EXEC_Family_of_Functions), [fork()](/Threads_Processes_IPC/Processes/Process_Creation),  [PCB](/Threads_Processes_IPC/Processes/Process_Table), [waitpid()](https://linux.die.net/man/2/waitpid), [dup2()](/Operating_Systems/Linux/Kernel/System_Calls)
```c++
#include<iostream>
#include<string>
#include<vector>
#include<fcntl.h>       //creat
#include<algorithm>
#include<unistd.h>    //fork()
#include<sys/wait.h>
#include<boost/tokenizer.hpp>
#include<boost/algorithm/string.hpp>

using tokenizer = boost::tokenizer <boost::char_separator<char>>;
boost::char_separator<char> sep(" ");
using VectorString = std::vector<std::string>;

/*
Execute the command.
1. Create array of `char*` containing command and its arguments
2. execute the command in child process and wait in parent
*/
void Execute (VectorString& vecInput) {
  int status;

  char *arr[vecInput.size() + 1];                               //1
  for (auto i=0; i<vecInput.size(); ++i)
    arr[i] = const_cast<char*>(vecInput[i].c_str());
  arr[vecInput.size()] = NULL;

  if (fork() == 0)    //Child                                    //2
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

/*Implements Pipe(|)  ls -ltr | grep a.out
How grep works?
 grep string file-name
  Prints string inside file
Logic:
  1. Save STDOUT=1 to restore after doing work
  2. Create a file(child.txt) to redirect output of execvp() into it
  3. duplicate STDOUT to child.txt. Now anything written on STDOUT will go to child.txt
  4. Parse the command. ls -ltr | grep test
    a. Execute 1st command (ls -ltr) using execvp and write output to child.txt
    b. Create vector contaning 2nd command after pipe
  5. Restore stdout.
  6. Create command as "grep test child.txt" and execute using execvp()
*/
void Pipe (VectorString& vecStr) {
  int saved_stdout = dup(1);            //1
  int fd = creat("child.txt", 0644);    //2
  dup2(fd, STDOUT_FILENO);              //3

  VectorString::iterator itr;
  VectorString temp;
  for (itr = vecStr.begin(); itr != vecStr.end(); itr++) {
    if (*itr == "|") {
      Execute (temp);                   //4a  ls -ltr
      continue;
    }
    temp.push_back (*itr);              //4b grep test
  }
  close (fd);
  dup2 (saved_stdout, STDOUT_FILENO);   //5
  temp.push_back("child.txt");          //6
  Execute (temp);
}

/* We will create 1 string that is passed to execvp()
   Example:
    ls & => ls&
*/
void BackGroundJob (VectorString& vecStr) {
    //Create 1 string
    std::string strTemp;
    for (auto i:vecStr) {
        strTemp += i;
    }
    VectorString vec;
    vec.push_back(strTemp);
    Execute (vec);
}

/*
1. Display shell prompt, Read command from keyboard into string, trim leading, trailing spaces.
2. Tokenize the command and place into `vector<string>` with sepeartor space " ".
3. Checks type of command
  3a. if input contains ">" call Redirect().
  3b. if input contains "|" call Pipe().
  3c. if input contains "&" call backGroundJob()
  3d. For normal command "ls -ltr" call Execute().
*/
int main() {
  std::string strInput;
  VectorString vecStr;

  while (1) {
    std::cout << "> ";                               //1
    getline (std::cin, strInput);
    boost::algorithm::trim (strInput);
    if (strInput == "q") {
      std::cout << "Bye!!\n";
      exit (0);
    }

    tokenizer tok(strInput, sep);               //2
    for (const auto& t:tok) {
        vecStr.push_back(t);
    }

    if (count(vecStr.begin(), vecStr.end(), ">"))  //3a
      Redirect(vecStr);
    else if (count(vecStr.begin(), vecStr.end(), "|")) //3b
      Pipe (vecStr);
    else if (count(vecStr.begin(), vecStr.end(), "&")) //3c
      BackGroundJob (vecStr);
    else                                          //3d
      Execute (vecStr);

    vecStr.clear();
  }
  return 0;
}

# g++ shell.cpp
# ./a.out
> ls -l
```

<a name=cc></a>
### [2. C Code](https://github.com/brenns10/lsh/tree/407938170e8b40d231781576e05282a41634848c)
