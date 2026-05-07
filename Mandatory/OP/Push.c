/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:30:00 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/07 20:32:03 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operations.h"
#include <unistd.h>

void	pa(t_core *core)
{
	if (!core)
		return ;
	push_stack(&core->a, &core->b);
	write(1, "pa\n", 3);
}

void	pb(t_core *core)
{
	if (!core)
		return ;
	push_stack(&core->b, &core->a);
	write(1, "pb\n", 3);
}
