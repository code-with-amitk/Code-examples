- [1. Get Started](#get)
- [2. Code](#code)

<a name=get></a>
## 1. Install & Get Started.
- Visual Studio Installer install > Desktop development with C++.
- File > New > Project > Windows Desktop Wizard > Next.
- Application Type(exe), empty Project. Ok
- Add a new cpp file.

<a name=code></a>
## 2. Code
- [Traditional Style Windows Application](traditional_Windows_app.md)
- [API, Structures](/Operating_Systems/Windows/API_Structures)
- **Logic**
  - _1._ Program starts at `wWinMain()`. 
  - _2._ Program fills & registers the structure(WNDCLASS) telling about window characteristics, function pointer of window to interact with main program(ie user).
  - _3._ Program creates a overlapped, pop-up, or child window and gets a unique handle of window and shows the window.
  - _4._ After successful window creation, program enters while() loop and remains in while() until user closes/exits the application.
    - _4a._ Main program communicates with Application windows using `WindowProc()` method by passing series of messages.
    - _4b._ `DispatchMessage()` causes Windows to invoke the WindowProc function, once for each message.
```cpp
#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)       //4a
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
        }
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)   //1
{

    WNDCLASS wc = { };                                                              //2
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = L"Sample Window Class";

    RegisterClass(&wc);                                                             //2

    HWND hwnd = CreateWindowEx(                                                     //3
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);                                                  //3

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))                                        //4
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
```
