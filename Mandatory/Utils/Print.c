/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:20:00 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 19:24:22 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"
#include <unistd.h>

static void	reverse_buf(char *buf, int len)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = buf[i];
		buf[i] = buf[j];
		buf[j] = temp;
		i++;
		j--;
	}
}

static void	write_number(int num)
{
	char	buf[20];
	int		len;
	int		temp;
	int		is_neg;

	len = 0;
	is_neg = 0;
	temp = num;
	if (temp < 0)
	{
		is_neg = 1;
		temp = -temp;
	}
	if (temp == 0)
		buf[len++] = '0';
	while (temp > 0)
	{
		buf[len++] = (temp % 10) + '0';
		temp /= 10;
	}
	reverse_buf(buf, len);
	if (is_neg)
		write(1, "-", 1);
	write(1, buf, len);
}

void	print_stack(t_stack *stack, char *name)
{
	t_stack	*current;

	if (!name)
		return ;
	write(1, name, ft_strlen(name));
	write(1, ": ", 2);
	current = stack;
	while (current)
	{
		write_number(current->m_value);
		write(1, " ", 1);
		current = current->m_next;
	}
	write(1, "\n", 1);
}
