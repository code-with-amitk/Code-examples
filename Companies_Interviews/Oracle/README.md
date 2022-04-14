**Oracle Bangalore**
- **March 2022, Principal Engineer**
  - [Round-1. DS => Choose Data Structure](#c)
  - [Round-2. OOD => Parking lot](#pl)
  - [Round-3. DS+OOD+SystemDesign](#r3)

## March 2022, Principal Engineer
<a name=c></a>
### 1. Choose Data Structure
- What DS will you choose to find which service is visited maximum times in last 1 hour.
- You have services s1,s2..sn. All services are accessed using common gateway, you can install your process to find which service is accessed.
- **Answer**
  - Purge timer will fire every second and check services from head of ll. if (current_timestamp > timestamp_on_list) remove
```c
list<timestamp, service>
  2pm   2.30  2.45  3     3.01
  s1    s2    s3    s2    s3

  [2,s1]  ->  [2.30,s2] ->  [2.45,s3] ->  [3,s2]  ->  [3.01,s3]
  /\
  Purge timer
```
<a name=pl></a>
### 2. OOD => Parking lot
- Design a parking lot which can accomodate 2 wheeler, 4 wheeler, truck into parking.
- n 2 wheelers will combine to create 1 4 wheeler. m 4 wheelers will combine to create 1 truck parking.
- Take driveway into consideration when designing parking lot.

### Round-3
#### 1. DS
[Counts Anagrams from Dictionary](/DS_Questions/Questions/Strings/Anagrams_Pangrams/Anagrams/Count_Anagrams_in_Dictionary.md)
#### 2. System Design
**Design Stock Trading System**
- Requirements: 
  - _1._ You can buy n units of particular stock (Eg: google 100)
  - _2._ Preference should be give to user who buys more stocks. (Eg: (user-A stocks=100,company google), (user-B stocks=50,company google))
  - _3._ Give OOD
```c
Objects:
 1. MoneyTransfer
 2. GlobalStock: This keeps avialble stock count globally
             stock   value   available_count
 3. Userbookeeping: This keeps stocks aviable per user inside datacenter.
             stock   value  time_picked   user_name(id)  count
             
      globalStock(stock,count) 
         moneyTransfer
  4. display: Shows stocks to user. Take values from  GlobalStock -> vector<object>
  5. user_microservice: call display's method show(). informs userbooking about stock picked
            pick(stock_name){
                  gbk(count, stock, selfid)
            }
            sell(){
            }
```
#### 3. OOD
- Design a system where original base class is not touched and we need to add new features. Design a window class which initially supports:
  - text window, image window
  - Now we want to add a new window(video window), base class should not change.
