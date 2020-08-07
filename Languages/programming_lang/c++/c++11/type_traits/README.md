## Type_Traits
- **What** 
  - Way to inspect properties & transform properties of template variable. These are resolved at compile time.
- **Why this is good?** 
  - We can improve our code, for particular data types eg: pointers.
- **Example**
```
#include<type_traits>
cout << is_same<int, int32_t>::value;  //1   If T and U are same type return true else false. ::value returns the bool showing result meets desired specification or not?
cout << is_same<int, float>::value;    //0            
```

### Types of type traits
#### 1. Primary types
- Primary data type checks.

#### 2. Composite Types
- Composite data types check.

#### 3. Supported Operations
- Tells if type supports the operation or not?

## 4. miscellaneous_transformation
- List of all miscellaneous type traits
