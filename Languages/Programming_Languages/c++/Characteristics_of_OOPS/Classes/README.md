## Class 
- Data structure for holding data members & member functions/Methods/Operations together. 
- same as int, float. Member functions of class are allocated only once at Code segment. Each object has separate memory allocated.

### SIZEOF(OBJECT)
```c++
    class t {};            //sizeof(t) -> 1
    class t{                //sizeof(t) -> 1.     //Why size=1? To access the functions of this class. Object must have address.
    public:
        fun(){ int a;   cout<<"Hello"; }
    };
    struct testP{};    //sizeof() -> 0    Why? No reason. This is kept language standard.
    class { int; };    //sizeof() -> 4
    class { int;  char; };    //sizeof() - 8
    class { int; char; static int; };    //sizeof() -> 8    Static are not part of Object
    class { int;    public: virtual int f();    };    //8(a,vptr)
```
### ACCESS SPECIFIERS/ACCESS MODIFIERS
- **PUBLIC:**
  - Members of base class can be accessed by:    
    - *a.* Function of base class    
    - *b.* Function of derived class    
    - *c.* Members which are outside base & derived class
- **PRIVATE:**    
  - Members of base class can be accessed by:    
    - *a.* Function of that class only.
- **PROTECTED:**    
  - Variables, Methods, Constructors with protected scope can be accessed in sub-class of base only
