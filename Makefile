SRCS = src/get_next_line.c \
		src/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

NAME = libget_next_line.a

CC = gcc

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus:	${OBJS_BONUS}
			ar rc ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all