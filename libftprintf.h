#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdarg.h>//biblioteca estándar de C que proporciona macros para manejar argumentos variables en funciones. Esto es esencial para tu implementación de ft_printf() porque necesitas aceptar un número variable de argumentos.
//Los argumentos variables son aquellos que permiten a una función recibir un número indeterminado de argumentos.
int ft_printf(const char *format, ...);

#endif