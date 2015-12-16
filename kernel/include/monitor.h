/*
  $ @ File : monitor.h
  $ @ Decription : Contains the  class definition for the monitor
  */

#ifndef MONITOR_H_INCLUDED
#define MONITOR_H_INCLUDED

#include <system.h>

// @ Define : Color Codes for the VGA Driver
#define BLACK         0
#define BLUE          1
#define GREEN         2
#define CYAN          3
#define RED           4
#define MAGENTA       5
#define BROWN         6
#define LIGHT_GREY    7
#define DARK_GREY     8
#define LIGHT_BLUE    9
#define LIGHT_GREEN   10
#define LIGHT_CYAN    11
#define LIGHT_RED     12
#define LIGHT_MAGNETA 13
#define LIGHT_BROWN   14
#define WHITE         15



/*
@ Inherits from IO for using  inb and outb
*/
class monitor : io
{
  // The VGA framebuffer starts at 0xB8000.
  u16int *video_memory;
  // Stores the cursor position.
  u8int cursor_x;
  u8int cursor_y;
  // Since Constructors are unavailable we must explicitly call an init function
  bool isInitialised;

public:
  void init();
  void seed(u8int x , u8int y);
  void clear();
  void scroll();
  void movecursor();
  void putch(char ch);
  void write(const char *c);
  void write_dec(int n);

  bool isinit()
  {
    return isInitialised;
  }

  u8int return_x()
  {
    return cursor_x;
  }

  u8int return_y()
  {
    return cursor_y;
  }

};

// @ Task : Print a Message on to the screen
void printj(const char *s);
void putch(char ch);
// @ Print a Number on to the screen
void print_dec(u32int n);
// @ Task Clear the Screen
void clrscr();


#endif
