/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:48 by sdaban            #+#    #+#             */
/*   Updated: 2025/02/18 16:02:11 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	b_sort_small(t_stack *s, int len)
{
	if (len == 1)
		pa(s, 0);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s, 0);
		while (len--)
			pa(s, 0);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				sa(s, 0);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = push_stack(s, len, 1);
			else
				sb(s, 0);
		}
	}
	return (0);
}

void	quick_sort3(t_stack *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		sort_three(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack, 0);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = push_stack(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack, 0);
			else if (len++)
				pa(stack, 0);
		}
	}
}

int	get_middle_and_free_tmp(int *pivot, int *stack_a, int size)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp[i] = stack_a[i];
		i++;
	}
	ft_sort_int_tmp(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}

int	quick_sort_a_stack(t_stack *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (is_sorted(stack->a, len, 0) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		quick_sort3(stack, len);
		return (1);
	}
	if (!get_middle_and_free_tmp(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack, 0);
		else if (++count)
			ra(stack, 0);
	}
	while (items / 2 + items % 2 != stack->size_a && count--)
		rra(stack, 0);
	return (quick_sort_a_stack(stack, items / 2 + items % 2, 0)
		&& quick_sort_b_stack(stack, items / 2, 0));
	return (1);
}

int	quick_sort_b_stack(t_stack *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && is_sorted(stack->b, len, 1) == 1)
		while (len--)
			pa(stack, 0);
	if (len <= 3)
	{
		b_sort_small(stack, len);
		return (1);
	}
	items = len;
	if (!get_middle_and_free_tmp(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			pa(stack, 0);
		else if (++count)
			rb(stack, 0);
	}
	while (items / 2 != stack->size_b && count--)
		rrb(stack, 0);
	return (quick_sort_a_stack(stack, items / 2 + items % 2, 0)
		&& quick_sort_b_stack(stack, items / 2, 0));
}
