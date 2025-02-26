/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:14:00 by sdaban            #+#    #+#             */
/*   Updated: 2024/10/20 12:19:57 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str2;
	size_t	len;

	len = ft_strlen(s1);
	str2 = (char *)malloc(len + 1);
	if ((str2) == NULL)
		return (NULL);
	ft_memcpy(str2, s1, len + 1);
	return (str2);
}
