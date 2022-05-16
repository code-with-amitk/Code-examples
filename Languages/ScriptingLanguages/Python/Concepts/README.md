- [GIL](#gil)
- [Pickling = Serialization / Unpickling](#pu)

<a name=gil></a>
### GIL / Global Interpreter Lock
- This is a mutex used for limiting access to python objects and helps thread synchronization by avoiding deadlocks. 
- GIL achieves [multitasking (and not parallel computing)](/Threads_Processes_IPC/Terms/).

<a name=pu></a>
### Pickling = Serialization / Unpickling
- Serializing an object refers to transforming it into a format that can be stored(json), so as to be able to deserialize it, later on, to obtain the original object. Serialization is called Pickling in python(because pickle module is used to do it)
#### Pickling? 
Any object in Python can be serialized into a byte stream and dumped as a file in the memory. **pickle.dump()**
#### Unpickling?
Inverse of pickling. Deserialize the byte stream to recreate the objects stored in the file and loads the object to memory. **pickle.load()**
