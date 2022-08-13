**Batch Processing**
- **MapReduce**
  - [Similar to this Unix pipeline](#m1)
  - **Joins**
    - [1. Reducer Side Join / Sort-Merge join (on userId)](#smj)
    - [2. Map-Side join](#msj)
  - [Handling Hot Keys](#hhk)
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

<a name=m1></a>
#### MapReduce is similar to this Unix pipeline
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

### Joins
<a name=rsj></a>
#### 1. Reduce-Side Join / Sort-Merge join (on userId)
<img src = images/sort-merge-join.PNG width=500 />

- Since this algorithm joins the data at reducer, hence called reducer side join.
- Roles:
  - Mapper: Preparing data
  - Reducer: joins data
- Mapper:
  - _Mapper-1:_ Seperates data into `<key=userId, value=activity event>`
  - _Mapper-1:_ Seperates data into `<key=userId, value=date of birth>`
- Sorter: Sort by keys
- _Reducer(joins):_ Joins the data to meaningful information which userId uses particular url

<a name=msj></a>
#### 2. Map-Side join
- In [reduce-side join](#rsj) we do not make any assumptions about input data(its properties/structure), mappers prepares data to be ready for joining.
- But in Map-Side join certain assumptions about data can be made and that will make joins FASTER. In this approach there is no sorting(& no reducer).

<a name=hhk></a>
### Handling [Hot Keys / Skewed Join](/System-Design/Concepts/Terms/README.md#hk)
- In MapReduce we bring all keys to same place that may create a problem of [hot keys](/System-Design/Concepts/Terms/README.md#hk).
- **a. Pig**
  - _1._ Runs a sampling job to determine which keys are hot?
  - _2._ Sends records relating to a hot key to one of several reducers(chosen at random)
- **b. Hive**
  - _1._ Hot keys are specified in table's metadata & store records(related to hot keys) in seperate files

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

