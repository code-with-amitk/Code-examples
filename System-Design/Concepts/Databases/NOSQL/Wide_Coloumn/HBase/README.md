## Apache HBase
- HBase is modeled after [Google’s BigTable] and runs on top of [Hadoop Distributed File System (HDFS)](/Operating_Systems/Linux/FileSystem/HDFS_Hadoop_Distributed_File_System.md)
- Written in Java.
- **Writes Data only Once**
  - HBase groups data together to store new data in a memory buffer and, once the buffer is full, it dumps the data to the disk.
