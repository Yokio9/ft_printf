SRCS = ft_printf.c ft_convert_type.c ft_putunbr.c ft_utoa.c ft_itoa_hexa.c ft_putnbr_hexa.c ft_switch_cases.c ft_putchar.c ft_putstr.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_putnbr.c ft_itoa.c ft_utoa_hexa.c
OBJECTS = ${SRCS:.c=.o}
HEADERS = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBC = ar rcs

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJECTS}
	${LIBC} ${NAME} ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re clean fclean
