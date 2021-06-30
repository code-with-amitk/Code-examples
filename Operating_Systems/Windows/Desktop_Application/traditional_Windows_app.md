## Code
- [APIs, Structures](/Operating_Systems/Windows)
```c++
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

HINSTANCE hInst;

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//  PURPOSE:  Processes messages for the main window.
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, Windows desktop!");

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        // Here your application is laid out.
        // For this introduction, we just print out "Hello, Windows desktop!"
        // in the top left corner.
        TextOut(hdc,
            5, 5,
            greeting, _tcslen(greeting));
        // End application-specific layout section.

        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}

static TCHAR szWindowClass[] = _T("DesktopApp");
static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

void FillWNDCLASSEX(WNDCLASSEX& wcex, _In_ HINSTANCE& hInstance) {
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;                         //7. Provide implementation of it
    wcex.cbClsExtra = 0; 
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
}

int CALLBACK WinMain(                    //1. Every Win32 Application starts from this
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow) {
    
    WNDCLASSEX wcex;
    FillWNDCLASSEX(wcex, hInstance);    //2. Fill structure WNDCLASSEX

    if (!RegisterClassEx(&wcex))        //3. Register our window using structure filled in step-2
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }
    
    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(                  //4. Creates an overlapped, pop-up, or child window.
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 100,
        NULL,
        NULL,
        hInstance,
        NULL
    );    
    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd, nCmdShow);                      //5. Window has been created, but we need to tell Windows to make it visible
    UpdateWindow(hWnd);                              
    
    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))           //6. For communication b/w application & windows
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
```
