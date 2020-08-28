## Hungarian Naming Convention
- This is language independent.
- **(Variable names)[http://web.mst.edu/~cpp/common/hungarian.html]**
  - All variable names are composed of following 4 types: 
    - scope: m_ for class member, g_ global, s_ static
    - prefixes: p pointer, u unsigned, signed, 
    - base type: ch character, sz Null terminated string, b byte, w word(2 byte), lw long word(4 byte), llw long long word(8 byte)|
  - Examples:
  
||Scope|Prefix|Base-Type|Compelete-Name|
|---|---|---|---|---|
|unsigned char variable of class|m_|u|ch|unsinged char m_uchVariable|
|char variable of class|m_||c|char m_cName|
|char pointer||p|c|char *pcName|
|local string|||str|string strName|
|Null terminated string|||sz|char szName[]|
