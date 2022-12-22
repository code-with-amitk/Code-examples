**BTreeMap**
- [Insert(key,value), len(), iterate over all element, delete](#c)
- Examples
  - [1. Insert `<key,value>` into BTreeMap](#ex1)


<a name=btm></a>
### [BTreeMap <key, value>](https://doc.rust-lang.org/std/collections/struct.BTreeMap.html)
- Map implemented using [BTree](/DS_Questions/Data_Structures/Trees/SelfBalancedBST/README.md#bt), suitable for storage of data in Databases, since Databases uses BTree internally.
- Has unique keys
```c
Complexity       Insert      Search    Delete
Map              O(1)         O(1)      O(1)
BS Tree,BTree    O(logn)     O(logn)   O(logn)
```

### Examples
<a name=ex1></a>
#### 1. Insert `<key,value>` into BTreeMap
```rs
use std::collections::BTreeMap;
#[derive(Debug, Clone)]
pub struct DeviceInfo {
    client_id: String,
    client_secret: String,
    timestamp: String,
}
impl DeviceInfo {
    pub fn create_device(i: String, s: String, t: String) -> Self {
        Self {
            client_id: i,
            client_secret: s,
            timestamp: t,
        }
    }
}
fn main() {
    let mut btm = BTreeMap::new();

    let d = DeviceInfo::create_device(
        "id1".to_string(),
        "secret1".to_string(),
        "time1".to_string(),
    );
    btm.insert("uuid1", d);
    btm.insert("uuid2", DeviceInfo::create_device(
        "id2".to_string(),
        "secret2".to_string(),
        "time2".to_string(),
    ));

    btm.insert("uuid2", DeviceInfo::create_device(          //This will not be inserted
        "id2".to_string(),
        "secret2".to_string(),
        "time2".to_string(),
    ));

    println!("{}",btm.len());                   //2

    for (key, val) in &btm {                          //Iterate over all elements in btm
        println!("{:?}, {:?}", key, val);
    }
    btm.remove("uuid1");
    println!("{}",btm.len());                   //1
}
```
