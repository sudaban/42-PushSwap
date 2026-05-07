/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:30:00 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/07 20:32:03 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operations.h"
#include <unistd.h>

void	sa(t_core *core)
{
	if (!core)
		return ;
	swap_stack(&core->a);
	write(1, "sa\n", 3);
}

void	sb(t_core *core)
{
	if (!core)
		return ;
	swap_stack(&core->b);
	write(1, "sb\n", 3);
}

void	ss(t_core *core)
{
	if (!core)
		return ;
	swap_stack(&core->a);
	swap_stack(&core->b);
	write(1, "ss\n", 3);
}
