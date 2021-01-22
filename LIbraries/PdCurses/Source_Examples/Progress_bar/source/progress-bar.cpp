#include <iostream>
#include <curses.h>
#include <thread>
#include <chrono>

void UpdateProgress (int& progress) { 
  progress++;
  
  //Sleep for 1 second
  std::this_threa::sleep_for(std::chrono::microseconds(1000000));
}

int main(){

  //initscr(): Determines terminal type and initialises all implementation data structures.
  initscr();
  
  //start_color(): Called if the programmer wants to use colors
  start_color();
  
  //init_pair(): 
  //Argument-1: the number of the color-pair to be changed
  //Argument-2: the foreground color number
  //Argument-3: the background color number. 
  init_pair (1, COLOR_RED, COLOR_BLACK);
  
  //attron(): turns on the named attributes without affecting any others
  attron (COLOR_PAIR(1));
  
  int loading = 0;
  
  while (loading < 50) {
    UpdateProgress (loading);
    
    //mvaddch(): put the character ch into the given window at its current window position
    //Argument-1:x. x coordinate from where characters to be put
    //Argument-2:y. y coordinate from where characters to be put
    //Argument-3:character 
    mvaddch (20, loading+10, '#');
    
    //refresh(): Put actual output to the terminal, as other routines merely manipulate data structures
    refresh();
  }
  
  std::cout << "Flashing Complete";
  
  //attroff(): Turns off the named attributes without turning any other attributes on or off
  attroff (COLOR_PAIR(1));
  getch ();
  endwin ();
}
