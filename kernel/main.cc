/*
  * @ File : main.cc
  * @ Description : defines kmain the Entry point of our kernel
*/

// Include the System File from the SDK
#include <system.h>


// Declared as a C function so as to remove name manglng and call it from the assembly file
extern "C" int kmain(struct multiboot *mboot_ptr);

// The Main Function
int kmain(struct multiboot *mboot_ptr)
{

  clrscr();

  // Initialise the Descritor Tables
  init_desc_tables();

  // Initialise the Timer
  init_timer(50);

  // Print Hello On to the Screen
  printj("Hello World \n");
  return 1;
}
