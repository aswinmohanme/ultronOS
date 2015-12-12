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

  // Initialise the Global Descriptor Table
  init_gdt();
  init_idt();
  memset(&interrupt_handlers, 0, sizeof(isr_t)*256);

  asm volatile("sti");
  init_timer(5);

  // Print Hello On to the Screen
  printj("Hello World \n");
  return 1;
}
