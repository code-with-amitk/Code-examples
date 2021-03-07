## How string is implemented internally?
- `basic_string::_M_dataplus._M_p` this is pointer to actual data.
```c
/usr/include/c++/7.5.0/bits/basic_string.h
class basic_string {
  ...
  struct _Alloc_hider : allocator_type{
    ...
    pointer _M_p;                           // The actual data.
  };
  
  _Alloc_hider  _M_dataplus;
  
};
```
