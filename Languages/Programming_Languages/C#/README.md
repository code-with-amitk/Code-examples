- .Net Framework
  - [Common Language Runtime (CLR) / .Net Runtime](#clr)

### .Net Framework
- All code written in C# will always run within the .NET Framework.

<a name=clr></a>
#### Common Language Runtime (CLR) / .Net Runtime
```c#
source code -> |Compiler| -> IL(Intermidiate Language Code) -> |CLR| -> Platform specific code
                             Managed Code
```
**Advantages/Features of Managed Code**
- _1. Platform Independent:_ IL-1 bought from other machine can be combined with IL-2 to create exe
- _2. Performance Improvement:_ Instead of compiling the entire application in one go (which could lead to a slow start-up time), it compiles portions.
- _3. Language interoperability:_ IL of 2 or more languages can be mixed to create exe. Languages(Visual Basic .net, C#, visual C++ .net
- _4. Common Type System:_ Predefined data types that are available in IL, so that all languages that target the .NET Framework will produce compiled code.
  - All .Net based languages uses 4 bytes for Int32.
- _5. Common Language Specification:_ CLS works with the CTS to ensure language interoperability.
- _[6. Garbage Collection](/Languages/Programming_Languages/Java#f)_
- _7. Code Based Security:_ .Net provides code based security, while Windows provides role based security. code-based security is that it reduces the risks associated with running code of dubious origin(eg internet).
- _8. Application domains:_ Ease overhead involved when running applications that need to be isolated from each other. Windows isolates application domains using processes.
  - Each process has its address space having(4GB of virtual memory)
  - Each process has its own security token,
