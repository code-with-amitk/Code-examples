## Dumping struct variables using println
- **Code**
  - *A.* To print debugging information, we need to explicitly add annotation `#[derive(Debug)]` for particular struct.
```rust
#[derive(Debug)]            //A
struct dimen {
    len:u32,
    width:u32
}

fn main() {
    let a = dimen {
        len:10,
        width:20
    };
    println!("{:?}",a);      //1
    
    println!("{:#?}",a);      //2. # is Trait.
}

# main.exe
dimen { len: 10, width: 20 }    //1

dimen {                         //2
    len: 10,
    width: 20,
}
```
