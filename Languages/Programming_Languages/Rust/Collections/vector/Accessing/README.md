## Accessing vector elements
```rust
fn main() {
    let mut v:Vec<i32> = vec![1,2,3];

    for a in v.iter() {
        print!("{} ", a);             //1 2 3
    }
    
    print!("{} ", v[0]);              //1
    //print!("{} ", v[10]);           //Seg Fault on runtime. Since Collections are stored on heap

    print!("{:#?}",v.get(1));         //Some(4,)

    print!("{:#?}",v.get(10));        //None. Does not crash
```
