

```c
typedef struct{
  const char* str;
  unsigned short length;
}TEXT;

typedef struct{    //menu.h
  TEXT name;
  TEXT description;
  struct tagMenu *imenu;
  ...
}ITEM;
```
- Example code
```c
int main(){
  //ITEM *new_item(const char *name, const char *description);
  //What? Allocate new item(pointed by name) for menu. Note: caller must have allocated array either on his stack/heap.
  //Arguments:
  //  const char* name:
  //  const char* des:
  //Return:
  //  struct ITEM*: Pointer to ITEM structure //See CommonDS.md

```
