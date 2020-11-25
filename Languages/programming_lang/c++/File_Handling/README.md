## File Handling
### Stream? 
- Input/Output in C++ is performed using Sequence of bytes called Streams

### Classes for File Handling in C++

|Class|What|Object|
|---|---|---|
|ifstream (>>)|<ul><li>For reading from file</li></ul>|<ul><li>cin is object of type ifstream</li></ul>|
|ofstream (<<)|<ul><li>For Writing to file</li></ul>|<ul><li>cout is object of type ofstream</li></ul>|
|fstream (<<)|<ul><li>For Reading/Writing to file</li></ul>||

- **fstream,ifstream,ofstream are dervied from ios_base**
```c
ios_base <--  ios   <--   ostream   <--  ofstream
```
