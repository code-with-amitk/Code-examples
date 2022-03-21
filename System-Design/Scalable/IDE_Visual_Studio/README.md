**IDE / Visual Studio**
- [Requirements](#r)

## IDE
<a name=r></a>
### 1. Requirements
#### 1a. Functional(Basic functionality, should work)
- _1._ Edit source code files.
- _2._ Run the compiler
- _3._ Show compilation results.
#### 1b. Non-functional(defines quality)
- _1._ Syntax colour highlighting.
- _2._ Help and documentation.
- _3._ A debugger (very hard).
- _4._ Support for plug-ins.
#### 1c. Extended:
```c
Scalable, Secure, SOA
Logging, Load, Latency
Cache(Invalidation, negative cache)
Available, Accurate, Analyze, Authenticate
Reliable, Redundant(Using DB)
Fast
```

### 2. Back of Envelope Calculations
Storage estimates
QPS(Queries per second)

### 3. HLD
- Make everything a plug-in. Breaking tasks down into individual chucks. IDE will support plug-ins:
  - Add a compiler invocation plug-in
  - program output viewer plug-in to see compiler result
  - plug-in for source code parsing
  - syntax colour highlighting plug-in

5. Database schema
6. Tradeoffs/Bottlenecks & correction
7. Adjusting to changing requirements
