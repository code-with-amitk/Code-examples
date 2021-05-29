## C++ Shell code
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
