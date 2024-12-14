/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:37:49 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/13 17:15:12 by mniemaz          ###   ########.fr       */
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
	// free(a);
	// free(b);
}

int	rotate_till_top(t_stack *s, int idx, enum e_operation_mode mode)
{
	int	ops_counter;

	if (idx == s->top)
		return (0);
	ops_counter = 0;
	// ft_printf("s->direc %d, s->direc == UP %d\n", s->direc, s->direc == UP);
	while ((s->direc == UP && idx != s->top) || (s->direc == DOWN && idx >= 0))
	{
		if (mode == MODE_EXECUTE)
		{
			if (s->direc == UP)
				rotate(s, PRINT);
			else
				reverse_rotate(s, PRINT);
		}
		else if (mode == MODE_COUNT)
			ops_counter++;
		if (s->direc == UP)
			idx++;
		else
			idx--;
	}
	return (ops_counter);
}
