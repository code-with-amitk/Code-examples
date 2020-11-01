## Sizes(bytes)/sizeof

|Type|C|C++|Python|
|---|---|---|---|
|void|1|1|16|
|char(signed)|1|1||
|uint8_t(unsigned)|1|1||
|short(signed)|2|2|2|
|uint16_t(unsigned)|2|2|2|
|int(signed)|4|4|400|
|uint32_t(unsigned)|4|4|400|
|long int|8|8||
|uint64_t(unsigned)|8|8||
|long long int|8|8||
|uint128_t(unsigned)|16|16||
|float|4|4|400|
|double|8|8|not present|
|long double|16|16|not present|
|empty string ""|1|1|49|
|array,vector,list|0,int a[]|0 vector<int> a|64|
|map,dict||48 map<int,int> a|240{}|
|tuple||8 tuple<int,int> a|48()|
|struct,class|0 struct A{}| 1 class A{}| 1056 class A;pass|

**Conclusion**
  -  Python is heavy eater of memory, If you want memory efficient code, Never go for python. Python design goals are radically different than C. C is designed to give control of hardware while python is designed to code rapidly while hiding most (if not all) of the underlying implementation details.
