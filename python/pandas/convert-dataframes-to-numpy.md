## Why conversion is required from dataframes to numpy arrays?
-  most machine learning frameworks (e.g. TensorFlow), work directly with NumPy data

### How conversion?
#### get_dummies(): Convert each categorical feature into indicator features for each of its categories. 
```
# predefined non-indicator DataFrame
print('{}\n'.format(df))              //DataFrame df has a single categorical feature called Color

# predefined indicator Dataframe
print('{}\n'.format(indicator_df))

Output:
 color
r1    red
r2   blue
r3  green
r4    red
r5    red
r6   blue

    blue  green  red
r1     0      0    1
r2     1      0    0
r3     0      1    0
r4     0      0    1
r5     0      0    1
r6     1      0    0
```
