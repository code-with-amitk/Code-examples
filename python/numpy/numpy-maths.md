One of the main purposes of NumPy is to perform multi-dimensional arithmetic

#### 1. Add, Subtract, double, Half, Square, Square Root numpy Array values
```
import numpy as np
arr = np.array([[1, 2], [3, 4]])
print(repr(arr + 1))                  # Add 1 to element values
print(repr(arr - 1.2))                # Subtract 1.2 from element values
print(repr(arr * 2))                  # Double element values
print(repr(arr / 2))                  # Halve element values
print(repr(arr // 2))                 # Integer division (half)
print(repr(arr**2))                   # Square element values
print(repr(arr**0.5))                 # Square root element values
"""
Output:
array([[2, 3],
       [4, 5]])
array([[-0.2,  0.8],
       [ 1.8,  2.8]])
array([[2, 4],
       [6, 8]])
array([[0.5, 1. ],
       [1.5, 2. ]])
array([[0, 1],
       [1, 2]])
array([[ 1,  4],
       [ 9, 16]])
array([[1.        , 1.41421356],
       [1.73205081, 2.        ]])
"""
```

#### 2. Converting Fahrenheit to Celsius in NumPy.
```
def fun(temps):
  return (5/9)*(temps-32)

fahrenheits = np.array([32, -4, 14, -40])
celsius = f2c(fahrenheits)
print('Celsius: {}'.format(repr(celsius)))        #Celsius: array([  0., -20., -10., -40.])
```

#### 3. NON-LINEAR FUNCTIONS: EXPONENTIAL, LOGRITHMIC
##### 3.1 Exponential
```
arr = np.array([[1, 2], [3, 4]])
print(repr(np.exp(arr)))            # Raised to power of e
print(repr(np.exp2(arr)))           # Raised to power of 2

Outputs
array([[ 2.71828183,  7.3890561 ], [20.08553692, 54.59815003]])
array([[ 2.,  4.], [ 8., 16.]])
```
##### 3.2 Logrithmic
```
arr2 = np.array([[1, 10], [np.e, np.pi]])
print(repr(np.log(arr2)))               # Natural logarithm
print(repr(np.log10(arr2)))             # Base 10 logarithm

Outputs:
array([[0.        , 2.30258509], [1.        , 1.14472989]])
array([[0.        , 1.        ], [0.43429448, 0.49714987]])
```

#### 4. np.power() Regular power operation
```
arr = np.array([[1, 2], [3, 4]])          
print(repr(np.power(3, arr)))                    # Raise 3 to power of each number in arr

arr2 = np.array([[10.2, 4], [3, 5]])
print(repr(np.power(arr2, arr)))                 # Raise arr2 to power of each number in arr

Outputs:
array([[ 3,  9],[27, 81]])
array([[ 10.2,  16. ],[ 27. , 625. ]])
```    


#### 5. np.matmul() to find matrix product
```
arr1 = np.array([1, 2, 3])
arr2 = np.array([-3, 0, 10])
print(np.matmul(arr1, arr2))                                   #27

arr3 = np.array([[1, 2], [3, 4], [5, 6]])
arr4 = np.array([[-1, 0, 1], [3, 2, -4]])
print(repr(np.matmul(arr3, arr4)))                 #array([[  5,   4,  -7],[  9,   8, -13],[ 13,  12, -19]])
print(repr(np.matmul(arr4, arr3)))                 #array([[  4,   4],[-11, -10]])
# This will result in ValueError
print(repr(np.matmul(arr3, arr3)))
```
