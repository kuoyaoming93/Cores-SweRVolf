#include "swervolf_print.h"
#include "swevolf_nexys.h"

volatile uint8_t* const uart_addr  = (uint8_t*) UART_BASE;

void init_uart()
{
    volatile uint8_t *p_aux;
    volatile uint32_t *p_aux_32;
    uint32_t aux;
    /* Set DLAB bit in LCR */
    p_aux = uart_addr + REG_LCR;
    *p_aux = (uint8_t) 0x80;

    /* Set divisor regs */
    p_aux_32 = (uint32_t*) CLK_FREQ_HZ;
    aux = *p_aux_32;
    aux = (uint32_t) ((aux/BAUD_RATE) >> 4);
    p_aux = uart_addr + REG_BRDL;
    *p_aux = (uint32_t) aux;

    /* 8 data bits, 1 stop bit, no parity, clear DLAB */
    p_aux = uart_addr + REG_LCR;
    *p_aux = (uint8_t) LCR_CS8 | LCR_1_STB | LCR_PDIS;

    p_aux = uart_addr + REG_FCR;
    *p_aux = (uint8_t) FCR_FIFO | FCR_MODE0 | FCR_FIFO_8 | FCR_RCVRCLR | FCR_XMITCLR;

    p_aux = uart_addr + REG_IER;
    *p_aux = (uint8_t) 0;
}

static int put_byte(char c)
{
    volatile uint8_t *p_aux;
    uint8_t aux;

    p_aux = uart_addr + REG_LSR;
    aux = *p_aux & LSR_THRE;

    while(aux == 0){
        
        aux = *p_aux & LSR_THRE;
    }

    p_aux = uart_addr;
    *p_aux = c;
    return c;
}

static int put_string(char *s)
{
    while(*s != '\0'){
        put_byte(*s);
        s += 1;
    }
    return 1;
}

static int print_unsigned(unsigned value, int width, char pad)
{
  char buffer[20];
  int charCount = 0;

  do
    {
      char c = '0' + (value % 10);
      value = value / 10;
      buffer[charCount++] = c;
    }
  while (value);

  for (int i = charCount; i < width; ++i)
    put_byte(pad);

  char* p = buffer + charCount - 1;
  for (int i = 0; i < charCount; ++i)
    put_byte(*p--);

  return charCount;
}


static int print_decimal(int value, int width, char pad)
{
  char buffer[20];
  int charCount = 0;

  unsigned neg = value < 0;
  if (neg)
    {
      value = -value;
      put_byte('-');
      width--;
    }

  do
    {
      char c = '0' + (value % 10);
      value = value / 10;
      buffer[charCount++] = c;
    }
  while (value);

  for (int i = charCount; i < width; ++i)
    put_byte(pad);

  char* p = buffer + charCount - 1;
  for (int i = 0; i < charCount; ++i)
    put_byte(*p--);

  if (neg)
    charCount++;

  return charCount;
}


static int print_int(int value, int width, int pad, int base)
{
  if (base == 10)
    return print_decimal(value, width, pad);

  char buffer[20];
  int charCount = 0;

  unsigned uu = value;

  if (base == 8)
    {
      do
        {
          char c = '0' + (uu & 7);
          buffer[charCount++] = c;
          uu >>= 3;
        }
      while (uu);
    }
  else if (base == 16)
    {
      do
        {
          int digit = uu & 0xf;
          char c = digit < 10 ? '0' + digit : 'a' + digit - 10;
          buffer[charCount++] = c;
          uu >>= 4;
        }
      while (uu);
    }
  else
    return -1;

  char* p = buffer + charCount - 1;
  for (unsigned i = 0; i < charCount; ++i)
    put_byte(*p--);

  return charCount;
}

int printf_impl(const char* format, va_list ap)
{
  int count = 0;  // Printed character count

  for (const char* fp = format; *fp; fp++)
    {
      char pad = ' ';
      int width = 0;  // Field width

      if (*fp != '%')
        {
          put_byte(*fp);
          ++count;
          continue;
        }

      ++fp;  // Skip %

      if (*fp == 0)
        break;

      if (*fp == '%')
        {
          put_byte('%');
          continue;
        }

      while (*fp == '0')
        {
          pad = '0';
          fp++;  // Pad zero not yet implented.
        }

      if (*fp == '-')
        {
          fp++;  // Pad right not yet implemented.
        }

      if (*fp == '*')
        {
          int outWidth = va_arg(ap, int);
          fp++;  // Width not yet implemented.
        }
      else if (*fp >= '0' && *fp <= '9')
        {    // Width not yet implemented.
          while (*fp >= '0' && *fp <= '9')
            width = width * 10 + (*fp++ - '0');
        }

      switch (*fp)
        {
        case 'd':
          count += print_decimal(va_arg(ap, int), width, pad);
          break;

        case 'u':
          count += print_unsigned((unsigned) va_arg(ap, unsigned), width, pad);
          break;

        case 'x':
        case 'X':
          count += print_int(va_arg(ap, int), width, pad, 16);
          break;

        case 'o':
          count += print_int(va_arg(ap, int), width, pad, 8);
          break;

        case 'c':
          put_byte(va_arg(ap, int));
          ++count;
          break;

        case 's':
          count += put_string(va_arg(ap, char*));
          break;
/*
        case 'g':
          count += whisperPrintDoubleG(va_arg(ap, double));
          break;

        case 'f':
          count += whisperPrintDoubleF(va_arg(ap, double));
*/
        }
    }

  return count;
}

int swerv_printf(const char* format, ...)
{
  va_list ap;

  va_start(ap, format);
  int code = printf_impl(format, ap);
  va_end(ap);

  return code;
}