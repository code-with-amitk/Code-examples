- [Why Threads](#w)
- [When single threaded is better than Multi-Threaded](#w2)

<a name=w></a>
### Why Threads
- _1._ To run Tasks in parallel & parallelly tasks are completed faster wrt sequential. [Thread usecases](..)
```c
//Very Imp Example to understand (Tanenbaum). Do not Delete
Example-1: Suppose multiprogrammed system has degree of 6 (i.e 6 programs in memory at the same time).
           Assume that each process spends 40% of its time in I/O wait. What is CPU utilization?     
Ans: For 1 process. if Total time=1min, 0.4 min is IO Wait.
     For 6 processes. .04^6 is IO Wait.
     1 - 0.4^6 = 1 - 0.004096 = 0.995904 CPU Utilization

Example-2: Suppose there are 2 jobs(j1,j2), each needing (20 minutes of CPU time), 50% of IO Wait time starts simultaneously.
           How long will it take to complete if they run sequentially? How long if they run parallel.
Ans:
A. Sequential: 80 min.  | j1 IO Wait(20 min) | j1 CPU Time(20 min) | j2 IO Wait(20 min) | j2 CPU Time(20 min) |.
  CPU Utilization = 1 - 0.5^2  (Each job uses CPU for 0.5 times (20min IO, 20min CPU)). = 0.375.
  Each job gets CPU for 0.375 minutes from 1 minute (this includes IO wait time as well).
B. Parallel: 53.33 min (Actual)
 0.375  --> 1		           //0.375 CPU got in 1 min
 20     --> 20/0.375 = 53.33       //For getting 20 min CPU.
     60 min (Theoritical)
Once j1 goes to IO Wait, j2 also starts executing & enters IO wait.     
     | j1 IO Wait(20 min) | j1 CPU Time(20 min) |
     | j2 IO Wait(20 min) | ------------------- | j2 CPU Time(20 min) |
     
```

<a name=w2></a>
### When single threaded is better than Multi-Threaded
- Consider web-server serving telephone directory assistance for an area with (1 million = 10<sup>6</sup>) people only.
- If each record(name, telephone number) is 64 characters, the entire database takes (64x10<sup>6</sup>bytes = 64MB) 
- 64MB can easily be kept in the server’s memory to provide fast lookup. Multithreaded will be an overhead.
