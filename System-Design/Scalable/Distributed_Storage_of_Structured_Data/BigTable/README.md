**BigTable**
- [Data Model](#datamodel)
  - [1. Row Range = Tablets](#rr)
  - [2. How read operation is faster](#faster)
  - [3. Colomn Keys = Colomn Families](#family)

## BigTable
- Any DS(stack,queue etc) when gets big is stored on BT. Projects storing data in BigTable: web indexing, Google Earth, and Google Finance.
- BT can scale to size(Petabytes) and distributed over 1000's of comodity servers.

<a name=datamodel></a>
## Data Model
- BT stores data lexicographically in [Multidimensinal map`<key, map<key, value>>`](/Languages/Programming_Languages/c++/Standard_Template_Library) ie RBT.
```c
  key <= {Hash Function} <= row key(string(64kb)) + coloumn key(64kb) + timestamp(int64)
  value = Array of bytes.

Example: Storing webpages
  Row key = url(abc.com)
  coloumn key = any 1 aspect of of web page
  timestamp = time when page is fetched
  value = contents of webpage
  
          col0 = Content            col1=Anchor  col2=Anchor
 0 | abc_t1 - def_t2 - hij_t3    |  cnn.com    | test.com   |
 
 [0][0] contains page contents at different timestamps
 [0][1] contains any anchors that references the page. websites
 [0][2] same as col1
```

<a name=rr></a>
### 1. Row Range = Tablets. 
1 tablet is n rows grouped together.

<a name=faster></a>
### 2. How read operation is faster
- For example, in Webtable, pages in the same domain are grouped together into contiguous rows by reversing the hostname components of the URLs.
- Eg: store `maps.google.com/index.html` under the key `com.google.maps/index.html`. Storing pages from the same domain near each other makes some host and domain analyses more efficient.

