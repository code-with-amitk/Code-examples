- assert Macros
  - [assert_eq](#eq)


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
