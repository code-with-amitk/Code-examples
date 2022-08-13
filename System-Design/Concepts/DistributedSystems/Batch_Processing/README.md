**Batch Processing**
- MapReduce
- [Hadoop Distributed File System](#hdfs)


## Batch Processing
- A batch processing system takes a large amount of input data, runs a job to process it, and produces some output data.
- Example
  - _1. MapReduce(published in 2004):_ Implemented in these open source data systems: Hadoop, CouchDB, and MongoDB on **comodity Hardware**.

### MapReduce
- Does Batch processing on large datasets, where jobs run on parallel on 1000's of comodity hardwares.
- **Nodes in MapReduce**
  - _1. Mapper:_ Extract `<key, value>` from each input record. 
  - _2. Reducer:_ Combines data.
- Its similar to this Unix pipeline:
```c
//////Unix Pipeline//////
$ cat /var/log/nginx/access.log | awk '{print $7}' | sort | uniq -c | sort -r -n | head -n 5

//////MAPREDUCE PIPELINE////
file1 ------|
file2 --|   |                                                            |--> Node(Reducer)
        \/ \/                                                            |
        Node(Reader) ----> Node(Mapper)   -------->  Node(Sorter)   -----|--> Node(Reducer)
        /\                Break into <key,value>    Sort by Keys         |
filen --|                                                                |--> Node(Reducer)
                                                                           Combine sorted <key,value>
```
| | Unix Pipeline | MapReduce |
|---|---|---|
|Run on| 1 Machine | 1000's of machines|
|Writes on |Unix Filesystem|[HDFS]()|

**Sort-Merge join (on userId) Example**
- Mapper:
  - _Mapper-1:_ Seperates data into `<key=userId, value=activity event>`
  - _Mapper-1:_ Seperates data into `<key=userId, value=date of birth>`
- Sorter: Sort by keys
- _Reducer:_ Sees reduces meaningful information which userId uses particular url

<img src = images/sort-merge-join.PNG width=500 />

<a name=hdfs></a>
## Hadoop Distributed File System(derived from GFS-google file system)
- HDFS is 1 big filesystem, where disks from nodes(running on comodity hardware) are used and controlled by namenode(central controller). Default block size=64MB. (xfs block size=4kb). Machine talk over TCP/IP.
- _Fault Tolerance:_ Data blocks are replicated on multiple nodes. 
```c
Architecture
                         nameNode
                     /TCP        \TCP
            dataNode-1    -TCP   dataNode-2
```
- **Disadvantages of HDFS:**     1. Not fast with other file systems.    2. Cannot be mounted

