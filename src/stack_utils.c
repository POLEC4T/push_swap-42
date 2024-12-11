/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:37:49 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/11 16:22:01 by mniemaz          ###   ########.fr       */
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

void	rotate_till_top(t_stack *s, int idx)
{
	if (s->curr_direction == UP)
	{
		while (idx != s->top)
		{
			if (s->stack_id == STACK_A)
				rotate_a(s, 0);
			else
				rotate_b(s, 0);
			idx++;
		}
	}
	else if (s->curr_direction == DOWN)
	{
		while (idx >= 0)
		{
			if (s->stack_id == STACK_A)
				reverse_rotate_a(s, 0);
			else
				reverse_rotate_b(s, 0);
			idx--;
		}
	}
}
