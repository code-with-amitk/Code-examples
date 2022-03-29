**Oracle Bangalore**
- **March 2022, Principal Engineer**
  - [1. Choose Data Structure](#c)
  - [2. OOD => Parking lot](#pl)

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
