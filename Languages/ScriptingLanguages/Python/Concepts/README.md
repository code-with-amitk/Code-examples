- [GIL](#gil)
- [Memory Management](#mm)
- [PEP 8](#pep)
- [Pickling = Serialization / Unpickling](#pu)
- [Scope Resolution](#sr)

<a name=gil></a>
### GIL / Global Interpreter Lock
- This is a mutex used for limiting access to python objects and helps thread synchronization by avoiding deadlocks. 
- GIL achieves [multitasking (and not parallel computing)](/Threads_Processes_IPC/Terms/).

<a name=mm></a>
### Memory Management
- Memory management in Python is done by Python Memory Manager. The memory allocated in private heap space.
- All objects are stored in private heap & inaccessible to programmer.
- Python has an in-built garbage collection to recycle the unused memory for the private heap space.

<a name=pep></a>
### PEP 8 (Python Enhancement Proposal)
- PEP is an official document providing information about new feature coming in python.

<a name=pu></a>
### Pickling = Serialization / Unpickling
- Serializing an object refers to transforming it into a format that can be stored(json), so as to be able to deserialize it, later on, to obtain the original object. Serialization is called Pickling in python(because pickle module is used to do it)
#### Pickling? 
Any object in Python can be serialized into a byte stream and dumped as a file in the memory. **pickle.dump()**
#### Unpickling?
Inverse of pickling. Deserialize the byte stream to recreate the objects stored in the file and loads the object to memory. **pickle.load()**

<a name=sr></a>
### Scope Resolution
- Python modules namely 'math' and 'cmath' have a lot of functions that are common to both of them - log10(), acos(), exp() etc. To resolve this ambiguity, it is necessary to prefix them with their respective module, like math.exp() and cmath.exp().
