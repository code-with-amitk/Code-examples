## Datatypes
- **[Fundamental Datatypes](Fundamental_Datatypes.md):** byte, word, dword, qword, qunitword, double qword, quad quadword
- **[Numerical Datatypes](Numerical_Datatypes.md)** Scalar and packed datatypes
- **Comparison**

|Type|C|C++|Python|
|---|---|---|---|
|void|1|1|16|
|short(signed)|2|2|2|
|int(signed)|4|4|400|
|float|4|4|400|
|double|8|8|not present|
|empty string ""|1|1|49|
|array,vector,list|0,int a[]|0 vector<int> a|64|
|map,dict||48 map<int,int> a|240{}|
|tuple||8 tuple<int,int> a|48()|
|struct,class|0 struct A{}| 1 class A{}| 1056 class A;pass|

**Conclusion**
  -  Python is heavy eater of memory, If you want memory efficient code, Never go for python. Python design goals are radically different than C. C is designed to give control of hardware while python is designed to code rapidly while hiding most (if not all) of the underlying implementation details.
