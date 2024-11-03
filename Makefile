
NAME = libftprintf.a
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall  -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_program

re: fclean all

test: $(NAME) main.c
	$(CC) $(CFLAGS) -o test_program main.c -L. -lftprintf
#La opción -lftprintf se usa en el contexto de la compilación y enlazado de programas en C, y cada parte de la expresión tiene un significado específico:
#-l: Este prefijo indica al compilador que debe buscar una biblioteca. Es una forma abreviada de la opción --library, que se utiliza para enlazar con bibliotecas en sistemas Unix y Linux.
#ftprintf: Este es el nombre de la biblioteca que se está buscando. Cuando usas -lftprintf, el compilador buscará archivos de biblioteca que sigan el patrón libftprintf.a o libftprintf.so en los directorios de bibliotecas predeterminados del sistema.
#Entonces, al usar -lftprintf, le indicas al compilador que debe enlazar tu programa con la biblioteca estática o compartida llamada libftprintf, facilitando el manejo de dependencias y permitiendo que el sistema busque la biblioteca en los directorios apropiados.