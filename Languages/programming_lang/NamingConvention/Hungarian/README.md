## Hungarian Naming Convention
- This is language independent.
- **[Variable names](http://web.mst.edu/~cpp/common/hungarian.html)**
  - All variable names are composed of following 3 types: 
    - scope
      - m_ class member
      - g_ global
      - s_ static
    - prefixes:
      - p pointer
      - u unsigned
      - s signed
    - base type:
      - ch character
      - sz Null terminated string
      - b byte(1 byte)
      - s short(2 byte)
      - i int(4 byte)
      - l long(4 byte)
      - ll long long(8 byte)
- **Examples `[SPB]`**
  
||Scope|Prefix|Base-Type|Compelete-Name|
|---|---|---|---|---|
|unsigned char variable of class|m_|u|ch|unsinged char m_uchVariable|
|char variable of class|m_||c|char m_cName|
|char pointer||p|c|char `*pcName`|
|local string|||str|string strName|
|Null terminated string|||sz|char szName[]|
