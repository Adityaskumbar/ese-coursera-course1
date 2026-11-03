#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t * p = ptr;
  uint8_t length = 0;
  int negative = 0;
  uint32_t value;
  uint32_t digit;
   
  if (data < 0)
  {
    negative = 1;
    value = (uint32_t)(-(int64_t)data);
  }
  else
  {
    value = (uint32_t)data;
  }

  if (value == 0)
  {
    *p = '0';
    p++;
    length++;
  }


  while (value > 0)
  {
    digit = value % base;
    if (digit < 10)
    {
      *p = '0' + digit;
    }
    else
    {
      *p = 'A' + digit - 10;
    }
    p++;
    length++;
    value = value / base;
  }

  if (negative)
  {
    *p = '-';
    p++;
    length++;
  }

  *p = '\0';
  length++;

  my_reverse(ptr, length - 1);
  return length;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  uint8_t * p = ptr;
  int32_t result = 0;
  int negative = 0;
  uint8_t i;
  uint8_t c;
  int32_t d;

    if (*p == '-')
  {
    negative = 1;
    p++;
    digits--;
  }

  digits--;

  for (i = 0; i < digits; i++)
  {
    c = *p;
    if (c >= '0' && c <= '9')
    {
      d = c - '0';
    }
    else
    {
      d = c - 'A' + 10;
    }
    result = result * base + d;
    p++;
  }

  if (negative)
  {
    result = -result;
  }

  return result;
}
