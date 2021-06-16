## Data Segment
- Stores Global, Static. 

### Parts of Data Segment
- **A. INITIALIZED DS:** initialized by Coder.  Again its divided into 2 parts:
  - _A1. RO(READ ONLY):_ Global constants are stored here. Eg: 
```c
const char *a = "test"
```
  - _A2. RW(READ WRITE):_ Stores Initialized globals, extern variables, local static.
```c
Initialized Globals:            
char s[] = "test";        
int a = 1;        
static int b = 1;

extern int a;     //Extern variable

static int a;     //Local static
```
- **B. UNINITIALIZED DS/BSS(Block Started by Symbol):** Stores uninitialized global and static. Data is Initialized to 0(by kernel) before code start executing.
```c
 int a;        
 static int b
```
