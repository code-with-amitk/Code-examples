## Hadoop Distributed File System
- Hadoop stores data in HDFS(derived from GFS-google file system). Default block size=64MB. (xfs block size=4kb)
- Blocks are replicated on multiple nodes. 
- Eg: Block-1 on Node1, Node2. Block2 on Node1, Node3. Hence provides replication in case of failure without data loss. 
- Cluster has single nameNode(manages metadata) and multiple dataNodes communicating using TCP/IP
```html
                         nameNode
                     /TCP        \TCP
            dataNode-1    -TCP   dataNode-2
```
- **Disadvantages of HDFS:**     1. Not fast with other file systems.    2. Cannot be mounted
- **Does COMPUTATION USING MAPREDUCE**
  - **MapReduce**
    - Designed to process large datasets by running tasks in parallel. 
    - it spread the work across nodes(Commodity hard-wares) and allows those nodes to process the data in parallel. 
    - Results from the initial parallel processing are sent to main nodes where the data is combined to allow for further reductions of the data.
    - There is a Single (RresourceManager[YARN], allocates resources on dataNodes) in cluster. 
    - Every single dataNode has (NM:nodeManager, which executes and monitors tasks)+(AM:applicationMaster, taking inputs from RM).
  - Data analysis uses a two step process: Example: Single word occurance need to be counted from 1 million documents.
    - *a. map:* counts the words in each document        
    - *b. reduce:* aggregates the per-document data into word counts spanning the entire collection.    //This process is carried on all nodes in cluster.
