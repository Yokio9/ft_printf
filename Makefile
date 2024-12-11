SRCS = ft_printf.c ft_utoa.c ft_putnbr_hexa.c ft_itoa.c ../libft/ft_putchar.c ../libft/ft_putstr.c
OBJECTS = ${SRCS:.c=.o}
HEADERS = ft_printf.h
CC = gcc
LIBC = ar rcs
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I.
LDFLAGS = -fsanitize=address
NAME = libftprintf.a
LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	cd $(LIBFT_PATH) && make

$(NAME): $(LIBFT) $(OBJECTS)
	$(LIBC) $(NAME) $(OBJECTS) $(LIBFT_PATH)/*.o

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re clean fclean
