"""     creating_tensor.py

TENSOR? Multi-dimensional arrays used to store numbers during computation. 
"""

"""
0-D/Scalar: Only 1 number 
https://docs.scipy.org/doc/numpy/reference/arrays.scalars.html
ndim: Tells dimension/axes of Tensor
"""
import numpy as np
x = np.array(12)
print(x)                # 12
print(x.ndim)           # 0


"""
VECTOR: Stores array of numbers.
TYPES:
    4-D vector: vector having 4 entries
    5-D vector: vector has five entries
Don't confuse 5-D Tensor with 5-D vector
"""
x = np.array([12, 3, 6, 14])   # 4-D vector
print(x)                       # [12  3  6 14] 
print(x.ndim)                  # 1


"""
2-D/MATRIX: Array of Vector 
ndim: Tells dimension/axes of Tensor
- Matrix has two axes (often referred to rows and columns)
"""
x = np.array(
        [
            [5, 78, 2, 34, 0],
            [6, 79, 3, 35, 1],
            [7, 80, 4, 36, 2]
        ]
    )
print(x.ndim)                  #2



"""
3-D TENSOR: Packing 2 or more Matrices.
ndim: Tells dimension/axes of Tensor
"""
x = np.array(
        [
            [
                [1,2,3],
                [4,5,6],
            ],
            [
                [7,8,9],
                [10,11,12],
            ]
       ] 
    )
print(x.ndim)                   #3


"""
4-D TENSOR: Packing 2 or more 3-D tensors.
ndim: Tells dimension/axes of Tensor
"""
x = np.array(
        [
            [
                [
                    [1,2,3],
                    [4,5,6],
                ],
                [
                    [7,8,9],
                    [10,11,12],
                ],
            ],
            [
                [
                    [13,14,15],
                    [16,17,18],
                ],
                [
                    [19,20,21],
                    [22,23,24],
                ]
            ]
       ]
    )
print(x.ndim)                   #4

