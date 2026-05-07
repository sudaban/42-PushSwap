/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:30:00 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/07 20:32:03 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operations.h"
#include <unistd.h>

void	rra(t_core *core)
{
	if (!core)
		return ;
	reverse_rotate_stack(&core->a);
	write(1, "rra\n", 4);
}

void	rrb(t_core *core)
{
	if (!core)
		return ;
	reverse_rotate_stack(&core->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_core *core)
{
	if (!core)
		return ;
	reverse_rotate_stack(&core->a);
	reverse_rotate_stack(&core->b);
	write(1, "rrr\n", 4);
}
