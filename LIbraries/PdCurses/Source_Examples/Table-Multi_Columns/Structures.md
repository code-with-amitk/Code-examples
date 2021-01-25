## Structures
- Includes common structures.
- **menu.h**
```c
typedef struct{
  const char* str;
  unsigned short length;
}TEXT;

typedef struct tagMENU {
  short height;
  short width;
  short row;
  ..
}MENU;

typedef struct{    
  TEXT name;
  TEXT description;
  struct tagMenu *imenu;
  ...
}ITEM;
```
- **curses.h**
```c
typedef struct _win_st WINDOW;
struct _win_st {
  bool _notimeout;
  bool _idlok;
  ...
};
```
