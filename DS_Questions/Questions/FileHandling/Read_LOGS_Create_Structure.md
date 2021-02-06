## Filter logs and create a structure
- Logfile is provided, filter the logs and fill the structure.
- **Log file** Contains logs similar to `/var/log/messages`
```c
#Date Timestamp host    program-that-generated  log message
Nov 5 20:17:41 centos1 dhcpd[3022] service1 failed
Nov 5 20:17:42 centos1 dhcpd[3022] adding default route via 192.168.0.1 metric 0
Nov 5 20:17:43 centos1 systemd[1212] service3 failed
Nov 5 20:17:44 centos1 copper[4556] service4 error
Nov 5 20:17:44 centos1 copper[4556] service5 down
```

### Approach
- **Logic**
  - *1.* Open and Read the file line by line.
  - *2.* Tokenize the line based on Space using `boost::tokenizer` store tokens in `vector<string>`
  - *3.* Pass this `vector<string>` to create() to fill in structure.
```c
  typedef struct date{
    std::string month;
    int day;
  }DATE;
  typedef struct Log{
    DATE d;
    String strTime;
    String strHostname;
    String strProgram;
    String strMessage;
  }LOG;
```
  - *4.* For faster searching of log, we will store in `unordered_multimap<key='failed or error or shutdown or down', value=Log_Structure>`
```c
LOG log1 = |month=Nov|day=5|Time=20:17:41|hostname=centos1|program=dhcpd[3022|message=service1 failed|
LOG log2 = |month=Nov|day=5|Time=20:17:42|hostname=centos1|program=dhcpd[3022|message=adding default route via 192.168.0.1 metric 0|
LOG log3 = |month=Nov|day=5|Time=20:17:43|hostname=centos1|program=systemd[1212]|message=service3 failed|
LOG log4 = |month=Nov|day=5|Time=20:17:44|hostname=centos1|program=copper[4556]|message=service4 error|
LOG log5 = |month=Nov|day=5|Time=20:17:45|hostname=centos1|program=copper[4556]|message=service5 down|

unordered_multimap
|                               |                       |                        |                       |
| key=failed |value = log1,log3 | key=None|value = log2 | key=error | value=log4 | key=down | value=log5 |
|                               |                       |                        |                       |
```
- **Complexity**
  - **Time:** O(mn)   //n:Words in file, m:line in log file
    - Parsing and storing in structure VectorString: m
    - Doing it n times.
  - **Space:** O(mn) + O(n) + O(m) = O(mn)
    - Tokenizer VectorString: n
    - m structures of n words: m x n
    - `unordered_multimap:` m keys
- **Code**
```c++
#include<fstream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<boost/tokenizer.hpp>

using VectorString = std::vector<std::string>;
using String = std::string;

std::unordered_set<String> ErrorSet = {
  "failed", "error", "down", "shutdown", "None"
};

class Logger{
  typedef struct date{
    std::string month;
    int day;
  }DATE;

  typedef struct Log{
    DATE d;
    String strTime;
    String strHostname;
    String strProgram;
    String strMessage;
  }LOG;

  std::unordered_multimap<String, LOG> umm;
public:
  bool create(VectorString);
  void dumpAll();
  void searchLog(String);
};

void Logger::dumpAll(){
  for (auto [i,j]:umm){
    std::cout<<j.d.month<<" "<<j.d.day<<" "<<j.strTime<<" "\
            <<j.strHostname<<" "<<j.strProgram<<" "\
            <<j.strMessage<<"\n";
  }
}

void Logger::searchLog(String strError){
  int i =0;
  auto it = umm.find(strError);
  if(it != umm.end()){
    while(i<umm.count(strError)){
      std::cout<<it->second.strMessage<<"\n";
      ++i;++it;
    }
  }
}

bool Logger::create(VectorString Tokens){
  std::string strWord;
  uint8_t i = 0;
  LOG log;

  int iValue;
  //We know at which places what value is present
  log.d.month = Tokens[0];
  std::istringstream(Tokens[1]) >> iValue;
  log.d.day = iValue;
  log.strTime = Tokens[2];
  log.strHostname = Tokens[3];
  log.strProgram = Tokens[4];

  //Create string of message, Detect ErrorWord
  auto it = Tokens.begin();
  std::advance(it, 5);
  String strTemp;
  String strKey = "None";
  while (it != Tokens.end()){
    if(ErrorSet.find(*it) != ErrorSet.end())
      strKey = *it;
    strTemp += *it++ + " ";
  }
  log.strMessage = strTemp;

  umm.insert(std::make_pair(strKey, log));
  return true;
}

class Utils{
public:
  typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
  boost::char_separator<char> sep{" "};

   VectorString Tokenize(std::string& strInput){
    VectorString vec;
    tokenizer tok{strInput, sep};
    for (const auto i:tok)
      vec.push_back(i);
    return vec;
  }
};

int main(){
  std::ifstream fin("logfile");
  if(not fin){
    std::cout<<"File does not exist";
    return 0;
  }

  String strLine, strWord;
  Logger oLogger;
  Utils oUtils;
  std::getline(fin, strLine);     //skip header
  while(fin){
    std::getline(fin, strLine);
    if (strLine.size()){
      if(not oLogger.create(oUtils.Tokenize(strLine)))
        std::cout<<"Wrong feild in log";
    }
  }
  fin.close();
  oLogger.dumpAll();
  oLogger.searchLog("failed");
}
```
