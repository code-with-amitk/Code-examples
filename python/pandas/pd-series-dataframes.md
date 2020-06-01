## What is pandas?
This library for processing and analyzing real world data. Usages:
a. parsing multiple file formats
b. converting input data table into a NumPy matrix

## 1-D and 2-D Arrays/Data
### 1-D data (also called series)
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

### 2-D data (also called DataFrame)
- This is tabular data(in form of tables or speardsheets)
- A dataFrame is created through the pd.dataFrame constructor(Takes same arguments as pd.series).
  - Takes additional coloumn keyword argument.
