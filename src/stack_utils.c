/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:37:49 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/11 17:08:33 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

int	pop(t_stack *a)
{
	int	top_value;

	if (a->top == -1)
	{
		ft_printf("Error : Stack underflow");
		return (-1);
	}
	top_value = a->list[a->top];
	a->top--;
	return (top_value);
}

void	push(t_stack *a, int val)
{
	if (a->top + 1 == a->max_stack_size)
	{
		ft_printf("Error : Stack overflow");
		return ;
	}
	a->top++;
	a->list[a->top] = val;
}

void	print_stack(t_stack *s)
{
	int	i;

	i = s->top;
	ft_printf("\n");
	while (i + 1)
	{
		ft_printf("%d : |%d|\n", i, s->list[i]);
		i--;
	}
	if (s->top != -1)
		ft_printf("     - \n");
	else
		ft_printf("stack is empty\n");
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->list);
	free(b->list);
}

// int	rotate_till_top(t_stack *s, int idx, enum e_mode mode)
// {
// 	int	ops_counter;

// 	ops_counter = 0;
// 	if (s->direc == UP)
// 	{
// 		while (idx != s->top)
// 		{
// 			if (mode == OPS_MODE)
// 				rotate(s, 0);
// 			else if (mode == COUNT_MODE)
// 				ops_counter++;
// 			idx++;
// 		}
// 	}
// 	else if (s->direc == DOWN)
// 	{
// 		while (idx >= 0)
// 		{
// 			if (mode == OPS_MODE)
// 				reverse_rotate(s, 0);
// 			else if (mode == COUNT_MODE)
// 				ops_counter++;
// 			idx--;
// 		}
// 	}
// 	return (ops_counter);
// }

int	rotate_till_top(t_stack *s, int idx, enum e_mode mode)
{
	int	ops_counter;

	ops_counter = 0;
	while ((s->direc == UP && idx != s->top) || (s->direc == DOWN && idx >= 0))
	{
		if (mode == OPS_MODE)
		{
			if (s->direc == UP)
				rotate(s, 0);
			else
				reverse_rotate(s, 0);
		}
		else if (mode == COUNT_MODE)
			ops_counter++;
		if (s->direc == UP)
			idx++;
		else
			idx--;
	}
	return (ops_counter);
}
