/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:52:33 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/07 20:32:13 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operations.h"
#include <unistd.h>

void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->m_next)
		return ;
	first = *stack;
	second = first->m_next;
	first->m_next = second->m_next;
	first->m_prev = second;
	if (second->m_next)
		second->m_next->m_prev = first;
	second->m_next = first;
	second->m_prev = NULL;
	*stack = second;
}

void	push_stack(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->m_next;
	if (*src)
		(*src)->m_prev = NULL;
	node->m_next = *dst;
	node->m_prev = NULL;
	if (*dst)
		(*dst)->m_prev = node;
	*dst = node;
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->m_next)
		return ;
	first = *stack;
	*stack = first->m_next;
	(*stack)->m_prev = NULL;
	last = *stack;
	while (last->m_next)
		last = last->m_next;
	last->m_next = first;
	first->m_prev = last;
	first->m_next = NULL;
}

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->m_next)
		return ;
	last = *stack;
	while (last->m_next)
		last = last->m_next;
	second_last = last->m_prev;
	second_last->m_next = NULL;
	last->m_next = *stack;
	last->m_prev = NULL;
	(*stack)->m_prev = last;
	*stack = last;
}
