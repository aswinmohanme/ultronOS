/*
  * @ File : memory.cc
  * @ Decription : Contains the Commonly used routines
*/

#include <system.h>

// @ Task : Copy set no of bytes from src to dest
void *memcpy(void *dest, const void *src, int count)
{
  const char *sp = (const char *)src;
  char *dp = (char *)dest;
  for(; count != 0; count--) *dp++ = *sp++;
  return dest;
}

// @ Task : Set no of destination bytes to val
void *memset(void *dest, char val, int count)
{
  char *temp = (char *)dest;
  for( ; count != 0; count--) *temp++ = val;
  return dest;
}

// @ Task : Same as that of memset() , except uses unsigned int
u16int *memsetw(u16int *dest, u16int val, int count)
{
  u16int *temp = (u16int *)dest;
  for( ; count != 0; count--) *temp++ = val;
  return dest;
}
