- **assert Macros**
  - [assert_eq](#eq)
  - [Others, assert_ne](#o)
- **unwrap**
  - [unwrap()](#u)
  - [unwrap_or()](#uo)
  - [unwrap_or_else()](#uoe)
- [value_of()](/Libraries/Command_Line/Rust/Clap)

## assert Macros
<a name=eq></a>
#### assert_eq!(a,b)
- if (a!=b) assert
```rs
    let mut v = vec![1,2];
    assert_eq!(v, [1,2,3].to_vec());   //Assert
    assert_eq!(v, [1,2].to_vec());     //No Assert
    
    assert_eq!(1,2);                    //Assert
```
<a name=o></a>
#### Others
```rs
       Function          desc                   Expects
-------------------|------------------------|------------
  assert!(a)       | if (a==false) assert   |  true
 assert_ne!(a,b)   | if (a==b) assert       |  not equal
```

## unwrap
[Result <T, E>](/Languages/Programming_Languages/Rust/Data_Types/Builtin_Types)
```c
         | unwrap(self) -> T           |  unwrap_or(self, default) -> T
---------|-----------------------------|-------------------------  
Return   | Succes: Read value          | Success: Read value
         | failure: panic              | Failure: Default value
```
<a name=u></a>
#### pub fn unwrap(self) `->` T
Returns the contained Ok value. This function may panic on error, hence its generally discouraged to use, use unwrap_or, unwrap_or_else, or unwrap_or_default.
```rs
let x: Result<u32, &str> = Err("emergency failure");
x.unwrap(); // panics with `emergency failure`
```

<a name=uo></a>
### pub fn `unwrap_or(self, default: T) -> T`
Returns the contained Ok value or a provided default.
```rs
let defaultVal = 2;
let x: Result<u32, &str> = Ok(9);
assert_eq!(x.unwrap_or(default), 9);
```
