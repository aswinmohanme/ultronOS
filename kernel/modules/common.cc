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
  printj("--------------------            ");
  printj("Booting Up");

}
