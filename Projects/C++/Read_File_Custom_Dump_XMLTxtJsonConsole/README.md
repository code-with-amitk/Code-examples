### Question
- input.txt File contains smileys { :-] :( :] } and some text
- Dump on console | xml | json | txt file
  - Start positions of smileys
  - Top 10 words

### Solution
- Uses CMake Build, CTest, Boost(program_options, Tokenizer, PropertyTree, FileSystem), catching exceptions

### Buildme
```
1. Go to code root directory
$ pwd
ParseFile_DumpInJsonXML_boost

2. Create Build directory, cmake and make the executable.
$ mkdir Build;
$ cd Build;
Build$ cmake ..
Build$ make

3. Run executable and dump output
Build$ ./Driver/Driver
Allowed options:
  --help                produce help message
  -d [ --display ] arg  console | file | xml | json

Build$ cp ../input.txt .
Build$ ./Driver/Driver -d file xml json console

4. Running CTests
Build$ pwd
CTEST/Build

Build$ cp input.txt Tests/
Build$ make test
```
