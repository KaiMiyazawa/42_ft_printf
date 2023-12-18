NAME = libftprintf.a
INCDIR = include
SRCS = ft_printf.c ft_put_fd.c ft_print_void_hex.c ft_print_num_hex.c ft_print_us_num_dec.c
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -o $@ -c $< -I ${INCDIR}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}
