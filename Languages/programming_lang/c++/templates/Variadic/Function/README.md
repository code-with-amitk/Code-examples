### Variadic Function template
- Function template taking variable no of arguments. Parameter pack may appear at any place.
- **How it works internally**
  - Varidic templates are written as recursive code, generic case which recurses and base case.
  - There's no actual recursion involved, all we have is a sequence of function calls pre-generated at compile-time
  - If you are thiking lot of functions and it can be huge size even its not the case because modern compilers are aggressively inlining code, it's likely to end up being compiled to machine code that has absolutely no function calls.
- **compared to va_ macros in C**
  - C-style variadic arguments have to be resolved at runtime, c++ variadic templates being resolved at compile time is huge speed win.
- **Variadic Template Functions are type safe**
  - printf is not type safe. if you are double to `%s`, runtime behviour is undefined, but since in VT everything is resolved at compile time runtime nightmares are avoided.
