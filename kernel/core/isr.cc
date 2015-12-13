/*
  * @ File : ISR.cc
  * @ Description : Handles the Interrupt Service Routines
*/

#include <system.h>

// The Interrupt Handlers
isr_t interrupt_handlers[256];

/*
  * Gets Called from the Assembly when an Interrupt is Raised
  * @param : Registers when an ISR is called
*/
extern "C" void isr_handler(registers_t regs)
{
  printj(" Unhandled Exception No :: ");
  print_dec(regs.int_no);
  printj("\n");
}

/**
  * Called when Interrupt Request is Raised by the PIT
  * @param : Saves the CPU state , and other related Information
**/
extern "C" void irq_handler(registers_t regs)
{
  // Send the EOI signal to the Slave
  // Slave handles the Interrupt from 40 to 47
  if(regs.int_no >= 40)
    io::outb(PIC_SLAVE_COMMAND , 0x20);

  // Send Reset Signal to Master
  io::outb(PIC_MASTER_COMMAND , 0x20);

  // if Interrupt is already registered
  if(interrupt_handlers[regs.int_no] != 0)
    {
      isr_t handler = interrupt_handlers[regs.int_no];
      handler(regs);
    }
}

// @ Task : Register an Interrupt Handler
void register_interrupt_handler(u8int n, isr_t handler)
{
  interrupt_handlers[n] = handler;
}
