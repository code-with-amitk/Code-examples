- Iterator
  - [What](#what)
  - [Why](#why)
- [iter() in for()](#itfor)
- [next() method](#next)
- [sum() method](#sum)


## Iterators
<a name=what></a>
**What**
Iterator is responsible for iterating over elements in sequence, we don’t have to reimplement that logic by ourself.

<a name=why></a>
**Why**
- Languages that don’t have iterators(Eg: C), we need to write this functionality by starting a variable at index 0, using that variable to index into the vector to get a value, and incrementing the variable value in a loop until it reached the total number of items in the vector.
- _Problems with for(i=0;i<5;++i) or while(i<5):_ 
  - Coder can mess up this code, ie increment after 5
  - Everytime incrementing by himself and checking the bound condition.

<a name=itfor></a>
### iter() in for()
```rs
fn main() {
    let mut v : Vec<i32> = vec![1,2,3];
    for a in v.iter() {
        print!("{} ", a);             //1 2 3
    }
    print!("{} ", v[0]);              //1
    print!("{:#?}",v.get(1));         //Some(4,)
    print!("{:#?}",v.get(10));        //None. Does not crash    
}    
```

<a name=next></a>
### [next() method](#next)
next() method of iterator returns next element and None when reaches end.
```rs
fn main() {
    let v = vec![1, 2];
    let mut a = v.iter();
    println!("{:#?}", a.next());    //Some(1)
    println!("{:#?}", a.next());    //Some(2)
    println!("{:#?}", a.next());    //None
```

### [sum() method](#sum)
sum() is consuming adoptor(calling them uses up the iterator). This takes ownership of the iterator and iterates through the items by repeatedly calling next, thus consuming the iterator. So everthing consumed, calling next() will give error.
```rs
fn main() {
    let v = vec![1, 2, 3];
    let a = a.iter();
    let total: i32 = a.sum();
    println!("{}", total);        //6
    println!("{:#?}",a.next());   //Compilation Error
}
```
