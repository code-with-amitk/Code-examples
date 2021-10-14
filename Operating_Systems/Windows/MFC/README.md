- [Microsoft Foundation classes / MFC](#mfc)
- **Terms**
  - [Window](#w)
  - [Messages](#m)
- **Creating MFC Application**
  - [1. Hello World](#hw)


<a name=mfc></a>
## MFC
MFC Library is a collection of C++ classes, which are used for writing windows applications.

## Terms
<a name=w></a>
### Windows
#### 1. Main Window
- Windows are the primary interface elements that applications use to present graphic and text output to the user. Main window will have:
  - _Client Area:_ On which the application/user writes or displays graphics and text, surrounded by a rectangular border.
<a name=m></a>
### Messages
Every MFC application is event driven. All application consists of message handler functions. Message is represented using this structure.
```c
struct {
  hwnd;             //window whose Handler received the message (hwnd is a pointer that contains the window’s address)
  struct message{   //Messages are represented with WM_
    type;
    number;         //Every message is defined by constant in windows.h
    wParam;         //Extra parameters in message
    IParam;         //Additional information about message
    time;           //time at which message was generated
  }
  
};
```

### Creating MFC Applications
<a name=hw></a>
#### 1. Hello World (name = mfc)
Visual Studio > Create MFC Application > Single Document.
```
Default files created
  |- mfc.cpp, mfc.h
  |- mainframe.cpp, mainframe.h
```
mfc.h
```cpp
class mfc : public CWinApp {      //CFrameWnd, CWinApp classes contain all code to create & operate the main window
};

```
