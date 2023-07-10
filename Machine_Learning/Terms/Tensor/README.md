- **Tensors**
  - [Types of Tensors](#ty)
  - [Tensor Terms](#tt)
    - Rank/axis/Dimension/ndim = dimension
    - Shape

## Tensor = n-D Matrix
- This is matrix(as in maths).
- Multi-dimensional numpy arrays used to store numbers during computation.

## Types of Tensors
| Dimension/Rank/Axis/Ndim | Name | Representation | Examples | Shape(Rows,cols) | Processed By (Keras) |
|---|---|---|---|---|---|
| 0 | Scalar | `[0]` | | (0) | |
| 1 | vector | `[1,2,3,4]` | | (4) | |
| 2 | Matrix / 2D Tensor | {{1,2,3},{4,5,6}} | Samples | (2,3) | Dense Class/Layer |
| 3 | 3D Tensor | {{{1,2,3},{4,5,6}},{{1,2,3},{4,5,6}}} | Timestamped data | (2,2,3) | Recurrent layers(eg: LSTM layer) |
| 4 | 4D Tensor | 3D tensors packed together | | 2D convolution layers (Conv2D)|

```py
/////////// 2-D Tensor //////////////
Shape: (2,3)
Dimension/Rank/Axis/Ndim: 2
        | 1,2,3 |
        | 4,5,6 |

/////////// 3-D Tensor example. Packing 2-D matrices //////////////
Shape: (3,3,5)
Dimension/Rank/Axis/Ndim: 3

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
```

<a name=tt></a>
## Tensor Terms
### Data types(dtype)
- Type of the data contained in the tensor; for instance, a tensor’s type could be float32, uint8, float64, and so on.
- String tensors don’t exist in Numpy (or in most other libraries), because tensors are preallocated contiguous memory segments, and strings, being variable length.
### Rank/Axis/Dimension/ndim
- Dimension of matrix. For instance, a 3D tensor has three axes, and a matrix has two axes. This is also called the tensor’s ndim in Python libraries such as Numpy.
### Shape
- Tells how many size tensor has along each axis.
-  For instance, the previous matrix example has shape (3, 5), and the 3D tensor example has shape (3, 3, 5).
