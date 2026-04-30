/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:56:39 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 19:19:53 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>
# include "../Core/Core.h"

size_t		ft_strlen(char *str);
bool		ft_is_digit(char *str);
int			ft_atoi_checked(char *str, bool *error);
int			parse_arguments(int argc, char **argv, t_core *core);
void		ft_message(char *str, int is_error);
char		**split_string(char *str);
void		free_split(char **split);
void		print_stack(t_stack *stack, char *name);
#endif