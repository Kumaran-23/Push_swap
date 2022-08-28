/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:48:40 by snair             #+#    #+#             */
/*   Updated: 2022/08/25 14:55:16 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct p_stack
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}	t_stack;

//stack_utils
void	error(int *stack);
int		argv_strlen(char **argv);
int		new_atoi(char *str, int *stack);
int		sorted(int *stack, int size, int order);
void	check_dup(int *stack, int size);
//push_swap initializing stack and main function
void	init_stack(char **argv);
int		main(int argc, char **argv);
int		sort_stack(t_stack *stack, int size);
void	leakfix(int *a, int *b, int size);
//moves to perform
void	swap(int *a, int *b);
void	r_helper(int *stack, int size);
void	rb(t_stack *stack);
void	ra(t_stack *stack);
void	rr(t_stack *stack);
void	rr_helper(int *stack, int size);
void	rrb(t_stack *stack);
void	rra(t_stack *stack);
void	rrr(t_stack *stack);
void	s_helper(int *stack, int size);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	p_helper(int *stack, int size);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
//sort_utils
void	pivot_sort(int *stack, int size);
int		get_pivot(int *pivot, int *stack, int size);
void	sort_3a(t_stack *s);
int		quicksort_3(t_stack *stack, int len);
int		quicksort_3b(t_stack *stack, int len);
//quicksort and sort_5
int		get_min(int *stack, int len);
void	rotate_5(t_stack *stack, int len);
int		sort_5(t_stack *stack, int len);
int		quicksort_a(t_stack *stack, int len);
int		quicksort_b(t_stack *stack, int len);

#endif 
