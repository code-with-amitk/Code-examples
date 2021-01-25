## Creating n Row, m cols
- [ncurses programming howto](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/menus.html)
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

  //3. CREATE NEW ITEMS
  for (i=0; i<4; ++i)
    my_items[i] = new_item(choices[i], choices[i]);
    
  //MENU *new_menu(ITEM **items);  //Create menu using item pointer array.
  //4. CREATE NEW MENU(for ITEMS to be attached)
  MENU* my_menu = new_menu ((ITEM**)my_menu);
  
	//5. Set menu option not to show the description
	menu_opts_off(my_menu, O_SHOWDESC);
  
  //6. Create window inside menu having 20 rows and 130 col, starting from (2,2)  
  //WINDOW *newwin(int nlines, int ncols, int begin_y, int begin_x);
  //Create new window with given rows=nlines and cols=ncols
  //begin_x, begin_y: (x,y) start menu from these coordinates
  WINDOW* my_menu_win = newwin(20,130,2,2);
  
  //int keypad(WINDOW *win, bool bf);   //enables the keypad of the user's terminal.
  keypad(my_menu_win, TRUE);
  
  //7. set Main window and submenu
  //int set_menu_win(MENU *menu, WINDOW *win);  //sets the window of menu to win.
  set_menu_win(my_menu, my_menu_win);
  
  //8. Create new windows inside main window
  //WINDOWS* derwin(WINDOW* orig, int nline, int ncols, int y, int x)
  //Start subwindow from (x,y) and make subwindow of rows=nlines, cols=ncols
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 68, 3, 1));
  
  //9. Maximum display size for given menu
  //set_menu_format(MENU* menu, int row, int col);    Create a submenu of 15 rows, 3 cols
  set_menu_format(my_menu, 5, 3);
  
  //10. int set_menu_mark(MENU *menu, char *mark);
  //menus mark string routines
  set_menu_mark(my_menu, "*");
  
  //11. Print a border around the main window and print a title
  //int box(WINDOW *win, chtype verch, chtype horch);
  box(my_menu_win,0,0);
  
  //12. Get actual output to terminal
  //int refresh(void);
  refresh();
  
  //13. Post the menu
  //int post_menu(MENU *menu);
  post_menu(my_menu);
  
  //14. get actual output to the terminal
  //int wrefresh(WINDOW *win);
  wrefresh(my_menu_win);
```
