- [Name Mangling](#nm)


<a name=nm></a>
### Name Mangling
- Compiler changes names of overloaded functions. so that linker can separate same names from each other.
- C++ has no standardized technique for name mangling. So different compiler uses different techniques
- If a variable is in a namespace, the name of the namespace is mangled into the variable name so that the same variable name can exist in more than one namespace.
- **C** Don't have name mangling, bcoz No overloaded functions.
```cpp
    int f(void) {return 0;}     //becomes _f_v.    
    int f(int) {return 1;}      //becomes _f_i

    namespace wikipedia {         
      class article{             
      public:                 
        string format (void);   //_ZN9wikipedia7article6formatEv    
                                //Start with (_Z). Nested name(N). Length(9).
                                //namespace(wikipedia). Length(7).
                                //class(article). Length(6).
                                //function name(format). E(keyword). v(void)                
        bool print_to (std::ostream&);    //_ZN9wikipedia7article8print_toERSo
      }
    } 
```
