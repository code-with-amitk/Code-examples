## Implement Tail
- tail shows last n lines from file, n=10(default)
- **Example**
```c
# cat logfile
#Date Timestamp host    program-that-generated  log message
Nov 5 20:17:41 centos1 dhcpd[3022] service1 failed
Nov 5 20:17:42 centos1 dhcpd[3022] adding default route via 192.168.0.1 metric 0
Nov 5 20:17:43 centos1 systemd[1212] service3 failed
Nov 5 20:17:44 centos1 copper[4556] service4 error
Nov 5 20:17:44 centos1 copper[4556] service5 down

////////////Output/////////////
# tail logfile 3
Nov 5 20:17:43 centos1 systemd[1212] service3 failed
Nov 5 20:17:44 centos1 copper[4556] service4 error
Nov 5 20:17:44 centos1 copper[4556] service5 down
```

### Approach/Logic
- *1.* Program will take 3 command line arguments. if no-of-lines-tobe-displayed(default=10).
```
  # ./a.out   filename    number-of-lines-tobe-displayed(optional)
```
- *2.* Move to end of file and start counting CRLF from end. 
- *3.* Keep decrementing file pointer. 
- *4.* When (number-of-lines-tobe-displayed=CRLF_count), dump all lines from present file pointer till end.

### Complexity
- **Time** O(mn)
  - O(1): Moving to end of file. using inode
  - O(n): n lines to displayed
  - O(m): m words in each line
- **Space** O(1). No extra space used

### Code
- **1. C++ Code**
  - [seekg(), tellg(), streampos](Code-examples/blob/master/Languages/Programming_Languages/c%2B%2B/Libraries_FileHandling/Streams/File_Handling/Functions/README.md)
```c++
class Tail {
public:
  void MoveToNthLine(std::ifstream& fin, long lLines);       //Moves file pointer to nth line from End
  void DumpNLines(std::ifstream& fin, long lLines);
};

void Tail::DumpNLines(std::ifstream& fin, long lLines){
  String strLine;
  while(fin){
    std::getline(fin, strLine);
    std::cout<<strLine<<std::endl;
  }
}

void Tail::MoveToNthLine(std::ifstream& fin, long lLines){
  fin.seekg(0, std::ios::end);                      //Move to end of file

  std::streampos len = fin.tellg();                  //No of total characters in file

  int currPosition = len;                           //This is last position in file
  int end = len;

  char ch;
  long countLines = 0;

  for(int i=len; i>=0; i--){                        //Read each character from end
    fin >> ch;

//  std::cout<<"ch="<<static_cast<unsigned>(ch)<<"\n";

    if (ch == '\n' and (end - i) > 1) {             //Increment count on New line only
      ++countLines;
      if (countLines == lLines)
        break;
    }
    --currPosition;
    fin.seekg(currPosition, std::ios::cur);             //Move 1 character backward
  }
  DumpNLines(fin, currPosition);
  fin.close();
}

int main(int argc, char* argv[]){
  if(argc < 2){
    std::cout<<"./a.out file-name number-of-lines(optional)\n";
    return 0;
  }

  std::ifstream fin(argv[1], std::ios::ate);               //Open the file
  if (not fin){
    std::cout<<"File not found"<<std::endl;
    return 0;
  }

  Tail tail;
  long lLines = 10;
  if (argv[2])
    std::istringstream(argv[2]) >> lLines;    //Takes default=10 if no input provided
  tail.MoveToNthLine(fin, lLines);
}
```

- **2. C Code**
```c

```
