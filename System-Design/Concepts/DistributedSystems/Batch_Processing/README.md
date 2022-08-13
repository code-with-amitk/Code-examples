**Batch Processing**
- MapReduce
- [Hadoop Distributed File System](#hdfs)


## Batch Processing
- A batch processing system takes a large amount of input data, runs a job to process it, and produces some output data.
- Example
  - _1. MapReduce(published in 2004):_ Implemented in these open source data systems: Hadoop, CouchDB, and MongoDB on **comodity Hardware**.

### MapReduce
- Does Batch processing on large datasets, where jobs run on parallel on 1000's of comodity hardwares.
- Its similar to this Unix pipeline:
```c
$ cat /var/log/nginx/access.log | awk '{print $7}' | sort | uniq -c | sort -r -n | head -n 5
```
| | Unix Pipeline | MapReduce |
|---|---|---|
|Run on| 1 Machine | 1000's of machines|
|Writes on |Unix Filesystem|[HDFS]()|

- it spread the work across nodes(Commodity hard-wares) and allows those nodes to process the data in parallel. 
- Results from the initial parallel processing are sent to main nodes where the data is combined to allow for further reductions of the data.
- There is a Single (RresourceManager[YARN], allocates resources on dataNodes) in cluster. 
- Every single dataNode has (NM:nodeManager, which executes and monitors tasks)+(AM:applicationMaster, taking inputs from RM).
- Data analysis uses a two step process: Example: Single word occurance need to be counted from 1 million documents.
  - *a. map:* counts the words in each document        
  - *b. reduce:* aggregates the per-document data into word counts spanning the entire collection.    //This process is carried on all nodes in cluster.


<a name=hdfs></a>
## Hadoop Distributed File System
- HDFS is a distributed filesystem(derived from GFS-google file system). Default block size=64MB. (xfs block size=4kb)
- Data blocks are replicated on multiple nodes. Eg: Block-1 on Node1, Node2. Block2 on Node1, Node3. Hence provides replication in case of failure without data loss. 
- Cluster has single nameNode(manages metadata) and multiple dataNodes communicating using TCP/IP
```c
                         nameNode
                     /TCP        \TCP
            dataNode-1    -TCP   dataNode-2
```
- **Disadvantages of HDFS:**     1. Not fast with other file systems.    2. Cannot be mounted

