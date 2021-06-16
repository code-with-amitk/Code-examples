## Compile Time vs Run Time
||Stack(compile time)|Heap(runtime)|
|---|---|---|
|What|All data stored on the stack must have a known, fixed size|Data with an unknown size at compile time stored on the heap|
|Type of data stored|int,float,char,string literal|Which can change at run time. Eg: String|
|Which is Faster|Stack is faster wrt heap because <ul><li>1. For pushing data on stack, place is never required to be searched. Push always happens at top of stack</li></ul> <ul><li>processors are faster if they jump around less in memory</li></ul>|Slower Why? <ul><li>When we ask data at runtime from heap, memory allocator finds big empty spot & returns. This search takes time</li></ul> <ul><li>You have to follow a pointer to get at location where data need to be stored.</li></ul>|
