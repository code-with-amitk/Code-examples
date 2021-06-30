- [1. Structures](#st)
  - [WNDCLASS](#WNDCLASS)
  - [WNDCLASSEX](#WNDCLASSEX)
- [2. API](#api)
  - [2.1 wWinMain](#wWinMain)
  - [2.2 WinMain](#WinMain)
  - [2.3 RegisterClass or RegisterClassEx](#RegisterClassEx)
  - [2.4 CreateWindow or CreateWindowEx](#CreateWindow)
  - [2.5 ShowWindow](#ShowWindow)
  - [2.6 UpdateWindow](#UpdateWindow)

<a name=st></a>
## 1. Structures
<a name=WNDCLASS></a>
### WNDCLASS
- To create window, we need to populate this structure. it contains information about the window: 
  - the application icon, background color of the window, name to display in the title bar, a function pointer to your window procedure. 
```c
typedef struct _WNDCLASS {
 UINT style; 
 WNDPROC lpfnWndProc; 
 int cbClsExtra; 
 int cbWndExtra; 
 HANDLE hInstance; 
 HICON hIcon; 
 HCURSOR hCursor; 
 HBRUSH hbrBackground; 
 LPCTSTR lpszMenuName; 
 LPCTSTR lpszClassName; 
 } WNDCLASS ;
```
<a name=WNDCLASSEX></a>
### WNDCLASSEX
```c++
typedef struct tagWNDCLASSEXW {
  UINT      cbSize;
  UINT      style;
  WNDPROC   lpfnWndProc;          //A pointer to the window procedure.
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCWSTR   lpszMenuName;
  LPCWSTR   lpszClassName;
  HICON     hIconSm;                //A handle to a small icon that is associated with the window class.
} WNDCLASSEXW, *PWNDCLASSEXW, *NPWNDCLASSEXW, *LPWNDCLASSEXW;
```

<a name=api></a>
## 2. APIs

<a name=wWinMain></a>
### 2.1 wWinMain
```c
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
```
<a name=WinMain></a>
### 2.2 WinMain
- Just as every C/C++ application must have a main(), every Windows desktop application must have a WinMain function.
```c++
int CALLBACK WinMain(
   _In_HINSTANCE hInstance,          //A handle to the current instance of the application.
   _In_opt_HINSTANCE hPrevInstance,  //handle to the previous instance of the application
   _In_LPSTR     lpCmdLine,          //command line for the application, excluding the program name
   _In_int       nCmdShow           //Controls how the window is to be shown.
);

Return: 
  Success: exit value
  error: 0
```
<a name=RegisterClassEx></a>
### 2.3 RegisterClassEx
- Register the struct WNDCLASS or WNDCLASSEX with Windows so that it knows about your window and how to send messages to it. 
```c++
ATOMRegisterClass(constWNDCLASS* lpWndClass);

ATOM RegisterClassExW(
  const WNDCLASSEXW *unnamedParam1    //A pointer to a WNDCLASSEX structure.
);
```

<a name=CreateWindow></a>
### 2.4 CreateWindow or CreateWindowEx
- Creates an overlapped, pop-up, or child window.
```c
void CreateWindowW(
   lpClassName,               //Name of application
   lpWindowName,              //the text that appears in the title bar
   dwStyle,                   //the type of window to create
   x,                         //// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
   y,
   nWidth,
   nHeight,
   hWndParent,
   hMenu,
   hInstance,
   lpParam
);
```

<a name=ShowWindow></a>
### 2.5 ShowWindow
- Sets the specified window's show state.
```c
BOOL ShowWindow(
  HWND hWnd,      //handle to the window.
  int  nCmdShow   //Controls how the window is to be shown. 
);
```

<a name=UpdateWindow></a>
### 2.6 UpdateWindow
- The UpdateWindow function updates the client area of the specified window by sending a WM_PAINT message to the window
```c
BOOL UpdateWindow(
  HWND hWnd                    //Handle to the window to be updated.
);
```
