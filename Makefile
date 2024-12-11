SRCDIR=./src/
INCDIR=./include/
OBJDIR=./.obj/

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)

SRCS = $(SRCDIR)push_swap.c \
		$(SRCDIR)ft_atoi.c \
		$(SRCDIR)input_check.c \
		$(SRCDIR)stack_utils.c \
		$(SRCDIR)stack_utils2.c \
		$(SRCDIR)ops_push.c \
		$(SRCDIR)ops_rotate.c \
		$(SRCDIR)ops_rev_rotate.c \
		$(SRCDIR)ops_swap.c \
		$(SRCDIR)sorter.c \

OBJS = ${SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o}

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(INCDIR)push_swap.h
	cd ./ft_printf/ && $(MAKE)
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME) -g

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean :
	cd ./ft_printf && $(MAKE) clean
	rm -rf $(OBJDIR)

fclean :
	cd ./ft_printf && $(MAKE) fclean
	rm -rf $(OBJDIR) $(NAME)

re : fclean all

.PHONY : all clean fclean re