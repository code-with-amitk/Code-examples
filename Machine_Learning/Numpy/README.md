- [What](#w)
- [Numpy Array Operations](#o)

<a name=w></a>
## Numpy
- **What?** Python library providing multidimensional numeric arrays. NumPy converts input datasets into usable form.

<a name=o></a>
### Numpy Array Operations
```py
import numpy as np
arr = np.array([[0, 1, 2], [3, 4, 5]], dtype=np.float32)    #Converting python lists TO NumPy arrays

arr = arr.copy()                                            #Copy to another array

arr = np.array([np.inf, 5])      #Infinity=np.inf array of 5

arr = np.linspace(5, 11, num=4)    #NP.LINSPACE(start, end): Create array by specifying the number of elements

flattened = arr.flatten()        #TO flatten the array to 1-D array

transposed = np.transpose(arr)    #Tranpose of 2-D Array
```
- [Operation on numpy array](numpy-arrays.md)
  - upcasting,copying,casting numpy array
  - NaN numpy Array: When we don't want a NumPy array to contain a value at a particular index
  - np.inf: infinity in numpy array
  - np.arange(), np.linspace(): creating range numpy arrays 
  - np.reshape():Reshaping the numpy array, np.flatten():Flatten, np.transpose():Transpose,np.zeros(),np.ones():Creating array filles with 0 & 1

- **Math operations on numpy array**

- [np.random():Generating random number using numpy](numpy-random-numbers.md)
