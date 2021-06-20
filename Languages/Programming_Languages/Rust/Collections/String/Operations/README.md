## Create
  - from(), new()
```rust
    let s1 = String::new();                   //new()
    s1 = "test".to_string();

    let s2 = String::from("Hello");              //from()
```

## Concatenate
  - Using push_str(), push() methods
```rust
    let s2 = String::from("Hello");
    s2.push_str(" World");                       //push_str() appends string.
    s2.push(' k');                               //push() appends 1 character
```
  - Using `+` operator
```rust
    let s1 = String::from("Test");
    let s2 = String::from("Foo");

    let s3 = s1 + &s2;                          //Why reference. Operator + uses add method `fn add(self, s: &str) -> String {..}`
    //println!("{}",s1);                        //Since s1 is moved not copied
```
  - Using format()! function
```rust
    let s1 = String::from("Test");
    let s2 = String::from("Foo");

    let s3 = format!("{} {}",s1,s2);            //Test Foo  
```
