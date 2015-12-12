/*
  * @ File : memory.h
  * @ Decription : Contains the Commonly used routines
*/

#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <system.h>

// @ Task: Copy set no of bytes from src to dest
void *memcopy(void *dest, const void *src, int count);

// @ TasK : Set 'count' bytes in 'dest' to 'val'.*/
void *memset(void *dest, char val, int count);

// @ Task : Same as Above
u16int *memsetw(u16int *dest, u16int val, int count);


#endif
