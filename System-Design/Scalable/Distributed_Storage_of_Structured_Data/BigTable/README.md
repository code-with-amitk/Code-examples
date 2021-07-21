- [What is BigTable](#what)
- [Data Model](#datamodel)
  - [1. Row Range = Tablets](#rr)
  - [2. How read operation is faster](#faster)
  - [3. Colomn Keys = Colomn Families](#family)

<a name=what></a>
## BigTable
- This is distributed storage system that scales to large size(Petabytes) and distributed over 1000's of comodity servers.
- if any of our datastructure(eg: stack,queue etc) contains millions of entries, those should be stored here.
- Projects storing data in BigTable: web indexing, Google Earth, and Google Finance.

<a name=datamodel></a>
## Data Model
- BigTable stores data lexicographically in Multidimensinal sorted Map`<Key,value>`(ie [map`<key,value>`](/Languages/Programming_Languages/c++/Standard_Template_Library/) which stores data in RBT, it not Hash Table, because HTs are not sorted). This is Google's Implementation of [Distributed Hash Table](/System-Design/Scalable)
```c
  row key(string(64kb)) + coloumn key(64kb) + timestamp(int64) -> {Hash_Function} -> Key 
  value = Array of bytes.

Example: Storing webpage

          col0 = Content            col1=Anchor  col2=Anchor
 0 | abc_t1 - def_t2 - hij_t3    |  cnn.com    | test.com   |
 
 [0][0] contains page contents at different timestamps
 [0][1] contains any anchors that references the page. websites
 [0][2] same as col1
```

<a name=rr></a>
### 1. Row Range = Tablets
- n rows are grouped together to form a **tablet**, which is the unit of distribution and load balancing.

<a name=faster></a>
### 2. How read operation is faster
- For example, in Webtable, pages in the same domain are grouped together into contiguous rows by reversing the hostname components of the URLs.
- Eg: store `maps.google.com/index.html` under the key `com.google.maps/index.html`. Storing pages from the same domain near each other makes some host and domain analyses more efficient.

