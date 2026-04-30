/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:45:55 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 18:52:38 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "GC/GC.h"
#include "Core/Core.h"

int	main(int argc, char **argv)
{
	t_core	god_object;

	(void)argv;
	if (argc < 2)
		return (1);
	init_core(&god_object);
	printf("Stack A: %p, Stack B: %p\n",
		(void *)god_object.a, (void *)god_object.b);
	return (0);
}
