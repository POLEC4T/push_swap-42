SRCDIR=./src/
INCDIR=./include/
OBJDIR=./.obj/

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)

SRCS = $(SRCDIR)push_swap.c \
		$(SRCDIR)ft_atoi.c \
		$(SRCDIR)ft_printf.c \
		$(SRCDIR)print_utils.c \
		$(SRCDIR)printers.c \
		$(SRCDIR)utils.c 

OBJS = ${SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o}

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean :
	rm -rf $(OBJDIR)

fclean :
	rm -rf $(OBJDIR) $(NAME)

re : fclean all

.PHONY : all clean fclean re