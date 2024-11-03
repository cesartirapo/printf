#include "libftprintf.h"
#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = (char)va_arg(args, int);
                write(1, &c, 1);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    write(1, str++, 1);
                }
            }
            else if (*format == 'p')
            {
                void *ptr = va_arg(args, void *);
                unsigned long address = (unsigned long)ptr;
                write(1, "0x", 2);
                for (int i = 15; i >= 0; i--)
                {
                    int hex_digit = (address >> (i * 4)) & 0xF;
                    char c = (hex_digit < 10) ? (hex_digit + '0') : (hex_digit - 10 + 'a');
                    write(1, &c, 1);
                }
            }
            else if (*format == 'd')
            {
                int d = va_arg(args, int);
                if (d == 0)
                {
                    write(1, "0", 1);
                }
                else if (d == -2147483648)
                {
                    write(1, "-2147483648", 11);
                }
                else
                {
                    if (d < 0)
                    {
                        d = -d;
                        write(1, "-", 1);
                    }
                    if (d > 9)
                    {
                        ft_printf("%d", d / 10);
                    }
                    char c = (d % 10) + '0';
                    write(1, &c, 1);
                }
            }
            else if (*format == 'u')
            {
                unsigned int u = va_arg(args, unsigned int);
                if (u == 0)
                {
                    write(1, "0", 1);
                }
                else
                {
                    if (u > 9)
                    {
                        ft_printf("%u", u / 10);
                    }
                    char c = (u % 10) + '0';
                    write(1, &c, 1);
                }
            }
            else if (*format == 'x')
            {
                unsigned int x = va_arg(args, unsigned int);
                if (x == 0)
                {
                    write(1, "0", 1);
                }
                else
                {
                    if (x > 15)
                    {
                        ft_printf("%x", x / 16);
                    }
                    char c = (x % 16 < 10) ? (x % 16 + '0') : (x % 16 + 'a' - 10);
                    write(1, &c, 1);
                }
            }
            else if (*format == 'X')
            {
                unsigned int X = va_arg(args, unsigned int);
                if (X == 0)
                {
                    write(1, "0", 1);
                }
                else
                {
                    if (X > 15)
                    {
                        ft_printf("%X", X / 16);
                    }
                    char c = (X % 16 < 10) ? (X % 16 + '0') : (X % 16 + 'A' - 10);
                    write(1, &c, 1);
                }
            }
            else if (*format == '%')//Esto revisalo porque aquí hay error.
            {
                write(1, "%", 1);
            }
        }
        else
        {
            write(1, format, 1);
        }
        format++;
    }
    va_end(args);
    return 0;
}