- .Net Framework

### .Net Framework
- All code written in C# will always run within the .NET Framework.

#### Common Language Runtime (CLR) / .Net Runtime
```c#
source code -> |Compiler| -> IL(Intermidiate Language Code) -> |CLR| -> Platform specific code
                             Managed Code
```
**Advantages/Features of Managed Code**
- _1. Platform Independent:_ IL-1 bought from other machine can be combined with IL-2 to create exe
- _2. Performance Improvement:_ Instead of compiling the entire application in one go (which could lead to a slow start-up time), it compiles portions.
- _3. Language interoperability:_ IL of 2 or more languages can be mixed to create exe. Languages(Visual Basic .net, C#, visual C++ .net
