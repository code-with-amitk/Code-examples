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

### Working Code
```c
#include<iostream>
#include<string>
#include<unistd.h>    //fork()
#include<sys/wait.h>
#include<boost/tokenizer.hpp>
#include<boost/algorithm/string.hpp>

using tokenizer = boost::tokenizer <boost::char_separator<char>>;
boost::char_separator<char> sep(" ");
using VectorString = vector<string>;

bool process (VectorString& vecInput) {
  int status;
  
  char *arr[vecInput.size() + 1];
  for (auto i=0; i<vecInput.size(); ++i)
    arr[i] = const_cast<char*>(vecInput[i].c_str());
  arr[vecInput.size()] = NULL;
  
  if (fork() == 0)    //Child
    execvp (arr[0], arr);
  else    
    waitpid (-1, &status, 0);
    
  return true;    
}

int main(){
  string strInput;
  VectorString vec;
  while (1) {
    cout << "> ";
    getline (cin, strInput);
    boost::algorithm::trim (strInput);
    if (strInput == "q") {
      cout << "Bye!!\n";
      exit (0);
    }
    tokenizer tok(strInput, sep);
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
