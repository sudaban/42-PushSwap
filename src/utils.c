/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:00 by sdaban            #+#    #+#             */
/*   Updated: 2025/02/18 16:04:46 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	free_whole_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		i++;
	while (--i >= 0)
	{
		if (str[i])
			free(str[i]);
	}
	free(str);
}

void	perror_and_free(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	write(2, "Error\n", 6);
}

int	strlen_2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	finisher(t_stack *stack, char **av)
{
	if (stack->flag == 1)
	{
		free_whole_str(av);
		perror_and_free(stack);
		exit(EXIT_FAILURE);
	}
}
