**Robot Restaurant**
- **Design**
  - [Data structures](#d)
  - [OOD](#o)
- Code

## Robot Restaurant
OOD a robot restaurant, the waiter inside is a robot. The main three requirements are to get the customer's order, send the order to the kitchen, and get the prepared dishes from the kitchen back to the table.

## Design
<a name=d></a>
### Data Structures
- Robot gets order from Tables/customers it stores information which order belongs to which table and sends order to kitchen.
```c
  Table-1                                 |-----> Kitchen-1
          <--order-->   Robot   <-order---|
  Table-n                                 |-----> Kitchen-n
```
- How Robot stores table order information?
  - Whenever a new order comes it finds key=orderName and pushes Table pointer to end of value vector.
  - When kitchen prepares the order and sends to robot, robot does pop_front() so that 1st recieved order is served 1st
```c
unordered_map <string=order, vector<string>={Table-1, Table-2..}
```
- How resturant to robot mapping is maintained?
  - We can create a `vector<unordered_set<string>>` which stores food those can be prepared by kitchens.
  - Robot will have a cache which stores most frequently ordered food items.
```c
      | <unodered_set=pasta,fries,egg> | <unordered_set=fish,chicken..> |
index       0 = kitchen-0                   1 = kitchen-1
```

<a name=o></a>
### OOD
```c
  Customer  <-observer dp-> Robot
```
