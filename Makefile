SRCS		= ft_printf.c ft_checkformat.c ft_utils.c ft_putchar.c ft_printstr.c \
			ft_printpointer.c ft_printnum.c ft_printunum.c ft_printbnum.c

OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
LIBC		= ar rcs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
rm			= rm -f

.PHONY: all clean fclean re bonus

%.o: %.c ft_printf.h
		${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS} ft_printf.h
		${LIBC} ${NAME} ${OBJS}

bonus: all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all
