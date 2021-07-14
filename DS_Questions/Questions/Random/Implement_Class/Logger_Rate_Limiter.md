- [Logger Rate Limiter](#ques)
- [Approach-1, Hashtable](#apr1)
  - [1. Logic](#logic)
  - [2. Complexity](#comp)
  - [3. Code](#code)
    - [3.1 C++](#cpp)
    - [3.2 Rust](#rust)

<a name=ques></a>
## [Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/)
- Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).
- All messages will come in chronological order. Several messages may arrive at the same timestamp.
- Implement the Logger class:
```c
Logger(): 
  Initializes the logger object.

bool shouldPrintMessage(int timestamp, string message):
  Returns true if the message should be printed in the given timestamp, otherwise returns false.
```
- Example
```c
Input
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output
[null, true, true, false, false, false, true]

Explanation
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is
                                      // 11 + 10 = 21
```

<a name=apr1></a>
## Approach-1, Hashtable

<a name=logic></a>
- **1. Logic**
  - Take `unordered_map<key=message, value=timestamp>`, Initialize it inside constructor to {}
  - Check 
    - if message is not present in hashtable return true. create entry
    - if message is present and timestamp>=earlier_timestamp+10. return true. update timestamp
    - else return false

<a name=comp></a>
- **2. Complexity**
  - **Time:** O(1)
  - **Space:** O(n). n=Number of unique messages

<a name=code></a>
- **3. Code**

<a name=cpp></a>
**3.1 C++**
```c++
class Logger {
                //message,timestamp
    unordered_map<string,int> umMessage;
public:
    Logger() {    
        umMessage = {};
    }

    bool shouldPrintMessage(int timestamp, string message) { 
        auto itr = umMessage.find(message);
        
        if (itr == umMessage.end()) {  //New message
            umMessage[message] = timestamp;
            return true;
        } else {                      //Old Message
            if (itr->second <= timestamp - 10) {
                itr->second = timestamp;
                return true;
            }
        }
        return false;
    }
};
```
<a name=rust></a>
**3.2 Rust**
