- [Question](#q)
- [Design](#d)
- [Code](#c)

<a name=q></a>
### Question
- There is huge floating point array. Size=m
- This is stored on n disks. m/n per disk.
- Calculate median.
- Consider communication overhead while calculating median.

<a name=d></a>
### Design
```c++
node-1    node-2    node-3    ...   node-n
Thread-1  th-2      th-3            th-n
median-1  md-2      md-3            md-n
    |       |         |             |
    |      \/        \/             |
    ------> name-node <--------------
              main(overall median)
```
