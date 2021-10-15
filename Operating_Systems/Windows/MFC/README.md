- [Microsoft Foundation classes / MFC](#mfc)
- **Terms**
  - [1. Windows](#w)
  - [2. Messages](#m)
  - [3. Multiple, Single Document Application](#md)
- **Creating MFC Application**
  - [1. Default MFC Application (name=Test)](#df)


<a name=mfc></a>
## MFC
MFC Library is a collection of C++ classes, which are used for writing windows applications.

## Terms
<a name=w></a>
#### 1. Windows
- **a. Main Window:** 
  - Windows are the primary interface elements that applications use to present graphic and text output to the user. Main window will have:
    - _Client Area:_ On which the application/user writes or displays graphics and text, surrounded by a rectangular border.
<a name=m></a>
#### 2. Messages
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
<a name=md></a>
#### 3. Multiple, Single Document Application
- **Multiple Document:** Same as Microsoft Excel or Word, where we can open several documents at same time.
- **Single Document:** Only 1 document is allowed to open at a time.

### Creating MFC Applications
<a name=df></a>
#### 1. Default MFC Application (name=Test)
Visual Studio > Create MFC Application > Single Document.
```
1. Windows will create following classes by default
  - C<name>App class inherited from CWinAppEx, which is derived from CWinThread,CObject,CCmdTarget
  - C<name>Doc class inherited from CDocument
  - C<name>View class inherited from CView
  - CMainFrame class inherited from CFramwWndEx
  - CChildFrame class inherited from CMDIChildWndEx

//C is prefixed before classes for MFC
      CCmdTarget
 CWinThread /\
  /\         | |-->CObject
  |          | |
 |--------------|    |--------------|    |--------------|      |-------------|   |----------------|
 |  CWinAppEx   |    |  CDocument   |    |     CView    |      | CFrameWndEx |   | CMDIChildWndEx |
 |--------------|    |--------------|    |--------------|      |-------------|   |----------------|
     /\                    /\                  /\                   /\                 /\
      |                     |                   |                    |                  |
      |                     |                   |                    |                  |
|-----------------|   |--------------|    |---------------|     |------------|     |-------------|
|   CTestApp      |   |  CTestDoc    |    |   CTestView   |     | CMainFrame |     | CChildFrame |
|-----------------|   |--------------|    |---------------|     |------------|     |-------------|
    
//////////What classes contains?////////////
                  Class                   |     What
------------------------------------------|--------------------------------
  CTestDoc(Derived from CDocument)        | Hold User,Application data in files
  CTestView(Derived from CView)           | Users can view/edit data present in CTestDoc    //(Doc, View classes) forms Document View Architecture
  CMainFrame(Derived from CFrameWnd)      | Manages Main Frame of Application(Menu, toolbars, status bars etc)
  CChildFrame(derived from CMDIChildWndEx)| Classes derived from CChildFrame manages child windows created from multiple views
                                            Like Mainframe, ChildFrame manages frames of child windows
  CWinThread                              | MFC Application can create multiple threads when needed.
  CCmdTarget                              | Handles Windows messages. Every derived class will have its own MessageMap(to handle messages)
  CObject                                 | Almost all classes are derived from CObject in MFC(except few eg: CString)
                                            CObject provides: Serialization, RTTI, Debugging features.

/////////////CWinApp class//////////////
class CTestApp : public CWinAppEx
{
public:
	CTestApp() noexcept;
// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};
```
2. Starting MFC application
```c
 a. Object of CWinApp is created.
//Test.cpp
CTestApp theApp;                          //Created object of CWinApp

b. All static objects are initialized

c. Initialize MFC
WinMain() {
  InitApplication() //of CWinApp class. 
  InitInstance()    //of CWinApp class
  ShowWindow()
  UpdateWindow()
  CWinThread::Run()    //of CWinApp class. This is INFINITE loop which waits for message.
}

BOOL CTestApp::InitInstance() {
  Initializes OLE, Windows sockets, 3D Controls.
}
```
