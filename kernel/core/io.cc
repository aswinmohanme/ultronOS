/*
  $ @ File : io.cc
  $ @ Decription : Contains the IO methods to communicate with the ports
  */

// Include the io.h as the class is declared there
#include <system.h>

// @ Fuction : outb
// @ Descrption : Writes a value to a given port  address
void io::outb(u16int port, u8int value)
{
  asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

// @ Fuction : inb
// @ Descrption : Writes a value to a given port  address
u8int io::inb(u16int port)
{
  u8int ret;
  asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}

// @ Fuction : inw
// @ Descrption : Writes a value to a given port  address
u16int io::inw(u16int port)
{
  u16int ret;
  asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}
