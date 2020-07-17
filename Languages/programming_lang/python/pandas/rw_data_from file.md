## Pandas can read data from
  - CSV, Excel, SQL, JSON or HTML. complete list [here](https://pandas.pydata.org/pandas-docs/stable/user_guide/io.html)
  
### pd.read_csv(): Reading from csv file
  - read_csv() returns DataFrame with integer indexes as row labels, and each comma-separated column name as the column labels
  - ***index_col*** Now use this coloumn as row label
```
df = pd.read_csv('data.csv')                #Let data.csv contains baseball data
print(df)                                             #   HR       name     pos
                                                          0  17  joe smith  2B
                                                          1  28  alan west   C
                                                          2  19   john doe   P

df = pd.read_csv('data.csv', index_col=0)
print(df)                                           # HR               
                                                      17  joe smith  2B
                                                      28  alan west   C
                                                      19   john doe   P

df = pd.read_csv('data.csv', index_col=1)
print(df)
```

### pd.read_excel(): Reading xlxs spreadsheets
  - DataFrame from pd.read_excel contains the first sheet of the Excel workbook.  
  - When ***sheet_name*** keyword argument is specified, we can obtain a specific spreadsheet.
