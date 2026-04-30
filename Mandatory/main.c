/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:45:55 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 19:19:53 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GC/GC.h"
#include "Core/Core.h"
#include "Utils/Utils.h"

int	main(int argc, char **argv)
{
	t_core	god_object;

	if (argc < 2)
		ft_message("Error", 1);
	init_core(&god_object);
	if (parse_arguments(argc, argv, &god_object) == 0)
	{
		print_stack(god_object.a, "Stack A");
		memory_cleanup(0);
		return (0);
	}
	memory_cleanup(1);
	return (1);
}
