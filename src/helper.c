/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:18:51 by sdaban            #+#    #+#             */
/*   Updated: 2025/02/18 12:54:09 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

static unsigned long int	parse_number(char *str, t_stack *stack)
{
	unsigned long int	num;
	unsigned int		i;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			stack->flag = 1;
			return (0);
		}
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return (num);
}

int	advanced_atoi(char *str, t_stack *stack)
{
	unsigned int		i;
	int					neg;
	unsigned long int	num;

	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	num = parse_number(&str[i], stack);
	if ((num > 2147483648 && neg == -1)
		|| (num > INT_MAX && neg == 1))
	{
		stack->flag = 1;
		return (-42);
	}
	return (num * neg);
}

void	check_repeated_args(t_stack *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack->a[i] == stack->a[j])
			{
				stack->flag = 1;
				return ;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
