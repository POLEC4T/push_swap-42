#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

void	swap_a(t_stack *a, int is_ss)
{
	int	val1;
	int	val2;

	val1 = pop(a);
	val2 = pop(a);
	push(a, val1);
	push(a, val2);
	if (!is_ss)
		ft_printf("sa\n");
}

void	swap_b(t_stack *b, int is_ss)
{
	int	val1;
	int	val2;

	val1 = pop(b);
	val2 = pop(b);
	push(b, val1);
	push(b, val2);
	if (!is_ss)
		ft_printf("sb\n");
}

void	swap_anb(t_stack *b, t_stack *a)
{
	swap_a(a, 1);
	swap_b(b, 1);
	ft_printf("ss\n");
}