## Creating n Row, m cols
- Example code
```c

//1. Take menu items to be displayed. size=4
char *choices[] = {"Value", "GPU1", "GPU2", (char*)NULL};   //Array of Pointer to char(must be NULL terminated)

int main(){
  //2. Allocate array of ITEM structures, equal to menu items
  ITEM** my_items = (ITEM**) calloc(4, sizeof(ITEM*));

  //ITEM *new_item(const char *name, const char *description);
  //What? Allocate new item(pointed by name) for menu. Note: caller must have allocated array either on his stack/heap.
  //Arguments:
  //  const char* name:
  //  const char* des:
  //Return:
  //  struct ITEM*: Pointer to ITEM structure //See Structures.md

  //3. Fill item structures using new_item() API.
  for (i=0; i<4; ++i)
    my_items[i] = new_item(choices[i], choices[i]);
    
  //MENU *new_menu(ITEM **items);
  //Create menu using item pointer array.
  
  //4. Get menu pointer from new_menu()
  MENU* my_menu = new_menu ((ITEM**)my_menu);
  
  //WINDOW *newwin(int nlines, int ncols, int begin_y, int begin_x);
  //Create new window with given rows=nlines and cols=ncols
  //begin_x, begin_y: (x,y) start menu from these coordinates
  
  //5. Create window inside menu having 20 rows and 130 col, starting from (2,2)
  WINDOW* my_menu_win = newwin(20,130,2,2);
  
  //int set_menu_win(MENU *menu, WINDOW *win);
  //sets the window of menu to win.
  
  //6. set window menu
  set_menu_win (my_menu, my_menu_win);
```
