/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:46:25 by sdaban            #+#    #+#             */
/*   Updated: 2025/02/18 16:03:43 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	flag;
}	t_stack;

void	free_whole_str(char **str);
void	perror_and_free(t_stack *stack);
int		strlen_2(char **str);
int		advanced_atoi(char *str, t_stack *stack);
void	check_repeated_args(t_stack *stack, int size);

int		is_sorted(int *stack_a, int size, int flag);
int		sort_stack(t_stack *stack, int size);
void	sort_three(t_stack *s);
void	ft_sort_int_tmp(int *tmp_stack, int size);

void	quick_sort3(t_stack *stack, int len);
int		b_sort_small(t_stack *s, int len);
int		push_stack(t_stack *stack, int len, int operation);
int		get_middle_and_free_tmp(int *pivot, int *stack_a, int size);
int		quick_sort_a_stack(t_stack *stack, int len, int count);
int		quick_sort_b_stack(t_stack *stack, int len, int count);

void	sa(t_stack *stack, int print);
void	rra(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	pa(t_stack *stack, int print);

void	pb(t_stack *stack, int print);
void	sb(t_stack	*stack, int print);
void	rb(t_stack	*stack, int print);
void	rrb(t_stack *stack, int print);

void	ft_push_swap(char **av, int flag);
void	finisher(t_stack *stack, char **av);

#endif