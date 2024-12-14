/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:40:03 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/14 11:17:51 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR "Error\n"

# include <limits.h>
# include <stdlib.h>

enum					e_stack_id
{
	STACK_A,
	STACK_B
};

enum					e_direction
{
	DOWN,
	UP
};

enum					e_operation_mode
{
	MODE_COUNT,
	MODE_EXECUTE
};

enum					e_print
{
	PRINT,
	NO_PRINT
};

typedef struct s_stack
{
	int					*list;
	int					top;
	int					max_stack_size;
	int					idx_to_top;
	enum e_stack_id		stack_id;
	enum e_direction	direc;
}						t_stack;

int						ft_atoi(const char *nptr, t_stack *a, t_stack *b);
void					initialize_stacks(t_stack *a, t_stack *b, char **av,
							int ac);
int						pop(t_stack *a);
void					push(t_stack *a, int val);
void					print_stack(t_stack *s);
int						reverse_rotate(t_stack *s, enum e_print print_mode);
int						reverse_rotate_anb(t_stack *a, t_stack *b);
int						rotate(t_stack *s, enum e_print print_mode);
int						rotate_anb(t_stack *a, t_stack *b);
int						push_a(t_stack *a, t_stack *b);
int						push_b(t_stack *a, t_stack *b);
int						swap_a(t_stack *a, int is_ss);
int						swap_b(t_stack *b, int is_ss);
void					free_stacks(t_stack *a, t_stack *b);
int						got_duplicates(t_stack *s);
int						input_only_nb(char **input);
void					sorter(t_stack *a, t_stack *b);
int						rotate_till_top(t_stack *s, int idx,
							enum e_operation_mode mode);
int						rotate_both_till_top(t_stack *a, t_stack *b, int idx,
							int wanted_idx_b, enum e_operation_mode mode);
int						is_stack_sorted(t_stack *s);
int						get_idx_min_val(t_stack *s);
void					change_direc_if_worth(t_stack *a, t_stack *b);
int						process_rotates(t_stack *a, t_stack *b, int i_a,
							int i_b, enum e_operation_mode op_mode);
int						get_nearest_lower_idx(t_stack *b, int val_to_push);
int						get_nearest_higher_idx(t_stack *a, int val_to_push);

#endif