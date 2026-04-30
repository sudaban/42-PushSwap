/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:15:00 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 19:21:49 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"
#include <stdlib.h>

static int	count_words(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			if (!in_word)
				count++;
			in_word = 1;
		}
		else
			in_word = 0;
		str++;
	}
	return (count);
}

static void	ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static void	extract_word(char **result, char *str, int *i, int word_idx)
{
	int	j;

	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
	j = 0;
	while (str[*i + j] && str[*i + j] != ' ' && str[*i + j] != '\t')
		j++;
	result[word_idx] = (char *)memory_malloc(j + 1);
	if (result[word_idx])
	{
		ft_strncpy(result[word_idx], str + *i, j);
		result[word_idx][j] = '\0';
	}
	*i += j;
}

char	**split_string(char *str)
{
	char	**result;
	int		word_count;
	int		i;
	int		word_idx;

	if (!str || !str[0])
		return (NULL);
	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);
	result = (char **)memory_malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	word_idx = 0;
	while (word_idx < word_count)
	{
		extract_word(result, str, &i, word_idx);
		word_idx++;
	}
	result[word_count] = NULL;
	return (result);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		i++;
	while (--i >= 0)
		memory_free(split[i]);
	memory_free(split);
}
