#include <stdint.h>
#include <stdarg.h>

void init_uart();
static int put_byte(char c);
static int put_string(char *s);

static int print_unsigned(unsigned value, int width, char pad);
static int print_decimal(int value, int width, char pad);
static int print_int(int value, int width, int pad, int base);
int printf_impl(const char* format, va_list ap);

int swerv_printf(const char* format, ...);