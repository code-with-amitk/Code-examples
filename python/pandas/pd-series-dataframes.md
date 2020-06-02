## What is pandas?
This library for processing and analyzing real world data. Usages:
- parsing multiple file formats
- converting input data table into a NumPy matrix

## 1-D data (also called series)
- A Series is created through the pd.Series constructor(Takes keyword arguments).
  - data = Specifies the elements of the Series     //1st kwarg
  - dtype (same as numpy arrays)                    //2nd kwarg for manual casting
  
Example Code:  initialize each Series by setting the first argument using a scalar, list, or NumPy array.
```python
s = pd.Series()
print(series,'\n')          #Series([], dtype: float64) 

series = pd.Series(5)
print(series,'\n')          #0    5
                            #dtype: int64 

series = pd.Series([1, 2, 3])
print(series,'\n')            #0    1
                              #1    2
                              #2    3
                              #dtype: int64  

arr = np.array([1, 2])
series = pd.Series(arr, dtype=np.float32)
print(series,'\n')            #0    1.0
                               1    2.0
                               dtype: float32 

```

#### Index of series
- In previous examples, there is a zero-indexed integer to the left of the elements in each Series. This is called **index** of series. Each individual index element is referred to as a **label**.
- Default index = 0
- We can give custom indexes using **index** keyword argument of pd.Series.
- index keyword argument needs to be a list or array with the same length as the data argument for pd.Series

Example code
```python
s = pd.Series([1, 2, 3], index=['a', 'b', 'c'])
print(s,'\n')                                     # a    1
                                                  # b    2
                                                  # c    3
                                                  # dtype: int64
                                                  
# Setting index using Dictionary                                                  
s = pd.Series({'a':1, 'b':2, 'c':3})
print(s,'\n')                                     # a    1
                                                  # b    2
                                                  # c    3
                                                  # dtype: int64                           
```

## 2-D data (also called DataFrame)
- This is tabular data(in form of tables or speardsheets)
- A dataFrame is created through the pd.dataFrame constructor(Takes same arguments as pd.series).
  - Takes additional coloumn keyword argument.

Example
```python
df = pd.DataFrame()
print(df)                       #Empty DataFrame
                                # Columns: []
                                # Index: []

df = pd.DataFrame([5, 6])       
print(df)                       #0
                                #0  5
                                #1  6
                                
df = pd.DataFrame({'c1': [1, 2], 'c2': [3, 4]},               //taking dictionary as argument
                  index=['r1', 'r2'])
print(df)                                   #    c1  c2
                                            #r1   1   3
                                            #r2   2   4
```

### Upcasting happen on coloumns
```python
a = pd.DataFrame([[5, 6], [1.2, 3]])
print(upcast)                               #     0  1
                                            # 0  5.0  6     //coloumn is upcasted
                                            # 1  1.2  3
```

### Appending additonal row through append() function
```python
df = pd.DataFrame([[5, 6], [1.2, 3]])
print(df)                                     #     0  1
                                              # 0  5.0  6
                                              # 1  1.2  3 
r = pd.Series([0, 0], name='r3')

df = df.append(r)
print('{}\n'.format(r))                       #      0  1
                                              # 0   5.0  6
                                              # 1   1.2  3
                                              # r3  0.0  0
```
##### Setting ignore_index=True will change the row labels to integer indexes.
```python
//continuation to above code
df_app = df.append(r, ignore_index=True)
print(df_app)                               #      0  1
                                            # 0  5.0  6 
                                            # 1  1.2  3
                                            # 2  0.0  0
                                            # 3  0.0  0 
```

### Dropping row/coloumn using drop() function
##### Method-1(labels keyword argument): specify the labels of the rows/columns we want to drop
```python
df = pd.DataFrame({'c1': [1, 2], 'c2': [3, 4], 'c3': [5, 6]}, index=['r1', 'r2'])
print(df)                                   #     c1  c2  c3
                                            # r1   1   3   5
                                            # r2   2   4   6
df = df.drop(labels='r1')
print(df)                                   #     c1  c2  c3
                                            # r2   2   4   6
```

##### Method-2(Directly specify row/colomn)
```python
//continuing to above example
df_drop = df.drop(columns='c2')
print('{}\n'.format(df_drop))               #    c1  c3
                                            # r1   1   5
                                            # r2   2   6
```
