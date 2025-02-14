SRCDIR=./src/
INCDIR=./include/
OBJDIR=./.obj/

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)

SRCS = $(SRCDIR)push_swap.c \
		$(SRCDIR)ft_atoi_improved.c \
		$(SRCDIR)ft_split.c \
		$(SRCDIR)stack_utils.c \
		$(SRCDIR)stack_utils2.c \
		$(SRCDIR)stack_utils3.c \
		$(SRCDIR)ops_push.c \
		$(SRCDIR)ops_rotate.c \
		$(SRCDIR)ops_rev_rotate.c \
		$(SRCDIR)ops_swap.c \
		$(SRCDIR)input_check.c \
		$(SRCDIR)sorter.c \
		$(SRCDIR)calc_costs.c \
		$(SRCDIR)frees.c \
		$(SRCDIR)utils.c

OBJS = ${SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o}

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c $(INCDIR)push_swap.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean :
	rm -rf $(OBJDIR)

fclean :
	rm -rf $(OBJDIR) $(NAME)

re : fclean all

.PHONY : all clean fclean re