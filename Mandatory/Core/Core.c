/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:41:22 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 19:01:45 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Core.h"
#include <stdlib.h>
#include <stddef.h>

void	init_core(t_core *core)
{
	core->a = NULL;
	core->b = NULL;
}

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)memory_malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->m_value = value;
	node->m_index = -1;
	node->m_pos = -1;
	node->m_cost_a = 0;
	node->m_cost_b = 0;
	node->m_target_node = NULL;
	node->m_next = NULL;
	node->m_prev = NULL;
	return (node);
}

void	push_to_stack(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	node->m_next = *stack;
	if (*stack)
		(*stack)->m_prev = node;
	*stack = node;
}
