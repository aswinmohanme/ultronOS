/*
  * @ File : ISR.h
  * @ Description : Handles the Interrupt Service Routines
*/

#ifndef ISR_H_INCLUDED
#define ISR_H_INCLUDED

#include <system.h>

// @ Define : The Respective Interrupt for the IRQ
#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47


// @ Define : Registers when an ISR is called
typedef struct registers
{
  u32int ds;                  // Data segment selector
  u32int edi;
  u32int esi;
  u32int ebp;
  u32int esp;
  u32int ebx;
  u32int edx;
  u32int ecx;
  u32int eax;
  // Interrupt number and error code (if applicable)
  u32int int_no, err_code;
  // Pushed by the processor automatically
  u32int eip;
  u32int cs;
  u32int eflags;
  u32int useresp;
  u32int ss;
} registers_t;

// isr_t is a pointer to the CPU registers
typedef void (*isr_t)(registers_t);

extern isr_t interrupt_handlers[];

// @ Task : Generic ISR Handler
extern "C" void isr_handler(registers_t regs);

// @ Task : Generic IRQ Handler
extern "C" void irq_handler(registers_t regs);

// @ Task : Register One Interrupt Handler
void register_interrupt_handler(u8int n, isr_t handler);

#endif
