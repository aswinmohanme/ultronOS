/*
  $ @ File Name : System.h
  $ @ Description : Contains the prototypes of commonly used Functions and all the classes
  $ @ Dated : 27 - 11 - 2015
*/

#ifndef SYSTEM_H_INCLUDED
#define  SYSTEM_H_INCLUDED

// Declare Uniform Types for use
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

// @ All Header Files Must Be Included Here
#include "io.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"
#include "monitor.h"
#include "memory.h"
#include "timer.h"


#endif
