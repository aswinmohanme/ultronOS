/*
  * @ File : common.h
  * @Desc : Includes some commonly used Interface routines
*/

#include <system.h>

// @ Task : Initialise the Descritor tables and pads them with zero
void init_desc_tables()
{
  init_gdt();
  init_idt();

  memset(&interrupt_handlers, 0, sizeof(isr_t)*256);
}

// @ Add Some Fancy Boot Text to the Screen
void boot()
{
  printj("Booting Up\n");
  printj("Initialising the GDT \n");
  printj("Initialising the IDT \n");
  printj("Configuring PIC\n");
  printj("Configuring TIMER\n");
  printj("Configuring KEYBOARD\n");
  printj("Loading System \n");

  printj("\n\n ========= System Ready ========== \n");
  printj(" Hello World");
}
