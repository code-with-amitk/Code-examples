**Kinesis**

### Kinesis
Kinesis collects, process, and analyze real time data streams.
```c

------data stream-------> [1. Kinesis Data Streams]
                          Store data stream  ------------> [Storage]
                          
                          [2. Kinesis Data Firehose]<--data stream---
                          Takes & Process data stream
                          & provides to analytics -----processed data stream-----> [3. Kinesis Data Analytics]
                                                                                   Analyze streaming data
```
