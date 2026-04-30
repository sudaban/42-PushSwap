/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:56:37 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 19:24:33 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

bool	ft_is_digit(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_checked(char *str, bool *error)
{
	long	result;
	int		sign;
	int		i;

	if (!ft_is_digit(str))
	{
		*error = 1;
		return (0);
	}
	*error = 0;
	result = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (str[i])
		result = result * 10 + (str[i++] - '0');
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		return (*error = 1, 0);
	return ((int)(sign * result));
}

void	ft_message(char *str, int is_error)
{
	if (!str)
		return ;
	if (is_error)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
