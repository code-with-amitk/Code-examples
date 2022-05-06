### Problem: Read 3 CSV files and find Total Spending?
```c
File1: Table01.csv
Country, City, Street, HouseNumber, Num_Resident_Age_0, Num_Resident_Age_1,Num_Resident_Age_2, Num_Resident_Age_3

File2: Table02.csv
Age_Range, Spending

File3: Table03.csv
City, L_Weight, W_Weight
```

### Logic
```c
1. Read Table03.csv and store in hashTable
    <std::string,std::pair<boost::any,boost::any>>

2. Read Table02.csv and store in vector<int>

3. Read Table01.csv in vector of boost::any

4. Calculate Spending:
  -> User will input following in 1 line
  no_of_cites no_of_streets city_name
  street1 street2 .. streetn
  houseNo1 HouseNo2 .. HouseNon
```

### Code Run
#### On Linux
```c
****Scope: Mumbai*****
  (1 * 100 + 1 * 200 + 2 * 300) = 900*1.8 = 1620
  (2 * 400) = 800*1.8 =  1440
  1620 + 1440 = 3060

# ./SPENDING
0 0 Mumbai          //0:Streets, 0:Houses
Spending: 3060
************************

*******Scope: Delhi*******
  (0*100 + 0*200 + 0*300 + 2*400) = 800*1.7 = 1360

# ./SPENDING          //0:Streets, 0:Houses
0 0 Delhi
Spending: 1360
**************************

******Scope: Mumbai Street01********
  (1 * 100 + 1 * 200 + 2 * 300) = 900*1.8 = 1620
  (2 * 400) = 800*1.8 =  1440
  1620 + 1440 = 3060

# ./SPENDING
1 0 Mumbai Street01       //1 Street, 0 Houses
Spending: 3060
************************************

******Scope: Mumbai Street01 House34********
  (1 * 100 + 1 * 200 + 2 * 300)  = 900*1.8 = 1620

# ./SPENDING
1 1 Mumbai Street01 34    //1 Street, 1 House
Spending: 1620
*********************************************

******Scope: Mumbai Street01 House34 House54********
  (1 * 100 + 1 * 200 + 2 * 300)  = 900*1.8 = 1620
  (2 * 400) = 800*1.8 =  1440
  1620 + 1440 = 3060

# ./SPENDING
1 1 Mumbai Street01 34 54 //1 Street, 2 Houses
Spending: 3060
*********************************************


******Scope: London Street01 House1 //Does not exist********
# ./SPENDING
1 1 London Street01 1   //Invalid Street, Invalid House
Spending: 0
*********************************************
```
#### On Windows
```c
****Scope: Mumbai*****
  (1 * 100 + 1 * 200 + 2 * 300) = 900*2 = 1800
  (2 * 400) = 800*2 =  1600
  1800 + 1600 = 3400

# ./SPENDING
0 0 Mumbai          //0:Streets, 0:Houses
Spending: 3400
************************

******Scope: Mumbai Street01 House34********
  (1 * 100 + 1 * 200 + 2 * 300)  = 900*2= 1800

# ./SPENDING
1 1 Mumbai Street01 34    //1 Street, 1 House
Spending: 1800
*********************************************
```
