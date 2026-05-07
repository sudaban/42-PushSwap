/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:30:00 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/07 20:32:03 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operations.h"
#include <unistd.h>

void	ra(t_core *core)
{
	if (!core)
		return ;
	rotate_stack(&core->a);
	write(1, "ra\n", 3);
}

void	rb(t_core *core)
{
	if (!core)
		return ;
	rotate_stack(&core->b);
	write(1, "rb\n", 3);
}

void	rr(t_core *core)
{
	if (!core)
		return ;
	rotate_stack(&core->a);
	rotate_stack(&core->b);
	write(1, "rr\n", 3);
}
