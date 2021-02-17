## Move Ctr
- **What**
  - same named function of class A
  - Takes non-const R-value reference as parameter.
  - Internally implemented as:
    - For union-type(https://en.cppreference.com/w/cpp/language/union) as std::memmove()
```c    
        void* memmove( void* dest, const void* src, std::size_t count );
```        
    - For non-union type(eg: class,struct):  Does full member-wise move of the object's members.
        
- **WHEN MOVE CTR IS CALLED?** object is initialized (by direct-initialization or copy-initialization) from rvalue

- **WHEN MOVE CTR IS NEVER CALLED?** When the initializer is a prvalue. see copy elision.  

- **THINGS TO CONSIDER?**  After move original object can be empty, But c++ standards says this should not be relied upon.
