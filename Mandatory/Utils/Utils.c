/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:56:37 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 18:45:36 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"
#include <limits.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

bool	ft_is_in_limit(int num)
{
	return (num >= INT_MIN && num <= INT_MAX);
}
