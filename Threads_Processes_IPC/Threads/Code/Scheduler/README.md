**Scheduler/Load Balancer**
- [Approach-1. Threads pooling queue](#a1)
- [Approach-2. Central scheduler accepts new tasks & assigns to workers threads](#a2)

## Scheduler
Scheduler accepts incoming requests/tasks(Packets or cpu jobs) & assign to worker threads (as qucikly as possible).
### Approaches
<a name=a1></a>
#### 1. Threads pooling queue
n threads are running contantly pooling the queue
- **Disadv**
  - _1._ Processor cycles wasted in pooling.
  - _2._ Congestion at synchronization (since mutexes are used)
  - _3._ Pooling scales poorly when threads increases.
```c
threa1  ---------------------|
                             \/
threa2    ---pooling--->   [Central-queue] <----Task
                              /\
threadn  ---------------------|
```

<a name=a2></a>
#### 2. Central scheduler accepts new tasks & assigns to workers threads
Scheduler can manage number of threads, their priority depeding on number of incoming tasks, type of task or other properties.
```c
thread1  <---------------------|
                               |
thread2  <-----------------   Scheduler <----Task
                              |
threadn  <--------------------|
```
