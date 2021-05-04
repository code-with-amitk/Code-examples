## How Hash Table is implemented internally
- Files are organized into buckets(Size is power of 2) stored either in RAM or disk or distributed servers.
- Hash function generates the bucket number which stores the key.
- **Example:**
  - Lets consider student data to be stored in hash table.
  - Each student data is stored in seperate file and File pointers are stored in Buckets (Similar to [Inode](/Operating_Systems/Linux/FileSystem/I_Node_IndexNode.md))
  - Hash Function generates bucket number as output with enrollment number(key) as input.
  - Clients maintain views to the global system state.
```html
  | Name | Roll-No | Class | Sub-1 | Sub-2 | Sub-3 | .. | Enrollment No(Unique Key) |
  | Amit |   5     | 10    | Math  | Sci   | Eng   |    | 12345                     | <- File-1
  | Ram  |   35    | 10    | Math  | Sci   | Eng   |    | 23241                     | <- File-2
  
  file1		file2		file3		file4
  0x40		0xac		0x45		0x34		//Files stored at different addresses
  
  |file1 file2 file3 file4|		|...|
  |0x40  0xac  0x45  0x34 |		|...|
  Bucket-1. Size=4			Bucket-2. Size=8

  server1		server2			server3
 bucket-1,2		Bucket-3,4,5		Bucket-6,7,10


Enrollment-Number(Key)  -> hash_function ->  Bucket-3
```
