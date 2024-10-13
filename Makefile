SRCS = ft_printf.c ft_print_num.c
OBJECTS = ${SRCS:.c=.o}
HEADERS = /libft/libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a
LIBC = ar rcs

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJECTS}
	${LIBC} ${NAME} ${OBJECTS}

bonus: ${OBJECTS} ${BOBJECTS}
	${LIBC} ${NAME} ${BOBJECTS}

clean:
	rm -f ${OBJECTS} ${BOBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re clean fclean bonus
