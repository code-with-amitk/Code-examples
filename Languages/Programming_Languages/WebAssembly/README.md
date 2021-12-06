- **[Web Assembly](#wa)**
- [Tools](#t)

<a name=wb></a>
## Web Assembly
- We can run C/C++/Java/Python/Go/other languages code in Web browser(inside javascript file) using Web Assembly. WA does not replace JS rather it requires it
- Web Assembly defines binary format that can be loaded in browser and executed, it does not define any language format.
```c
source -> |Complier| -> Web_Assembly_binary -> Javascript -> Web Page
*.cpp                     01010101              *.js          *.html
*rs, *.py
```

<a name=t></a>
### Tools
- **[1. WA Studio](https://webassembly.studio/)** Runs in browser and creates WA binary files from c/c++ code.
- **2. WA binary toolkit:** command line utility to interact with WA code.
- **3. Emcripten:** Converts c/c++ code to asm.js
- **4. Binaryen:** Converts asm.js to WA.
