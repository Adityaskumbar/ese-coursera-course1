/****************************************************************************** 
 * Copyright (C) 2017 by Alex Fosdick - 
 University of Colorado * * Redistribution, 
 modification or use of this software in source 
 or binary * forms is permitted as long as the 
 files maintain this copyright. Users are * 
 permitted to modify this and use it to learn 
 about the field of embedded * software. Alex 
 Fosdick and the University of Colorado are not 
 liable for any * misuse of this material. * 
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdlib.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


int32_t * reserve_words(size_t length)
{
  return (int32_t *) malloc( length * sizeof(int32_t) );
}

void free_words(int32_t * src)
{
  free( src );
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
  uint8_t * p = src;
    size_t i;
     for (i = 0; i < length; i++)
     {
       *p = value;
       p++;
     }

  return src;
}



   uint8_t * my_memzero(uint8_t * src, size_t length)
   {
     uint8_t * p = src;
     size_t i;
     for (i = 0; i < length; i++)
     {
         *p = 0;
          
p++;
     }
     return src;
   }

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
  uint8_t * s = src;
  uint8_t * d = dst;
  size_t i;
  for (i = 0; i < length; i++)
  {
    *d = *s;
    s++;
    d++;
  }
  return dst;
}


uint8_t * my_reverse(uint8_t * src, size_t length)
{
  uint8_t * front = src;
  uint8_t * back = src + length - 1;
  uint8_t temp;
  while (front < back)
  {
    temp = *front;
    *front = *back;
    *back = temp;
    front++;
    back--;
  }
  return src;
}


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  size_t i;
  if (dst < src)
  {
    uint8_t * s = src;
    uint8_t * d = dst;
    for (i = 0; i < length; i++)
    {
      *d = *s;
      s++;
      d++;
    }
  }
  else
  {
    uint8_t * s = src + length;
    uint8_t * d = dst + length;
    for (i = 0; i < length; i++)
    {
      s--;
      d--;
      *d = *s;
    }
  }
  return dst;
}
