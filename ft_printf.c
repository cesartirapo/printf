#include "libftprintf.h"
#include <unistd.h>// Para write
//Una función variádica es una función que puede recibir un número variable de argumentos. En C, se define utilizando el tipo ... en su prototipo, como en int printf(const char *format, ...). Esto permite que la función procese diferentes cantidades de argumentos de distintos tipos al mismo tiempo, como en el caso de ft_printf.
int ft_printf(const char *format, ...)
{
    //const char *format: Primer argumento de la función; es un puntero constante a un carácter (const char*) que apunta a una cadena de formato. La cadena contiene texto y especificadores como %d o %s.
    //Además, format es el último argumento fijo, ya que es el último valor o último argumento fijo que se define explícitamente en el prototipo de la función antes de los opcionales.
    //No es opcional; en este caso, format siempre es requerido, ya que indica el formato de salida.
    //Tiene requisitos: para ser leída correctamente por la función. Debe:
    //Contener especificadores de formato válidos (como %d, %s, %c, etc.) para indicar cómo se deben interpretar los argumentos opcionales.
    //Escapar el carácter % usando %% si deseas imprimir un solo signo de porcentaje.
    //Ser una cadena de caracteres bien formada (es decir, debe terminar con un carácter nulo \0).
    //...: Indica que ft_printf es una función variádica, permitiendo que reciba un número indefinido de argumentos adicionales/opcionales.
    va_list args;//Declaración de variable args que es la variable que almacenará los argumentos.
    //va_list: Tipo de dato especial de la biblioteca stdarg.h que representa la lista de argumentos variables.
    //args: Nombre de la variable que almacenará la lista de argumentos variables que se pasan a ft_printf.
    va_start(args, format);//Inicializa la lista con el último argumento fijo
    //va_start: Macro de stdarg.h que inicializa args para acceder a los argumentos variables/opcionales/adicionales.
    //format: Último argumento fijo de ft_printf. va_start necesita saber cuál es el último argumento fijo para encontrar el comienzo de los argumentos variables/opcionales en memoria.
    //Con va_start(args, format); el programa sabe que los argumentos opcionales comienzan justo después de format en la memoria, permitiéndole leerlos correctamente.
    while (*format)//Ahora, itera sobre el string format para procesar cada carácter. Si encuentras un %, verifica el siguiente carácter para manejar las conversiones.
    {
        if (*format == '%')//se utiliza para identificar el carácter de porcentaje (%) en la cadena de formato, lo cual indica que lo que sigue es una conversión que debe procesarse.
        {
            format++; // Avanza al siguiente carácter
            // Manejar conversiones aquí
            if (*format == 'c')
            {
                char    c = (char)va_arg(args, int); // Se extrae un arg de tipo int y luego se convierte a char.
                //En C, cuando se pasan argumentos de tipo char a funciones variádicas (como ft_printf), se promocionan a int.
                //Esto significa que se convierten automáticamente en int para garantizar que sean compatibles y se manejen correctamente en la llamada a la función.
                //La promoción de tipos en funciones variádicas sucede solo con ciertos tipos simples:
                //Tipos como char y short (entero corto) se promocionan a int cuando se pasan a una función variádica.
                //Tipos como float se promocionan a double en funciones variádicas
                //Punteros (char *, int *, etc.) no se promocionan.
                //Esto es una regla en C para asegurar compatibilidad y evitar problemas de tamaño en la memoria.
                //Por eso, para obtener un char, necesitamos decirle a va_arg que extraiga un int y luego convertirlo a char.
                //char c = : se declara la variable como variable de tipo char.
                //(char) : conversión a char
                //va_arg: Es una macro de la biblioteca stdarg.h que se utiliza para acceder a los argumentos variables de la lista.
                //args: Es la lista de argumentos variables que se inicializó previamente con va_start. Contiene los argumentos pasados a la función ft_printf.
                write(1, &c, 1); // Imprime el carácter
            }
            // Agrega más conversiones aquí (por ejemplo, 's', 'p', 'd', 'i', etc.)
            else if (*format == 's')
            {
                char    *str = va_arg(args, char *);//obtiene el siguiente argumento de la lista de argumentos variables, una cadena de caracteres, y lo almacena como un puntero que apunta a dicha cadena.
                while (*str)
                {
                    write(1, str++, 1);
                }
            }
            else if (*format == 'p')
            {
                void    *ptr = va_arg(args, void *);
                unsigned long   address = (unsigned long)ptr; // Convierte el puntero a un número
                write(1, "0x", 2); // Imprime el prefijo "0x"
                // Imprime cada dígito hexadecimal
                int i;
                i = 15;
                while (i >= 0)
                {
                    int hex_digit = (address >> (i * 4)) & 0xF; // Obtiene el dígito hexadecimal
                    char    c = (hex_digit < 10) ? (hex_digit + '0') : (hex_digit - 10 + 'a');
                    write(1, &c, 1);
                    i--;
                }
            }
            else if (*format == 'd')//como la funcion putnbr
            {
                int d = va_arg(args, int);//obtiene el siguiente argumento de la lista de argumentos variables
                if (d == 0)
                {
                    write(1, "0", 1);
                }
                if (d == -2147483648)
                {
                    write(1, "-2147483648", 11);
                }
                if (d < 0)
                {
                    d = -d;
                    write(1, "-", 1);
                }
                if (d > 9)
                {
                    ft_printf("%d", d / 10);
                    //El primer argumento es la cadena de formato "%d", que le indica a ft_printf que debe interpretar el siguiente valor como un número entero en base 10.
                    //Las comillas "%d" le dicen al compilador que es una cadena literal, no una variable ni un valor numérico.
                }
                char    c = (d % 10) + '0';
                write(1, &c, 1);
            }
            //else if (*format == 'i'){}//???ChatGPT dice que la implementación es igual que para 'd'
            else if (*format == 'u')//%u imprime un número entero sin signo en base 10, es decir, solo valores positivos.
            {
                unsigned int    u = va_arg(args, unsigned int);//obtiene el siguiente argumento de la lista de argumentos variables
                if (u == 0)
                {
                    write(1, "0", 1);
                }
                if (u > 9)
                {
                    ft_printf("%u", u / 10);
                }
                char    c = (u % 10) + '0';
                write(1, &c, 1);
            }
            else if (*format == 'x')
            {
                unsigned int    x = va_arg(args, unsigned int);
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
                    char    c;
                    if ((x % 16) < 10)
                        c = (x % 16) + '0';
                    else
                        c = (x % 16) + 'a' - 10;
                write(1, &c, 1);
                }
            }
            else if (*format == 'X')
            {
                unsigned int    X = va_arg(args, unsigned int);
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
                    char    c;
                    if ((X % 16) < 10)
                        c = (X % 16) + '0';
                    else
                        c = (X % 16) + 'A' - 10;
                write(1, &c, 1);
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1); // Imprime un solo %
            }
        }
        else
        {
            write(1, format, 1); // Imprime el carácter normal
        }
        format++; // Avanza al siguiente carácter
    }
    return 0; // Devuelve 0 por ahora
}