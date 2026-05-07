/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:52:39 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/07 20:30:46 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../Core/Core.h"

void	sa(t_core *core);
void	sb(t_core *core);
void	ss(t_core *core);
void	pa(t_core *core);
void	pb(t_core *core);
void	ra(t_core *core);
void	rb(t_core *core);
void	rr(t_core *core);
void	rra(t_core *core);
void	rrb(t_core *core);
void	rrr(t_core *core);

void	swap_stack(t_stack **stack);
void	push_stack(t_stack **dst, t_stack **src);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);

#endif