NAME = libftprintf.a
CC = cc
DIRSRC = ./src/
DIRINC = ./include/
CFLAGS = -Wall -Wextra -Werror -I $(DIRINC)

SRC = ${DIRSRC}ft_printf.c \
		${DIRSRC}printers.c \
		${DIRSRC}utils.c \
		${DIRSRC}print_utils.c

HEADER_FILE = $(DIRINC)ft_printf.h

OBJS = ${SRC:.c=.o}
DEPS = ${SRC:.c=.d}

all: ${NAME}

-include $(DEPS)
%.o: %.c
	${CC} ${CFLAGS} -MMD -MP -c $< -o $@

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS} ${DEPS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus 