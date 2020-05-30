## WHAT is NumPy array?

> Numpy also converts data into usable form.


### 1. CONVERTING PYTHON LIST TO NumPy arrays using np.array()
> Argument: dtype: keyword argument takes in a NumPy type and manually casts the array to the specified type
      
```python
import numpy as np
arr = np.array([[0, 1, 2], [3, 4, 5]], dtype=np.float32)
print(repr(arr))
```


#2. UPCASTING of NumPy array. When array contains mixed types
# The array's type will be upcast to the highest level type. Example:
# if an array input has mixed int and float elements, all the integers will be cast to their floating-point equivalents. 
# If an array is mixed with int, float, and string elements, everything is cast to strings.
import numpy as np
arr = np.array([0, 0.1, 2])
print(repr(arr))


#3. COPYING Numpy Array
a = np.array([0, 1])
b = np.array([9, 8])
c = a                               #c is reference to a. changing c leads to the same change in a
print('Array a: {}'.format(repr(a)))      #Array a: array([0, 1])
c[0] = 5
print('Array a: {}'.format(repr(a)))      #Array a: array([5, 1])

d = b.copy()                        #d is copy of a. changing d does not change the value of b
d[0] = 6
print('Array b: {}'.format(repr(b)))      #Array b: array([9, 8])


#4. CASTING NUMPY ARRAY using astype() function
arr = np.array([0, 1, 2])
print(arr.dtype)                 #int64
arr = arr.astype(np.float32)
print(arr.dtype)                 #float32


#5. NaN NUMPY ARRAY. When we don't want a NumPy array to contain a value at a particular index,
# we can use np.nan to act as a placeholder.
arr = np.array([np.nan, 1, 2])
print(repr(arr))                       #array([nan,  1.,  2.])

arr = np.array([np.nan, 'abc'])
print(repr(arr))                       #array(['nan', 'abc'], dtype='<U32')

# Will result in a ValueError
np.array([np.nan, 1, 2], dtype=np.int32)


#6. INFINITY in NUMPY ARRAY. infinity is represented by np.inf(special value). -ve infinity using -np.inf.
print(np.inf > 1000000)                   #True

arr = np.array([np.inf, 5])
print(repr(arr))                          #array([inf,  5.])

arr = np.array([-np.inf, 1])
print(repr(arr))                          #array([-inf,   1.])

# Will result in an OverflowError
np.array([np.inf, 3], dtype=np.int32)


#7. CREATING RANGE NUMPY ARRAYS using np.arange() function
#Like np.array, np.arange performs upcasting. It also has the dtype keyword argument to manually cast the array.
#If only a single number, n, is passed in as an argument, return an array with all the integers in the range [0, n)
arr = np.arange(5)
print(repr(arr))           #array([0, 1, 2, 3, 4])

arr = np.arange(5.1)
print(repr(arr))           #array([0., 1., 2., 3., 4., 5.])

#For two arguments, m and n, np.arange will return an array with all the integers in the range [m, n).
arr = np.arange(-1, 4)
print(repr(arr))           #array([-1,  0,  1,  2,  3])

#For three arguments, m, n, and s, np.arange will return an array with the integers in the range [m, n) 
#using a step size of s.
arr = np.arange(-1.5, 4, 2)
print(repr(arr))              #array([-1.5,  0.5,  2.5])


#8. NP.LINSPACE(start, end) 
# Create array by specifying the number of elements in the array, 
# rather than the step size
arr = np.linspace(5, 11, num=4)
print(repr(arr))                                   #array([ 5.,  7.,  9., 11.])

arr = np.linspace(5, 11, num=4, endpoint=False)
print(repr(arr))                                   #array([5. , 6.5, 8. , 9.5])

arr = np.linspace(5, 11, num=4, dtype=np.int32)    #dtype keyword argument for manual casting.
print(repr(arr))                                   #array([ 5,  7,  9, 11], dtype=int32)


#9. NP.RESHAPE(array_to_be_reshaped, new_shape)
# This function reshapes the array. Reshaping means changing dimensions of array.
#The new shape must exactly contain all the elements from the input array.
#For example, we could reshape an array with 12 elements to (4, 3), but we can't reshape it to (4, 4).
varr = np.arange(8)
print(repr(arr))                                  #array([0, 1, 2, 3, 4, 5, 6, 7])

reshaped_arr = np.reshape(arr, (2, 4))
print(repr(reshaped_arr))                          #array([[0, 1, 2, 3], [4, 5, 6, 7]])
print('New shape: {}'.format(reshaped_arr.shape))  #New shape: (2, 4)

reshaped_arr = np.reshape(arr, (-1, 2, 2))         #array([[[0, 1], [2, 3]], [[4, 5], [6, 7]]])
print(repr(reshaped_arr))                          #New shape: (2, 2, 2)
print('New shape: {}'.format(reshaped_arr.shape))


#10. FLATTEN() function. TO flatten the array to 1-D array
arr = np.arange(8)
arr = np.reshape(arr, (2, 4))
print(repr(arr))                                      #array([[0, 1, 2, 3],[4, 5, 6, 7]])
print('arr shape: {}'.format(arr.shape))              #arr shape: (2, 4)

flattened = arr.flatten()
print(repr(flattened))                                 #array([0, 1, 2, 3, 4, 5, 6, 7])
print('flattened shape: {}'.format(flattened.shape))  #flattened shape: (8,)


#11. TRANSPOSE() function to transpose the array
arr = np.arange(8)
arr = np.reshape(arr, (4, 2))
print(repr(arr))                            
print('arr shape: {}'.format(arr.shape))
"""
array([[0, 1],
       [2, 3],
       [4, 5],
       [6, 7]])
arr shape: (4, 2)       
"""       

transposed = np.transpose(arr)
print(repr(transposed))
print('transposed shape: {}'.format(transposed.shape))
"""
array([[0, 2, 4, 6],
       [1, 3, 5, 7]])
transposed shape: (2, 4)
"""


#12. NP.ZEROS()   NP.ONES()
# Creating arrays filled with 0s or 1s.
# For example, since binary data is labeled with 0 and 1, we may need to create dummy datasets of strictly one label
arr = np.zeros(4)
print(repr(arr))                    #array([0., 0., 0., 0.])
   
arr = np.ones((2, 3))
print(repr(arr))                    
"""
array([[1., 1., 1.],
       [1., 1., 1.]])
"""

arr = np.ones((2, 3), dtype=np.int32)
print(repr(arr))
"""
Output:
array([[1, 1, 1],
       [1, 1, 1]], dtype=int32)
"""


#13. NPZEROS_LIKE(), NPONCES_LIKE()
# If we want to create an array of 0's or 1's with the same shape as another array, use above functions
arr = np.array([[1, 2], [3, 4]])
print(repr(np.zeros_like(arr)))
"""
OUtput:
array([[0, 0],
       [0, 0]])
"""

arr = np.array([[0., 1.], [1.2, 4.]])
print(repr(np.ones_like(arr)))
print(repr(np.ones_like(arr, dtype=np.int32)))
"""
array([[1., 1.],
       [1., 1.]])
array([[1, 1],
       [1, 1]], dtype=int32)
"""
