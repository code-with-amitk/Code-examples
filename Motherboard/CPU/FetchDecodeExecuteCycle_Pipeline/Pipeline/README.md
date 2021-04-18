## Pipeline
- **Why?** To improve performance, CPU designers abandoned simple model of fetching, decoding, and executing one instruction at a time. 
- **What?** All modern CPUs have facilities for executing more than 1 instruction at the same time. Example
  - A CPU have separate fetch, decode, and execute units. so while it is executing instruction n, it could also be decoding instruction n + 1 and fetching instruction n + 2. 
```c
Pipeline:
  [Fetch Unit]  =>   [Decode Unit]   =>  [Execute Unit]
```
