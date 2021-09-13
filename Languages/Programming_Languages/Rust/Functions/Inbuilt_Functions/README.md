- assert Macros
  - [assert_eq](#eq)
- [unwrap()](#u)


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

#### Others
```rs
       Function          desc                   Expects
-------------------|------------------------|------------
  assert!(a)       | if (a==false) assert   |  true
 assert_ne!(a,b)   | if (a==b) assert       |  not equal
```

<a name=u></a>
### unwrap
When an operation may return T or fail, value if type `Option<T>`, unwrap() will provide embedded T if there is one. If not T but an E or None then it will panic.
