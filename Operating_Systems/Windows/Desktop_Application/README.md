- [1. Install & Get Started](#get)
- [2. Create and show blank Window](#create)
- [3. Painting the Window](#paint)
- [4. Closing the Window](#close)

<a name=get></a>
## 1. Install & Get Started.
- Visual Studio Installer install > Desktop development with C++.
- File > New > Project > Windows Desktop Wizard > Next.
- Application Type(exe), empty Project. Ok
- Add a new cpp file.

<a name=create></a>
## 2. Create and show blank Window
- [Traditional Style Windows Application](traditional_Windows_app.md)
- [API, Structures](/Operating_Systems/Windows/API_Structures)
- **Logic**
  - _1._ Program starts at `wWinMain()`. 
  - _2._ Program fills & registers the structure(WNDCLASS) telling about window characteristics, function pointer of window to interact with main program(ie user).
  - _3._ Program creates a overlapped, pop-up, or child window and gets a unique handle of window and shows the window.
  - _4._ After successful window creation, program enters while() loop and remains in while() until user closes/exits the application.
    - _4a._ Main program communicates with Application windows using [WindowProc()](/Operating_Systems/Windows/API_Structures) method by passing series of messages.
    - _4b._ `DispatchMessage()` causes Windows to invoke the WindowProc function, once for each message.
  - _5._ See Section "Paiting the Window"
  - _6._ See Section "Closing the Window"
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
            // All painting occurs here, between BeginPaint and EndPaint.
            HDC hdc = BeginPaint(hwnd, &ps);                                    //5a
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));             //5b
            EndPaint(hwnd, &ps);                                               //5c
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
        L"Sample Window Class",                     // Window class
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
        DispatchMessage(&msg);                                                  //6a
    }

    return 0;
}
```

<a name=paint></a>
## 3. Painting the Window
- We have created a window, Now we want to show something inside it. In Windows terminology, this is called painting the window.
- Sometime you paint yourself, othertimes OS asks to paint by sending WM_PAINT message. The portion of the window that must be painted is called the update region.
- The first time a window is shown, the entire client area of the window must be painted. Hence we will always receive at least one WM_PAINT message when we show window.
- **Understading Concepts:** See WindowProc() function above
  - _5a._ Fill the [structure PAINTSTRUCT](/Operating_Systems/Windows/API_Structures).
  - _5b._ Update region with a single color, using the system-defined window background color (COLOR_WINDOW). actual color indicated by COLOR_WINDOW depends on the user's current color scheme.
  - _5c._ After paiting is done, EndPaint function is called which clears the update region & also signals to Windows that the window has completed painting itself.

<a name=close></a>
## 4. Closing the Window
- _6a._ User can close an application window by clicking the Close button or keyboard shortcut. Window will receive a WM_CLOSE message. DestroyWindow function does it
