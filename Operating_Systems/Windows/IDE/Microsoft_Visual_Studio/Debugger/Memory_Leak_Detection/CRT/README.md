**CRT**
- [Memory Leak in DLL](#mdll)

## CRT (C Runtime Library)

<a name=mdll></a>
### Memory Leak in DLL
- [How to create dll and use in application](https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170)
- [Find memory leaks with the CRT library](https://learn.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2022)
#### 1. Introduce Memory Leak in DLL
```cpp
1. Create test.h, test.cpp, without this dll will not be detected
///////////test.h////////////
#pragma once

#ifdef TEST_EXPORTS
#define TEST_API __declspec(dllexport)
#else
#define TEST_API __declspec(dllimport)
#endif
extern "C" TEST_API void test();          //2. Write a test function which has leak

///////////test.cpp//////////////
#include "pch.h"
#include "test.h"
void test() {
    int* a;
    a = new int;                          //3. Introduce a leak in test function
    //a = DBG_NEW int[100];
}

///////////////pch.h//////////////////
#ifndef PCH_H
#define PCH_H
#include "framework.h"

#define _CRTDBG_MAP_ALLOC                     //4. Include headers for leak detection
#include <stdlib.h>
#include <crtdbg.h>
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )     //5. override new operator to print line,file numbers

#endif //PCH_H

/////////////dllmain.cpp//////////////////
// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);   //6. Place this at start of dll
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    _CrtDumpMemoryLeaks();                                        //7. Place this before end of dll
    return TRUE;
}
```
#### 2. Call function provided by dll from application
```c
#include "test.h"
int main() {
    test();
}
```
#### 3. Run Application using F5, And see output window
```c
Detected memory leaks!
Dumping objects ->
C:\Users\amit\test.cpp(6) : {93} normal block at 0x00862DA0, 4 bytes long.
 Data: <    > CD CD CD CD 
```
