/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:46:27 by sdaban            #+#    #+#             */
/*   Updated: 2025/02/18 16:02:56 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"

static int	allocate_memory(t_stack *stack, int size)
{
	stack->a = malloc(sizeof(int) * size);
	if (!stack->a)
		return (0);
	stack->size_a = size;
	stack->b = malloc(sizeof(int) * size);
	if (!stack->b)
	{
		free(stack->a);
		return (0);
	}
	stack->size_b = 0;
	return (1);
}

void	ft_push_swap(char **av, int flag)
{
	t_stack	stack;
	int		size;
	int		i;

	i = -1;
	size = strlen_2(av);
	stack.flag = 0;
	if (allocate_memory(&stack, size) == 0)
	{
		free_whole_str(av);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (++i < size)
			stack.a[i] = advanced_atoi(av[i], &stack);
		check_repeated_args(&stack, size);
		if (stack.flag == 1 && flag == 1)
			finisher(&stack, av);
		sort_stack(&stack, size);
		free(stack.a);
		free(stack.b);
	}
}

static int	validate_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "+") == 0 || ft_strcmp(str[i], "-") == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	is_full_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == 32 || str[i] == 9))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			if (ft_strlen(argv[0]) == 0 || is_full_space(argv[0]))
				return (write(2, "Error\n", 6), 1);
			argv = ft_split(*argv, ' ');
			if (!argv || !validate_args(argv))
			{
				free_whole_str(argv);
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			ft_push_swap(argv, 1);
			free_whole_str(argv);
		}
		else
		{
			if (!validate_args(argv))
				return (write(2, "Error\n", 6), 1);
			ft_push_swap(argv, 0);
		}
	}
	return (0);
}
