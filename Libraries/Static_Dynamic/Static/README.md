## Static Object/Library
- `*.a(linux)`
- `*.lib(windows)`

### Disadvantages  
- **1. Increased Size of Binary**
  - If Static Library contains 1000 functions, this all source code will become part of application code. if library contains 1000 functions, size of application code becomes huge.
- **2. If changes in static library, application code has to be complied everytime**
  - 3rd Party static library developer done some changes in libtotal.a & publishes on internet, to take those changes we have to download & compile with our exe again.
