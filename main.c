#include "libftprintf.h"
#include <stdio.h>

int main()
{
    ft_printf("Hola %c, %s!\n", 'A', "mundo");
    ft_printf("Dirección: %p\n", (void *)main);// imprimire la dirección de memoria donde se encuentra la función main en formato hexadecimal.
    //%p: formato que indica que se debe imprimir una dirección de puntero en formato hexadecimal.
    //(void *): El casting (void *) convierte la dirección de la función main (que es un puntero a función) a un puntero de tipo void*.
    //el tipo void* es un puntero genérico que puede apuntar a cualquier tipo de datos.
    //main: Es el nombre de la función main. En C, el nombre de una función representa su dirección en memoria.
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Hexadecimal: %X\n", 255);
    ft_printf("Probando %, %%\n");
    return 0;
}