/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:48 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 18:56:36 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "../GC/GC.h"

typedef struct s_stack
{
	int				m_value;
	int				m_index;
	int				m_pos;
	int				m_cost_a;
	int				m_cost_b;
	struct s_stack	*m_target_node;
	struct s_stack	*m_next;
	struct s_stack	*m_prev;
}	t_stack;

typedef struct s_core
{
	t_stack	*a;
	t_stack	*b;
}	t_core;

void	init_core(t_core *core);
t_stack	*create_node(int value);
#endif