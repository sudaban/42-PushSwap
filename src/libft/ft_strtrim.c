/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:12:19 by sdaban            #+#    #+#             */
/*   Updated: 2024/10/20 12:20:40 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_char_in_set(char const character, char const *set)
{
	int	current_index;

	current_index = -1;
	while (set[++current_index])
		if (set[current_index] == character)
			return (1);
	return (0);
}

static char	*create_empty_string(void)
{
	char	*empty_str;

	empty_str = malloc(sizeof(char));
	if (!empty_str)
		return (NULL);
	ft_strlcpy(empty_str, "", 1);
	return (empty_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	size_t	input_length;
	char	*trimmed_string;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	while (is_char_in_set(s1[start_index], set))
		start_index++;
	input_length = ft_strlen(s1);
	end_index = input_length - 1;
	if (start_index == input_length)
		return (create_empty_string());
	while (is_char_in_set(s1[end_index], set))
		end_index--;
	trimmed_string = malloc((end_index - start_index + 2) * sizeof(char));
	if (!trimmed_string)
		return (NULL);
	ft_strlcpy(trimmed_string,
		(s1 + start_index), (end_index - start_index + 2));
	return (trimmed_string);
}
