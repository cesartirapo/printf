#include "libftprintf.h"
#include <stdio.h>

int main()
{
    ft_printf("Hola %c, %s!\n", 'A', "mundo");
    ft_printf("Dirección: %p\n", (void *)main);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Hexadecimal: %X\n", 255);
    ft_printf("Probando %%");
    return 0;
}