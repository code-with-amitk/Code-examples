- [Asynchronous](#as)
  - [Asynchronous vs Multithreaded](#vs1)
  - C++
    - [async function](#a1)
  - Rust 
    - [async function](#afun)
    - [block_on()](#bo)
    - [await](#aw)
- [Future](#fut)
  - [C++](#fc)
  - [Rust](#fr)
- [Promise](#p)


<a name=as></a>
## Asynchronous
Async program are [concurrent](/Threads_Processes_IPC/Terms/README.md#con) ie work on many tasks at a time but only using 1 thread, it usually returns a [future](#fut)
```c
main () {
  future = send()          //Does not block
  //execution resumes
}
```
<a name=vs1></a>
#### Asynchronous vs Multithreaded
Asynchronous can be both single and multithreaded

### C++
- Used to create asynchronous task and execute in parallel.
  - *promise(input side)* For passing value from calling to called thread.
  - *future(output side)* For retreving values returned by called thred into main() thread. `auto returned_value = get_future()`

<a name=a1></a>
#### async Function
```cpp
#include <iostream>
#include <thread>
#include <iostream>
#include <future>

void fun(){
    std::cout << "Hello";
}
int main() {
    auto fut = std::async(std::launch::async, fun);
}
$ ./a.out
Hello
```

### Rust
<a name=afun></a>
#### async Function
Function prefixed with async & which will run asynchronously in rust.
```rs
async fn fun() {
    ...
}
```

<a name=bo></a>
#### block_on() 
Block/sleep the caller until async function does not run to completion. block_on() returns [future](/Languages/Programming_Languages/Rust/Triat_Interface).
```rs
$ cat Cargo.toml
[dependencies]
futures = "0.3"

$ cat main.rs
use futures::executor::block_on;
async fn fun1() { print!("fun1"); }
async fn fun2() { print!("fun2"); }
fn main() {
    block_on(fun1());                       //main() blocks until fun1(),fun2() does not compelte
    block_on(fun2());
}
$ main.exe
fun1 fun2
```

<a name=aw></a>
#### await
Inside [async function](#afun) await is used to wait for another async function.
```rs
$ cat main.rs
use futures::executor::block_on;
async fn fun1() { print!("fun1"); }
async fn fun2() { print!("fun2"); }

aync fn async_main() {                  //fun1(),fun2() can independently execute. async_main() can run other tasks independently as well.
    fun1().await;
    //other work
    fun2.await();
}

fn main() {
    block_on(async_main());
}
```
**await vs block_on()** 
```c
                                        |   await          |        block_on()    |
----------------------------------------|------------------|----------------------|
Blocks current thread                   |     no           |          yes         |
wait for future to complete             |     yes          |          yes         |
Other tasks in async function can run?  |     yes          |          no          |
```

<a name=fut></a>
### Future
- This is a value which is not yet ready. (Same as Javascript=promises). 
- if we wait for some time it will be ready, its something compute heavy(Eg: network channel etc).
- async function returns a future object.
<a name=fc></a>
#### C++
```cpp
include <iostream>
#include <future>
#include <thread>
int main() {
    // future from an async()
    std::future<int> f2 = std::async(std::launch::async,
                                []{                 //Creating lambda
                                 return 8;
                                });
    f2.wait();
    std::cout << "Done!\nResults are:" << f2.get() << '\n';
}
$ g++ test.cpp -lpthread
$ ./a.out
Done 8
```

<a name=fr></a>
#### Rust
```rs
//Example, non working code
fn main() {
    let fut_x  = TcpStream::connect("127.0.0.1")
                 .and_then(|c| c.write("got it");       //When connected write this

    let ex: Executor;
    let a = ex.run(fut_x);
}
```

<a name=p></a>
### Promise
<a name=pc></a>
#### C++ (std::promise)
- Remember a [future](#fut) object is returned by the [async function](#as).
- std::future can be stored in std::promise. future can be a value or an exception.
- std::promise object can be used only once.
```cpp
#include <iostream>
#include <future>
#include <thread>
void fun(int a, std::promise<int> pro){
    pro.set_value(a);
}
int main() {
    std::promise<int> pro;
    std::future<int> fut = pro.get_future();
    std::thread t(fun, 9, std::move(pro));
    std::cout <<  fut.get() << "\n";
    t.join();
}
$ g++ test.cpp -lpthread
$ ./a.out
9
```
