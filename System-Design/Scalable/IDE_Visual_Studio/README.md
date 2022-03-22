**IDE / Visual Studio**
- [1. Requirements](#r)
- [2. BOE](#boe)
- [3. HLD](#hld)

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

<a name=boe></a>
### 2. Back of Envelope Calculations
Storage estimates
QPS(Queries per second)

<a name=hld></a>
### 3. [HLD](https://2021.desosa.nl/projects/vscode/posts/essay2/#fn:1)
#### Plugin based
- Make everything a plug-in/extensions. All extensions run as seperate processes. Breaking tasks down into individual chucks. IDE will support plug-ins:
  - Add a compiler invocation plug-in
  - program output viewer plug-in to see compiler result
  - plug-in for source code parsing
  - syntax colour highlighting plug-in
#### [Layered & Modular design](https://github.com/microsoft/vscode/wiki/Source-Code-Organization) (extended using extensions,plugins)
- **[Layered Architecture](/System-Design/Concepts/Software_Architecture_Patterns):** Code is designed into different layers:
  - _1. Base layer:_ Provides general utilities.
  - _2. Platform layer:_ Have base services in vs code, service injection.
  - _3. Editor layer:_ For plug-in new editors(Eg: Monaco)
  - _4. workbench:_ hosts editors & provides the framework for "viewlets" like the Explorer, Status Bar, or Menu Bar.
  - _5. Code:_ Entry point for desktop app.

<img src=vscode.png width=400 />

5. Database schema
6. Tradeoffs/Bottlenecks & correction
7. Adjusting to changing requirements
