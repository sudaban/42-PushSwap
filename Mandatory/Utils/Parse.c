/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:15:00 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 19:19:53 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"
#include <stdbool.h>

static int	add_arg_to_stack(char *arg, t_core *core)
{
	t_stack	*node;
	int		num;
	bool	error;

	num = ft_atoi_checked(arg, &error);
	if (error)
		return (1);
	node = create_node(num);
	if (!node)
		return (1);
	push_to_stack(&core->a, node);
	return (0);
}

static int	parse_split_args(char **split_args, t_core *core)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		if (add_arg_to_stack(split_args[i], core))
		{
			free_split(split_args);
			return (1);
		}
		i++;
	}
	free_split(split_args);
	return (0);
}

int	parse_arguments(int argc, char **argv, t_core *core)
{
	char	**split_args;
	int		i;

	if (argc == 2)
	{
		split_args = split_string(argv[1]);
		if (split_args)
			return (parse_split_args(split_args, core));
		return (add_arg_to_stack(argv[1], core));
	}
	i = 1;
	while (i < argc)
	{
		if (add_arg_to_stack(argv[i], core))
			return (1);
		i++;
	}
	return (0);
}
