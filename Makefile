SRCS		= ft_printf.c ft_handleflags.c ft_utils.c ft_itoa.c \
			ft_printchar.c ft_printstr.c ft_pintint.c ft_printhex.c ft_printptr.c 

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

a:
		@${CC} main.c libftprintf.a -o main
		@./main