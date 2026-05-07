/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:15:00 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/07 20:24:52 by sdaban           ###   ########.fr       */
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

static int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		compare = current->m_next;
		while (compare)
		{
			if (current->m_value == compare->m_value)
				return (1);
			compare = compare->m_next;
		}
		current = current->m_next;
	}
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
		{
			if (parse_split_args(split_args, core))
				return (1);
		}
		else if (add_arg_to_stack(argv[1], core))
			return (1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (add_arg_to_stack(argv[i], core))
				return (1);
			i++;
		}
	}
	if (check_duplicates(core->a))
		return (1);
	return (0);
}
