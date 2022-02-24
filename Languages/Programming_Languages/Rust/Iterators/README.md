- Iterator
  - [What](#what)
  - [Why](#why)
- [iter() in for()](#itfor)
- **Methods**
  - [next() method](#next)
  - [sum() method](#sum)
  - Iterator Adopters
    - [collect method](#col)
    - [filter method](#fil)


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
#### next() method
next() method of iterator returns next element and None when reaches end.
```rs
fn main() {
    let v = vec![1, 2];
    let mut a = v.iter();
    println!("{:#?}", a.next());    //Some(1)
    println!("{:#?}", a.next());    //Some(2)
    println!("{:#?}", a.next());    //None
```

<a name=sum></a>
#### sum() method
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

### Iterator Adoptors
These are methods defined on the Iterator trait, which allow you to change iterators into different kinds of iterators. 
- Multiple calls to iterator adaptors are possible to perform complex actions in a readable way.
<a name=col></a>
#### collect() method
collect() method is called on any iteratable item and collects the resulting values into a collection data type.
- **Example-1:** increment all fields of `vector<int>` by 1
```rs
fn main() {
    let v = vec![1,2,3,];
    let v1:Vec<i32> = v.iter().map(|x| x+1).collect();
    for i in v1.iter(){
        println!("{}",i);     //2,3,4
    }
```
- **Example-2:** Collect 1 field from `vector<struct>`
```rs
pub struct test {
    pub tenant: String,
    pub device_uuid: Option<String>,
    pub ip: Option<String>,
}
impl test {
    pub fn new(t: String, d: String, i: String) -> Self {
        Self {
            tenant: t,
            device_uuid: Some(d),
            ip: Some(i),
        }
    }
}
fn main() {

    let v1 = test::new("t1".to_string(), "d1".to_string(), "i1".to_string());
    let v2 = test::new("t2".to_string(), "d2".to_string(), "i2".to_string());
    
    let mut vec_test = vec![v2, v2];
    
    //Iterate thru vector. Read device_uuid and collect all in opt_vec_devices
    let opt_vec_devices : Vec<Option<String>> = vec_test.iter().map(|x| x.device_uuid.clone()).collect();
    
    //Convert vec<Option<String>> to vec<String>
    let mut vec_devices:Vec<String> = Vec::new();
    for i in opt_vec_devices {
        if !i.is_none(){
            vec_devices.push(i.unwrap());
        }
    }
    
    for i in vec_devices {
        println!("{:?}",i);
    }
}
```

<a name=fil></a>
#### filter() method
This adoptor is applied over iterator, takes closure as argument(which takes each item of iterator) and return bool. 
- If the closure returns true, the value is included in the iterator produced by filter, If the closure returns false, the value won’t be included in the resulting iterator.
```rs
struct Test {
    a:i32,
    s:String,
}

//This function takes ownership of a vector. It returns all those vectors which have (a==2).
//filter() adapts the iterator. collect() gathers the values returned by the adapted iterator into a vector which satisfies the condition.
fn fun(v: Vec<Test>) -> Vec<Test> {
    v.into_iter().filter(|s| s.a == 2).collect()
}

fn main() {
    let a = Test{a:1, s:String::from("a")};
    let b = Test{a:2, s:String::from("b")};
    let b = Test{a:2, s:String::from("c")};

    let v1:Vec<Test> = fun(vec![a, b]);
    //fun(v);

    for i in v1.iter(){
        println!("{}",i.s);
    }
}

$ cargo run
b
c
```
