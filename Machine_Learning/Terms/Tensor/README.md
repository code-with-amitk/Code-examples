- **Tensors**
  - [Types of Tensors](#ty)
    - scalars = 1 element
    - vectors = 1-d array
    - Matrices = 2-d array
    - Tensor = n-d matrix
  - [Tensor Terms](#tt)
    - Data type = dtype
    - Rank/axis = dimension
    - Shape

## Matrix = Tensor
<a name=ty></a>
### Types of Tensors
#### Tensor (n-D matrix)
- Multi-dimensional numpy arrays used to store numbers during computation.
```py
# 3-D Tensor example. Packing 2-D matrices
>> x = np.array([[
                      [5, 78, 2, 34, 0],
                      [6, 79, 3, 35, 1],
                      [7, 80, 4, 36, 2]
                 ],
                 [
                      [5, 78, 2, 34, 0],
                      [6, 79, 3, 35, 1],
                      [7, 80, 4, 36, 2]
                 ],
                 [
                      [5, 78, 2, 34, 0],
                      [6, 79, 3, 35, 1],
                      [7, 80, 4, 36, 2]
                ]])
>>> x.ndim
3
```
#### scalars (0D tensors)
- contains only one number
#### Vectors (1D tensors)
- An array of numbers
```py
 x = np.array([12, 3, 6, 14])          #This vector has five entries and so is called a 5-dimensional vector
```
#### Matrices (2D Tensors)
```py
>> x = np.array([[5, 78, 2, 34, 0],
           [6, 79, 3, 35, 1],
           [7, 80, 4, 36, 2]])
>>> x.ndim
2
```

<a name=tt></a>
## Tensor Terms
### Data types(dtype)
- Type of the data contained in the tensor; for instance, a tensor’s type could be float32, uint8, float64, and so on.
- String tensors don’t exist in Numpy (or in most other libraries), because tensors are preallocated contiguous memory segments, and strings, being variable length.
### Rank/Axis
- Dimension of matrix. For instance, a 3D tensor has three axes, and a matrix has two axes. This is also called the tensor’s ndim in Python libraries such as Numpy.
### Shape
- Tells how many size tensor has along each axis.
-  For instance, the previous matrix example has shape (3, 5), and the 3D tensor example has shape (3, 3, 5).
